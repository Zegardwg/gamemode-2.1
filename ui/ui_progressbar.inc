#include <YSI\y_hooks>
new PlayerText:PROGRESSBAR[MAX_PLAYERS][4];
new LoadingPlayerBar[MAX_PLAYERS];
new TimerLoading[MAX_PLAYERS];
new ProgressTimer[MAX_PLAYERS][128];

HideProgressBar(playerid)
{
	for(new idx; idx < 4; idx++) PlayerTextDrawHide(playerid, PROGRESSBAR[playerid][idx]);
	return 1;
}
/* Create TD */
CreateProgress(playerid)
{
	PROGRESSBAR[playerid][0] = CreatePTextdraw(playerid, 271.000, -29.000, "New textdraw");
	PlayerTextDrawLetterSize(playerid, PROGRESSBAR[playerid][0], 0.300, 1.500);
	PlayerTextDrawAlignment(playerid, PROGRESSBAR[playerid][0], 1);
	PlayerTextDrawColor(playerid, PROGRESSBAR[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, PROGRESSBAR[playerid][0], 1);
	PlayerTextDrawSetOutline(playerid, PROGRESSBAR[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, PROGRESSBAR[playerid][0], 150);
	PlayerTextDrawFont(playerid, PROGRESSBAR[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PROGRESSBAR[playerid][0], 1);

	PROGRESSBAR[playerid][1] = CreatePTextdraw(playerid, 265.000, 409.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, PROGRESSBAR[playerid][1], 105.000, 25.000);
	PlayerTextDrawAlignment(playerid, PROGRESSBAR[playerid][1], 1);
	PlayerTextDrawColor(playerid, PROGRESSBAR[playerid][1], 160);
	PlayerTextDrawSetShadow(playerid, PROGRESSBAR[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, PROGRESSBAR[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PROGRESSBAR[playerid][1], 255);
	PlayerTextDrawFont(playerid, PROGRESSBAR[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, PROGRESSBAR[playerid][1], 1);

	PROGRESSBAR[playerid][2] = CreatePTextdraw(playerid, 265.000, 409.000, "LD_BUM:blkdot");
	PlayerTextDrawTextSize(playerid, PROGRESSBAR[playerid][2], 105.000, 25.000);
	PlayerTextDrawAlignment(playerid, PROGRESSBAR[playerid][2], 1);
	PlayerTextDrawColor(playerid, PROGRESSBAR[playerid][2], -1140842753);
	PlayerTextDrawSetShadow(playerid, PROGRESSBAR[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, PROGRESSBAR[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, PROGRESSBAR[playerid][2], 255);
	PlayerTextDrawFont(playerid, PROGRESSBAR[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, PROGRESSBAR[playerid][2], 1);

	PROGRESSBAR[playerid][3] = CreatePTextdraw(playerid, 316.000, 416.000, "MAKAN");
	PlayerTextDrawLetterSize(playerid, PROGRESSBAR[playerid][3], 0.230, 1.099);
	PlayerTextDrawAlignment(playerid, PROGRESSBAR[playerid][3], 2);
	PlayerTextDrawColor(playerid, PROGRESSBAR[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, PROGRESSBAR[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, PROGRESSBAR[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, PROGRESSBAR[playerid][3], 150);
	PlayerTextDrawFont(playerid, PROGRESSBAR[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, PROGRESSBAR[playerid][3], 1);
	return 1;
}

hook OnPlayerConnect(playerid)
{
    CreateProgress(playerid);
    return 1;
}
/* Func */
ShowProgressbar(playerid, text[] = "", Times)
{
	if(pData[playerid][pProgress] > 0) return 1;
	LoadingPlayerBar[playerid] = 0;
	pData[playerid][pProgress] = 1;
	new Timer = Times*1000/100;
	PlayerTextDrawSetString(playerid, PROGRESSBAR[playerid][3], text);
	for(new idx; idx < 4; idx++) PlayerTextDrawShow(playerid, PROGRESSBAR[playerid][idx]);
	TogglePlayerControllable(playerid, 0);
	TimerLoading[playerid] = SetTimerEx("UpdtLoading", Timer, true, "d", playerid);
	return 1;
}

stock UpdateLoading(playerid)
{
	new Float:Value = LoadingPlayerBar[playerid]*105.0/100;
	PlayerTextDrawTextSize(playerid, PROGRESSBAR[playerid][2], Value, 25.0);
	PlayerTextDrawShow(playerid, PROGRESSBAR[playerid][2]);
	return 1;
}

forward UpdtLoading(playerid);
public UpdtLoading(playerid)
{
	LoadingPlayerBar[playerid] += 1;
	UpdateLoading(playerid);
	if(LoadingPlayerBar[playerid] >= 100)
	{
		KillTimer(TimerLoading[playerid]);
		LoadingPlayerBar[playerid] = 0;
		pData[playerid][pProgress] = 0;
		HideProgressBar(playerid);
		SetTimerEx(ProgressTimer[playerid], 500, false, "d", playerid);
		TogglePlayerControllable(playerid, 1);
		for(new i=0; i<MAX_PLAYER_ATTACHED_OBJECTS; i++)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, i)) RemovePlayerAttachedObject(playerid, i);
		}
	}
	return 1;
}
CMD:testprog(playerid, params[])
{
   	if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda sedang melakukan activity progress");
	ShowProgressbar(playerid, "Test aja", 3);
	return 1;
}
