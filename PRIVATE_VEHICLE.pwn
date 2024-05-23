
//Private Vehicle Player System Define

#define MAX_PRIVATE_VEHICLE 1000
#define MAX_PLAYER_VEHICLE 3
#define MAX_VEHICLE_STORAGE 8
//new Float: VehicleFuel[MAX_VEHICLES] = 100.0;
new bool:VehicleHealthSecurity[MAX_VEHICLES] = false, Float:VehicleHealthSecurityData[MAX_VEHICLES] = 1000.0;

enum pvdata
{
	cID,
	cOwner,
	cModel,
	cColor1,
	cColor2,
	cPaintJob,
	cLocked,
	cInsu,
	cClaim,
	cPlate[15],
	cPlateTime,
	cPrice,
	cRent,
	Float:cHealth,
	cFuel,
	Float:cPos[4],
	cInt,
	cVw,
	cDamage[4],
	cMod[17],
	cLumber,
	cMetal,
	cCoal,
	cProduct,
	cVeh,
	cTrunk,
	cParkid,
	bool:LoadedStorage,
	cWeapons[5],
	cAmmo[5],
	cSerial[5],
	cDurability[5],			
	// Trunk Storage
	e_TRUNK_FLAGS:vehTrunkType[MAX_VEHICLE_STORAGE],
};
new pvData[MAX_PRIVATE_VEHICLE][pvdata],
	Iterator:PVehicles<MAX_PRIVATE_VEHICLE + 1>;

/* New Trunk storage system */

#define MAX_CAR_STORAGE 5

enum carStorage
{
	cItemID,
	cItemExists,
	cItemName[32 char],
	cItemModel,
	cItemQuantity
};

new CarStorage[MAX_PLAYER_VEHICLE][MAX_CAR_STORAGE][carStorage];

//Private Vehicle Player System Native
new const g_arrVehicleNames[][] = {
        "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel", "Dumper", "Firetruck", "Trashmaster",
        "Stretch", "Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
        "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer",
        "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach",
        "Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow",
        "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair",
        "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic",
        "Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton",
        "Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher",
        "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick",
        "Boxville", "Benson", "Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher",
        "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt", "Tanker", "Roadtrain",
        "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck",
        "Fortune", "Cadrona", "SWAT Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan",
        "Blade", "Streak", "Freight", "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder",
        "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster", "Monster",
        "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
        "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30",
        "Huntley", "Stafford", "BF-400", "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
        "Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "LSPD Car", "SFPD Car", "LVPD Car",
        "Police Rancher", "Picador", "S.W.A.T", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs",
        "Boxville", "Tiller", "Utility Trailer"
};

GetEngineStatus(vehicleid)
{
    static
        engine,
        lights,
        alarm,
        doors,
        bonnet,
        boot,
        objective;

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

    if(engine != 1)
        return 0;

    return 1;
}

GetLightStatus(vehicleid)
{
    static
        engine,
        lights,
        alarm,
        doors,
        bonnet,
        boot,
        objective;

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

    if(lights != 1)
        return 0;

    return 1;
}

GetHoodStatus(vehicleid)
{
    static
        engine,
        lights,
        alarm,
        doors,
        bonnet,
        boot,
        objective;

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

    if(bonnet != 1)
        return 0;

    return 1;
}

GetTrunkStatus(vehicleid)
{
    static
        engine,
        lights,
        alarm,
        doors,
        bonnet,
        boot,
        objective;

    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

    if(boot != 1)
        return 0;

    return 1;
}

GetVehicleModelByName(const name[])
{
    if(IsNumeric(name) && (strval(name) >= 400 && strval(name) <= 611))
        return strval(name);

    for (new i = 0; i < sizeof(g_arrVehicleNames); i ++)
    {
        if(strfind(g_arrVehicleNames[i], name, true) != -1)
        {
                    return i + 400;
        }
    }
    return 0;
}

Vehicle_Nearest(playerid, Float:range = 3.5)
{
    static
        Float:fX,
        Float:fY,
        Float:fZ;

    for(new i = 0; i != MAX_PRIVATE_VEHICLE; i++) if(Iter_Contains(PVehicles, i)) 
	{
        GetVehiclePos(pvData[i][cVeh], fX, fY, fZ);

        if(IsPlayerInRangeOfPoint(playerid, range, fX, fY, fZ)) {
            return i;
        }
    }
    return -1;
}

Vehicle_Nearest2(playerid, Float:range = 6.0)
{
    static
        Float:fX,
        Float:fY,
        Float:fZ;

    for(new i = 0; i != MAX_PRIVATE_VEHICLE; i++) if(Iter_Contains(PVehicles, i)) {
        GetVehiclePos(pvData[i][cVeh], fX, fY, fZ);

        if(IsPlayerInRangeOfPoint(playerid, range, fX, fY, fZ)) {
            return i;
        }
    }
    return -1;
}

Vehicle_IsOwner(playerid, carid)
{
    if(!pData[playerid][IsLoggedIn] || pData[playerid][pID] == -1)
        return 0;

    if((Iter_Contains(PVehicles, carid) && pvData[carid][cOwner] != 0) && pvData[carid][cOwner] == pData[playerid][pID])
        return 1;

    return 0;
}

Vehicle_GetStatus(carid)
{
    GetVehicleDamageStatus(pvData[carid][cVeh], pvData[carid][cDamage][0], pvData[carid][cDamage][1], pvData[carid][cDamage][2], pvData[carid][cDamage][3]);

    GetVehicleHealth(pvData[carid][cVeh], pvData[carid][cHealth]);
	pvData[carid][cFuel] = GetVehicleFuel(pvData[carid][cVeh]);
    if(pvData[carid][cOwner])
    {
        GetVehiclePos(pvData[carid][cVeh], pvData[carid][cPos][0], pvData[carid][cPos][1], pvData[carid][cPos][2]);
        GetVehicleZAngle(pvData[carid][cVeh],pvData[carid][cPos][3]);
    }
    return 1;
}

SetValidVehicleHealth(vehicleid, Float:health) {
    VehicleHealthSecurity[vehicleid] = true;
    SetVehicleHealth(vehicleid, health);
    return 1;
}

ValidRepairVehicle(vehicleid) {
    VehicleHealthSecurity[vehicleid] = true;
    RepairVehicle(vehicleid);
    return 1;
}


//Private Vehicle Player System Function

function OnPlayerVehicleRespawn(i)
{
	/*if(IsValidVehicle(pvData[i][cVeh]))
		DestroyVehicle(pvData[i][cVeh]);*/
	
	pvData[i][cVeh] = CreateVehicle(pvData[i][cModel], pvData[i][cPos][0], pvData[i][cPos][1], pvData[i][cPos][2], pvData[i][cPos][3], pvData[i][cColor1], pvData[i][cColor2], 60000);
	SetVehicleNumberPlate(pvData[i][cVeh], pvData[i][cPlate]);
	SetVehicleVirtualWorld(pvData[i][cVeh], pvData[i][cVw]);
	LinkVehicleToInterior(pvData[i][cVeh], pvData[i][cInt]);
	SetVehicleFuel(pvData[i][cVeh], pvData[i][cFuel]);
	SetValidVehicleHealth(pvData[i][cVeh], pvData[i][cHealth]);
	UpdateVehicleDamageStatus(pvData[i][cVeh], pvData[i][cDamage][0], pvData[i][cDamage][1], pvData[i][cDamage][2], pvData[i][cDamage][3]);
	if(pvData[i][cVeh] != INVALID_VEHICLE_ID)
    {
        if(pvData[i][cPaintJob] != -1)
        {
            ChangeVehiclePaintjob(pvData[i][cVeh], pvData[i][cPaintJob]);
        }
		for(new z = 0; z < 17; z++)
		{
			if(pvData[i][cMod][z]) AddVehicleComponent(pvData[i][cVeh], pvData[i][cMod][z]);
		}
		if(pvData[i][cLocked] == 1)
		{
			SwitchVehicleDoors(pvData[i][cVeh], true);
		}
		else
		{
			SwitchVehicleDoors(pvData[i][cVeh], false);
		}
	}
	if(pvData[i][cMetal] > 0)
	{

		LogStorage[pvData[i][cVeh]][ 0 ] += pvData[i][cMetal];
	}
	else
	{
		LogStorage[pvData[i][cVeh]][ 0 ] = 0;
	}
	
	if(pvData[i][cCoal] > 0)
	{
		LogStorage[pvData[i][cVeh]][ 1 ] += pvData[i][cCoal];
	}
	else
	{
		LogStorage[pvData[i][cVeh]][ 1 ] = 0;
	}
	
	if(pvData[i][cProduct] > 0)
	{
		VehProduct[pvData[i][cVeh]] += pvData[i][cProduct];
	}
	else
	{
		VehProduct[pvData[i][cVeh]] = 0;
	}
	SetTimerEx("OnLoadVehicleStorage", 2000, false, "d", i);
	MySQL_LoadVehicleStorage(i);	
	/*if(pvData[i][cClaim] != 0)
	{
		SetTimerEx("RespawnPV", 3000, false, "d", pvData[i][cVeh]);
	}*/
	//SwitchVehicleEngine(pvData[i][cVeh], false);
	return 1;
}

