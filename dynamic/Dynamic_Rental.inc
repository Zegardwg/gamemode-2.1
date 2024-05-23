#define MAX_RENTAL 100

enum e_rental
{
	rentID,
	bool:rentExists,
	Float:rentPos[3],
	Float:rentSpawn[4],
	rentModel[2],
	rentPrice[2],
	STREAMER_TAG_3D_TEXT_LABEL:rentText,
	STREAMER_TAG_PICKUP:rentPickup,
};

new RentData[MAX_RENTAL][e_rental];

stock Rental_Create(playerid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	if (GetPlayerPos(playerid, x, y, z))
	{
		forex(i, MAX_RENTAL)
		{
		    if(!RentData[i][rentExists])
		    {
		        RentData[i][rentExists] = true;
		        RentData[i][rentModel][0] = 0;
		        RentData[i][rentModel][1] = 0;
		        RentData[i][rentPos][0] = x;
		        RentData[i][rentPos][1] = y;
		        RentData[i][rentPos][2] = z;
		        RentData[i][rentSpawn][0] = 0;
		        RentData[i][rentSpawn][1] = 0;
		        RentData[i][rentSpawn][2] = 0;
		        
		        Rental_Refresh(i);
		        mysql_tquery(g_SQL, "INSERT INTO `rental` (`Vehicle1`) VALUES(0)", "OnRentalCreated", "d", i);
		        return i;
			}
		}
	}
	return -1;
}

function OnRentalCreated(id)
{
	if (id == -1 || !RentData[id][rentExists])
	    return 0;

	RentData[id][rentID] = cache_insert_id();
	Rental_Save(id);

	return 1;
}

