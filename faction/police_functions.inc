#include <YSI\y_hooks>

new carvid;
new aksesoris_sanchez_sabhara1,
    aksesoris_sanchez_sabhara2,
    aksesoris_sanchez_sabhara3,
    aksesoris_sanchez_sabhara4,
    aksesoris_sanchez_sabhara5,
    aksesoris_sanchez_sabhara6,
    aksesoris_sanchez_sabhara7,
    aksesoris_sanchez_sabhara8,
    aksesoris_sanchez_sabhara9,
    aksesoris_sanchez_sabhara10,
    aksesoris_sanchez_sabhara11,
    aksesoris_sanchez_sabhara12;

new aksesoris_sanchez_satlantas1,
    aksesoris_sanchez_satlantas2,
    aksesoris_sanchez_satlantas3,
    aksesoris_sanchez_satlantas4,
    aksesoris_sanchez_satlantas5,
    aksesoris_sanchez_satlantas6,
    aksesoris_sanchez_satlantas7,
    aksesoris_sanchez_satlantas8,
    aksesoris_sanchez_satlantas9,
    aksesoris_sanchez_satlantas10,
    aksesoris_sanchez_satlantas11,
    aksesoris_sanchez_satlantas12;

new aksesoris_yosmite_sabhara1,
    aksesoris_yosmite_sabhara2,
    aksesoris_yosmite_sabhara3,
    aksesoris_yosmite_sabhara4,
    aksesoris_yosmite_sabhara5,
    aksesoris_yosmite_sabhara6,
    aksesoris_yosmite_sabhara7,
    aksesoris_yosmite_sabhara8,
    aksesoris_yosmite_sabhara9,
    aksesoris_yosmite_sabhara10,
    aksesoris_yosmite_sabhara11,
    aksesoris_yosmite_sabhara12,
    aksesoris_yosmite_sabhara13,
    aksesoris_yosmite_sabhara14,
    aksesoris_yosmite_sabhara15,
    aksesoris_yosmite_sabhara16,
    aksesoris_yosmite_sabhara17,
    aksesoris_yosmite_sabhara18,
    aksesoris_yosmite_sabhara19,
    aksesoris_yosmite_sabhara20,      
    aksesoris_yosmite_sabhara21,
    aksesoris_yosmite_sabhara22;

new aksesoris_yosmite_patwal1,
    aksesoris_yosmite_patwal2,
    aksesoris_yosmite_patwal3,
    aksesoris_yosmite_patwal4,
    aksesoris_yosmite_patwal5,
    aksesoris_yosmite_patwal6,
    aksesoris_yosmite_patwal7,
    aksesoris_yosmite_patwal8,
    aksesoris_yosmite_patwal9,
    aksesoris_yosmite_patwal10,
    aksesoris_yosmite_patwal11,
    aksesoris_yosmite_patwal12,
    aksesoris_yosmite_patwal13,
    aksesoris_yosmite_patwal14,
    aksesoris_yosmite_patwal15,
    aksesoris_yosmite_patwal16,
    aksesoris_yosmite_patwal17,
    aksesoris_yosmite_patwal18,
    aksesoris_yosmite_patwal19,
    aksesoris_yosmite_patwal20,      
    aksesoris_yosmite_patwal21,
    aksesoris_yosmite_patwal22,
    aksesoris_yosmite_patwal23,
    aksesoris_yosmite_patwal24,      
    aksesoris_yosmite_patwal25,
    aksesoris_yosmite_patwal26;

new aksesoris_sultan_satlantas1,
    aksesoris_sultan_satlantas2,
    aksesoris_sultan_satlantas3,
    aksesoris_sultan_satlantas4,
    aksesoris_sultan_satlantas5,
    aksesoris_sultan_satlantas6,
    aksesoris_sultan_satlantas7,
    aksesoris_sultan_satlantas8,
    aksesoris_sultan_satlantas9,
    aksesoris_sultan_satlantas10,
    aksesoris_sultan_satlantas11,
    aksesoris_sultan_satlantas12,
    aksesoris_sultan_satlantas13,
    aksesoris_sultan_satlantas14,
    aksesoris_sultan_satlantas15,
    aksesoris_sultan_satlantas16,
    aksesoris_sultan_satlantas17,
    aksesoris_sultan_satlantas18,
    aksesoris_sultan_satlantas19,
    aksesoris_sultan_satlantas20,      
    aksesoris_sultan_satlantas21,
    aksesoris_sultan_satlantas22,
    aksesoris_sultan_satlantas23,
    aksesoris_sultan_satlantas24,      
    aksesoris_sultan_satlantas25;  

new aksesoris_sultan_sabhara1,
    aksesoris_sultan_sabhara2,
    aksesoris_sultan_sabhara3,
    aksesoris_sultan_sabhara4,
    aksesoris_sultan_sabhara5,
    aksesoris_sultan_sabhara6,
    aksesoris_sultan_sabhara7,
    aksesoris_sultan_sabhara8,
    aksesoris_sultan_sabhara9,
    aksesoris_sultan_sabhara10,
    aksesoris_sultan_sabhara11,
    aksesoris_sultan_sabhara12,
    aksesoris_sultan_sabhara13,
    aksesoris_sultan_sabhara14,
    aksesoris_sultan_sabhara15,
    aksesoris_sultan_sabhara16,
    aksesoris_sultan_sabhara17,
    aksesoris_sultan_sabhara18,
    aksesoris_sultan_sabhara19,
    aksesoris_sultan_sabhara20,      
    aksesoris_sultan_sabhara21,
    aksesoris_sultan_sabhara22;

enum E_POLISISTUFF
{
    STREAMER_TAG_AREA:DutyArea,
    STREAMER_TAG_AREA:LokerArea,
    STREAMER_TAG_AREA:PerlengkapanArea,
    STREAMER_TAG_AREA:BossTable,
    STREAMER_TAG_AREA:MenuGarasi,
    STREAMER_TAG_AREA:MasukinGarasi
}
new PolisiVars[E_POLISISTUFF];  

stock LoadPolisiStuff()
{
    PolisiVars[MasukinGarasi] = CreateDynamicSphere(1757.296752, -1777.894531, 13.528462, 2.3);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}Untuk mengambil kendaran polisi", -1, 1760.769409, -1787.802368, 13.523437, 25.0, 0, 1);		
    PolisiVars[MenuGarasi] = CreateDynamicSphere(1760.769409, -1787.802368, 13.523437, 1.3);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}Boss Table", -1, 1799.595458, -1755.121704, 17.163227, 25.0, 0, 1);	
    PolisiVars[BossTable] = CreateDynamicSphere(1799.595458, -1755.121704, 17.163227, 1.3);
    Create3DTextLabel("WARGA YANG TIDAK BERKEPENTINGAN DILARANG MASUK!!", COLOR_RED, 1801.715576, -1774.135620, 14.546964, 50.0, 0, 1);	
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk Onduty/Offduty Polisi", -1, 1793.439941, -1774.090698, 13.624095, 25.0, 0, 1);		
    PolisiVars[DutyArea] = CreateDynamicSphere(1793.439941, -1774.090698, 13.624095, 1.5);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk membuka loker polisi", -1, 1786.853149, -1791.598388, 13.653233, 25.0, 0, 1);		
    PolisiVars[LokerArea] = CreateDynamicSphere(1786.853149, -1791.598388, 13.653233, 2.3);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk mengambil perlengkapan", -1, 1790.746704, -1795.602661, 17.163248, 25.0, 0, 1);		
    PolisiVars[PerlengkapanArea] = CreateDynamicSphere(1790.746704, -1795.602661, 17.163248, 2.3);
    return 1;
}

