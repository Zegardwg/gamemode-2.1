stock PlayerPlaySoundEx(playerid, sound)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	GetPlayerPos(playerid, x, y, z);

	foreach (new i : Player) if (IsPlayerInRangeOfPoint(i, 20.0, x, y, z)) {
	    PlayerPlaySound(i, sound, x, y, z);
	}
	return 1;
}

stock PlayReloadAnimation(playerid, weaponid)
{
	switch (weaponid)
	{
	    case 22: ApplyAnimation(playerid, "COLT45", "colt45_reload", 4.0, 0, 0, 0, 0, 0);
		case 23: ApplyAnimation(playerid, "SILENCED", "Silence_reload", 4.0, 0, 0, 0, 0, 0);
		case 24: ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
		case 25, 27: ApplyAnimation(playerid, "BUDDY", "buddy_reload", 4.0, 0, 0, 0, 0, 0);
		case 26: ApplyAnimation(playerid, "COLT45", "sawnoff_reload", 4.0, 0, 0, 0, 0, 0);
		case 29..31, 33, 34: ApplyAnimation(playerid, "RIFLE", "rifle_load", 4.0, 0, 0, 0, 0, 0);
		case 28, 32: ApplyAnimation(playerid, "TEC", "tec_reload", 4.0, 0, 0, 0, 0, 0);
	}
	return 1;
}							

stock IsPlayerNearPlayer(playerid, targetid, Float:radius)
{
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	GetPlayerPos(targetid, fX, fY, fZ);

	return (GetPlayerInterior(playerid) == GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid)) && IsPlayerInRangeOfPoint(playerid, radius, fX, fY, fZ);
}

function NotifHilang(playerid)
{
	for(new i = 0; i < 26; i++)
	{
		PlayerTextDrawHide(playerid, NotifTwitterGhea[playerid][i]);
	}
}

ClearChat(playerid)
{
	for(new i = 0; i < 29; i ++)
	{
	    SendClientMessage(playerid, -1, " ");
	}
}

function ShowMenuHP(playerid)
{
	for(new i = 0; i < 65; i++)
	{
		TextDrawShowForPlayer(playerid, HPMENUSCREEN[i]);
	}
}

function HideMenuHP(playerid)
{
	for(new i = 0; i < 65; i++)
	{
		TextDrawHideForPlayer(playerid, HPMENUSCREEN[i]);
	}
}

function NgeweHP(playerid)
{
	for(new i = 0; i < 65; i++)
	{
		TextDrawHideForPlayer(playerid, HPMENUSCREEN[i]);
	}
	CancelSelectTextDraw(playerid);
	RemovePlayerAttachedObject(playerid, 9);
	ClearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
}

stock loadWorld(playerid)
{
    GameTextForPlayer(playerid, "MEMUAT OBJECT", 5000, 3);
    TogglePlayerControllable(playerid, false);
    SetTimerEx("objectLoaded", 5000, false, "d", playerid);
    return 1;
}

function objectLoaded(playerid)
{
	TogglePlayerControllable(playerid, true);
	return 1;
}

stock HidePanelFull(playerid)
{
	for(new i = 0; i < 54; i++)
	{
		PlayerTextDrawHide(playerid, PR_PANELSTD[playerid][i]);
	}

	//

	for(new i = 0; i < 47; i++)
	{
		PlayerTextDrawHide(playerid, PR_DPANEL[playerid][i]);
	}

	//

	for(new i = 0; i < 29; i++)
	{
		PlayerTextDrawHide(playerid, PR_IPANEL[playerid][i]);
	}

	//

	for(new i = 0; i < 50; i++)
	{
		PlayerTextDrawHide(playerid, PR_KPANEL[playerid][i]);
	}
	TextDrawHideForPlayer(playerid, PR_KPANEL1[0]);

	//

	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, PR_PPANEL[playerid][i]);
	}
	CancelSelectTextDraw(playerid);
}

stock HidePanelFullNC(playerid)
{
	for(new i = 0; i < 54; i++)
	{
		PlayerTextDrawHide(playerid, PR_PANELSTD[playerid][i]);
	}

	//

	for(new i = 0; i < 47; i++)
	{
		PlayerTextDrawHide(playerid, PR_DPANEL[playerid][i]);
	}

	//

	for(new i = 0; i < 29; i++)
	{
		PlayerTextDrawHide(playerid, PR_IPANEL[playerid][i]);
	}

	//

	for(new i = 0; i < 50; i++)
	{
		PlayerTextDrawHide(playerid, PR_KPANEL[playerid][i]);
	}
	TextDrawHideForPlayer(playerid, PR_KPANEL1[0]);

	//

	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, PR_PPANEL[playerid][i]);
	}
	//CancelSelectTextDraw(playerid);
}

stock HidePanelS(playerid)
{
	for(new i = 0; i < 54; i++)
	{
		PlayerTextDrawHide(playerid, PR_PANELSTD[playerid][i]);
	}
}

stock HidePanelK(playerid)
{
	for(new i = 0; i < 50; i++)
	{
		PlayerTextDrawHide(playerid, PR_KPANEL[playerid][i]);
	}
	TextDrawHideForPlayer(playerid, PR_KPANEL1[0]);
}

stock HidePanelI(playerid)
{
	for(new i = 0; i < 29; i++)
	{
		PlayerTextDrawHide(playerid, PR_IPANEL[playerid][i]);
	}
}

stock HidePanelP(playerid)
{
	for(new i = 0; i < 28; i++)
	{
		PlayerTextDrawHide(playerid, PR_PPANEL[playerid][i]);
	}
}

stock HidePanelD(playerid)
{
	for(new i = 0; i < 47; i++)
	{
		PlayerTextDrawHide(playerid, PR_DPANEL[playerid][i]);
	}
}

stock ShowPanelS(playerid)
{
	for(new i = 0; i < 54; i++)
	{
		PlayerTextDrawShow(playerid, PR_PANELSTD[playerid][i]);
	}
}
stock GetNearestVehicle(playerid, Float:radius)
{
	static
	    Float:fX,
	    Float:fY,
	    Float:fZ;

	for (new i = 1; i != MAX_VEHICLES; i ++) if (IsValidVehicle(i) && GetVehiclePos(i, fX, fY, fZ))
	{
	    if (IsPlayerInRangeOfPoint(playerid, radius, fX, fY, fZ)) return i;
	}
	return INVALID_VEHICLE_ID;
}