function LoadPlayerVehicle(playerid)
{
	new query[128];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `vehicle` WHERE `owner` = %d", pData[playerid][pID]);
	mysql_query(g_SQL, query, true);
	new count = cache_num_rows(), tempString[56];
	if(count > 0)
	{
		for(new z = 0; z < count; z++)
		{
			new i = Iter_Free(PVehicles);
			cache_get_value_int(z, "id", pvData[i][cID]);
			//pvData[i][VehicleOwned] = true;
			cache_get_value_int(z, "owner", pvData[i][cOwner]);
			cache_get_value_int(z, "locked", pvData[i][cLocked]);
			cache_get_value_int(z, "insu", pvData[i][cInsu]);
			cache_get_value_int(z, "claim", pvData[i][cClaim]);
			cache_get_value_float(z, "x", pvData[i][cPos][0]);
			cache_get_value_float(z, "y", pvData[i][cPos][1]);
			cache_get_value_float(z, "z", pvData[i][cPos][2]);
			cache_get_value_float(z, "a", pvData[i][cPos][3]);
			cache_get_value_float(z, "health", pvData[i][cHealth]);
			cache_get_value_int(z, "fuel", pvData[i][cFuel]);
			cache_get_value_int(z, "int", pvData[i][cInt]);
			cache_get_value_int(z, "vw", pvData[i][cVw]);
			cache_get_value_int(z, "damage0", pvData[i][cDamage][0]);
			cache_get_value_int(z, "damage1", pvData[i][cDamage][1]);
			cache_get_value_int(z, "damage2", pvData[i][cDamage][2]);
			cache_get_value_int(z, "damage3", pvData[i][cDamage][3]);
			cache_get_value_int(z, "color1", pvData[i][cColor1]);
			cache_get_value_int(z, "color2", pvData[i][cColor2]);
			cache_get_value_int(z, "paintjob", pvData[i][cPaintJob]);
			cache_get_value_int(z, "price", pvData[i][cPrice]);
			cache_get_value_int(z, "model", pvData[i][cModel]);
			cache_get_value_name(z, "plate", tempString);
			format(pvData[i][cPlate], 16, tempString);
			cache_get_value_int(z, "plate_time", pvData[i][cPlateTime]);
			
			cache_get_value_int(z, "mod0", pvData[i][cMod][0]);
			cache_get_value_int(z, "mod1", pvData[i][cMod][1]);
			cache_get_value_int(z, "mod2", pvData[i][cMod][2]);
			cache_get_value_int(z, "mod3", pvData[i][cMod][3]);
			cache_get_value_int(z, "mod4", pvData[i][cMod][4]);
			cache_get_value_int(z, "mod5", pvData[i][cMod][5]);
			cache_get_value_int(z, "mod6", pvData[i][cMod][6]);
			cache_get_value_int(z, "mod7", pvData[i][cMod][7]);
			cache_get_value_int(z, "mod8", pvData[i][cMod][8]);
			cache_get_value_int(z, "mod9", pvData[i][cMod][9]);
			cache_get_value_int(z, "mod10", pvData[i][cMod][10]);
			cache_get_value_int(z, "mod11", pvData[i][cMod][11]);
			cache_get_value_int(z, "mod12", pvData[i][cMod][12]);
			cache_get_value_int(z, "mod13", pvData[i][cMod][13]);
			cache_get_value_int(z, "mod14", pvData[i][cMod][14]);
			cache_get_value_int(z, "mod15", pvData[i][cMod][15]);
			cache_get_value_int(z, "mod16", pvData[i][cMod][16]);
			cache_get_value_int(z, "lumber", pvData[i][cLumber]);
			cache_get_value_int(z, "metal", pvData[i][cMetal]);
			cache_get_value_int(z, "coal", pvData[i][cCoal]);
			cache_get_value_int(z, "product", pvData[i][cProduct]);
			cache_get_value_name_int(z, "rental", pvData[i][cRent]);
			cache_get_value_name_int(z, "parkid", pvData[i][cParkid]);
			cache_get_value_name_int(z, "carweapon1", pvData[i][cWeapons][0]);
			cache_get_value_name_int(z, "carweapon2", pvData[i][cWeapons][1]);
			cache_get_value_name_int(z, "carweapon3", pvData[i][cWeapons][2]);
			cache_get_value_name_int(z, "carweapon4", pvData[i][cWeapons][3]);
			cache_get_value_name_int(z, "carweapon5", pvData[i][cWeapons][4]);
			cache_get_value_name_int(z, "carammo1", pvData[i][cAmmo][0]);
			cache_get_value_name_int(z, "carammo2", pvData[i][cAmmo][1]);
			cache_get_value_name_int(z, "carammo3", pvData[i][cAmmo][2]);
			cache_get_value_name_int(z, "carammo4", pvData[i][cAmmo][3]);
			cache_get_value_name_int(z, "carammo5", pvData[i][cAmmo][4]);
			cache_get_value_name_int(z, "cardurability1", pvData[i][cDurability][0]);
			cache_get_value_name_int(z, "cardurability2", pvData[i][cDurability][1]);
			cache_get_value_name_int(z, "cardurability3", pvData[i][cDurability][2]);
			cache_get_value_name_int(z, "cardurability4", pvData[i][cDurability][3]);
			cache_get_value_name_int(z, "cardurability5", pvData[i][cDurability][4]);	

			new str[128];
			format(str, sizeof(str), "SELECT * FROM `carstorage` WHERE `ID` = '%d'", pvData[i][cID]);
			mysql_tquery(g_SQL , str, "OnLoadCarStorage", "d", i);	
			/*for(new x = 0; x < 17; x++)
			{
				format(tempString, sizeof(tempString), "mod%d", x);
				cache_get_value_int(z, tempString, pvData[i][cMod][x]);
			}*/
			Iter_Add(PVehicles, i);
			if(pvData[i][cClaim] == 0 && pvData[i][cParkid] == -1)
			{
				//pvData[i][cTrunk] = 1;
				OnPlayerVehicleRespawn(i);
			}
			else
			{
				pvData[i][cVeh] = 0;
			}
		}
		printf("[P_VEHICLE] Loaded player vehicle from: %s(%d)", pData[playerid][pName], playerid);
	}
	return true;
}