stock PangkatPolisi(playerid)
{
    new rantaipangkat[128];
    if(pData[playerid][pFaction] == 1)
    {
        if(pData[playerid][pFactionRank] == 0)format(rantaipangkat, sizeof(rantaipangkat), "Tidak Ada");
        else if(pData[playerid][pFactionRank] == 1)format(rantaipangkat, sizeof(rantaipangkat), "Bripda");
        else if(pData[playerid][pFactionRank] == 2)format(rantaipangkat, sizeof(rantaipangkat), "Briptu");
        else if(pData[playerid][pFactionRank] == 3)format(rantaipangkat, sizeof(rantaipangkat), "Bripka");
        else if(pData[playerid][pFactionRank] == 4)format(rantaipangkat, sizeof(rantaipangkat), "Brigpol");
        else if(pData[playerid][pFactionRank] == 5)format(rantaipangkat, sizeof(rantaipangkat), "AIPDA");
        else if(pData[playerid][pFactionRank] == 6)format(rantaipangkat, sizeof(rantaipangkat), "AIPTU");
        else if(pData[playerid][pFactionRank] == 7)format(rantaipangkat, sizeof(rantaipangkat), "IPDA");
        else if(pData[playerid][pFactionRank] == 8)format(rantaipangkat, sizeof(rantaipangkat), "IPTU");
        else if(pData[playerid][pFactionRank] == 9)format(rantaipangkat, sizeof(rantaipangkat), "AKP");
        else if(pData[playerid][pFactionRank] == 10)format(rantaipangkat, sizeof(rantaipangkat), "Kompol");
        else if(pData[playerid][pFactionRank] == 11)format(rantaipangkat, sizeof(rantaipangkat), "AKBP");
        else if(pData[playerid][pFactionRank] == 12)format(rantaipangkat, sizeof(rantaipangkat), "Kombes Pol");
        else if(pData[playerid][pFactionRank] == 13)format(rantaipangkat, sizeof(rantaipangkat), "Brigjenpol");
        else if(pData[playerid][pFactionRank] == 14)format(rantaipangkat, sizeof(rantaipangkat), "Irjenpol");   
        else if(pData[playerid][pFactionRank] == 15)format(rantaipangkat, sizeof(rantaipangkat), "Komjenpol");
        else if(pData[playerid][pFactionRank] == 16)format(rantaipangkat, sizeof(rantaipangkat), "Jendral");            
    }
    return rantaipangkat;
}

