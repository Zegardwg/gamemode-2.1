#include <YSI\y_hooks>

//disnaker
new pointdisnaker, buatktp;

stock PointServer()
{
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} Membuat KTP", -1, 1376.779052, 1573.292236, 17.000314, 10.0, 0, 0);	
    buatktp = CreateDynamicSphere(1376.779052, 1573.292236, 17.000314, 1.0);
    //disnaker
    Create3DTextLabel(""LG_E"[Y]{FFFFFF} Mengambil Pekerjaan", -1, 1376.6829,1576.6292,17.0003, 10.0, 0, 0);	
    pointdisnaker = CreateDynamicSphere(1376.6829,1576.6292,17.0003, 1.0);
}

hook OnPlayerConnect(playerid)
{
    PointServer();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{   
        if(IsPlayerInDynamicArea(playerid, buatktp))
        {
            if(AccountData[playerid][pKtp])
                return ErrorMsg(playerid, "Anda sudah mempunyai KTP.");
            AccountData[playerid][pKtp] = 1;
            SuccesMsg(playerid, "Anda berhasil membuat ktp");
        }
        if(IsPlayerInDynamicArea(playerid, pointdisnaker))
        {
            new str[500];
            format(str, 500, "Job\tPekerja\nTukang Ayam\t{FFFF00}%d\n"GREY_E"Penjahit\t{FFFF00}%d\nPengangguran\t-\n", 
            Iter_Count(ButcherOnduty), Iter_Count(TailorOnduty));
            Dialog_Show(playerid, DIALOG_DISNAKERMENU, DIALOG_STYLE_TABLIST_HEADERS, "{a8ecff}Konoha Roleplay{FFFFFF} - Disnaker", str, "Pilih", "Batal");
        }
    }
    return 1;
}

Dialog:DIALOG_DISNAKERMENU(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            if(AccountData[playerid][PlayerJob] > 1) return ErrorMsg(playerid, "Anda sudah mempunyai pekerjaan sebelumnya");
            AccountData[playerid][PlayerJob] = 1;
            Iter_Add(ButcherOnduty, 1);
            SuccesMsg(playerid, "Anda berhasil mengambil pekerjaan menjadi seorang Tukang Ayam!");
        }
        if(listitem == 1)
        {
            if(AccountData[playerid][PlayerJob] > 1) return ErrorMsg(playerid, "Anda sudah mempunyai pekerjaan sebelumnya");
            AccountData[playerid][PlayerJob] = 2;
            Iter_Add(TailorOnduty, 1);
            SuccesMsg(playerid, "Anda berhasil mengambil pekerjaan menjadi seorang Penjahit!");                         
        } 
        if(listitem == 2)
        {
            if(!AccountData[playerid][PlayerJob]) return ErrorMsg(playerid, "Anda tidak didalam pekerjaan apapun");
            if(AccountData[playerid][PlayerJob] == 1)
            {
                AccountData[playerid][PlayerJob] = 0;
                PlayerButcherVars[playerid][DuringTakeChicken] = false;
                Iter_Remove(ButcherOnduty, 1);
                SuccesMsg(playerid, "Anda berhasil keluar dari pekerjaan Tukang Ayam!");
            }               
            else if(AccountData[playerid][PlayerJob] == 2)
            {
                AccountData[playerid][PlayerJob] = 0;
                Iter_Remove(TailorOnduty, 1);
                SuccesMsg(playerid, "Anda berhasil keluar dari pekerjaan Penjahit!");
            }                                   
        }         
    }      
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(AccountData[playerid][PlayerJob] == 1)
    {
        Iter_Add(ButcherOnduty, 1);
    } 
    else if(AccountData[playerid][PlayerJob] == 2)
    {
        Iter_Add(TailorOnduty, 1);
    }     
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(AccountData[playerid][PlayerJob] == 1)
    {
        Iter_Remove(ButcherOnduty, 1);
    }    
    else if(AccountData[playerid][PlayerJob] == 2)
    {
        Iter_Remove(TailorOnduty, 1);
    }     
    return 1;
}