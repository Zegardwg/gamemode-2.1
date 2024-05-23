#include <YSI\y_hooks>

//announcement system
new PlayerText: ANNOUNCEMENT[MAX_PLAYERS][7];

stock LoadAnnouncementTD(playerid)
{
    ANNOUNCEMENT[playerid][0] = CreatePTextdraw (playerid, 203.000, 7.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][0], 197.000, 48.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][0], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][0], -191362561);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][0], 255);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][0], 1);

    ANNOUNCEMENT[playerid][1] = CreatePTextdraw (playerid, 230.000, 15.000, "Server Announcement by Admin:");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][1], 0.230, 1.099);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][1], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][1], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][1], 1);

    ANNOUNCEMENT[playerid][2] = CreatePTextdraw (playerid, 230.000, 27.000, "Server Akan segera badai");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][2], 0.210, 1.099);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][2], 399.000, 0.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][2], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][2], 1);

    ANNOUNCEMENT[playerid][3] = CreatePTextdraw (playerid, 209.000, 11.000, "/");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][3], 0.659, 3.199);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][3], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][3], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][3], 1);

    ANNOUNCEMENT[playerid][4] = CreatePTextdraw (playerid, 216.000, 11.000, "\\");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][4], 0.659, 3.199);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][4], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][4], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][4], 1);

    ANNOUNCEMENT[playerid][5] = CreatePTextdraw (playerid, 209.000, 27.000, "-");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][5], 1.610, 1.599);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][5], 0.000, -62.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][5], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][5], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][5], 1);

    ANNOUNCEMENT[playerid][6] = CreatePTextdraw (playerid, 216.000, 22.000, "!");
    PlayerTextDrawLetterSize(playerid, ANNOUNCEMENT[playerid][6], 0.280, 1.399);
    PlayerTextDrawTextSize(playerid, ANNOUNCEMENT[playerid][6], 0.000, -62.000);
    PlayerTextDrawAlignment(playerid, ANNOUNCEMENT[playerid][6], 1);
    PlayerTextDrawColor(playerid, ANNOUNCEMENT[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ANNOUNCEMENT[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ANNOUNCEMENT[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ANNOUNCEMENT[playerid][6], 150);
    PlayerTextDrawFont(playerid, ANNOUNCEMENT[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, ANNOUNCEMENT[playerid][6], 1);    
}

hook OnPlayerConnect(playerid)
{
    LoadAnnouncementTD(playerid);
    return 1;
}

function hideann()
{
	foreach(new i : Player)
	{
		for(new  ii = 0; ii < 7; ii ++)
		{
			PlayerTextDrawHide(i, ANNOUNCEMENT[i][ii]);
		}
	}
	return 1;
}

CMD:ann(playerid, params[])
{
	if(pData[playerid][pAdmin] < 1)
		return PermissionError(playerid);

    new teks[250], str[128];
    if(sscanf(params, "s[250]", teks))
    {
        Usage(playerid, "/ann [teks]");
        return 1;
    }		
	format(str, 128, "%s", teks);
	for(new ii = 0; ii < 7; ii ++)
	{
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			PlayerTextDrawShow(i, ANNOUNCEMENT[i][ii]);
			PlayerTextDrawSetString(i, ANNOUNCEMENT[i][2], str);	
			SetTimer("hideann", 5000, 0);	
		}
	}		
	return 1;
}