#include <YSI\y_hooks>
new listcar[MAX_PLAYERS];
new PlayerText: DEALERMENU[MAX_PLAYERS][28];
enum E_DEALERSTUFF
{
    STREAMER_TAG_AREA:buycar
}
new DealerData[E_DEALERSTUFF];

stock LoadAreaBuyCar()
{
    DealerData[buycar] = CreateDynamicSphere(1034.985717, -1443.655761, 13.591075, 2.0);
    Create3DTextLabel("Tekan "LG_E"Y{FFFFFF} untuk membeli kendaraan", -1, 1034.985717, -1443.655761, 13.591075, 25.0, 0, 1);		
}

hook OnGameModeInit()
{
    LoadAreaBuyCar();
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_YES)
	{   
		if(IsPlayerInDynamicArea(playerid, DealerData[buycar]))
		{
			forex(i, 28)
			{
				PlayerTextDrawShow(playerid, DEALERMENU[playerid][i]);
				SelectTextDraw(playerid, -1);
				listcar[playerid] = 0;
			}			
		}		        
    }
    return 1;
}

new const Car1[] = 
{
    481,
    510,
    462,
    468,
    521,
    586,
    461,
    422,
    413,
    554,
    418,
    478,
    400,
    579,
    479,
    458,
    536,
    575,
    534,
    576,
    412,
    545,
    602,
    401,
    527,
    560,
    475,
    445,
    507,
    492,
    580,
    605,
    561,
};
new carcolor1[MAX_PLAYERS];
new carcolor2[MAX_PLAYERS];
stock LoadDealerMenu(playerid)
{
    DEALERMENU[playerid][0] = CreatePTextdraw(playerid, 172.000, 133.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][0], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][0], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][0], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][0], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][0], 1);

    DEALERMENU[playerid][1] = CreatePTextdraw(playerid, 457.000, 133.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][1], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][1], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][1], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][1], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][1], 1);

    DEALERMENU[playerid][2] = CreatePTextdraw(playerid, 172.000, 318.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][2], 18.000, 20.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][2], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][2], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][2], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][2], 1);

    DEALERMENU[playerid][3] = CreatePTextdraw(playerid, 457.000, 318.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][3], 18.000, 20.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][3], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][3], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][3], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][3], 1);

    DEALERMENU[playerid][4] = CreatePTextdraw(playerid, 181.000, 136.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][4], 285.000, 199.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][4], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][4], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][4], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][4], 1);

    DEALERMENU[playerid][5] = CreatePTextdraw(playerid, 175.000, 143.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][5], 297.000, 186.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][5], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][5], 1364218367);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][5], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][5], 1);

    DEALERMENU[playerid][6] = CreatePTextdraw(playerid, 178.000, 139.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][6], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][6], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][6], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][6], 1);

    DEALERMENU[playerid][7] = CreatePTextdraw(playerid, 450.000, 139.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][7], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][7], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][7], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][7], 1);

    DEALERMENU[playerid][8] = CreatePTextdraw(playerid, 178.000, 312.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][8], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][8], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][8], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][8], 1);

    DEALERMENU[playerid][9] = CreatePTextdraw(playerid, 450.000, 312.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][9], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][9], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][9], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][9], 1);

    DEALERMENU[playerid][10] = CreatePTextdraw(playerid, 187.000, 142.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][10], 271.000, 188.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][10], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][10], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][10], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][10], 1);

    DEALERMENU[playerid][11] = CreatePTextdraw(playerid, 181.000, 150.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][11], 284.000, 170.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][11], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][11], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][11], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][11], 1);

    DEALERMENU[playerid][12] = CreatePTextdraw(playerid, 208.000, 151.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][12], 241.000, 170.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][12], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][12], 589374975);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][12], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][12], 1);

    DEALERMENU[playerid][13] = CreatePTextdraw(playerid, 239.000, 166.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][13], 171.000, 111.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][13], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][13], 1111442687);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][13], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][13], 1);

    DEALERMENU[playerid][14] = CreatePTextdraw(playerid, 182.000, 218.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][14], 24.000, 28.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][14], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][14], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][14], 1);

    DEALERMENU[playerid][15] = CreatePTextdraw(playerid, 259.000, 136.000, "_");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][15], 117.000, 159.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][15], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][15], 0);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][15], 5);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][15], 0);
    PlayerTextDrawSetPreviewModel(playerid, DEALERMENU[playerid][15], 481);
    PlayerTextDrawSetPreviewRot(playerid, DEALERMENU[playerid][15], -14.000, 1.000, 42.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, DEALERMENU[playerid][15], 0, 0);

    DEALERMENU[playerid][16] = CreatePTextdraw(playerid, 381.000, 215.000, "LD_BEAT:right");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][16], 19.000, 23.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][16], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][16], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][16], 1);

    DEALERMENU[playerid][17] = CreatePTextdraw(playerid, 249.000, 215.000, "LD_BEAT:left");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][17], 19.000, 24.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][17], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][17], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][17], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][17], 1);

    DEALERMENU[playerid][18] = CreatePTextdraw(playerid, 323.000, 278.000, "bmx");
    PlayerTextDrawLetterSize(playerid, DEALERMENU[playerid][18], 0.240, 1.299);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][18], 2);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][18], 150);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][18], 2);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][18], 1);

    DEALERMENU[playerid][19] = CreatePTextdraw(playerid, 322.000, 289.000, "rp.25.000");
    PlayerTextDrawLetterSize(playerid, DEALERMENU[playerid][19], 0.220, 1.099);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][19], 2);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][19], 852308735);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][19], 150);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][19], 3);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][19], 1);

    DEALERMENU[playerid][20] = CreatePTextdraw(playerid, 209.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][20], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][20], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][20], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][20], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][20], 1);

    DEALERMENU[playerid][21] = CreatePTextdraw(playerid, 225.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][21], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][21], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][21], 255);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][21], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][21], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][21], 1);

    DEALERMENU[playerid][22] = CreatePTextdraw(playerid, 241.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][22], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][22], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][22], -16776961);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][22], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][22], 1);

    DEALERMENU[playerid][23] = CreatePTextdraw(playerid, 257.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][23], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][23], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][23], -2686721);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][23], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][23], 1);

    DEALERMENU[playerid][24] = CreatePTextdraw(playerid, 273.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][24], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][24], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][24], 512819199);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][24], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][24], 1);

    DEALERMENU[playerid][25] = CreatePTextdraw(playerid, 289.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][25], 18.000, 21.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][25], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][25], -9849601);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][25], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][25], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][25], 1);

    DEALERMENU[playerid][26] = CreatePTextdraw(playerid, 386.000, 297.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, DEALERMENU[playerid][26], 50.000, 16.000);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][26], 1);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][26], 16711935);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][26], 255);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][26], 1);
    PlayerTextDrawSetSelectable(playerid, DEALERMENU[playerid][26], 1);

    DEALERMENU[playerid][27] = CreatePTextdraw(playerid, 412.000, 299.000, "buy");
    PlayerTextDrawLetterSize(playerid, DEALERMENU[playerid][27], 0.240, 1.299);
    PlayerTextDrawAlignment(playerid, DEALERMENU[playerid][27], 2);
    PlayerTextDrawColor(playerid, DEALERMENU[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, DEALERMENU[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, DEALERMENU[playerid][27], -1);
    PlayerTextDrawBackgroundColor(playerid, DEALERMENU[playerid][27], 150);
    PlayerTextDrawFont(playerid, DEALERMENU[playerid][27], 2);
    PlayerTextDrawSetProportional(playerid, DEALERMENU[playerid][27], 1);    
}

hook OnPlayerConnect(playerid)
{
    LoadDealerMenu(playerid);
    return 1;
}

stock Vehicleprice(vehicleid)
{
    if(vehicleid == 481) return 10000;
    if(vehicleid == 510) return 12500;
    if(vehicleid == 462) return 15000;
    if(vehicleid == 468) return 35000;
    if(vehicleid == 521) return 38000;
    if(vehicleid == 586) return 27000;
    if(vehicleid == 461) return 30000;
    if(vehicleid == 422) return 25000;
    if(vehicleid == 413) return 25000;
    if(vehicleid == 554) return 45000;
    if(vehicleid == 418) return 32000;
    if(vehicleid == 478) return 22500;
    if(vehicleid == 400) return 60000;
    if(vehicleid == 579) return 42500;
    if(vehicleid == 479) return 25000;
    if(vehicleid == 458) return 45000;
    if(vehicleid == 536) return 75000;
    if(vehicleid == 575) return 75000;
    if(vehicleid == 534) return 90000;
    if(vehicleid == 576) return 85000;
    if(vehicleid == 412) return 78000;
    if(vehicleid == 545) return 120000;
    if(vehicleid == 602) return 100000;
    if(vehicleid == 401) return 100000;
    if(vehicleid == 527) return 95000;
    if(vehicleid == 560) return 150000;
    if(vehicleid == 475) return 90000;
    if(vehicleid == 445) return 120000;
    if(vehicleid == 507) return 135000;
    if(vehicleid == 492) return 110000;
    if(vehicleid == 580) return 180000;
    if(vehicleid == 605) return 17500;
    if(vehicleid == 561) return 20000;            
 	return -1;
}

