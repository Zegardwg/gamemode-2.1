#include <YSI\y_hooks>

enum E_MESTUFF
{
    MeAlready,
    STREAMER_TAG_3D_TEXT_LABEL:MeLabel
}
new PlayerMeVars[MAX_PLAYERS][E_MESTUFF];

CMD:me(playerid, params[])
{
	new text[200];
	if(sscanf(params, "s[200]", text)) return Usage(playerid, "/me [text]");    
    if(PlayerMeVars[playerid][MeAlready])
        return Error(playerid, "Harap tunggu sebentar");

    new str[200];
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    format(str, sizeof(str), "{FF0000}%s", text);
    PlayerMeVars[playerid][MeAlready] = 1;
    PlayerMeVars[playerid][MeLabel] = CreateDynamic3DTextLabel(str, -1, x, y, z-1, 15.0, .attachedplayer = playerid);
    SetTimerEx("hapusmelabel", 3000, 0, "i", playerid);
    return 1;
}

FUNC::hapusmelabel(playerid)
{
    if(IsValidDynamic3DTextLabel(PlayerMeVars[playerid][MeLabel]))
        DestroyDynamic3DTextLabel(PlayerMeVars[playerid][MeLabel]);
    PlayerMeVars[playerid][MeAlready] = 0;
    return 1;
}