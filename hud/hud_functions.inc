#include <YSI\y_hooks>

new PlayerText: HUDSERVER[MAX_PLAYERS][34];
new PlayerText: ARIVSPEEDO[MAX_PLAYERS][6];
stock LoadHudTD(playerid)
{
    ARIVSPEEDO[playerid][0] = CreatePTextdraw (playerid, 130.000, 400.000, "22:14");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][0], 0.158, 0.850);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][0], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][0], 1);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][0], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][0], 1);

    ARIVSPEEDO[playerid][1] = CreatePTextdraw (playerid, 130.000, 413.000, "79");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][1], 0.304, 1.699);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][1], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][1], 0);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][1], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][1], 1);

    ARIVSPEEDO[playerid][2] = CreatePTextdraw (playerid, 151.000, 415.000, "Fuel");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][2], 0.158, 0.850);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][2], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][2], 1);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][2], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][2], 1);

    ARIVSPEEDO[playerid][3] = CreatePTextdraw (playerid, 173.000, 413.000, "0");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][3], 0.304, 1.699);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][3], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][3], 0);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][3], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][3], 1);

    ARIVSPEEDO[playerid][4] = CreatePTextdraw (playerid, 193.000, 415.000, "KMH");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][4], 0.158, 0.850);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][4], 156.000, 17.000);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][4], 1);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][4], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][4], 1);

    ARIVSPEEDO[playerid][5] = CreatePTextdraw (playerid, 130.000, 432.000, "West I Temple");
    PlayerTextDrawLetterSize(playerid, ARIVSPEEDO[playerid][5], 0.170, 1.149);
    PlayerTextDrawTextSize(playerid, ARIVSPEEDO[playerid][5], 304.000, 47.500);
    PlayerTextDrawAlignment(playerid, ARIVSPEEDO[playerid][5], 0);
    PlayerTextDrawColor(playerid, ARIVSPEEDO[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ARIVSPEEDO[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ARIVSPEEDO[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ARIVSPEEDO[playerid][5], 255);
    PlayerTextDrawFont(playerid, ARIVSPEEDO[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ARIVSPEEDO[playerid][5], 1);

    HUDSERVER[playerid][0] = CreatePlayerTextDraw(playerid, 4.000, 346.000, "_");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][0], 0.428, 2.000);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][0], 21.000, 0.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][0], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, HUDSERVER[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, HUDSERVER[playerid][0], 150);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][0], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][0], 1);

    HUDSERVER[playerid][1] = CreatePlayerTextDraw(playerid, 4.000, 364.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][1], 17.000, -18.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][1], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][1], 546459903);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][1], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][1], 1);

    HUDSERVER[playerid][2] = CreatePlayerTextDraw(playerid, 4.000, 370.000, "_");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][2], 0.428, 2.000);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][2], 21.000, 0.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][2], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][2], -1);
    PlayerTextDrawUseBox(playerid, HUDSERVER[playerid][2], 1);
    PlayerTextDrawBoxColor(playerid, HUDSERVER[playerid][2], 150);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][2], 1);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][2], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][2], 1);

    HUDSERVER[playerid][3] = CreatePlayerTextDraw(playerid, 4.000, 388.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][3], 17.000, -18.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][3], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][3], -1521606913);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][3], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][3], 1);

    HUDSERVER[playerid][4] = CreatePlayerTextDraw(playerid, 4.000, 394.000, "_");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][4], 0.428, 2.000);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][4], 21.000, 0.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][4], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][4], -1);
    PlayerTextDrawUseBox(playerid, HUDSERVER[playerid][4], 1);
    PlayerTextDrawBoxColor(playerid, HUDSERVER[playerid][4], 150);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][4], 1);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][4], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][4], 1);

    HUDSERVER[playerid][5] = CreatePlayerTextDraw(playerid, 4.000, 412.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][5], 17.000, -18.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][5], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][5], 409373695);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][5], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][5], 1);

    HUDSERVER[playerid][6] = CreatePlayerTextDraw(playerid, 4.000, 418.000, "_");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][6], 0.428, 2.000);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][6], 21.000, 0.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][6], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, HUDSERVER[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, HUDSERVER[playerid][6], 150);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][6], 1);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][6], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][6], 1);

    HUDSERVER[playerid][7] = CreatePlayerTextDraw(playerid, 4.000, 436.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][7], 17.000, -18.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][7], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][7], -849584897);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][7], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][7], 1);

    HUDSERVER[playerid][8] = CreatePlayerTextDraw(playerid, 11.000, 348.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][8], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][8], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][8], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][8], 1);

    HUDSERVER[playerid][9] = CreatePlayerTextDraw(playerid, 8.000, 350.000, "V");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][9], 0.358, 1.098);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][9], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][9], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][9], 1);

    HUDSERVER[playerid][10] = CreatePlayerTextDraw(playerid, 9.000, 350.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][10], 6.000, 8.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][10], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][10], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][10], 1);

    HUDSERVER[playerid][11] = CreatePlayerTextDraw(playerid, 7.000, 348.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][11], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][11], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][11], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][11], 1);

    HUDSERVER[playerid][12] = CreatePlayerTextDraw(playerid, 8.000, 416.000, "+");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][12], 0.398, 2.197);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][12], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][12], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][12], 1);

    HUDSERVER[playerid][13] = CreatePlayerTextDraw(playerid, 10.000, 396.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][13], 4.000, 12.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][13], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][13], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][13], 1);

    HUDSERVER[playerid][14] = CreatePlayerTextDraw(playerid, 9.000, 399.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][14], 6.000, 12.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][14], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][14], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][14], 1);

    HUDSERVER[playerid][15] = CreatePlayerTextDraw(playerid, 10.000, 376.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][15], 0.112, 1.049);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][15], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][15], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][15], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][15], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][15], 1);

    HUDSERVER[playerid][16] = CreatePlayerTextDraw(playerid, 8.000, 374.000, "-");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][16], 0.418, 0.648);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][16], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][16], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][16], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][16], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][16], 1);

    HUDSERVER[playerid][17] = CreatePlayerTextDraw(playerid, 8.000, 372.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][17], 0.112, 0.800);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][17], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][17], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][17], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][17], 1);

    HUDSERVER[playerid][18] = CreatePlayerTextDraw(playerid, 10.000, 372.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][18], 0.112, 0.800);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][18], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][18], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][18], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][18], 1);

    HUDSERVER[playerid][19] = CreatePlayerTextDraw(playerid, 12.000, 372.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][19], 0.112, 0.800);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][19], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][19], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][19], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][19], 1);

    HUDSERVER[playerid][20] = CreatePlayerTextDraw(playerid, 15.000, 376.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][20], 0.112, 1.049);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][20], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][20], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][20], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][20], 1);

    HUDSERVER[playerid][21] = CreatePlayerTextDraw(playerid, 15.000, 371.000, "D");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][21], 0.112, 1.049);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][21], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][21], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][21], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][21], 1);

    HUDSERVER[playerid][22] = CreatePlayerTextDraw(playerid, 4.000, 322.000, "_");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][22], 0.428, 2.000);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][22], 21.000, 0.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][22], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][22], -1);
    PlayerTextDrawUseBox(playerid, HUDSERVER[playerid][22], 1);
    PlayerTextDrawBoxColor(playerid, HUDSERVER[playerid][22], 150);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][22], 1);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][22], 1);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][22], 150);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][22], 1);

    HUDSERVER[playerid][23] = CreatePlayerTextDraw(playerid, 4.000, 340.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][23], 17.000, -18.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][23], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][23], -1448498689);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][23], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][23], 1);

    HUDSERVER[playerid][24] = CreatePlayerTextDraw(playerid, 8.000, 325.000, ")");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][24], 0.216, 0.750);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][24], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][24], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][24], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][24], 1);

    HUDSERVER[playerid][25] = CreatePlayerTextDraw(playerid, 8.000, 324.000, "/");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][25], 0.189, 0.349);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][25], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][25], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][25], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][25], 1);

    HUDSERVER[playerid][26] = CreatePlayerTextDraw(playerid, 10.000, 324.000, "U");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][26], 0.291, 0.300);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][26], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][26], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][26], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][26], 1);

    HUDSERVER[playerid][27] = CreatePlayerTextDraw(playerid, 15.000, 325.000, "(");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][27], 0.216, 0.750);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][27], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][27], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][27], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][27], 1);

    HUDSERVER[playerid][28] = CreatePlayerTextDraw(playerid, 15.000, 324.000, "\\");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][28], 0.189, 0.349);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][28], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][28], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][28], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][28], 1);

    HUDSERVER[playerid][29] = CreatePlayerTextDraw(playerid, 8.000, 330.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][29], 0.108, 0.648);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][29], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][29], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][29], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][29], 1);

    HUDSERVER[playerid][30] = CreatePlayerTextDraw(playerid, 16.000, 330.000, "I");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][30], 0.112, 0.648);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][30], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][30], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][30], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][30], 1);

    HUDSERVER[playerid][31] = CreatePlayerTextDraw(playerid, 8.000, 331.000, "-");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][31], 0.670, 0.648);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][31], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][31], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][31], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][31], 1);

    HUDSERVER[playerid][32] = CreatePlayerTextDraw(playerid, 11.000, 325.000, "-");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][32], 0.256, 0.600);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][32], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][32], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][32], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][32], 1);

    HUDSERVER[playerid][33] = CreatePlayerTextDraw(playerid, 11.000, 327.000, "-");
    PlayerTextDrawLetterSize(playerid, HUDSERVER[playerid][33], 0.256, 0.500);
    PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][33], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HUDSERVER[playerid][33], 1);
    PlayerTextDrawColor(playerid, HUDSERVER[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, HUDSERVER[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, HUDSERVER[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, HUDSERVER[playerid][33], 255);
    PlayerTextDrawFont(playerid, HUDSERVER[playerid][33], 1);
    PlayerTextDrawSetProportional(playerid, HUDSERVER[playerid][33], 1);
}

hook OnPlayerConnect(playerid)
{
    LoadHudTD(playerid);
    return 1;
}

hook OnGameModeInit()
{
    SetTimer("ProsesStatsPemain", 720000, 1);
    SetTimer("ProsesStress", 600000, 1);	
    return 1;    
}

forward ProsesLaparPemain(playerid);
public ProsesLaparPemain(playerid)
{
	if(pData[playerid][pSpawned])
	{
		if(!pData[playerid][pInjured])
		{
			if(pData[playerid][pHunger] > 0 && !pData[playerid][pInjured])
			{
				pData[playerid][pHunger] -= 5;
			}		
			else if(pData[playerid][pHunger] <= 0 && !pData[playerid][pInjured])
			{
				if(IsPlayerInAnyVehicle(playerid))
					RemovePlayerFromVehicle(playerid);
				SetPlayerHealth(playerid, 0.0);
			}

			if(pData[playerid][pHunger] == 20)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}
			else if(pData[playerid][pHunger] == 15)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}			
			else if(pData[playerid][pHunger] == 10)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}			
			else if(pData[playerid][pHunger] == 5)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}			
			else if(pData[playerid][pHunger] == 3)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}			
			else if(pData[playerid][pHunger] == 1)
			{
				SendClientMessageEx(playerid, -1, "[Lapar] Karaktermu sudah merasa lapar ("YELLOW_E"%d persen{FFFFFF}) // segera makan sebelum pingsan", pData[playerid][pHunger]);
			}				
		}
	}
    return 1;
}

