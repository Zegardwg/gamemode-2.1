#include <YSI\y_hooks>

enum E_MEDISSTUFF
{
    STREAMER_TAG_AREA:DutyArea,
    STREAMER_TAG_AREA:LokerArea,
    STREAMER_TAG_AREA:ApotekArea,
    STREAMER_TAG_AREA:PerlengkapanArea,
    STREAMER_TAG_AREA:BossTable,
}
new MedisVars[E_MEDISSTUFF];

enum e_barang_data
{
    P3K,
    Kertas,
    Perban,
    PilStress
}
new bmData[e_barang_data];

enum E_PLAYERMEDISSTUFF
{
    mPrice[2],
    mAmount[2],
    mItem[5],
    AmountInvoice,
    NameInvoice[128]
}
new PlayerMedisVars[MAX_PLAYERS][E_PLAYERMEDISSTUFF];

stock PangkatMedis(playerid)
{
    new rantaipangkat[128];
    if(pData[playerid][pFaction] == 2)
    {
        if(pData[playerid][pFactionRank] == 0)format(rantaipangkat, sizeof(rantaipangkat), "Tidak Ada");
        else if(pData[playerid][pFactionRank] == 1)format(rantaipangkat, sizeof(rantaipangkat), "EMT");
        else if(pData[playerid][pFactionRank] == 2)format(rantaipangkat, sizeof(rantaipangkat), "Perawat");  
        else if(pData[playerid][pFactionRank] == 3)format(rantaipangkat, sizeof(rantaipangkat), "Wakil Dir Lapangan");      
        else if(pData[playerid][pFactionRank] == 4)format(rantaipangkat, sizeof(rantaipangkat), "Wakil Dir Administrasi");
        else if(pData[playerid][pFactionRank] == 5)format(rantaipangkat, sizeof(rantaipangkat), "Direktur RS");           
    }
    return rantaipangkat;
}

stock LoadMedisStuff()
{	
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}Boss Table", -1, 304.159942, -1520.185302, 36.432510, 25.0, 0, 1);	
    MedisVars[BossTable] = CreateDynamicSphere(304.159942, -1520.185302, 36.432510, 1.3);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk Onduty/Offduty Medis", -1, 301.911621, -1523.987426, 36.432510, 25.0, 0, 1);	
    MedisVars[DutyArea] = CreateDynamicSphere(301.911621, -1523.987426, 36.432510, 1.0);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk membuka loker medis", -1, 298.273773, -1523.849243, 36.432510, 25.0, 0, 1);	
    MedisVars[LokerArea] = CreateDynamicSphere(298.273773, -1523.849243, 36.432510, 1.0);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk membuka loker apotek", -1, 351.683502, -1487.372436, 36.432510, 25.0, 0, 1);	
    MedisVars[ApotekArea] = CreateDynamicSphere(351.683502, -1487.372436, 36.432510, 1.5);
    Create3DTextLabel("Tekan "LG_E"Y {FFFFFF}untuk mengambil perlengkapan", -1, 311.997039, -1533.278564, 36.432510, 25.0, 0, 1);	
    MedisVars[PerlengkapanArea] = CreateDynamicSphere(311.997039, -1533.278564, 36.432510, 1.5);
}