function OnPlayerDataLoaded(playerid, race_check)
{
    SetPlayerCameraPos(playerid,698.826049, -1404.027099, 41);
	SetPlayerCameraLookAt(playerid,703.825317, -1404.041990, 39.802570);
	InterpolateCameraPos(playerid, 698.826049, -1404.027099, 16.206615, 2045.292480, -1425.237182, 128.337753, 60000);
	InterpolateCameraLookAt(playerid, 703.825317, -1404.041990, 500000681, 2050.291992, -1425.306762, 128.361190, 50000);
	if (race_check != g_MysqlRaceCheck[playerid]) return Kick(playerid);

	cache_get_value_name(0, "password", pData[playerid][pPassword], 65);
	cache_get_value_name(0, "salt", pData[playerid][pSalt], 17);
	cache_get_value_name_int(0, "verifycode", pData[playerid][pVerfi]);
	cache_get_value_name_int(0, "verdi", pData[playerid][pVerifikasi]);


	//new string[1000];
	if(cache_num_rows() > 0)
	{
		if(pData[playerid][pPassword] < 1)
		{
			new str[400];
			format(str, sizeof(str), "UCP: {15D4ED}%s\n{ffffff}Silahkan masukkan PIN yang sudah di kirimkan oleh KonohaBot", pData[playerid][pUCP]);
			ShowPlayerDialog(playerid, DIALOG_VERIFIKASI, DIALOG_STYLE_INPUT, "{15D4ED}Konoha Roleplay{ffffff} - Verify Account", str, "Input", "Batal");
		}
		if(pData[playerid][pPassword] > 10)
		{
			new lstring[512];
		    format(lstring, sizeof(lstring), "{FFFFFF}Selamat datang kembali di {15D4ED}Konoha Roleplay\n\n{FFFFFF}Akun-mu telah terdaftar di server.\nMasukkan password akun-mu untuk login:");
			ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "{15D4ED}Konoha Roleplay{ffffff} - Login", lstring, "Login", "Quit");

			//format(string, sizeof string, "{FFFFFF}This account is {00FF00}registered!\n\n{FFFFFF}UCP: {FFFF00}%s\n{FFFFFF}Enter your password below :", pData[playerid][pUCP]);
			//ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login to {15D4ED}Konoha{FFFF00}", string, "Login", "Abort");
		}
		//pData[playerid][LoginTimer] = SetTimerEx("OnLoginTimeout", SECONDS_TO_LOGIN * 1000, false, "i", playerid);
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX,"Kota Konoha - Tiket","Dari: Penjaga Pintu Konoha\nKepada: Calon Aktor (Pemain Peran) di Kota Konoha\n\nSilahkan Terlebih Dahulu mengambil tiket Konoha di discord sebelum dapat memasuki Kota Konoha\nLink Discord: https://discord.gg/5dmGMXYyaC","Keluar","");
        SetTimerEx("KickTimer", 1000, 0, "i", playerid);
	}
	return 1;
}
forward LDC_DEL(idx);
public LDC_DEL(idx)
{
	g_ldc[idx][LDC_ID] = -1;
	DestroyDynamic3DTextLabel(g_ldc[idx][LDC_LABEL]); 
	g_ldc[idx][LDC_TIMER] = -1;
	Iter_Remove(LDCS, idx);
	return 1;
}

function CheckBan(playerid)
{
	if(cache_num_rows() > 0)
	{
		new Reason[40], PlayerName[24];
	    new banTime_Int, banDate, banIP[16];
		cache_get_value(0, "admin", PlayerName);
		cache_get_value(0, "reason", Reason);
		cache_get_value(0, "ip", banIP);
		cache_get_value_int(0, "ban_expire", banTime_Int);
		cache_get_value_int(0, "ban_date", banDate);

		new currentTime = gettime();
        if(banTime_Int != 0 && banTime_Int <= currentTime) // Unban the player.
		{
			new query[248];
			mysql_format(g_SQL, query, sizeof(query), "DELETE FROM banneds WHERE name = '%s'", pData[playerid][pName]);
			mysql_tquery(g_SQL, query);
				
			Servers(playerid, "Welcome back to server, its been %s since your ban was lifted.", ReturnTimelapse(banTime_Int, gettime()));
		}
		else
		{
			new query[248], PlayerIP[16];
  			mysql_format(g_SQL, query, sizeof query, "UPDATE `banneds` SET `last_activity_timestamp` = %i WHERE `name` = '%s'", gettime(), pData[playerid][pName]);
			mysql_tquery(g_SQL, query);
				
			pData[playerid][IsLoggedIn] = false;
			printf("[BANNED INFO]: Ban Getting Called on %s", pData[playerid][pName]);
			GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"%s(%i) has been auto-kicked for ban evading.", pData[playerid][pName], playerid);
			InfoTD_MSG(playerid, 5000, "~r~~h~You are banned from this server!");
			//for(new l; l < 20; l++) SendClientMessage(playerid, COLOR_DARK, "\n");
			SendClientMessage(playerid, COLOR_RED, "You are banned from this server!");
			if(banTime_Int == 0)
			{
				new lstr[512];
				format(lstr, sizeof(lstr), "{FF0000}You are banned from this server!\n\n"LB2_E"Ban Info:\n{FF0000}Name: {778899}%s\n{FF0000}IP: {778899}%s\n{FF0000}Admin: {778899}%s\n{FF0000}Ban Date: {778899}%s\n{FF0000}Ban Reason: {778899}%s\n{FF0000}Ban Time: {778899}Permanent\n\n{FFFFFF}Feel that you were wrongfully banned? Appeal at nfs-server.pe.hu/forums", pData[playerid][pName], PlayerIP, PlayerName, ReturnDate(banDate), Reason);
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"BANNED", lstr, "Exit", "");
			}
			else
			{
				new lstr[512];
				format(lstr, sizeof(lstr), "{FF0000}You are banned from this server!\n\n"LB2_E"Ban Info:\n{FF0000}Name: {778899}%s\n{FF0000}IP: {778899}%s\n{FF0000}Admin: {778899}%s\n{FF0000}Ban Date: {778899}%s\n{FF0000}Ban Reason: {778899}%s\n{FF0000}Ban Time: {778899}%s\n\n{FFFFFF}Feel that you were wrongfully banned? Appeal at nfs-server.pe.hu/forums", pData[playerid][pName], PlayerIP, PlayerName, ReturnDate(banDate), Reason, ReturnTimelapse(gettime(), banTime_Int));
				ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, ""RED_E"BANNED", lstr, "Exit", "");
			}
			KickEx(playerid);
			return 1;
  		}
	}
	return 1;
}

