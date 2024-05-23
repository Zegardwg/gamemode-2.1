// Server Define
#define TEXT_GAMEMODE	"BETA version 5"
#define TEXT_WEBURL		"www.soi-rp.com"
#define TEXT_LANGUAGE	"Indonesia/English"

// MySQL configuration
#define		MYSQL_HOST 			"157.254.166.212"
#define		MYSQL_USER 			"u172_HiTSmYenvi"
#define		MYSQL_PASSWORD 		"ombN!B1Fa!xqBZKix!dLYXR6"
#define		MYSQL_DATABASE 		"s172_konoha_samp"
#define forex(%0,%1) for(new %0 = 0; %0 < %1; %0++)
// how many seconds until it kicks the player for taking too long to login
#define		SECONDS_TO_LOGIN 	200
#define FUNC::%0(%1) forward %0(%1); public %0(%1)
// default spawn point: Las Venturas (The High Roller)
#define 	DEFAULT_POS_X 		1744.3411
#define 	DEFAULT_POS_Y 		-1862.8655
#define 	DEFAULT_POS_Z 		13.3983
#define 	DEFAULT_POS_A 		270.0000
//Android Client Check
#define IsPlayerAndroid(%0)                 GetPVarInt(%0, "NotAndroid") == 0
// Message
#define function%0(%1) forward %0(%1); public %0(%1)
#define Servers(%1,%2) SendClientMessageEx(%1, ARWIN, "{15851d}[Info]: "WHITE_E""%2)
#define Info(%1,%2) SendClientMessageEx(%1, ARWIN, "{15851d}[Info]: "WHITE_E""%2)
#define Vehicle(%1,%2) SendClientMessageEx(%1, ARWIN, "[VEHICLE]: "WHITE_E""%2)
#define Usage(%1,%2) SendClientMessage(%1, ARWIN, ""GREY_E"[Syntax]: "WHITE_E""%2)
#define Error(%1,%2) SendClientMessageEx(%1, COLOR_GREY3, "{8B0000}[Error]: "WHITE_E""%2)
#define Warning(%1,%2) SendClientMessageEx(%1, COLOR_ORANGE, "[Warning]: "WHITE_E""%2)
#define Action(%1,%2) SendClientMessageEx(%1, COLOR_WHITE, "ACTION :  {D0AEEB}"%2)
#define PermissionError(%0) SendClientMessage(%0, COLOR_RED, "ERROR: "WHITE_E"You are not allowed to use this commands!")
new g_player_listitem[MAX_PLAYERS][96];
#define GetPlayerListitemValue(%0,%1) 		g_player_listitem[%0][%1]
#define SetPlayerListitemValue(%0,%1,%2) 	g_player_listitem[%0][%1] = %2


#define fn stock
#define PRESSED(%0) \
    (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
//Converter
#define Loop(%0,%1,%2) for(new %0 = %2; %0 < %1; %0++)
#define minplus(%1) \
        (((%1) < 0) ? (-(%1)) : ((%1)))

// AntiCaps
#define UpperToLower(%1) for( new ToLowerChar; ToLowerChar < strlen( %1 ); ToLowerChar ++ ) if ( %1[ ToLowerChar ]> 64 && %1[ ToLowerChar ] < 91 ) %1[ ToLowerChar ] += 32

// Banneds
const BAN_MASK = (-1 << (32 - (/*this is the CIDR ip detection range [def: 26]*/26)));

//---------[ Define Faction ]-----
#define SAPD	1		//locker 1573.26, -1652.93, -40.59
#define	SAGS	2		// 1464.10, -1790.31, 2349.68
#define SAMD	3		// -1100.25, 1980.02, -58.91
#define SANEW	4		// 256.14, 1776.99, 701.08