forward ProsesHausPemain(playerid);
public ProsesHausPemain(playerid)
{
	if(pData[playerid][pSpawned])
	{
		if(!pData[playerid][pInjured])
		{
			if(pData[playerid][pEnergy] > 0 && !pData[playerid][pInjured])
			{
				pData[playerid][pEnergy] -= 5;
			}				
			else if(pData[playerid][pEnergy] <= 0 && !pData[playerid][pInjured])
			{
				if(IsPlayerInAnyVehicle(playerid))
					RemovePlayerFromVehicle(playerid);
				SetPlayerHealth(playerid, 0.0);
			}

			if(pData[playerid][pEnergy] == 20)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}
			else if(pData[playerid][pEnergy] == 15)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}			
			else if(pData[playerid][pEnergy] == 10)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}			
			else if(pData[playerid][pEnergy] == 5)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}			
			else if(pData[playerid][pEnergy] == 3)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}			
			else if(pData[playerid][pEnergy] == 1)
			{
				SendClientMessageEx(playerid, -1, "[Haus] Karaktermu sudah merasa haus ("YELLOW_E"%d persen{FFFFFF}) // segera minum sebelum pingsan", pData[playerid][pEnergy]);
			}				
		}
	}
    return 1;
}

forward Prosesstress(playerid);
public Prosesstress(playerid)
{
	if(pData[playerid][pSpawned])
	{
		if(!pData[playerid][pInjured])
		{
			pData[playerid][pBladder]++;
			if(pData[playerid][pBladder] >= 50)
			{
				SetPlayerDrunkLevel(playerid, 10000);
			}
			else if(pData[playerid][pBladder] < 50)
			{
				SetPlayerDrunkLevel(playerid, 0);
			}

			if(pData[playerid][pBladder] == 60)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}
			else if(pData[playerid][pBladder] == 65)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}			
			else if(pData[playerid][pBladder] == 70)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}			
			else if(pData[playerid][pBladder] == 75)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}			
			else if(pData[playerid][pBladder] == 80)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}			
			else if(pData[playerid][pBladder] == 90)
			{
				SendClientMessageEx(playerid, -1, "[Stress] Karaktermu sudah merasa stress ("YELLOW_E"%d persen{FFFFFF}) // segera hilangin setress", pData[playerid][pBladder]);
			}				
		}
	}
    return 1;
}