function CekNamaDobelJing(playerid, name[])
{
	new rows = cache_num_rows();
	if(rows > 0)
	{
		ShowPlayerDialog(playerid, DIALOG_MAKE_CHAR, DIALOG_STYLE_INPUT, "Create Character", "ERROR: This name is already used by the other player!\nInsert your new Character Name\n\nExample: Finn_Xanderz, Javier_Cooper etc.", "Create", "Back");
	}
	else 
	{
		new characterQuery[178];
		mysql_format(g_SQL, characterQuery, sizeof(characterQuery), "INSERT INTO players ( username, ucp, reg_date ) VALUES ('%s', '%s', CURRENT_TIMESTAMP())", name, GetName(playerid));
		mysql_tquery(g_SQL, characterQuery, "OnPlayerRegister", "d", playerid);

		SetPlayerName(playerid, name);
		format(pData[playerid][pName], MAX_PLAYER_NAME, name);
	}
}


function OnPlayerRegister(playerid)
{
	pData[playerid][pID] = cache_insert_id();
	pData[playerid][IsLoggedIn] = true;

	pData[playerid][pPosX] = DEFAULT_POS_X;
	pData[playerid][pPosY] = DEFAULT_POS_Y;
	pData[playerid][pPosZ] = DEFAULT_POS_Z;
	pData[playerid][pPosA] = DEFAULT_POS_A;
	pData[playerid][pInt] = 0;
	pData[playerid][pWorld] = 0;
	pData[playerid][pGender] = 0;
	
	format(pData[playerid][pAdminname], 128, "None");
	format(pData[playerid][pEmail], 128, "None");
	pData[playerid][pHealth] = 100.0;
	pData[playerid][pArmour] = 0.0;
	pData[playerid][pLevel] = 1;
	pData[playerid][pHunger] = 100;
	pData[playerid][pBladder] = 0;
	pData[playerid][pEnergy] = 100;
	pData[playerid][pMoney] = 15000;
	pData[playerid][pBankMoney] = 5000;
	/*new rand = RandomEx(111111, 999999);
	new rek = rand+pData[playerid][pID];
	pData[playerid][pBankRek] = rek;*/
	
	new query[128], rand = RandomEx(111111111, 999999999);
	new rek = rand+pData[playerid][pID];
	mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
	mysql_tquery(g_SQL, query, "BankRek", "id", playerid, rek);
	
	Inventory_Add(playerid, "Backpack", 2919);
	ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "{a8ecff}Konoha Roleplay{FFFFFF} - Tanggal Lahir", "Mohon masukan tanggal lahir sesuai format hh/bb/tttt cth: (25/08/2001)", "Input", "");
	return 1;
}

function BankRek(playerid, brek)
{
	if(cache_num_rows() > 0)
	{
		//Rekening Exist
		new query[128], rand = RandomEx(11111, 99999);
		new rek = rand+pData[playerid][pID];
		mysql_format(g_SQL, query, sizeof(query), "SELECT brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "BankRek", "is", playerid, rek);
		Info(playerid, "Your Bank rekening number is same with someone. We will research new.");
	}
	else
	{
		new query[128];
	    mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET brek='%d' WHERE ID=%d", brek, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);
		pData[playerid][pBankRek] = brek;
	}
    return true;
}

function PhoneNumber(playerid, phone)
{
	if(cache_num_rows() > 0)
	{
		//Rekening Exist
		new query[128], rand = RandomEx(1111, 9888);
		new phones = rand+pData[playerid][pID];
		mysql_format(g_SQL, query, sizeof(query), "SELECT phone FROM players WHERE phone='%d'", phones);
		mysql_tquery(g_SQL, query, "PhoneNumber", "is", playerid, phones);
		Info(playerid, "Your Phone number is same with someone. We will research new.");
	}
	else
	{
		new query[128];
	    mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET phone='%d' WHERE ID=%d", phone, pData[playerid][pID]);
		mysql_tquery(g_SQL, query);
		pData[playerid][pPhone] = phone;
	}
    return true;
}

function OnLoginTimeout(playerid)
{
	pData[playerid][LoginTimer] = 0;

	ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, "Login", "You have been kicked for taking too long to login successfully to your account.", "Okay", "");
	KickEx(playerid);
	return 1;
}


function _KickPlayerDelayed(playerid)
{
	Kick(playerid);
	return 1;
}

function SafeLogin(playerid)
{

	// Main Menu Features.
	SetPlayerVirtualWorld(playerid, 0);
	
	if(!IsValidRoleplayName(pData[playerid][pName]))
    {
        Error(playerid, "Nama tidak sesuai format untuk server mode roleplay.");
        Error(playerid, "Penggunaan nama harus mengikuti format Firstname_Lastname.");
        Error(playerid, "Sebagai contoh, Steven_Dreschler, Nick_Raymond, dll.");
        KickEx(playerid);
    }
}

//---------[ Textdraw ]----------

// Info textdraw timer for hiding the textdraw
function InfoTD_MSG(playerid, ms_time, text[])
{
	if(GetPVarInt(playerid, "InfoTDshown") != -1)
	{
	    PlayerTextDrawHide(playerid, InfoTD[playerid]);
	    KillTimer(GetPVarInt(playerid, "InfoTDshown"));
	}

    PlayerTextDrawSetString(playerid, InfoTD[playerid], text);
    PlayerTextDrawShow(playerid, InfoTD[playerid]);
	SetPVarInt(playerid, "InfoTDshown", SetTimerEx("InfoTD_Hide", ms_time, false, "i", playerid));
}

function InfoTD_Hide(playerid)
{
	SetPVarInt(playerid, "InfoTDshown", -1);
	PlayerTextDrawHide(playerid, InfoTD[playerid]);
}

//---------[Admin Function ]----------

function a_ChangeAdminName(otherplayer, playerid, nname[])
{
	if(cache_num_rows() > 0)
	{
		// Name Exists
		Error(playerid, "The name "DARK_E"'%s' "GREY_E"already exists in the database, please use a different name!", nname);
	}
	else
	{
		new query[128];
	    format(query, sizeof(query), "UPDATE players SET adminname='%s' WHERE id=%d", nname, pData[otherplayer][pID]);
		mysql_tquery(g_SQL, query);
		format(pData[otherplayer][pAdminname], 128, "%s", nname);
		Servers(playerid, "You has set admin name player %s to %s", pData[otherplayer][pName], nname);
	}
    return true;
}