function EngineStatus(playerid, vehicleid)
{
	if(!GetEngineStatus(vehicleid))
	{
		new Float: f_vHealth;
		GetVehicleHealth(vehicleid, f_vHealth);
		if(f_vHealth < 350.0) return ErrorMsg(playerid, "Kendaraan tidak dapat Menyala, Sudah rusak!");
		if(GetVehicleFuel(vehicleid) <= 0.0) return ErrorMsg(playerid, "Kendaraan tidak dapat Menyala, Bensin habis!");

		new rand = random(3);
		if(rand == 0)
		{
			SwitchVehicleEngine(vehicleid, true);
			SuccesMsg(playerid, "Mesin kendaraan menyala");
		}
		if(rand == 1)
		{
			SwitchVehicleEngine(vehicleid, true);
			SuccesMsg(playerid, "Mesin kendaraan menyala");
		}
		if(rand == 2)
		{
			SwitchVehicleEngine(vehicleid, true);
			SuccesMsg(playerid, "Mesin kendaraan menyala");
		}
	}
	else
	{
		//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s mematikan mesin kendaraan %s.", ReturnName(playerid, 0), GetVehicleNameByVehicle(GetPlayerVehicleID(playerid)));
		SwitchVehicleEngine(vehicleid, false);
		//Info(playerid, "Engine turn off..");
        SuccesMsg(playerid, "Mesin kendaraan dimatikan");
	}
	return 1;
}

function RemovePlayerVehicle(playerid)
{
	foreach(new i : PVehicles)
	{
		if(pvData[i][cParkid] == -1)
		{
			Vehicle_GetStatus(i);
		}
		if(pvData[i][cOwner] == pData[playerid][pID])
		{
			for (new ai = 0; ai != MAX_CAR_STORAGE; ai ++)
			{
		        CarStorage[i][ai][cItemExists] = false;
		        CarStorage[i][ai][cItemModel] = 0;
		        CarStorage[i][ai][cItemQuantity] = 0;
			}			
			new cQuery[2048], color1, color2, paintjob;
			pvData[i][cOwner] = -1;
			GetVehicleColor(pvData[i][cVeh], color1, color2);
			paintjob = GetVehiclePaintjob(pvData[i][cVeh]);
			//pvData[i][VehicleOwned] = false;
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "UPDATE `vehicle` SET ");
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`x` = '%f', ", cQuery, pvData[i][cPos][0]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`y` = '%f', ", cQuery, pvData[i][cPos][1]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`z` = '%f', ", cQuery, pvData[i][cPos][2]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`a` = '%f', ", cQuery, pvData[i][cPos][3]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`health` = '%f', ", cQuery, pvData[i][cHealth]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`fuel` = '%d', ", cQuery, pvData[i][cFuel]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`int` = %d, ", cQuery, pvData[i][cInt]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`price` = %d, ", cQuery, pvData[i][cPrice]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`vw` = %d, ", cQuery, pvData[i][cVw]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`model` = %d, ", cQuery, pvData[i][cModel]);
			if(pvData[i][cLocked] == 1)
				mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`locked` = 1, ", cQuery);
			else
				mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`locked` = 0, ", cQuery);
			/*if(pvData[i][VehicleAlarm])
				mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`alarm` = 1, ", cQuery);
			else
				mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`alarm` = 0, ", cQuery);*/
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`insu` = '%d', ", cQuery, pvData[i][cInsu]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`claim` = '%d', ", cQuery, pvData[i][cClaim]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`plate` = '%e', ", cQuery, pvData[i][cPlate]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`plate_time` = '%d', ", cQuery, pvData[i][cPlateTime]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`color1` = %d, ", cQuery, color1);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`color2` = %d, ", cQuery, color2);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`paintjob` = %d, ", cQuery, paintjob);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`damage0` = %d, ", cQuery, pvData[i][cDamage][0]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`damage1` = %d, ", cQuery, pvData[i][cDamage][1]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`damage2` = %d, ", cQuery, pvData[i][cDamage][2]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`damage3` = %d, ", cQuery, pvData[i][cDamage][3]);
			new tempString[56];
			for(new z = 0; z < 17; z++)
			{
				format(tempString, sizeof(tempString), "mod%d", z);
				mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`%s` = %d, ", cQuery, tempString, pvData[i][cMod][z]);
			}
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`lumber` = %d, ", cQuery, pvData[i][cLumber]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`metal` = %d, ", cQuery, pvData[i][cMetal]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`coal` = %d, ", cQuery, pvData[i][cCoal]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`product` = %d, ", cQuery, pvData[i][cProduct]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`rental`=%d, ", cQuery, pvData[i][cRent]);
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`parkid`='%d' ", cQuery, pvData[i][cParkid]);

			
			mysql_format(g_SQL, cQuery, sizeof(cQuery), "%sWHERE `id` = %d", cQuery, pvData[i][cID]);
			mysql_query(g_SQL, cQuery, true);
			if(IsValidVehicle(pvData[i][cVeh])) DestroyVehicle(pvData[i][cVeh]);
			Iter_SafeRemove(PVehicles, i, i);
		}
	}
	return 1;
}

function OnVehCreated(playerid, oid, pid, model, color1, color2, Float:x, Float:y, Float:z, Float:a)
{
	new i = Iter_Free(PVehicles);
	pvData[i][cID] = cache_insert_id();
	pvData[i][cOwner] = pid;
	pvData[i][cModel] = model;
	pvData[i][cColor1] = color1;
	pvData[i][cColor2] = color2;
	pvData[i][cPaintJob] = -1;
	pvData[i][cLocked] = 0;
	pvData[i][cInsu] = 1;
	pvData[i][cClaim] = 0;
	pvData[i][cPrice] = 100000;
	pvData[i][cHealth] = 1000;
	pvData[i][cFuel] = 1000;
	format(pvData[i][cPlate], 16, "NoHave");
	pvData[i][cPlateTime] = 0;
	pvData[i][cParkid] = -1;
	pvData[i][cPos][0] = x;
	pvData[i][cPos][1] = y;
	pvData[i][cPos][2] = z;
	pvData[i][cPos][3] = a;
	pvData[i][cInt] = 0;
	pvData[i][cVw] = 0;
	pvData[i][cLumber] = -1;
	pvData[i][cMetal] = 0;
	pvData[i][cCoal] = 0;
	pvData[i][cProduct] = 0;
	for(new j = 0; j < 17; j++)
		pvData[i][cMod][j] = 0;
	Iter_Add(PVehicles, i);
	OnPlayerVehicleRespawn(i);
	Servers(playerid, "Anda telah membuat kendaraan kepada %s dengan (model=%d, color1=%d, color2=%d)", pData[oid][pName], model, color1, color2);
	return 1;
}

function OnVehBuyPV(playerid, pid, model, color1, color2, cost, Float:x, Float:y, Float:z, Float:a)
{
	new i = Iter_Free(PVehicles);
	pvData[i][cID] = cache_insert_id();
	pvData[i][cOwner] = pid;
	pvData[i][cModel] = model;
	pvData[i][cColor1] = color1;
	pvData[i][cColor2] = color2;
	pvData[i][cPaintJob] = -1;
	pvData[i][cLocked] = 0;
	pvData[i][cInsu] = 1;
	pvData[i][cParkid] = -1;
	pvData[i][cClaim] = 0;
	pvData[i][cPrice] = cost;
	pvData[i][cHealth] = 2000;
	pvData[i][cFuel] = 1000;
	format(pvData[i][cPlate], 16, "NoHave");
	pvData[i][cPlateTime] = 0;
	pvData[i][cPos][0] = x;
	pvData[i][cPos][1] = y;
	pvData[i][cPos][2] = z;
	pvData[i][cPos][3] = a;
	pvData[i][cInt] = 0;
	pvData[i][cVw] = 0;
	pvData[i][cLumber] = -1;
	pvData[i][cMetal] = 0;
	pvData[i][cCoal] = 0;
	pvData[i][cProduct] = 0;
	for(new j = 0; j < 17; j++)
		pvData[i][cMod][j] = 0;
	Iter_Add(PVehicles, i);
	OnPlayerVehicleRespawn(i);
	Servers(playerid, "Anda telah membeli kendaraan seharga %s dengan model %s(%d)", FormatMoney(GetVehicleCost(model)), GetVehicleModelName(model), model);
	pData[playerid][pBuyPvModel] = 0;
	return 1;
}