hook OnGameModeInit()
{
    LoadPolisiStuff();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_CTRL_BACK)
    {
        if(pData[playerid][pFaction] == 1)
        {
            if(pData[playerid][pOnDuty])
            {
                foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
                {
                    Dialog_Show(playerid, DIALOG_RADIALPOLISI, DIALOG_STYLE_LIST, ""GREY_E"Polisi >> Faction Menu", "Geledah\nBeri Invoice\nBorgol\nLepas Borgol", "Pilih", "Batalkan");
                }
            }
        }
    }
	if(newkeys & KEY_YES)
	{
        if(IsPlayerInDynamicArea(playerid, PolisiVars[MasukinGarasi]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
                    {
                        DestroyDynamicObject(aksesoris_sanchez_sabhara1);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara2);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara3);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara4);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara5);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara6);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara7);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara8);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara9);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara10);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara11);
                        DestroyDynamicObject(aksesoris_sanchez_sabhara12);

                        DestroyDynamicObject(aksesoris_sanchez_satlantas1);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas2);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas3);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas4);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas5);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas6);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas7);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas8);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas9);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas10);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas11);
                        DestroyDynamicObject(aksesoris_sanchez_satlantas12);

                        DestroyDynamicObject(aksesoris_yosmite_sabhara1);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara2);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara3);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara4);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara5);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara6);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara7);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara8);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara9);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara10);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara11);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara12);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara13);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara14);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara15);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara16);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara17);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara18);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara19);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara20);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara21);
                        DestroyDynamicObject(aksesoris_yosmite_sabhara22);

                        DestroyDynamicObject(aksesoris_yosmite_patwal1);
                        DestroyDynamicObject(aksesoris_yosmite_patwal2);
                        DestroyDynamicObject(aksesoris_yosmite_patwal3);
                        DestroyDynamicObject(aksesoris_yosmite_patwal4);
                        DestroyDynamicObject(aksesoris_yosmite_patwal5);
                        DestroyDynamicObject(aksesoris_yosmite_patwal6);
                        DestroyDynamicObject(aksesoris_yosmite_patwal7);
                        DestroyDynamicObject(aksesoris_yosmite_patwal8);
                        DestroyDynamicObject(aksesoris_yosmite_patwal9);
                        DestroyDynamicObject(aksesoris_yosmite_patwal10);
                        DestroyDynamicObject(aksesoris_yosmite_patwal11);
                        DestroyDynamicObject(aksesoris_yosmite_patwal12);
                        DestroyDynamicObject(aksesoris_yosmite_patwal13);
                        DestroyDynamicObject(aksesoris_yosmite_patwal14);
                        DestroyDynamicObject(aksesoris_yosmite_patwal15);
                        DestroyDynamicObject(aksesoris_yosmite_patwal16);
                        DestroyDynamicObject(aksesoris_yosmite_patwal17);
                        DestroyDynamicObject(aksesoris_yosmite_patwal18);
                        DestroyDynamicObject(aksesoris_yosmite_patwal19);
                        DestroyDynamicObject(aksesoris_yosmite_patwal20);
                        DestroyDynamicObject(aksesoris_yosmite_patwal21);
                        DestroyDynamicObject(aksesoris_yosmite_patwal22);
                        DestroyDynamicObject(aksesoris_yosmite_patwal23);
                        DestroyDynamicObject(aksesoris_yosmite_patwal24);
                        DestroyDynamicObject(aksesoris_yosmite_patwal25);
                        DestroyDynamicObject(aksesoris_yosmite_patwal26);       

                        DestroyDynamicObject(aksesoris_sultan_satlantas1);
                        DestroyDynamicObject(aksesoris_sultan_satlantas2);
                        DestroyDynamicObject(aksesoris_sultan_satlantas3);
                        DestroyDynamicObject(aksesoris_sultan_satlantas4);
                        DestroyDynamicObject(aksesoris_sultan_satlantas5);
                        DestroyDynamicObject(aksesoris_sultan_satlantas6);
                        DestroyDynamicObject(aksesoris_sultan_satlantas7);
                        DestroyDynamicObject(aksesoris_sultan_satlantas8);
                        DestroyDynamicObject(aksesoris_sultan_satlantas9);
                        DestroyDynamicObject(aksesoris_sultan_satlantas10);
                        DestroyDynamicObject(aksesoris_sultan_satlantas11);
                        DestroyDynamicObject(aksesoris_sultan_satlantas12);
                        DestroyDynamicObject(aksesoris_sultan_satlantas13);
                        DestroyDynamicObject(aksesoris_sultan_satlantas14);
                        DestroyDynamicObject(aksesoris_sultan_satlantas15);
                        DestroyDynamicObject(aksesoris_sultan_satlantas16);
                        DestroyDynamicObject(aksesoris_sultan_satlantas17);
                        DestroyDynamicObject(aksesoris_sultan_satlantas18);
                        DestroyDynamicObject(aksesoris_sultan_satlantas19);
                        DestroyDynamicObject(aksesoris_sultan_satlantas20);
                        DestroyDynamicObject(aksesoris_sultan_satlantas21);
                        DestroyDynamicObject(aksesoris_sultan_satlantas22);
                        DestroyDynamicObject(aksesoris_sultan_satlantas23);
                        DestroyDynamicObject(aksesoris_sultan_satlantas24);
                        DestroyDynamicObject(aksesoris_sultan_satlantas25);  

                        DestroyDynamicObject(aksesoris_sultan_sabhara1);
                        DestroyDynamicObject(aksesoris_sultan_sabhara2);
                        DestroyDynamicObject(aksesoris_sultan_sabhara3);
                        DestroyDynamicObject(aksesoris_sultan_sabhara4);
                        DestroyDynamicObject(aksesoris_sultan_sabhara5);
                        DestroyDynamicObject(aksesoris_sultan_sabhara6);
                        DestroyDynamicObject(aksesoris_sultan_sabhara7);
                        DestroyDynamicObject(aksesoris_sultan_sabhara8);
                        DestroyDynamicObject(aksesoris_sultan_sabhara9);
                        DestroyDynamicObject(aksesoris_sultan_sabhara10);
                        DestroyDynamicObject(aksesoris_sultan_sabhara11);
                        DestroyDynamicObject(aksesoris_sultan_sabhara12);
                        DestroyDynamicObject(aksesoris_sultan_sabhara13);
                        DestroyDynamicObject(aksesoris_sultan_sabhara14);
                        DestroyDynamicObject(aksesoris_sultan_sabhara15);
                        DestroyDynamicObject(aksesoris_sultan_sabhara16);
                        DestroyDynamicObject(aksesoris_sultan_sabhara17);
                        DestroyDynamicObject(aksesoris_sultan_sabhara18);
                        DestroyDynamicObject(aksesoris_sultan_sabhara19);
                        DestroyDynamicObject(aksesoris_sultan_sabhara20);
                        DestroyDynamicObject(aksesoris_sultan_sabhara21);
                        DestroyDynamicObject(aksesoris_sultan_sabhara22);                                                       
                        DestroyVehicle(GetPlayerVehicleID(playerid));
                    }
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, PolisiVars[MenuGarasi]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    Dialog_Show(playerid, DIALOG_GARASIKANPOL, DIALOG_STYLE_LIST, ""GREY_E"Garasi Kepolisian", "Sanchez Sabhara\nYosmite Sabhara\nYosmite Patwal\nSultan Satlantas\nSultan Sabhara\nSanchez Satlantas", "Pilih", "Batalkan");
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, PolisiVars[BossTable]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    if(pData[playerid][pFactionRank] < 13)
                        return ErrorMsg(playerid, "Anda bukan perwira tinggi");

                    Dialog_Show(playerid, DIALOG_JENDRALTABLE, DIALOG_STYLE_LIST, ""GREY_E"Jendral Table", "Invite Anggota\nDaftar Anggota Online", "Pilih", "Batalkan");
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, PolisiVars[PerlengkapanArea]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    if(pData[playerid][pFactionRank] < 10)
                        return ErrorMsg(playerid, "Anda bukan perwira tinggi");                    
                    new str[900];
                    format(str, sizeof(str), 
                    "Nama Perlengkapan\t:\tDeskripsi\nMP5\t-\tMendapatkan Peluru Sebanyak 270\nM4\t-\tMendapatkan Peluru Sebanyak 300\nShotgun\t-\tMendapatkan Peluru Sebanyak 100\nCombat Shotgun\t-\tMendapatkan Peluru Sebanyak 150\nDesert Eagle\t-\tMendapatkan Peluru Sebanyak 250\nKevlar\t-\tMendapatkan Kevlar Sebanyak 3\n");
                    Dialog_Show(playerid, DIALOG_LOKPOLIS, DIALOG_STYLE_TABLIST_HEADERS, ""GREY_E"Polisi >> Perlengkapan Polisi", str, "Pilih", "Batalkan");    
                }
            }
        }        
        if(IsPlayerInDynamicArea(playerid, PolisiVars[LokerArea]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    Dialog_Show(playerid, DIALOG_LOKERPOLISI, DIALOG_STYLE_LIST, ""GREY_E"Polisi >> Loker Polisi", "Satlantas\nSabhara\nJendral\nSatlantas 2\nBrimob\nJendral 2\nSabhara 2", "Pilih", "Batalkan");
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, PolisiVars[DutyArea]))
        {
            if(pData[playerid][pFaction] == 1)
            {
                if(!pData[playerid][pOnDuty])
                {
                    pData[playerid][pOnDuty] = 1;
                    //ScoreboardVars[CountPolisi]++;
                    foreach(new i : Player) if(IsPlayerConnected(i) && i != playerid)
                    {
                        if(pData[i][pFaction] == 1)
                        {
                            if(pData[i][pOnDuty])
                            {
                                SetPlayerMarkerForPlayer(i, playerid, COLOR_BLUE);
                            }
                        }
                    }                    
                    InfoMsg(playerid, "Anda telah OnDuty menjadi Polisi");
                }
                else
                {
					pData[playerid][pOnDuty] = 0;
                    //ScoreboardVars[CountPolisi]--;
					SetPlayerSkin(playerid, pData[playerid][pSkin]);
                    foreach(new i : Player) if(IsPlayerConnected(i) && i != playerid)
                    {
                        if(pData[i][pFaction] == 1)
                        {
                            if(pData[i][pOnDuty])
                            {
                                SetPlayerMarkerForPlayer(i, playerid, -1);
                            }
                        }
                    }                       
					InfoMsg(playerid, "Anda telah Offduty menjadi Polisi");
                }
            }
        }
    }
    return 1;
}

