#define MAX_GSTATION 50

enum gsinfo
{
	gsStock,
	Float:gsPosX,
	Float:gsPosY,
	Float:gsPosZ,
	Text3D:gsLabel,
	gsPickup
};

new gsData[MAX_GSTATION][gsinfo],
	Iterator: GStation<MAX_GSTATION>;

new vehiclecallsign[MAX_VEHICLES];
new Text3D:vehicle3Dtext[MAX_VEHICLES];
	
GStation_Refresh(gsid)
{
	if(gsid != -1)
    {
        if(IsValidDynamic3DTextLabel(gsData[gsid][gsLabel]))
            DestroyDynamic3DTextLabel(gsData[gsid][gsLabel]);

        if(IsValidDynamicPickup(gsData[gsid][gsPickup]))
            DestroyDynamicPickup(gsData[gsid][gsPickup]);

        static
        string[255];

		format(string, sizeof(string), "Tekan "LG_E"Y{FFFFFF} untuk mengisi bbm");
		//gsData[gsid][gsPickup] = CreateDynamicPickup(1650, 23, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]+0.2, -1, -1, -1, 5.0);
		gsData[gsid][gsLabel] = CreateDynamic3DTextLabel(string, -1, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]+0.5, 4.5);
	}
    return 1;
}

stock Business_NearestFuel1(playerid)
{
	foreach(new gsid : GStation)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 4.0, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]))
	    {
	        return gsid;
	    }
	}
	return -1;
}

function LoadGStations()
{
    static gsid;
	
	new rows = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "id", gsid);
			cache_get_value_name_int(i, "stock", gsData[gsid][gsStock]);
			cache_get_value_name_float(i, "posx", gsData[gsid][gsPosX]);
			cache_get_value_name_float(i, "posy", gsData[gsid][gsPosY]);
			cache_get_value_name_float(i, "posz", gsData[gsid][gsPosZ]);
			GStation_Refresh(gsid);
			Iter_Add(GStation, gsid);
		}
		printf("[Dynamic Gas Station] Number of Loaded: %d.", rows);
	}
}

GStation_Save(gsid)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE gstations SET stock='%d', posx='%f', posy='%f', posz='%f' WHERE id='%d'",
	gsData[gsid][gsStock],
	gsData[gsid][gsPosX],
	gsData[gsid][gsPosY],
	gsData[gsid][gsPosZ],
	gsid
	);
	return mysql_tquery(g_SQL, cQuery);
}

CMD:creategs(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new gsid = Iter_Free(GStation), query[128];
	if(gsid == -1) return Error(playerid, "You cant create more gs!");
	new stok;
	if(sscanf(params, "d", stok)) return Usage(playerid, "/creategs [stock - max: 10000/liters]");
	
	if(stok < 1 || stok > 10000) return Error(playerid, "Invagsid stok.");
	
	GetPlayerPos(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
	gsData[gsid][gsStock] = stok;
    GStation_Refresh(gsid);
	Iter_Add(GStation, gsid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO gstations SET id='%d', stock='%d', posx='%f', posy='%f', posz='%f'", gsid, gsData[gsid][gsStock], gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
	mysql_tquery(g_SQL, query, "OnGstationCreated", "i", gsid);
	return 1;
}

function OnGstationCreated(gsid)
{
	GStation_Save(gsid);
	return 1;
}

CMD:gotogs(playerid, params[])
{
	new gsid;
	if(pData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
		
	if(sscanf(params, "d", gsid))
		return Usage(playerid, "/gotogs [id]");
		
	if(!Iter_Contains(GStation, gsid)) return Error(playerid, "The gs you specified ID of doesn't exist.");
	SetPlayerPosition(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ], 2.0);
    SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	pData[playerid][pInBiz] = -1;
	pData[playerid][pInDoor] = -1;
	pData[playerid][pInHouse] = -1;
	Servers(playerid, "You has teleport to gs id %d", gsid);
	return 1;
}

CMD:editgs(playerid, params[])
{
    static
        gsid,
        type[24],
        string[128];

    if(pData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if(sscanf(params, "ds[24]S()[128]", gsid, type, string))
    {
        Usage(playerid, "/editgs [id] [name]");
        SendClientMessageEx(playerid, COLOR_YELLOW, "[NAMES]{FFFFFF} location, stock, delete");
        return 1;
    }
    if((gsid < 0 || gsid >= MAX_GSTATION))
        return Error(playerid, "You have specified an invagsid ID.");
	if(!Iter_Contains(GStation, gsid)) return Error(playerid, "The doors you specified ID of doesn't exist.");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]);
        GStation_Save(gsid);
		GStation_Refresh(gsid);

        SendAdminMessage(COLOR_RED, "%s has adjusted the location of gs ID: %d.", pData[playerid][pAdminname], gsid);
    }
    else if(!strcmp(type, "stock", true))
    {
        new stok;

        if(sscanf(string, "d", stok))
            return Usage(playerid, "/editgs [id] [type] [stock - 10000]");

        if(stok < 1 || stok > 10000)
            return Error(playerid, "You must specify at least 1 - 5.");

        gsData[gsid][gsStock] = stok;
        GStation_Save(gsid);
		GStation_Refresh(gsid);

        SendAdminMessage(COLOR_RED, "%s has set gs ID: %d stock to %d.", pData[playerid][pAdminname], gsid, stok);
    }
    else if(!strcmp(type, "delete", true))
    {
		new query[128];
		DestroyDynamic3DTextLabel(gsData[gsid][gsLabel]);
		DestroyDynamicPickup(gsData[gsid][gsPickup]);
		gsData[gsid][gsPosX] = 0;
		gsData[gsid][gsPosY] = 0;
		gsData[gsid][gsPosY] = 0;
		gsData[gsid][gsStock] = 0;
		gsData[gsid][gsLabel] = Text3D: INVALID_3DTEXT_ID;
		gsData[gsid][gsPickup] = -1;
		Iter_Remove(GStation, gsid);
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM gstations WHERE id=%d", gsid);
		mysql_tquery(g_SQL, query);
        SendAdminMessage(COLOR_RED, "%s has delete gs ID: %d.", pData[playerid][pAdminname], gsid);
    }
    return 1;
}