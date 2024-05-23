#include <YSI\y_hooks>
enum e_pilkadadata
{
    pkontol,
    no1,
    no2,
    no3,
    no4,
    pres1[50],
    pres2[50],
    pres3[50],
    pres4[50],
    wakpres1[50],
    wakpres2[50],
    wakpres3[50],
    wakpres4[50],    
    partai1[50],
    partai2[50],
    partai3[50],
    partai4[50]    
}
new pilkadaData[e_pilkadadata];

CMD:avote(playerid, params[])
{
    new str[200];
    format(str, 200, "No. Urut\tCapres\tCawapres\tPartai\n#01\t%s\t%s\t%s\n#02\t%s\t%s\t%s\n\n#03\t%s\t%s\t%s\n\n#04\t%s\t%s\t%s\n", 
    pilkadaData[pres1], pilkadaData[wakpres1], pilkadaData[partai1], pilkadaData[pres2], pilkadaData[wakpres2], pilkadaData[partai2], pilkadaData[pres3], pilkadaData[wakpres3], pilkadaData[partai3], pilkadaData[pres4], pilkadaData[wakpres4], pilkadaData[partai4]);
    Dialog_Show(playerid, DIALOG_PILKADAADMIN, DIALOG_STYLE_TABLIST_HEADERS, "Admin Menu TPS", str, "Edit", "Batal");
    return 1;
}

stock pilkada_save()
{
    new str[5000];

    format(str, sizeof(str), "UPDATE pilkada SET pres1='%s', pres2='%s', pres33='%s', pres4='%s', wakpres1='%s', wakpres2='%s', wakpres3='%s', wakpres4='%s', partai1='%s', partai2='%s', partai3='%s', partai4='%s', no1='%d', no2='%d', no3='%d', no4='%d' WHERE id=0",
	pilkadaData[pres1], pilkadaData[wakpres1], pilkadaData[partai1], pilkadaData[pres2], pilkadaData[wakpres2], pilkadaData[partai2], pilkadaData[pres3], pilkadaData[wakpres3], pilkadaData[partai3], pilkadaData[pres4], pilkadaData[wakpres4], pilkadaData[partai4]);
    return mysql_tquery(g_SQL, str);
}

function LoadPilkadaData()
{
	cache_get_value_name(0, "pres1", pilkadaData[pres1]);
	cache_get_value_name(0, "pres2", pilkadaData[pres2]);
	cache_get_value_name(0, "pres3", pilkadaData[pres3]);
	cache_get_value_name(0, "pres4", pilkadaData[pres4]);    
    cache_get_value_name(0, "wakpres1", pilkadaData[wakpres1]);
    cache_get_value_name(0, "wakpres2", pilkadaData[wakpres2]);
    cache_get_value_name(0, "wakpres3", pilkadaData[wakpres3]);
    cache_get_value_name(0, "wakpres4", pilkadaData[wakpres4]);    
    cache_get_value_name(0, "partai1", pilkadaData[partai1]);
    cache_get_value_name(0, "partai2", pilkadaData[partai2]);    
    cache_get_value_name(0, "partai3", pilkadaData[partai3]);
    cache_get_value_name(0, "partai4", pilkadaData[partai4]);       
    cache_get_value_name_int(0, "no1", pilkadaData[no1]);  
    cache_get_value_name_int(0, "no2", pilkadaData[no2]);  
    cache_get_value_name_int(0, "no3", pilkadaData[no3]);  
    cache_get_value_name_int(0, "no4", pilkadaData[no4]);      
}

hook OnGameModeInit()
{
    mysql_tquery(g_SQL, "SELECT * FROM `pilkada`", "LoadPilkadaData");
    return 1;
}

CMD:tpsstatus(playerid, params[])
{
	if(pData[playerid][pAdmin] < 3)
		return SendErrorMessage(playerid, "You don't have permission to use this command!");

    if(pilkadaData[pkontol] < 1)
    {
        pilkadaData[pkontol] = 1;
        SendClientMessageToAllEx(COLOR_YELLOW, "[TPS] tempat TPS telah dibuka untuk umum");
    }
    else 
    {
        pilkadaData[pkontol] = 0;
        SendClientMessageToAllEx(COLOR_YELLOW, "[TPS] tempat TPS telah ditutup untuk umum");
    }
    return 1;
}

