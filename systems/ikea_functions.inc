#include <YSI\y_hooks>
new ikeamenu;

stock LoadIkeaPoint()
{
    Create3DTextLabel("Tekan "LG_E"Y{FFFFFF} untuk menjual barang hasil kerja", -1, 2357.816406, -1990.605102, 13.546875, 25.0, 0, 1);		
    ikeamenu = CreateDynamicSphere(2357.816406, -1990.605102, 13.546875, 2.0, 0, 0);
    return 1;
}

hook OnGameModeInit()
{
    LoadIkeaPoint();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
        if(IsPlayerInDynamicArea(playerid, ikeamenu))
        {
            new str[500];
            format(str, 500, "Item Name\t:\tPrice\tYou Have\nAyam Kemas\t-\t"LG_E"$14/pcs\t%d\nPakaian\t-\t"LG_E"$12/pcs\t%d",
            Inventory_Count(playerid, "Ayam Kemas"), Inventory_Count(playerid, "Pakaian"));
            Dialog_Show(playerid, DIALOG_SELLITEM, DIALOG_STYLE_TABLIST_HEADERS, "{a8ecff}Konoha Roleplay{FFFFFF} - Penjualan Barang Kerja", str, "Pilih", "Batalkan");   
        }
    }
    return 1;
}

Dialog:DIALOG_SELLITEM(playerid, listitem, response, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            new amount = Inventory_Count(playerid, "Ayam Kemas");
            Inventory_Remove(playerid, "Ayam Kemas", amount);
            GiveMoney(playerid, 12*amount);         
        }
        if(listitem == 1)
        {
            new amount = Inventory_Count(playerid, "Pakaian");
            Inventory_Remove(playerid, "Pakaian", amount);
            GiveMoney(playerid, 12*amount);          
        }            
    }
    return 1;
}

CMD:ad(playerid, params[])
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    PlayOnlineAudio(playerid, "Sorai", x, y, z);
    return 1;
}