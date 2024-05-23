//inv
new PlayerText:OtrpInv[MAX_PLAYERS][117];
new PlayerText:NAMETD[MAX_PLAYERS][40];
new PlayerText:INDEXTD[MAX_PLAYERS][40];
new PlayerText:MODELTD[MAX_PLAYERS][40];
new PlayerText:AMOUNTTD[MAX_PLAYERS][40];
new PlayerText:GARISBAWAH[MAX_PLAYERS][40];
new PlayerText:NameInv[MAX_PLAYERS][1];
new PlayerText:KgInv[MAX_PLAYERS][1];

#define MAX_INVENTORY 20
enum inventoryData
{
	invExists,
	invID,
	invItem[32 char],
	invModel,
    invAmount,
	invQuantity,
 	invTotalQuantity
};
new InventoryData[MAX_PLAYERS][MAX_INVENTORY][inventoryData];

enum e_InventoryItems
{
	e_InventoryItem[32],
	e_InventoryModel,
	Float: e_InventoryWeight
};

new const g_aInventoryItems[][e_InventoryItems] =
{
	{"Handphone", 18867, 0.001},
	{"Kevlar", 1242, 0.050},
	{"Backpack", 2919, 1.000},
	{"Ayam Hidup", 16776, 0.100},
	{"Sampah", 2840, 0.120},	
	{"Ayam Potong", 2806, 0.125},
	{"Ayam Kemas", 2768, 0.110},

	{"Bulu", 1974, 0.025},
	{"Benang", 1931, 0.030},
	{"Kain", 2384, 0.050},
	{"Pakaian", 2689, 0.080},

	{"Nasi Goreng", 2354, 0.127},
	{"Es Teh", 2647, 0.127},
	{"Roti Cokelat", 19883, 0.127},
	{"Kopi", 19835, 0.127},
	{"Ice Cream", 19567, 0.127},

	{"Ktp", 19792, 0.080},
	{"Sks", 19792, 0.080},	
	{"Skck", 19792, 0.080},
	{"Bpjs", 19792, 0.080},
	{"Sim", 19792, 0.080},

	{"Creatine", 1950, 1.000},		
	{"Protein", 1951, 1.000},

	//medis
	{"P3K", 11738, 0.150},
	{"Kertas", 2684, 0.001},	
	{"Pil Stress", 1241, 0.100},	
	{"Perban", 11747, 0.020},

	{"Clip Pistol", 2041, 0.050},	
	{"Clip Rifle", 2041, 0.050},
	{"Clip SMG", 2041, 0.050}		
};