CMD:vote(playerid, params[])
{
    if(pilkadaData[pkontol] != 1)
        return ErrorMsg(playerid, "Pilkada tidak sedang dibuka");

    if(pData[playerid][Pilkada] == 1)
        return ErrorMsg(playerid, "Anda telah mencoblos sebelumnya");

    new str[200];
    format(str, 200, "No. Urut\tCapres\tCawapres\tPartai\n#01\t%s\t%s\t%s\n#02\t%s\t%s\t%s\n\n#03\t%s\t%s\t%s\n\n#04\t%s\t%s\t%s\n", 
    pilkadaData[pres1], pilkadaData[wakpres1], pilkadaData[partai1], pilkadaData[pres2], pilkadaData[wakpres2], pilkadaData[partai2], pilkadaData[pres3], pilkadaData[wakpres3], pilkadaData[partai3], pilkadaData[pres4], pilkadaData[wakpres4], pilkadaData[partai4]);
    Dialog_Show(playerid, DIALOG_PILIHCAPRES, DIALOG_STYLE_TABLIST_HEADERS, "Bilik TPS", str, "Pilih", "Batal");
    return 1;
}

Dialog:DIALOG_PILIHCAPRES(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                pData[playerid][Pilkada] = 1;
                pilkadaData[no1]++;
                pilkada_save();
            }
            case 1:
            {
                pData[playerid][Pilkada] = 1;
                pilkadaData[no2]++;
                pilkada_save();                
            }         
            case 2:
            {
                pData[playerid][Pilkada] = 1;
                pilkadaData[no3]++;
                pilkada_save();
            }
            case 3:
            {
                pData[playerid][Pilkada] = 1;
                pilkadaData[no4]++;
                pilkada_save();                
            }                 
        }
    }
    return 1;
}

Dialog:DIALOG_PILKADAADMIN(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
               Dialog_Show(playerid, MENU_PASLON1, DIALOG_STYLE_LIST, "Menu Paslon #01", "Edit Paslon #01\nClear Paslon #01", "Pilih", "Batal");
               //Dialog_Show(playerid, DIALOG_PASLON1, DIALOG_STYLE_INPUT, "Edit Capres #01", "{FFFFF}Maskkan nama calon presiden #01", "Input", "Tutup");
            }
            case 1:
            {
                Dialog_Show(playerid, MENU_PASLON2, DIALOG_STYLE_LIST, "Menu Paslon #02", "Edit Paslon #01\nClear Paslon #02", "Pilih", "Batal");
                //Dialog_Show(playerid, DIALOG_PASLON2, DIALOG_STYLE_INPUT, "Edit Capres #02", "{FFFFF}Maskkan nama calon presiden #02", "Input", "Tutup");
            }     
            case 2:
            {
               Dialog_Show(playerid, MENU_PASLON3, DIALOG_STYLE_LIST, "Menu Paslon #03", "Edit Paslon #01\nClear Paslon #03", "Pilih", "Batal");
               //Dialog_Show(playerid, DIALOG_PASLON1, DIALOG_STYLE_INPUT, "Edit Capres #01", "{FFFFF}Maskkan nama calon presiden #01", "Input", "Tutup");
            }
            case 3:
            {
                Dialog_Show(playerid, MENU_PASLON4, DIALOG_STYLE_LIST, "Menu Paslon #04", "Edit Paslon #01\nClear Paslon #04", "Pilih", "Batal");
                //Dialog_Show(playerid, DIALOG_PASLON2, DIALOG_STYLE_INPUT, "Edit Capres #02", "{FFFFF}Maskkan nama calon presiden #02", "Input", "Tutup");
            }                     
        }
    }
    return 1;
}

Dialog:MENU_PASLON1(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                Dialog_Show(playerid, DIALOG_PASLON1, DIALOG_STYLE_INPUT, "Edit Capres #01", "Maskkan nama calon presiden #01", "Input", "Tutup");
            }
            case 1:
            {
                format(pilkadaData[pres1], 50, "");
                format(pilkadaData[wakpres1], 50, "");
                format(pilkadaData[partai1], 50, "");
            }
        }
    }
    return 1;
}

Dialog:MENU_PASLON2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                Dialog_Show(playerid, DIALOG_PASLON2, DIALOG_STYLE_INPUT, "Edit Capres #02", "Maskkan nama calon presiden #02", "Input", "Tutup");
            }
            case 1:
            {
                format(pilkadaData[pres2], 50, "");
                format(pilkadaData[wakpres2], 50, "");
                format(pilkadaData[partai2], 50, "");
            }
        }
    }
    return 1;
}

