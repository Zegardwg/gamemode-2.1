#include <YSI\y_hooks>

new pTakingChickenTimer[MAX_PLAYERS] = {-1, ...};
enum E_GLOBALBUTCHERSTUFF
{
    STREAMER_TAG_AREA:pointjob,
    STREAMER_TAG_AREA:potongayam[3],
    STREAMER_TAG_AREA:kemasayam[3]
}
new ButcherVars[E_GLOBALBUTCHERSTUFF];

enum E_BUTCHERSTUFF
{
    ChickenObject,
    STREAMER_TAG_AREA:ChickenTakeArea,
    STREAMER_TAG_AREA:ChickenTakejob,

    bool:DuringTakeChicken,
    TakeCountChicken,
    ActivityTime
}
new PlayerButcherVars[MAX_PLAYERS][E_BUTCHERSTUFF],
    Iterator:ButcherOnduty<MAX_PLAYERS>;

new Float: ChickenSpawn[][6] = {
    {1519.3685,23.9024,23.118568, 0.000000, 270.000000, 0.000000},
    {1522.2843,20.5854,23.118568, 0.000000, 270.000000, 0.000000},
    {1520.2584,17.5775,23.118568, 0.000000, 270.000000, 0.000000},
    {1515.2158,18.6767,23.118568, 0.000000, 270.000000, 0.000000},
    {1518.6177,13.1949,23.118568, 0.000000, 270.000000, 0.000000}  
};

stock LoadPointButcher()
{   
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Kemas Ayam", -1, 1922.354492, 159.760513, 37.217388, 10.0, 0, 0);	
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Kemas Ayam", -1, 1924.603881, 159.117767, 37.229881, 10.0, 0, 0);	
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Kemas Ayam", -1, 1926.637207, 158.530227, 37.241218, 10.0, 0, 0);	    
    ButcherVars[kemasayam][0] = CreateDynamicSphere(1922.354492, 159.760513, 37.217388, 1.2);
    ButcherVars[kemasayam][1] = CreateDynamicSphere(1924.603881, 159.117767, 37.229881, 1.2);
    ButcherVars[kemasayam][2] = CreateDynamicSphere(1926.637207, 158.530227, 37.241218, 1.2);

    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Memotong Ayam", -1, 1928.558715, 155.491210, 37.266738, 10.0, 0, 0);	
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Memotong Ayam", -1, 1931.046997, 154.773956, 37.281250, 10.0, 0, 0);	
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Memotong Ayam", -1, 1933.761474, 153.998474, 37.281250, 10.0, 0, 0);	
    ButcherVars[potongayam][0] = CreateDynamicSphere(1928.558715, 155.491210, 37.266738, 1.2);
    ButcherVars[potongayam][1] = CreateDynamicSphere(1931.046997, 154.773956, 37.281250, 1.2);
    ButcherVars[potongayam][2] = CreateDynamicSphere(1933.761474, 153.998474, 37.281250, 1.2);

    Create3DTextLabel(""LG_E"[Y]{FFFFFF} - Mulai Pekerjaan", -1, 1543.553222, 21.141000, 24.140625, 10.0, 0, 0);	
    ButcherVars[pointjob] = CreateDynamicSphere(1543.553222, 21.141000, 24.140625, 1.0);
}

hook OnGameModeInit()
{
    LoadPointButcher();
    return 1;
}