function Rental_Refresh(id)
{
	if(id != -1 && RentData[id][rentExists])
	{
	    if(IsValidDynamic3DTextLabel(RentData[id][rentText]))
	        DestroyDynamic3DTextLabel(RentData[id][rentText]);
	        
		if(IsValidDynamicPickup(RentData[id][rentPickup]))
		    DestroyDynamicPickup(RentData[id][rentPickup]);
		    
		new string[156];
		format(string, sizeof(string), "{D3D3D3}[Vehicle Rental]\n{5FC6F4}Rental Vehicle\n{00FF00}[Y]{FFFFFF} untuk mengakses rental vehicle");
        RentData[id][rentText] = CreateDynamic3DTextLabel(string, -1, RentData[id][rentPos][0], RentData[id][rentPos][1], RentData[id][rentPos][2]+0.5, 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
		RentData[id][rentPickup] = CreatePickup(1239, 0, RentData[id][rentPos][0], RentData[id][rentPos][1], RentData[id][rentPos][2], -1);
	}
	return 1;
}

function Rental_Load()
{
	new rows = cache_num_rows();
	if(rows)
	{
	    forex(i, rows)
	    {
	        RentData[i][rentExists] = true;
	        cache_get_value_name_int(i, "ID", RentData[i][rentID]);
	        cache_get_value_name_float(i, "PosX", RentData[i][rentPos][0]);
	        cache_get_value_name_float(i, "PosY", RentData[i][rentPos][1]);
	        cache_get_value_name_float(i, "PosZ", RentData[i][rentPos][2]);
	        cache_get_value_name_float(i, "SpawnX", RentData[i][rentSpawn][0]);
	        cache_get_value_name_float(i, "SpawnY", RentData[i][rentSpawn][1]);
	        cache_get_value_name_float(i, "SpawnZ", RentData[i][rentSpawn][2]);
	        cache_get_value_name_float(i, "SpawnA", RentData[i][rentSpawn][3]);
	        cache_get_value_name_int(i, "Vehicle1", RentData[i][rentModel][0]);
	        cache_get_value_name_int(i, "Vehicle2", RentData[i][rentModel][1]);
	        cache_get_value_name_int(i, "Price1", RentData[i][rentPrice][0]);
	        cache_get_value_name_int(i, "Price2", RentData[i][rentPrice][1]);
	        
	        Rental_Refresh(i);
		}
	}
	return 1;
}

stock Rental_Save(id)
{
	new query[1052];
	mysql_format(g_SQL, query, sizeof(query), "UPDATE `rental` SET ");
	mysql_format(g_SQL, query, sizeof(query), "%s`PosX`='%f', ", query, RentData[id][rentPos][0]);
	mysql_format(g_SQL, query, sizeof(query), "%s`PosY`='%f', ", query, RentData[id][rentPos][1]);
	mysql_format(g_SQL, query, sizeof(query), "%s`PosZ`='%f', ", query, RentData[id][rentPos][2]);
	mysql_format(g_SQL, query, sizeof(query), "%s`SpawnX`='%f', ", query, RentData[id][rentSpawn][0]);
	mysql_format(g_SQL, query, sizeof(query), "%s`SpawnY`='%f', ", query, RentData[id][rentSpawn][1]);
	mysql_format(g_SQL, query, sizeof(query), "%s`SpawnZ`='%f', ", query, RentData[id][rentSpawn][2]);
	mysql_format(g_SQL, query, sizeof(query), "%s`SpawnA`='%f', ", query, RentData[id][rentSpawn][3]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Vehicle1`='%d', ", query, RentData[id][rentModel][0]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Vehicle2`='%d', ", query, RentData[id][rentModel][1]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Price1`='%d', ", query, RentData[id][rentModel][0]);
	mysql_format(g_SQL, query, sizeof(query), "%s`Price2`='%d' ", query, RentData[id][rentModel][1]);
	mysql_format(g_SQL, query, sizeof(query), "%sWHERE `ID` = '%d'", query, RentData[id][rentID]);
	mysql_query(g_SQL, query, true);
	return 1;
}

CMD:editrental(playerid, params[])
{
    new
        id,
        type[24],
        string[128];

    if(AccountData[playerid][pAdmin] < 3)
        return ErrorMsg(playerid, "You don't have permission to use this command!");
        
    if(sscanf(params, "ds[24]S()[128]", id, type, string))
    {
        SyntaxMsg(playerid, "/editrental [id] [name]\nName: Location, Spawn");
        return 1;
    }
    if((id < 0 || id >= MAX_RENTAL))
        return ErrorMsg(playerid, "You have specified an invalid ID.");

	if(!RentData[id][rentExists])
        return ErrorMsg(playerid, "You have specified an invalid ID.");

	if(!strcmp(type, "location", true))
	{
	    GetPlayerPos(playerid, RentData[id][rentPos][0], RentData[id][rentPos][1], RentData[id][rentPos][2]);
	    Rental_Save(id);
	    Rental_Refresh(id);
	    
	    SendAdminMessage(C_ADMIN, "[AdmCmd] %s telah mengubah posisi Rental ID: %d", GetName(playerid), id);
	}
	else if(!strcmp(type, "spawn", true))
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	        return ErrorMsg(playerid, "Kamu harus berada didalam kendaraan!");
	        
		GetVehiclePos(GetPlayerVehicleID(playerid), RentData[id][rentSpawn][0], RentData[id][rentSpawn][1], RentData[id][rentSpawn][2]);
		GetVehicleZAngle(GetPlayerVehicleID(playerid), RentData[id][rentSpawn][3]);
		
		SendAdminMessage(C_ADMIN, "AdmCmd: %s Kamu telah mengubah posisi Spawn Rental ID: %d", GetName(playerid), id);
		Rental_Save(id);
	}	
	return 1;
}
CMD:createrental(playerid, params[])
{
	new id;

    if (AccountData[playerid][pAdmin] < 3)
	    return ErrorMsg(playerid, "You don't have permission to use this command.");
		
	id = Rental_Create(playerid);
	
	if(id == -1)
	    return ErrorMsg(playerid, "Kamu tidak bisa membuat lebih banyak Rental!");
	return 1;
}

GetVehicleRental2Cost(carid)
{
	if(carid == 462) return 1000; 
	if(carid == 463) return 1500; 
	return -1;
}