CMD:pol(playerid, params[])
{
    if(pData[playerid][pFaction] == 1)
    {
        new stringpol[512];
        if(isnull(params)) return Usage(playerid,"/pol [pesan]");
        format(stringpol, sizeof(stringpol), "{0080FF}POLISI | %s: {FFFFFF}%s", GetName(playerid), params);
        SendClientMessageToAll(COLOR_YELLOW,stringpol);
        return 1;
    }
    else
    {
        ErrorMsg(playerid, "Anda bukan anggota Kepolisian.");
    }
    return 1;
}   

Dialog:DIALOG_GARASIKANPOL(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            carvid = CreateVehicle(468,1757.296752, -1777.894531, 13.528462, 357.948516,61,0,-1,1);

            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            SetVehicleFuel(carvid, 100);
            ////SetVehicleEngineState(carvid, 1);            
            aksesoris_sanchez_sabhara1 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara1, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara1, carvid, 0.000, -0.960, 0.230, 0.000, 90.000, 0.000);
            aksesoris_sanchez_sabhara2 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara2, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_sabhara2, 0, "{E69C3C} POLISI", 100, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara2, carvid, -0.010, -0.970, 0.250, -0.099, 360.000, 0.000);
            aksesoris_sanchez_sabhara3 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara3, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_sabhara3, 0, "{E69C3C} ____", 60, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara3, carvid, -0.010, -0.970, 0.260, 0.000, 0.000, 0.000);
            aksesoris_sanchez_sabhara4 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara4, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_sabhara4, 0, "{E69C3C} SABHARA", 100, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara4, carvid, -0.010, -0.970, 0.200, 0.000, 0.000, 0.000);
            aksesoris_sanchez_sabhara5 = CreateDynamicObject(19483,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara5, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_sabhara5, 0, "{FFFFFF} POLISI", 130, "Arial", 15, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara5, carvid, 0.168, 0.270, 0.240, 41.699, -12.700, 0.000);
            aksesoris_sanchez_sabhara6 = CreateDynamicObject(19483,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara6, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_sabhara6, 0, "{FFFFFF} POLISI", 130, "Arial", 15, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara6, carvid, -0.176, 0.300, 0.252, -43.510, -35.080, 171.500);
            aksesoris_sanchez_sabhara7 = CreateDynamicObject(1898,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara7, 0, 1560, "7_11_door", "CJ_CHROME2", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara7, carvid, -0.060, -0.890, 0.280, 0.039, 90.030, 0.000);
            aksesoris_sanchez_sabhara8 = CreateDynamicObject(1898,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara8, 0, 1560, "7_11_door", "CJ_CHROME2", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara8, carvid, 0.050, -0.890, 0.260, 540.000, 450.000, 180.000);
            aksesoris_sanchez_sabhara9 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara9, 0, 18646, "matcolours", "orange", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara9, carvid, 0.190, -0.919, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_sabhara10 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara10, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara10, carvid, 0.190, -0.909, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_sabhara11 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara11, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara11, carvid, -0.180, -0.919, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_sabhara12 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_sabhara12, 0, 18646, "matcolours", "orange", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_sabhara12, carvid, -0.180, -0.929, 0.290, 0.000, 90.000, 90.000);
        }
        if(listitem == 1)
        {
            carvid = CreateVehicle(554,1757.296752, -1777.894531, 13.528462, 357.948516,1,61,-1,1);
            SetVehicleFuel(carvid, 100);
            AddVehicleComponent(carvid, 1010);
            ////SetVehicleEngineState(carvid, 1);                      
            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            aksesoris_yosmite_sabhara1 = CreateDynamicObject(19419,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara1, 0, 10765, "airportgnd_sfse", "white", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara1, carvid, 0.000, 0.000, 0.999, 0.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara2 = CreateDynamicObject(19348,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara2, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara2, carvid, 1.100, -0.443, 0.206, -4.199, 0.000, 0.000);
            aksesoris_yosmite_sabhara3 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara3, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara3, carvid, 0.000, 2.711, -0.330, 90.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara4 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara4, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara4, 0, "{FFC300} SABHARA", 130, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara4, carvid, -0.090, 2.729, -0.360, 0.000, 360.000, 450.000);
            aksesoris_yosmite_sabhara5 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara5, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara5, 0, "{FFC300} ________", 120, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara5, carvid, -0.090, 2.729, -0.310, 0.000, 360.000, 90.000);
            aksesoris_yosmite_sabhara6 = CreateDynamicObject(19775,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara6, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara6, carvid, 0.109, 2.731, -0.320, 0.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara7 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara7, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara7, 0, "{000000} POLISI", 140, "Arial", 55, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara7, carvid, 1.220, -0.201, 0.080, 0.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara8 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara8, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara8, 0, "{000000} KOTA Konoha", 140, "Arial", 24, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara8, carvid, 1.220, -0.131, -0.100, 0.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara9 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara9, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara9, 0, "{000000} POLISI", 140, "Arial", 55, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara9, carvid, -1.250, -0.041, 0.080, 0.000, 0.000, 180.000);
            aksesoris_yosmite_sabhara10 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara10, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara10, 0, "{000000} KOTA Konoha", 140, "Arial", 24, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara10, carvid, -1.239, -0.111, -0.100, 0.000, 0.000, 180.000);
            aksesoris_yosmite_sabhara11 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara11, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara11, 0, "{000000} POLISI", 140, "Arial", 55, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara11, carvid, 0.040, 1.647, 0.430, 180.000, 91.199, 630.000);
            aksesoris_yosmite_sabhara12 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara12, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara12, 0, "{000000} KOTA Konoha", 140, "Arial", 25, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara12, carvid, -0.049, 1.888, 0.420, 180.000, 91.099, 270.000);
            aksesoris_yosmite_sabhara13 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara13, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara13, 0, "{000000} POLISI", 140, "Arial", 55, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara13, carvid, -0.099, -2.913, 0.080, 0.000, 0.000, 270.000);
            aksesoris_yosmite_sabhara14 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara14, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara14, 0, "{FFC300} POLISI", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara14, carvid, -0.080, 2.729, -0.300, 0.000, 0.000, 450.000);
            aksesoris_yosmite_sabhara15 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara15, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara15, carvid, 0.000, -2.996, -0.349, 90.699, 720.000, 360.000);
            aksesoris_yosmite_sabhara16 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara16, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara16, 0, "{FFC300} POLISI", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara16, carvid, -0.010, -3.012, -0.340, 180.000, 180.000, 90.000);
            aksesoris_yosmite_sabhara17 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara17, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara17, 0, "{FFC300} _______", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara17, carvid, -0.010, -3.012, -0.350, 0.000, 0.000, 270.000);
            aksesoris_yosmite_sabhara18 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara18, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_sabhara18, 0, "{FFC300} SABHARA", 130, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara18, carvid, -0.010, -3.012, -0.390, 0.000, 0.000, 270.000);
            aksesoris_yosmite_sabhara19 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara19, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara19, carvid, 0.580, 0.130, 1.040, 90.000, 360.000, 0.000);
            aksesoris_yosmite_sabhara20 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara20, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara20, carvid, 0.140, 0.130, 1.040, 90.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara21 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara21, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara21, carvid, -0.320, 0.130, 1.040, 450.000, 0.000, 0.000);
            aksesoris_yosmite_sabhara22 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_sabhara22, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_sabhara22, carvid, -0.590, 0.130, 1.040, 90.000, 0.000, 0.000);
        }
        if(listitem == 2)
        {
            
            carvid = CreateVehicle(554,1757.296752, -1777.894531, 13.528462, 357.948516,1,1,-1,1);
            SetVehicleFuel(carvid, 100);
            AddVehicleComponent(carvid, 1010);
            //SetVehicleEngineState(carvid, 1);                      
            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            aksesoris_yosmite_patwal1 = CreateDynamicObject(19419,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal1, 0, 10765, "airportgnd_sfse", "white", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal1, carvid, 0.000, 0.000, 0.999, 0.000, 0.000, 0.000);
            aksesoris_yosmite_patwal2 = CreateDynamicObject(19348,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal2, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal2, carvid, 1.100, -0.443, 0.206, -4.199, 0.000, 0.000);
            aksesoris_yosmite_patwal3 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal3, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal3, carvid, 0.000, 2.711, -0.330, 90.000, 0.000, 0.000);
            aksesoris_yosmite_patwal4 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal4, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal4, 0, "{FFC300} SATLANTAS", 130, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal4, carvid, -0.090, 2.729, -0.360, 0.000, 360.000, 450.000);
            aksesoris_yosmite_patwal5 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal5, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal5, 0, "{FFC300} ________", 120, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal5, carvid, -0.090, 2.729, -0.310, 0.000, 360.000, 90.000);
            aksesoris_yosmite_patwal6 = CreateDynamicObject(19775,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal6, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal6, carvid, 0.109, 2.731, -0.320, 0.000, 0.000, 0.000);
            aksesoris_yosmite_patwal7 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal7, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal7, 0, "{0000CD} PATWAL", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal7, carvid, 1.220, -0.201, 0.080, 0.000, 0.000, 0.000);
            aksesoris_yosmite_patwal8 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal8, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal8, 0, "{0000CD} KOTA Konoha", 140, "Arial", 24, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal8, carvid, 1.220, -0.131, -0.100, 0.000, 0.000, 0.000);
            aksesoris_yosmite_patwal9 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal9, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal9, 0, "{0000CD} PATWAL", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal9, carvid, -1.250, -0.041, 0.080, 0.000, 0.000, 180.000);
            aksesoris_yosmite_patwal10 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal10, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal10, 0, "{0000CD} KOTA Konoha", 140, "Arial", 24, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal10, carvid, -1.239, -0.111, -0.100, 0.000, 0.000, 180.000);
            aksesoris_yosmite_patwal11 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal11, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal11, 0, "{FFFFFF} PATWAL", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal11, carvid, -0.019, 1.828, 0.436, 180.000, 91.199, 630.000);
            aksesoris_yosmite_patwal12 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal12, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal12, 0, "{FFFFFF} KOTA Konoha", 140, "Arial", 25, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal12, carvid, -0.049, 1.998, 0.417, 180.000, 91.099, 270.000);
            aksesoris_yosmite_patwal13 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal13, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal13, 0, "{FFFFFF} POLISI", 140, "Arial", 55, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal13, carvid, -0.099, -2.913, 0.080, 0.000, 0.000, 270.000);
            aksesoris_yosmite_patwal14 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal14, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal14, 0, "{FFC300} POLISI", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal14, carvid, -0.080, 2.729, -0.300, 0.000, 0.000, 450.000);
            aksesoris_yosmite_patwal15 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal15, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal15, carvid, 0.000, -2.996, -0.349, 90.699, 720.000, 360.000);
            aksesoris_yosmite_patwal16 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal16, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal16, 0, "{FFC300} POLISI", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal16, carvid, -0.010, -3.012, -0.340, 180.000, 180.000, 90.000);
            aksesoris_yosmite_patwal17 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal17, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal17, 0, "{FFC300} _______", 130, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal17, carvid, -0.010, -3.012, -0.350, 0.000, 0.000, 270.000);
            aksesoris_yosmite_patwal18 = CreateDynamicObject(19476,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal18, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_yosmite_patwal18, 0, "{FFC300} SATLANTAS", 130, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal18, carvid, -0.010, -3.012, -0.390, 0.000, 0.000, 270.000);
            aksesoris_yosmite_patwal19 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal19, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal19, carvid, 0.580, 0.130, 1.040, 90.000, 360.000, 0.000);
            aksesoris_yosmite_patwal20 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal20, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal20, carvid, 0.140, 0.130, 1.040, 90.000, 0.000, 0.000);
            aksesoris_yosmite_patwal21 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal21, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal21, carvid, -0.320, 0.130, 1.040, 450.000, 0.000, 0.000);
            aksesoris_yosmite_patwal22 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal22, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal22, carvid, -0.590, 0.130, 1.040, 90.000, 0.000, 0.000);
            aksesoris_yosmite_patwal23 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal23, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal23, carvid, -0.520, 1.886, 0.437, -95.299, 360.000, 0.000);
            aksesoris_yosmite_patwal24 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal24, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal24, carvid, 0.470, 1.886, 0.437, -94.699, 360.000, 0.000);
            aksesoris_yosmite_patwal25 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal25, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal25, carvid, -0.410, -2.925, 0.057, 360.000, 0.000, 0.000);
            aksesoris_yosmite_patwal26 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_yosmite_patwal26, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_yosmite_patwal26, carvid, 0.410, -2.925, 0.057, 0.000, 0.000, 0.000);
        }
        if(listitem == 3)
        {
            carvid = CreateVehicle(560,1757.296752, -1777.894531, 13.528462, 357.948516,1,1,-1,1);
            SetVehicleFuel(carvid, 100);
            AddVehicleComponent(carvid, 1010);
            //SetVehicleEngineState(carvid, 1);                      
            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            aksesoris_sultan_satlantas1 = CreateDynamicObject(19419,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas1, 0, 10765, "airportgnd_sfse", "white", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas1, carvid, 0.000, -0.090, 0.849, 0.000, 0.000, 0.000);
            aksesoris_sultan_satlantas2 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas2, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas2, carvid, 0.570, -0.230, 0.890, 90.000, 90.000, 90.000);
            aksesoris_sultan_satlantas3 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas3, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas3, carvid, 0.160, -0.230, 0.890, 90.000, 90.000, 90.000);
            aksesoris_sultan_satlantas4 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas4, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas4, carvid, -0.220, -0.230, 0.890, 270.000, 0.000, 0.000);
            aksesoris_sultan_satlantas5 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas5, 0, 18901, "matclothes", "darkblue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas5, carvid, -0.570, -0.230, 0.890, 270.000, 0.000, 0.000);
            aksesoris_sultan_satlantas6 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas6, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas6, carvid, 0.000, -2.421, -0.140, 90.000, 360.000, 0.000);
            aksesoris_sultan_satlantas7 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas7, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas7, carvid, -0.628, 2.663, -0.190, 90.000, -173.299, 0.000);
            aksesoris_sultan_satlantas8 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas8, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas8, 0, "{FFC300} POLISI", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas8, carvid, -0.672, 2.678, -0.160, 0.000, 0.000, 97.599);
            aksesoris_sultan_satlantas9 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas9, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas9, 0, "{FFC300} _____", 60, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas9, carvid, -0.672, 2.678, -0.150, 0.000, 0.000, 97.499);
            aksesoris_sultan_satlantas10 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas10, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas10, 0, "{FFC300} SATLANTAS", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas10, carvid, -0.672, 2.678, -0.230, 0.000, 0.000, 95.499);
            aksesoris_sultan_satlantas11 = CreateDynamicObject(19774,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas11, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas11, carvid, -0.500, 2.689, -0.190, 0.000, 0.000, 3.099);
            aksesoris_sultan_satlantas12 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas12, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas12, 0, "{FFC300} _____", 60, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas12, carvid, 0.078, -2.441, -0.100, 0.000, 0.000, 90.000);
            aksesoris_sultan_satlantas13 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas13, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas13, 0, "{FFC300} POLISI", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas13, carvid, 0.068, -2.442, -0.110, 0.000, 0.000, 270.000);
            aksesoris_sultan_satlantas14 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas14, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas14, 0, "{FFC300} SATLANTAS", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas14, carvid, 0.068, -2.442, -0.170, 0.000, 0.000, 270.000);
            aksesoris_sultan_satlantas15 = CreateDynamicObject(19774,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas15, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas15, carvid, -0.140, -2.440, -0.140, 0.000, 0.000, 0.000);
            aksesoris_sultan_satlantas16 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas16, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas16, 0, "{FFFFFF} PATWAL", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas16, carvid, 0.040, 1.905, 0.310, 1620.000, 100.799, 270.000);
            aksesoris_sultan_satlantas17 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas17, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas17, 0, "{FFFFFF} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas17, carvid, 0.000, 2.085, 0.300, 900.000, 90.000, 630.000);
            aksesoris_sultan_satlantas18 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas18, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas18, 0, "{0000CD} PATWAL", 140, "Arial", 35, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas18, carvid, -1.066, 0.025, 0.069, 0.000, -5.800, 180.000);
            aksesoris_sultan_satlantas19 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas19, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas19, 0, "{0000CD} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas19, carvid, -1.061, 0.006, -0.069, 0.000, 0.000, 180.000);
            aksesoris_sultan_satlantas20 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas20, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas20, 0, "{0000CD} PATWAL", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas20, carvid, 1.059, -0.154, 0.114, 0.000, -7.399, 360.000);
            aksesoris_sultan_satlantas21 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas21, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas21, 0, "{0000CD} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas21, carvid, 1.051, -0.153, -0.069, 0.000, 0.000, 0.000);
            aksesoris_sultan_satlantas22 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas22, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_satlantas22, 0, "{FFFFFF} POLISI", 140, "Arial", 25, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas22, carvid, -0.019, -2.064, 0.406, 180.010, 448.000, 90.000);
            aksesoris_sultan_satlantas23 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas23, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas23, carvid, 0.393, 1.939, 0.322, -98.000, -177.600, 2.199);
            aksesoris_sultan_satlantas24 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas24, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas24, carvid, -0.367, 1.929, 0.323, -97.300, 0.000, 0.000);
            aksesoris_sultan_satlantas25 = CreateDynamicObject(2661,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_satlantas25, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_satlantas25, carvid, -0.026, -2.033, 0.403, -85.100, 360.000, 0.000);            
        }
        if(listitem == 4)
        {
            carvid = CreateVehicle(560,1757.296752, -1777.894531, 13.528462, 357.948516,61,1,-1,0);
            SetVehicleFuel(carvid, 100);
            AddVehicleComponent(carvid, 1010);
            //SetVehicleEngineState(carvid, 1);                      
            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            aksesoris_sultan_sabhara1 = CreateDynamicObject(19419,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara1, 0, 10765, "airportgnd_sfse", "white", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara1, carvid, 0.000, -0.090, 0.849, 0.000, 0.000, 0.000);
            aksesoris_sultan_sabhara2 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara2, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara2, carvid, 0.570, -0.230, 0.890, 90.000, 90.000, 90.000);
            aksesoris_sultan_sabhara3 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara3, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara3, carvid, 0.160, -0.230, 0.890, 90.000, 90.000, 90.000);
            aksesoris_sultan_sabhara4 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara4, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara4, carvid, -0.220, -0.230, 0.890, 270.000, 0.000, 0.000);
            aksesoris_sultan_sabhara5 = CreateDynamicObject(19566,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara5, 0, 18646, "matcolours", "blue", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara5, carvid, -0.570, -0.230, 0.890, 270.000, 0.000, 0.000);
            aksesoris_sultan_sabhara6 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara6, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara6, carvid, 0.000, -2.421, -0.140, 90.000, 360.000, 0.000);
            aksesoris_sultan_sabhara7 = CreateDynamicObject(19808,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara7, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara7, carvid, -0.628, 2.663, -0.190, 90.000, -173.299, 0.000);
            aksesoris_sultan_sabhara8 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara8, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara8, 0, "{FFC300} POLISI", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara8, carvid, -0.672, 2.678, -0.160, 0.000, 0.000, 97.599);
            aksesoris_sultan_sabhara9 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara9, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara9, 0, "{FFC300} _____", 60, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara9, carvid, -0.672, 2.678, -0.150, 0.000, 0.000, 97.499);
            aksesoris_sultan_sabhara10 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara10, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara10, 0, "{FFC300} SABHARA", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara10, carvid, -0.672, 2.678, -0.230, 0.000, 0.000, 95.499);
            aksesoris_sultan_sabhara11 = CreateDynamicObject(19774,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara11, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara11, carvid, -0.500, 2.689, -0.190, 0.000, 0.000, 3.099);
            aksesoris_sultan_sabhara12 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara12, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara12, 0, "{FFC300} _____", 60, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara12, carvid, 0.108, -2.441, -0.100, 0.000, 0.000, 90.000);
            aksesoris_sultan_sabhara13 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara13, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara13, 0, "{FFC300} POLISI", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara13, carvid, 0.098, -2.442, -0.110, 0.000, 0.000, 270.000);
            aksesoris_sultan_sabhara14 = CreateDynamicObject(19475,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara14, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara14, 0, "{FFC300} SABHARA", 100, "Arial", 30, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara14, carvid, 0.098, -2.442, -0.170, 0.000, 0.000, 270.000);
            aksesoris_sultan_sabhara15 = CreateDynamicObject(19774,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara15, 0, 5168, "lashops6_las2", "yellow2_128", 0);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara15, carvid, -0.090, -2.440, -0.139, 0.000, 0.000, 0.000);
            aksesoris_sultan_sabhara16 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara16, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara16, 0, "{000000} POLISI", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara16, carvid, 0.040, 1.905, 0.310, 1620.000, 100.799, 270.000);
            aksesoris_sultan_sabhara17 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara17, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara17, 0, "{000000} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara17, carvid, 0.000, 2.085, 0.280, 900.000, 90.000, 630.000);
            aksesoris_sultan_sabhara18 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara18, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara18, 0, "{000000} POLISI", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara18, carvid, -1.060, 0.025, 0.129, 0.000, -5.800, 180.000);
            aksesoris_sultan_sabhara19 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara19, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara19, 0, "{000000} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara19, carvid, -1.061, 0.006, -0.069, 0.000, 0.000, 180.000);
            aksesoris_sultan_sabhara20 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara20, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara20, 0, "{000000} POLISI", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara20, carvid, 1.049, -0.184, 0.113, 0.000, -7.399, 360.000);
            aksesoris_sultan_sabhara21 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara21, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara21, 0, "{000000} KOTA Konoha", 140, "Arial", 20, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara21, carvid, 1.051, -0.153, -0.069, 0.000, 0.000, 0.000);
            aksesoris_sultan_sabhara22 = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sultan_sabhara22, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sultan_sabhara22, 0, "{000000} POLISI", 140, "Arial", 45, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sultan_sabhara22, carvid, -0.069, -1.995, 0.383, 180.010, 448.000, 90.000);
        }
        if(listitem == 5)
        {
            carvid = CreateVehicle(468,1757.296752, -1777.894531, 13.528462, 357.948516,1,53,-1,1);
            SetVehicleFuel(carvid, 100);
            //SetVehicleEngineState(carvid, 1);                      
            SetVehicleVirtualWorld(carvid, 0);
            LinkVehicleToInterior(carvid, 0);
            aksesoris_sanchez_satlantas1 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas1, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas1, carvid, 0.000, -0.960, 0.230, 0.000, 90.000, 0.000);
            aksesoris_sanchez_satlantas2 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas2, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_satlantas2, 0, "{E69C3C} POLISI", 100, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas2, carvid, -0.010, -0.970, 0.250, -0.099, 360.000, 0.000);
            aksesoris_sanchez_satlantas3 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas3, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_satlantas3, 0, "{E69C3C} ____", 60, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas3, carvid, -0.010, -0.970, 0.260, 0.000, 0.000, 0.000);
            aksesoris_sanchez_satlantas4 = CreateDynamicObject(19827,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas4, 0, 10765, "airportgnd_sfse", "black64", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_satlantas4, 0, "{FFC300} SATLANTAS", 100, "Arial", 50, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas4, carvid, -0.010, -0.970, 0.200, 0.000, 0.000, 0.000);
            aksesoris_sanchez_satlantas5 = CreateDynamicObject(19483,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas5, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_satlantas5, 0, "{0000CD} PATWAL", 130, "Arial", 15, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas5, carvid, 0.168, 0.270, 0.240, 41.699, -12.700, 0.000);
            aksesoris_sanchez_satlantas6 = CreateDynamicObject(19483,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas6, 0, 10101, "2notherbuildsfe", "ferry_build14", 0);
            SetDynamicObjectMaterialText(aksesoris_sanchez_satlantas6, 0, "{0000CD} PATWAL", 130, "Arial", 15, 1, 0, 0, 1);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas6, carvid, -0.180, 0.306, 0.246, -43.510, 324.919, 171.500);
            aksesoris_sanchez_satlantas7 = CreateDynamicObject(1898,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas7, 0, 1560, "7_11_door", "CJ_CHROME2", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas7, carvid, -0.060, -0.890, 0.280, 0.039, 90.030, 0.000);
            aksesoris_sanchez_satlantas8 = CreateDynamicObject(1898,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas8, 0, 1560, "7_11_door", "CJ_CHROME2", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas8, carvid, 0.050, -0.890, 0.260, 540.000, 450.000, 180.000);
            aksesoris_sanchez_satlantas9 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas9, 0, 18646, "matcolours", "orange", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas9, carvid, 0.190, -0.919, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_satlantas10 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas10, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas10, carvid, 0.190, -0.909, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_satlantas11 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas11, 0, 10765, "airportgnd_sfse", "black64", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas11, carvid, -0.180, -0.919, 0.290, 0.000, 90.000, 90.000);
            aksesoris_sanchez_satlantas12 = CreateDynamicObject(1927,0.0,0.0,-1000.0,0.0,0.0,0.0,0,0,-1,300.0,300.0);
            SetDynamicObjectMaterial(aksesoris_sanchez_satlantas12, 0, 18646, "matcolours", "orange", 0);
            AttachDynamicObjectToVehicle(aksesoris_sanchez_satlantas12, carvid, -0.180, -0.929, 0.290, 0.000, 90.000, 90.000);
        }

    }
    return 1;
}

