new StatusKompensasi;
#define COLOR_CYAN					0x00FFFFFF
CMD:kompensasi(playerid, params[])
{
    if(!StatusKompensasi)
        return ErrorMsg(playerid, "Kompensasi sedang tidak di buka");

    if(pData[playerid][pKompensasi])
        return ErrorMsg(playerid, "Anda telah mengambil kompensasi sebelumnya");

	GiveMoney(playerid, 2500);
	Inventory_Add(playerid, "Handphone", 18867, 1);
	Inventory_Add(playerid, "Nasi Goreng", 2354, 10);
	Inventory_Add(playerid, "Es Teh", 2647, 10);
    pData[playerid][pKompensasi] = 1;
    return 1;
}

CMD:akompensasi(playerid, params[])
{
    if (pData[playerid][pAdmin] < 5)
	    return ErrorMsg(playerid, "You don't have permission to use this command.");

    if(!StatusKompensasi)
    {
        SendClientMessageToAllEx(COLOR_CYAN, "[AdmCmd] %s telah membuka kembali Kompensasi '/kompensasi'", pData[playerid][pAdminname]);
        StatusKompensasi = 1;
    }
    else 
    {
        SendClientMessageToAllEx(COLOR_CYAN, "[AdmCmd] %s telah menutup kembali Kompensasi", pData[playerid][pAdminname]);
        StatusKompensasi = 0;
        foreach(new i : Player)
        {
            if(pData[i][pSpawned])
            {
                pData[i][pKompensasi] = 0;
            }
        }
    }
    return 1;
}