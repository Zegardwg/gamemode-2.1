#include <YSI\y_hooks>

enum E_DOSTUFF
{
    DoAlready,
    STREAMER_TAG_3D_TEXT_LABEL:DoLabel
}
new PlayerDoVars[MAX_PLAYERS][E_DOSTUFF];

CMD:do(playerid, params[])
{
	new text[200];
	if(sscanf(params, "s[200]", text)) return Usage(playerid, "/do [text]");    
    if(PlayerDoVars[playerid][DoAlready])
        return Error(playerid, "Harap tunggu sebentar");

    new str[200];
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    format(str, sizeof(str), "{004BFF}%s", text);
    PlayerDoVars[playerid][DoAlready] = 1;
    PlayerDoVars[playerid][DoLabel] = CreateDynamic3DTextLabel(str, -1, x, y, z-2, 15.0, .attachedplayer = playerid);
    SetTimerEx("hapusdolabel", 3000, 0, "i", playerid);
    return 1;
}

FUNC::hapusdolabel(playerid)
{
    if(IsValidDynamic3DTextLabel(PlayerDoVars[playerid][DoLabel]))
        DestroyDynamic3DTextLabel(PlayerDoVars[playerid][DoLabel]);
    PlayerDoVars[playerid][DoAlready] = 0;
    return 1;
}