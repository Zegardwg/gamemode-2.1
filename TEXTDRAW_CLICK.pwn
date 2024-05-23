public OnPlayerClickDynamicTextdraw(playerid, PlayerText:playertextid)
{
    if(playertextid == DEALERMENU[playerid][26])
    {
        new vehid = Car1[listcar[playerid]];
        if(!carcolor1[playerid] && carcolor2[playerid]) return Error(playerid, "Silahkan pilih warna kendaraan");
        if(vehid < 1) return 1;
        new price = Vehicleprice(vehid);
        if(pData[playerid][pMoney] < price) return Error(playerid, "Uang anda tidak cukup");

        GiveMoney(playerid, -price);
		new cQuery[1024];
		new Float:x,Float:y,Float:z, Float:a;
		new model;
		model = vehid;
		x = 1028.601562;
		y = -1448.891845;
		z = 13.567011;
		a = 180.224700;
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "INSERT INTO `vehicle` (`owner`, `model`, `color1`, `color2`, `price`, `x`, `y`, `z`, `a`) VALUES (%d, %d, %d, %d, %d, '%f', '%f', '%f', '%f')", pData[playerid][pID], model, carcolor1[playerid], carcolor2[playerid], price, x, y, z, a);
		mysql_tquery(g_SQL, cQuery, "OnVehBuyPV", "ddddddffff", playerid, pData[playerid][pID], model, carcolor1[playerid], carcolor2[playerid], price, x, y, z, a);		

        carcolor1[playerid] = 0;
		PutPlayerInVehicle(playerid, model, 0);
        carcolor2[playerid] = 0;
        forex(i, 28)
        {
            PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 0, 0);
            PlayerTextDrawSetPreviewModel(playerid, DEALERMENU[playerid][15], 481);
            PlayerTextDrawHide(playerid, DEALERMENU[playerid][i]);
            CancelSelectTextDraw(playerid);
            listcar[playerid] = 0;
        }        
    }
    if(playertextid == DEALERMENU[playerid][25])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 126, 126);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 126;
        carcolor2[playerid] = 126;        
    }
    if(playertextid == DEALERMENU[playerid][24])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 7, 7);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 7;
        carcolor2[playerid] = 7;        
    }
    if(playertextid == DEALERMENU[playerid][23])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 6, 6);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 6;
        carcolor2[playerid] = 6;        
    }
    if(playertextid == DEALERMENU[playerid][22])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 70, 70);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 70;
        carcolor2[playerid] = 70;        
    }
    if(playertextid == DEALERMENU[playerid][21])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 0, 0);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 0;
        carcolor2[playerid] = 0;        
    }
    if(playertextid == DEALERMENU[playerid][20])
    {
        PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 1, 1);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
        carcolor1[playerid] = 1;
        carcolor2[playerid] = 1;
    }
    if(playertextid == DEALERMENU[playerid][17])
    {
	    listcar[playerid]--;
        if(listcar[playerid] < 0) listcar[playerid] = sizeof Car1 - 1;
        PlayerTextDrawSetPreviewModel(playerid, DEALERMENU[playerid][15], Car1[listcar[playerid]]);
        PlayerTextDrawSetString(playerid, DEALERMENU[playerid][18], GetVehicleModelName(Car1[listcar[playerid]]));
        PlayerTextDrawSetString(playerid, DEALERMENU[playerid][19], FormatMoney(Vehicleprice(Car1[listcar[playerid]])));
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][18]);
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][19]);        
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
    }     
    if(playertextid == DEALERMENU[playerid][16])
    {
	    listcar[playerid]++;
        if(listcar[playerid] >= sizeof Car1) listcar[playerid] = 0;
        PlayerTextDrawSetPreviewModel(playerid, DEALERMENU[playerid][15], Car1[listcar[playerid]]);
        PlayerTextDrawSetString(playerid, DEALERMENU[playerid][18], GetVehicleModelName(Car1[listcar[playerid]]));
        PlayerTextDrawSetString(playerid, DEALERMENU[playerid][19], FormatMoney(Vehicleprice(Car1[listcar[playerid]])));
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][18]);        
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][19]);        
        PlayerTextDrawShow(playerid, DEALERMENU[playerid][15]);
    }
    if(playertextid == DEALERMENU[playerid][14])
    {
        forex(i, 28)
        {
            PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 0, 0);
            PlayerTextDrawSetPreviewModel(playerid, DEALERMENU[playerid][15], 481);
            PlayerTextDrawHide(playerid, DEALERMENU[playerid][i]);
            CancelSelectTextDraw(playerid);
            listcar[playerid] = 0;
        }
    }    	
	if(playertextid == ATMTD[playerid][33])
	{
		if(amountDeposit[playerid] > 1)
		{
			if(amountDeposit[playerid] > pData[playerid][pMoney]) return ErrorMsg(playerid, "Anda tidak memiliki uang segitu.");
			if(amountDeposit[playerid] < 1) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid!");
			else
			{
				new query[512], lstr[512];
				pData[playerid][pBankMoney] = (pData[playerid][pBankMoney] + amountDeposit[playerid]);
				GiveMoney(playerid, -amountDeposit[playerid]);
				mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=%d,money=%d WHERE reg_id=%d", pData[playerid][pBankMoney], pData[playerid][pMoney], pData[playerid][pID]);
				mysql_tquery(g_SQL, query);
				format(lstr, sizeof(lstr), "Berhasil masukkan %s", FormatMoney(amountDeposit[playerid]));
				SuccesMsg(playerid, lstr);
				amountDeposit[playerid] = 0;
			}	
		}
		else ErrorMsg(playerid, "Silahkan input amount deposit");
	}			
	if(playertextid == ATMTD[playerid][24])
	{
		if(amountWithdraw[playerid] > 1)
		{
			if(amountWithdraw[playerid] > pData[playerid][pBankMoney]) return ErrorMsg(playerid, "Anda tidak memiliki uang sebanyak itu di bank.");
			if(amountWithdraw[playerid] < 1) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid!");
			else
			{
				new query[128], lstr[512];
				pData[playerid][pBankMoney] = (pData[playerid][pBankMoney] - amountWithdraw[playerid]);
				GiveMoney(playerid, amountWithdraw[playerid]);
				mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET bmoney=%d,money=%d WHERE reg_id=%d", pData[playerid][pBankMoney], pData[playerid][pMoney], pData[playerid][pID]);
				mysql_tquery(g_SQL, query);
				format(lstr, sizeof(lstr), "Berhasil mengambil uang $%s", FormatMoney(amountWithdraw[playerid]));
				SuccesMsg(playerid, lstr);
				amountWithdraw[playerid] = 0;
			}			
		}
		else ErrorMsg(playerid, "Silahkan input amount withdraw");
	}			
	if(playertextid == ATMTD[playerid][31])
	{
		Dialog_Show(playerid, DIALOG_ATMDEPO, DIALOG_STYLE_INPUT, "{a8ecff}Konoha Roleplay{FFFFFF} - Fleeca Bank", 
		"Mohon masukan nerapa jumlah uang yang ingin anda masukkan:", "Submit", "Batal");
	}			
	if(playertextid == ATMTD[playerid][22])
	{
		Dialog_Show(playerid, DIALOG_ATMWITHDRAW, DIALOG_STYLE_INPUT, "{a8ecff}Konoha Roleplay{FFFFFF} - Fleeca Bank", 
		"Mohon masukan nerapa jumlah uang yang ingin anda ambil:", "Submit", "Batal");
	}		
	if(playertextid == ATMTD[playerid][17])
	{
		PlayerTextDrawSetString(playerid, ATMTD[playerid][23], "Amount");		
		PlayerTextDrawSetString(playerid, ATMTD[playerid][32], "Amount");		
		forex(ix, 38)
		{
			PlayerTextDrawHide(playerid, ATMTD[playerid][ix]);
		}
		CancelSelectTextDraw(playerid);
	}	
	//CALL
	if(playertextid == BatalTelpon[playerid])
	{
        callcmd::offhu(playerid, "");
	}
	if(playertextid == RijekTelpon[playerid])
	{
        callcmd::ofhu(playerid, "");
	}
	if(playertextid == AngkatTelpon[playerid])
	{
        callcmd::angkattelp(playerid, "");
	}
	if(playertextid == AkhiriTelpon[playerid])
	{
        callcmd::endcall(playerid, "");
	}
	//Radial Player
	if(playertextid == PR_PANELSTD[playerid][1])// Panel Buka Smartphone
	{
		HidePanelFullNC(playerid);
        if(!Inventory_Count(playerid, "Handphone")) 
			return ErrorMsg(playerid, "Kamu tidak memilik Handphone!");

		for(new i = 0; i < 28; i++)
		{
			TextDrawShowForPlayer(playerid, HPLOCKSCREEN[i]);
		}
		PlayerPlaySound(playerid, 3600, 0,0,0);
	    SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, ""WHITE_E"ACTION: {D0AEEB}%s Telah membuka handphone miliknya", pData[playerid][pName]);
		Info(playerid, "Gunakan '/cursor'Jika mouse hilang Dari Layar/teksdraw tidak bisa ditekan!");
		SetPlayerAttachedObject(playerid, 9, 18871, 5, 0.056, 0.039, -0.015, -18.100, -108.600, 93.000, 1,1,1);
		ApplyAnimation(playerid,"ped","Jetpack_Idle",4.1, 0, 1, 1, 1, 1, 1); // Not looping
	}
	if(playertextid == PR_PANELSTD[playerid][2])// Panel Buka Identitas
	{
		HidePanelS(playerid);
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawShow(playerid, PR_IPANEL[playerid][i]);
		}
	}
	if(playertextid == PR_PANELSTD[playerid][3])// Panel Kendaraan
	{
		HidePanelS(playerid);
		for(new i = 0; i < 50; i++)
		{
			PlayerTextDrawShow(playerid, PR_KPANEL[playerid][i]);
		}
		TextDrawShowForPlayer(playerid, PR_KPANEL1[0]);
	}
	if(playertextid == PR_PANELSTD[playerid][4])// Panel Invoice
	{
		HidePanelFull(playerid);

		new header[1400], count = 0;
	    new bool:status = false;
	    format(header, sizeof(header), "Faction\tFrom\tBill Name\tAmount\n");
	    foreach(new i: tagihan)
	    {
	    	new fac[24];
			if(bilData[i][bilType] == 1)
			{
				fac = "Police";
			}
			else if(bilData[i][bilType] == 2)
			{
				fac = "Goverment";
			}
			else if(bilData[i][bilType] == 3)
			{
				fac = "Medic";
			}
			else if(bilData[i][bilType] == 4)
			{
				fac = "News";
			}
			else if(bilData[i][bilType] == 5)
			{
				fac = "Food Vendor";
			}
	        if(i != -1)
	        {
	            if(bilData[i][bilTarget] == pData[playerid][pID])
	            {
	                format(header, sizeof(header), "%s\t%s\t%s\t%s\t{00ff00}%s\n", header, fac, bilData[i][billoName], bilData[i][bilName], FormatMoney(bilData[i][bilammount]));
	                count++;
	                status = true;
	            }
	        }
	    }
	    if(status)
	    {
	        ShowPlayerDialog(playerid, DIALOG_PAYBILL, DIALOG_STYLE_TABLIST_HEADERS, "My invoice", header, "Pay", "back");
	    }
	    else
	    {
	        Error(playerid, "You have no bills");
	    }
	}
	if(playertextid == PR_PANELSTD[playerid][5])// Panel Dokumen
	{
		HidePanelS(playerid);
		for(new i = 0; i < 47; i++)
		{
			PlayerTextDrawShow(playerid, PR_DPANEL[playerid][i]);
		}
	}
	if(playertextid == PR_PANELSTD[playerid][6])// Panel Pakaian
	{
		HidePanelS(playerid);
		for(new i = 0; i < 28; i++)
		{
			PlayerTextDrawShow(playerid, PR_PPANEL[playerid][i]);
		}
	}
	if(playertextid == PR_PANELSTD[playerid][7])// Panel Inventory
	{
		HidePanelFull(playerid);
		ShowInventory(playerid);
	}
	if(playertextid == PR_PANELSTD[playerid][8])// Close Panel
	{
		HidePanelFull(playerid);
	}
	if(playertextid == PR_KPANEL[playerid][1])// Kunci Kendaraan
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

					new Float:X, Float:Y, Float:Z;
					InfoTD_MSG(playerid, 4000, "Kendaraan ini berhasil ~r~Dikunci!");
					GetPlayerPos(playerid, X, Y, Z);
					SwitchVehicleDoors(pvData[carid][cVeh], true);
				}
				else
				{
					pvData[carid][cLocked] = 0;
					new Float:X, Float:Y, Float:Z;
					InfoTD_MSG(playerid, 4000, "Kendaraan ini berhasil ~g~Terbuka!");
					GetPlayerPos(playerid, X, Y, Z);
					SwitchVehicleDoors(pvData[carid][cVeh], false);
				}
			}
				//else SendErrorMessage(playerid, "You are not in range of anything you can lock.");
		}
		else Error(playerid, "Kamu tidak berada didekat Kendaraan apapun yang ingin anda kunci.");
	}
	if(playertextid == PR_KPANEL[playerid][2])// Close Panel
	{
		HidePanelK(playerid);

		ShowPanelS(playerid);
	}
	if(playertextid == PR_KPANEL[playerid][4])// Trunk
	{
		new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);

		if(vehicleid == INVALID_VEHICLE_ID)
			return Error(playerid, "Kamu tidak berada didekat Kendaraan apapun.");

		switch (GetTrunkStatus(vehicleid))
		{
			case false:
			{
				SwitchVehicleBoot(vehicleid, true);
				InfoTD_MSG(playerid, 4000, "Vehicle Trunk ~g~OPEN");
			}
			case true:
			{
				SwitchVehicleBoot(vehicleid, false);
				InfoTD_MSG(playerid, 4000, "Vehicle Trunk ~g~OPEN");
			}
		}
		return 1;
	}
	if(playertextid == PR_KPANEL[playerid][5])// Hood
	{
		new vehicleid = GetNearestVehicleToPlayer(playerid, 3.5, false);

		if(vehicleid == INVALID_VEHICLE_ID)
			return Error(playerid, "Kamu tidak berada didekat Kendaraan apapun.");

		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);

		switch (GetHoodStatus(vehicleid))
		{
			case false:
			{
				SwitchVehicleBonnet(vehicleid, true);
				InfoTD_MSG(playerid, 4000, "Vehicle Hood ~g~OPEN");
			}
			case true:
			{
				SwitchVehicleBonnet(vehicleid, false);
				InfoTD_MSG(playerid, 4000, "Vehicle Hood ~r~CLOSED");
			}
		}
		return 1;
	}
	if(playertextid == PR_KPANEL[playerid][6])// Engine
	{
		//new vehicleid = GetPlayerVehicleID(playerid);

		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			return callcmd::v(playerid, "engine");
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	if(playertextid == PR_KPANEL[playerid][7])// bagasi
	{
		HidePanelFull(playerid);
		callcmd::trunk(playerid, "");//
	}
	if(playertextid == PR_KPANEL[playerid][8])// Lampu
	{	
		new
			vehicleid = GetPlayerVehicleID(playerid);

		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(!IsEngineVehicle(vehicleid))
				return Error(playerid, "Kamu tidak berada didalam kendaraan.");

			switch(GetLightStatus(vehicleid))
			{
				case false:
				{
					SwitchVehicleLight(vehicleid, true);
					InfoTD_MSG(playerid, 4000, "Vehicle Light ~g~ON");
				}
				case true:
				{
					SwitchVehicleLight(vehicleid, false);
					InfoTD_MSG(playerid, 4000, "Vehicle Light ~r~OFF");
				}
			}
		}
		else return Error(playerid, "Anda harus mengendarai kendaraan!");
	}
	if(playertextid == PR_IPANEL[playerid][1])// Lihat KTP
	{
		HidePanelFull(playerid);

		callcmd::ktpshow(playerid, "");
	}
	if(playertextid == PR_IPANEL[playerid][2])// Lihat Sim
	{
		HidePanelFull(playerid);

		callcmd::simshow(playerid, "");
	}
	if(playertextid == PR_IPANEL[playerid][3])// Tunjukan Sim
	{
		HidePanelFull(playerid);

		new str[500], count = 0,String[500];
        String="";
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
		{
			format(str, sizeof(str), "Kantong - %s (%d)\n", pData[i][pName], i);
			SetPlayerListitemValue(playerid, count++, i);
		}
		if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
		else ShowPlayerDialog(playerid, DIALOG_SHOWSIM, DIALOG_STYLE_LIST, "ValriseReality - Tunjukan SIM", str, "Pilih", "Tutup");
	}
	if(playertextid == PR_IPANEL[playerid][4])// Tunjukan KTP
	{
		//HidePanelFullNC(playerid);
		HidePanelFull(playerid);

		new str[500], count = 0,String[500];
        String="";
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
		{
			format(str, sizeof(str), "Kantong - %s (%d)\n", pData[i][pName], i);
			SetPlayerListitemValue(playerid, count++, i);
		}
		if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
		else ShowPlayerDialog(playerid, DIALOG_SHOWKTP, DIALOG_STYLE_LIST, "ValriseReality - Tunjukan KTP", str, "Pilih", "Tutup");
	}
	if(playertextid == PR_IPANEL[playerid][5])// Close Panel iden
	{
		for(new i = 0; i < 29; i++)
		{
			PlayerTextDrawHide(playerid, PR_IPANEL[playerid][i]);
		}
		ShowPanelS(playerid);
	}
	if(playertextid == PR_DPANEL[playerid][2])// Close Dokmen
	{
		for(new i = 0; i < 47; i++)
		{
			PlayerTextDrawHide(playerid, PR_DPANEL[playerid][i]);
		}
		ShowPanelS(playerid);
	}
	if(playertextid == PR_DPANEL[playerid][4])// Tunjukan SKCK
	{
		HidePanelFull(playerid);

		new str[500], count = 0,String[500];
        String="";
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
		{
			format(str, sizeof(str), "Kantong - %s (%d)\n", pData[i][pName], i);
			SetPlayerListitemValue(playerid, count++, i);
		}
		if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
		else ShowPlayerDialog(playerid, DIALOG_SHOWSKCK, DIALOG_STYLE_LIST, "ValriseReality - Tunjukan SKCK", str, "Pilih", "Tutup");
	}
	if(playertextid == PR_DPANEL[playerid][5])// Lihat SKCK
	{
		HidePanelFull(playerid);

		callcmd::showskck(playerid, "");
	}
	if(playertextid == PR_DPANEL[playerid][6])// Tunjukan SKS
	{
		HidePanelFull(playerid);

		new str[500], count = 0,String[500];
        String="";
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
		{
			format(str, sizeof(str), "Kantong - %s (%d)\n", pData[i][pName], i);
			SetPlayerListitemValue(playerid, count++, i);
		}
		if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
		else ShowPlayerDialog(playerid, DIALOG_SHOWSKS, DIALOG_STYLE_LIST, "ValriseReality - Tunjukan SKS", str, "Pilih", "Tutup");
	}
	if(playertextid == PR_DPANEL[playerid][7])// Lihat SKS
	{
		HidePanelFull(playerid);

		callcmd::showsks(playerid, "");
	}
	if(playertextid == PR_DPANEL[playerid][1])// Lihat BPJS
	{
		HidePanelFull(playerid);

		callcmd::showbpjs(playerid, "");
	}
	if(playertextid == PR_DPANEL[playerid][8])// Tunjukan BPJS
	{
		HidePanelFull(playerid);

		new str[500], count = 0,String[500];
        String="";
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 5) && i != playerid)
		{
			format(str, sizeof(str), "Kantong - %s (%d)\n", pData[i][pName], i);
			SetPlayerListitemValue(playerid, count++, i);
		}
		if(!count) ErrorMsg(playerid, "Tidak ada player lain didekat mu!");
		else ShowPlayerDialog(playerid, DIALOG_SHOWBPJS, DIALOG_STYLE_LIST, "ValriseReality - Tunjukan BPJS", str, "Pilih", "Tutup");
	}
	if(playertextid == PR_PPANEL[playerid][1])// Hat Topi
	{
		new name[MAX_PLAYER_NAME];
		new string[42];
		if(pData[playerid][pHelmet] == 0)
		{
			SetPlayerAttachedObject(playerid, 0, 18645, 2, 0.07, 0, 0, 88, 75, 0);
			pData[playerid][pHelmet] = 1;
			GetPlayerName(playerid, name, sizeof(name));
			format(string, sizeof(string), "%s memakai helm nya.", name);
			ApplyAnimation(playerid, "goggles", "goggles_put_on", 4.0, 0, 0, 0, 0, 0, 1);
			ProxDetector(15.0, playerid, string,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		}
		else  if(pData[playerid][pHelmet] == 1)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, 0)) RemovePlayerAttachedObject(playerid, 0);
			pData[playerid][pHelmet] = 0;
			GetPlayerName(playerid, name, sizeof(name));
			format(string, sizeof(string), "%s melepas helm nya.", name);
			ApplyAnimation(playerid, "goggles", "goggles_put_on", 4.0, 0, 0, 0, 0, 0, 1);
			ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		}
	}
	if(playertextid == PR_PPANEL[playerid][2])// Hat Aksesoris
	{
		HidePanelFull(playerid);
		callcmd::toys(playerid);
	}
	if(playertextid == PR_PPANEL[playerid][3])// Hat Tas
	{
		if(pData[playerid][pTas] == 0)
		{
			SuccesMsg(playerid, "Berhasil memakai Tas");
			SetPlayerAttachedObject(playerid, 4, 11745, 1, -0.090000, -0.128999, -0.028999, 90.400016, 1.300006, 26.499988, 0.600000, 0.956999, 0.669000);
		}
		else if(pData[playerid][pTas] == 1)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, 4)) RemovePlayerAttachedObject(playerid, 4);
			pData[playerid][pTas] = 0;
			SuccesMsg(playerid, "Berhasil melepas Tas");
		}
	}
	if(playertextid == PR_PPANEL[playerid][4])// Hat Kacamata
	{
		if(pData[playerid][pKacamata] == 0)
		{
			SuccesMsg(playerid, "Berhasil memakai Kacamata");
			ApplyAnimation(playerid, "goggles", "goggles_put_on", 4.0, 0, 0, 0, 0, 0, 1);
			SetPlayerAttachedObject(playerid, 4, 19008, 2, 0.09,0.04, 0.0, 88, 75, 0, 1, 1, 1);
		}
		else if(pData[playerid][pKacamata] == 1)
		{
			ApplyAnimation(playerid, "goggles", "goggles_put_on", 4.0, 0, 0, 0, 0, 0, 1);
			if(IsPlayerAttachedObjectSlotUsed(playerid, 4)) RemovePlayerAttachedObject(playerid, 4);
			pData[playerid][pKacamata] = 0;
			SuccesMsg(playerid, "Berhasil melepas Kacamata");
		}
	}
	if(playertextid == PR_PPANEL[playerid][5])// Tutup
	{
		for(new i = 0; i < 28; i++)
		{
			PlayerTextDrawHide(playerid, PR_PPANEL[playerid][i]);
		}
		ShowPanelS(playerid);
	}	
	for(new i = 0; i < MAX_INVENTORY; i++)
    {
		if(playertextid == INDEXTD[playerid][i])
        {
			if(InventoryData[playerid][i][invExists])
            {
				MenuStore_UnselectRow1(playerid);
				MenuStore_SelectRow1(playerid, i);
				new name[48];
				strunpack(name, InventoryData[playerid][PlayerData[playerid][pSelectItem]][invItem]);

			}
		}
	}
	if(playertextid == OtrpInv[playerid][30])
    {
		new id = PlayerData[playerid][pSelectItem], string[200];

		if(id == -1)
        {
		    Error(playerid, "You aren't selecting any item");
			Inventory_Close(playerid);
		}
		else
        {
		    strunpack(string, InventoryData[playerid][id][invItem]);

		    if(!PlayerHasItem(playerid, string))
            {
		   		Error(playerid, "You don't have any items on you");
                ShowInventory(playerid);
			}
			else
            {
				CallLocalFunction("OnPlayerUseItem", "dds", playerid, id, string);
			}
		}
	}
	if(playertextid == OtrpInv[playerid][31])
    {
		Inventory_Close(playerid);
	}
	if(playertextid == OtrpInv[playerid][29])
    {
		new id = PlayerData[playerid][pSelectItem];
		if(id == -1)
        {
			Inventory_Close(playerid);
			ErrorMsg(playerid, "You aren't selecting any item"), PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		}
		else{
		    if (PlayerData[playerid][pGiveAmount] < 1) 
				return ErrorMsg(playerid,"Masukan Jumlah Terlebih Dahulu"), PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);

            new Float:X, Float:Y, Float:Z;
		    GetPlayerPos(playerid, X, Y, Z);

		    new count = 0, string[100];

            format(string, sizeof(string), "ID:\n");
		    foreach(new i : Player)
            {
		        if(!IsPlayerConnected(i) || i == playerid)continue;

		        if(IsPlayerInRangeOfPoint(i, 3.0, X, Y, Z))
                {
		            format(string, sizeof(string), "%s%d\n", string, i);
		            count += 1;
		        }
		    }
			if(count != 0)
            {
		        Dialog_Show(playerid, DIALOG_GIVE, DIALOG_STYLE_TABLIST_HEADERS, "{a8ecff}Konoha Roleplay{FFFFFF} - Give Item", string, "Pilih", "Cancel");
		    }
		}
	}
	if(playertextid == OtrpInv[playerid][28])
    {
		Dialog_Show(playerid, DIALOG_INVAM, DIALOG_STYLE_INPUT, "{a8ecff}Konoha Roleplay{FFFFFF} - Set Amount", "Mohon maukkan berapa jumlah item yang akan diberikan:", "Set", "Batal");
	}	
    if(playertextid == SPAWNMENU[playerid][4])
    {
		PlayerData[playerid][pPos][0] = pData[playerid][pPosX],
		PlayerData[playerid][pPos][1] = pData[playerid][pPosY],
		PlayerData[playerid][pPos][2] = pData[playerid][pPosZ];
		PlayerData[playerid][pPos][3] = pData[playerid][pPosA];        
		InterpolateCameraPos(playerid, PlayerData[playerid][pPos][0]-2.5, PlayerData[playerid][pPos][1],250.00,PlayerData[playerid][pPos][0]-2.5, PlayerData[playerid][pPos][1], PlayerData[playerid][pPos][2]+2.5,2500,CAMERA_MOVE);
		InterpolateCameraLookAt(playerid, PlayerData[playerid][pPos][0], PlayerData[playerid][pPos][1], PlayerData[playerid][pPos][2], PlayerData[playerid][pPos][0], PlayerData[playerid][pPos][1], PlayerData[playerid][pPos][2], 2500, CAMERA_MOVE);        
        pData[playerid][PilihSpawn] = 3;
    }         
    if(playertextid == SPAWNMENU[playerid][3])
    {
        InterpolateCameraPos(playerid, 2740.1541,-2440.6343,13.6432, 2771.3376,-2437.4644,13.6377, 3000);
		InterpolateCameraLookAt(playerid, 2740.1541,-2440.6343,13.6432, 2771.3376,-2437.4644,13.6377, 3000);        
        pData[playerid][PilihSpawn] = 2;
    }      
    if(playertextid == SPAWNMENU[playerid][2])
    {
        InterpolateCameraPos(playerid, 1717.2083,-2250.4700,13.3828, 1676.7021,-2260.7058,13.5363, 3000);
		InterpolateCameraLookAt(playerid, 1717.2083,-2250.4700,13.3828, 1676.7021,-2260.7058,13.5363, 3000);        
        pData[playerid][PilihSpawn] = 1;
    }     
    if(playertextid == SPAWNMENU[playerid][1])
    {
        if(pData[playerid][PilihSpawn] == 0)
            return 1;

        if(pData[playerid][PilihSpawn] == 1)
        {
            forex(i, 9)
            {
                PlayerTextDrawHide(playerid, SPAWNMENU[playerid][i]);
            }
            CancelSelectTextDraw(playerid);
            SetSpawnInfo(playerid, 0, pData[playerid][pSkin], 1685.7356,-2238.5923,13.5469, 176.7719, 0, 0, 0, 0, 0, 0);
            SpawnPlayer(playerid);	            
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Welcome back, {00FFFF}%s!", pData[playerid][pName]);
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Happy roleplay and let's start your journey today!");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Use {FFFF00}'/ask' {FFFFFF}if you have any questions and {FFFF00}'/report' {FFFFFF}if you want to report something.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Make sure you've read {FF8C00}#basic-rules {FFFFFF}in our discord before playing any further.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> Our Discord: {FFFF00}sites.google.com/view/konoha-roleplay");			
        }
        else if(pData[playerid][PilihSpawn] == 2)
        {
            forex(i, 9)
            {
                PlayerTextDrawHide(playerid, SPAWNMENU[playerid][i]);
            }
            CancelSelectTextDraw(playerid);
            SetSpawnInfo(playerid, 0, pData[playerid][pSkin], 2731.871826, -2448.361572, 17.593746, 274.199981, 0, 0, 0, 0, 0, 0);
            SpawnPlayer(playerid);	   
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Welcome back, {00FFFF}%s!", pData[playerid][pName]);
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Happy roleplay and let's start your journey today!");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Use {FFFF00}'/ask' {FFFFFF}if you have any questions and {FFFF00}'/report' {FFFFFF}if you want to report something.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Make sure you've read {FF8C00}#basic-rules {FFFFFF}in our discord before playing any further.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> Our Discord: {FFFF00}sites.google.com/view/konoha-roleplay");			
        }
        else if(pData[playerid][PilihSpawn] == 3)
        {
            if(pData[playerid][pSpaTime] >= gettime())
                return 1;

            forex(i, 9)
            {
                PlayerTextDrawHide(playerid, SPAWNMENU[playerid][i]);
            }
            CancelSelectTextDraw(playerid);
            SetSpawnInfo(playerid, 0, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], 0, 0, 0, 0, 0, 0);
            SpawnPlayer(playerid);	  
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Welcome back, {00FFFF}%s!", pData[playerid][pName]);
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Happy roleplay and let's start your journey today!");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Use {FFFF00}'/ask' {FFFFFF}if you have any questions and {FFFF00}'/report' {FFFFFF}if you want to report something.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> {FFFFFF}Make sure you've read {FF8C00}#basic-rules {FFFFFF}in our discord before playing any further.");
			SendClientMessageEx(playerid, 0xa6bbffAA, "</> Our Discord: {FFFF00}sites.google.com/view/konoha-roleplay");				                 
        }            
    } 
    return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if(clickedid == HPLOCKSCREEN[19])//Close HP
	{
		for(new i = 0; i < 28; i++)
		{
			TextDrawHideForPlayer(playerid, HPLOCKSCREEN[i]);
		}
		CancelSelectTextDraw(playerid);
		ClearAnimations(playerid);
		StopLoopingAnim(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	}
	if(clickedid == HPLOCKSCREEN[27])//Sidik Jari
	{
		for(new i = 0; i < 28; i++)
		{
			TextDrawHideForPlayer(playerid, HPLOCKSCREEN[i]);
		}
		ShowMenuHP(playerid);
	}	
	//Menu Screen
	if(clickedid == HPMENUSCREEN[19])//Close Menu HP
	{
		HideMenuHP(playerid);
		for(new i = 0; i < 28; i++)
		{
			TextDrawShowForPlayer(playerid, HPLOCKSCREEN[i]);
		}
	}
	if(clickedid == HPMENUSCREEN[39])//Gojek
	{
		HideMenuHP(playerid);

		new AtmInfo[560];
	   	format(AtmInfo,1000,"%s", FormatMoney(pData[playerid][pGopay]));
		TextDrawSetString(APKGOJEK[28], AtmInfo);

		for(new i = 0; i < 49; i++)
		{
			TextDrawShowForPlayer(playerid, APKGOJEK[i]);
		}
	}
	if(clickedid == APKGOJEK[19])//Close Gojek
	{
		for(new i = 0; i < 49; i++)
		{
			TextDrawHideForPlayer(playerid, APKGOJEK[i]);
		}
		ShowMenuHP(playerid);
	}
	if(clickedid == APKGOJEK[34]) //Gojek Pay
	{
		ShowPlayerDialog(playerid, DIALOG_GOPAY, DIALOG_STYLE_INPUT, "GoJek App - Pay", "Masukan jumlah uang yang ingin anda bayar", "Input", "Kembali");	
	}
	if(clickedid == APKGOJEK[36]) //Gojek TopUp
	{
		ShowPlayerDialog(playerid, DIALOG_GOTOPUP, DIALOG_STYLE_INPUT, "GoJek App - TopUp", "Masukan jumlah gopay yang ingin anda topup", "Input", "Kembali");
	}
	if(clickedid == APKGOJEK[40]) //Go Ride
	{
	    ShowPlayerDialog(playerid, DIALOG_GOJEK, DIALOG_STYLE_INPUT, "GoJek App - Pesan GoJek", "Hai, kamu akan memesan GoJek. Mau kemana hari ini?", "Pesan", "Kembali");
	}
	if(clickedid == APKGOJEK[43]) // Go Car
	{
	    ShowPlayerDialog(playerid, DIALOG_GOCAR, DIALOG_STYLE_INPUT, "GoJek App - Pesan GoCar", "Hai, kamu akan memesan GoCar. Mau kemana hari ini?", "Pesan", "Kembali");
	}
	if(clickedid == APKGOJEK[46]) // Go Food
	{
		ShowPlayerDialog(playerid, DIALOG_GOFOOD, DIALOG_STYLE_INPUT, "GoJek App - Pesan GoFood", "Hai, kamu akan memesan GoFood. Mau makan apa hari ini?", "Pesan", "Kembali");
	}
	if(clickedid == HPMENUSCREEN[35])//Kontak
	{
		DisplayContact(playerid);
	}
	if(clickedid == HPMENUSCREEN[52])//ADS
	{
		ShowAdsLog(playerid);
	}
	if(clickedid == HPMENUSCREEN[48])//GPS
	{
		ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "Lokasi Umum\nLokasi Pekerjaan\n"RED_E"(Hapus Checkpoint GPS)", "Pilih", "Batal");
	}
	if(clickedid == HPMENUSCREEN[56])//Twitter
	{
		new str[128];
		format(str, sizeof(str), "Set Username\nPost Message");
		ShowPlayerDialog(playerid, TWITTER_MENU, DIALOG_STYLE_LIST, "Twitter Application", str, "Select", "No");
	}
	if(clickedid == HPMENUSCREEN[31])//SMS
	{
		ShowPlayerDialog(playerid, DIALOG_WASSAP, DIALOG_STYLE_LIST, "Handphone - Message", "Shareloc\nMessage", "Pilih", "Kembali");
	}
	if(clickedid == HPMENUSCREEN[26])//TLP
	{
		if(pData[playerid][pUsePhone] == 0) 
			return Error(playerid, "Handphone anda mati nyalakan terlebih dahulu di setting");

		ShowPlayerDialog(playerid, DIALOG_PHONE_DIALUMBER, DIALOG_STYLE_INPUT, "Nomor Telpon", "Masukkan Nomor telpon yang ingin anda telpon", "telpon", "Kembali");
	}
	if(clickedid == HPMENUSCREEN[45]) // Settings
	{
		ShowPlayerDialog(playerid, DIALOG_PANELPHONE, DIALOG_STYLE_LIST, "Handphone - Setting", "Tentang Ponsel\nSettings", "Select", "Back");
	}
	if(clickedid == HPMENUSCREEN[61])//BRI
	{
		HideMenuHP(playerid);

		new AtmInfo[560];
	   	format(AtmInfo,1000,"%s", FormatMoney(pData[playerid][pBankMoney]));
		TextDrawSetString(APKBRIMO[31], AtmInfo);
		format(AtmInfo,1000,"%d", pData[playerid][pBankRek]);
		TextDrawSetString(APKBRIMO[33], AtmInfo);

		for(new i = 0; i < 56; i++)
		{
			TextDrawShowForPlayer(playerid, APKBRIMO[i]);
		}
	}
	if(clickedid == APKBRIMO[19])//close bri
	{
		for(new i = 0; i < 56; i++)
		{
			TextDrawHideForPlayer(playerid, APKBRIMO[i]);
		}
		ShowMenuHP(playerid);
	}
	if(clickedid == APKBRIMO[50])//TF
	{
		ShowPlayerDialog(playerid, DIALOG_ATMREKENING, DIALOG_STYLE_INPUT, ""LB_E"Bank", "Masukan jumlah uang:", "Transfer", "Cancel");
	}
	if(clickedid == APKBRIMO[43])//MyTax
	{
		new str[128];
		format(str, sizeof(str), "Business Tax\nHouse Tax\nDealer Tax\nVending Tax");
		ShowPlayerDialog(playerid, MYTAX_MENU, DIALOG_STYLE_LIST, "MyTax", str, "Select", "No");
	}
	if(clickedid == APKBRIMO[43])//Invoice
	{
		new header[1400], count = 0;
	    new bool:status = false;
	    format(header, sizeof(header), "Faction\tFrom\tBill Name\tAmount\n");
	    foreach(new i: tagihan)
	    {
	    	new fac[64];
			if(bilData[i][bilType] == 1)
			{
				fac = "Police";
			}
			else if(bilData[i][bilType] == 2)
			{
				fac = "Goverment";
			}
			else if(bilData[i][bilType] == 3)
			{
				fac = "Medic";
			}
			else if(bilData[i][bilType] == 4)
			{
				fac = "News";
			}
			else if(bilData[i][bilType] == 5)
			{
				fac = "Pedagang";
			}
			else if(bilData[i][bilType] == 6)
			{
				fac = "Gojek";
			}
			else if(bilData[i][bilType] == 7)
			{
				fac = "Mekanik";
			}
	        if(i != -1)
	        {
	            if(bilData[i][bilTarget] == pData[playerid][pID])
	            {
	                format(header, sizeof(header), "%s\t%s\t%s\t%s\t{00ff00}%s\n", header, fac, bilData[i][billoName], bilData[i][bilName], FormatMoney(bilData[i][bilammount]));
	                count++;
	                status = true;
	            }
	        }
	    }
	    if(status)
	    {
	        ShowPlayerDialog(playerid, DIALOG_PAYBILL, DIALOG_STYLE_TABLIST_HEADERS, "My invoice", header, "Pay", "back");
	    }
	    else
	    {
	        Error(playerid, "You have no bills");
	    }
	}	
	return 1;
}

