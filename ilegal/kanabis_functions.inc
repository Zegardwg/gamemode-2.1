#include <YSI\y_hooks>

new pTakingKokainTimer[MAX_PLAYERS] = {-1, ...};
new kokainarea;
enum E_KOKAINSTUFF
{
    STREAMER_TAG_OBJECT:KokainObject,
    STREAMER_TAG_AREA:KokainTakeArea,

    ActivityTime
}
new PlayerKokainVars[MAX_PLAYERS][E_KOKAINSTUFF];
new proseskoka[3], prosespaket[3];
new Float: KokainSpawn[][6] = {
    {-2788.179443, -1388.278808, 134.485534, 0.0, 0.0, 0.0},
    {-2783.331298, -1384.606079, 134.366729, 0.0, 0.0, 0.0},
    {-2791.131347, -1386.604980, 134.269531, 0.0, 0.0, 0.0},
    {-2790.845703, -1394.098022, 134.831024, 0.0, 0.0, 0.0},
    {-2796.812500, -1398.836669, 134.967498, 0.0, 0.0, 0.0},
    {-2793.698242, -1403.845336, 135.425445, 0.0, 0.0, 0.0},
    {-2787.489501, -1404.682250, 135.629104, 0.0, 0.0, 0.0},
    {-2777.716552, -1405.127319, 135.572769, 0.0, 0.0, 0.0},
    {-2772.053222, -1399.369995, 135.572387, 0.0, 0.0, 0.0},
    { 2768.253173, -1392.413940, 135.159759, 0.0, 0.0, 0.0}
};

