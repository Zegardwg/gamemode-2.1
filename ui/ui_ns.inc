#define popup_alert:: popup_m_
#define popup:: ntf_

#define MAX_POPUP 3
new BitArray:popup_bit[MAX_POPUP]<MAX_PLAYERS>;
new PlayerText:POPUP[MAX_PLAYERS][MAX_POPUP][3];

enum E_POPUP{
	Time,
	Lines,
	Text[512],
	Float:Pos_y,
	Float:Pos_y_text,
	TimeStamp,
	UniqueID
};
new popup[MAX_PLAYERS][MAX_POPUP][E_POPUP];

enum e_popup_type{
	TYPE_NORMAL,
	TYPE_ALERT
};
new BitArray:bit_popup_alert<MAX_PLAYERS>;
new PlayerText:TD_POPUP_ALERT[MAX_PLAYERS][6];
static Float:popup_alert_pb[MAX_PLAYERS];
static Float:popup_alert_save_progress[MAX_PLAYERS];

fn popup_alert::Show(clientid, const text[], time, const _icon[], const title[]){
	if(Bit_Get(bit_popup_alert, clientid)) popup_alert::Hide(clientid);
	TD_POPUP_ALERT[clientid][0] = CreatePlayerTextDraw(clientid, 313.750000, 348.386779, "LD_SPAC:white");
	PlayerTextDrawTextSize(clientid, TD_POPUP_ALERT[clientid][0], 16.000000, 16.000000);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][0], 1);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][0], 200);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][0], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][0], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][0], 4);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][0], 0);

	TD_POPUP_ALERT[clientid][1] = CreatePlayerTextDraw(clientid, 321.924591, 348.439910, _icon);
	PlayerTextDrawLetterSize(clientid, TD_POPUP_ALERT[clientid][1], 0.400000, 1.600000);
	PlayerTextDrawTextSize(clientid, TD_POPUP_ALERT[clientid][1], 0.000000, -52.000000);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][1], 2);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][1], -1);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][1], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][1], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][1], 0);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][1], 1);

	TD_POPUP_ALERT[clientid][2] = CreatePlayerTextDraw(clientid, 322.500000, 367.106872, title);
	PlayerTextDrawLetterSize(clientid, TD_POPUP_ALERT[clientid][2], 0.306874, 1.450664);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][2], 2);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][2], -222166273);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][2], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][2], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][2], 1);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][2], 1);

	TD_POPUP_ALERT[clientid][3] = CreatePlayerTextDraw(clientid, 280.000000, 381.986694, "LD_SPAC:white");
	PlayerTextDrawTextSize(clientid, TD_POPUP_ALERT[clientid][3], 82.000000, 5.229991);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][3], 1);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][3], 336794111);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][3], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][3], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][3], 4);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][3], 0);

	//79.900009 - 0.000000
	TD_POPUP_ALERT[clientid][4] = CreatePlayerTextDraw(clientid, 280.749908, 383.486572, "LD_SPAC:white");
	PlayerTextDrawTextSize(clientid, TD_POPUP_ALERT[clientid][4], 79.900009, 2.499993);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][4], 1);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][4], -471936001);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][4], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][4], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][4], 4);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][4], 0);

	TD_POPUP_ALERT[clientid][5] = CreatePlayerTextDraw(clientid, 321.250000, 390.853363, text);
	PlayerTextDrawLetterSize(clientid, TD_POPUP_ALERT[clientid][5], 0.201874, 1.039999);
	PlayerTextDrawTextSize(clientid, TD_POPUP_ALERT[clientid][5], 0.000000, 269.375000);
	PlayerTextDrawAlignment(clientid, TD_POPUP_ALERT[clientid][5], 2);
	PlayerTextDrawColor(clientid, TD_POPUP_ALERT[clientid][5], -136);
	PlayerTextDrawSetShadow(clientid, TD_POPUP_ALERT[clientid][5], 0);
	PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][5], 255);
	PlayerTextDrawFont(clientid, TD_POPUP_ALERT[clientid][5], 1);
	PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][5], 1);

	new Float:divvv = 79.900009/time/10.5;

	popup_alert_pb[clientid] = divvv;
	for(new i; i < 6; i++) PlayerTextDrawShow(clientid, TD_POPUP_ALERT[clientid][i]);
	Bit_Set(bit_popup_alert, clientid, true);

	SetTimerEx("popup_m_Hide", time * 1000, false, "d", clientid);
}

function popup_alert::Hide(clientid){
	popup_alert_pb[clientid] = 0.0;
	popup_alert_save_progress[clientid] = 0.0;
	for(new i; i < 6; i++) PlayerTextDrawDestroy(clientid, TD_POPUP_ALERT[clientid][i]);
	Bit_Set(bit_popup_alert, clientid, false);
}

//10 veces por segundo
//50 veces por 5s
/*
100.0/10 = 10


*/
ptask UpdatePBAlert[100](clientid){
	if(Bit_Get(bit_popup_alert, clientid)){
		//79.900009
		if(popup_alert_save_progress[clientid] > 79.900009){
			popup_alert_save_progress[clientid] = 79.900009;
		}
		if(popup_alert_save_progress[clientid] == 79.900009) return 0;
		//PlayerTextDrawDestroy(clientid, TD_POPUP_ALERT[clientid][4]);
		popup_alert_save_progress[clientid] += popup_alert_pb[clientid];
		// TD_POPUP_ALERT[clientid][4] = CreatePlayerTextDraw(clientid, 280.749908, 383.486572, "LD_SPAC:white");
		PlayerTextDrawTextSize(clientid, 		TD_POPUP_ALERT[clientid][4], popup_alert_save_progress[clientid], 2.499993);
		// PlayerTextDrawAlignment(clientid, 		TD_POPUP_ALERT[clientid][4], 1);
		// PlayerTextDrawColor(clientid, 			TD_POPUP_ALERT[clientid][4], -471936001);
		// PlayerTextDrawSetShadow(clientid, 		TD_POPUP_ALERT[clientid][4], 0);
		// PlayerTextDrawBackgroundColor(clientid, TD_POPUP_ALERT[clientid][4], 255);
		// PlayerTextDrawFont(clientid, 			TD_POPUP_ALERT[clientid][4], 4);
		// PlayerTextDrawSetProportional(clientid, TD_POPUP_ALERT[clientid][4], 0);

		PlayerTextDrawShow(clientid, TD_POPUP_ALERT[clientid][4]);
	}
	return 1;
}

CMD:ns(playerid, params[])
{
    popup_alert::Show(playerid, "Hallo semuanya", 3, "!", "Alert");    
    return 1;
}