function LoadStats(playerid, PlayersName[])
{
	if(!cache_num_rows())
	{
		Error(playerid, "Account '%s' does not exist.", PlayersName);
	}
	else
	{
		new email[40], admin, helper, level, levelup, vip, viptime, coin, regdate[40], lastlogin[40], money, bmoney, brek,
			jam, menit, detik, gender, age[40], faction, family, warn, job, job2, int, world;
		cache_get_value(0, 0, email);
		cache_get_value_int(0, 1, admin);
		cache_get_value_int(0, 2, helper);
		cache_get_value_int(0, 3, level);
		cache_get_value_int(0, 4, levelup);
		cache_get_value_int(0, 5, vip);
		cache_get_value_int(0, 6, viptime);
		cache_get_value_int(0, 7, coin);
		cache_get_value(0, 8, regdate);
		cache_get_value(0, 9, lastlogin);
		cache_get_value_int(0, 10, money);
		cache_get_value_int(0, 11, bmoney);
		cache_get_value_int(0, 12, brek);
		cache_get_value_int(0, 13, jam);
		cache_get_value_int(0, 14, menit);
		cache_get_value_int(0, 15, detik);
		cache_get_value_int(0, 16, gender);
		cache_get_value(0, 17, age);
		cache_get_value_int(0, 18, faction);
		cache_get_value_int(0, 19, family);
		cache_get_value_int(0, 20, warn);
		cache_get_value_int(0, 21, job);
		cache_get_value_int(0, 22, job2);
		cache_get_value_int(0, 23, int);
		cache_get_value_int(0, 24, world);
		
		new header[248], scoremath = ((level)*4), fac[24], Cache:checkfamily, gstr[2468], query[128];
	
		if(faction == 1)
		{
			fac = "San Andreas Police";
		}
		else if(faction == 2)
		{
			fac = "San Andreas Goverment";
		}
		else if(faction == 3)
		{
			fac = "San Andreas Medic";
		}
		else if(faction == 4)
		{
			fac = "San Andreas News";
		}
		else
		{
			fac = "None";
		}
		
		new name[40];
		if(admin == 1)
		{
			name = ""RED_E"Administrator(1)";
		}
		else if(admin == 2)
		{
			name = ""RED_E"Senior Admin(2)";
		}
		else if(admin == 3)
		{
			name = ""RED_E"Lead Admin(3)";
		}
		else if(admin == 4)
		{
			name = ""RED_E"Head Admin(4)";
		}
		else if(admin== 5)
		{
			name = ""RED_E"Server Owner(5)";
		}
		else if(helper >= 1 && admin == 0)
		{
			name = ""GREEN_E"Helper";
		}
		else
		{
			name = "None";
		}
		
		new name1[30];
		if(vip == 1)
		{
			name1 = ""LG_E"Regular(1)";
		}
		else if(vip == 2)
		{
			name1 = ""YELLOW_E"Premium(2)";
		}
		else if(vip == 3)
		{
			name1 = ""PURPLE_E"VIP Player(3)";
		}
		else
		{
			name1 = "None";
		}
		
		format(query, sizeof(query), "SELECT * FROM `familys` WHERE `ID`='%d'", family);
		checkfamily = mysql_query(g_SQL, query);
		
		new rows = cache_num_rows(), fname[128];
		
		if(rows)
		{
			new fam[128];
			cache_get_value(0, "name", fam);
			format(fname, 128, fam);
		}
		else
		{
			format(fname, 128, "None");
		}
		
		format(header,sizeof(header),"Stats:"YELLOW_E"%s"WHITE_E" ("BLUE_E"%s"WHITE_E")", PlayersName, ReturnTime());
		format(gstr,sizeof(gstr),""RED_E"In Character"WHITE_E"\n");
		format(gstr,sizeof(gstr),"%sGender: [%s] | Money: ["GREEN_E"%s"WHITE_E"] | Bank: ["GREEN_E"%s"WHITE_E"] | Rekening Bank: [%d] | Phone Number: [None]\n", gstr,(gender == 2) ? ("Female") : ("Male") , FormatMoney(money), FormatMoney(bmoney), brek);
		format(gstr,sizeof(gstr),"%sBirdthdate: [%s] | Job: [None] | Job2: [None] | Faction: [%s] | Family: [%s]\n\n", gstr, age, fac, fname);
		format(gstr,sizeof(gstr),"%s"RED_E"Out of Character"WHITE_E"\n",gstr);
		format(gstr,sizeof(gstr),"%sLevel score: [%d/%d] | Email: [%s] | Warning:[%d/10] | Last Login: [%s]\n", gstr, levelup, scoremath, email, warn, lastlogin);
		format(gstr,sizeof(gstr),"%sStaff: [%s"WHITE_E"] | Time Played: [%d hour(s) %d minute(s) %02d second(s)] | Gold Coin: [%d]\n", gstr, name, jam, menit, detik, coin);
		if(vip != 0)
		{
			format(gstr,sizeof(gstr),"%sInterior: [%d] | Virtual World: [%d] | Register Date: [%s] | VIP Level: [%s"WHITE_E"] | VIP Time: [%s]", gstr, int, world, regdate, name1, ReturnTimelapse(gettime(), viptime));
		}
		else
		{
			format(gstr,sizeof(gstr),"%sInterior: [%d] | Virtual World: [%d] | Register Date: [%s] | VIP Level: [%s"WHITE_E"] | VIP Time: [None]", gstr, int, world, regdate, name1);
		}
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, header, gstr, "Close", "");
		
		cache_delete(checkfamily);
	}
	return true;
}

function CheckPlayerIP(playerid, zplayerIP[])
{
	new count = cache_num_rows(), datez, line[248], tstr[64], lstr[128];
	if(count)
	{
		datez = 0;
 		line = "";
 		format(line, sizeof(line), "Names matching IP: %s:\n\n", zplayerIP);
 		for(new i = 0; i != count; i++)
		{
			// Get the name  ache and append it to the dialog content
			cache_get_value(i, 0, lstr);
			strcat(line, lstr);
			datez ++;

			if(datez == 5)
				strcat(line, "\n"), datez = 0;
			else
				strcat(line, "\t\t");
		}

		tstr = "{ACB5BA}Aliases for {70CAFA}", strcat(tstr, zplayerIP);
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, tstr, line, "Close", "");
	}
	else
 	{
		Error(playerid, "No other accounts from this IP!");
	}
	return 1;
}