hook OnGameModeInit()
{
    LoadMedisStuff();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES)
    {
        if(IsPlayerInDynamicArea(playerid, MedisVars[BossTable]))
        {
            if(pData[playerid][pFaction] == 2)
            {
                if(pData[playerid][pOnDuty])
                {
                    if(pData[playerid][pFactionRank] < 3)
                        return Error(playerid, "Anda bukan petinggi rumah sakit");        

                    Dialog_Show(playerid, DIALOG_MEDISTABLE, DIALOG_STYLE_LIST, "Medis Table", "Invite Anggota\nDaftar Anggota Online", "Pilih", "Batalkan");                  
                }                
            }
        }        
        if(IsPlayerInDynamicArea(playerid, MedisVars[PerlengkapanArea]))
        {
            if(pData[playerid][pFaction] == 2)
            {
                if(pData[playerid][pFactionRank] > 1)
                {
                    new str[200];
                    format(str, sizeof(str), "Item Name\t:\tPrice\tAmount\nP3K\t-\t$500\t%d\nKertas\t-\t$100\t%d\n", bmData[P3K], bmData[Kertas]);
                    Dialog_Show(playerid, DIALOG_PERLENGKAPANMEDIS, DIALOG_STYLE_TABLIST_HEADERS, "Medis >> Perlengkapan", str, "Pilih", "Batalkan");                    
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, MedisVars[ApotekArea]))
        {
            if(pData[playerid][pFaction] == 2)
            {
                if(pData[playerid][pFactionRank] > 1)
                {
                    new str[200];
                    format(str, sizeof(str), "Item Name\t:\tPrice\tAmount\nPerban\t-\t$250\t%d\nPill Stress\t-\t$1000\t%d\n", bmData[Perban], bmData[PilStress]);
                    Dialog_Show(playerid, DIALOG_APOTEKMEDIS, DIALOG_STYLE_TABLIST_HEADERS, "Medis >> Apotek",
                    str, "Pilih", "Batalkan");
                }
            }
        }
        if(IsPlayerInDynamicArea(playerid, MedisVars[LokerArea]))
        {
            if(pData[playerid][pFaction] == 2)
            {
                Dialog_Show(playerid, DIALOG_LOKERMEDIS, DIALOG_STYLE_LIST, "Medis >> Loker Medis", "Seragam EMT\nSeragam EMS\nSeragam Direktur", "Pilih", "Batalkan");
            }
        }
        if(IsPlayerInDynamicArea(playerid, MedisVars[DutyArea]))
        {
            if(pData[playerid][pFaction] == 2)
            {
                if(!pData[playerid][pOnDuty])
                {
                    pData[playerid][pOnDuty] = 1;
                    //ScoreboardVars[CountMedis]++;
                    InfoMsg(playerid, "Anda telah OnDuty menjadi Medis");
                }
                else
                {
					pData[playerid][pOnDuty] = 0;
                    //ScoreboardVars[CountMedis]--;
					SetPlayerSkin(playerid, pData[playerid][pSkin]);
					InfoMsg(playerid, "Anda telah Offduty menjadi Medis");
                }
            }
        }
    }
    if(newkeys & KEY_CTRL_BACK)
    {
        if(pData[playerid][pFaction] == 2)
        {
            if(pData[playerid][pFactionRank] < 1)
            {
                if(pData[playerid][pOnDuty])
                {
                    foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
                    {
                        Dialog_Show(playerid, DIALOG_RADIALMEDIS, DIALOG_STYLE_LIST, ""GREY_E"Medis >> Faction Menu", "Treatment", "Pilih", "Batalkan");
                    }
                }
            }
            else
            {
                if(pData[playerid][pOnDuty])
                {
                    foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
                    {
                        Dialog_Show(playerid, DIALOG_RADIALMEDIS, DIALOG_STYLE_LIST, ""GREY_E"Medis >> Faction Menu", "Beri Invoice\nRevive\nTreatment", "Pilih", "Batalkan");
                    }
                }                
            }
        }        
    }
    return 1;
}

stock barangmedis_save()
{
    new str[5000];

    format(str, sizeof(str), "UPDATE barangmedis SET p3k='%d', kertas='%d', perban='%d', pilstress='%d' WHERE id=0",
	bmData[P3K], bmData[Kertas], bmData[Perban], bmData[PilStress]);
    return mysql_tquery(g_SQL, str);
}