FUNC::OnPlayerUseItem(playerid, itemid, name[]) 
{
	if(!strcmp(name, "Backpack"))
	{
		Inventory_Close(playerid);
		ShowProgressbar(playerid, "MEMBUKA TAS", 5);

		Inventory_Remove(playerid, "Backpack");

		GiveMoney(playerid, 2500);
		Inventory_Add(playerid, "Handphone", 18867, 1);
		Inventory_Add(playerid, "Nasi Goreng", 2354, 10);
		Inventory_Add(playerid, "Es Teh", 2647, 10);
	}
	else if(!strcmp(name, "Creatine"))
	{
		Inventory_Close(playerid);
		ShowProgressbar(playerid, "MENGGUNAKAN CREATINE", 5);

		Inventory_Remove(playerid, "Creatine");
		AccountData[playerid][UseCreatine] = 1;
	}
	else if(!strcmp(name, "Protein"))
	{
		Inventory_Close(playerid);
		ShowProgressbar(playerid, "MENGGUNAKAN PROTEIN", 5);

		Inventory_Remove(playerid, "Protein");
		AccountData[playerid][UseProtein] = 1;
	}	
	else if(!strcmp(name, "Nasi Goreng"))
	{
        if (PlayerData[playerid][pHunger] > 90) 
            return Info(playerid, "You're not hungry.");

        PlayerData[playerid][pHunger] += 25; 
		Inventory_Remove(playerid, "Nasi Goreng", 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        Action(playerid, "Take Nasi Goreng then eat them.");
        SetPlayerChatBubble(playerid, "> Take Nasi Goreng then eat them <", COLOR_PURPLE, 30.0, 5000);		
	}	
	else if(!strcmp(name, "Es Teh"))
	{
        if (PlayerData[playerid][pEnergy] > 90) 
            return Info(playerid, "You're not thirsty.");

        PlayerData[playerid][pEnergy] += 25; 
		Inventory_Remove(playerid, "Es Teh", 1);
		ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        Action(playerid, "Take Es Teh then drink it.");
        SetPlayerChatBubble(playerid, "> Take Es Teh then drink it <", COLOR_PURPLE, 30.0, 5000);		
	}		
	else if(!strcmp(name, "Roti Cokelat"))
	{
        if (PlayerData[playerid][pHunger] > 90) 
            return Info(playerid, "You're not hungry.");

        PlayerData[playerid][pHunger] += 15; 
		Inventory_Remove(playerid, "Roti Cokelat", 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        Action(playerid, "Take Roti Cokelat then eat them.");
        SetPlayerChatBubble(playerid, "> Take Roti Cokelat then eat them <", COLOR_PURPLE, 30.0, 5000);		
	}		
	else if(!strcmp(name, "Kopi"))
	{
        if (PlayerData[playerid][pEnergy] > 90) 
            return Info(playerid, "You're not thirsty.");

        PlayerData[playerid][pEnergy] += 15; 
		PlayerData[playerid][pBladder] -= 5; 
		Inventory_Remove(playerid, "Kopi", 1);
		ApplyAnimation(playerid, "VENDING", "VEND_DRINK2_P", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        Action(playerid, "Take Kopi then drink it.");
        SetPlayerChatBubble(playerid, "> Take Kopi then drink it <", COLOR_PURPLE, 30.0, 5000);		
	}			
	else if(!strcmp(name, "Ice Cream"))
	{
        if (PlayerData[playerid][pHunger] > 90) 
            return Info(playerid, "You're not hungry.");
        if (PlayerData[playerid][pEnergy] > 90) 
            return Info(playerid, "You're not thirsty.");			

        PlayerData[playerid][pHunger] += 10; 
		PlayerData[playerid][pEnergy] += 10; 
		PlayerData[playerid][pBladder] -= 5; 
		Inventory_Remove(playerid, "Ice Cream", 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		Inventory_Close(playerid);
        Action(playerid, "Take Ice Cream then eat them.");
        SetPlayerChatBubble(playerid, "> Take Ice Cream then eat them <", COLOR_PURPLE, 30.0, 5000);		
	}		
    else if (!strcmp(name, "Kevlar"))
    {
		new get = GetPlayerArmour(playerid, AccountData[playerid][pArmour]);
		if(get > 99) return ErrorMsg(playerid, "Anda tidak bisa menggunakan kevlar");
		if(get > 100) get = 100;
		if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih dalam activity progress");
        Inventory_Remove(playerid, "Kevlar", 1);
		SetTimerEx("pakek_kevlar", 5000, 0, "i", playerid);
		ShowProgressbar(playerid, "Menggunakan Kevlar..", 5); 
		Inventory_Close(playerid);  
    }		
	else if(!strcmp(name, "Perban"))
	{
		new Float: health;
		GetPlayerHealth(playerid, health);
		new get = GetPlayerHealth(playerid, AccountData[playerid][pHealth]);
		if(get > 99) return ErrorMsg(playerid, "Anda tidak bisa menggunakan perban");
		if(get > 100) get = 100;

		GivePlayerHealth(playerid, get + 40.0);
		if(pData[playerid][pHealth] > 100) pData[playerid][pHealth] = 100;

		Inventory_Remove(playerid, "Perban", 1);
		Inventory_Close(playerid);
	}			
	else if(!strcmp(name, "Pil Stress"))
	{
        if(AccountData[playerid][pBladder] < 30) 
            return InfoMsg(playerid, "Kamu tidak sedang stress");

        AccountData[playerid][pBladder] -= 30;
		Inventory_Remove(playerid, "Pil Stress", 1);
		ApplyAnimation(playerid, "FOOD", "EAT_Burger", 4.1, 0, 0, 0, 0, 0, 1);
		if(pData[playerid][pBladder] < 50)
		{
			SetPlayerDrunkLevel(playerid, 0);
		}
		Inventory_Close(playerid);
	}	
    return 1;
}

stock Inventory_Clear(playerid)
{
	static
	    string[64];

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (InventoryData[playerid][i][invExists])
	    {
	        InventoryData[playerid][i][invExists] = 0;
	        InventoryData[playerid][i][invModel] = 0;
	        InventoryData[playerid][i][invQuantity] = 0;
	        InventoryData[playerid][i][invTotalQuantity] = 0;
			PlayerData[playerid][pWeight] = 0.00;
		}
	}
	format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d'", PlayerData[playerid][pID]);
	return mysql_tquery(g_SQL, string);
}

stock Inventory_GetItemID(playerid, item[])
{
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return i;
	}
	return -1;
}

stock Inventory_GetFreeID(playerid)
{
	if (Inventory_Items(playerid) >= 20)
		return -1;

	for(new i = 0; i < MAX_INVENTORY; i++)
	{
	    if (!InventoryData[playerid][i][invExists])
	        return i;
	}
	return -1;
}

stock Inventory_Items(playerid)
{
    new count;

    for(new i = 0; i < MAX_INVENTORY; i++) if (InventoryData[playerid][i][invExists]) {
        count++;
	}
	return count;
}

stock Inventory_Count(playerid, item[])
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid != -1)
	    return InventoryData[playerid][itemid][invQuantity];

	return 0;
}

