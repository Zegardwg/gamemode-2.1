#include <YSI\y_hooks>

enum E_CELLCOUNTERSTUFF
{
    ccPrice,
    ccAmount,
    ccJumlah[2],
    ccItem[2]
}
new PlayerCellVars[MAX_PLAYERS][E_CELLCOUNTERSTUFF];

new phonearea1, cellbuyarea1;

stock LoadAreaCell()
{
    Create3DTextLabel("Tekan "LG_E"Y{FFFFFF} untuk mengambil barang", -1, 1944.937866, -1979.875610, 13.797863, 25.0, 0, 1);		
    Create3DTextLabel("Tekan "LG_E"Y{FFFFFF} untuk membayar barang", -1, 1942.508544, -1980.982421, 13.797863, 25.0, 0, 1);		
    phonearea1 = CreateDynamicSphere(1944.937866, -1979.875610, 13.797863, 1.0);
    cellbuyarea1 = CreateDynamicSphere(1942.508544, -1980.982421, 13.797863, 1.0);
}

hook OnGameModeInit()
{
    LoadAreaCell();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
        if(IsPlayerInDynamicArea(playerid, cellbuyarea1))
        {
            if(PlayerCellVars[playerid][ccItem][0])
            {
                new str[500];
                format(str, 500, "Nama Barang\t:\tJumlah\nHandphone\t-\t%d\nTagihan:\t%s", PlayerCellVars[playerid][ccJumlah][0], FormatMoney(PlayerCellVars[playerid][ccPrice]));
                Dialog_Show(playerid, DIALOG_CELLCOUNTERBUY, DIALOG_STYLE_TABLIST_HEADERS, "Cell Counter >> Payment Barang", str, "Bayar", "Batalkan");
            }
        }
        if(IsPlayerInDynamicArea(playerid, phonearea1))
        {
            Dialog_Show(playerid, DIALOG_AMOUNTHP, DIALOG_STYLE_INPUT, "Cell Counter >> Handphone", "{FFFFFF}Masukan jumlah handphone yang ingin anda beli:", "Masukan", "Batalkan");
        }
    }
    return 1;
}

stock ResetPlayerCell(playerid)
{
    PlayerCellVars[playerid][ccPrice] = 0;
    PlayerCellVars[playerid][ccAmount] = 0;
    PlayerCellVars[playerid][ccJumlah][0] = 0;
    PlayerCellVars[playerid][ccJumlah][1] = 0;
    PlayerCellVars[playerid][ccItem][0] = 0;
    PlayerCellVars[playerid][ccItem][1] = 0;
    return 1;
}

hook OnPlayerConnect(playerid)
{
    ResetPlayerCell(playerid);
    return 1;
}

Dialog:DIALOG_CELLCOUNTERBUY(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(PlayerCellVars[playerid][ccItem][0])
        {
            if(GetPlayerMoney(playerid) < PlayerCellVars[playerid][ccPrice]) return ErrorMsg(playerid, "Uang anda tidak cukup");
            GiveMoney(playerid, -PlayerCellVars[playerid][ccPrice]);
            Inventory_Add(playerid, "Handphone", 18867, PlayerCellVars[playerid][ccJumlah][0]);
            new nomor = RandomEx(11111, 99999);
            pData[playerid][pPhone] = nomor;          
            PlayerCellVars[playerid][ccJumlah][0] = 0;
            PlayerCellVars[playerid][ccItem][0] = 0;
            PlayerCellVars[playerid][ccPrice] = 0;
        }
    }
    return 1;
}

Dialog:DIALOG_AMOUNTHP(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new amount = strval(inputtext);
        if(amount < 0) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");
        if(amount == 0) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");
        if(amount > 3) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");

        PlayerCellVars[playerid][ccJumlah][0] = amount;
        PlayerCellVars[playerid][ccItem][0] = 1;
        PlayerCellVars[playerid][ccPrice] = amount*200;
    }
    return 1;
}