function CheckPlayerIP2(playerid, zplayerIP[])
{
	new rows = cache_num_rows(), datez, line[248], tstr[64], lstr[128];
	if(!rows)
	{
		Error(playerid, "No other accounts from this IP!");
	}
	else
 	{
 		datez = 0;
 		line = "";
 		format(line, sizeof(line), "Names matching IP: %s:\n\n", zplayerIP);
 		for(new i = 0; i != rows; i++)
		{
			// Get the name from the cache and append it to the dialog content
			cache_get_value(i, 0, lstr);
			strcat(line, lstr);
			datez ++;

			if(datez == 5)
				strcat(line, "\n"), datez = 0;
			else
				strcat(line, "\t\t");
		}

		tstr = "{ACB5BA}Aliases for {70CAFA}", strcat(tstr, zplayerIP);
		ShowPlayerDialog(playerid, DIALOG_UNUSED, DIALOG_STYLE_MSGBOX, tstr, line, "Close", "");
	}
	return 1;
}

function JailPlayer(playerid)
{
	//ShowPlayerDialog(playerid, -1, DIALOG_STYLE_LIST, "Close", "Close", "Close", "Close");
	SetPlayerPositionEx(playerid, -310.64, 1894.41, 34.05, 178.17, 2000);
	SetPlayerInterior(playerid, 10);
	SetPlayerVirtualWorld(playerid, 100);
	SetPlayerWantedLevel(playerid, 0);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	ResetPlayerWeaponsEx(playerid);
	pData[playerid][pInBiz] = -1;
	pData[playerid][pInHouse] = -1;
	pData[playerid][pInDoor] = -1;
	SetPlayerCuffed(playerid, false);
	PlayerPlaySound(playerid, 1186, 0, 0, 0);
	return true;
}

//-----------[ Banneds Function ]----------

function OnOBanQueryData(adminid, NameToBan[], banReason[], banTime)
{
	new mstr[512];
	mstr = "";
	if(!cache_num_rows())
	{
		Error(adminid, "Account '%s' does not exist.", NameToBan);
	}
	else
	{
		new datez, PlayerIP[16];
		cache_get_value(0, 0, PlayerIP);
		if(banTime != 0)
	    {
			datez = gettime() + (banTime * 86400);
            Servers(adminid, "You have temp-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline player %s selama %d hari. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banTime, banReason);
		}
		else
		{
			Servers(adminid, "You have permanent-banned %s (IP: %s) from the server.", NameToBan, PlayerIP);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Admin %s telah membanned offline player %s secara permanent. [Reason: %s]", pData[adminid][pAdminname], NameToBan, banReason);
		}
		new query[512];
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', '%s', '%s', UNIX_TIMESTAMP(), %d)", NameToBan, PlayerIP, pData[adminid][pAdminname], banReason, datez);
		mysql_tquery(g_SQL, query);
	}
	return true;
}


//-------------[ Player Update Function ]----------

function DragUpdate(playerid, targetid)
{
    if(pData[targetid][pDragged] && pData[targetid][pDraggedBy] == playerid)
    {
        static
        Float:fX,
        Float:fY,
        Float:fZ,
        Float:fAngle;

        GetPlayerPos(playerid, fX, fY, fZ);
        GetPlayerFacingAngle(playerid, fAngle);

        fX -= 3.0 * floatsin(-fAngle, degrees);
        fY -= 3.0 * floatcos(-fAngle, degrees);

        SetPlayerPos(targetid, fX, fY, fZ);
        SetPlayerInterior(targetid, GetPlayerInterior(playerid));
        SetPlayerVirtualWorld(targetid, GetPlayerVirtualWorld(playerid));
		//ApplyAnimation(targetid, "PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0, 1);
		ApplyAnimation(targetid,"PED","WALK_civi",4.1,1,1,1,1,1);
    }
    return 1;
}

function UnfreezePee(playerid)
{
    TogglePlayerControllable(playerid, 1);
   // pData[playerid][pBladder] = 0;
    ClearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

function UnfreezeSleep(playerid)
{
    TogglePlayerControllable(playerid, 1);
    pData[playerid][pEnergy] = 100;
	pData[playerid][pHunger] -= 3;
    ClearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	InfoTD_MSG(playerid, 3000, "Sleeping Done!");
	return 1;
}

function RefullCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
    {
		if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
		{
			new fuels = GetVehicleFuel(vehicleid);
		
			SetVehicleFuel(vehicleid, fuels+300);
			InfoTD_MSG(playerid, 8000, "Refulling done!");
			//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has successfully refulling the vehicle.", ReturnName(playerid));
			KillTimer(pData[playerid][pActivity]);
			pData[playerid][pActivityTime] = 0;
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
		}
		else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
		{
			pData[playerid][pActivityTime] += 5;
			SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
		}
		else
		{
			Error(playerid, "Refulling fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			pData[playerid][pActivityTime] = 0;
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
		}
	}
	else
	{
		Error(playerid, "Refulling fail! Anda tidak berada didekat kendaraan tersebut!");
		KillTimer(pData[playerid][pActivity]);
		pData[playerid][pActivityTime] = 0;
		HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
		PlayerTextDrawHide(playerid, ActiveTD[playerid]);
		return 1;
	}
	return 1;
}

//Bank
function SearchRek(playerid, rek)
{
	if(!cache_num_rows())
	{
		// Rekening tidak ada
		Error(playerid, "Rekening bank "YELLOW_E"'%d' "WHITE_E"tidak terdaftar!", rek);
		pData[playerid][pTransfer] = 0;
	    
	}
	else
	{
	    // Proceed
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "SELECT username,brek FROM players WHERE brek='%d'", rek);
		mysql_tquery(g_SQL, query, "SearchRek2", "id", playerid, rek);
	}
}

function SearchRek2(playerid, rek)
{
	if(cache_num_rows())
	{
		new name[128], brek, mstr[128];
		cache_get_value(0, 0, name);
		//format(pData[playerid][pAdminname], 128, "%s", aname);
		cache_get_value_int(0, 1, brek);
		
		//format(pData[playerid][pTransferName], 128, "%s" name);
		pData[playerid][pTransferName] = name;
		pData[playerid][pTransferRek] = brek;
		format(mstr, sizeof(mstr), ""WHITE_E"No Rek Target: "YELLOW_E"%d\n"WHITE_E"Nama Target: "YELLOW_E"%s\n"WHITE_E"Jumlah: "GREEN_E"%s\n\n"WHITE_E"Anda yakin akan melanjutkan mentransfer?", brek, name, FormatMoney(pData[playerid][pTransfer]));
		ShowPlayerDialog(playerid, DIALOG_BANKCONFIRM, DIALOG_STYLE_MSGBOX, ""LB_E"Bank", mstr, "Transfer", "Cancel");
	}
	return true;
}

//----------[ JOB FUNCTION ]-------------
//Mech JOB
function CheckCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(pData[playerid][pJob] == 2 || pData[playerid][pJob2] == 2)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pMechVeh] = vehicleid;
				InfoTD_MSG(playerid, 8000, "Checking done!");
				//SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s has successfully refulling the vehicle.", ReturnName(playerid));
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pActivityTime] = 0;
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				ClearAnimations(playerid);
				return 1;
			}
			else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pActivityTime] += 5;
				SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
			}
			else
			{
				Error(playerid, "Checking fail! Anda tidak berada didekat kendaraan tersebut!");
				KillTimer(pData[playerid][pActivity]);
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				pData[playerid][pActivityTime] = 0;
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			}
		}
		else
		{
			Error(playerid, "Checking fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			return 1;
		}
	}
	return 1;
}