forward ProsesStress();
public ProsesStress()
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
	    if(IsPlayerConnected(i))
        {
            Prosesstress(i);
            new Float:barstress;

            barstress = pData[i][pBladder] * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][7], 17.000, barstress);
            PlayerTextDrawShow(i, HUDSERVER[i][7]);             	
        }
    }
    return 1;
}

forward ProsesStatsPemain();
public ProsesStatsPemain()
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
	    if(IsPlayerConnected(i))
        {
            ProsesLaparPemain(i);

            ProsesHausPemain(i);
            new
                Float:bardarah, Float: darah, Float:armor, Float:bararmor, Float:barhunger, Float:barthirst, Float:barstress;

            GetPlayerHealth(i, darah);
            GetPlayerArmour(i, armor);
            bararmor = armor * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][23], 17.000, bararmor);
            PlayerTextDrawShow(i, HUDSERVER[i][23]);	

            bardarah = darah * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][1], 17.000, bardarah);
            PlayerTextDrawShow(i, HUDSERVER[i][1]);	

            barhunger = pData[i][pHunger] * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][3], 17.000, barhunger);
            PlayerTextDrawShow(i, HUDSERVER[i][3]);	

            barthirst = pData[i][pEnergy] * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][5], 17.000, barthirst);
            PlayerTextDrawShow(i, HUDSERVER[i][5]);	

            barstress = pData[i][pBladder] * -18.000/100; 
            PlayerTextDrawTextSize(i, HUDSERVER[i][7], 17.000, barstress);
            PlayerTextDrawShow(i, HUDSERVER[i][7]);                                    
    	}
	}
    return 1;
}