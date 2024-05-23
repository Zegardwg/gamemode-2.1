#include <YSI\y_hooks>

#define MAX_MARKET 100

enum E_MARKETSTUFF
{
	Float: clotX,
	Float: clotY,
	Float: clotZ,
    clotInt,
    clotWorld,
    STREAMER_TAG_PICKUP:clotPickup,
    STREAMER_TAG_MAP_ICON:clotIcon,
    Text3D:clotLabel,
    clotArea
}
new MarketData[MAX_MARKET][E_MARKETSTUFF],
	Iterator:MARKETS<MAX_MARKET>;

FUNC::LoadMarket()
{
	new rows;
	cache_get_row_count(rows);
	if(rows)
  	{
 		new id, i = 0, str[55];
		while(i < rows)
		{
		    cache_get_value_name_int(i, "id", id);
			cache_get_value_name_float(i, "posx", MarketData[id][clotX]);
			cache_get_value_name_float(i, "posy", MarketData[id][clotY]);
			cache_get_value_name_float(i, "posz", MarketData[id][clotZ]);
			cache_get_value_name_int(i, "interior", MarketData[id][clotInt]);
			cache_get_value_name_int(i, "world", MarketData[id][clotWorld]);
			format(str, 200, "Tekan "LG_E"Y {FFFFFF}untuuk membeli barang");
			MarketData[id][clotLabel] = CreateDynamic3DTextLabel(str, COLOR_WHITE, MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, MarketData[id][clotWorld], MarketData[id][clotInt], -1, 10.0);
			MarketData[id][clotArea] = CreateDynamicSphere(MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 1.3);
            MarketData[id][clotIcon] = CreateDynamicMapIcon(MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 17, -1);
			Iter_Add(MARKETS, id);
	    	i++;
		}
		printf("[POINT MARKET]: %d Loaded.", i);
	}
}

Market_Save(id)
{
	new cQuery[512];
	format(cQuery, sizeof(cQuery), "UPDATE markets SET posx='%f', posy='%f', posz='%f', interior='%d', world='%d' WHERE id='%d'",
	MarketData[id][clotX],
	MarketData[id][clotY],
	MarketData[id][clotZ], 
	MarketData[id][clotInt],
	MarketData[id][clotWorld],
	id
	);
	return mysql_tquery(g_SQL, cQuery);
}


FUNC::OnMarketCreated(playerid, id)
{
	Market_Save(id);
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
        forex(i, MAX_MARKET)
        {
            if(IsPlayerInDynamicArea(playerid, MarketData[i][clotArea]))
            {
                Dialog_Show(playerid, DIALOG_WARUNGMENU, DIALOG_STYLE_TABLIST_HEADERS, "Markets Shop", "Item\t:\tPrice\nRoti Cokelat\t-\t"LG_E"$350\nKopi\t-\t"LG_E"$230\nIce Cream\t-\t"LG_E"$370", "Pilih", "Batal");
            }	
        }
    }
    return 1;
}

CMD:createmarket(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return ErrorMsg(playerid, "You don't have permission to use this command!");
		
	new id = Iter_Free(MARKETS), query[512];
	if(id == -1) return ErrorMsg(playerid, "Can't add any more Market.");
 	new Float: x, Float: y, Float: z;
 	GetPlayerPos(playerid, x, y, z);
	
	MarketData[id][clotX] = x;
	MarketData[id][clotY] = y;
	MarketData[id][clotZ] = z;
	MarketData[id][clotInt] = GetPlayerInterior(playerid);
	MarketData[id][clotWorld] = GetPlayerVirtualWorld(playerid);
	
    new str[200];
	format(str, 200, "Tekan "LG_E"Y {FFFFFF}untuk membeli barang");
	MarketData[id][clotLabel] = CreateDynamic3DTextLabel(str, COLOR_WHITE, MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, MarketData[id][clotWorld], MarketData[id][clotInt], -1, 10.0);
	MarketData[id][clotArea] = CreateDynamicSphere(MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 1.3);
	MarketData[id][clotIcon] = CreateDynamicMapIcon(MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], 17, -1);
	Iter_Add(MARKETS, id);
	
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO markets SET id='%d', posx='%f', posy='%f', posz='%f', interior='%d', world='%d'", id, MarketData[id][clotX], MarketData[id][clotY], MarketData[id][clotZ], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
	mysql_tquery(g_SQL, query, "OnMarketCreated", "ii", playerid, id);
	return 1;
}

CMD:removemarket(playerid, params[])
{
    if(pData[playerid][pAdmin] < 3)
		return ErrorMsg(playerid, "You don't have permission to use this command!");
		
	new id, query[512];
	if(sscanf(params, "i", id)) return SyntaxMsg(playerid, "/removemarket [id]");
	if(!Iter_Contains(MARKETS, id)) return ErrorMsg(playerid, "Invalid ID.");
	
	DestroyDynamicArea(MarketData[id][clotArea]);
	DestroyDynamic3DTextLabel(MarketData[id][clotLabel]);
	DestroyDynamicMapIcon(MarketData[id][clotIcon]);

	MarketData[id][clotX] = MarketData[id][clotY] = MarketData[id][clotZ] = 0.0;
	MarketData[id][clotInt] = MarketData[id][clotWorld] = 0;
	Iter_Remove(MARKETS, id);
	
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM markets WHERE id=%d", id);
	mysql_tquery(g_SQL, query);
	return 1;
}

Dialog:DIALOG_WARUNGMENU(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                if(pData[playerid][pMoney] < 350)
                    return InfoMsg(playerid, "Uang anda tidak cukup");

                Inventory_Add(playerid, "Roti Cokelat", 19883, 1);
                GiveMoney(playerid, 350);
            }
            case 1:
            {
                if(pData[playerid][pMoney] < 230)
                    return InfoMsg(playerid, "Uang anda tidak cukup"); 

                Inventory_Add(playerid, "Kopi", 19835, 1);
                GiveMoney(playerid, 230);               
            }   
            case 2:
            {
                if(pData[playerid][pMoney] < 370)
                    return InfoMsg(playerid, "Uang anda tidak cukup"); 

                Inventory_Add(playerid, "Ice Cream", 19567, 1);
                GiveMoney(playerid, 370);               
            }                     
        }
    }
    return 1;
}