function OnVehBuyVIPPV(playerid, pid, model, color1, color2, cost, Float:x, Float:y, Float:z, Float:a)
{
	new i = Iter_Free(PVehicles);
	pvData[i][cID] = cache_insert_id();
	pvData[i][cOwner] = pid;
	pvData[i][cModel] = model;
	pvData[i][cColor1] = color1;
	pvData[i][cColor2] = color2;
	pvData[i][cPaintJob] = -1;
	pvData[i][cLocked] = 0;
	pvData[i][cParkid] = -1;
	pvData[i][cInsu] = 1;
	pvData[i][cClaim] = 0;
	pvData[i][cPrice] = cost;
	pvData[i][cHealth] = 2000;
	pvData[i][cFuel] = 1000;
	format(pvData[i][cPlate], 16, "NoHave");
	pvData[i][cPlateTime] = 0;
	pvData[i][cPos][0] = x;
	pvData[i][cPos][1] = y;
	pvData[i][cPos][2] = z;
	pvData[i][cPos][3] = a;
	pvData[i][cInt] = 0;
	pvData[i][cVw] = 0;
	pvData[i][cLumber] = -1;
	pvData[i][cMetal] = 0;
	pvData[i][cCoal] = 0;
	pvData[i][cProduct] = 0;
	for(new j = 0; j < 17; j++)
		pvData[i][cMod][j] = 0;
	Iter_Add(PVehicles, i);
	OnPlayerVehicleRespawn(i);
	Servers(playerid, "Anda telah membeli kendaraan VIP seharga %d Coin dengan model %s(%d)", GetVipVehicleCost(GetVehicleModel(GetPlayerVehicleID(playerid))), GetVehicleModelName(model), model);
	SetPlayerPosition(playerid, 1802.51, -1797.49, 13.54, 1.28, 0);
	return 1;
}


function OnVehRentPV(playerid, pid, model, color1, color2, cost, Float:x, Float:y, Float:z, Float:a, rental)
{
	new i = Iter_Free(PVehicles);
	pvData[i][cID] = cache_insert_id();
	pvData[i][cOwner] = pid;
	pvData[i][cModel] = model;
	pvData[i][cColor1] = color1;
	pvData[i][cColor2] = color2;
	pvData[i][cPaintJob] = -1;
	pvData[i][cParkid] = -1;
	pvData[i][cLocked] = 0;
	pvData[i][cInsu] = 3;
	pvData[i][cClaim] = 0;
	pvData[i][cPrice] = cost;
	pvData[i][cHealth] = 2000;
	pvData[i][cFuel] = 100;
	format(pvData[i][cPlate], 16, "NoHave");
	pvData[i][cPlateTime] = 0;
	pvData[i][cPos][0] = x;
	pvData[i][cPos][1] = y;
	pvData[i][cPos][2] = z;
	pvData[i][cPos][3] = a;
	pvData[i][cInt] = 0;
	pvData[i][cVw] = 0;
	pvData[i][cLumber] = -1;
	pvData[i][cMetal] = 0;
	pvData[i][cCoal] = 0;
	pvData[i][cProduct] = 0;
	pvData[i][cRent] = rental;
	for(new j = 0; j < 17; j++)
		pvData[i][cMod][j] = 0;
	Iter_Add(PVehicles, i);
	OnPlayerVehicleRespawn(i);
	//Servers(playerid, "Anda telah menyewa kendaraan seharga $500 / one days dengan model %s(%d)", GetVehicleModelName(model), model);
	pData[playerid][pBuyPvModel] = 0;
	return 1;
}

function RespawnPV(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	SetValidVehicleHealth(vehicleid, 1000);
	SetVehicleFuel(vehicleid, 1000);
	return 1;
}

// Private Vehicle Player System Commands
CMD:createpv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
	
	new model, color1, color2, otherid;
	if(sscanf(params, "uddd", otherid, model, color1, color2)) return Usage(playerid, "/createpv [name/playerid] [model] [color1] [color2]");
	
	if(color1 < 0 || color1 > 255) { Error(playerid, "Color Number can't be below 0 or above 255 !"); return 1; }
    if(color2 < 0 || color2 > 255) { Error(playerid, "Color Number can't be below 0 or above 255 !"); return 1; }
    if(model < 400 || model > 611) { Error(playerid, "Vehicle Number can't be below 400 or above 611 !"); return 1; }
	if(otherid == INVALID_PLAYER_ID) return Error(playerid, "Invalid player ID!");
	new count = 0, limit = MAX_PLAYER_VEHICLE + pData[otherid][pVip];
	foreach(new ii : PVehicles)
	{
		if(pvData[ii][cOwner] == pData[otherid][pID])
			count++;
	}
	if(count >= limit)
	{
		Error(playerid, "This player have too many vehicles, sell a vehicle first!");
		return 1;
	}
	new cQuery[1024];
	new Float:x,Float:y,Float:z, Float:a;
    GetPlayerPos(otherid,x,y,z);
    GetPlayerFacingAngle(otherid,a);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[otherid][pID], model, color1, color2, x, y, z, a);
	mysql_tquery(g_SQL, cQuery, "OnVehCreated", "ddddddffff", playerid, otherid, pData[otherid][pID], model, color1, color2, x, y, z, a);
	return 1;
}

CMD:deletepv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new vehid;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/deletepv [vehid] | /apv - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
			
	foreach(new i : PVehicles)			
	{
		if(vehid == pvData[i][cVeh])
		{
			Servers(playerid, "Your deleted private vehicle id %d (database id: %d).", vehid, pvData[i][cID]);
			new query[128];
			mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvData[i][cID]);
			mysql_tquery(g_SQL, query);
			if(IsValidVehicle(pvData[i][cVeh])) DestroyVehicle(pvData[i][cVeh]);
			Iter_SafeRemove(PVehicles, i, i);
		}
	}
	return 1;
}

/*CMD:deletepv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new otherid;
	if(sscanf(params, "u", otherid)) return Usage(playerid, "/gotopv [name/playerid]");
	if(otherid == INVALID_PLAYER_ID) return Error(playerid, "Invalid playerid");
	
	new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
	format(msg2, sizeof(msg2), "ID\tModel\tLocation\n");
	foreach(new i : PVehicles)
	{
		if(pvData[i][cOwner] == pData[otherid][pID])
		{
			GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
			format(msg2, sizeof(msg2), "%s%d\t%s\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), GetLocation(fx, fy, fz));
			found = true;
		}
	}
	if(found)
		ShowPlayerDialog(playerid, DIALOG_DELETEVEH, DIALOG_STYLE_TABLIST_HEADERS, "Delete Vehicles", msg2, "Delete", "Close");
	else
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles", "Player ini tidak memeliki kendaraan", "Close", "");
			
	return 1;
}

CMD:gotopv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new otherid;
	if(sscanf(params, "u", otherid)) return Usage(playerid, "/gotopv [name/playerid]");
	if(otherid == INVALID_PLAYER_ID) return Error(playerid, "Invalid playerid");
	
	new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
	format(msg2, sizeof(msg2), "ID\tModel\tLocation\n");
	foreach(new i : PVehicles)
	{
		if(pvData[i][cOwner] == pData[otherid][pID])
		{
			GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
			format(msg2, sizeof(msg2), "%s%d\t%s\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), GetLocation(fx, fy, fz));
			found = true;
		}
	}
	if(found)
		ShowPlayerDialog(playerid, DIALOG_GOTOVEH, DIALOG_STYLE_TABLIST_HEADERS, "Goto Vehicles", msg2, "Goto", "Close");
	else
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles", "Player ini tidak memeliki kendaraan", "Close", "");
			
	return 1;
}

CMD:getpv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 4)
		return PermissionError(playerid);
		
	new otherid;
	if(sscanf(params, "u", otherid)) return Usage(playerid, "/getpv [name/playerid]");
	if(otherid == INVALID_PLAYER_ID) return Error(playerid, "Invalid playerid");
	
	new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
	format(msg2, sizeof(msg2), "ID\tModel\tLocation\n");
	foreach(new i : PVehicles)
	{
		if(pvData[i][cOwner] == pData[otherid][pID])
		{
			GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
			format(msg2, sizeof(msg2), "%s%d\t%s\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), GetLocation(fx, fy, fz));
			found = true;
		}
	}
	if(found)
		ShowPlayerDialog(playerid, DIALOG_GETVEH, DIALOG_STYLE_TABLIST_HEADERS, "Get Vehicles", msg2, "Get", "Close");
	else
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles", "Player ini tidak memeliki kendaraan", "Close", "");
			
	return 1;
}*/

