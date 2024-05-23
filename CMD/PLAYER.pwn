CMD:setlevel(playerid, params[])
{
	if(pData[playerid][pAdmin] < 6)
        return ErrorMsg(playerid, "Anda tidak memiliki akses untuk menggunakan perintah tersebut!");
	
	new jumlah, otherid;
	if(sscanf(params, "ud", otherid, jumlah))
        return SyntaxMsg(playerid, "/setlevel [playerid id/name] <jumlah>");
	
	if(!IsPlayerConnected(otherid))
        return ErrorMsg(playerid, "Player belum masuk!");
		
	pData[otherid][pLevel] = jumlah;
	SetPlayerScore(otherid, jumlah);
	SendStaffMessage(COLOR_RED, "%s telah men set jumlah level player %s", pData[playerid][pAdminname], pData[otherid][pName]);
	Servers(otherid, "Admin %s telah men set level anda", pData[playerid][pAdminname]);
	return 1;
}

CMD:admins(playerid, params[])
{
	new count = 0;
	new location[4080], lstr[596];
    foreach (new i : Player) if (PlayerData[i][pAdmin] > 0)
	{
		strcat(location,"Rank\tAdmin\t#ID\n",sizeof(location));
	
		if(count)
		{
			format(lstr,sizeof(lstr), "%s\t%s\t%d", GetStaffRank(i), PlayerData[i][pAdminname], i);
		}
		else format(lstr,sizeof(lstr), "%s\t%s\t%d", GetStaffRank(i), PlayerData[i][pAdminname], i);
		strcat(location,lstr,sizeof(location));
	}
	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_TABLIST_HEADERS,"{a8ecff}Konoha Roleplay{FFFFFF} - Online Administrator",location,"Tutup","");
	return 1;
}

CMD:sid(playerid, params[])
{
    if(sidSystem[playerid] == 0)
	{
		foreach(new i : Player)
		{
			if(IsPlayerConnected(i))
			{
				if(AccountData[i][pSpawned])
				{
					sid3dtext[playerid] = CreateDynamic3DTextLabel((sprintf("%s (%s)[%d]", AccountData[i][pName], AccountData[i][pUCP], i)), COLOR_WHITE, 0.0, 0.0, -1.0, 15.0, i,  INVALID_VEHICLE_ID,  0, GetPlayerVirtualWorld(i), GetPlayerInterior(i), playerid, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
					sidSystem[playerid] = 1;
					Info(playerid, "Name UCP ID telah {00FF00}diaktifkan.");
				}
			}
		}
	}
	else 
	{
		sidSystem[playerid] = 0;
		if(IsValidDynamic3DTextLabel(sid3dtext[playerid]))
				DestroyDynamic3DTextLabel(sid3dtext[playerid]);  
		Info(playerid, "Name UCP ID telah {FF0000}dinonaktifkan.");
	}	

	return 1;
}

CMD:ads(playerid, params[])
{
	if(pData[playerid][pVip] != 0)
	{
		if(GetPVarInt(playerid, "delay") > gettime()) 
			return ErrorMsg(playerid, "Mohon Tunggu 10 Menit Untuk Menggunakan kembali.");

        if(!Inventory_Count(playerid, "Handphone")) 
			return ErrorMsg(playerid, "Kamu tidak memilik Handphone!");
		
		if(isnull(params))
		{
			Usage(playerid, "/ads [text] | 1 character pay $2");
			return 1;
		}
		if(strlen(params) >= 100 ) return ErrorMsg(playerid, "Maximum character is 100 text." );
		new payout = strlen(params) * 2;
		if(pData[playerid][pMoney] < payout) return ErrorMsg(playerid, "Not enough money.");
		
		GivePlayerMoneyEx(playerid, -payout);
		Server_AddMoney(payout);
		SetPVarInt(playerid, "delay", gettime() + 600);
		foreach(new ii : Player)
		{
			if(pData[ii][pTogAds] == 0)
			{
				SendClientMessageEx(ii, COLOR_ORANGE2, "[IKLAN] "GREEN_E"%s.", params);
				SendClientMessageEx(ii, COLOR_ORANGE2, "Contact Info: ["GREEN_E"%s"ORANGE_E2"] Ph: ["GREEN_E"%d"ORANGE_E2"] Bank Rek: ["GREEN_E"%d"ORANGE_E2"]", pData[playerid][pName], pData[playerid][pPhone], pData[playerid][pBankRek]);
			}
		}
		Add_AdsLog(playerid, params);
	}
	else
	{
		if(GetPVarInt(playerid, "delay") > gettime()) 
			return ErrorMsg(playerid, "Mohon Tunggu 10 Menit Untuk Menggunakan kembali.");

		if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2360.01, -284.87, 1303.75)) 
			return ErrorMsg(playerid, "You must in SANA Station!");
		
        if(!Inventory_Count(playerid, "Handphone")) 
			return ErrorMsg(playerid, "Kamu tidak memilik Handphone!");
		
		if(isnull(params))
		{
			Usage(playerid, "/ads [text] | 1 character pay $2");
			return 1;
		}
		if(strlen(params) >= 100 ) return ErrorMsg(playerid, "Maximum character is 100 text." );
		new payout = strlen(params) * 2;
		if(pData[playerid][pMoney] < payout) return ErrorMsg(playerid, "Not enough money.");
		
		GivePlayerMoneyEx(playerid, -payout);
		Server_AddMoney(payout);
		SetPVarInt(playerid, "delay", gettime() + 600);
		foreach(new ii : Player)
		{
			if(pData[ii][pTogAds] == 0)
			{
				SendClientMessageEx(ii, COLOR_ORANGE2, "[IKLAN] "GREEN_E"%s.", params);
				SendClientMessageEx(ii, COLOR_ORANGE2, "Contact Info: ["GREEN_E"%s"ORANGE_E2"] Ph: ["GREEN_E"%d"ORANGE_E2"] Bank Rek: ["GREEN_E"%d"ORANGE_E2"]", pData[playerid][pName], pData[playerid][pPhone], pData[playerid][pBankRek]);
			}
		}
		Add_AdsLog(playerid, params);
	}
	return 1;
}

CMD:shareloc(playerid, params[])
{
	new otherid;
	if(sscanf(params, "u", otherid))
        return SyntaxMsg(playerid, "/shareloc [playerid/PartOfName]");

    if(!Inventory_Count(playerid, "Handphone")) 
		return ErrorMsg(playerid, "Kamu tidak memilik Handphone!");

    if(pData[otherid][pPhone] < 1)
    	return ErrorMsg(playerid, "Pemain yang dituju tidak memiliki Handphone");

    if(otherid == playerid)
        return ErrorMsg(playerid, "Kamu tidak bisa meminta lokasi kepada anda sendiri.");

    pData[otherid][pLocOffer] = playerid;

    new Float:sX, Float:sY, Float:sZ;
	GetPlayerPos(playerid, sX, sY, sZ);
	SetPlayerCheckpoint(otherid, sX, sY, sZ, 5.0);
	SuccesMsg(playerid, "Berhasil mengirimkan lokasi");
	new lstr[500];
	format(lstr,sizeof(lstr), "Anda telah dikirimkan Lokasi oleh ~y~%s.", pData[playerid][pName]);
	InfoMsg(otherid, lstr);
	return 1;
}