function BodyFix(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(pData[playerid][pJob] == 2 || pData[playerid][pJob2] == 2)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
			{
				new panels, doors, light, tires;	
				GetVehicleDamageStatus(vehicleid, panels, doors, light, tires);		
				UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);
				
				InfoTD_MSG(playerid, 8000, "Fix body done!");
				pData[playerid][pMechVeh] = vehicleid;
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pActivityTime] = 0;
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				ClearAnimations(playerid);
				return 1;
			}
			else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pActivityTime] += 5;
				SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
			}
			else
			{
				Error(playerid, "Body fix fail! Anda tidak berada didekat kendaraan tersebut!");
				KillTimer(pData[playerid][pActivity]);
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				pData[playerid][pActivityTime] = 0;
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			}
		}
		else
		{
			Error(playerid, "Body fix fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			return 1;
		}
	}
	return 1;
}

function EngineFix(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(pData[playerid][pJob] == 2 || pData[playerid][pJob2] == 2)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
			{
				SetValidVehicleHealth(vehicleid, 1000);
				//new panels, doors, light, tires;	
				//GetVehicleDamageStatus(vehicleid, panels, doors, light, tires);		
				//UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);
				
				InfoTD_MSG(playerid, 8000, "Fix engine done!");
				pData[playerid][pMechVeh] = vehicleid;
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pActivityTime] = 0;
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				ClearAnimations(playerid);
				return 1;
			}
			else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pActivityTime] += 5;
				SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
			}
			else
			{
				Error(playerid, "Engine fix fail! Anda tidak berada didekat kendaraan tersebut!");
				KillTimer(pData[playerid][pActivity]);
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				pData[playerid][pActivityTime] = 0;
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			}
		}
		else
		{
			Error(playerid, "Engine fix fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			return 1;
		}
	}
	return 1;
}

function SprayCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(pData[playerid][pJob] == 2 || pData[playerid][pJob2] == 2)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
			{
				
				ChangeVehicleColor(vehicleid, pData[playerid][pMechColor1], pData[playerid][pMechColor2]);
				
				InfoTD_MSG(playerid, 8000, "Spraying done!");
				pData[playerid][pMechVeh] = vehicleid;
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pActivityTime] = 0;
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				ClearAnimations(playerid);
				return 1;
			}
			else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pActivityTime] += 5;
				SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
			}
			else
			{
				Error(playerid, "Spraying car fail! Anda tidak berada didekat kendaraan tersebut!");
				KillTimer(pData[playerid][pActivity]);
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				pData[playerid][pActivityTime] = 0;
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			}
		}
		else
		{
			Error(playerid, "Engine fix fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			return 1;
		}
	}
	return 1;
}

function PaintjobCar(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	//if(!IsValidVehicle(vehicleid)) return 0;
	if(!IsValidTimer(pData[playerid][pActivity])) return 0;
	if(pData[playerid][pJob] == 2 || pData[playerid][pJob2] == 2)
	{
		if(GetNearestVehicleToPlayer(playerid, 3.8, false) == vehicleid)
		{
			if(pData[playerid][pActivityTime] >= 100 && IsValidVehicle(vehicleid))
			{
				
				ChangeVehiclePaintjob(vehicleid, pData[playerid][pMechColor1]);
				
				InfoTD_MSG(playerid, 8000, "Painting done!");
				pData[playerid][pMechVeh] = vehicleid;
				KillTimer(pData[playerid][pActivity]);
				pData[playerid][pActivityTime] = 0;
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				ClearAnimations(playerid);
				return 1;
			}
			else if(pData[playerid][pActivityTime] < 100 && IsValidVehicle(vehicleid))
			{
				pData[playerid][pActivityTime] += 5;
				SetPlayerProgressBarValue(playerid, pData[playerid][activitybar], pData[playerid][pActivityTime]);
			}
			else
			{
				Error(playerid, "Spraying car fail! Anda tidak berada didekat kendaraan tersebut!");
				KillTimer(pData[playerid][pActivity]);
				HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
				PlayerTextDrawHide(playerid, ActiveTD[playerid]);
				pData[playerid][pActivityTime] = 0;
				pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			}
		}
		else
		{
			Error(playerid, "Engine fix fail! Anda tidak berada didekat kendaraan tersebut!");
			KillTimer(pData[playerid][pActivity]);
			HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
			PlayerTextDrawHide(playerid, ActiveTD[playerid]);
			pData[playerid][pActivityTime] = 0;
			pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
			return 1;
		}
	}
	return 1;
}

//Server Timer
function pCountDown()
{
	Count--;
	if(0 >= Count)
	{
		Count = -1;
		KillTimer(countTimer);
		foreach(new ii : Player)
		{
 			if(showCD[ii] == 1)
   			{
   				GameTextForPlayer(ii, "~w~GO~r~!~g~!~b~!", 2500, 6);
   				PlayerPlaySound(ii, 1057, 0, 0, 0);
   				showCD[ii] = 0;
			}
		}
	}
	else
	{
		foreach(new ii : Player)
		{
 			if(showCD[ii] == 1)
   			{
				GameTextForPlayer(ii, CountText[Count-1], 2500, 6);
				PlayerPlaySound(ii, 1056, 0, 0, 0);
   			}
		}
	}
	return 1;
}