forward TakeChicken(playerid);
public TakeChicken(playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(pTakingChickenTimer[playerid]);
        return 0;
    }    

    if(!IsValidDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
    {
        KillTimer(pTakingChickenTimer[playerid]);
        pTakingChickenTimer[playerid] = 1;

        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);

        if(DestroyPlayerObject(playerid, PlayerButcherVars[playerid][ChickenObject]))
        if(DestroyDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
            PlayerButcherVars[playerid][ChickenTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;                 
        return 0;
    }
    if(PlayerButcherVars[playerid][ActivityTime] == 30)
    {
        new rand = random(sizeof(ChickenSpawn));
        KillTimer(pTakingChickenTimer[playerid]);
        pTakingChickenTimer[playerid] = 1;
        PlayerButcherVars[playerid][ActivityTime] = 0;

        ClearAnimations(playerid, 1);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);        

        if(DestroyPlayerObject(playerid, PlayerButcherVars[playerid][ChickenObject]))
        if(DestroyDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
            PlayerButcherVars[playerid][ChickenTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;           

        PlayerButcherVars[playerid][ChickenObject] = CreatePlayerObject(playerid, 19079, ChickenSpawn[rand][0], ChickenSpawn[rand][1], ChickenSpawn[rand][2], ChickenSpawn[rand][3], ChickenSpawn[rand][4], ChickenSpawn[rand][5], 300.00);                       
        PlayerButcherVars[playerid][ChickenTakeArea] = CreateDynamicSphere(ChickenSpawn[rand][0], ChickenSpawn[rand][1], ChickenSpawn[rand][2], 1.5);        

        Inventory_Add(playerid, "Ayam Hidup", 16776, 1);   
    }
    else
    {
        PlayerButcherVars[playerid][ActivityTime] += 10;
    }
    return 1;
}   

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{     
        if(IsPlayerInDynamicArea(playerid, ButcherVars[kemasayam][2]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Potong") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Potong (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "PACKING AYAM", 5);
            SetTimerEx("packingayam", 10000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);            
        }         
        if(IsPlayerInDynamicArea(playerid, ButcherVars[kemasayam][1]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Potong") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Potong (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "PACKING AYAM", 5);
            SetTimerEx("packingayam", 10000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);            
        }         
        if(IsPlayerInDynamicArea(playerid, ButcherVars[kemasayam][0]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Potong") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Potong (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "PACKING AYAM", 5);
            SetTimerEx("packingayam", 10000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);            
        }          
        if(IsPlayerInDynamicArea(playerid, ButcherVars[potongayam][2]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Hidup") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Hidup");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMOTONG AYAM", 5);
            SetTimerEx("potongayamm", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "KNIFE", "KILL_Knife_Player", 4.0, 1, 1, 1, 1, 1);
            SetPlayerAttachedObject(playerid,9,19583,6,0.079999,0.023000,0.038000,-109.299987,171.599990,0.000000,1.000000,1.000000,1.000000);       
        }           
        if(IsPlayerInDynamicArea(playerid, ButcherVars[potongayam][1]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Hidup") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Hidup");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMOTONG AYAM", 5);
            SetTimerEx("potongayamm", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "KNIFE", "KILL_Knife_Player", 4.0, 1, 1, 1, 1, 1);
            SetPlayerAttachedObject(playerid,9,19583,6,0.079999,0.023000,0.038000,-109.299987,171.599990,0.000000,1.000000,1.000000,1.000000);
        }           
        if(IsPlayerInDynamicArea(playerid, ButcherVars[potongayam][0]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(Inventory_Count(playerid, "Ayam Hidup") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Hidup");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMOTONG AYAM", 5);
            SetTimerEx("potongayamm", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "KNIFE", "KILL_Knife_Player", 4.0, 1, 1, 1, 1, 1);
            SetPlayerAttachedObject(playerid,9,19583,6,0.079999,0.023000,0.038000,-109.299987,171.599990,0.000000,1.000000,1.000000,1.000000);
        }        
        if(IsPlayerInDynamicArea(playerid, PlayerButcherVars[playerid][ChickenTakeArea]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            if(!PlayerButcherVars[playerid][DuringTakeChicken]) return ErrorMsg(playerid, "Kamu belum duty sebagai pemotong ayam");
            pTakingChickenTimer[playerid] = SetTimerEx("TakeChicken", 1000, true, "i", playerid);
            ShowProgressbar(playerid, "MENGAMBIL AYAM", 4);
            ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 1, 0, 0, 0, 0, 1);
        }             
        if(IsPlayerInDynamicArea(playerid, ButcherVars[pointjob]))
        {
            if(AccountData[playerid][PlayerJob] != 1) return ErrorMsg(playerid, "Anda bukan seorang Tukang Ayam!");
            Dialog_Show(playerid, DIALOG_BUTCHERJOB, DIALOG_STYLE_LIST, "{a8ecff}Konoha Roleplay{FFFFFF} - Tukang Ayam",
            "Mulai Pekerjaan\n"GREY_E"Selesaikan Pekerjaan", "Pilih", "Batal");
        }        
    }
    return 1;
}

Dialog:DIALOG_BUTCHERJOB(playerid, response, listitem, inputtext[])
{
    if(response)   
    {
        if(listitem == 0)
        {
            if(PlayerButcherVars[playerid][DuringTakeChicken])
                return ErrorMsg(playerid, "Anda sudah duty pemotong ayam sebelumnya");

            PlayerButcherVars[playerid][DuringTakeChicken] = true;
            Info(playerid, "Anda sekaran telah "LG_E"Duty{FFFFFF} sebagai pemotong ayam");

            new rand = random(sizeof(ChickenSpawn));
            if(DestroyPlayerObject(playerid, PlayerButcherVars[playerid][ChickenObject]))
            if(DestroyDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
                PlayerButcherVars[playerid][ChickenTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;    

            PlayerButcherVars[playerid][ChickenObject] = CreatePlayerObject(playerid, 19079, ChickenSpawn[rand][0], ChickenSpawn[rand][1], ChickenSpawn[rand][2], ChickenSpawn[rand][3], ChickenSpawn[rand][4], ChickenSpawn[rand][5], 300.00);                       
            PlayerButcherVars[playerid][ChickenTakeArea] = CreateDynamicSphere(ChickenSpawn[rand][0], ChickenSpawn[rand][1], ChickenSpawn[rand][2], 1.5);                         
        }
        if(listitem == 1)
        {
            if(!PlayerButcherVars[playerid][DuringTakeChicken])
                return ErrorMsg(playerid, "Anda belum duty pemotong ayam sebelumnya");

            if(DestroyPlayerObject(playerid, PlayerButcherVars[playerid][ChickenObject]))
            if(DestroyDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
                PlayerButcherVars[playerid][ChickenTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;    
            PlayerButcherVars[playerid][DuringTakeChicken] = false;
            Info(playerid, "Anda sekaran telah "RED_E"Off Duty{FFFFFF} sebagai pemotong ayam");
        }
    }
    return 1;
}

stock ButcherClear(playerid)
{
    KillTimer(pTakingChickenTimer[playerid]);
    pTakingChickenTimer[playerid] = 0;
    PlayerButcherVars[playerid][TakeCountChicken] = 0;

    if(DestroyPlayerObject(playerid, PlayerButcherVars[playerid][ChickenObject]))
    if(DestroyDynamicArea(PlayerButcherVars[playerid][ChickenTakeArea]))
        PlayerButcherVars[playerid][ChickenTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;       
    return 1;
}

hook OnPlayerConnect(playerid)
{
    ButcherClear(playerid);
    return 1;
}

function potongayamm(playerid)
{
    new countbulu = random(10);
    if(countbulu < 1)
    {
        countbulu = random(10);
    }
    Info(playerid, "Anda mendapatkan "YELLOW_E"Bulu{FFFFFF} sebanyak "YELLOW_E"%dx", countbulu);
    Inventory_Remove(playerid, "Ayam Hidup", 1);
    Inventory_Add(playerid, "Ayam Potong", 2806, 5);
    Inventory_Add(playerid, "Bulu", 1974, countbulu);
    RemovePlayerAttachedObject(playerid, 9);
	ClearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    return 1;
}

function packingayam(playerid)
{
    if(Inventory_Count(playerid, "Ayam Potong") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Ayam Potong (1)");
    Inventory_Remove(playerid, "Ayam Potong", 1);
    Inventory_Add(playerid, "Ayam Kemas", 2768, 2);
	ClearAnimations(playerid);
	StopLoopingAnim(playerid);
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    return 1;
}