CMD:simshow(playerid, params[])
{
	if(!Inventory_Count(playerid, "Sim"))
		return ErrorMsg(playerid, "Anda tidak mempunyai SIM");

	new sext[40], AtmInfo[560];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
   	format(AtmInfo,1000,"%s", pData[playerid][pName]);
   	PlayerTextDrawSetString(playerid, SIMVALRISE[playerid][18], AtmInfo);
	format(AtmInfo,1000,"%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, SIMVALRISE[playerid][29], AtmInfo);
	format(AtmInfo,1000,"%s", sext);
	PlayerTextDrawSetString(playerid, SIMVALRISE[playerid][22], AtmInfo);

	for(new i = 0; i < 30; i++)
	{
		PlayerTextDrawShow(playerid, SIMVALRISE[playerid][i]);
	}
	SetTimerEx("simisimi",9000, false, "d", playerid);
	//Info(playerid, "Gunakan /simhide Untuk menghilangkan Textdraw");
	return 1;
}
function simisimi(playerid)
{
	for(new i = 0; i < 30; i++)
	{
		PlayerTextDrawHide(playerid, SIMVALRISE[playerid][i]);
	}
	return 1;
}

CMD:simhide(playerid, params[])
{
	for(new i = 0; i < 30; i++)
	{
		PlayerTextDrawHide(playerid, SIMVALRISE[playerid][i]);
	}
	return 1;
}

CMD:showsks(playerid, params[])
{
	if(!Inventory_Count(playerid, "Sks"))
		return ErrorMsg(playerid, "Anda tidak mempunyai SKS");

	new sext[40], AtmInfo[560];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
   	format(AtmInfo,1000,"%s", pData[playerid][pName]);
   	PlayerTextDrawSetString(playerid, SKSTD[playerid][23], AtmInfo);
   	format(AtmInfo,1000,"%d", pData[playerid][pPhone]);
	PlayerTextDrawSetString(playerid, SKSTD[playerid][24], AtmInfo);
   	format(AtmInfo,1000,"%s", sext);
	PlayerTextDrawSetString(playerid, SKSTD[playerid][26], AtmInfo);
	format(AtmInfo,1000,"%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, SKSTD[playerid][25], AtmInfo);
	format(AtmInfo,1000,"%s", GetJobName(pData[playerid][pJob]));
	PlayerTextDrawSetString(playerid, SKSTD[playerid][27], AtmInfo);
	format(AtmInfo,1000,"%s Cm", pData[playerid][pTinggi]);
	PlayerTextDrawSetString(playerid, SKSTD[playerid][28], AtmInfo);

	for(new i = 0; i < 34; i++)
	{
		PlayerTextDrawShow(playerid, SKSTD[playerid][i]);
	}
	SetTimerEx("sks",9000, false, "d", playerid);
	return 1;
}

function sks(playerid)
{
	for(new i = 0; i < 34; i++)
	{
		PlayerTextDrawHide(playerid, SKSTD[playerid][i]);
	}
	return 1;
}

CMD:showskck(playerid, params[])
{
	if(!Inventory_Count(playerid, "Skck"))
		return ErrorMsg(playerid, "Anda tidak mempunyai SKCK");

	new sext[40], AtmInfo[560];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
   	format(AtmInfo,1000,"Nama : %s", pData[playerid][pName]);
   	PlayerTextDrawSetString(playerid, SKCKTD[playerid][7], AtmInfo);
   	format(AtmInfo,1000,"Jenis Kelamin : %s", sext);
	PlayerTextDrawSetString(playerid, SKCKTD[playerid][8], AtmInfo);
	format(AtmInfo,1000,"Tempat tanggal lahir : LS, %s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, SKCKTD[playerid][9], AtmInfo);
	format(AtmInfo,1000,"Pekerjaan : %s", GetJobName(pData[playerid][pJob]));
	PlayerTextDrawSetString(playerid, SKCKTD[playerid][11], AtmInfo);

	for(new i = 0; i < 27; i++)
	{
		PlayerTextDrawShow(playerid, SKCKTD[playerid][i]);
	}
	SetTimerEx("skck",9000, false, "d", playerid);
	return 1;
}

function skck(playerid)
{
	for(new i = 0; i < 27; i++)
	{
		PlayerTextDrawHide(playerid, SKCKTD[playerid][i]);
	}
	return 1;
}

CMD:showbpjs(playerid, params[])
{
	if(!Inventory_Count(playerid, "Bpjs"))
		return ErrorMsg(playerid, "Anda tidak mempunyai BPJS");

	new AtmInfo[560];
   	format(AtmInfo,1000,"%s", pData[playerid][pName]);
   	PlayerTextDrawSetString(playerid, BPJSTD[playerid][12], AtmInfo);
	format(AtmInfo,1000,"%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, BPJSTD[playerid][15], AtmInfo);

	for(new i = 0; i < 19; i++)
	{
		PlayerTextDrawShow(playerid, BPJSTD[playerid][i]);
	}
	SetTimerEx("bpjs",9000, false, "d", playerid);
	return 1;
}

function bpjs(playerid)
{
	for(new i = 0; i < 19; i++)
	{
		PlayerTextDrawHide(playerid, BPJSTD[playerid][i]);
	}
	return 1;
}

CMD:hidebpjs(playerid, params[])
{
	for(new i = 0; i < 19; i++)
	{
		PlayerTextDrawHide(playerid, BPJSTD[playerid][i]);
	}
	return 1;
}

CMD:ktpshow(playerid, params[])
{
	if(!AccountData[playerid][pKtp])
		return ErrorMsg(playerid, "Anda tidak mempunyai KTP");

	new sext[40], AtmInfo[560];
	if(pData[playerid][pGender] == 1) { sext = "Laki-Laki"; } else { sext = "Perempuan"; }
   	format(AtmInfo,1000,"%s", pData[playerid][pName]);
   	PlayerTextDrawSetString(playerid, KTPValrise[playerid][10], AtmInfo);
	format(AtmInfo,1000,"%s", pData[playerid][pAge]);
	PlayerTextDrawSetString(playerid, KTPValrise[playerid][15], AtmInfo);
	format(AtmInfo,1000,"%s", sext);
	PlayerTextDrawSetString(playerid, KTPValrise[playerid][17], AtmInfo);
	format(AtmInfo,1000,"%s", pData[playerid][pTinggi]);
	PlayerTextDrawSetString(playerid, KTPValrise[playerid][19], AtmInfo);

	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawShow(playerid, KTPValrise[playerid][i]);
	}
	SetTimerEx("ktp",9000, false, "d", playerid);
	//Info(playerid, "Gunakan /ktphide Untuk menghilangkan Textdraw");
	return 1;
}

function ktp(playerid)
{
	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, KTPValrise[playerid][i]);
	}
	return 1;
}

CMD:ktphide(playerid, params[])
{
	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, KTPValrise[playerid][i]);
	}
	return 1;
}

CMD:cursor(playerid, params[])
{
	SelectTextDraw(playerid, COLOR_BLUE);
	return 1;
}