Dialog:DIALOG_JENDRALTABLE(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			Dialog_Show(playerid, DIALOG_POLISIINVITE, DIALOG_STYLE_INPUT, "Invite Anggota Polisi", "Masukan Kantong Yang Ingin Anda Jadikan Polisi", "Masukan", "Batalkan");
		}
		if(listitem == 1)
		{
			new lstr[1024];
			format(lstr, sizeof(lstr), "Nama\tPangkat\n");
			foreach(new i: Player)
			{
				if(pData[i][pFaction] == 1)
				{
					format(lstr, sizeof(lstr), "%s%s\t%s (%d)", lstr, pData[i][pName], PangkatPolisi(i), pData[i][pFactionRank]);
					format(lstr, sizeof(lstr), "%s\n", lstr);						
				}
			}
			Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_TABLIST_HEADERS, "List Online Anggota - Polisi", lstr, "Tutup", "");				
		}			      
    }
    return 1;
}

Dialog:DIALOG_POLISIINVITE(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		new otherid = strval(inputtext);
		if(!IsPlayerNearPlayer(playerid, otherid, 3.0))
			return ErrorMsg(playerid, "You're not close to that player!");				
		if(!IsPlayerConnected(otherid))
			return ErrorMsg(playerid, "Player belum masuk!");		

        if (AccountData[otherid][pFaction] == AccountData[otherid][pFaction])
            return ErrorMsg(playerid, "Pemain itu sudah menjadi bagian dari faction lain");	

        if (AccountData[otherid][pFaction] != -1)
            return ErrorMsg(playerid, "Pemain itu sudah menjadi bagian dari faction lain");	  

        if(AccountData[otherid][pOnDuty])   
            return ErrorMsg(playerid, "Pemain ini sedang dalam duty faction");                 		
		pData[playerid][pTarget] = otherid;
		Dialog_Show(playerid, DIALOG_POLISIRANK, DIALOG_STYLE_INPUT, "Invite Anggota Polisi", "Masukan Rank Yang Ingin Anda Berikan", "Masukan", "Batalkan");     
    }
    return 1;
}