Dialog:MENU_PASLON3(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                Dialog_Show(playerid, DIALOG_PASLON3, DIALOG_STYLE_INPUT, "Edit Capres #03", "Maskkan nama calon presiden #03", "Input", "Tutup");
            }
            case 1:
            {
                format(pilkadaData[pres3], 50, "");
                format(pilkadaData[wakpres3], 50, "");
                format(pilkadaData[partai3], 50, "");
            }
        }
    }
    return 1;
}

Dialog:MENU_PASLON4(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                Dialog_Show(playerid, DIALOG_PASLON4, DIALOG_STYLE_INPUT, "Edit Capres #04", "Maskkan nama calon presiden #04", "Input", "Tutup");
            }
            case 1:
            {
                format(pilkadaData[pres4], 50, "");
                format(pilkadaData[wakpres4], 50, "");
                format(pilkadaData[partai4], 50, "");
            }
        }
    }
    return 1;
}

Dialog:DIALOG_PASLON1(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");
        
        format(pilkadaData[pres1], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_CAWAPRESS1, DIALOG_STYLE_INPUT, "Edit Cawapress #01", "Maskkan nama calon wakil presiden #01", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_PASLON2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[pres2], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_CAWAPRESS2, DIALOG_STYLE_INPUT, "Edit Cawapress #02", "Maskkan nama calon wakil presiden #02", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_PASLON3(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[pres3], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_CAWAPRESS3, DIALOG_STYLE_INPUT, "Edit Cawapress #03", "Maskkan nama calon wakil presiden #03", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_PASLON4(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[pres4], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_CAWAPRESS4, DIALOG_STYLE_INPUT, "Edit Cawapress #04", "Maskkan nama calon wakil presiden #04", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_CAWAPRESS1(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[wakpres1], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_PARTAI1, DIALOG_STYLE_INPUT, "Edit Partai #01", "Maskkan nama partai #01", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_CAWAPRESS2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[wakpres2], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_PARTAI2, DIALOG_STYLE_INPUT, "Edit Partai #02", "Maskkan nama partai #02", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_CAWAPRESS3(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[wakpres3], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_PARTAI3, DIALOG_STYLE_INPUT, "Edit Partai #03", "Maskkan nama partai #03", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_CAWAPRESS4(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[wakpres4], 50, inputtext);
        pilkada_save();
        Dialog_Show(playerid, DIALOG_PARTAI4, DIALOG_STYLE_INPUT, "Edit Partai #04", "Maskkan nama partai #04", "Input", "Tutup");
    }
    return 1;
}

Dialog:DIALOG_PARTAI1(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[partai1], 50, inputtext);
        pilkada_save();
    }
    return 1;
}

Dialog:DIALOG_PARTAI2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[partai2], 50, inputtext);
        pilkada_save();
    }
    return 1;
}

Dialog:DIALOG_PARTAI3(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[partai3], 50, inputtext);
        pilkada_save();
    }
    return 1;
}

Dialog:DIALOG_PARTAI4(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(IsNumeric(inputtext))
            return ErrorMsg(playerid, "Anda hanya bisa memasukkan nama");

        format(pilkadaData[partai4], 50, inputtext);
        pilkada_save();
    }
    return 1;
}

CMD:pilkada(playerid, params[])
{
    new str[500];
    format(str, 500, "======= [QUICK COUNT PILKADAKOTA KONOHA #1] =======\n> #01 - %s <\n> %s & %s\n> Suara: %d\n> #02 - %s <\n> %s & %s\n> Suara: %d\n> #03 - %s <\n> %s & %s\n> Suara: %d\n> #04 - %s <\n> %s & %s\n> Suara: %d",
    pilkadaData[partai1], pilkadaData[pres1], pilkadaData[wakpres1], pilkadaData[no1], pilkadaData[partai2], pilkadaData[pres2], pilkadaData[wakpres2], pilkadaData[no2], pilkadaData[partai3], pilkadaData[pres3], pilkadaData[wakpres3], pilkadaData[no3], pilkadaData[partai4], pilkadaData[pres4], pilkadaData[wakpres4], pilkadaData[no4]);
    Dialog_Show(playerid, DIALOG_UNKD, DIALOG_STYLE_MSGBOX, "Pilkada Kota", str, "Close", "");
    return 1;
}