CMD:pvlist(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
	
	new count = 0, created = 0;
	foreach(new i : PVehicles)
	{
		count++;
		if(IsValidVehicle(pvData[i][cVeh]))
		{
			created++;
		}
	}
	Info(playerid, "Foreach total: %d, Created: %d", count, created);
	return 1;
}

CMD:apv(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid)) return Usage(playerid, "/apv [name/playerid]");
	if(otherid == INVALID_PLAYER_ID) return Error(playerid, "Invalid playerid");
		
	new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
	format(msg2, sizeof(msg2), "ID\tModel\tPlate\tPlate Time\n");
	foreach(new i : PVehicles)
	{
		if(pvData[i][cOwner] == pData[otherid][pID])
		{
			if(strcmp(pvData[i][cPlate], "NoHave"))
			{
				GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
				format(msg2, sizeof(msg2), "%s%d\t%s(id: %d)\t%s\t%s\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), pvData[i][cVeh], pvData[i][cPlate], ReturnTimelapse(gettime(), pvData[i][cPlateTime]));
				found = true;
			}
			else
			{
				GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
				format(msg2, sizeof(msg2), "%s%d\t%s(id: %d)\t%s\tNone\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), pvData[i][cVeh], pvData[i][cPlate]);
				found = true;
			}
		}
	}
	if(found)
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "Vehicles Plate", msg2, "Close", "");
	else
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles Plate", "Anda tidak memeliki kendaraan", "Close", "");
	return 1;
}

CMD:aveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	new vehicleid = GetNearestVehicleToPlayer(playerid, 5.0, false);

	if(vehicleid == INVALID_VEHICLE_ID)
		return Error(playerid, "You not in near any vehicles.");
	
	Servers(playerid, "Vehicle ID near on you id: %d (Model: %s(%d))", vehicleid, GetVehicleName(vehicleid), GetVehicleModel(vehicleid));
	return 1;
}

CMD:getveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	new vehid, Float:posisiX, Float:posisiY, Float:posisiZ;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/getveh [vehid] | /apv - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
	if(!IsValidVehicle(vehid)) return Error(playerid, "Invalid id");
	GetPlayerPos(playerid, posisiX, posisiY, posisiZ);
	Servers(playerid, "Your get spawn vehicle to %s (vehicle id: %d).", GetLocation(posisiX, posisiY, posisiZ), vehid);
	SetVehiclePos(vehid, posisiX, posisiY, posisiZ+0.5);
	return 1;
}

CMD:gotoveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	new vehid, Float:posisiX, Float:posisiY, Float:posisiZ;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/gotoveh [vehid] | /apv - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
	if(!IsValidVehicle(vehid)) return Error(playerid, "Invalid id");
	
	GetVehiclePos(vehid, posisiX, posisiY, posisiZ);
	Servers(playerid, "Your teleport to %s (vehicle id: %d).", GetLocation(posisiX, posisiY, posisiZ), vehid);
	SetPlayerPosition(playerid, posisiX, posisiY, posisiZ+3.0, 4.0, 0);
	return 1;
}

CMD:respawnveh(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);
		
	new vehid, Float:posisiX, Float:posisiY, Float:posisiZ;
	if(sscanf(params, "d", vehid)) return Usage(playerid, "/respawnveh [vehid] | /apv - for find vehid");
	if(vehid == INVALID_VEHICLE_ID) return Error(playerid, "Invalid id");
	if(!IsValidVehicle(vehid)) return Error(playerid, "Invalid id");
	GetVehiclePos(vehid, posisiX, posisiY, posisiZ);
	if(IsVehicleEmpty(vehid))
	{
		SetTimerEx("RespawnPV", 3000, false, "d", vehid);
		Servers(playerid, "Your respawned vehicle location %s (vehicle id: %d).", GetLocation(posisiX, posisiY, posisiZ), vehid);
	}
	else Error(playerid, "This Vehicle in used by someone.");
	return 1;
}

CMD:mypv(playerid, params[])
{
	return callcmd::v(playerid, "my");
}