stock PlayerHasItem(playerid, item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

stock Inventory_Sets(playerid, item[], model, amount)
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1 && amount > 0)
		Inventory_AddSets(playerid, item, model, amount);

	else if (amount > 0 && itemid != -1)
	    Inventory_SetQuantity(playerid, item, amount);

	else if (amount < 1 && itemid != -1)
	    Inventory_Remove(playerid, item, -1);

	return 1;
}

stock Inventory_AddSets(playerid, item[], model, amount = 1)
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
	   		InventoryData[playerid][itemid][invExists] = true;
		    InventoryData[playerid][itemid][invModel] = model;
			InventoryData[playerid][itemid][invAmount] = amount;

		    strpack(InventoryData[playerid][itemid][invItem], item, 32 char);
		    return itemid;
		}
		return -1;
	}
	else
	{
		InventoryData[playerid][itemid][invAmount] += amount;
	}
	return itemid;
}

stock Inventory_AddSet(playerid, item[], model, quantity = 1, totalquantity)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
	        InventoryData[playerid][itemid][invExists] = true;
	        InventoryData[playerid][itemid][invModel] = model;
	        InventoryData[playerid][itemid][invQuantity] = quantity;
	        InventoryData[playerid][itemid][invTotalQuantity] = totalquantity;

	        strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`, `invTotal`) VALUES('%d', '%s', '%d', '%d', '%d')", PlayerData[playerid][pID], item, model, quantity, totalquantity);
            mysql_tquery(g_SQL, string, "OnInventoryAdd", "ii", playerid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
	    mysql_tquery(g_SQL, string);

	   	format(string, sizeof(string), "UPDATE `inventory` SET `invTotal` = `invTotal` + %d WHERE `ID` = '%d' AND `invID` = '%d'", totalquantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
   		mysql_tquery(g_SQL, string);

	    InventoryData[playerid][itemid][invQuantity] += quantity;
	    InventoryData[playerid][itemid][invTotalQuantity] += totalquantity;
	}
	return itemid;
}

stock Inventory_Set(playerid, item[], model, amount)
{
    new itemid = Inventory_GetItemID(playerid, item);

    if(amount > 0)
        Inventory_Add(playerid, item, model, amount);

    else if(amount < 1 && itemid != -1)
        Inventory_Remove(playerid, item, InventoryData[playerid][itemid][invQuantity]);

    return 1;
}

stock Inventory_SetQuantity(playerid, item[], quantity)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid != -1)
	{
		format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
		mysql_tquery(g_SQL, string);

		InventoryData[playerid][itemid][invQuantity] = quantity;
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			new Float:Weight = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
			PlayerData[playerid][pWeight] += Weight;
		}
	}
	return 1;
}

stock Inventory_GetInventoryID(playerid ,item[])
{
	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
		if (!InventoryData[playerid][i][invExists])
			continue;

		if (!strcmp(InventoryData[playerid][i][invItem], item)) return InventoryData[playerid][i][invID];
	}
	return -1;
}

stock Inventory_Remove(playerid, item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		invid = Inventory_GetInventoryID(playerid, item),
		string[128];    
	if (itemid != -1)
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
		{
			PlayerData[playerid][pWeight] -= quantity*g_aInventoryItems[i][e_InventoryWeight];
			if(PlayerData[playerid][pWeight] <= 0.0) PlayerData[playerid][pWeight] = 0.0;
            ShowItemBox(playerid, item, sprintf("Removed_%dx", quantity), InventoryData[playerid][itemid][invModel], 3);
		}
		if (InventoryData[playerid][itemid][invQuantity] > 0)
		{
			InventoryData[playerid][itemid][invQuantity] -= quantity;
		}
		if (quantity == -1 || InventoryData[playerid][itemid][invQuantity] < 1)
		{
			InventoryData[playerid][itemid][invExists] = false;
			InventoryData[playerid][itemid][invModel] = 19300;
			InventoryData[playerid][itemid][invQuantity] = 0;

			format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", PlayerData[playerid][pID], invid);
			mysql_tquery(g_SQL, string);
		}
		else if (quantity != -1 && InventoryData[playerid][itemid][invQuantity] > 0)
		{
			format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
			mysql_tquery(g_SQL, string);
		}
		return 1;
	}
	return 0;
}

stock Inventory_Add(playerid, item[], model, quantity = 1)
{
    new
        itemid = Inventory_GetItemID(playerid, item),
        string[318];

    if(PlayerData[playerid][pWeight] >= 150) {ErrorMsg(playerid, "Inventory anda sudah penuh!"); return -2;}
    if (itemid == -1)
    {
        itemid = Inventory_GetFreeID(playerid);

        if (itemid != -1)
        {

			if(!strcmp(item, "Radio", true)) {
				CallRemoteFunction("OnPlayerHaveRadio", "d", playerid);
			}

            new Float:Weights;
            for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
            {
                Weights = float(quantity)*g_aInventoryItems[i][e_InventoryWeight];
            }
            if(PlayerData[playerid][pWeight]+Weights >= 150) {ErrorMsg(playerid, "Inventory anda sudah penuh!"); return 1;}
            PlayerData[playerid][pWeight] += Weights;
            InventoryData[playerid][itemid][invExists] = true;
            InventoryData[playerid][itemid][invModel] = model;
            InventoryData[playerid][itemid][invQuantity] = quantity;

            strpack(InventoryData[playerid][itemid][invItem], item, 32 char);

            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`) VALUES('%d', '%s', '%d', '%d')", PlayerData[playerid][pID], item, model, quantity);
            mysql_tquery(g_SQL, string, "OnInventoryAdd", "ii", playerid, itemid);
            return itemid;
        }
        return -1;
    }
    else
    {
        new Float:totalquantity = 0;
        for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true)) {
            totalquantity = g_aInventoryItems[i][e_InventoryWeight];
            break;
        }
        format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
        mysql_tquery(g_SQL, string);

        format(string, sizeof(string), "UPDATE `inventory` SET `invTotal` = `invTotal` + %d WHERE `ID` = '%d' AND `invID` = '%d'", totalquantity, PlayerData[playerid][pID], InventoryData[playerid][itemid][invID]);
        mysql_tquery(g_SQL, string);

        InventoryData[playerid][itemid][invQuantity] += quantity;
        for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
        {
            PlayerData[playerid][pWeight] += quantity*g_aInventoryItems[i][e_InventoryWeight];
        }
        printf("inventory ID: %d, DBID: %d, quantity: %d, total: %d", itemid, InventoryData[playerid][itemid][invID], quantity, totalquantity);
    }
    return itemid;
}