//Player Update Time
function onlineTimer()
{	
	//Date and Time Textdraw
	new datestring[64];
	new hours,
	minutes,
	days,
	months,
	years;
	new MonthName[12][] =
	{
		"January", "February", "March", "April", "May", "June",
		"July",	"August", "September", "October", "November", "December"
	};
	getdate(years, months, days);
 	gettime(hours, minutes);
	format(datestring, sizeof datestring, "%s%d - %s - %s%d", ((days < 10) ? ("0") : ("")), days, MonthName[months-1], (years < 10) ? ("0") : (""), years);
	//TextDrawSetString(TextDate, datestring);
	format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
	//TextDrawSetString(TextTime, datestring);
	foreach(new ii : Player)
	{
		format(datestring, sizeof datestring, "%s%d %s %s%d", ((days < 10) ? ("0") : ("")), days, MonthName[months-1], (years < 10) ? ("0") : (""), years);
		TextDrawSetString(HPLOCKSCREEN[26], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(HPLOCKSCREEN[21], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(HPMENUSCREEN[21], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(APKBRIMO[21], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(APKGOJEK[21], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(TelponNotif[21], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		TextDrawSetString(PlayerTelpon[15], datestring);
		format(datestring, sizeof datestring, "%s%d:%s%d", (hours < 10) ? ("0") : (""), hours, (minutes < 10) ? ("0") : (""), minutes);
		PlayerTextDrawSetString(ii, NotifTwitterGhea[ii][25], datestring);
	}

    /*foreach (new i : Player) 
	{
		SetPlayerTime(i, hours, minutes);
		if(pData[i][pInDoor] <= -1 || pData[i][pInHouse] <= -1 || pData[i][pInBiz] <= -1)
        {
			SetPlayerWeather(i, GetGVarInt("g_Weather"));
		}
	}*/
	// Increase server uptime
	up_seconds ++;
	if(up_seconds == 60)
	{
	    up_seconds = 0, up_minutes ++;
	    if(up_minutes == 60)
	    {
	        up_minutes = 0, up_hours ++;
	        if(up_hours == 24) up_hours = 0, up_days ++;
			new tstr[128], rand = RandomEx(0, 20);
			format(tstr, sizeof(tstr), ""BLUE_E"UPTIME: "WHITE_E"The server has been online for %s.", Uptime());
			SendClientMessageToAll(COLOR_WHITE, tstr);
			if(hours > 20)
			{
				SetWorldTime(12);
			}
			else
			{
				SetWorldTime(hours);
			}
			SetWeather(rand);

			// Sync Server
			mysql_tquery(g_SQL, "OPTIMIZE TABLE `players`,`bisnis`,`houses`,`toys`,`vehicle`");
			//SetTimer("changeWeather", 10000, false);
		}
	}
	foreach(new ii : Player)
	{
		// Online Timer
		if(pData[ii][IsLoggedIn] == true /*&& cAFK[ii] == 0*/)
		{
			pData[ii][pPaycheck] ++;
			/*if(pData[ii][pPaycheck] >= 3600)
			{
				Info(ii, "Waktunya mengambil paycheck!");
				Servers(ii, "silahkan pergi ke bank atau ATM terdekat untuk mengambil paycheck.");
			}*/
			
			pData[ii][pSeconds] ++, pData[ii][pCurrSeconds] ++;
			if(pData[ii][pOnDuty] >= 1)
			{
				pData[ii][pOnDutyTime]++;
			}
			if(pData[ii][pTaxiDuty] >= 1)
			{
				pData[ii][pTaxiTime]++;
			}
			if(pData[ii][pSeconds] == 60)
			{
		    	pData[ii][pMinutes]++, pData[ii][pCurrMinutes] ++;
		    	pData[ii][pSeconds] = 0, pData[ii][pCurrSeconds] = 0;
				
				new scoremath = ((pData[ii][pLevel])*4);
				
				switch(pData[ii][pMinutes])
				{
				    case 10, 20, 30, 40, 50:
		            {
					    /*if(pData[ii][pHours] != 0)
					   	{
						   	format(lstr, sizeof(lstr), "~y~You have been online for ~r~~h~%d~y~ hours and ~r~~h~%d~y~ minutes.", pData[ii][pHours], pData[ii][pMinutes]);
							format(mstr, sizeof(mstr), ""RED_E"*** {FFE4C4}You have been online for %d hours and %d minutes.", pData[ii][pHours], pData[ii][pMinutes]);
						}
						else
						{
				            format(lstr, sizeof(lstr), "~y~You have been online for ~r~~h~%d~y~ minutes.", pData[ii][pMinutes]);
							format(mstr, sizeof(mstr), ""RED_E"*** {FFE4C4}You have been online for %d minutes.", pData[ii][pMinutes]);
						}
						InfoTD_MSG(ii, 10000, lstr);
						SendClientMessage(ii, 0xFFE4C4FF, mstr);
 						PlayerPlaySound(ii, 1138, 0.0, 0.0, 0.0);*/
						//SetPlayerTime(ii, hours, minutes);
						if(pData[ii][pPaycheck] >= 3600)
						{
							AccountData[ii][pBankMoney] += 100;
							new stringpaycek[100];
							format(stringpaycek, sizeof(stringpaycek), "Anda mendapatkan bansos $100 dari Pemerintah");
							TextDrawSetString(notifTD[1], stringpaycek);
							TextDrawShowForPlayer(ii, notifTD[0]);
							TextDrawShowForPlayer(ii, notifTD[1]);
							timernotif[ii] = 10;
							PlayerPlaySound(ii, 1139, 0.0, 0.0, 0.0);
						}
					}
					case 60:
					{
						if(pData[ii][pPaycheck] >= 3600)
						{
							AccountData[ii][pBankMoney] += 100;
							new stringpaycek[100];
							format(stringpaycek, sizeof(stringpaycek), "Anda mendapatkan bansos $100 dari Pemerintah");
							TextDrawSetString(notifTD[1], stringpaycek);
							TextDrawShowForPlayer(ii, notifTD[0]);
							TextDrawShowForPlayer(ii, notifTD[1]);
							timernotif[ii] = 10;
							PlayerPlaySound(ii, 1139, 0.0, 0.0, 0.0);
						}
						
						pData[ii][pHours] ++;
						pData[ii][pLevelUp] ++;
						pData[ii][pMinutes] = 0;
						UpdatePlayerData(ii);
			            
						/*PlayerPlaySound(ii, 1139, 0.0, 0.0, 0.0);

						if(pData[ii][pHours] != 1)
						{
							format(lstr, sizeof(lstr), "~y~You have been online for ~r~~h~%d~y~ hours.", pData[ii][pHours]);
							format(mstr, sizeof(mstr), ""RED_E"*** {FFE4C4}You have been online for %d hours.", pData[ii][pHours]);
						}
						else
						{
						    format(lstr, sizeof(lstr), "~y~You have been online for ~r~~h~one~y~ hour.");
						    format(mstr, sizeof(mstr), ""RED_E"*** {FFE4C4}You have been online for an hour.");
						}
						InfoTD_MSG(ii, 10000, lstr);
						SendClientMessage(ii, 0xFFE4C4FF, mstr);*/
						if(pData[ii][pLevelUp] >= scoremath)
						{
							new mstr[128];
							pData[ii][pLevelUp]= 0;
							pData[ii][pLevel] ++;
							SetPlayerScore(ii, pData[ii][pLevel]);
							format(mstr,sizeof(mstr),"~g~New level unlocked~n~~w~Now you're level ~r~%d", pData[ii][pLevel]);
							GameTextForPlayer(ii, mstr, 6000, 1);
						}
					}
				}
				if(pData[ii][pCurrMinutes] == 60)
				{
				    pData[ii][pCurrMinutes] = 0;
				    pData[ii][pCurrHours] ++;
				}
			}
   		}
		
		//VIP Expired Checking
		if(pData[ii][pVip] > 0)
		{
			if(pData[ii][pVipTime] != 0 && pData[ii][pVipTime] <= gettime())
			{
				Info(ii, "Maaf, Level VIP player anda sudah habis! sekarang anda adalah player biasa!");
				pData[ii][pVip] = 0;
				pData[ii][pVipTime] = 0;
			}
		}
		//ID Card Expired Checking
		if(pData[ii][pIDCard] > 0)
		{
			if(pData[ii][pIDCardTime] != 0 && pData[ii][pIDCardTime] <= gettime())
			{
				Info(ii, "Masa berlaku ID Card anda telah habis, silahkan perpanjang kembali!");
				pData[ii][pIDCard] = 0;
				pData[ii][pIDCardTime] = 0;
			}
		}
		if(pData[ii][pDriveLic] > 0)
		{
			if(pData[ii][pDriveLicTime] != 0 && pData[ii][pDriveLicTime] <= gettime())
			{
				Info(ii, "Masa berlaku Driving anda telah habis, silahkan perpanjang kembali!");
				pData[ii][pDriveLic] = 0;
				pData[ii][pDriveLicTime] = 0;
			}
		}
		//Player JobTime Delay
		if(pData[ii][pJobTime] > 0)
		{
			pData[ii][pJobTime]--;
		}
		if(pData[ii][pSideJobTime] > 0)
		{
			pData[ii][pSideJobTime]--;
		}
		//Warn Player Check
		if(pData[ii][pWarn] >= 10)
		{
			new ban_time = 0, query[512], PlayerIP[16], giveplayer[24];
			GetPlayerIp(ii, PlayerIP, sizeof(PlayerIP));
			GetPlayerName(ii, giveplayer, sizeof(giveplayer));
			pData[ii][pWarn] = 0;
			SetPlayerPosition(ii, 227.46, 110.0, 999.02, 360.0000, 10);
			BanPlayerMSG(ii, ii, "10 Total Warning", true);
			SendClientMessageToAllEx(COLOR_RED, "Server: "GREY2_E"Player %s(%d) telah otomasti dibanned permanent dari server. [Reason: 10 Total Warning]", giveplayer, ii);
			
			mysql_format(g_SQL, query, sizeof(query), "INSERT INTO banneds(name, ip, admin, reason, ban_date, ban_expire) VALUES ('%s', '%s', 'Server Ban', '10 Total Warning', %i, %d)", giveplayer, PlayerIP, gettime(), ban_time);
			mysql_tquery(g_SQL, query);
			KickEx(ii);
		}
		//Jail Player
		if(pData[ii][pJail] > 0)
		{
			pData[ii][pJail]--;
			new mstr[128];
			format(mstr, sizeof(mstr), "~b~~h~You will be released in ~w~%d ~b~~h~seconds.", pData[ii][pJail]);
			InfoTD_MSG(ii, 1000, mstr);
		    if(pData[ii][pJail] == 0)
		    {
		    	pData[ii][pJail] = 0;
				//SpawnPlayer(ii);
				SetPlayerPositionEx(ii, 1482.0356,-1724.5726,13.5469,750, 2000);
				SetPlayerInterior(ii, 0);
				SetPlayerVirtualWorld(ii, 0);
				SetPlayerSpecialAction(ii, SPECIAL_ACTION_NONE);
		    	Info(ii, "You have been un-jailed by the server. (times up)");
			}
		}
		//Arreset Player
		if(pData[ii][pArrestTime] > 0)
		{
			pData[ii][pArrestTime]--;
			new mstr[128];
			format(mstr, sizeof(mstr), "~b~~h~You will be released in ~w~%d ~b~~h~seconds.", pData[ii][pArrestTime]);
			InfoTD_MSG(ii, 1000, mstr);
		    if(pData[ii][pArrestTime] <= 0)
		    {
				pData[ii][pArrest] = 0;
		    	pData[ii][pArrestTime] = 0;
				//SpawnPlayer(ii);
				SetPlayerPositionEx(ii, 1526.69, -1678.05, 5.89, 267.76, 2000);
				SetPlayerInterior(ii, 0);
				SetPlayerVirtualWorld(ii, 0);
				SetPlayerSpecialAction(ii, SPECIAL_ACTION_NONE);
		    	Info(ii, "You have been auto release. (times up)");
			}
		}
	}
	return 1;
}

//----------[ Other Function ]-----------

function SetPlayerToUnfreeze(playerid, Float:x, Float:y, Float:z, Float:a)
{
    if(!IsPlayerInRangeOfPoint(playerid, 15.0, x, y, z))
        return 0;

    pData[playerid][pFreeze] = 0;
    SetPlayerPos(playerid, x, y, z);
	SetPlayerFacingAngle(playerid, a);
    TogglePlayerControllable(playerid, 1);
    return 1;
}

function KickTimer(playerid)
{
	KickEx(playerid);
	return 1;
}

IsValidPassword(const name[])
{
	new len = strlen(name);

	for(new ch = 0; ch != len; ch++)
	{
		switch(name[ch])
		{
			case 'A' .. 'Z', 'a' .. 'z', '0' .. '9', ']', '[', '(', ')', '_', '.', '@', '#': continue;
			default: return false;
		}
	}
	return true;
}