CMD:v(playerid, params[])
{
	static
        type[20],
        string[225],
		vehicleid;

    if(sscanf(params, "s[20]S()[128]", type, string))
    {
        SendClientMessage(playerid,COLOR_BLUE,"|__________________ Vehicle Command __________________|");
        SendClientMessage(playerid,COLOR_WHITE,"VEHICLE: /v [(en)gine(Y)] [(li)ghts(N)] [hood] [trunk] [tow] [untow]");
		SendClientMessage(playerid,COLOR_WHITE,"VEHICLE: /v [my] [lock] [park]");
        return 1;
    }
	
	if(!strcmp(type, "engine", true))
    {
		vehicleid = GetPlayerVehicleID(playerid);
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{	
			if(!IsEngineVehicle(vehicleid))
            return Error(playerid, "You are not in any vehicle.");
			
			if(GetEngineStatus(vehicleid))
			{
				EngineStatus(playerid, vehicleid);
			}
			else
			{
				//Info(playerid, "Anda mencoba menyalakan mesin kendaraan..");
				//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s mencoba menghidupkan mesin kendaraan %s.", ReturnName(playerid, 0), GetVehicleNameByVehicle(GetPlayerVehicleID(playerid)));
				InfoTD_MSG(playerid, 4000, "Starting Engine...");
				SetTimerEx("EngineStatus", 3000, false, "id", playerid, vehicleid);
			}
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	else if(!strcmp(type, "en", true))
    {
		vehicleid = GetPlayerVehicleID(playerid);
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{	
			if(!IsEngineVehicle(vehicleid))
            return Error(playerid, "You are not in any vehicle.");
			
			if(GetEngineStatus(vehicleid))
			{
				EngineStatus(playerid, vehicleid);
			}
			else
			{
				//Info(playerid, "Anda mencoba menyalakan mesin kendaraan..");
				//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s mencoba menghidupkan mesin kendaraan %s.", ReturnName(playerid, 0), GetVehicleNameByVehicle(GetPlayerVehicleID(playerid)));
				InfoTD_MSG(playerid, 4000, "Starting Engine...");
				SetTimerEx("EngineStatus", 3000, false, "id", playerid, vehicleid);
			}
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	else if(!strcmp(type,"lights",true))
	{
		vehicleid = GetPlayerVehicleID(playerid);
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{	
			if(!IsEngineVehicle(vehicleid))
            return Error(playerid, "You are not in any vehicle.");
			
			switch(GetLightStatus(vehicleid))
			{
				case false:
				{
					SwitchVehicleLight(vehicleid, true);
				}
				case true:
				{
					SwitchVehicleLight(vehicleid, false);
				}
			}
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	else if(!strcmp(type,"li",true))
	{
		vehicleid = GetPlayerVehicleID(playerid);
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{	
			if(!IsEngineVehicle(vehicleid))
            return Error(playerid, "You are not in any vehicle.");
			
			switch(GetLightStatus(vehicleid))
			{
				case false:
				{
					SwitchVehicleLight(vehicleid, true);
				}
				case true:
				{
					SwitchVehicleLight(vehicleid, false);
				}
			}
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	else if(!strcmp(type,"hood",true))
    {
        /*
		vehicleid = GetPlayerVehicleID(playerid);
		if(!IsEngineVehicle(vehicleid))
            return Error(playerid, "You are not in any vehicle.");

        if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
            return Error(playerid, "You can't do this as you're not the driver.");*/
			
		if(IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must exit from the vehicle.");
			
		vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);

		if(vehicleid == INVALID_VEHICLE_ID)
			return Error(playerid, "You not in near any vehicles.");

		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
        switch (GetHoodStatus(vehicleid))
        {
            case false:
            {
                SwitchVehicleBonnet(vehicleid, true);
                InfoTD_MSG(playerid, 4000, "Vehicle Hood ~g~Open");
            }
            case true:
            {
                SwitchVehicleBonnet(vehicleid, false);
                InfoTD_MSG(playerid, 4000, "Vehicle Hood ~r~Close");
            }
        }
    }
    else if(!strcmp(type,"trunk",true))
    {
		if(IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must exit from the vehicle.");
		
        vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);

		if(vehicleid == INVALID_VEHICLE_ID)
			return Error(playerid, "You not in near any vehicles.");
			
        switch (GetTrunkStatus(vehicleid))
        {
            case false:
            {
                SwitchVehicleBoot(vehicleid, true);
                Info(playerid, "Vehicle trunk "GREEN_E"opened.");
            }
            case true:
            {
                SwitchVehicleBoot(vehicleid, false);
                Info(playerid, "Vehicle trunk "RED_E"close.");
            }
        }
    }
	else if(!strcmp(type,"lock",true))
	{
		static
			carid = -1;

		if((carid = Vehicle_Nearest(playerid)) != -1)
		{
			if(Vehicle_IsOwner(playerid, carid))
			{
				if(!pvData[carid][cLocked])
				{
					pvData[carid][cLocked] = 1;

					InfoTD_MSG(playerid, 4000, "You have ~r~locked~w~ the vehicle!");
					PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);

					SwitchVehicleDoors(pvData[carid][cVeh], true);
				}
				else
				{
					pvData[carid][cLocked] = 0;
					InfoTD_MSG(playerid, 4000, "You have ~g~unlocked~w~ the vehicle!");
					PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);

					SwitchVehicleDoors(pvData[carid][cVeh], false);
				}
			}
			//else SendErrorMessage(playerid, "You are not in range of anything you can lock.");
		}
		else Error(playerid, "You are not in range of vehicle you can lock.");
	}
	else if(!strcmp(type,"unlock",true))
	{
		static
			carid = -1;

		if((carid = Vehicle_Nearest(playerid)) != -1)
		{
			if(Vehicle_IsOwner(playerid, carid))
			{
				if(!pvData[carid][cLocked])
				{
					pvData[carid][cLocked] = 1;

					InfoTD_MSG(playerid, 4000, "You have ~r~locked~w~ the vehicle!");
					PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);

					SwitchVehicleDoors(pvData[carid][cVeh], true);
				}
				else
				{
					pvData[carid][cLocked] = 0;
					InfoTD_MSG(playerid, 4000, "You have ~g~unlocked~w~ the vehicle!");
					PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);

					SwitchVehicleDoors(pvData[carid][cVeh], false);
				}
			}
			//else SendErrorMessage(playerid, "You are not in range of anything you can lock.");
		}
		else Error(playerid, "You are not in range of vehicle you can lock.");
	}
	else if(!strcmp(type,"park",true))
	{
		if(!IsPlayerInAnyVehicle(playerid)) return Error(playerid, "You must in private vehicle.");
		
		new carid = -1,
			vehid = GetPlayerVehicleID(playerid);
			
		if((carid = Vehicle_Nearest(playerid)) != -1)
		{
			if(Vehicle_IsOwner(playerid, carid))
			{
				GetVehiclePos(vehid, pvData[carid][cPos][0], pvData[carid][cPos][1], pvData[carid][cPos][2]);
				GetVehicleZAngle(vehid, pvData[carid][cPos][3]);
				pvData[carid][cVw] = GetPlayerVirtualWorld(playerid);
				pvData[carid][cInt] = GetPlayerInterior(playerid);
				InfoTD_MSG(playerid, 4000, "You have ~g~Park~w~ the vehicle!");
				PlayerPlaySound(playerid, 1145, 0.0, 0.0, 0.0);
			}
		}
		else Error(playerid, "You are not in of vehicle you can park.");
	}
	else if(!strcmp(type,"my",true))
	{
		if(!GetOwnedVeh(playerid)) return Error(playerid, "You don't have any Vehicle.");
		new vid, _tmpstring[128], count = GetOwnedVeh(playerid), CMDSString[512], status[30], status1[30];
		CMDSString = "";
		strcat(CMDSString,"No\tName\tPlate\tStatus\n",sizeof(CMDSString));
		Loop(itt, (count + 1), 1)
		{
			vid = ReturnPlayerVehID(playerid, itt);
			if(pvData[vid][cParkid] != -1)
			{
				status = "{3BBD44}Garkot";
			}
			else if(pvData[vid][cClaim] != 0)
			{
				status = "{D2D2AB}Asuranssi";
			}
			else
			{
				status = "{FFFF00}Spawned";
			}

			if(pvData[vid][cRent] != 0)
			{
				status1 = "{BABABA}(Rental)";
			}
			else 
			{
				status1 = "";
			}

			if(itt == count)
			{
				format(_tmpstring, sizeof(_tmpstring), "{ffffff}%d.\t%s%s{ffffff}\t%s\t%s\n", itt, GetVehicleModelName(pvData[vid][cModel]), status1, pvData[vid][cPlate], status);
			}
			else format(_tmpstring, sizeof(_tmpstring), "{ffffff}%d.\t%s%s{ffffff}\t%s\t%s\n", itt, GetVehicleModelName(pvData[vid][cModel]), status1, pvData[vid][cPlate], status);
			strcat(CMDSString, _tmpstring);
		}
		ShowPlayerDialog(playerid, DIALOG_MYVEH, DIALOG_STYLE_TABLIST_HEADERS, "My Vehicle", CMDSString, "Select", "Cancel");
	}
	else if(!strcmp(type,"insu",true))
	{
		new bool:found = false, msg2[512], Float:fx, Float:fy, Float:fz;
		format(msg2, sizeof(msg2), "ID\tModel\tInsurance\tClaim\n");
		foreach(new i : PVehicles)
		{
			if(pvData[i][cOwner] == pData[playerid][pID])
			{
				GetVehiclePos(pvData[i][cVeh], fx, fy, fz);
				format(msg2, sizeof(msg2), "%s%d\t%s(id: %d)\t%d\t%d\n", msg2, pvData[i][cVeh], GetVehicleModelName(pvData[i][cModel]), pvData[i][cVeh], pvData[i][cInsu], pvData[i][cClaim]);
				found = true;
			}
		}
		if(found)
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS, "My Vehicles", msg2, "Close", "");
		else
			ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Vehicles", "Anda tidak memeliki kendaraan", "Close", "");
	}
	else if(!strcmp(type,"tow",true))
	{
		return callcmd::tow(playerid, params);
	}
	else if(!strcmp(type,"untow",true))
	{
		return callcmd::untow(playerid, params);
	}
	return 1;
}

GetDistanceToCar(playerid, veh, Float: posX = 0.0, Float: posY = 0.0, Float: posZ = 0.0) {

	new
	    Float: Floats[2][3];

	if(posX == 0.0 && posY == 0.0 && posZ == 0.0) {
		if(!IsPlayerInAnyVehicle(playerid)) GetPlayerPos(playerid, Floats[0][0], Floats[0][1], Floats[0][2]);
		else GetVehiclePos(GetPlayerVehicleID(playerid), Floats[0][0], Floats[0][1], Floats[0][2]);
	}
	else {
		Floats[0][0] = posX;
		Floats[0][1] = posY;
		Floats[0][2] = posZ;
	}
	GetVehiclePos(veh, Floats[1][0], Floats[1][1], Floats[1][2]);
	return floatround(floatsqroot((Floats[1][0] - Floats[0][0]) * (Floats[1][0] - Floats[0][0]) + (Floats[1][1] - Floats[0][1]) * (Floats[1][1] - Floats[0][1]) + (Floats[1][2] - Floats[0][2]) * (Floats[1][2] - Floats[0][2])));
}

GetClosestCar(playerid, exception = INVALID_VEHICLE_ID) 
{

    new
		Float: Distance,
		target = -1,
		Float: vPos[3];

	if(!IsPlayerInAnyVehicle(playerid)) GetPlayerPos(playerid, vPos[0], vPos[1], vPos[2]);
	else GetVehiclePos(GetPlayerVehicleID(playerid), vPos[0], vPos[1], vPos[2]);

    for(new v; v < MAX_VEHICLES; v++) if(GetVehicleModel(v) >= 400) {
        if(v != exception && (target < 0 || Distance > GetDistanceToCar(playerid, v, vPos[0], vPos[1], vPos[2]))) {
            target = v;
            Distance = GetDistanceToCar(playerid, v, vPos[0], vPos[1], vPos[2]); // Before the rewrite, we'd be running GetPlayerPos 2000 times...
        }
    }
    return target;
}

CMD:tow(playerid, params[]) 
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		new carid = GetPlayerVehicleID(playerid);
		if(IsATowTruck(carid))
		{
			new closestcar = GetClosestCar(playerid, carid);

			if(GetDistanceToCar(playerid, closestcar) <= 8 && !IsTrailerAttachedToVehicle(carid)) 
			{
				/*for(new x;x<sizeof(SAGSVehicles);x++)
				{
					if(SAGSVehicles[x] == closestcar) return Error(playerid, "You cant tow faction vehicle.");
					Info(playerid, "You has towed the vehicle in trailer.");
					AttachTrailerToVehicle(closestcar, carid);
					return 1;
				}
				for(new xx;xx<sizeof(SAPDVehicles);xx++)
				{
					if(SAPDVehicles[xx] == closestcar) return Error(playerid, "You cant tow faction vehicle.");
					Info(playerid, "You has towed the vehicle in trailer.");
					AttachTrailerToVehicle(closestcar, carid);
					return 1;
				}
				for(new y;y<sizeof(SAMDVehicles);y++)
				{
					if(SAMDVehicles[y] == closestcar) return Error(playerid, "You cant tow faction vehicle.");
					Info(playerid, "You has towed the vehicle in trailer.");
					AttachTrailerToVehicle(closestcar, carid);
					return 1;
				}
				for(new yy;yy<sizeof(SANAVehicles);yy++)
				{
					if(SANAVehicles[yy] == closestcar) return Error(playerid, "You cant tow faction vehicle.");
					Info(playerid, "You has towed the vehicle in trailer.");
					AttachTrailerToVehicle(closestcar, carid);
					return 1;
				}*/
				Info(playerid, "You has towed the vehicle in trailer.");
				AttachTrailerToVehicle(closestcar, carid);
				return 1;
			}
		}
		else
		{
			Error(playerid, "Anda harus mengendarai Tow truck.");
			return 1;
		}
	}
	else
	{
		Error(playerid, "Anda harus mengendarai Tow truck.");
		return 1;
	}
	return 1;
}

CMD:untow(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		if(IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
		{
			Info(playerid, "You has untowed the vehicle trailer.");
			DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
		}
		else
		{
			Error(playerid, "Tow penderek kosong!");
		}
	}
	else
	{
		Error(playerid, "Anda harus mengendarai Tow truck.");
		return 1;
	}
	return 1;
}

CMD:vstorage(playerid, params[])
{
	static
   	carid = -1;

	if(IsPlayerInAnyVehicle(playerid)) 
		return ErrorMsg(playerid, "Anda harus berada di luar kendaraan!");

	new x = GetNearestVehicleToPlayer(playerid, 3.5, false);

	if(!GetTrunkStatus(x) && !IsABike(x)) return ErrorMsg(playerid,"Buka bagasi terlebih dahulu");

	if((carid = Vehicle_Nearest(playerid)) != -1)
	{
		if(IsAVehicleStorage(x))
		{
			if(Vehicle_IsOwner(playerid, carid) || pData[playerid][pFaction] == 1)
			{
				foreach(new i: PVehicles)
				if(x == pvData[i][cVeh])
				{
					new vehid = pvData[i][cVeh];

					if(pvData[vehid][LoadedStorage] == false)
					{
						new cQuery[600];

						mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT * FROM `vstorage` WHERE `owner`='%d'", pvData[i][cID]);
						mysql_tquery(g_SQL, cQuery, "CheckVehicleStorageStatus", "iii", playerid, vehid, i);
					}
					else
					{
						new cQuery[600];

						mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT * FROM `vstorage` WHERE `owner`='%d'", pvData[i][cID]);
						mysql_tquery(g_SQL, cQuery, "CheckVehicleStorageStatus", "iii", playerid, vehid, i);
					}

					ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0, 1);
				}
			}
			else ErrorMsg(playerid, "Kendaraan ini bukan milik anda!");
		}	
		else ErrorMsg(playerid, "Kendaraan tidak mempunyai penyimpanan/ bagasi!");
	}
	else ErrorMsg(playerid, "Kamu tidak berada didekat Kendaraan apapun.");
	return 1;
}