CMD:nonono(playerid, params[])
{
    if(!Inventory_Count(playerid, "Handphone")) 
		return ErrorMsg(playerid, "Kamu tidak memilik Handphone!");
	
	if(pData[playerid][pUsePhone] == 0) 
		return Error(playerid, "Handphone anda sedang dimatikan");

	if(pData[playerid][pGpsIns] < 1 && pData[playerid][pTwtIns] < 1 && pData[playerid][pAonaIns] < 1)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] < 1 && pData[playerid][pTwtIns] < 1 && pData[playerid][pAonaIns] > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nAds Of News Agency", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] > 0 && pData[playerid][pTwtIns] < 1 && pData[playerid][pAonaIns] < 1)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nGps", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] < 1 && pData[playerid][pTwtIns] > 0 && pData[playerid][pAonaIns] < 1)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nTwitter", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] > 0 && pData[playerid][pTwtIns] > 0 && pData[playerid][pAonaIns] < 1)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nGps\nTwitter", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] < 1 && pData[playerid][pTwtIns] > 0 && pData[playerid][pAonaIns] > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nAds of News Agency\nTwitter", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] > 0 && pData[playerid][pTwtIns] < 1 && pData[playerid][pAonaIns] > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nAds of News Agency\nGps", "Select", "Exit");
	}
	else if(pData[playerid][pGpsIns] > 0 && pData[playerid][pTwtIns] > 0 && pData[playerid][pAonaIns] > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, "Phone", "MyTax\nInvoice\nContact\nMBanking\nApp Store\nTwitter\nGps\nAds of New Agency", "Select", "Exit");
	}
	return 1;
}
CMD:angkattelp(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	if(pData[playerid][pCall] != INVALID_PLAYER_ID)
		return Error(playerid, "Anda sudah sedang menelpon seseorang!");
		
	if(pData[playerid][pInjured] != 0)
		return Error(playerid, "You cant do that in this time.");
		
	foreach(new ii : Player)
	{
		if(playerid == pData[ii][pCall])
		{
			pData[ii][pPhoneCredit]--;
			
			pData[playerid][pCall] = ii;
			//SendClientMessageEx(ii, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
   			for(new i = 0; i < 29; i++)
			{
				TextDrawHideForPlayer(ii, TelponNotif[i]);
			}
			PlayerTextDrawHide(ii, NamaDanFuncall[ii][0]);
			PlayerTextDrawHide(ii, NamaDanFuncall[ii][1]);
			PlayerTextDrawHide(ii, BatalTelpon[ii]);
			PlayerTextDrawHide(ii, RijekTelpon[ii]);
			PlayerTextDrawHide(ii, AngkatTelpon[ii]);
			
			for(new i = 0; i < 23; i++)
			{
				TextDrawShowForPlayer(ii, PlayerTelpon[i]);
			}

			new tstr[256];
			format(tstr, sizeof(tstr), "%s", pData[playerid][pName]);
			PlayerTextDrawSetString(ii, NamaDanJamTelp[ii][0], tstr);
			PlayerTextDrawShow(ii, NamaDanJamTelp[ii][0]);
			PlayerTextDrawShow(ii, NamaDanJamTelp[ii][1]);
			PlayerTextDrawShow(ii, AkhiriTelpon[ii]);
			CancelSelectTextDraw(ii);
			//SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			for(new i = 0; i < 29; i++)
			{
				TextDrawHideForPlayer(playerid, TelponNotif[i]);
			}
			PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][0]);
			PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][1]);
			PlayerTextDrawHide(playerid, BatalTelpon[playerid]);
			PlayerTextDrawHide(playerid, RijekTelpon[playerid]);
			PlayerTextDrawHide(playerid, AngkatTelpon[playerid]);
			
			for(new i = 0; i < 23; i++)
			{
				TextDrawShowForPlayer(playerid, PlayerTelpon[i]);
			}
			format(tstr, sizeof(tstr), "%s", pData[ii][pName]);
			PlayerTextDrawSetString(playerid, NamaDanJamTelp[playerid][0], tstr);
			PlayerTextDrawShow(playerid, NamaDanJamTelp[playerid][0]);
			PlayerTextDrawShow(playerid, NamaDanJamTelp[playerid][1]);
			PlayerTextDrawShow(playerid, AkhiriTelpon[playerid]);
			CancelSelectTextDraw(playerid);
			ToggleCall[playerid] = 1;
			ToggleCall[ii] = 1;
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s answers their cellphone.", ReturnName(playerid));
			
			DetikCall[playerid] = 0;
			MenitCall[playerid] = 0;
			JamCall[playerid] = 0;
			
			DetikCall[ii] = 0;
			MenitCall[ii] = 0;
			JamCall[ii] = 0;
			
			KillTimer(CallTimer[playerid]);
			KillTimer(CallTimer[ii]);
			
			CallTimer[playerid] = SetTimerEx("TambahDetikCall", 1000, true, "i", playerid);
			CallTimer[ii] = SetTimerEx("TambahDetikCall", 1000, true, "i", ii);
			
   			new targetid = pData[playerid][pCall];

			OnPhone[targetid] = SvCreateGStream(0xFFA200FF, "InPhone");

		    if (OnPhone[targetid])
			{
		        SvAttachListenerToStream(OnPhone[targetid], targetid);
		        SvAttachListenerToStream(OnPhone[targetid], playerid);
		    }
		    if (OnPhone[targetid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
			{
		        SvAttachSpeakerToStream(OnPhone[targetid], playerid);
		    }

		    if(OnPhone[targetid] && pData[targetid][pCall] != INVALID_PLAYER_ID)
			{
		        SvAttachSpeakerToStream(OnPhone[targetid], targetid);
		    }
		}
	}
	return 1;
}

CMD:offhu(playerid, params[])
{
 	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	for(new i = 0; i < 29; i++)
	{
		TextDrawHideForPlayer(playerid, TelponNotif[i]);
	}
	PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][0]);
	PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][1]);
	PlayerTextDrawHide(playerid, BatalTelpon[playerid]);
	PlayerTextDrawHide(playerid, RijekTelpon[playerid]);
	PlayerTextDrawHide(playerid, AngkatTelpon[playerid]);
	CancelSelectTextDraw(playerid);
	ToggleCall[playerid] = 0;
	DetikCall[playerid] = 0;
	MenitCall[playerid] = 0;
	JamCall[playerid] = 0;
	pData[playerid][pCall] = INVALID_PLAYER_ID;
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
	return 1;
}

CMD:ofhu(playerid, params[])
{
 	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

    foreach(new ii : Player)
	{
		if(playerid == pData[ii][pCall])
		{
			pData[playerid][pCall] = ii;
			for(new i = 0; i < 29; i++)
			{
				TextDrawHideForPlayer(ii, TelponNotif[i]);
			}
			PlayerTextDrawHide(ii, NamaDanFuncall[ii][0]);
			PlayerTextDrawHide(ii, NamaDanFuncall[ii][1]);
			PlayerTextDrawHide(ii, BatalTelpon[ii]);
			PlayerTextDrawHide(ii, RijekTelpon[ii]);
			PlayerTextDrawHide(ii, AngkatTelpon[ii]);
			pData[ii][pCall] = INVALID_PLAYER_ID;
			SetPlayerSpecialAction(ii, SPECIAL_ACTION_STOPUSECELLPHONE);
			//SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			for(new i = 0; i < 29; i++)
			{
				TextDrawHideForPlayer(playerid, TelponNotif[i]);
			}
			PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][0]);
			PlayerTextDrawHide(playerid, NamaDanFuncall[playerid][1]);
			PlayerTextDrawHide(playerid, BatalTelpon[playerid]);
			PlayerTextDrawHide(playerid, RijekTelpon[playerid]);
			PlayerTextDrawHide(playerid, AngkatTelpon[playerid]);
			CancelSelectTextDraw(playerid);
			CancelSelectTextDraw(ii);
			ToggleCall[ii] = 0;
			ToggleCall[playerid] = 0;
			DetikCall[playerid] = 0;
			MenitCall[playerid] = 0;
			JamCall[playerid] = 0;
			DetikCall[ii] = 0;
			MenitCall[ii] = 0;
			JamCall[ii] = 0;
			pData[playerid][pCall] = INVALID_PLAYER_ID;
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		}
	}
	return 1;
}