FUNC::OnInventoryAdd(playerid, itemid)
{
	InventoryData[playerid][itemid][invID] = cache_insert_id();
	return 1;
}

FUNC::LoadPlayerItems(playerid)
{
	new name[128];
	new count = cache_num_rows();
	if(count > 0)
	{
	    forex(i, count)
	    {
	        InventoryData[playerid][i][invExists] = true;

	        cache_get_value_name_int(i, "invID", InventoryData[playerid][i][invID]);
	        cache_get_value_name_int(i, "invModel", InventoryData[playerid][i][invModel]);
	        cache_get_value_name_int(i, "invQuantity", InventoryData[playerid][i][invQuantity]);
	        cache_get_value_name(i, "invItem", name);

			strpack(InventoryData[playerid][i][invItem], name, 32 char);
			for (new id = 0; id < sizeof(g_aInventoryItems); id ++) if(!strcmp(g_aInventoryItems[id][e_InventoryItem], InventoryData[playerid][i][invItem], true))
			{
				PlayerData[playerid][pWeight] += float(InventoryData[playerid][i][invQuantity])*g_aInventoryItems[id][e_InventoryWeight];
			}				
		}
	}
	return 1;
}

CMD:setitem(playerid, params[])
{
	new
	    userid,
		item[32],
		amount;

	if (sscanf(params, "uds[32]", userid, amount, item))
	    return SendClientMessage(playerid, -1, "/setitem [playerid/name] [amount] [item name]");

	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
	{
        new id = Inventory_Set(userid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], amount);
        if(id == -1) return SendClientMessage(playerid, -1, "Anda tidak memiliki slot inventory yang tersisa.");
	}
	return 1;
}

