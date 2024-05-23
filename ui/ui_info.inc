#include <YSI\y_hooks>
new PlayerText: UIINFO[MAX_PLAYERS][4];

stock LoadInfoTD(playerid)
{
	UIINFO[playerid][0] = CreatePlayerTextDraw(playerid, 3.000, 230.000, "ld_bum:blkdot");
	PlayerTextDrawLetterSize(playerid, UIINFO[playerid][0], 0.600, 2.000);
	PlayerTextDrawTextSize(playerid, UIINFO[playerid][0], 2.000, 18.000);
	PlayerTextDrawAlignment(playerid, UIINFO[playerid][0], 1);
	PlayerTextDrawColor(playerid, UIINFO[playerid][0], 366276095);
	PlayerTextDrawUseBox(playerid, UIINFO[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, UIINFO[playerid][0], 50);
	PlayerTextDrawSetShadow(playerid, UIINFO[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, UIINFO[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, UIINFO[playerid][0], 255);
	PlayerTextDrawFont(playerid, UIINFO[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, UIINFO[playerid][0], 1);

	UIINFO[playerid][1] = CreatePlayerTextDraw(playerid, 5.000, 230.000, "ld_bum:blkdot");
	PlayerTextDrawLetterSize(playerid, UIINFO[playerid][1], 0.600, 2.000);
	PlayerTextDrawTextSize(playerid, UIINFO[playerid][1], 81.000, 18.000);
	PlayerTextDrawAlignment(playerid, UIINFO[playerid][1], 1);
	PlayerTextDrawColor(playerid, UIINFO[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, UIINFO[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, UIINFO[playerid][1], 50);
	PlayerTextDrawSetShadow(playerid, UIINFO[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, UIINFO[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, UIINFO[playerid][1], 255);
	PlayerTextDrawFont(playerid, UIINFO[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, UIINFO[playerid][1], 1);

	UIINFO[playerid][2] = CreatePlayerTextDraw(playerid, 8.000, 234.000, "ld_beat:chit");
	PlayerTextDrawLetterSize(playerid, UIINFO[playerid][2], 0.600, 2.000);
	PlayerTextDrawTextSize(playerid, UIINFO[playerid][2], 7.000, 9.500);
	PlayerTextDrawAlignment(playerid, UIINFO[playerid][2], 1);
	PlayerTextDrawColor(playerid, UIINFO[playerid][2], 366276095);
	PlayerTextDrawUseBox(playerid, UIINFO[playerid][2], 1);
	PlayerTextDrawBoxColor(playerid, UIINFO[playerid][2], 50);
	PlayerTextDrawSetShadow(playerid, UIINFO[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, UIINFO[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, UIINFO[playerid][2], 255);
	PlayerTextDrawFont(playerid, UIINFO[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, UIINFO[playerid][2], 1);

	UIINFO[playerid][3] = CreatePlayerTextDraw(playerid, 17.000, 234.000, "[Y]Access ATM");
	PlayerTextDrawLetterSize(playerid, UIINFO[playerid][3], 0.137, 1.000);
	PlayerTextDrawTextSize(playerid, UIINFO[playerid][3], 400.000, 97.000);
	PlayerTextDrawAlignment(playerid, UIINFO[playerid][3], 1);
	PlayerTextDrawColor(playerid, UIINFO[playerid][3], 255);
	PlayerTextDrawSetShadow(playerid, UIINFO[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, UIINFO[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, UIINFO[playerid][3], 255);
	PlayerTextDrawFont(playerid, UIINFO[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, UIINFO[playerid][3], 1);
}

hook OnPlayerConnect(playerid)
{
	LoadInfoTD(playerid);
	return 1;
}

stock ShowInfo(playerid, text[])
{
	PlayerTextDrawShow(playerid, UIINFO[playerid][0]);
	PlayerTextDrawShow(playerid, UIINFO[playerid][1]);
	PlayerTextDrawShow(playerid, UIINFO[playerid][2]);
	PlayerTextDrawShow(playerid, UIINFO[playerid][3]);
	PlayerTextDrawSetString(playerid, UIINFO[playerid][3], sprintf("[Y] - %s", text));
	PlayerPlaySound(playerid, 5201, 0.0, 0.0, 0.0);	
	return 1;
}

stock HideInfo(playerid)
{
	PlayerTextDrawHide(playerid, UIINFO[playerid][3]);
	PlayerTextDrawHide(playerid, UIINFO[playerid][2]);
	PlayerTextDrawHide(playerid, UIINFO[playerid][1]);
	PlayerTextDrawHide(playerid, UIINFO[playerid][0]);
	return 1;
}