stock LoadAreaKokain()
{
    //kanabis
    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses kanabis", -1, -2157.132080, -247.075683, 36.515625, 10.0);
    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses kanabis", -1, -2160.771240, -247.075622, 36.515625, 10.0);
    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses kanabis", -1, -2164.087646, -247.074325, 36.515625, 10.0);
    prosespaket[0] = CreateDynamicSphere(-2157.132080, -247.075683, 36.515625, 1.0);
    prosespaket[1] = CreateDynamicSphere(-2160.771240, -247.075622, 36.515625, 1.0); 
    prosespaket[2] = CreateDynamicSphere(-2164.087646, -247.074325, 36.515625, 1.0);    

    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses daun kanabis", -1, -2155.412841, -264.502716, 36.515625, 10.0);
    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses daun kanabis", -1, -2158.872070, -264.501434, 36.515625, 10.0);
    CreateDynamic3DTextLabel("{FFFFFF}Tekan "LG_E"[Y] {FFFFFF}untuk memproses daun kanabis", -1, -2162.326171, -264.502655, 36.515625, 10.0);
    proseskoka[0] = CreateDynamicSphere(-2155.412841, -264.502716, 36.515625, 1.0);
    proseskoka[1] = CreateDynamicSphere(-2158.872070, -264.501434, 36.515625, 1.0); 
    proseskoka[2] = CreateDynamicSphere(-2162.326171, -264.502655, 36.515625, 1.0);         
    kokainarea = CreateDynamicSphere(-2783.362060, -1392.033691, 135.913467, 20.0);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == kokainarea)
    {
        new rand = random(sizeof(KokainSpawn));
        if(DestroyPlayerObject(playerid, PlayerKokainVars[playerid][KokainObject]))
            PlayerKokainVars[playerid][KokainObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
        if(DestroyDynamicArea(PlayerKokainVars[playerid][KokainTakeArea]))
            PlayerKokainVars[playerid][KokainTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;  

        PlayerKokainVars[playerid][KokainObject] = CreatePlayerObject(playerid, 19473, KokainSpawn[rand][0], KokainSpawn[rand][1], KokainSpawn[rand][2], KokainSpawn[rand][3], KokainSpawn[rand][4], KokainSpawn[rand][5], 300.00);           
        PlayerKokainVars[playerid][KokainTakeArea] = CreateDynamicSphere(KokainSpawn[rand][0], KokainSpawn[rand][1], KokainSpawn[rand][2], 1.5);
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == kokainarea)
    {
        KillTimer(pTakingKokainTimer[playerid]);
        pTakingKokainTimer[playerid] = 1;

        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        if(DestroyDynamicObject(PlayerKokainVars[playerid][KokainObject]))
            PlayerKokainVars[playerid][KokainObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
        if(DestroyDynamicObject(PlayerKokainVars[playerid][KokainTakeArea]))
            PlayerKokainVars[playerid][KokainTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;   
    }
    return 1;
}

forward TakeKokain(playerid);
public TakeKokain(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTakingKokainTimer[playerid]);
        return 0;
    }    

    if(!IsValidDynamicArea(PlayerKokainVars[playerid][KokainTakeArea]))
    {
        KillTimer(pTakingKokainTimer[playerid]);
        pTakingKokainTimer[playerid] = 1;

        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        if(DestroyPlayerObject(playerid, PlayerKokainVars[playerid][KokainObject]))
        if(DestroyDynamicArea(PlayerKokainVars[playerid][KokainTakeArea]))
            PlayerKokainVars[playerid][KokainTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;                 
        return 0;
    }
    if(PlayerKokainVars[playerid][ActivityTime] == 45)
    {
        new rand = random(sizeof(KokainSpawn));
        KillTimer(pTakingKokainTimer[playerid]);
        pTakingKokainTimer[playerid] = 1;
        PlayerKokainVars[playerid][ActivityTime] = 0;

        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);                

        if(DestroyPlayerObject(playerid, PlayerKokainVars[playerid][KokainObject]))
        if(DestroyDynamicArea(PlayerKokainVars[playerid][KokainTakeArea]))
            PlayerKokainVars[playerid][KokainTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;  

        PlayerKokainVars[playerid][KokainObject] = CreatePlayerObject(playerid, 19473, KokainSpawn[rand][0], KokainSpawn[rand][1], KokainSpawn[rand][2], KokainSpawn[rand][3], KokainSpawn[rand][4], KokainSpawn[rand][5], 300.00);           
        PlayerKokainVars[playerid][KokainTakeArea] = CreateDynamicSphere(KokainSpawn[rand][0], KokainSpawn[rand][1], KokainSpawn[rand][2], 1.5);                   

        Inventory_Add(playerid, "Daun Kanabis", 19473, 1);   
    }
    else
    {
        PlayerKokainVars[playerid][ActivityTime] += 15;
    }    
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{
		if(IsPlayerInDynamicArea(playerid, prosespaket[2]))
		{
			if(Inventory_Count(playerid, "Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES KANABIS", 12);
			SetTimerEx("prosespakett", 12000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	      
		}        
		if(IsPlayerInDynamicArea(playerid, prosespaket[1]))
		{
			if(Inventory_Count(playerid, "Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES KANABIS", 12);
			SetTimerEx("prosespakett", 12000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	      
		}        
		if(IsPlayerInDynamicArea(playerid, prosespaket[0]))
		{
			if(Inventory_Count(playerid, "Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES KANABIS", 12);
			SetTimerEx("prosespakett", 12000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	      
		}

		if(IsPlayerInDynamicArea(playerid, proseskoka[2]))
		{
			if(Inventory_Count(playerid, "Daun Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Daun Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES DAUN KANABIS", 10);
			SetTimerEx("proseskokaa", 10000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	      
		}		
		if(IsPlayerInDynamicArea(playerid, proseskoka[1]))
		{
			if(Inventory_Count(playerid, "Daun Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Daun Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES DAUN KANABIS", 10);
			SetTimerEx("proseskokaa", 10000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	      
		}		
		if(IsPlayerInDynamicArea(playerid, proseskoka[0]))
		{
			if(Inventory_Count(playerid, "Daun Kanabis") < 1)
				return ErrorMsg(playerid, "Kamu tidak mempunyai Daun Kanabis");

			if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
			ShowProgressbar(playerid, "MEMPROSES DAUN KANABIS", 10);
			SetTimerEx("proseskokaa", 10000, 0, "i", playerid);
			ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);	     
		}        
        if(IsPlayerInDynamicArea(playerid, PlayerKokainVars[playerid][KokainTakeArea]))
        {            
            if(pData[playerid][pProgress] == 1) return Error(playerid, "Anda masih dalam activity progress");
            pTakingKokainTimer[playerid] = SetTimerEx("TakeKokain", 1000, true, "i", playerid);
            ShowProgressbar(playerid, "MENGAMBIL KANABIS", 4);
            ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 1, 0, 0, 0, 0, 1);
        }
    }    
    return 1;
}

hook OnGameModeInit()
{
    LoadAreaKokain();
    return 1;
}

FUNC::prosespakett(playerid)
{
	Inventory_Remove(playerid, "Kanabis", 1);
	Inventory_Add(playerid, "Paket Kanabis", 1575, 1);
    ClearAnimations(playerid, 1);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

FUNC::proseskokaa(playerid)
{
	Inventory_Remove(playerid, "Daun Kanabis", 1);
	Inventory_Add(playerid, "Kanabis", 13637, 1);
    ClearAnimations(playerid, 1);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    KokainClear(playerid);
    return 1;
}

stock KokainClear(playerid)
{
    KillTimer(pTakingKokainTimer[playerid]);
    pTakingKokainTimer[playerid] = 0;

    if(DestroyPlayerObject(playerid, PlayerKokainVars[playerid][KokainObject]))
    if(DestroyDynamicArea(PlayerKokainVars[playerid][KokainTakeArea]))
        PlayerKokainVars[playerid][KokainTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;        
    return 1;
}