Dialog:DIALOG_POLISIRANK(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		new rank = strval(inputtext);
		if(!IsPlayerNearPlayer(playerid, pData[playerid][pTarget], 3.0))
			return ErrorMsg(playerid, "You're not close to that player!");				
		if(!IsPlayerConnected(pData[playerid][pTarget]))
			return ErrorMsg(playerid, "Player belum masuk!");		
		pData[pData[playerid][pTarget]][pFaction] = 1;
		pData[pData[playerid][pTarget]][pFactionRank] = rank;
		SuccesMsg(playerid, "Anda berhasil menambahkan Anggota baru");
		SuccesMsg(pData[playerid][pTarget], "Kamu telah bergabung dalam Fraksi Polisi");    
    }
    return 1;
}

Dialog:DIALOG_RADIALPOLISI(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			foreach(new ix : Player) if(IsPlayerConnected(ix) && NearPlayer(playerid, ix, 1.5) && ix != playerid)
			{
				pData[playerid][pTarget] = ix;
				new
					amounts[MAX_INVENTORY],
					str[512],
					string[256];

				format(str, sizeof(str), "Name\t:\tAmount\n"LG_E"Money\t-\t"LG_E"%s", FormatMoney(pData[ix][pMoney]));
				forex(i, MAX_INVENTORY)
				{
					if(InventoryData[ix][i][invExists])
					{
						amounts[i] = InventoryData[ix][i][invQuantity];
						strunpack(string, InventoryData[ix][i][invItem]);
						format(str, sizeof(str), "%s\n{FFFFFF}%s\t-\t%d\n", str, string, amounts[i]);
					}
				}
				Dialog_Show(playerid, DIALOG_AFRISK, DIALOG_STYLE_TABLIST_HEADERS, ""GREY_E"Polisi >> Geledah", str, "Pilih", "Batalkan");	
			}
		}
		if(listitem == 1)
		{
			new str[500], count = 0;				
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
			{
				format(str, sizeof(str), "[%d]\n", i);
				SetPlayerListitemValue(playerid, count++, i);
			}
			if(!count) ErrorMsg(playerid, "Tidak ada orang didekat mu");
			else Dialog_Show(playerid, DIALOG_JUMLAHINVOICE, DIALOG_STYLE_LIST, ""GREY_E"Polisi >> Kasih Invoice", str, "Pilih", "Batalkan");
		}
		if(listitem == 2)
		{
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.0) && i != playerid)
			{
				if(pData[i][pCuffed])
					return ErrorMsg(playerid, "The player is already cuffed at the moment.");

				pData[i][pCuffed] = true;
				SetPlayerSpecialAction(i, SPECIAL_ACTION_CUFFED);
				for(new ix=MAX_PLAYER_ATTACHED_OBJECTS-1; ix!=0; ix--)
				{
					if(!IsPlayerAttachedObjectSlotUsed(i, ix))
					{
						SetPlayerArmedWeapon(i, 0);
						SetPVarInt(i, "Cuff_Index", i);
						SetPlayerAttachedObject(i, ix, 19418, 6, -0.027999, 0.051999, -0.030000, -18.699926, 0.000000, 104.199928, 1.489999, 3.036000, 1.957999);
						return 1;
					}
				}
			}
		}	
		if(listitem == 3)
		{
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.0) && i != playerid)
			{
				if(!pData[i][pCuffed])
					return Error(playerid, "The player is not cuffed at the moment.");

				pData[i][pCuffed] = false;
				SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);
				RemovePlayerAttachedObject(i, GetPVarInt(i, "Cuff_Index"));
				SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);
			}
		}		  
    }
    return 1;
}