FUNC::LoadBarangMedis()
{
	cache_get_value_name_int(0, "p3k", bmData[P3K]);
	cache_get_value_name_int(0, "kertas", bmData[Kertas]);
    cache_get_value_name_int(0, "perban", bmData[Perban]);
    cache_get_value_name_int(0, "pilstress", bmData[PilStress]);
}

Dialog:DIALOG_PILIHBARANGMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			if(!pData[playerid][pAdmin]) return ErrorMsg(playerid, "Untuk saat ini hanya admin yang bisa restock");
            if(!pData[playerid][pAdminDuty]) return ErrorMsg(playerid, "Anda harus onduty admin");
			Dialog_Show(playerid, DIALOG_BARANGAMOUNT, DIALOG_STYLE_INPUT, "Medis >> Barang Medis", "Masukan Jumlah Item Yang Ingin Anda Taruh Didalam Gudang", "Masukan", "Batalkan");
		}
		if(listitem == 1)
		{
			Dialog_Show(playerid, DIALOG_BARANGAMOUNT2, DIALOG_STYLE_INPUT, "Medis >> Barang Medis", "Masukan Jumlah Item Yang Ingin Anda Ambil Didalam Gudang", "Masukan", "Batalkan");
		}        
    }
    return 1;
}

Dialog:DIALOG_BARANGAMOUNT(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(PlayerMedisVars[playerid][mItem][0] == 1)
		{
			new amount = strval(inputtext);

			bmData[Perban] += amount;
			PlayerMedisVars[playerid][mItem][0] = 0;
			barangmedis_save();
		}
		else if(PlayerMedisVars[playerid][mItem][1] == 1)
		{
			new amount = strval(inputtext);

			bmData[PilStress] += amount;
			PlayerMedisVars[playerid][mItem][1] = 0;
			barangmedis_save();
		}
		else if(PlayerMedisVars[playerid][mItem][2] == 1)
		{
			new amount = strval(inputtext);

			bmData[P3K] += amount;
			PlayerMedisVars[playerid][mItem][2] = 0;
			barangmedis_save();
		}			
		else if(PlayerMedisVars[playerid][mItem][3] == 1)
		{
			new amount = strval(inputtext);

			bmData[Kertas] += amount;
			PlayerMedisVars[playerid][mItem][3] = 0;
			barangmedis_save();
		}										
    }
    else 
    {
        PlayerMedisVars[playerid][mItem][0] = 0;
        PlayerMedisVars[playerid][mItem][1] = 0;
        PlayerMedisVars[playerid][mItem][2] = 0;
        PlayerMedisVars[playerid][mItem][3] = 0;        
    }
    return 1;
}

Dialog:DIALOG_BARANGAMOUNT2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new amount = strval(inputtext);
        if(amount < 0) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");
        if(amount == 0) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");

        PlayerMedisVars[playerid][mAmount][0] = amount;
        if(PlayerMedisVars[playerid][mItem][0] == 1)
        {
            Inventory_Add(playerid, "Perban", 11747, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -3500*PlayerMedisVars[playerid][mAmount][0]);
            PlayerMedisVars[playerid][mItem][0] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][1] == 1)
        {
            Inventory_Add(playerid, "Pil Stress", 1241, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -2500*PlayerMedisVars[playerid][mAmount][0]);               
            PlayerMedisVars[playerid][mItem][1] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][2] == 1)
        {
            Inventory_Add(playerid, "P3K", 11738, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -3000*PlayerMedisVars[playerid][mAmount][0]);
            PlayerMedisVars[playerid][mItem][2] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][3] == 1)
        {
            Inventory_Add(playerid, "Kertas", 2684, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -1000*PlayerMedisVars[playerid][mAmount][0]);               
            PlayerMedisVars[playerid][mItem][3] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }             
    }
    else 
    {
        PlayerMedisVars[playerid][mItem][0] = 0;
        PlayerMedisVars[playerid][mItem][1] = 0;
        PlayerMedisVars[playerid][mItem][2] = 0;
        PlayerMedisVars[playerid][mItem][3] = 0;        
    }
    return 1;
}

