#include <YSI\y_hooks>

enum E_GLOBALTAILORSTUFF
{
    STREAMER_TAG_AREA:buatbenang[2],
    STREAMER_TAG_AREA:buatkain[2],
    STREAMER_TAG_AREA:jahitpakaian[3]
}
new TailorVars[E_GLOBALTAILORSTUFF],
    Iterator:TailorOnduty<MAX_PLAYERS>;

stock LoadPointTailor()
{
	CreateDynamic3DTextLabel(""LG_E"[Y] {FFFFFF}Buat benang (1x bulu => 1x benang)", -1, 2322.974121, -2074.806152, 17.022911, 10.0);   
    TailorVars[buatbenang][0] = CreateDynamicSphere(2322.974121, -2074.806152, 17.022911, 1.0);

	CreateDynamic3DTextLabel(""LG_E"[Y] {FFFFFF}Buat kain", -1, 2326.471435, -2078.283691, 17.022911, 10.0);
    TailorVars[buatkain][0] = CreateDynamicSphere(2326.471435, -2078.283691, 17.022911, 1.0);

	CreateDynamic3DTextLabel(""LG_E"[Y] {FFFFFF}Jahit pakaian", -1, 2317.097656, -2081.939697, 17.002910, 10.0);
	CreateDynamic3DTextLabel(""LG_E"[Y] {FFFFFF}Jahit pakaian", -1, 2315.181152, -2083.854492, 17.002910, 10.0);   
    CreateDynamic3DTextLabel(""LG_E"[Y] {FFFFFF}Jahit pakaian", -1, 2314.000244, -2081.623291, 17.002910, 10.0);   
    TailorVars[jahitpakaian][0] = CreateDynamicSphere(2317.097656, -2081.939697, 17.002910, 1.0);
    TailorVars[jahitpakaian][1] = CreateDynamicSphere(2315.181152, -2083.854492, 17.002910, 1.0);
    TailorVars[jahitpakaian][2] = CreateDynamicSphere(2314.000244, -2081.623291, 17.002910, 1.0);
}

hook OnGameModeInit()
{
    LoadPointTailor();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{
        //proses pekerjaan
        if(IsPlayerInDynamicArea(playerid, TailorVars[jahitpakaian][2]))
        {
            if(AccountData[playerid][PlayerJob] != 2) return ErrorMsg(playerid, "Anda bukan seorang Tukang Jahit!");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
              
            if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Kain (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMBUAT PAKAIAN", 5);
            SetTimerEx("membuatpakaian", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);                    
        }
        if(IsPlayerInDynamicArea(playerid, TailorVars[jahitpakaian][1]))
        {
            if(AccountData[playerid][PlayerJob] != 2) return ErrorMsg(playerid, "Anda bukan seorang Tukang Jahit!");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
              
            if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Kain (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMBUAT PAKAIAN", 5);
            SetTimerEx("membuatpakaian", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);                    
        }                 
        if(IsPlayerInDynamicArea(playerid, TailorVars[jahitpakaian][0]))
        {
            if(AccountData[playerid][PlayerJob] != 2) return ErrorMsg(playerid, "Anda bukan seorang Tukang Jahit!");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
           
            if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Kain (1)");
            if(Inventory_Count(playerid, "Bulu") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Bulu (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMBUAT PAKAIAN", 5);
            SetTimerEx("membuatpakaian", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);                
        }        
        //
        if(IsPlayerInDynamicArea(playerid, TailorVars[buatkain][0]))
        {
            if(AccountData[playerid][PlayerJob] != 2) return ErrorMsg(playerid, "Anda bukan seorang Tukang Jahit!");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");

            if(Inventory_Count(playerid, "Benang") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Benang (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMBUAT KAIN", 5);
            SetTimerEx("membuatkain", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);                 
        }
        //mengolah benang           
        if(IsPlayerInDynamicArea(playerid, TailorVars[buatbenang][0]))
        {
            if(AccountData[playerid][PlayerJob] != 2) return ErrorMsg(playerid, "Anda bukan seorang Tukang Jahit!");
            if(Inventory_Count(playerid, "Bulu") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Bulu (1)");
            if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");
            ShowProgressbar(playerid, "MEMBUAT BENANG", 5);
            SetTimerEx("membuatbenang", 5000, 0, "i", playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.1, 1, 1, 1, 1, 0, 1);                 
        }
    }
    return 1;
}

function membuatbenang(playerid)
{
    if(Inventory_Count(playerid, "Bulu") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Bulu (1)");
    if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");    
    Inventory_Remove(playerid, "Bulu", 1);
    Inventory_Add(playerid, "Benang", 1931, 2);
    return 1;
}

function membuatkain(playerid)
{
    if(Inventory_Count(playerid, "Benang") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Benang (1)");
    if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");    
    Inventory_Remove(playerid, "Benang", 1);
    Inventory_Add(playerid, "Kain", 2384, 2);
    return 1;
}

function membuatpakaian(playerid)
{
    if(Inventory_Count(playerid, "Kain") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Kain (1)");
    if(Inventory_Count(playerid, "Bulu") < 1) return ErrorMsg(playerid, "Kamu tidak memiliki Bulu (1)");
    if(pData[playerid][pProgress]) return ErrorMsg(playerid, "Anda masih dalam activity progress");    
    Inventory_Remove(playerid, "Kain", 1);
    Inventory_Remove(playerid, "Bulu", 1);
    Inventory_Add(playerid, "Pakaian", 2689, 1);
    return 1;
}