Dialog:DIALOG_LOKERPOLISI(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 281);
				SetFactionSkin(playerid, 281);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}
		}
		if(listitem == 1)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 282);
				SetFactionSkin(playerid, 282);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}
		if(listitem == 2)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 283);
				SetFactionSkin(playerid, 283);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}
		if(listitem == 3)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 284);
				SetFactionSkin(playerid, 283);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}
		if(listitem == 4)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 285);
				SetFactionSkin(playerid, 285);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}			
		if(listitem == 5)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 288);
				SetFactionSkin(playerid, 288);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}				
		if(listitem == 6)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 311);
				SetFactionSkin(playerid, 311);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 211);
				SetFactionSkin(playerid, 211);
			}				
		}											
    }
    return 1;
}

stock SetFactionSkin(playerid, model)
{
	SetPlayerSkin(playerid, model);
	AccountData[playerid][pFacSkin] = model;
}

Dialog:DIALOG_LOKPOLIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			GivePlayerWeaponEx(playerid, 29, 270);
			ShowItemBox(playerid, "MP5", "Recived_270x", 353, 3);
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil senjata MP5 sebanyak 270x ammo", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }
		}
		if(listitem == 1)
		{
			GivePlayerWeaponEx(playerid, 31, 300);
			ShowItemBox(playerid, "MP4", "Recived_300x", 356, 3);	
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil senjata M4 sebanyak 300x ammo", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }            		
		}
		if(listitem == 2)
		{
			GivePlayerWeaponEx(playerid, 25, 100);
			ShowItemBox(playerid, "Shotgun", "Recived_100x", 349, 3);		
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil senjata Shotgun sebanyak 100x ammo", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }            		
		}
		if(listitem == 3)
		{
			GivePlayerWeaponEx(playerid, 27, 150);
			ShowItemBox(playerid, "Combat Shotgun", "Recived_150x", 351, 3);	
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil senjata Combat Shotgun sebanyak 150x ammo", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }            			
		}
		if(listitem == 4)
		{
			GivePlayerWeaponEx(playerid, 24, 250);
			ShowItemBox(playerid, "Desert Eagle", "Recived_250x", 348, 3);		
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil senjata Desert Eagle sebanyak 250x ammo", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }            		
		}			
		if(listitem == 5)
		{
			Inventory_Add(playerid, "Kevlar", 1242, 3);
			ShowItemBox(playerid, "Kevlar", "Recived_3x", 1242, 3);		
            foreach(new i : Player)
            {
                if(AccountData[i][pSpawned])
                {
                    if(AccountData[i][pFaction] == 1)
                    {
                        if(AccountData[i][pOnDuty])
                        {
                            SendClientMessageEx(i, COLOR_ORANGE, "[ALERT] %s (%s) telah mengambil Kevlar sebanyak 3x", AccountData[playerid][pName], PangkatPolisi(playerid));
                        }
                    }
                }
            }            		
		}			
    }
    return 1;
}