Dialog:DIALOG_MEDISRANK(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		new rank = strval(inputtext);
		if(!IsPlayerNearPlayer(playerid, pData[playerid][pTarget], 3.0))
			return ErrorMsg(playerid, "You're not close to that player!");				
		if(!IsPlayerConnected(pData[playerid][pTarget]))
			return ErrorMsg(playerid, "Player belum masuk!");		
		pData[pData[playerid][pTarget]][pFaction] = 2;
		pData[pData[playerid][pTarget]][pFactionRank] = rank;
		SuccesMsg(playerid, "Anda berhasil menambahkan Anggota baru");
		SuccesMsg(pData[playerid][pTarget], "Kamu telah bergabung dalam Fraksi Medis");   
    }
    return 1;
}

Dialog:DIALOG_MEDISINVITE(playerid, response, listitem, inputtext[])
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
            return Error(playerid, "Pemain ini sedang dalam duty faction");   			
		pData[playerid][pTarget] = otherid;
		Dialog_Show(playerid, DIALOG_MEDISRANK, DIALOG_STYLE_INPUT, "Invite Anggota Medis", "Masukan Rank Yang Ingin Anda Berikan", "Masukan", "Batalkan");
    }
    return 1;
}

Dialog:DIALOG_MEDISTABLE(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			Dialog_Show(playerid, DIALOG_MEDISINVITE, DIALOG_STYLE_INPUT, "Invite Anggota Medis", "Masukan Kantong Yang Ingin Anda Jadikan Medis", "Masukan", "Batalkan");
		}
		if(listitem == 1)
		{
			new lstr[1024];
			format(lstr, sizeof(lstr), "Nama\tPangkat\n");
			foreach(new i: Player)
			{
				if(pData[i][pFaction] == 4)
				{
					format(lstr, sizeof(lstr), "%s%s\t%s (%d)", lstr, pData[i][pName], PangkatMedis(i), pData[i][pFactionRank]);
					format(lstr, sizeof(lstr), "%s\n", lstr);						
				}
			}
			Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_TABLIST_HEADERS, "List Online Anggota - Medis", lstr, "Tutup", "");				
		}	
    }
    return 1;
}

Dialog:DIALOG_APOTEKBUY(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(PlayerMedisVars[playerid][mItem][0] == 1)
        {
            Inventory_Add(playerid, "Perban", 11747, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, 250*PlayerMedisVars[playerid][mAmount][0]);
            PlayerMedisVars[playerid][mItem][0] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][1] == 1)
        {
            Inventory_Add(playerid, "Pil Stress", 1241, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, 1000*PlayerMedisVars[playerid][mAmount][0]);               
            PlayerMedisVars[playerid][mItem][1] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
    }
    return 1;
}

Dialog:DIALOG_AMOUNTMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new amount = strval(inputtext);
        if(amount < 0) return Error(playerid, "Angka yang anda masukan tidak valid");
        if(amount == 0) return Error(playerid, "Angka yang anda masukan tidak valid");

        PlayerMedisVars[playerid][mAmount][0] = amount;
        if(PlayerMedisVars[playerid][mItem][0] == 1)
        {
            Inventory_Add(playerid, "Perban", 11747, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -250*PlayerMedisVars[playerid][mAmount][0]);
            PlayerMedisVars[playerid][mItem][0] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][1] == 1)
        {
            Inventory_Add(playerid, "Pil Stress", 1241, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -1000*PlayerMedisVars[playerid][mAmount][0]);               
            PlayerMedisVars[playerid][mItem][1] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][2] == 1)
        {
            Inventory_Add(playerid, "P3K", 11738, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -500*PlayerMedisVars[playerid][mAmount][0]);
            PlayerMedisVars[playerid][mItem][2] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }
        else if(PlayerMedisVars[playerid][mItem][3] == 1)
        {
            Inventory_Add(playerid, "Kertas", 2684, PlayerMedisVars[playerid][mAmount][0]);
            GiveMoney(playerid, -100*PlayerMedisVars[playerid][mAmount][0]);               
            PlayerMedisVars[playerid][mItem][3] = 0;
            PlayerMedisVars[playerid][mAmount][0] = 0;
        }                        
    }
    else
    {
        PlayerMedisVars[playerid][mItem][0] = 0;
        PlayerMedisVars[playerid][mItem][1] = 0;
        PlayerMedisVars[playerid][mItem][2] = 0;
        PlayerMedisVars[playerid][mItem][3] = 0;
    }
    return 1;
}