CMD:endcall(playerid, params[])
{
	if(IsPlayerInRangeOfPoint(playerid, 50, 2184.32, -1023.32, 1018.68))
		return Error(playerid, "Anda tidak dapat melakukan ini jika sedang berada di OOC Zone");

	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		//SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		for(new i = 0; i < 23; i++)
		{
			TextDrawHideForPlayer(caller, PlayerTelpon[i]);
		}
		PlayerTextDrawHide(caller, NamaDanJamTelp[caller][0]);
		PlayerTextDrawHide(caller, NamaDanJamTelp[caller][1]);
		PlayerTextDrawHide(caller, AkhiriTelpon[caller]);
		CancelSelectTextDraw(caller);
		ToggleCall[caller] = 0;
		DetikCall[caller] = 0;
		MenitCall[caller] = 0;
		JamCall[caller] = 0;
		
		//SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
  		for(new i = 0; i < 23; i++)
		{
			TextDrawHideForPlayer(playerid, PlayerTelpon[i]);
		}
		PlayerTextDrawHide(playerid, NamaDanJamTelp[playerid][0]);
		PlayerTextDrawHide(playerid, NamaDanJamTelp[playerid][1]);
		PlayerTextDrawHide(playerid, AkhiriTelpon[playerid]);
		CancelSelectTextDraw(playerid);
		ToggleCall[playerid] = 0;
		DetikCall[playerid] = 0;
		MenitCall[playerid] = 0;
		JamCall[playerid] = 0;
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);

  		if (OnPhone[caller] && pData[caller][pCall] != INVALID_PLAYER_ID)
	 	{
            SvDetachSpeakerFromStream(OnPhone[caller], caller);
        }

        if(OnPhone[caller] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
            SvDetachSpeakerFromStream(OnPhone[caller], playerid);
        }

        if(OnPhone[caller])
		{
            SvDetachListenerFromStream(OnPhone[caller], caller);
            SvDetachListenerFromStream(OnPhone[caller], playerid);
            SvDeleteStream(OnPhone[caller]);
            OnPhone[caller] = SV_NULL;
        }

		if (OnPhone[playerid] && pData[caller][pCall] != INVALID_PLAYER_ID)
		{
            SvDetachSpeakerFromStream(OnPhone[playerid], caller);
        }

        if(OnPhone[playerid] && pData[playerid][pCall] != INVALID_PLAYER_ID)
		{
            SvDetachSpeakerFromStream(OnPhone[playerid], playerid);
        }

        if(OnPhone[playerid])
		{
            SvDetachListenerFromStream(OnPhone[playerid], caller);
            SvDetachListenerFromStream(OnPhone[playerid], playerid);
            SvDeleteStream(OnPhone[playerid]);
            OnPhone[playerid] = SV_NULL;
        }
	}
	return 1;
}
CMD:help(playerid, params[])
{
	ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "Help Menu", "Player\nChat\nVehicle\nJob\nFaction\nFamily\nBisnis\nHouse", "Select", "Close");
	return 1;
}

/*CMD:gps(playerid, params[])
{
	if(pData[playerid][pGPS] < 1) return Error(playerid, "Anda tidak memiliki GPS.");
	ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS Menu", "My House\nMy Bisnis\nMy Vehicle\nMy Mission\nBank\nJobs", "Select", "Close");
	return 1;
}
*/
CMD:death(playerid, params[])
{
    if(pData[playerid][pInjured] == 0)
        return Error(playerid, "You are not injured at the moment.");

    if((gettime()-GetPVarInt(playerid, "GiveUptime")) < 100)
        return Error(playerid, "You must waiting 3 minutes for spawn to hospital");
        
	/*if(pMatiPukul[playerid] == 1)
	{
	    SetPlayerHealthEx(playerid, 50.0);
	    ClearAnimations(playerid);
	    pData[playerid][pInjured] = 0;
	    pMatiPukul[playerid] = 0;
    	Servers(playerid, "You have wake up and accepted death in your position.");
    	return 1;
	}*/
    Servers(playerid, "You have given up and accepted your death.");
	pData[playerid][pHospitalTime] = 0;
	pData[playerid][pHospital] = 1;
    return 1;
}

CMD:newrek(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2246.46, -1757.03, 1014.77)) return Error(playerid, "Anda harus berada di City Hall!");
	new query[128], rand = RandomEx(111111, 999999);
	new rek = rand+pData[playerid][pID];
	mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
	mysql_tquery(g_SQL, query, "BankRek", "id", playerid, rek);
	Info(playerid, "New rekening bank!");
	GivePlayerMoneyEx(playerid, -500);
	Server_AddMoney(500);
	return 1;
}

CMD:bank(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2246.55, -1750.25, 1014.77)) return Error(playerid, "Anda harus berada di bank point!");
	new tstr[128];
	format(tstr, sizeof(tstr), ""ORANGE_E"No Rek: "LB_E"%d", pData[playerid][pBankRek]);
	ShowPlayerDialog(playerid, DIALOG_BANK, DIALOG_STYLE_LIST, tstr, "Deposit Money\nWithdraw Money\nCheck Balance\nTransfer Money\nSign Paycheck", "Select", "Cancel");
	return 1;
}

CMD:pay(playerid, params[])
{
	new money, otherid, mstr[128];
	if(sscanf(params, "ud", otherid, money))
	{
	    Usage(playerid, "/pay <ID/Name> <amount>");
	    return true;
	}

	if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 4.0))
        return Error(playerid, "The specified player is disconnected or not near you.");

 	if(otherid == playerid)
		return Error(playerid, "You can't send yourself money!");
	if(pData[playerid][pMoney] < money)
		return Error(playerid, "You don't have enough money to send!");
	if(money > 1000000 && pData[playerid][pAdmin] == 0)
		return Error(playerid, "You can't send more than $1,000,000 at once!");
	if(money < 1)
		return Error(playerid, "You can't send anyone less than $1!");
		
	format(mstr, sizeof(mstr), ""WHITEP_E"Are you sure you want to send %s(%d) "GREEN_E"%s?", ReturnName(otherid), otherid, FormatMoney(money));
	ShowPlayerDialog(playerid, DIALOG_PAY, DIALOG_STYLE_MSGBOX, ""GREEN_E"Send Money", mstr, "Send", "Cancel");

	SetPVarInt(playerid, "gcAmount", money);
	SetPVarInt(playerid, "gcPlayer", otherid);
	if(money > 1000)
	{
		SendAdminMessage(COLOR_YELLOW, "[Pay] %s (%d) memberikan uang kepada %s sebesar %s", AccountData[playerid][pName], playerid, AccountData[otherid][pName], FormatMoney(money));
	}	
	return 1;
}

CMD:cc(playerid, params[])
{
	ClearChat(playerid);
	return 1;
}

CMD:stats(playerid, params[])
{
	if(pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be logged in to check statistics!");
	    return 1;
	}
	
	DisplayStats(playerid, playerid);
	return 1;
}

CMD:items(playerid, params[])
{
	if(pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be logged in to check items!");
	    return true;
	}
	DisplayItems(playerid, playerid);
	return 1;
}

