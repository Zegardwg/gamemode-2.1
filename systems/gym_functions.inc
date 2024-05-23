#include <YSI\y_hooks>
new PlayerText: GYMTEXT[MAX_PLAYERS][1];
enum  e_gym_data
{ 
	barbel,
	barbelobject[2],
	Text3D:areagym[3],
	gymPersen
};
new GymData[MAX_PLAYERS][e_gym_data];

new buysupple;

stock Load3DTextLabelGym()
{
    buysupple = CreateDynamicSphere(670.761474, -1861.124511, 5.460937, 1.0);
    CreateActor(45, 670.761474, -1861.124511, 5.460937, 359.146362);
	CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}Untuk Memulai GYM", -1, 659.9156, -1869.5369, 5.5537, 10.0);
	CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}Untuk Memulai GYM", -1, 654.2678, -1869.5612, 5.5537, 10.0);
	CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}Untuk Memulai GYM", -1, 651.7175, -1864.0197, 5.4609, 10.0);
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == buysupple)
    {
        ShowInfo(playerid, "Membeli Supplements");
    }
    return 1;
}

hook OnGameModeInit()
{
    Load3DTextLabelGym();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if ((newkeys & KEY_YES))
    {
        if(IsPlayerInDynamicArea(playerid, buysupple))
        {
            Dialog_Show(playerid, DIALOG_BUYSUPPLE, DIALOG_STYLE_TABLIST_HEADERS, "Gym Supplements",
            "Name\t-\tPrice\nCreatine\t:\t"LG_E"$30\nProtein\t:\t"LG_E"$50", "Pilih", "Batal");
        }        
		if (InAreaYoga(playerid) >= 0)
		{
			if (GetPVarInt(playerid, "gymdelay") >  gettime()) return Y_HOOKS_CONTINUE_RETURN_0;

			SetTimerEx("ClearAnimation", 12000, false, "i", playerid);
			TogglePlayerControllable(playerid, 0);
            ApplyAnimation(playerid,"PARK","Tai_Chi_Loop", 4.1, 1, 1, 1, 1, 0, 1);
			SetPVarInt(playerid, "gymdelay", gettime() + 30);
		}        
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 651.7175,-1864.0197,5.4609))
		{
			if (GetPVarInt(playerid, "gymdelay") >  gettime()) return Y_HOOKS_CONTINUE_RETURN_0;
            if(GymData[playerid][barbel] == 9)
			{
                SetTimerEx("ResetBarbel", 1000, false, "i", playerid);
			}

            ApplyAnimation(playerid, "Freeweights", "gym_free_A", 4.1, 0, 1, 1, 0, 0, 1);
            SetPlayerAttachedObject(playerid, 2, 2916, 6, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            SetPlayerAttachedObject(playerid, 9, 2916, 5, 0.0, 0.0, 0.0, 0.0, 80.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
 
			GymData[playerid][gymPersen] += 10;
            GymData[playerid][barbel] ++;
			new str[100];
			format(str, 100, "%d%%", GymData[playerid][gymPersen]);
			PlayerTextDrawSetString(playerid, GYMTEXT[playerid][0], str);
			PlayerTextDrawShow(playerid, GYMTEXT[playerid][0]);
			SetPVarInt(playerid, "gymdelay", gettime() + 5);
		}

    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    GYMTEXT[playerid][0] = CreatePTextdraw(playerid, 139.000, 414.000, "100#");
    PlayerTextDrawLetterSize(playerid, GYMTEXT[playerid][0], 0.389, 1.799);
    PlayerTextDrawAlignment(playerid, GYMTEXT[playerid][0], 2);
    PlayerTextDrawColor(playerid, GYMTEXT[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, GYMTEXT[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GYMTEXT[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, GYMTEXT[playerid][0], 150);
    PlayerTextDrawFont(playerid, GYMTEXT[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, GYMTEXT[playerid][0], 1);    
    return 1;
}

InAreaYoga(playerid)
{
	for(new i = 0; i < 3; i ++)
	{
	    if(IsPlayerInRangeOfPoint(playerid, 2.0, 659.9156, -1869.5369, 5.5537))
	    {
	        return i;
	    }
		if(IsPlayerInRangeOfPoint(playerid, 2.0, 654.2678, -1869.5612, 5.5537))
	    {
	        return i;
	    }
	}
	return Y_HOOKS_BREAK_RETURN_0;
}

function ClearAnimation(playerid)
{
    if(AccountData[playerid][UseCreatine])
    {
        AccountData[playerid][pBladder] -= RandomEx(10, 15);
        AccountData[playerid][UseCreatine] = 0;
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }
    else if(AccountData[playerid][UseProtein])
    {
        AccountData[playerid][pBladder] -= RandomEx(15, 20);
        AccountData[playerid][pHunger] += 20;
        AccountData[playerid][pEnergy] += 20;
        AccountData[playerid][UseProtein] = 0;
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }
    else 
    {
        AccountData[playerid][pBladder] -= RandomEx(1, 5);
        ClearAnimations(playerid);
        TogglePlayerControllable(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

function ResetBarbel(playerid)
{
    if(AccountData[playerid][UseCreatine])
    {
        AccountData[playerid][pBladder] -= RandomEx(10, 15);
        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 2)) RemovePlayerAttachedObject(playerid, 2);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
        GymData[playerid][barbel] = 0;
        GymData[playerid][gymPersen] = 0;
        AccountData[playerid][UseCreatine] = 0;
        PlayerTextDrawHide(playerid, GYMTEXT[playerid][0]);
    }
    else if(AccountData[playerid][UseProtein])
    {
        AccountData[playerid][pBladder] -= RandomEx(15, 20);
        AccountData[playerid][pHunger] += 20;
        AccountData[playerid][pEnergy] += 20;
        ClearAnimations(playerid, 1);
        AccountData[playerid][UseProtein] = 0;
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 2)) RemovePlayerAttachedObject(playerid, 2);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
        GymData[playerid][barbel] = 0;
        GymData[playerid][gymPersen] = 0;
        PlayerTextDrawHide(playerid, GYMTEXT[playerid][0]);
    }
    else 
    {
        AccountData[playerid][pBladder] -= RandomEx(1, 5);
        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 2)) RemovePlayerAttachedObject(playerid, 2);
        if(IsPlayerAttachedObjectSlotUsed(playerid, 9)) RemovePlayerAttachedObject(playerid, 9);
        GymData[playerid][barbel] = 0;
        GymData[playerid][gymPersen] = 0;
        PlayerTextDrawHide(playerid, GYMTEXT[playerid][0]);
    }    
    return Y_HOOKS_CONTINUE_RETURN_1;
}

Dialog:DIALOG_BUYSUPPLE(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                GiveMoney(playerid, -30);
                Inventory_Add(playerid, "Creatine", 1950, 1);
                
            }
            case 1:
            {
                GiveMoney(playerid, -50);
                Inventory_Add(playerid, "Protein", 1951, 1);                
            }            
        }
    }
    return 1;
}