GetVehicleStorage(vehicleid, item)
{
	static const StorageLimit[][] = {
	   //Snack  Sprunk  Medicine  Medkit  Bandage  Seed  Material  Component  Marijuana
	    {30,    30,     50,  	  5,  	  10,  	   500,  500,  	   500, 	 250}
	};

	return StorageLimit[pvData[vehicleid][cTrunk] - 1][item];
}

CMD:engine(playerid, params[])
{
	new vehicleid = GetPlayerVehicleID(playerid);
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{	
		if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Kamu tidak berada didalam kendaraan.");
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Tunggu sebentar..");
		if(GetEngineStatus(vehicleid))
		{
			EngineStatus(playerid, vehicleid);
		}
		else
		{
		    SetPlayerChatBubble(playerid,"> Mencoba menyalakan mesin <", COLOR_PURPLE,30.0,10000);
            SendNearbyMessage(playerid, 30.0, COLOR_WHITE, "ACTION: {D0AEEB} %s mencoba menyalakan mesin kendaraan.", ReturnName(playerid));
			SetTimerEx("EngineStatus", 3000, false, "id", playerid, vehicleid);
		}
	}
	else return ErrorMsg(playerid, "Anda harus mengendarai kendaraan!");
	return 1;
}

CMD:en(playerid, params[])
{
	new vehicleid = GetPlayerVehicleID(playerid);
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{	
		if(!IsEngineVehicle(vehicleid))
			return ErrorMsg(playerid, "Kamu tidak berada didalam kendaraan.");
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Tunggu sebentar..");
		if(GetEngineStatus(vehicleid))
		{
			EngineStatus(playerid, vehicleid);
		}
		else
		{
		    SetPlayerChatBubble(playerid,"> Mencoba menyalakan mesin <", COLOR_PURPLE,30.0,10000);
            SendNearbyMessage(playerid, 30.0, COLOR_WHITE, "ACTION: {D0AEEB} %s mencoba menyalakan mesin kendaraan.", ReturnName(playerid));
			SetTimerEx("EngineStatus", 3000, false, "id", playerid, vehicleid);
		}
	}
	else return ErrorMsg(playerid, "Anda harus mengendarai kendaraan!");
	return 1;
}

GetOwnedVeh(playerid)
{
	new tmpcount;
	foreach(new vid : PVehicles)
	{
	    if(pvData[vid][cOwner] == pData[playerid][pID])
	    {
     		tmpcount++;
		}
	}
	return tmpcount;
}

ReturnPlayerVehID(playerid, hslot)
{
	new tmpcount;
	if(hslot < 1 && hslot > MAX_PLAYER_VEHICLE) return -1;
	foreach(new vid : PVehicles)
	{
	    if(pvData[vid][cOwner] == pData[playerid][pID])
	    {
     		tmpcount++;
       		if(tmpcount == hslot)
       		{
        		return vid;
  			}
	    }
	}
	return -1;
}

function OnLoadCarStorage(carid)
{
	new name[128];
	new count = cache_num_rows();
	if(count > 0)
	{
	    for(new i = 0; i < count; i++)
	    {
			CarStorage[carid][i][cItemExists] = true;
			cache_get_value_name_int(i, "itemID", CarStorage[carid][i][cItemID]);
			cache_get_value_name_int(i, "itemModel", CarStorage[carid][i][cItemModel]);
			cache_get_value_name_int(i, "itemQuantity", CarStorage[carid][i][cItemQuantity]);

			cache_get_value_name(i, "itemName", name);
			strpack(CarStorage[carid][i][cItemName], name, 32 char);
		}
	}
	return 1;
}