CMD:joinjob(playerid, params[])
{
	if(pData[playerid][pIDCard] <= 0)
		return Error(playerid, "Anda tidak memiliki ID-Card.");
		
	if(pData[playerid][pVip] >= 1)
	{
		if(pData[playerid][pJob] == 0 || pData[playerid][pJob2] == 0)
		{
			if(pData[playerid][pJob] == 0)
			{
				if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -2159.04, 640.36, 1052.38))
				{
					pData[playerid][pGetJob] = 1;
					Info(playerid, "Anda telah berhasil mendaftarkan job Taxi. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 2254.83, -1984.17, 13.58))
				{
					pData[playerid][pGetJob] = 2;
					Info(playerid, "Anda telah berhasil mendaftarkan job mechanic. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -265.87, -2213.63, 29.04))
				{
					pData[playerid][pGetJob] = 3;
					Info(playerid, "Anda telah berhasil mendaftarkan job lumber jack. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -77.38, -1136.52, 1.07))
				{
					pData[playerid][pGetJob] = 4;
					Info(playerid, "Anda telah berhasil mendaftarkan job trucker. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 319.94, 874.77, 20.39))
				{
					pData[playerid][pGetJob] = 5;
					Info(playerid, "Anda telah berhasil mendaftarkan job miner. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -283.02, -2174.36, 28.66))
				{
					pData[playerid][pGetJob] = 6;
					Info(playerid, "Anda telah berhasil mendaftarkan job production. /accept job untuk konfirmasi.");
				}
				else return Error(playerid, "Anda tidak berada di dekat pendaftaran job.");
			}
			else if(pData[playerid][pJob2] == 0)
			{
				if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -2159.04, 640.36, 1052.38))
				{
					pData[playerid][pGetJob2] = 1;
					Info(playerid, "Anda telah berhasil mendaftarkan job Taxi. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 2254.83, -1984.17, 13.58))
				{
					pData[playerid][pGetJob2] = 2;
					Info(playerid, "Anda telah berhasil mendaftarkan job mechanic. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -265.87, -2213.63, 29.04))
				{
					pData[playerid][pGetJob2] = 3;
					Info(playerid, "Anda telah berhasil mendaftarkan job lumber jack. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -77.38, -1136.52, 1.07))
				{
					pData[playerid][pGetJob2] = 4;
					Info(playerid, "Anda telah berhasil mendaftarkan job trucker. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 319.94, 874.77, 20.39))
				{
					pData[playerid][pGetJob2] = 5;
					Info(playerid, "Anda telah berhasil mendaftarkan job miner. /accept job untuk konfirmasi.");
				}
				else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -283.02, -2174.36, 28.66))
				{
					pData[playerid][pGetJob2] = 6;
					Info(playerid, "Anda telah berhasil mendaftarkan job production. /accept job untuk konfirmasi.");
				}
				else return Error(playerid, "Anda tidak berada di dekat pendaftaran job.");
			}
			else return Error(playerid, "Anda sudah memiliki 2 pekerjaan!");
		}
		else return Error(playerid, "Anda sudah memiliki 2 pekerjaan!");
	}
	else
	{
		if(pData[playerid][pJob] > 0)
			return Error(playerid, "Anda hanya bisa memiliki 1 pekerjaan!");
			
		if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -2159.04, 640.36, 1052.38))
		{
			pData[playerid][pGetJob] = 1;
			Info(playerid, "Anda telah berhasil mendaftarkan job Taxi. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 2254.83, -1984.17, 13.58))
		{
			pData[playerid][pGetJob] = 2;
			Info(playerid, "Anda telah berhasil mendaftarkan job mechanic. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -265.87, -2213.63, 29.04))
		{
			pData[playerid][pGetJob] = 3;
			Info(playerid, "Anda telah berhasil mendaftarkan job lumber jack. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -77.38, -1136.52, 1.07))
		{
			pData[playerid][pGetJob] = 4;
			Info(playerid, "Anda telah berhasil mendaftarkan job trucker. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob2] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, 319.94, 874.77, 20.39))
		{
			pData[playerid][pGetJob] = 5;
			Info(playerid, "Anda telah berhasil mendaftarkan job miner. /accept job untuk konfirmasi.");
		}
		else if(pData[playerid][pJob] == 0 && GetPlayerState(playerid) == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, -283.02, -2174.36, 28.66))
		{
			pData[playerid][pGetJob] = 6;
			Info(playerid, "Anda telah berhasil mendaftarkan job production. /accept job untuk konfirmasi.");
		}
		else return Error(playerid, "Anda tidak berada di dekat pendaftaran job.");
	}
	return 1;
}

CMD:frisk(playerid, params[])
{
	new otherid;
	if(sscanf(params, "u", otherid))
        return Usage(playerid, "/frisk [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "The specified player is disconnected or not near you.");

    if(otherid == playerid)
        return Error(playerid, "You cannot frisk yourself.");

    pData[otherid][pFriskOffer] = playerid;

    Info(otherid, "%s has offered to frisk you (type \"/accept frisk or /deny frisk\").", ReturnName(playerid));
    Info(playerid, "You have offered to frisk %s.", ReturnName(otherid));
	return 1;
}

CMD:accept(playerid, params[])
{
	if(IsPlayerConnected(playerid)) 
	{
        if(isnull(params)) 
		{
            Usage(playerid, "USAGE: /accept [name]");
            Info(playerid, "Names: faction, drag, frisk, job");
            return 1;
        }
		if(strcmp(params,"faction",true) == 0) 
		{
            if(pData[playerid][pFacOffer] > -1) 
			{
                if(pData[playerid][pFacInvite] > 0) 
				{
                    pData[playerid][pFaction] = pData[playerid][pFacInvite];
					pData[playerid][pFactionRank] = 1;
					Info(playerid, "Anda telah menerima invite faction dari %s", pData[pData[playerid][pFacOffer]][pName]);
					Info(pData[playerid][pFacOffer], "%s telah menerima invite faction yang anda tawari", pData[playerid][pName]);
					pData[playerid][pFacInvite] = 0;
					pData[playerid][pFacOffer] = -1;
				}
				else
				{
					Error(playerid, "Invalid faction id!");
					return 1;
				}
            }
            else 
			{
                Error(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
		else if(strcmp(params,"drag",true) == 0)
		{
			new dragby = GetPVarInt(playerid, "DragBy");
			if(dragby == INVALID_PLAYER_ID || dragby == playerid)
				return Error(playerid, "That player is disconnected.");
        
			if(!NearPlayer(playerid, dragby, 5.0))
				return Error(playerid, "You must be near this player.");
        
			pData[playerid][pDragged] = 1;
			pData[playerid][pDraggedBy] = dragby;

			pData[playerid][pDragTimer] = SetTimerEx("DragUpdate", 1000, true, "ii", dragby, playerid);
			SendNearbyMessage(dragby, 30.0, COLOR_PURPLE, "* %s grabs %s and starts dragging them, (/undrag).", ReturnName(dragby), ReturnName(playerid));
			return true;
		}
		else if(strcmp(params,"frisk",true) == 0)
		{
			if(pData[playerid][pFriskOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pFriskOffer]))
				return Error(playerid, "That player not connected!");
			
			if(!NearPlayer(playerid, pData[playerid][pFriskOffer], 5.0))
				return Error(playerid, "You must be near this player.");
				
			DisplayItems(pData[playerid][pFriskOffer], playerid);
			Servers(playerid, "Anda telah berhasil menaccept tawaran frisk kepada %s.", ReturnName(pData[playerid][pFriskOffer]));
			pData[playerid][pFriskOffer] = INVALID_PLAYER_ID;
		}
		else if(strcmp(params,"job",true) == 0) 
		{
			if(pData[playerid][pGetJob] > 0)
			{
				pData[playerid][pJob] = pData[playerid][pGetJob];
				Info(playerid, "Anda telah berhasil mendapatkan pekerjaan baru. gunakan /help untuk informasi.");
				pData[playerid][pGetJob] = 0;
			}
			else if(pData[playerid][pGetJob2] > 0)
			{
				pData[playerid][pJob2] = pData[playerid][pGetJob2];
				Info(playerid, "Anda telah berhasil mendapatkan pekerjaan baru. gunakan /help untuk informasi.");
				pData[playerid][pGetJob2] = 0;
			}
		}
	}
	return 1;
}

alias:deny("cancel")
CMD:deny(playerid, params[])
{
	if(IsPlayerConnected(playerid)) 
	{
        if(isnull(params)) 
		{
            Usage(playerid, "USAGE: /deny [name]");
            Info(playerid, "Names: faction, drag, frisk, job1, job2");
            return 1;
        }
		if(strcmp(params,"faction",true) == 0) 
		{
            if(pData[playerid][pFacOffer] > -1) 
			{
                if(pData[playerid][pFacInvite] > 0) 
				{
					Info(playerid, "Anda telah menolak faction dari %s", ReturnName(pData[playerid][pFacOffer]));
					Info(pData[playerid][pFacOffer], "%s telah menolak invite faction yang anda tawari", ReturnName(playerid));
					pData[playerid][pFacInvite] = 0;
					pData[playerid][pFacOffer] = -1;
				}
				else
				{
					Error(playerid, "Invalid faction id!");
					return 1;
				}
            }
            else 
			{
                Error(playerid, "Tidak ada player yang menawari anda!");
                return 1;
            }
        }
		else if(strcmp(params,"drag",true) == 0)
		{
			new dragby = GetPVarInt(playerid, "DragBy");
			if(dragby == INVALID_PLAYER_ID || dragby == playerid)
				return Error(playerid, "That player is disconnected.");

			Info(playerid, "Anda telah menolak drag.");
			Info(dragby, "Player telah menolak drag yang anda tawari.");
			
			DeletePVar(playerid, "DragBy");
			pData[playerid][pDragged] = 0;
			pData[playerid][pDraggedBy] = INVALID_PLAYER_ID;
			return 1;
		}
		else if(strcmp(params,"frisk",true) == 0)
		{
			if(pData[playerid][pFriskOffer] == INVALID_PLAYER_ID || !IsPlayerConnected(pData[playerid][pFriskOffer]))
				return Error(playerid, "That player not connected!");
			
			Info(playerid, "Anda telah menolak tawaran frisk kepada %s.", ReturnName(pData[playerid][pFriskOffer]));
			pData[playerid][pFriskOffer] = INVALID_PLAYER_ID;
			return 1;
		}
		else if(strcmp(params,"job1",true) == 0) 
		{
			if(pData[playerid][pJob] == 0) return Error(playerid, "Anda tidak memiliki job apapun.");
			if(pData[playerid][pJob] != 0)
			{
				pData[playerid][pJob] = 0;
				Info(playerid, "Anda berhasil keluar dari pekerjaan anda.");
				return 1;
			}
		}
		else if(strcmp(params,"job2",true) == 0) 
		{
			if(pData[playerid][pJob2] == 0) return Error(playerid, "Anda tidak memiliki job apapun.");
			if(pData[playerid][pJob2] != 0)
			{
				pData[playerid][pJob2] = 0;
				Info(playerid, "Anda berhasil keluar dari pekerjaan anda.");
				return 1;
			}
		}
	}
	return 1;
}

CMD:drag(playerid, params[])
{
	new otherid;
    if(sscanf(params, "u", otherid))
        return Usage(playerid, "/drag [playerid/PartOfName] || /undrag [playerid]");

    if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "That player is disconnected.");

    if(otherid == playerid)
        return Error(playerid, "You cannot drag yourself.");

    if(!NearPlayer(playerid, otherid, 5.0))
        return Error(playerid, "You must be near this player.");

    if(!pData[otherid][pInjured])
        return Error(playerid, "kamu tidak bisa drag orang yang tidak mati.");

    SetPVarInt(otherid, "DragBy", playerid);
    Info(otherid, "%s Telah menawari drag kepada anda, /accept drag untuk menerimanya /deny drag untuk membatalkannya.", ReturnName(playerid));
	Info(playerid, "Anda berhasil menawari drag kepada player %s", ReturnName(otherid));
    return 1;
}

CMD:undrag(playerid, params[])
{
	new otherid;
    if(sscanf(params, "u", otherid)) return Usage(playerid, "/undrag [playerid]");
	if(pData[otherid][pDragged])
    {
        DeletePVar(playerid, "DragBy");
        DeletePVar(otherid, "DragBy");
        pData[otherid][pDragged] = 0;
        pData[otherid][pDraggedBy] = INVALID_PLAYER_ID;

        KillTimer(pData[otherid][pDragTimer]);
        SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s releases %s from their grip.", ReturnName(playerid), ReturnName(otherid));
    }
    return 1;
}

CMD:mask(playerid, params[])
{
	if(pData[playerid][pMask] <= 0)
		return Error(playerid, "Anda tidak memiliki topeng!");
		
	switch (pData[playerid][pMaskOn])
    {
        case 0:
        {
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s takes out a mask and puts it on.", ReturnName(playerid));
            pData[playerid][pMaskOn] = 1;
			for(new i = GetPlayerPoolSize(); i != -1; --i)
			{
				ShowPlayerNameTagForPlayer(i, playerid, 0);
			}
			//SetPlayerAttachedObject(playerid, 9, 18911, 2,0.078534, 0.041857, -0.001727, 268.970458, 1.533374, 269.223754);
        }
        case 1:
        {
            pData[playerid][pMaskOn] = 0;
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s takes their mask off and puts it away.", ReturnName(playerid));
			for(new i = GetPlayerPoolSize(); i != -1; --i)
			{
				ShowPlayerNameTagForPlayer(i, playerid, 1);
			}
			//RemovePlayerAttachedObject(playerid, 9);
        }
    }
	return 1;
}

//Text and Chat Commands
CMD:try(playerid, params[])
{

    if(isnull(params))
        return Usage(playerid, "/try [action]");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %.64s ..", ReturnName(playerid), params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s, %s", params[64], (random(2) == 0) ? ("and success") : ("but fail"));
    }
    else {
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s %s, %s", ReturnName(playerid), params, (random(2) == 0) ? ("and success") : ("but fail"));
    }
	printf("[TRY] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:ado(playerid, params[])
{
    new flyingtext[164], Float:x, Float:y, Float:z;

    if(isnull(params))
	{
        SyntaxMsg(playerid, "/ado [text]\nGunakan '/ado off' untuk menghapus text");
		return 1;
	}
    if(strlen(params) > 128)
        return ErrorMsg(playerid, "Max text can only maximmum 128 characters.");

    if (!strcmp(params, "off", true))
    {
        if (IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
            DestroyDynamic3DTextLabel(pData[playerid][pAdoTag]);

        Servers(playerid, "Teks berhasil dihapus");
        pData[playerid][pAdoActive] = false;
        return 1;
    }

    FixText(params);
    format(flyingtext, sizeof(flyingtext), "(( %s ))\n>> %s[%d] <<", params, ReturnName(playerid), playerid);

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);

    GetPlayerPos(playerid, x, y, z);
    if(pData[playerid][pAdoActive])
    {
        if (IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
            UpdateDynamic3DTextLabelText(pData[playerid][pAdoTag], COLOR_PURPLE, flyingtext);
        else
            pData[playerid][pAdoTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
    else
    {
        pData[playerid][pAdoActive] = true;
        pData[playerid][pAdoTag] = CreateDynamic3DTextLabel(flyingtext, COLOR_PURPLE, x, y, z, 15, _, _, 1, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
	printf("[ADO] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:ame(playerid, params[])
{
    new flyingtext[164];

    if(isnull(params))
        return Usage(playerid, "/ame [action]");

    if(strlen(params) > 128)
        return Error(playerid, "Max action can only maximmum 128 characters.");

	if(GetPVarType(playerid, "Caps")) UpperToLower(params);
    if(strlen(params) > 64) 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AME]: %.64s ..", params);
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, ".. %s", params[64]);
    }
    else 
	{
        SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* [AME]: %s", params);
    }
    format(flyingtext, sizeof(flyingtext), "* %s %s*", ReturnName(playerid), params);
    SetPlayerChatBubble(playerid, flyingtext, COLOR_PURPLE, 10.0, 10000);
	printf("[AME] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:toglog(playerid, params[])
{
	if(!pData[playerid][pTogLog])
	{
		pData[playerid][pTogLog] = 1;
		Info(playerid, "Anda telah menonaktifkan log server.");
	}
	else
	{
		pData[playerid][pTogLog] = 0;
		Info(playerid, "Anda telah mengaktifkan log server.");
	}
	return 1;
}

CMD:togpm(playerid, params[])
{
	if(!pData[playerid][pTogPM])
	{
		pData[playerid][pTogPM] = 1;
		Info(playerid, "Anda telah menonaktifkan PM");
	}
	else
	{
		pData[playerid][pTogPM] = 0;
		Info(playerid, "Anda telah mengaktifkan PM");
	}
	return 1;
}

CMD:pm(playerid, params[])
{
    static text[128], otherid;
    if(sscanf(params, "us[128]", otherid, text))
        return Usage(playerid, "/pm [playerid/PartOfName] [message]");

    /*if(pData[playerid][pTogPM])
        return Error(playerid, "You must enable private messaging first.");*/

    /*if(pData[otherid][pAdminDuty])
        return Error(playerid, "You can't pm'ing admin duty now!");*/
		
	if(otherid == INVALID_PLAYER_ID)
        return Error(playerid, "You have specified an invalid player.");

    if(otherid == playerid)
        return Error(playerid, "You can't private message yourself.");

    if(pData[otherid][pTogPM])
        return Error(playerid, "That player has disabled private messaging.");

    //GameTextForPlayer(otherid, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~y~New message!", 3000, 3);
    PlayerPlaySound(otherid, 1085, 0.0, 0.0, 0.0);

    SendClientMessageEx(otherid, COLOR_YELLOW, "(( PM from %s (%d): %s ))", pData[playerid][pName], playerid, text);
    SendClientMessageEx(playerid, COLOR_YELLOW, "(( PM to %s (%d): %s ))", pData[otherid][pName], otherid, text);
	Info(otherid, "/togpm for tog enable/disable PM");

    foreach(new i : Player) if((pData[i][pAdmin]) && pData[playerid][pSPY] > 0)
    {
        SendClientMessageEx(i, COLOR_LIGHTGREEN, "[SPY PM] %s (%d) to %s (%d): %s", pData[playerid][pName], playerid, pData[otherid][pName], otherid, text);
    }
    return 1;
}

CMD:b(playerid, params[])
{
    if(isnull(params))
        return Usage(playerid, "/b [text]");
		
	if(pData[playerid][pAdminDuty] == 1)
    {
		SendNearbyMessage(playerid, 20.0, COLOR_WHITE, "{ff0000}Administrator {ffffff}%s (%s)[%d]: (( %s ))", pData[playerid][pName], pData[playerid][pUCP], playerid, params);
	}
	else
	{
		SendNearbyMessage(playerid, 20.0, COLOR_WHITE, "Warga %s (%s)[%d]: (( %s ))", pData[playerid][pName], pData[playerid][pUCP], playerid, params);
	}
	//printf("[OOC] %s(%d) : %s", pData[playerid][pName], playerid, params);
    return 1;
}

CMD:call(playerid, params[])
{
	new ph;
	if(pData[playerid][pPhone] == 0) return Error(playerid, "You dont have phone!");
	if(pData[playerid][pPhoneCredit] <= 0) return Error(playerid, "You dont have phone credits!");
	
	if(sscanf(params, "d", ph))
        return Usage(playerid, "/call [phone number] 933 - Taxi Call | 911 - SAPD Crime Call | 922 - SAMD Medic Call");
	
	if(ph == 911)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		Info(playerid, "Warning: This number for emergency crime only! please wait for SAPD respon!");
		SendFactionMessage(1, COLOR_BLUE, "[EMERGENCY CALL] "WHITE_E"%s calling the emergency crime! Ph: ["GREEN_E"%d"WHITE_E"] | Location: %s", ReturnName(playerid), pData[playerid][pPhone], GetLocation(x, y, z));
	}
	if(ph == 922)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		Info(playerid, "Warning: This number for emergency medical only! please wait for SAMD respon!");
		SendFactionMessage(3, COLOR_PINK2, "[EMERGENCY CALL] "WHITE_E"%s calling the emergency medical! Ph: ["GREEN_E"%d"WHITE_E"] | Location: %s", ReturnName(playerid), pData[playerid][pPhone], GetLocation(x, y, z));
	}
	if(ph == 933)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		Info(playerid, "Your calling has sent to the taxi driver. please wait for respon!");
		foreach(new tx : Player)
		{
			if(pData[tx][pJob] == 1 || pData[tx][pJob2] == 1)
			{
				SendClientMessageEx(tx, COLOR_YELLOW, "[TAXI CALL] "WHITE_E"%s calling the taxi for order! Ph: ["GREEN_E"%d"WHITE_E"] | Location: %s", ReturnName(playerid), pData[playerid][pPhone], GetLocation(x, y, z));
			}
		}
	}
	if(ph == pData[playerid][pPhone]) return Error(playerid, "Nomor sedang sibuk!");
	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(pData[ii][IsLoggedIn] == false || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
			
			pData[playerid][pCall] = ii;
			if(IsPlayerConnected(ii))
			{
				if(pData[ii][pCall] == INVALID_PLAYER_ID)
				{
					SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE to %d] "WHITE_E"phone begins to ring, please wait for answer!", ph);
					SendClientMessageEx(ii, COLOR_YELLOW, "[CELLPHONE form %d] "WHITE_E"Your phonecell is ringing, type '/p' to answer it!", pData[playerid][pPhone]);
					PlayerPlaySound(playerid, 3600, 0,0,0);
					PlayerPlaySound(ii, 6003, 0,0,0);
					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
					SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s takes out a cellphone and calling someone.", ReturnName(playerid));
					return 1;
				}
				else
				{
					Error(playerid, "Nomor ini sedang sibuk.");
					return 1;
				}
			}
		}
	}
	return 1;
}

CMD:p(playerid, params[])
{
	if(pData[playerid][pCall] != INVALID_PLAYER_ID)
		return Error(playerid, "Anda sudah sedang menelpon seseorang!");
		
	if(pData[playerid][pInjured] != 0)
		return Error(playerid, "You cant do that in this time.");
		
	foreach(new ii : Player)
	{
		if(pData[ii][pCall] == playerid)
		{
			pData[ii][pPhoneCredit]--;
			
			pData[playerid][pCall] = ii;
			SendClientMessageEx(ii, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			SendClientMessageEx(playerid, COLOR_YELLOW, "[CELLPHONE] "WHITE_E"phone is connected, type '/hu' to stop!");
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
			SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s answers their cellphone.", ReturnName(playerid));
		}
	}
	return 1;
}

CMD:hu(playerid, params[])
{
	new caller = pData[playerid][pCall];
	if(IsPlayerConnected(caller) && caller != INVALID_PLAYER_ID)
	{
		pData[caller][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
		SendNearbyMessage(caller, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(caller));
		
		SendNearbyMessage(playerid, 20.0, COLOR_PURPLE, "* %s puts away their cellphone.", ReturnName(playerid));
		pData[playerid][pCall] = INVALID_PLAYER_ID;
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
	}
	return 1;
}

CMD:sms(playerid, params[])
{
	new ph, text[50];
	if(pData[playerid][pPhone] == 0) return Error(playerid, "You dont have phone!");
	if(pData[playerid][pPhoneCredit] <= 0) return Error(playerid, "You dont have phone credits!");
	if(pData[playerid][pInjured] != 0) return Error(playerid, "You cant do at this time.");
	
	if(sscanf(params, "ds[50]", ph, text))
        return Usage(playerid, "/sms [phone number] [message max 50 text]");
	
	foreach(new ii : Player)
	{
		if(pData[ii][pPhone] == ph)
		{
			if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii)) return Error(playerid, "This number is not actived!");
			SendClientMessageEx(playerid, COLOR_YELLOW, "[SMS to %d]"WHITE_E" %s", ph, text);
			SendClientMessageEx(ii, COLOR_YELLOW, "[SMS from %d]"WHITE_E" %s", pData[playerid][pPhone], text);
			Info(ii, "Gunakan "LB_E"'@<text>' "WHITE_E"untuk membalas SMS!");
			PlayerPlaySound(ii, 6003, 0,0,0);
			pData[ii][pSMS] = pData[playerid][pPhone];
			
			pData[playerid][pPhoneCredit] -= 1;
		}
	}
	return 1;
}

CMD:savestats(playerid, params[])
{
	UpdateWeapons(playerid);
	UpdatePlayerData(playerid);
	Info(playerid, "Your data have been saved!");
	return 1;
}
//------------------[ Bisnis and Buy Commands ]-------
CMD:buy(playerid, params[])
{
	//trucker product
	if(IsPlayerInRangeOfPoint(playerid, 3.5, -279.67, -2148.42, 28.54))
	{
		if(pData[playerid][pJob] == 4 || pData[playerid][pJob2] == 4)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new mstr[128];
				format(mstr, sizeof(mstr), ""WHITEP_E"Masukan jumlah product:\nProduct Stock: "GREEN_E"%d\n"WHITE_E"Product Price"GREEN_E"%s / item", Product, FormatMoney(ProductPrice));
				ShowPlayerDialog(playerid, DIALOG_PRODUCT, DIALOG_STYLE_INPUT, "Buy Product", mstr, "Buy", "Cancel");
			}
			else return Error(playerid, "You are not in vehicle trucker.");
		}
		else return Error(playerid, "You are not trucker job.");
	}
	//Material
	if(IsPlayerInRangeOfPoint(playerid, 2.5, -258.54, -2189.92, 28.97))
	{
		new mstr[128];
		format(mstr, sizeof(mstr), ""WHITEP_E"Masukan jumlah material:\nMaterial Stock: "GREEN_E"%d\n"WHITE_E"Material Price"GREEN_E"%s / item", Material, FormatMoney(MaterialPrice));
		ShowPlayerDialog(playerid, DIALOG_MATERIAL, DIALOG_STYLE_INPUT, "Buy Material", mstr, "Buy", "Cancel");
	}
	//Component
	if(IsPlayerInRangeOfPoint(playerid, 2.5, 315.07, 926.53, 20.46))
	{
		new mstr[128];
		format(mstr, sizeof(mstr), ""WHITEP_E"Masukan jumlah component:\nComponent Stock: "GREEN_E"%d\n"WHITE_E"Component Price"GREEN_E"%s / item", Component, FormatMoney(ComponentPrice));
		ShowPlayerDialog(playerid, DIALOG_COMPONENT, DIALOG_STYLE_INPUT, "Buy Component", mstr, "Buy", "Cancel");
	}
	//Apotek
	if(IsPlayerInRangeOfPoint(playerid, 2.5, 1435.34, -23.91, 1000.92))
	{
		new mstr[128];
		format(mstr, sizeof(mstr), ""WHITEP_E"Product\tPrice\n\
		Medicine\t"GREEN_E"%s\n\
		Medkit(Medical Only)\t"GREEN_E"%s\n\
		", FormatMoney(MedicinePrice), FormatMoney(MedkitPrice));
		ShowPlayerDialog(playerid, DIALOG_APOTEK, DIALOG_STYLE_TABLIST_HEADERS, "Apotek", mstr, "Buy", "Cancel");
	}
	//Buy House
	foreach(new hid : Houses)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtpos][0], hData[hid][hExtpos][1], hData[hid][hExtpos][2]))
		{
			if(hData[hid][hPrice] > GetPlayerMoney(playerid)) return Error(playerid, "Not enough money, you can't afford this houses.");
			if(strcmp(hData[hid][hOwner], "-")) return Error(playerid, "Someone already owns this house.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 2) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 3) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 4) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_HouseCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more houses.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -hData[hid][hPrice]);
			Server_AddMoney(hData[hid][hPrice]);
			GetPlayerName(playerid, hData[hid][hOwner], MAX_PLAYER_NAME);
			hData[hid][hVisit] = gettime();
			
			House_Refresh(hid);
			House_Save(hid);
		}
	}
	//Buy Bisnis
	foreach(new bid : Bisnis)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.5, bData[bid][bExtpos][0], bData[bid][bExtpos][1], bData[bid][bExtpos][2]))
		{
			if(bData[bid][bPrice] > GetPlayerMoney(playerid)) return Error(playerid, "Not enough money, you can't afford this bisnis.");
			if(strcmp(bData[bid][bOwner], "-")) return Error(playerid, "Someone already owns this bisnis.");
			if(pData[playerid][pVip] == 1)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_BisnisCount(playerid) + 1 > 2) return Error(playerid, "You can't buy any more bisnis.");
				#endif
			}
			else if(pData[playerid][pVip] == 2)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_BisnisCount(playerid) + 1 > 3) return Error(playerid, "You can't buy any more bisnis.");
				#endif
			}
			else if(pData[playerid][pVip] == 3)
			{
			    #if LIMIT_PER_PLAYER > 0
				if(Player_BisnisCount(playerid) + 1 > 4) return Error(playerid, "You can't buy any more bisnis.");
				#endif
			}
			else
			{
				#if LIMIT_PER_PLAYER > 0
				if(Player_BisnisCount(playerid) + 1 > 1) return Error(playerid, "You can't buy any more bisnis.");
				#endif
			}
			GivePlayerMoneyEx(playerid, -bData[bid][bPrice]);
			Server_AddMoney(-bData[bid][bPrice]);
			GetPlayerName(playerid, bData[bid][bOwner], MAX_PLAYER_NAME);
			bData[bid][bVisit] = gettime();
			
			Bisnis_Refresh(bid);
			Bisnis_Save(bid);
		}
	}
	//Buy Bisnis menu
	if(pData[playerid][pInBiz] >= 0 && IsPlayerInRangeOfPoint(playerid, 2.5, bData[pData[playerid][pInBiz]][bPoint][0], bData[pData[playerid][pInBiz]][bPoint][1], bData[pData[playerid][pInBiz]][bPoint][2]))
	{
		Bisnis_BuyMenu(playerid, pData[playerid][pInBiz]);
	}
	return 1;
}