CMD:itemlist(playerid, params[])
{
	new string[1024];

	if (!strlen(string))
	{
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++)
		{
			format(string, sizeof(string), "%s%s\n", string, g_aInventoryItems[i][e_InventoryItem]);
		}
	}
	return Dialog_Show(playerid, INVALID_DIALOG_ID, DIALOG_STYLE_LIST, "List of Items", string, "Select", "Cancel");
}

stock Inventory_Close(playerid) {

	CancelSelectTextDraw(playerid);
	PlayerData[playerid][pSelectItem] = -1;
	forex(i, 117)
	{
		PlayerTextDrawHide(playerid, OtrpInv[playerid][i]);
	}
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		PlayerTextDrawHide(playerid, NAMETD[playerid][i]);
		PlayerTextDrawHide(playerid, INDEXTD[playerid][i]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][i], 1499163000);
		PlayerTextDrawHide(playerid, MODELTD[playerid][i]);
		PlayerTextDrawHide(playerid, AMOUNTTD[playerid][i]);
		PlayerTextDrawHide(playerid, GARISBAWAH[playerid][i]);
		PlayerTextDrawHide(playerid, NameInv[playerid][i]);
		PlayerTextDrawHide(playerid, KgInv[playerid][i]);
	}
    PlayerData[playerid][pSelectItem] = -1;
    return 1;
}

stock ShowInventory(playerid)
{
	SelectTextDraw(playerid, C_ADMIN);
	new str[256], string[256];

	forex(i, 117)
	{
		PlayerTextDrawShow(playerid, OtrpInv[playerid][i]);
	}

	format(str,1000,"%s", pData[playerid][pName]);
	PlayerTextDrawSetString(playerid, NameInv[playerid][0], str);
	PlayerTextDrawSetString(playerid, OtrpInv[playerid][33], "JUMLAH");
	PlayerPlaySound(playerid, 1039, 0,0,0);
	
	for (new i = 0; i < MAX_INVENTORY; i ++) 
	{
		PlayerTextDrawShow(playerid, INDEXTD[playerid][i]);
		PlayerTextDrawShow(playerid, NameInv[playerid][i]);
		PlayerTextDrawShow(playerid, KgInv[playerid][i]);

		if(InventoryData[playerid][i][invExists])
		{
			format(str, sizeof(str), "H %.3f/150.0 Kg", pData[playerid][pWeight]);
			PlayerTextDrawSetString(playerid, KgInv[playerid][0], str);
			PlayerTextDrawShow(playerid, NAMETD[playerid][i]);
			PlayerTextDrawShow(playerid, GARISBAWAH[playerid][i]);
			PlayerTextDrawShow(playerid, AMOUNTTD[playerid][i]);
			PlayerTextDrawSetPreviewModel(playerid, MODELTD[playerid][i], InventoryData[playerid][i][invModel]);

			PlayerTextDrawShow(playerid, MODELTD[playerid][i]);
			strunpack(string, InventoryData[playerid][i][invItem]);
			format(str, sizeof(str), "%s", string);
			PlayerTextDrawSetString(playerid, NAMETD[playerid][i], str);
			format(str, sizeof(str), "%d", InventoryData[playerid][i][invQuantity]);
			PlayerTextDrawSetString(playerid, AMOUNTTD[playerid][i], str);

			new Float:bar;
			bar = pData[playerid][pWeight] * 298.5/150;
			PlayerTextDrawTextSize(playerid,OtrpInv[playerid][4], bar, 167.0);
			PlayerTextDrawShow(playerid,OtrpInv[playerid][4]);
		}
		else
		{
			//PlayerTextDrawHide(playerid, AMOUNTTD[playerid][i]);
		}
	}
	return 1;
}