Dialog:DIALOG_INVAM(playerid, response, listitem, inputtext[])
{
	if(response)
	{
	    if (strval(inputtext) > 20)
			return ErrorMsg(playerid, "Can't give more than 20");
		PlayerData[playerid][pGiveAmount] = strval(inputtext);
		new str[125];
		format(str, sizeof(str), "%d", strval(inputtext));
		PlayerTextDrawSetString(playerid, OtrpInv[playerid][33], str);		
	}
	return 1;
}

Dialog:DIALOG_GIVE(playerid, response, listitem, inputtext[])
{
	if (response)
	{
	    inputtext[strfind(inputtext, "\n")] = EOS;

	    new userid = strval(inputtext);

		if (userid == INVALID_PLAYER_ID)
		    return Error(playerid, "Invalid player specified");

	    if (!IsPlayerNearPlayer(playerid, userid, 4.0))
			return Error(playerid, "You are not near that player");

	    if (userid == playerid)
			return Error(playerid, "You can't give items to yourself");

		new value = PlayerData[playerid][pGiveAmount];
  		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][PlayerData[playerid][pSelectItem]][invItem], true)){
			Inventory_Remove(playerid, g_aInventoryItems[i][e_InventoryItem], value);
		    Inventory_Add(userid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], value);
		}
	}	
	return 1;
}

Dialog:DIALOG_ATMWITHDRAW(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new amount = strval(inputtext);
		amountWithdraw[playerid] = amount;
	   	PlayerTextDrawSetString(playerid, ATMTD[playerid][23], sprintf("%d", amountWithdraw[playerid]));		
	}
	return 1;
}

Dialog:DIALOG_ATMDEPO(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new amount = strval(inputtext);
		amountDeposit[playerid] = amount;
	   	PlayerTextDrawSetString(playerid, ATMTD[playerid][32], sprintf("%d", amountDeposit[playerid]));		
	}
	return 1;
}