Dialog:DIALOG_PERLENGKAPANMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            Dialog_Show(playerid, DIALOG_PILIHBARANGMEDIS, DIALOG_STYLE_LIST, "Medis >> Barang Medis", "Masukan Barang\nAmbil Barang", "Pilih", "Batalkan");
            PlayerMedisVars[playerid][mItem][2] = 1;
        }
        if(listitem == 1)
        {
            Dialog_Show(playerid, DIALOG_PILIHBARANGMEDIS, DIALOG_STYLE_LIST, "Medis >> Barang Medis", "Masukan Barang\nAmbil Barang", "Pilih", "Batalkan");
            PlayerMedisVars[playerid][mItem][3] = 1;
        }
    }
    return 1;
}

Dialog:DIALOG_APOTEKMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
            Dialog_Show(playerid, DIALOG_PILIHBARANGMEDIS, DIALOG_STYLE_LIST, "Medis >> Barang Medis", "Masukan Barang\nAmbil Barang", "Pilih", "Batalkan");
            //Dialog_Show(playerid, DIALOG_AMOUNTMEDIS, DIALOG_STYLE_INPUT, "Medis >> Apotek", "Masukan jumlah barang yang ingin anda beli:", "Masukan", "Batalkan");
            PlayerMedisVars[playerid][mItem][0] = 1;
        }
        if(listitem == 1)
        {
            Dialog_Show(playerid, DIALOG_PILIHBARANGMEDIS, DIALOG_STYLE_LIST, "Medis >> Barang Medis", "Masukan Barang\nAmbil Barang", "Pilih", "Batalkan");
            //Dialog_Show(playerid, DIALOG_AMOUNTMEDIS, DIALOG_STYLE_INPUT, "Medis >> Apotek", "Masukan jumlah barang yang ingin anda beli:", "Masukan", "Batalkan");
            PlayerMedisVars[playerid][mItem][1] = 1;
        }
    }
    return 1;
}

Dialog:DIALOG_LOKERMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		if(listitem == 0)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 274);
                SetFactionSkin(playerid, 274);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 308);
                SetFactionSkin(playerid, 308);
			}
		}
		if(listitem == 1)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 275);
                SetFactionSkin(playerid, 275);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 308);
                SetFactionSkin(playerid, 308);
			}				
		}
		if(listitem == 2)
		{
			if(pData[playerid][pGender] == 1)
			{
				SetPlayerSkin(playerid, 70);
                SetFactionSkin(playerid, 70);
			}
			else if(pData[playerid][pGender] == 0)
			{
				SetPlayerSkin(playerid, 150);
                SetFactionSkin(playerid, 150);
			}				
		}		
    }
    return 1;
}   

