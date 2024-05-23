#include <YSI\y_hooks>

new PlayerText: DMADM[MAX_PLAYERS][5];

stock LoadDmTD(playerid)
{
    DMADM[playerid][0] = CreatePlayerTextDraw(playerid, 261.000, 9.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DMADM[playerid][0], 128.000, 43.000);
    PlayerTextDrawAlignment(playerid, DMADM[playerid][0], 1);
    PlayerTextDrawColor(playerid, DMADM[playerid][0], 7650303);
    PlayerTextDrawSetShadow(playerid, DMADM[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, DMADM[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, DMADM[playerid][0], 255);
    PlayerTextDrawFont(playerid, DMADM[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, DMADM[playerid][0], 1);

    DMADM[playerid][1] = CreatePlayerTextDraw(playerid, 266.000, 20.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DMADM[playerid][1], 15.000, 19.000);
    PlayerTextDrawAlignment(playerid, DMADM[playerid][1], 1);
    PlayerTextDrawColor(playerid, DMADM[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, DMADM[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, DMADM[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, DMADM[playerid][1], 255);
    PlayerTextDrawFont(playerid, DMADM[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, DMADM[playerid][1], 1);

    DMADM[playerid][2] = CreatePlayerTextDraw(playerid, 272.000, 23.000, "i");
    PlayerTextDrawLetterSize(playerid, DMADM[playerid][2], 0.280, 1.299);
    PlayerTextDrawAlignment(playerid, DMADM[playerid][2], 1);
    PlayerTextDrawColor(playerid, DMADM[playerid][2], 7650303);
    PlayerTextDrawSetShadow(playerid, DMADM[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, DMADM[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, DMADM[playerid][2], 150);
    PlayerTextDrawFont(playerid, DMADM[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, DMADM[playerid][2], 1);

    DMADM[playerid][3] = CreatePlayerTextDraw(playerid, 282.000, 15.000, "DM form admin eternals:");
    PlayerTextDrawLetterSize(playerid, DMADM[playerid][3], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, DMADM[playerid][3], 1);
    PlayerTextDrawColor(playerid, DMADM[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, DMADM[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, DMADM[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, DMADM[playerid][3], 150);
    PlayerTextDrawFont(playerid, DMADM[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, DMADM[playerid][3], 1);

    DMADM[playerid][4] = CreatePlayerTextDraw(playerid, 282.000, 26.000, "kontol");
    PlayerTextDrawLetterSize(playerid, DMADM[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, DMADM[playerid][4], 384.000, 0.000);
    PlayerTextDrawAlignment(playerid, DMADM[playerid][4], 1);
    PlayerTextDrawColor(playerid, DMADM[playerid][4], 255);
    PlayerTextDrawUseBox(playerid, DMADM[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, DMADM[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, DMADM[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, DMADM[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, DMADM[playerid][4], 150);
    PlayerTextDrawFont(playerid, DMADM[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, DMADM[playerid][4], 1);  
    return 1;
}

hook OnPlayerConnect(playerid)
{
    LoadDmTD(playerid);
    return 1;
}

CMD:adm(playerid, params[])
{
	static
		userid,
	    teks[100];

	if (AccountData[playerid][pAdmin] < 3)
	    return SendErrorMessage(playerid, "You don't have permission to use this command.");

	if (sscanf(params, "us[100]", userid, teks))
		return SyntaxMsg(playerid, "/adm [playerid/PartOfName] [text]");

	if (userid == INVALID_PLAYER_ID)
	    return SendErrorMessage(playerid, "You have specified an invalid player.");

    forex(i, 5)
    {
        PlayerTextDrawShow(userid, DMADM[userid][i]);
        PlayerTextDrawSetString(userid, DMADM[userid][3], sprintf("DM from admin %s:", AccountData[playerid][pUCP]));
        PlayerTextDrawSetString(userid, DMADM[userid][4], sprintf("%s", teks));
    }
    SetTimerEx("hideadm", 5000, 0, "i", userid);
    return 1;
}

function hideadm(playerid)
{
    forex(i, 5)
    {
        PlayerTextDrawHide(playerid, DMADM[playerid][i]);
    }    
    return 1;
}