stock Inventory_Update(playerid)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	new str[256], str2[200], string[256], quantitybar;
	for(new i = 0; i < MAX_INVENTORY; i++)
	{
		format(str2, sizeof(str2), "%.3f/50.00", PlayerData[playerid][pWeight]);
		PlayerTextDrawSetString(playerid, InventoryTD2[playerid][0], str2);
		quantitybar = floatround(PlayerData[playerid][pWeight]) * 188/48;
	    PlayerTextDrawTextSize(playerid, InventoryTD2[playerid][1], quantitybar, 6.5);
		if(InventoryData[playerid][i][invExists])
		{
            strunpack(string, InventoryData[playerid][i][invItem]);
            format(str, sizeof(str), "%s", string);
            PlayerTextDrawSetString(playerid, INV2NAMETD[playerid][i], str);
            format(str, sizeof(str), "%dx", InventoryData[playerid][i][invQuantity]);
            PlayerTextDrawSetString(playerid, AMOUNTD[playerid][i], str);
           // format(str, sizeof(str), "%d.0", InventoryData[playerid][i][invQuantity]);
           // PlayerTextDrawSetString(playerid, BERATTD[playerid][i], str);
		}
		else
		{
            PlayerTextDrawHide(playerid, AMOUNTD[playerid][i]);
            //PlayerTextDrawHide(playerid, BERATTD[playerid][i]);
            PlayerTextDrawHide(playerid, INV2MODELTD[playerid][i]);
            PlayerTextDrawHide(playerid, INV2NAMETD[playerid][i]);
            PlayerTextDrawHide(playerid, BARBOX[playerid][i]);
		}
	}
	return 1;
}

stock IsValidInventoryWeight(playerid)
{
	if(PlayerData[playerid][pWeight] >= 49.00)
	{
		if(IsValidLoadingBar(playerid))
		StopPlayerLoadingBar(playerid);

        Error(playerid, "Inventory anda sudah penuh!", 3);
        ClearAnimations(playerid, 1);
        TogglePlayerControllable(playerid, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		PlayerData[playerid][pLoopAnim] = false;
		PlayerData[playerid][pApplyAnimation] = false;
		PlayerData[playerid][pIdleAnim] = false;
	}
	return 0;
}

CMD:clearitem(playerid, params[])
{
	new targetid;
	if(sscanf(params, "u", targetid))
		return SyntaxMsg(playerid, "/clearitems [playerid/PartOfName]");

	if(targetid == INVALID_PLAYER_ID)
		return ErrorMsg(playerid, "You have specified invalid player!");

	SendAdminMessage(C_ADMIN, "[AdmCmd] %s telah membersihkan inventory %s (%d)", pData[playerid][pUCP], pData[targetid][pName], targetid);
	Inventory_Clear(targetid);
	return 1;
}
stock MenuStore_SelectRow2(playerid, row)
{
	PlayerData[playerid][pSelectItem] = row;
    PlayerTextDrawHide(playerid,IndexIn[playerid][row]);
	PlayerTextDrawColor(playerid, IndexIn[playerid][row], C_ADMIN);
	PlayerTextDrawShow(playerid,IndexIn[playerid][row]);
}

stock MenuStore_UnselectRow2(playerid)
{
	if(PlayerData[playerid][pSelectItem] != -1)
	{
		new row = PlayerData[playerid][pSelectItem];
		PlayerTextDrawHide(playerid,IndexIn[playerid][row]);
		PlayerTextDrawColor(playerid, IndexIn[playerid][row], 859394047);
		PlayerTextDrawShow(playerid,IndexIn[playerid][row]);
	}

	PlayerData[playerid][pSelectItem] = -1;
}

stock MenuStore_SelectRow1(playerid, row)
{
	PlayerData[playerid][pSelectItem] = row;
    PlayerTextDrawHide(playerid,INDEXTD[playerid][row]);
	PlayerTextDrawColor(playerid, INDEXTD[playerid][row], C_ADMIN);
	PlayerTextDrawShow(playerid,INDEXTD[playerid][row]);
}

stock MenuStore_UnselectRow1(playerid)
{
	if(PlayerData[playerid][pSelectItem] != -1)
	{
		new row = PlayerData[playerid][pSelectItem];
		PlayerTextDrawHide(playerid,INDEXTD[playerid][row]);
		PlayerTextDrawColor(playerid, INDEXTD[playerid][row], 859394047);
		PlayerTextDrawShow(playerid,INDEXTD[playerid][row]);
	}

	PlayerData[playerid][pSelectItem] = -1;
}

FUNC::pakek_kevlar(playerid)
{
    new get = GetPlayerArmour(playerid, AccountData[playerid][pArmour]);
    GivePlayerArmour(playerid, get + 40.0);
	if(pData[playerid][pArmour] > 100) pData[playerid][pArmour] = 100;
	return 1;
}

stock GivePlayerHealth(playerid, Float:amount)
{
	new Float:get = GetPlayerHealth(playerid, AccountData[playerid][pHealth]);
	pData[playerid][pHealth] += get+amount;
	SetPlayerArmour(playerid, pData[playerid][pHealth]);
	return 1;
}