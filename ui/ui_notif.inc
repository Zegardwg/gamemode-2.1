#include <YSI\y_hooks>
enum e_player_notif
{
    barTimer,
	bool:barExists,
};

new PlayerNotif[MAX_PLAYERS][e_player_notif];

new PlayerText:BOXNOTIF[MAX_PLAYERS][23];
new PlayerText:text_info[MAX_PLAYERS];
new PlayerText:text_error[MAX_PLAYERS];
new PlayerText:text_suksek[MAX_PLAYERS];
new PlayerText:text_syntax[MAX_PLAYERS];
new PlayerText:text_warning[MAX_PLAYERS];

stock LoadNotif(playerid)
{
	BOXNOTIF[playerid][0] = CreatePlayerTextDraw(playerid, 502.000000, 108.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][0], 111.500000, 31.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][0], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][0], 1486083583);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][0], 0);

	BOXNOTIF[playerid][1] = CreatePlayerTextDraw(playerid, 505.000000, 108.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][1], 12.500000, 14.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][1], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][1], 0);

	BOXNOTIF[playerid][2] = CreatePlayerTextDraw(playerid, 506.000000, 109.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][2], 10.500000, 12.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][2], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][2], 1486083583);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][2], 0);

	BOXNOTIF[playerid][3] = CreatePlayerTextDraw(playerid, 510.000000, 109.000000, "i");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][3], 0.245833, 1.200000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][3], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][3], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][3], 0);

	BOXNOTIF[playerid][4] = CreatePlayerTextDraw(playerid, 517.000000, 111.000000, "INFO");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][4], 0.183333, 0.949999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][4], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][4], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][4], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][4], 0);

	text_info[playerid] = CreatePlayerTextDraw(playerid, 507.000000, 119.000000, "script tidak ada silahkan cek dc dan jangan sampai menjadi kontol ajajajajajjajajajaja");
	PlayerTextDrawFont(playerid, text_info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, text_info[playerid], 0.133333, 0.949999);
	PlayerTextDrawTextSize(playerid, text_info[playerid], 610.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, text_info[playerid], 0);
	PlayerTextDrawSetShadow(playerid, text_info[playerid], 0);
	PlayerTextDrawAlignment(playerid, text_info[playerid], 1);
	PlayerTextDrawColor(playerid, text_info[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, text_info[playerid], 255);
	PlayerTextDrawBoxColor(playerid, text_info[playerid], 50);
	PlayerTextDrawUseBox(playerid, text_info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, text_info[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, text_info[playerid], 0);

	BOXNOTIF[playerid][5] = CreatePlayerTextDraw(playerid, 502.000000, 190.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][5], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][5], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][5], 111.500000, 35.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][5], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][5], -1001895169);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][5], 0);

	BOXNOTIF[playerid][6] = CreatePlayerTextDraw(playerid, 507.000000, 192.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][6], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][6], 15.500000, 4.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][6], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][6], -421070081);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][6], 0);

	BOXNOTIF[playerid][7] = CreatePlayerTextDraw(playerid, 507.000000, 197.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][7], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][7], 15.500000, 4.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][7], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][7], -421070081);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][7], 0);

	BOXNOTIF[playerid][8] = CreatePlayerTextDraw(playerid, 517.000000, 198.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][8], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][8], 4.000000, 2.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][8], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][8], -1001895169);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][8], 0);

	BOXNOTIF[playerid][9] = CreatePlayerTextDraw(playerid, 517.000000, 193.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][9], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][9], 4.000000, 1.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][9], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][9], -1001895169);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][9], 0);

	BOXNOTIF[playerid][10] = CreatePlayerTextDraw(playerid, 524.000000, 194.000000, "ERROR");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][10], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][10], 0.183333, 0.899999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][10], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][10], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][10], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][10], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][10], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][10], 0);

	text_error[playerid] = CreatePlayerTextDraw(playerid, 507.000000, 202.000000, "script tidak ada silahkan cek dc dan jangan sampai menjadi kontol ajajajajajjajajajaja");
	PlayerTextDrawFont(playerid, text_error[playerid], 1);
	PlayerTextDrawLetterSize(playerid, text_error[playerid], 0.133333, 0.949999);
	PlayerTextDrawTextSize(playerid, text_error[playerid], 610.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, text_error[playerid], 0);
	PlayerTextDrawSetShadow(playerid, text_error[playerid], 0);
	PlayerTextDrawAlignment(playerid, text_error[playerid], 1);
	PlayerTextDrawColor(playerid, text_error[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, text_error[playerid], 255);
	PlayerTextDrawBoxColor(playerid, text_error[playerid], 50);
	PlayerTextDrawUseBox(playerid, text_error[playerid], 0);
	PlayerTextDrawSetProportional(playerid, text_error[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, text_error[playerid], 0);

	BOXNOTIF[playerid][11] = CreatePlayerTextDraw(playerid, 502.000000, 151.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][11], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][11], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][11], 111.500000, 31.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][11], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][11], 1689621503);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][11], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][11], 0);

	BOXNOTIF[playerid][12] = CreatePlayerTextDraw(playerid, 505.000000, 151.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][12], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][12], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][12], 12.500000, 14.500000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][12], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][12], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][12], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][12], 0);

	BOXNOTIF[playerid][13] = CreatePlayerTextDraw(playerid, 509.000000, 157.000000, "\\");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][13], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][13], 0.229166, 0.399999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][13], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][13], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][13], 16711935);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][13], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][13], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][13], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][13], 0);

	BOXNOTIF[playerid][14] = CreatePlayerTextDraw(playerid, 511.000000, 154.000000, "/");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][14], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][14], 0.150000, 0.749999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][14], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][14], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][14], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][14], 16711935);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][14], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][14], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][14], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][14], 0);

	BOXNOTIF[playerid][15] = CreatePlayerTextDraw(playerid, 517.000000, 154.000000, "SUCCESS");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][15], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][15], 0.183333, 0.949999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][15], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][15], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][15], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][15], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][15], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][15], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][15], 0);

	text_suksek[playerid] = CreatePlayerTextDraw(playerid, 507.000000, 162.000000, "script tidak ada silahkan cek dc dan jangan sampai menjadi kontol ajajajajajjajajajaja");
	PlayerTextDrawFont(playerid, text_suksek[playerid], 1);
	PlayerTextDrawLetterSize(playerid, text_suksek[playerid], 0.133333, 0.949999);
	PlayerTextDrawTextSize(playerid, text_suksek[playerid], 610.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, text_suksek[playerid], 0);
	PlayerTextDrawSetShadow(playerid, text_suksek[playerid], 0);
	PlayerTextDrawAlignment(playerid, text_suksek[playerid], 1);
	PlayerTextDrawColor(playerid, text_suksek[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, text_suksek[playerid], 255);
	PlayerTextDrawBoxColor(playerid, text_suksek[playerid], 50);
	PlayerTextDrawUseBox(playerid, text_suksek[playerid], 0);
	PlayerTextDrawSetProportional(playerid, text_suksek[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, text_suksek[playerid], 0);

	BOXNOTIF[playerid][16] = CreatePlayerTextDraw(playerid, 502.000000, 232.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][16], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][16], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][16], 111.500000, 35.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][16], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][16], 893010175);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][16], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][16], 0);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][16], 0);

	BOXNOTIF[playerid][17] = CreatePlayerTextDraw(playerid, 507.000000, 232.000000, "!");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][17], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][17], 0.304166, 1.549999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][17], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][17], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][17], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][17], -1953195521);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][17], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][17], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][17], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][17], 0);

	BOXNOTIF[playerid][18] = CreatePlayerTextDraw(playerid, 511.000000, 236.000000, "SYNTAX");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][18], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][18], 0.187500, 0.999999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][18], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][18], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][18], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][18], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][18], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][18], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][18], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][18], 0);

	text_syntax[playerid] = CreatePlayerTextDraw(playerid, 507.000000, 244.000000, "script tidak ada silahkan cek dc dan jangan sampai menjadi kontol ajajajajajjajajajaja");
	PlayerTextDrawFont(playerid, text_syntax[playerid], 1);
	PlayerTextDrawLetterSize(playerid, text_syntax[playerid], 0.133333, 0.949999);
	PlayerTextDrawTextSize(playerid, text_syntax[playerid], 610.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, text_syntax[playerid], 0);
	PlayerTextDrawSetShadow(playerid, text_syntax[playerid], 0);
	PlayerTextDrawAlignment(playerid, text_syntax[playerid], 1);
	PlayerTextDrawColor(playerid, text_syntax[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, text_syntax[playerid], 255);
	PlayerTextDrawBoxColor(playerid, text_syntax[playerid], 50);
	PlayerTextDrawUseBox(playerid, text_syntax[playerid], 0);
	PlayerTextDrawSetProportional(playerid, text_syntax[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, text_syntax[playerid], 0);

	BOXNOTIF[playerid][19] = CreatePlayerTextDraw(playerid, 502.000000, 274.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][19], 4);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][19], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][19], 111.500000, 35.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][19], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][19], 893010175);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][19], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][19], 0);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][19], 0);

	BOXNOTIF[playerid][20] = CreatePlayerTextDraw(playerid, 507.000000, 273.000000, "!");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][20], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][20], 0.304166, 1.549999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][20], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][20], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][20], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][20], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][20], -1921306881);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][20], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][20], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][20], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][20], 0);

	BOXNOTIF[playerid][21] = CreatePlayerTextDraw(playerid, 511.000000, 236.000000, "SYNTAX");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][21], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][21], 0.187500, 0.999999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][21], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][21], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][21], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][21], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][21], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][21], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][21], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][21], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][21], 0);

	BOXNOTIF[playerid][22] = CreatePlayerTextDraw(playerid, 511.000000, 277.000000, "WARNING");
	PlayerTextDrawFont(playerid, BOXNOTIF[playerid][22], 1);
	PlayerTextDrawLetterSize(playerid, BOXNOTIF[playerid][22], 0.187500, 0.999999);
	PlayerTextDrawTextSize(playerid, BOXNOTIF[playerid][22], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, BOXNOTIF[playerid][22], 0);
	PlayerTextDrawSetShadow(playerid, BOXNOTIF[playerid][22], 0);
	PlayerTextDrawAlignment(playerid, BOXNOTIF[playerid][22], 1);
	PlayerTextDrawColor(playerid, BOXNOTIF[playerid][22], -1);
	PlayerTextDrawBackgroundColor(playerid, BOXNOTIF[playerid][22], 255);
	PlayerTextDrawBoxColor(playerid, BOXNOTIF[playerid][22], 50);
	PlayerTextDrawUseBox(playerid, BOXNOTIF[playerid][22], 0);
	PlayerTextDrawSetProportional(playerid, BOXNOTIF[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, BOXNOTIF[playerid][22], 0);

	text_warning[playerid] = CreatePlayerTextDraw(playerid, 507.000000, 286.000000, "script tidak ada silahkan cek dc dan jangan sampai menjadi kontol ajajajajajjajajajaja");
	PlayerTextDrawFont(playerid, text_warning[playerid], 1);
	PlayerTextDrawLetterSize(playerid, text_warning[playerid], 0.133333, 0.949999);
	PlayerTextDrawTextSize(playerid, text_warning[playerid], 610.000000, 22.000000);
	PlayerTextDrawSetOutline(playerid, text_warning[playerid], 0);
	PlayerTextDrawSetShadow(playerid, text_warning[playerid], 0);
	PlayerTextDrawAlignment(playerid, text_warning[playerid], 1);
	PlayerTextDrawColor(playerid, text_warning[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, text_warning[playerid], 255);
	PlayerTextDrawBoxColor(playerid, text_warning[playerid], 50);
	PlayerTextDrawUseBox(playerid, text_warning[playerid], 0);
	PlayerTextDrawSetProportional(playerid, text_warning[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, text_warning[playerid], 0);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	LoadNotif(playerid);
	return 1;
}

forward HideNotif2(playerid);
public HideNotif2(playerid)
{
	for(new txd; txd < 23; txd++)
	{
		PlayerTextDrawHide(playerid, BOXNOTIF[playerid][txd]);
	}
	PlayerTextDrawHide(playerid, text_info[playerid]);
	PlayerTextDrawHide(playerid, text_error[playerid]);
	PlayerTextDrawHide(playerid, text_suksek[playerid]);
	PlayerTextDrawHide(playerid, text_syntax[playerid]);
	PlayerTextDrawHide(playerid, text_warning[playerid]);
    PlayerNotif[playerid][barExists] = false;
    KillTimer(PlayerNotif[playerid][barTimer]);
	PlayerNotif[playerid][barTimer] = 0;
	return 1;
}

stock InfoMsg(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][0]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][1]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][2]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][3]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][4]);
	PlayerTextDrawShow(playerid, text_info[playerid]);
	PlayerTextDrawSetString(playerid, text_info[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}

stock ErrorMsg(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][5]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][6]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][7]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][8]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][9]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][10]);
	PlayerTextDrawShow(playerid, text_error[playerid]);
	PlayerTextDrawSetString(playerid, text_error[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}

stock SendErrorMessage(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][5]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][6]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][7]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][8]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][9]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][10]);
	PlayerTextDrawShow(playerid, text_error[playerid]);
	PlayerTextDrawSetString(playerid, text_error[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}

stock SyntaxMsg(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][16]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][17]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][18]);
	PlayerTextDrawShow(playerid, text_syntax[playerid]);
	PlayerTextDrawSetString(playerid, text_syntax[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}

stock SendSyntaxMessage(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][16]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][17]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][18]);
	PlayerTextDrawShow(playerid, text_syntax[playerid]);
	PlayerTextDrawSetString(playerid, text_syntax[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}

stock SuccesMsg(playerid, text[] = "", {Float,_}:...)
{
	if(PlayerNotif[playerid][barExists])
 		return printf("ERROR: Unable for creating Loadingbar for Player ID: %d!", playerid);
	
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][11]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][12]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][12]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][14]);
	PlayerTextDrawShow(playerid, BOXNOTIF[playerid][15]);
	PlayerTextDrawShow(playerid, text_suksek[playerid]);
	PlayerTextDrawSetString(playerid, text_suksek[playerid], text);
	PlayAudioStreamForPlayer(playerid, "https://cdn.discordapp.com/attachments/899154218160635964/1203680828475834448/notification.wav");
	
	PlayerNotif[playerid][barTimer] = SetTimerEx("HideNotif2", 5000, true, "d", playerid);
	return 1;
}