Dialog:DIALOG_NAMEINVOICEMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
		{
			if(1 > strlen(inputtext) < 128) return ErrorMsg(playerid, "Tidak bisa kuarng dari 1 dan lebih dari 128 karakter");
			new biid = Iter_Free(tagihan);
			new id = i;
			new bill[3400];
			bilData[biid][bilType] = pData[playerid][pFaction];
			format(bilData[biid][bilName], 128, inputtext);
			bilData[biid][bilTarget] = pData[id][pID];
			bilData[biid][bilammount] = PlayerMedisVars[playerid][AmountInvoice];
			Iter_Add(tagihan, biid);
			mysql_format(g_SQL, bill, sizeof(bill), "INSERT INTO `bill` (`bid`,`type`,`name`,`target`,`ammount`) VALUES ('%d','%d','%s','%d','%d')",
			biid,
			bilData[biid][bilType],
			bilData[biid][bilName],
			bilData[biid][bilTarget],
			bilData[biid][bilammount]);
			mysql_tquery(g_SQL, bill);

			Info(id, "- [Invoice] Kamu menerima invoice sebesar %s",FormatMoney(bilData[biid][bilammount]));
			PlayerMedisVars[playerid][AmountInvoice] = 0;			
		}
    }
    return 1;
}   

Dialog:DIALOG_INPUTINVOICEMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        Dialog_Show(playerid, DIALOG_INPUTJUMLAHMEDIS, DIALOG_STYLE_INPUT, ""GREY_E"Medis >> Kasih Invoice", "{FFFFFF}Masukan harga invoice yang ingin anda beri:", "Masukan", "Batalkan");
    }
    return 1;
}

Dialog:DIALOG_INPUTJUMLAHMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new ammount = strval(inputtext);

		if(ammount < 1) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");	
		if(ammount == 0) return ErrorMsg(playerid, "Angka yang anda masukan tidak valid");		

		PlayerMedisVars[playerid][AmountInvoice] = ammount;
		Dialog_Show(playerid, DIALOG_NAMEINVOICEMEDIS, DIALOG_STYLE_INPUT, ""GREY_E"Medis >> Kasih Invoice", "{FFFFFF}Masukan nama invoice yang ingin anda beri:", "Masukan", "Batalkan");
    }
    return 1;
}

Dialog:DIALOG_TREATMENTMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
        {
            SetPlayerHealth(i, 100.0);
        }
    }
    return 1;
}

Dialog:DIALOG_RADIALMEDIS(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(listitem == 0)
        {
			new str[500], count = 0;				
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
			{
				format(str, sizeof(str), "[%d]\n", i);
				SetPlayerListitemValue(playerid, count++, i);
			}
			if(!count) Error(playerid, "Tidak ada orang didekat mu");
			else Dialog_Show(playerid, DIALOG_INPUTINVOICEMEDIS, DIALOG_STYLE_LIST, ""GREY_E"Medis >> Kasih Invoice", str, "Pilih", "Batalkan"); 
        }         
        if(listitem == 1)
        {
            if(!Inventory_Count(playerid, "P3K")) return ErrorMsg(playerid, "Anda tidak mempunyai P3K");
            foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.0) && i != playerid)
            {
                if(pData[i][pInjured])
                {
                    Inventory_Remove(playerid, "P3K", 1);
                    SetPlayerHealthEx(i, 100.0);
                    pData[i][pInjured] = 0;
                    pData[i][pInjuredTime] = 0;
                    pData[i][pHospital] = 0;
                    pData[i][pSick] = 0;
                    HideTdDeath(i);
                    TogglePlayerControllable(i, 1);
                    ClearAnimations(i);
                    SetPlayerSpecialAction(i, SPECIAL_ACTION_NONE);                    
                }
            }
        }  
        if(listitem == 2)
        {
			new str[500], count = 0;				
			foreach(new i : Player) if(IsPlayerConnected(i) && NearPlayer(playerid, i, 1.5) && i != playerid)
			{
				format(str, sizeof(str), "[%d]\n", i);
				SetPlayerListitemValue(playerid, count++, i);
			}
			if(!count) ErrorMsg(playerid, "Tidak ada orang didekat mu");
			else Dialog_Show(playerid, DIALOG_TREATMENTMEDIS, DIALOG_STYLE_LIST, ""GREY_E"Medis >> Treatment", str, "Pilih", "Batalkan"); 
        }
    }
    return 1;
}