stock Car_GetFreeID(carid)
{
	if (carid == -1)
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        return i;
	}
	return -1;
}


stock Car_AddItem(carid, item[], model, quantity = 1, slotid = -1)
{
    if (carid == -1 )
	    return 0;

	new
		itemid = Car_GetItemID(carid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = Car_GetFreeID(carid);

	    if (itemid != -1)
	    {
	        if (slotid != -1)
	            itemid = slotid;

	        CarStorage[carid][itemid][cItemExists] = true;
	        CarStorage[carid][itemid][cItemModel] = model;
	        CarStorage[carid][itemid][cItemQuantity] = quantity;

	        strpack(CarStorage[carid][itemid][cItemName], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `carstorage` (`ID`, `itemName`, `itemModel`, `itemQuantity`) VALUES('%d', '%s', '%d', '%d')",pvData[carid][cID], item, model, quantity);
			mysql_tquery(g_SQL , string, "OnCarStorageAdd", "dd", carid, itemid);

	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `carstorage` SET `itemQuantity` = `itemQuantity` + %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity,pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
	    mysql_tquery(g_SQL , string);

	    CarStorage[carid][itemid][cItemQuantity] += quantity;
	}
	return itemid;
}

stock Car_GetItemID(carid, item[])
{
	if (carid == -1 )
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        continue;

		if (!strcmp(CarStorage[carid][i][cItemName], item)) return i;
	}
	return -1;
}
	
stock Car_RemoveItem(carid, item[], quantity = 1)
{
    if (carid == -1 )
	    return 0;

	new
		itemid = Car_GetItemID(carid, item),
		string[128];

	if (itemid != -1)
	{
	    if (CarStorage[carid][itemid][cItemQuantity] > 0)
	    {
	        CarStorage[carid][itemid][cItemQuantity] -= quantity;
		}
		if (quantity == -1 || CarStorage[carid][itemid][cItemQuantity] < 1)
		{
		    CarStorage[carid][itemid][cItemExists] = false;
		    CarStorage[carid][itemid][cItemModel] = 0;
		    CarStorage[carid][itemid][cItemQuantity] = 0;

		    format(string, sizeof(string), "DELETE FROM `carstorage` WHERE `ID` = '%d' AND `itemID` = '%d'",pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
	        mysql_tquery(g_SQL , string);
		}
		else if (quantity != -1 && CarStorage[carid][itemid][cItemQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `carstorage` SET `itemQuantity` = `itemQuantity` - %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity,pvData[carid][cID], CarStorage[carid][itemid][cItemID]);
            mysql_tquery(g_SQL , string);
		}
		return 1;
	}
	return 0;
}

Car_ShowTrunk(playerid, carid)
{
	static
	    string[MAX_CAR_STORAGE * 32],
		name[32];

	string[0] = 0;

	for (new i = 0; i != MAX_CAR_STORAGE; i ++)
	{
	    if (!CarStorage[carid][i][cItemExists])
	        format(string, sizeof(string), "%sEmpty Slot\n", string);

		else {
			strunpack(name, CarStorage[carid][i][cItemName]);

			if (CarStorage[carid][i][cItemQuantity] == 1) {
                format(string, sizeof(string), "%s%s\n", string, name);
			}
			else format(string, sizeof(string), "%s%s (%d)\n", string, name, CarStorage[carid][i][cItemQuantity]);
		}
	}
	strcat(string, "Weapon Storage");

	AccountData[playerid][pStorageSelect] = 0;
	ShowPlayerDialog(playerid, DIALOG_TRUNK, DIALOG_STYLE_LIST, "Vehicle Storage", string, "Select", "Cancel");
	return 1;
}

CMD:trunk(playerid, params[])
{
	new
	    id = Vehicle_Nearest(playerid),
		vid = GetNearestVehicle(playerid, 4.0);

	if (id != -1 && Vehicle_IsOwner(playerid, id))
	{
	    if (IsPlayerInAnyVehicle(playerid))
	        return SendErrorMessage(playerid, "You must exit the vehicle first.");

		if (!IsDoorVehicle(vid))
		    return SendErrorMessage(playerid, "This vehicle doesn't have a trunk.");

		if (pvData[id][cLocked])
		    return SendErrorMessage(playerid, "The vehicle's trunk is locked.");

		Car_ShowTrunk(playerid, id);
		AccountData[playerid][pCar] = id;
	}
	else
	    SendErrorMessage(playerid, "You're not close with your own Vehicle!");
	return 1;
}

Car_WeaponStorage(playerid, carid)
{
    static
	    string[164];

	string[0] = 0;

	for (new i = 0; i < 5; i ++)
	{
	    if (22 <= pvData[carid][cWeapons][i] <= 38)
	        format(string, sizeof(string), "%s%s - Ammo: %d\n", string, ReturnWeaponName(pvData[carid][cWeapons][i]), pvData[carid][cAmmo][i]);

		else
		    format(string, sizeof(string), "%s%s\n", string, (pvData[carid][cWeapons][i]) ? (ReturnWeaponName(pvData[carid][cWeapons][i])) : ("Empty Slot"));
	}
	ShowPlayerDialog(playerid, DIALOG_TRUNKWEAPON, DIALOG_STYLE_LIST, "Vehicle Trunk", string, "Select", "Cancel");
	return 1;
}

Dialog:DIALOG_INVA(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new
		    name[48],
			id = -1;
			
        strunpack(name, InventoryData[playerid][listitem][invItem]);
        AccountData[playerid][pListitem] = listitem;

		switch (AccountData[playerid][pStorageSelect])
		{
			case 1:
			{
				if ((id = AccountData[playerid][pCar]) != -1)
				{        
					if (InventoryData[playerid][listitem][invQuantity] == 1)
					{
			    		Car_AddItem(id, name, InventoryData[playerid][listitem][invModel], 1);
			    		Inventory_Remove(playerid, name);

			    		SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has stored a \"%s\" into the trunk.", ReturnName(playerid), name);
				 		Car_ShowTrunk(playerid, id);
			    	}
			    	else
					{
					    new ztr[128];
					    format(ztr, sizeof(ztr), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryData[playerid][AccountData[playerid][pListitem]][invQuantity]);
						ShowPlayerDialog(playerid, DIALOG_TRUNKPUT, DIALOG_STYLE_INPUT, "Trunk Deposit", ztr, "Store", "Back");
					}
				}
			}			
		}
					
	}
	return 1;
}

stock IsDoorVehicle(vehicleid)
{
	switch (GetVehicleModel(vehicleid))
	{
		case 400..424, 426..429, 431..440, 442..445, 451, 455, 456, 458, 459, 466, 467, 470, 474, 475:
		    return 1;

		case 477..480, 482, 483, 486, 489, 490..492, 494..496, 498..500, 502..508, 514..518, 524..529, 533..536:
		    return 1;

		case 540..547, 549..552, 554..562, 565..568, 573, 575, 576, 578..580, 582, 585, 587..589, 596..605, 609:
			return 1;
	}
	return 0;
}

function OpenInventory(playerid)
{
    if (!IsPlayerConnected(playerid))
	    return 0;

	new
	    items[MAX_INVENTORY],
		amounts[MAX_INVENTORY],
		str[512],
		string[256];

	new count = 0;
	format(str, sizeof(str), "Name\tAmount\n");
	for (new i = 0; i < 20; i ++)
	{
		if (InventoryData[playerid][i][invExists])
	    {
	        count++;
			items[i] = InventoryData[playerid][i][invModel];
			amounts[i] = InventoryData[playerid][i][invQuantity];
			strunpack(string, InventoryData[playerid][i][invItem]);
			format(str, sizeof(str), "%s\n%s\t%d", str, string, amounts[i]);
		}
	}
	if(count)
	{
		Dialog_Show(playerid, DIALOG_INVA, DIALOG_STYLE_TABLIST_HEADERS, "Inventory Data", str, "Select", "Close");
	}
	else
	{
	    SendErrorMessage(playerid, "There is no item exists on your Inventory!");
	}
	return 1;
}