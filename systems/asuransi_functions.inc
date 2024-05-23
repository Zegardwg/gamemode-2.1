#include <YSI\y_hooks>

new pointinsu;

hook OnGameModeInit()
{
    CreateDynamicCP(424.229309, -1318.538330, 14.990978, 1.0);
    pointinsu = CreateDynamicSphere(424.229309, -1318.538330, 14.990978, 1.0);
    return 1;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == pointinsu)
    {
        ShowInfo(playerid, "Mengambil Kendaraan");
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{   
        if(IsPlayerInDynamicArea(playerid, pointinsu))
        {
			new msg2[100], bool:found = false;	
			format(msg2, sizeof(msg2), "Nama Mobil\tHarga Asuransi\n");					
			foreach(new i : PVehicles)
			{	
				if(pvData[i][cInsu] > 0)
				{
					if(Vehicle_IsOwner(playerid, i))
					{
						format(msg2, sizeof(msg2), "%s%s\t{FF0000}$500\n", msg2, GetVehicleModelName(pvData[i][cModel]));
						found = true;
					}				
				}
			}
			if(found)
				Dialog_Show(playerid, DIALOG_ASURANSI, DIALOG_STYLE_TABLIST_HEADERS, "Pengambilan Kendaraan Asuransi", msg2, "Pilih", "Batalkan");
			else
				Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "Pengambilan Kendaraan Asuransi", "Tidak ada kendaraan apapun yang masuk Asuransi", "Tutup", "");			
		    /*if(!GetOwnedVeh(playerid)) return ErrorMsg(playerid, "Anda tidak memiliki kendaraan apapun.");
			new vid, _tmpstring[128], count = GetOwnedVeh(playerid), CMDSString[512];
			CMDSString = "";
			strcat(CMDSString,"Name\tPrice",sizeof(CMDSString));
			Loop(itt, (count + 1), 1)
			{
				vid = ReturnPlayerVehID(playerid, itt);
				if(itt == count)
				{
					format(_tmpstring, sizeof(_tmpstring), "%s{ffffff}\t"LG_E"$500", GetVehicleModelName(pvData[vid][cModel]));
				}
				else format(_tmpstring, sizeof(_tmpstring), "%s{ffffff}\t"LG_E"$500", GetVehicleModelName(pvData[vid][cModel]));
				strcat(CMDSString, _tmpstring);
            }
            Dialog_Show(playerid, DIALOG_ASURANSI, DIALOG_STYLE_TABLIST_HEADERS, "{a8ecff}Konoha Roleplay{FFFFFF} - Ansuransi Kendaraan", CMDSString, "Pilih", "Batal");  **/          
        }
    }
    return 1;
}

Dialog:DIALOG_ASURANSI(playerid, response, listitem, inputtext[])
{
    if(response)
    {
		new count;
		foreach(new i : PVehicles)	
		{
			if(Vehicle_IsOwner(playerid, i) && pvData[i][cClaim] && count++ == listitem)
			{
				pvData[i][cClaim] = 0;
				pvData[i][cInsu] = 0;
				OnPlayerVehicleRespawn(i);
				pvData[i][cPos][0] = 406.459594;
				pvData[i][cPos][1] = -1314.405395;
				pvData[i][cPos][2] = 14.607555;
				pvData[i][cPos][3] = 206.858398;
				SetValidVehicleHealth(pvData[i][cVeh], 1500);
				SetVehiclePos(pvData[i][cVeh], 406.459594, -1314.405395, 14.607555);
				SetVehicleZAngle(pvData[i][cVeh], 206.858398);
				SetVehicleFuel(pvData[i][cVeh], 75);
				ValidRepairVehicle(pvData[i][cVeh]);
				GivePlayerMoneyEx(playerid, -500);
				ShowItemBox(playerid, "Uang", "Removed_$500", 1212, 4);
			}
		}	
    }
    return 1;
}