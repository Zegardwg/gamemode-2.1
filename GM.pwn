#include <a_samp>
#undef MAX_PLAYERS
#define MAX_PLAYERS	500
#include <crashdetect.inc> 
#include <a_http>
#include <gvar.inc>
#include <a_mysql.inc>
#include <a_actor.inc>
#include <a_zones.inc>

#include <CTime.inc>
#include <strlib>
#include <Dini.inc>

#include <progress2.inc>

#include <Pawn.CMD.inc>
#include <mSelection.inc>
#include <TimestampToDate.inc>
#define ENABLE_3D_TRYG_YSI_SUPPORT
#include <3DTryg.inc>
#include <EVF2.inc>
#include <YSI\y_timers>
#include <streamer.inc>
#include <sscanf2.inc>
#include <cuff.inc>
#include <yom_buttons.inc>
#include <geoiplite.inc>
#include <garageblock.inc>
#include <timerfix.inc>
#include <textdraw-streamer>
#include <easyDialog>
#include <sampvoice>
#define DEBUG
#include <nex-ac_en.lang> //or any other
#include <rhnaAC>
#include <OnlineMusic>
#include "DEFINE.pwn"

enum
{
	//---[ DIALOG PUBLIC ]---
	DIALOG_UNUSED,
    DIALOG_LOGIN,
    DIALOG_REGISTER,
    DIALOG_AGE,
	DIALOG_GENDER,
	//---[ DIALOG BISNIS ]---
	DIALOG_SELL_BISNISS,
	DIALOG_SELL_BISNIS,
	DIALOG_MY_BISNIS,
	BISNIS_MENU,
	BISNIS_INFO,
	BISNIS_NAME,
	BISNIS_VAULT,
	BISNIS_WITHDRAW,
	BISNIS_DEPOSIT,
	BISNIS_BUYPROD,
	DIALOG_CHARLIST,
	DIALOG_VERIFIKASI,	
	BISNIS_EDITPROD,
	BISNIS_PRICESET,
	//---[ DIALOG HOUSE ]---
	DIALOG_SELL_HOUSES,
	DIALOG_SELL_HOUSE,
	DIALOG_MY_HOUSES,
	HOUSE_INFO,
	HOUSE_STORAGE,
	HOUSE_WEAPONS,
	HOUSE_MONEY,
	DIALOG_PAYBILL,
	DIALOG_MAKE_CHAR,
	HOUSE_WITHDRAWMONEY,
	HOUSE_DEPOSITMONEY,
	//---[ DIALOG PRIVATE VEHICLE ]---
	DIALOG_FINDVEH,
	DIALOG_TRACKVEH,
	DIALOG_GOTOVEH,
	DIALOG_GETVEH,
	DIALOG_DELETEVEH,
	DIALOG_BUYPV,
	DIALOG_BUYVIPPV,
	DIALOG_BUYPLATE,
	DIALOG_BUYPVCP,
	DIALOG_BUYPVCP_BIKES,
	DIALOG_BUYPVCP_UCARS,
	DIALOG_BUYPVCP_JOBCARS,
	DIALOG_BUYPVCP_CONFIRM,
	//---[ DIALOG TOYS ]---
	DIALOG_TOY,
	DIALOG_TOYEDIT,
	DIALOG_TOYPOSISI,
	DIALOG_TOYPOSISIBUY,
	DIALOG_TOYBUY,
	DIALOG_TOYVIP,
	//---[ DIALOG PLAYER ]---
	DIALOG_HELP,
	DIALOG_GPS,
	DIALOG_GPS_JOB,
	DIALOG_PAY,
	//---[ DIALOG WEAPONS ]---
	DIALOG_EDITBONE,
	//---[ DIALOG FAMILY ]---
	FAMILY_SAFE,
	FAMILY_STORAGE,
	FAMILY_WEAPONS,
	//---[ DIALOG FACTION ]---
	DIALOG_LOCKERSAPD,
	DIALOG_WEAPONSAPD,
	DIALOG_LOCKERSAGS,
	DIALOG_WEAPONSAGS,
	DIALOG_LOCKERSAMD,
	DIALOG_WEAPONSAMD,
	DIALOG_LOCKERSANEW,
	DIALOG_WEAPONSANEW,
	
	DIALOG_LOCKERVIP,
	//---[ DIALOG JOB ]---
	//MECH
	DIALOG_SERVICE,
	DIALOG_SERVICE_COLOR,
	DIALOG_SERVICE_COLOR2,
	DIALOG_SERVICE_PAINTJOB,
	//Trucker
	DIALOG_RESTOCK,
	
	//----[ Items ]-----
	DIALOG_MATERIAL,
	DIALOG_COMPONENT,
	DIALOG_PRODUCT,
	DIALOG_APOTEK,
	//Bank
	DIALOG_BANK,
	DIALOG_BANKDEPOSIT,
	DIALOG_BANKWITHDRAW,
	DIALOG_BANKREKENING,
	DIALOG_BANKTRANSFER,
	DIALOG_BANKCONFIRM,
	DIALOG_BANKSUKSES,
	
	//reports
	DIALOG_REPORTS,
	DIALOG_SALARY,
	DIALOG_PAYCHECK,
	
	// PHONE
	DIALOG_PHONE,
	DIALOG_MBANK,
	DIALOG_APPSTORE,

	//Sidejob
	DIALOG_SWEEPER,
	DIALOG_BUS,

	DIALOG_SHOWKTP,
	DIALOG_SHOWSIM,
	DIALOG_SHOWBPJS,
	DIALOG_SHOWSKS,
	DIALOG_SHOWSKCK,
	//--[ VEHICLE STORAGE]--
	VEHICLE_STORAGE,

	VEHICLE_WEAPONS,

	//NEW VSTORAGE
	VEHICLE_WEAPON,
	VEHICLE_OTHER,
	VEHICLE_SEED1,
	VEHICLE_SEED_WITHDRAW1,
	VEHICLE_SEED_DEPOSIT1,
	VEHICLE_MATERIAL1,
	VEHICLE_MATERIAL_WITHDRAW1,
	VEHICLE_MATERIAL_DEPOSIT1,
	VEHICLE_MARIJUANA1,
	VEHICLE_MARIJUANA_WITHDRAW1,
	VEHICLE_MARIJUANA_DEPOSIT1,
	VEHICLE_COMPONENT1,
	VEHICLE_COMPONENT_WITHDRAW1,
	VEHICLE_COMPONENT_DEPOSIT1,
	//
	VEHICLE_MONEY,
	VEHICLE_DEPOSITMONEY,
	VEHICLE_WITHDRAWMONEY,

	VEHICLE_COMPONENT,
	VEHICLE_DEPOSITCOMPONENT,
	VEHICLE_WITHDRAWCOMPONENT,

	VEHICLE_MATERIAL,
	VEHICLE_DEPOSITMATERIAL,
	VEHICLE_WITHDRAWMATERIAL,

	VEHICLE_SEED,
	VEHICLE_DEPOSITSEED,
	VEHICLE_WITHDRAWSEED,

	VEHICLE_MARIJUANA,
	VEHICLE_DEPOSITMARIJUANA,
	VEHICLE_WITHDRAWMARIJUANA,
	DIALOG_GIVE,
	//Gojek
	DIALOG_GOJEK,
	DIALOG_GOPAY,
	DIALOG_GOTOPUP,
	DIALOG_GOFOOD,
	DIALOG_GOCAR,
	//CONTACT
	DIALOG_ADDCTRESPONSE,
	DIALOG_ADDCT,
	DIALOG_EDITCTRESPONSE,
	DIALOG_EDITCTMENU,
	DIALOG_EDITNAMECT,
	DIALOG_EDITNUMBERCT,
	DIALOG_SENDMSGCT,
	TWITTER_MENU,
	TWITTER_NAME,
	TWITTER_POST,
	ADSLOG_LIST,
	DIALOG_TOGGLEPHONE,
	DIALOG_PANELPHONE,
	DIALOG_PHONE_SENDSMS,
	DIALOG_SHARELOC,
	DIALOG_PHONE_TEXTSMS,
	DIALOG_PHONE_DIALUMBER,	
	DIALOG_ATMREKENING,
	MYTAX_MENU,
	DIALOG_WASSAP,
	//---[ MENU VEHICLE ]---
	DIALOG_MYVEH,
	DIALOG_MYVEH_INFO,
	DIALOG_VMENU,
	GARKOT_PICKUP,
	//trunk
	DIALOG_TRUNK,
	DIALOG_TRUNKWEAPON,
	DIALOG_TRUNKTAKE,
	DIALOG_TRUNKOPTION,
	DIALOG_TRUNKPUT,					
}
enum
{
	EDIT_NONE,
	EDIT_GATE,
};

// Countdown
new Count = -1;
new countTimer;
new showCD[MAX_PLAYERS];
new CountText[5][5] =
{
	"~r~1",
	"~g~2",
	"~y~3",
	"~g~4",
	"~b~5"
};

// Server Uptime
new up_days,
	up_hours,
	up_minutes,
	up_seconds;

//Model Selection 
new SpawnMale = mS_INVALID_LISTID,
	SpawnFemale = mS_INVALID_LISTID,
	MaleSkins = mS_INVALID_LISTID,
	FemaleSkins = mS_INVALID_LISTID,
	VIPMaleSkins = mS_INVALID_LISTID,
	VIPFemaleSkins = mS_INVALID_LISTID,
	SAPDMale = mS_INVALID_LISTID,
	SAPDFemale = mS_INVALID_LISTID,
	SAPDWar = mS_INVALID_LISTID,
	SAGSMale = mS_INVALID_LISTID,
	SAGSFemale = mS_INVALID_LISTID,
	SAMDMale = mS_INVALID_LISTID,
	SAMDFemale = mS_INVALID_LISTID,
	SANEWMale = mS_INVALID_LISTID,
	SANEWFemale = mS_INVALID_LISTID,
	toyslist = mS_INVALID_LISTID,
	viptoyslist = mS_INVALID_LISTID;

#define VEHICLE_RESPAWN 7200

new SAPDVehicles[30],
	SAGSVehicles[30],
	SAMDVehicles[30],
	SANAVehicles[30];

new Text:notifTD[2],
    timernotif[MAX_PLAYERS];
	
//Showroom Checkpoint
new ShowRoomCP;
	
/*// Button and Doors
new SAGSLobbyBtn[2],
	SAGSLobbyDoor;
new gMyButtons[2],
	gMyDoor;*/
	
/*//Keypad Txd
new SAGSLobbyKey[2],
	SAGSLobbyDoor;
*/

// Yom Button
new SAGSLobbyBtn[2],
	SAGSLobbyDoor,
	SAPDLobbyBtn[4],
	SAPDLobbyDoor[4];

// MySQL connection handle
new MySQL: g_SQL;

new TogOOC = 1;

// Player data
enum E_PLAYERS
{
	pID,
	pVerfi[64],
	pVerifikasi,
	pUCP[22],
	pExtraChar,
	pTempPass[64],
	pChar,		
	pName[MAX_PLAYER_NAME],
	pAdminname[MAX_PLAYER_NAME],
	pTwittername[MAX_PLAYER_NAME],
	pIP[16],
	pPassword[65],
	pSalt[17],
	pEmail[24],
	pAdmin,
	pHelper,
	pLevel,
	pLevelUp,
	pVip,
	pVipTime,
	pCoin,
	pRegDate[50],
	pLastLogin[50],
	pMoney,
	pBankMoney,
	pBankRek,
	pPhone,
	pPhoneCredit,
	pSMS,
	pCall,
	pHours,
	pMinutes,
	pSeconds,
	pPaycheck,
	PilihSpawn,
	pTarget,
	pSkin,
	pFacSkin,
	pGender,
	pAge[50],
	pInDoor,
	pInHouse,
	pInBiz,
	Float: pPosX,
	Float: pPosY,
	Float: pPosZ,
	Float: pPosA,
	pInt,
	pWorld,
	Float:pHealth,
    Float:pArmour,
	pHunger,
	pBladder,
	pEnergy,
	pHungerTime,
	pEnergyTime,
	pBladderTime,
	pSick,
	pSpaTime,
	pSickTime,
	pHospital,
	pHospitalTime,
	pInjured,
	pInjuredTime,
	pOnDuty,
	pOnDutyTime,
	pFaction,
	pFactionRank,
	pFactionLead,
	pTazer,
	pBroadcast,
	pNewsGuest,
	pFamily,
	pFamilyRank,
	pJail,
	pArrest,
	pArrestTime,
	pWarn,
	pJob,
	pJob2,
	pJobTime,
	PlayerJob,
	pMedicine,
	pMedkit,
	pMask,
	pHelmet,
	pSnack,
	pTas,
	pKacamata,	
	pSprunk,
	Float:pPos[4],
	pListitem,
	pGas,
	pBandage,
	pGPS,
	pStorageSelect,
	pMaterial,
	pComponent,
	pIDCard,
	pIDCardTime,
	pDriveLic,
	pCar,
	pStorageItem,	
	pDriveLicTime,
	pBoatLic,
	pBoatLicTime,
	pFlyLic,
	pFlyLicTime,
	pGuns[13],
    pAmmo[13],
	pWeapon,
	//Not Save
	pRenting,
	Cache: Cache_ID,
	bool: IsLoggedIn,
	LoginAttempts,
	LoginTimer,
	pSpawned,
	pAdminDuty,
	pFreezeTimer,
	pFreeze,
	pMaskID,
	pMaskOn,
	pSPY,
	pTogPM,
	pTogLog,
	Text3D:pAdoTag,
	bool:pAdoActive,
	pFlare,
	bool:pFlareActive,
	pTrackCar,
	pBuyPvModel,
	pTrackHouse,
	pTrackBisnis,
	pFillPrice,
	pFill,
    pFuelMoney,
    pFuelCar,	
	pFacInvite,
	pFacOffer,
	pFindEms,
	pCuffed,
	pCallTime,
	toySelected,
	bool:PurchasedToy,
	pEditingItem,
	pProductModify,
	pCurrSeconds,
	pCurrMinutes,
	pCurrHours,
	pSpec,
	playerSpectated,
	pFriskOffer,
	pDragged,
	pDraggedBy,
	pDragTimer,
	pHideHBE,
	pHideSpeedo,
	pHelmetOn,
	pSeatBelt,
	pReportTime,
	//Player Progress Bar
	PlayerBar:fuelbar,
	PlayerBar:damagebar,
	PlayerBar:hungrybar,
	PlayerBar:energybar,
	PlayerBar:bladdybar,
	PlayerBar:activitybar,
	pActivity,
	pActivityTime,
	//Jobs
	pSideJob,
	pSideJobTime,
	pGetJob,
	pGetJob2,
	pTaxiDuty,
	pTaxiTime,
	pFare,
	pGiveAmount,
	pFareTimer,
	pTotalFare,
	Float:pFareOldX,
	Float:pFareOldY,
	pSelectItem,
	Float:pWeight,
	Float:pFareOldZ,
	Float:pFareNewX,
	Float:pFareNewY,
	Float:pFareNewZ,
	pMechDuty,
	pMechVeh,
	pMechColor1,
	pMechColor2,
	//lumber job
	EditingTreeID,
	CuttingTreeID,
	bool:CarryingLumber,
	//Miner job
	EditingOreID,
	MiningOreID,
	CarryingLog,
	LoadingPoint,
	//production
	CarryProduct,
	//trucker
	pMission,
	pTransfer,
	pTransferRek,
	pTransferName[128],
	//progressbar
	pProgress,

	pGpsIns,
	pTwtIns,
	pAonaIns,

	pTinggi[32],
	pEditing,
	pBerat[32],
	pEditGate,
	pEditType,	
	pOrigin[32],
	pUsePhone,
	pGopay,
	pLocOffer,
	pContact,
	pTogAds,
	EditingATMID,
	pGetPARKID,

	UseCreatine,
	UseProtein,

	//ktp
	pKtp,
	pKompensasi,

	Pilkada,	
    pHoldWeapon,
	pUsedMagazine,

	//afk
	Float:pAFKPos[6],
	pAFK,
	pAFKTime			
};
new pData[MAX_PLAYERS][E_PLAYERS];
new g_MysqlRaceCheck[MAX_PLAYERS];
#define AccountData pData
#define PlayerData pData
enum
{
	LIMIT_SNACK,
	LIMIT_SPRUNK,
	LIMIT_MEDICINE,
	LIMIT_MEDKIT,
 	LIMIT_BANDAGE,
 	LIMIT_SEED,
	LIMIT_MATERIAL,
	LIMIT_COMPONENT,
	LIMIT_MARIJUANA
};
//
new g_aMaleSkins[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 32, 33, 34, 35, 36, 37, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 57, 58, 59, 60,
	61, 62, 66, 68, 72, 73, 80, 81, 82, 83, 84, 94, 95, 96, 97, 98, 100, 101, 102,
	103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
	121, 122, 123, 124, 125, 126, 127, 128, 132, 133, 134, 135, 136, 137, 142, 143, 144, 146,
	147, 153, 154, 155, 156, 158, 159, 160, 161, 162, 167, 168, 170, 171, 173, 174, 175, 176,
	177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 200, 202, 203, 204, 206,
	208, 209, 210, 212, 213, 217, 220, 221, 222, 223, 228, 229, 230, 234, 235, 236, 239, 240,
	241, 242, 247, 248, 249, 250, 253, 254, 255, 258, 259, 260, 261, 262, 268, 272, 273, 289,
	290, 291, 292, 293, 294, 295, 296, 297, 299
};
new g_aFemaleSkins[] = {
    9, 10, 11, 12, 13, 31, 40, 41, 55, 56, 65, 69,
    77, 85, 88, 89, 90, 91, 93, 130, 138, 141,
    145, 148, 150, 151, 152, 157, 169, 178, 190, 191, 192, 193, 194, 195,
    196, 197, 198, 199, 201, 205, 207, 211, 214, 215, 216, 219, 224, 225,
    226, 231, 232, 233, 237, 238, 243, 244, 245, 246, 251, 256, 257, 263,
    298
};

//---------[ Ores miner Job Log ]-------	
#define LOG_LIFETIME 100
#define LOG_LIMIT 10
#define MAX_LOG 100

enum    E_LOG
{
	// temp
	bool:logExist,
	logType,
	logDroppedBy[MAX_PLAYER_NAME],
	logSeconds,
	logObjID,
	logTimer,
	Text3D:logLabel
}
new LogData[MAX_LOG][E_LOG];

new
	LogStorage[MAX_VEHICLES][2];

enum E_LDC
{
	LDC_ID, Text3D:LDC_LABEL, LDC_TIMER
}
new g_ldc[2000][E_LDC];
new Iterator: LDCS<2000>;

new JamCall[MAX_PLAYERS];
new DetikCall[MAX_PLAYERS];
new MenitCall[MAX_PLAYERS];
new SV_GSTREAM:OnPhone[MAX_PLAYERS];
//Voice
new ToggleCall[MAX_PLAYERS];
new CallTimer[MAX_PLAYERS];
//atm
new amountWithdraw[MAX_PLAYERS];
new amountDeposit[MAX_PLAYERS];
//------[ Trucker ]--------

new VehProduct[MAX_VEHICLES];
//sid
new sidSystem[MAX_PLAYERS], STREAMER_TAG_3D_TEXT_LABEL:sid3dtext[MAX_PLAYERS];	
//-----[ Modular ]-----
main() 
{
	SetTimer("onlineTimer", 1000, true);
	SetTimer("TDUpdates", 8000, true);
}
#include "COLOR.pwn"
#include "BILLS.pwn"
//dynamic inventory
#include "inventory\inventory_functions"
#include "TEXTDRAW.pwn"
#include "ANIMS.pwn"
#include "UCP.pwn"
#include "FUNCTION.pwn"
#include "REPORT.pwn"
#include "WEAPON_ATTH.pwn"
#include "TOYS.pwn"
#include "HELMET.pwn"
#include "PRIVATE_VEHICLE.pwn"
#include "FAMILY.pwn"
#include "HOUSE.pwn"
#include "BISNIS.pwn"
#include "DYNAMIC_LOCKER.pwn"
#include "SERVER.pwn"
#include "NATIVE.pwn"
#include "MAPPING.pwn"
//veh storage
#include "systems\VStorage"
#include "systems\phonebook"
#include "systems\adslog_functions"
#include "dynamic\Dynamic_Garkot"
#include "systems\dealer_functions"
#include "DIALOG.pwn"
#include "VOUCHER.pwn"
#include "SALARY.pwn"
#include "TEXTDRAW_CLICK.pwn"
//#include "AUDIO.pwn"
#include "jobs\JOB_TAXI.pwn"
#include "jobs\JOB_MECH.pwn"
#include "jobs\JOB_MINER.pwn"
#include "jobs\JOB_PRODUCTION.pwn"

#include "CMD\ADMIN.pwn"
#include "CMD\FACTION.pwn"
#include "CMD\PLAYER.pwn"

#include "CMD\ALIAS\ALIAS_ADMIN.pwn"

//User Interface
#include "ui\ui_progressbar"
#include "ui\ui_notif"
#include "ui\ui_showitem"
#include "ui\ui_info"
#include "ui\ui_alert"
#include "ui\ui_announcement"
#include "ui\ui_dmadm"
#include "ui\ui_ns"
//hud
#include "hud\hud_functions"
//dynamic data
#include "dynamic\Dynamic_GasStation"
#include "dynamic\Dynamic_Door"
#include "dynamic\Dynamic_Atm"
#include "dynamic\Dynamic_Rental"
#include "dynamic\Dynamic_Gate"
#include "dynamic\Dynamic_Market"
//////////////////JOBS///////////////////////
#include "jobs\butcher\butcher_functions"
#include "jobs\tailor\tailor_functions"
//disnaker
#include "systems\disnaker_functions"
//ikea
#include "systems\ikea_functions"
//other systems
#include "systems\me_functions"
#include "systems\do_functions"
#include "systems\gym_functions"
#include "systems\asuransi_functions"
#include "systems\konter_functions"
#include "systems\kompensasi_functions"
#include "systems\callvoice_functions"
#include "systems\pilkada_functions"
#include "systems\clip_functions"
#include "systems\idleanim_functions"
//faction
#include "faction\police_functions"
#include "faction\medic_functions"
//ilegal
#include "ilegal\kanabis_functions"

public OnGameModeInit()
{
	//mysql_log(ALL);
	new MySQLOpt: option_id = mysql_init_options();

	mysql_set_option(option_id, AUTO_RECONNECT, true);

	g_SQL = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE, option_id);
	if (g_SQL == MYSQL_INVALID_HANDLE || mysql_errno(g_SQL) != 0)
	{
		print("MySQL connection failed. Server is shutting down.");
		SendRconCommand("exit");
		return 1;
	}
	print("Berhasi terhubung kedalam Database server");

	mysql_tquery(g_SQL, "SELECT * FROM `gates`", "Gate_Load", "");
	mysql_tquery(g_SQL, "SELECT * FROM `markets`", "LoadMarket");
	mysql_tquery(g_SQL, "SELECT * FROM `barangmedis`", "LoadBarangMedis");
	mysql_tquery(g_SQL, "SELECT * FROM `garkot`", "LoadGarkot");
	mysql_tquery(g_SQL, "SELECT * FROM `rental`", "Rental_Load", "");
	mysql_tquery(g_SQL, "SELECT * FROM `atms`", "LoadATM");
	mysql_tquery(g_SQL, "SELECT * FROM `bill`", "LoadBill");
	mysql_tquery(g_SQL, "SELECT * FROM `gstations`", "LoadGStations");
	mysql_tquery(g_SQL, "SELECT * FROM `doors`", "LoadDoors");
	mysql_tquery(g_SQL, "SELECT * FROM `familys`", "LoadFamilys");
	mysql_tquery(g_SQL, "SELECT * FROM `houses`", "LoadHouses");
	mysql_tquery(g_SQL, "SELECT * FROM `bisnis`", "LoadBisnis");
	mysql_tquery(g_SQL, "SELECT * FROM `lockers`", "LoadLockers");
	mysql_tquery(g_SQL, "SELECT * FROM `vouchers`", "LoadVouchers");
	mysql_tquery(g_SQL, "SELECT * FROM `ores`", "LoadOres");
	mysql_tquery(g_SQL, "SELECT * FROM `server`", "LoadServer");
	
	CreateTextDraw();
	LoadMapping();
	CreateServerPoint();
	CreateJoinTaxiPoint();
	CreateJoinMechPoint();
	CreateJoinMinerPoint();
	CreateJoinProductionPoint();
	
	new gm[32];
	format(gm, sizeof(gm), "%s", TEXT_GAMEMODE);
	SetGameModeText(gm);
	format(gm, sizeof(gm), "weburl %s", TEXT_WEBURL);
	SendRconCommand(gm);
	format(gm, sizeof(gm), "language %s", TEXT_LANGUAGE);
	SendRconCommand(gm);

	SendRconCommand("hostname Konoha Roleplay | #KonohaMerakyat");
	SendRconCommand("mapname San Andreas");
	ManualVehicleEngineAndLights();
	EnableStuntBonusForAll(0);
	AllowInteriorWeapons(1);
	DisableInteriorEnterExits();
	ShowNameTags(0);
	LimitPlayerMarkerRadius(15.0);
	SetNameTagDrawDistance(20.0);

	ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
	SetWorldTime(10);
	SetWeather(24);
	BlockGarages(.text="NO ENTER");	
	SpawnMale = LoadModelSelectionMenu("spawnmale.txt");
	SpawnFemale = LoadModelSelectionMenu("spawnfemale.txt");
	MaleSkins = LoadModelSelectionMenu("maleskin.txt");
	FemaleSkins = LoadModelSelectionMenu("femaleskin.txt");
	VIPMaleSkins = LoadModelSelectionMenu("maleskin.txt");
	VIPFemaleSkins = LoadModelSelectionMenu("femaleskin.txt");
	SAPDMale = LoadModelSelectionMenu("sapdmale.txt");
	SAPDFemale = LoadModelSelectionMenu("sapdfemale.txt");
	SAPDWar = LoadModelSelectionMenu("sapdwar.txt");
	SAGSMale = LoadModelSelectionMenu("sagsmale.txt");
	SAGSFemale = LoadModelSelectionMenu("sagsfemale.txt");
	SAMDMale = LoadModelSelectionMenu("samdmale.txt");
	SAMDFemale = LoadModelSelectionMenu("samdfemale.txt");
	SANEWMale = LoadModelSelectionMenu("sanewmale.txt");
	SANEWFemale = LoadModelSelectionMenu("sanewfemale.txt");
	toyslist = LoadModelSelectionMenu("toys.txt");
	viptoyslist = LoadModelSelectionMenu("viptoys.txt");
	printf("[Object] Number of Dynamic objects loaded: %d", CountDynamicObjects());
	return 1;
}

public OnGameModeExit()
{
	new count = 0;
	foreach(new gsid : GStation)
	{
		if(Iter_Contains(GStation, gsid))
		{
			count++;
			GStation_Save(gsid);
		}
	}
	printf("[Gas Station] Number of Saved: %d", count);	
	for (new i = 0, j = GetPlayerPoolSize(); i <= j; i++) 
	{
		if (IsPlayerConnected(i))
		{
			OnPlayerDisconnect(i, 1);
		}
	}
	//Audio_DestroyTCPServer();
	mysql_close(g_SQL);
	return 1;
}

function SAGSLobbyDoorClose()
{
	MoveDynamicObject(SAGSLobbyDoor, 1389.375000, -25.387500, 999.978210, 3);
	return 1;
}

function SAPDLobbyDoorClose()
{
	MoveDynamicObject(SAPDLobbyDoor[0], 253.10965, 107.61060, 1002.21368, 3);
	MoveDynamicObject(SAPDLobbyDoor[1], 253.12556, 110.49657, 1002.21460, 3);
	MoveDynamicObject(SAPDLobbyDoor[2], 239.69435, 116.15908, 1002.21411, 3);
	MoveDynamicObject(SAPDLobbyDoor[3], 239.64050, 119.08750, 1002.21332, 3);
	return 1;
}

public OnPlayerPressButton(playerid, buttonid)
{
	if(buttonid == SAGSLobbyBtn[0] || buttonid == SAGSLobbyBtn[1])
	{
	    if(pData[playerid][pFaction] == 2)
	    {
	        MoveDynamicObject(SAGSLobbyDoor, 1387.9232, -25.3887, 999.9782, 3);
			SetTimer("SAGSLobbyDoorClose", 5000, 0);
	    }
		else
	    {
	        Error(playerid, "Access denied.");
			return 1;
		}
	}
	if(buttonid == SAPDLobbyBtn[0] || buttonid == SAPDLobbyBtn[1])
	{
		if(pData[playerid][pFaction] == 1)
		{
			MoveDynamicObject(SAPDLobbyDoor[0], 253.14204, 106.60210, 1002.21368, 3);
			MoveDynamicObject(SAPDLobbyDoor[1], 253.24377, 111.94370, 1002.21460, 3);
			SetTimer("SAPDLobbyDoorClose", 5000, 0);
		}
		else
	    {
	        Error(playerid, "Access denied.");
			return 1;
		}
	}
	if(buttonid == SAPDLobbyBtn[2] || buttonid == SAPDLobbyBtn[3])
	{
		if(pData[playerid][pFaction] == 1)
		{
			MoveDynamicObject(SAPDLobbyDoor[2], 239.52385, 114.75534, 1002.21411, 3);
			MoveDynamicObject(SAPDLobbyDoor[3], 239.71977, 120.21591, 1002.21332, 3);
			SetTimer("SAPDLobbyDoorClose", 5000, 0);
		}
		else
	    {
	        Error(playerid, "Access denied.");
			return 1;
		}
	}
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
		if(GetVehicleModel(vehicleid) == 548 || GetVehicleModel(vehicleid) == 417 || GetVehicleModel(vehicleid) == 487 || GetVehicleModel(vehicleid) == 488 ||
		GetVehicleModel(vehicleid) == 497 || GetVehicleModel(vehicleid) == 563 || GetVehicleModel(vehicleid) == 469)
		{
			if(pData[playerid][pLevel] < 5)
			{
				RemovePlayerFromVehicle(playerid);
			    new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz);
				Error(playerid, "Anda tidak memiliki izin!");
			}
		}
	}
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(isnull(text)) return 0;
	printf("[CHAT] %s(%d) : %s", pData[playerid][pName], playerid, text);
	
	if(pData[playerid][pSpawned] == 0 && pData[playerid][IsLoggedIn] == false)
	{
	    Error(playerid, "You must be spawned or logged in to use chat.");
	    return 0;
	}
	if(text[0] == '@')
	{
		if(pData[playerid][pSMS] != 0)
		{
			if(pData[playerid][pPhoneCredit] < 1)
			{
				Error(playerid, "You dont have phone credits!");
				return 0;
			}
			if(pData[playerid][pInjured] != 0)
			{
				Error(playerid, "You cant do at this time.");
				return 0;
			}
			new tmp[512];
			foreach(new ii : Player)
			{
				if(text[1] == ' ')
				{
			 		format(tmp, sizeof(tmp), "%s", text[2]);
				}
				else
				{
				    format(tmp, sizeof(tmp), "%s", text[1]);
				}
				if(pData[ii][pPhone] == pData[playerid][pSMS])
				{
					if(ii == INVALID_PLAYER_ID || !IsPlayerConnected(ii))
					{
						Error(playerid, "This number is not actived!");
						return 0;
					}
					SendClientMessageEx(playerid, COLOR_YELLOW, "[SMS to %d]"WHITE_E" %s", pData[playerid][pSMS], tmp);
					SendClientMessageEx(ii, COLOR_YELLOW, "[SMS from %d]"WHITE_E" %s", pData[playerid][pPhone], tmp);
					PlayerPlaySound(ii, 6003, 0,0,0);
					pData[ii][pSMS] = pData[playerid][pPhone];
					
					pData[playerid][pPhoneCredit] -= 1;
					return 0;
				}
			}
		}
	}
	if(pData[playerid][pCall] != INVALID_PLAYER_ID)
	{
		// Anti-Caps
		if(GetPVarType(playerid, "Caps"))
			UpperToLower(text);
		new lstr[1024];
		format(lstr, sizeof(lstr), "(cellphone) %s says: %s", ReturnName(playerid), text);
		ProxDetector(10, playerid, lstr, 0xE6E6E6E6, 0xC8C8C8C8, 0xAAAAAAAA, 0x8C8C8C8C, 0x6E6E6E6E);
		SetPlayerChatBubble(playerid, text, COLOR_WHITE, 10.0, 3000);
		
		SendClientMessageEx(pData[playerid][pCall], COLOR_YELLOW, "[CELLPHONE] "WHITE_E"%s.", text);
		return 0;
	}
	else
	{
		return 0;
	}
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
    if (result == -1)
    {
		SendClientMessageEx(playerid, -1, "{00FF00}[CMD]: {FFFFFF}The command '{FF0000}/%s{FFFFFF}' is unknown, check {FFFF00}/help{FFFFFF} to see the list of available commands", cmd);
		printf("[UNKOWNW CMD]: %s(%d) has used the command '%s' (%s)", pData[playerid][pName], playerid, cmd, params);
        return 0;
    }
	printf("[CMD]: %s(%d) has used the command '%s' (%s)", pData[playerid][pName], playerid, cmd, params);
    return 1;
}

public OnPlayerCommandReceived(playerid, cmd[], params[], flags)
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	new PlayerIP[16], country[MAX_COUNTRY_LENGTH], city[MAX_CITY_LENGTH];
	g_MysqlRaceCheck[playerid]++;
	ResetVariables(playerid);
	LoadRemoveBuilding(playerid);
	CreatePlayerTextDraws(playerid);
	Player_ResetAdsLog(playerid);
	GetPlayerName(playerid, pData[playerid][pName], MAX_PLAYER_NAME);
	GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
	pData[playerid][pIP] = PlayerIP;
	GetPlayerCountry(playerid, country, MAX_COUNTRY_LENGTH);
	GetPlayerCity(playerid, city, MAX_CITY_LENGTH);
	GetPlayerName(playerid, pData[playerid][pUCP], MAX_PLAYER_NAME);
	pData[playerid][activitybar] = CreatePlayerProgressBar(playerid, 273.500000, 157.333541, 88.000000, 8.000000, 5930683, 100, 0);

	new query[103];
	mysql_format(g_SQL, query, sizeof query, "SELECT * FROM `playerucp` WHERE `ucp` = '%s' LIMIT 1", pData[playerid][pUCP]);
	mysql_pquery(g_SQL, query, "OnPlayerDataLoaded", "dd", playerid, g_MysqlRaceCheck[playerid]);
	SetPlayerColor(playerid, COLOR_WHITE);
	
	SetPlayerSkillLevel(playerid, WEAPON_COLT45, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SILENCED, 1);
	SetPlayerSkillLevel(playerid, WEAPON_DEAGLE, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SHOTGUN, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SAWEDOFF, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SHOTGSPA, 1);
	SetPlayerSkillLevel(playerid, WEAPON_UZI, 1);
	SetPlayerSkillLevel(playerid, WEAPON_MP5, 1);
	SetPlayerSkillLevel(playerid, WEAPON_AK47, 1);
	SetPlayerSkillLevel(playerid, WEAPON_M4, 1);
	SetPlayerSkillLevel(playerid, WEAPON_TEC9, 1);
	SetPlayerSkillLevel(playerid, WEAPON_RIFLE, 1);
	SetPlayerSkillLevel(playerid, WEAPON_SNIPER, 1);
	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 1000, playerid); 
	
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	pData[playerid][pSpaTime] = gettime() + 3600;
	SetPlayerName(playerid, pData[playerid][pUCP]);
	UpdateWeapons(playerid);
	UpdatePlayerData(playerid);
	RemovePlayerVehicle(playerid);
	Report_Clear(playerid);
	
	g_MysqlRaceCheck[playerid]++;
	
	if(IsValidDynamic3DTextLabel(pData[playerid][pAdoTag]))
        DestroyDynamic3DTextLabel(pData[playerid][pAdoTag]);
			
	if(IsValidDynamicObject(pData[playerid][pFlare]))
        DestroyDynamicObject(pData[playerid][pFlare]);

    pData[playerid][pAdoActive] = false;
	
	if (cache_is_valid(pData[playerid][Cache_ID]))
	{
		cache_delete(pData[playerid][Cache_ID]);
		pData[playerid][Cache_ID] = MYSQL_INVALID_CACHE;
	}

	if (pData[playerid][LoginTimer])
	{
		KillTimer(pData[playerid][LoginTimer]);
		pData[playerid][LoginTimer] = 0;
	}

	pData[playerid][IsLoggedIn] = false;
	new szDisconnectReason[5][] =
    {
        "Timeout/Crash",
        "Quit",
        "Kick/Ban",
        "Custom",
        "Mode End"
    };

	new lbdc[200];
	new Float: x, Float: y, Float: z;
	new idx = Iter_Free(LDCS);
	GetPlayerPos(playerid, x, y, z);
	format(lbdc, sizeof(lbdc), "[%s | %s (%d)] has left server.\nReason: [%s]",pData[playerid][pName], pData[playerid][pUCP], playerid, szDisconnectReason[reason]);
	g_ldc[idx][LDC_ID] = pData[playerid][pID];
	g_ldc[idx][LDC_LABEL] = CreateDynamic3DTextLabel(lbdc, 0x89CFF0FF, x, y, z + 0.2, 5.0);
	g_ldc[idx][LDC_TIMER] = SetTimerEx("LDC_DEL", 10 * 1000, false, "i", idx);
	Iter_Add(LDCS, idx);	
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if(AccountData[playerid][pInjured])
	{
		AccountData[playerid][pInjuredTime] = 1200;
		SetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
		SetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
        SetCameraBehindPlayer(playerid);
        SetPlayerHealthEx(playerid, 99999.9);
		ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 1, 1, 1, 1, 0, 1);
		TogglePlayerControllable(playerid, false);		
	}	
	StopAudioStreamForPlayer(playerid);
	SetPlayerInterior(playerid, pData[playerid][pInt]);
	SetPlayerVirtualWorld(playerid, pData[playerid][pWorld]);
	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, 0);
	SetPlayerSpawn(playerid);
	LoadAnims(playerid);
	return 1;
}

SetPlayerSpawn(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		StopAudioStreamForPlayer(playerid);
		if(pData[playerid][pGender] == 0)
		{
			SetPlayerHealth(playerid, 100.0);
			SetPlayerArmour(playerid, 0.0);
			SetPlayerVirtualWorld(playerid, 0);
			ShowPlayerDialog(playerid, DIALOG_AGE, DIALOG_STYLE_INPUT, "{a8ecff}Konoha Roleplay{FFFFFF} - Tanggal Lahir", "Mohon masukan tanggal lahir sesuai format hh/bb/tttt cth: (25/08/2001)", "Input", "");
		}
		else
		{
			SendClientMessageToAllEx(COLOR_GREY, "** %s has joined the server! ID: {FFFFFF}%d "GREY_E"(IP: {FFFFFF}%s"GREY_E")", AccountData[playerid][pUCP], playerid, ReturnIP(playerid));
			SetPlayerColor(playerid, COLOR_WHITE);
			if(pData[playerid][pHideHBE] == 0)
			{
				for(new i = 0; i < 34; i++)
				{
					PlayerTextDrawShow(playerid, HUDSERVER[playerid][i]);
				}
			}
			SetPlayerSkin(playerid, pData[playerid][pSkin]);
			if(pData[playerid][pOnDuty] >= 1)
			{
				SetPlayerSkin(playerid, pData[playerid][pFacSkin]);
				SetFactionColor(playerid);
			}
			for(new i; i < 8; i++)
			{
				TextDrawShowForPlayer(playerid, KonohaFeature[i]);
			}					
			SetTimerEx("SpawnTimer", 3000, false, "i", playerid);
		}
	}
}

function SpawnTimer(playerid)
{
	StopAudioStreamForPlayer(playerid);
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, pData[playerid][pMoney]);
	SetPlayerScore(playerid, pData[playerid][pLevel]);
	SetPlayerHealth(playerid, pData[playerid][pHealth]);
	SetPlayerArmour(playerid, pData[playerid][pArmour]);
	pData[playerid][pSpawned] = 1;
	TogglePlayerControllable(playerid, 1);
	SetCameraBehindPlayer(playerid);
	AttachPlayerToys(playerid);
	pData[playerid][IsLoggedIn] = true;
	SetWeapons(playerid);
	return 1;
}

public OnPlayerModelSelection(playerid, response, listid, modelid)
{
	if(listid == SpawnMale)
    {
		if(response)
		{
			pData[playerid][pSkin] = modelid;
			SetSpawnInfo(playerid, 0, pData[playerid][pSkin], 1744.3411, -1862.8655, 13.3983, 270.0000, 0, 0, 0, 0, 0, 0);
			SpawnPlayer(playerid);
		}
    }
	if(listid == SpawnFemale)
    {
		if(response)
		{
			pData[playerid][pSkin] = modelid;
			SetSpawnInfo(playerid, 0, pData[playerid][pSkin], 1744.3411, -1862.8655, 13.3983, 270.0000, 0, 0, 0, 0, 0, 0);
			SpawnPlayer(playerid);
		}
    }
	//Locker Faction Skin
	if(listid == SAPDMale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAPDFemale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAPDWar)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAGSMale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAGSFemale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAMDMale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SAMDFemale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SANEWMale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	if(listid == SANEWFemale)
    {
		if(response)
		{
			pData[playerid][pFacSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			Servers(playerid, "Anda telah mengganti faction skin menjadi ID %d", modelid);
		}
    }
	///Bisnis buy skin clothes
	if(listid == MaleSkins)
    {
		if(response)
		{
			new bizid = pData[playerid][pInBiz], price;
			price = bData[bizid][bP][0];
			pData[playerid][pSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			GivePlayerMoneyEx(playerid, -price);
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli skin ID %d seharga %s.", ReturnName(playerid), modelid, FormatMoney(price));
            bData[bizid][bProd]--;
            bData[bizid][bMoney] += Server_Percent(price);
			Server_AddPercent(price);
            Bisnis_Save(bizid);
			Info(playerid, "Anda telah mengganti skin menjadi ID %d", modelid);
		}
		else return Servers(playerid, "Canceled buy skin");
    }
	if(listid == FemaleSkins)
    {
		if(response)
		{
			new bizid = pData[playerid][pInBiz], price;
			price = bData[bizid][bP][0];
			pData[playerid][pSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
			GivePlayerMoneyEx(playerid, -price);
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli skin ID %d seharga %s.", ReturnName(playerid), modelid, FormatMoney(price));
            bData[bizid][bProd]--;
            bData[bizid][bMoney] += Server_Percent(price);
			Server_AddPercent(price);
            Bisnis_Save(bizid);
			Info(playerid, "Anda telah mengganti skin menjadi ID %d", modelid);
		}
		else return Servers(playerid, "Canceled buy skin");
    }
	if(listid == VIPMaleSkins)
    {
		if(response)
		{
			pData[playerid][pSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah mengganti skin ID %d.", ReturnName(playerid), modelid);
			Info(playerid, "Anda telah mengganti skin menjadi ID %d", modelid);
		}
		else return Servers(playerid, "Canceled buy skin");
    }
	if(listid == VIPFemaleSkins)
    {
		if(response)
		{
			pData[playerid][pSkin] = modelid;
			SetPlayerSkin(playerid, modelid);
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli skin ID %d.", ReturnName(playerid), modelid);
			Info(playerid, "Anda telah mengganti skin menjadi ID %d", modelid);
		}
		else return Servers(playerid, "Canceled buy skin");
    }
	if(listid == toyslist)
	{
		if(response)
		{
			new bizid = pData[playerid][pInBiz], price;
			price = bData[bizid][bP][1];
			
			GivePlayerMoneyEx(playerid, -price);
			if(!pData[playerid][PurchasedToy]) MySQL_CreatePlayerToy(playerid);
			pToys[playerid][pData[playerid][toySelected]][toy_model] = modelid;
			new finstring[750];
			strcat(finstring, ""dot"Spine\n"dot"Head\n"dot"Left upper arm\n"dot"Right upper arm\n"dot"Left hand\n"dot"Right hand\n"dot"Left thigh\n"dot"Right tigh\n"dot"Left foot\n"dot"Right foot");
			strcat(finstring, "\n"dot"Right calf\n"dot"Left calf\n"dot"Left forearm\n"dot"Right forearm\n"dot"Left clavicle\n"dot"Right clavicle\n"dot"Neck\n"dot"Jaw");
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""WHITE_E"Select Bone", finstring, "Select", "Cancel");
			
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah membeli object ID %d seharga %s.", ReturnName(playerid), modelid, FormatMoney(price));
            bData[bizid][bProd]--;
            bData[bizid][bMoney] += Server_Percent(price);
			Server_AddPercent(price);
            Bisnis_Save(bizid);
		}
		else return Servers(playerid, "Canceled buy toys");
	}
	if(listid == viptoyslist)
	{
		if(response)
		{
			if(!pData[playerid][PurchasedToy]) MySQL_CreatePlayerToy(playerid);
			pToys[playerid][pData[playerid][toySelected]][toy_model] = modelid;
			new finstring[750];
			strcat(finstring, ""dot"Spine\n"dot"Head\n"dot"Left upper arm\n"dot"Right upper arm\n"dot"Left hand\n"dot"Right hand\n"dot"Left thigh\n"dot"Right tigh\n"dot"Left foot\n"dot"Right foot");
			strcat(finstring, "\n"dot"Right calf\n"dot"Left calf\n"dot"Left forearm\n"dot"Right forearm\n"dot"Left clavicle\n"dot"Right clavicle\n"dot"Neck\n"dot"Jaw");
			ShowPlayerDialog(playerid, DIALOG_TOYPOSISIBUY, DIALOG_STYLE_LIST, ""WHITE_E"Select Bone", finstring, "Select", "Cancel");
			
            SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "** %s telah mengambil object ID %d dilocker.", ReturnName(playerid), modelid);
		}
		else return Servers(playerid, "Canceled toys");
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	InterpolateCameraPos(playerid, 456.8247, -2114.3958, 45.9822, 441.5885, -2077.0420, 41.5508, 15000, CAMERA_CUT);
	InterpolateCameraLookAt(playerid, 395.1692, -2024.1072, 36.2388, 395.1692, -2024.1072, 36.2388, 15000, CAMERA_CUT);
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}
public OnPlayerDeath(playerid, killerid, reason)
{
	if(AccountData[playerid][pInjured] == 1)
	{
		new weaponid = GetPlayerWeapon(playerid);
		if (weaponid)
		{
			static
				Float:x,
				Float:y,
				Float:z,
				Float:angle;

			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, angle);

			x += 1 * floatsin(-angle, degrees);
			y += 1 * floatcos(-angle, degrees);

			DropWeapon(pData[playerid][pName], GetWeaponModel(weaponid), weaponid, GetPlayerAmmo(playerid), x, y, z - 1, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
			ResetWeapon(playerid, weaponid);
		}				
	}	
	if(killerid != INVALID_PLAYER_ID)
	{
		new reasontext[526];
		switch(reason)
		{
	        case 0: reasontext = "Fist";
	        case 1: reasontext = "Brass Knuckles";
	        case 2: reasontext = "Golf Club";
	        case 3: reasontext = "Nite Stick";
	        case 4: reasontext = "Knife";
	        case 5: reasontext = "Basebal Bat";
	        case 6: reasontext = "Shovel";
	        case 7: reasontext = "Pool Cue";
	        case 8: reasontext = "Katana";
	        case 9: reasontext = "Chain Shaw";
	        case 14: reasontext = "Cane";
	        case 18: reasontext = "Molotov";
	        case 22..24: reasontext = "Pistol";
	        case 25..27: reasontext = "Shotgan";
	        case 28..34: reasontext = "Laras long";
		    case 49: reasontext = "Rammed by Car";
		    case 50: reasontext = "Helicopter blades";
		    case 51: reasontext = "Explosion";
		    case 53: reasontext = "Drowned";
		    case 54: reasontext = "Splat";
		    case 255: reasontext = "Suicide";
		}
		new h, m, s;
		new day, month, year;
	    gettime(h, m, s);
	    getdate(year,month,day);

	}
    else
	{
		new reasontext[526];
		switch(reason)
		{
	        case 0: reasontext = "Fist";
	        case 1: reasontext = "Brass Knuckles";
	        case 2: reasontext = "Golf Club";
	        case 3: reasontext = "Nite Stick";
	        case 4: reasontext = "Knife";
	        case 5: reasontext = "Basebal Bat";
	        case 6: reasontext = "Shovel";
	        case 7: reasontext = "Pool Cue";
	        case 8: reasontext = "Katana";
	        case 9: reasontext = "Chain Shaw";
	        case 14: reasontext = "Cane";
	        case 18: reasontext = "Molotov";
	        case 22..24: reasontext = "Pistol";
	        case 25..27: reasontext = "Shotgan";
	        case 28..34: reasontext = "Laras long";
		    case 49: reasontext = "Rammed by Car";
		    case 50: reasontext = "Helicopter blades";
		    case 51: reasontext = "Explosion";
		    case 53: reasontext = "Drowned";
		    case 54: reasontext = "Splat";
		    case 255: reasontext = "Suicide";
		}
	    new h, m, s;
	    new day, month, year;
	    gettime(h, m, s);
	    getdate(year,month,day);
	    new name[MAX_PLAYER_NAME + 1];
	    GetPlayerName(playerid, name, sizeof name);

	}

	foreach(new ii : Player)
    {
        if(pData[ii][pFaction] == 1)
        {
          	new Float: X, Float: Y, Float: Z;
          	GetPlayerPos(playerid, X, Y, Z);
          	SetPlayerCheckpoint(ii,  X, Y, Z, 3.0);

            for(new ai = 0; ai < 10; ai++)
            {
                TextDrawShowForPlayer(ii, PDLogsDeath[ai]);
            }
        	new pe [120];
        	format(pe, sizeof(pe), "Death : %s Killed : %s Weapon : %s Lokasi : %s", pData[playerid][pName], pData[killerid][pName], ReturnWeaponName(reason), GetLocation(X, Y, Z));//GetName(killerid)
        	TextDrawSetString(PDLogsDeath[9], pe);
        	SetTimerEx("spawntw", 8000, false, "d", ii);
        }
    }

    foreach(new i : Player)
    {
        if(pData[i][pFaction] == 3)
        {
          	new Float: X, Float: Y, Float: Z;
          	GetPlayerPos(playerid, X, Y, Z);
          	//new posisinya = GetPlayerPos(playerid, X, Y, Z);
          	SetPlayerCheckpoint(i, X, Y, Z, 4.0);

            for(new ai = 0; ai < 10; ai++)
            {
                TextDrawShowForPlayer(i, SAMDLogsDeath[ai]);
            }
        	new pe [120];
        	format(pe, sizeof(pe), "Death : %s Lokasi : %s", pData[playerid][pName], GetLocation(X, Y, Z));
        	TextDrawSetString(SAMDLogsDeath[9], pe);
        	SetTimerEx("spawntw", 8000, false, "d", i);
        }
    }

	DeletePVar(playerid, "UsingSprunk");
	SetPVarInt(playerid, "GiveUptime", -1);
	pData[playerid][pSpawned] = 0;
	Player_ResetMining(playerid);
	
	pData[playerid][CarryProduct] = 0;
	
	KillTimer(pData[playerid][pActivity]);
	HidePlayerProgressBar(playerid, pData[playerid][activitybar]);
	PlayerTextDrawHide(playerid, ActiveTD[playerid]);
	pData[playerid][pMechVeh] = INVALID_VEHICLE_ID;
	pData[playerid][pActivityTime] = 0;
	
	pData[playerid][pMechDuty] = 0;
	pData[playerid][pTaxiDuty] = 0;
	pData[playerid][pMission] = -1;
	
	pData[playerid][pSideJob] = 0;
	DisablePlayerCheckpoint(playerid);
	DisablePlayerRaceCheckpoint(playerid);
	SetPlayerColor(playerid, COLOR_WHITE);
	RemovePlayerAttachedObject(playerid, 9);
	GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
	foreach(new ii : Player)
    {
        if(pData[ii][pAdmin] > 0)
        {
            SendDeathMessageToPlayer(ii, killerid, playerid, reason);
        }
    }
	return 1;
}

public OnPlayerEditAttachedObject( playerid, response, index, modelid, boneid,
                                   Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ,
                                   Float:fRotX, Float:fRotY, Float:fRotZ,
                                   Float:fScaleX, Float:fScaleY, Float:fScaleZ )
{
	new weaponid = EditingWeapon[playerid];
    if(weaponid)
    {
        if (response)
        {
            new enum_index = weaponid - 22, weaponname[18], string[340];
 
            GetWeaponName(weaponid, weaponname, sizeof(weaponname));
           
            WeaponSettings[playerid][enum_index][Position][0] = fOffsetX;
            WeaponSettings[playerid][enum_index][Position][1] = fOffsetY;
            WeaponSettings[playerid][enum_index][Position][2] = fOffsetZ;
            WeaponSettings[playerid][enum_index][Position][3] = fRotX;
            WeaponSettings[playerid][enum_index][Position][4] = fRotY;
            WeaponSettings[playerid][enum_index][Position][5] = fRotZ;
 
            RemovePlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid));
            SetPlayerAttachedObject(playerid, GetWeaponObjectSlot(weaponid), GetWeaponModel(weaponid), WeaponSettings[playerid][enum_index][Bone], fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, 1.0, 1.0, 1.0);
 
            Servers(playerid, "You have successfully adjusted the position of your %s.", weaponname);
           
            mysql_format(g_SQL, string, sizeof(string), "INSERT INTO weaponsettings (Owner, WeaponID, PosX, PosY, PosZ, RotX, RotY, RotZ) VALUES ('%d', %d, %.3f, %.3f, %.3f, %.3f, %.3f, %.3f) ON DUPLICATE KEY UPDATE PosX = VALUES(PosX), PosY = VALUES(PosY), PosZ = VALUES(PosZ), RotX = VALUES(RotX), RotY = VALUES(RotY), RotZ = VALUES(RotZ)", pData[playerid][pID], weaponid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ);
            mysql_tquery(g_SQL, string);
        }
        EditingWeapon[playerid] = 0;
    }
	else
	{
		if(response)
		{
			GameTextForPlayer(playerid, "~g~~h~Toy Position Updated~y~!", 4000, 5);

			pToys[playerid][index][toy_x] = fOffsetX;
			pToys[playerid][index][toy_y] = fOffsetY;
			pToys[playerid][index][toy_z] = fOffsetZ;
			pToys[playerid][index][toy_rx] = fRotX;
			pToys[playerid][index][toy_ry] = fRotY;
			pToys[playerid][index][toy_rz] = fRotZ;
			pToys[playerid][index][toy_sx] = fScaleX;
			pToys[playerid][index][toy_sy] = fScaleY;
			pToys[playerid][index][toy_sz] = fScaleZ;
			
			MySQL_SavePlayerToys(playerid);
		}
		else
		{
			GameTextForPlayer(playerid, "~r~~h~Selection Cancelled~y~!", 4000, 5);

			SetPlayerAttachedObject(playerid,
				index,
				modelid,
				boneid,
				pToys[playerid][index][toy_x],
				pToys[playerid][index][toy_y],
				pToys[playerid][index][toy_z],
				pToys[playerid][index][toy_rx],
				pToys[playerid][index][toy_ry],
				pToys[playerid][index][toy_rz],
				pToys[playerid][index][toy_sx],
				pToys[playerid][index][toy_sy],
				pToys[playerid][index][toy_sz]);
		}
		SetPVarInt(playerid, "UpdatedToy", 1);
		TogglePlayerControllable(playerid, true);
	}
   	return 1;
}

public OnPlayerEditDynamicObject(playerid, STREAMER_TAG_OBJECT: objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if(pData[playerid][EditingATMID] != -1 && Iter_Contains(ATMS, pData[playerid][EditingATMID]))
	{
		if(response == EDIT_RESPONSE_FINAL)
	    {
	        new etid = pData[playerid][EditingATMID];
	        AtmData[etid][atmX] = x;
	        AtmData[etid][atmY] = y;
	        AtmData[etid][atmZ] = z;
	        AtmData[etid][atmRX] = rx;
	        AtmData[etid][atmRY] = ry;
	        AtmData[etid][atmRZ] = rz;

	        SetDynamicObjectPos(objectid, AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ]);
	        SetDynamicObjectRot(objectid, AtmData[etid][atmRX], AtmData[etid][atmRY], AtmData[etid][atmRZ]);

			DestroyDynamicArea(AtmData[etid][atmArea]);
			AtmData[etid][atmArea] = CreateDynamicSphere(AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ] - 0.4, 1.3);

		    Atm_Save(etid);
	        pData[playerid][EditingATMID] = -1;
	    }

	    if(response == EDIT_RESPONSE_CANCEL)
	    {
	        new etid = pData[playerid][EditingATMID];
	        SetDynamicObjectPos(objectid, AtmData[etid][atmX], AtmData[etid][atmY], AtmData[etid][atmZ]);
	        SetDynamicObjectRot(objectid, AtmData[etid][atmRX], AtmData[etid][atmRY], AtmData[etid][atmRZ]);
	        pData[playerid][EditingATMID] = -1;
	    }
	}		
	if(pData[playerid][EditingOreID] != -1 && Iter_Contains(Ores, pData[playerid][EditingOreID]))
	{
	    if(response == EDIT_RESPONSE_FINAL)
	    {
	        new etid = pData[playerid][EditingOreID];
	        OreData[etid][oreX] = x;
	        OreData[etid][oreY] = y;
	        OreData[etid][oreZ] = z;
	        OreData[etid][oreRX] = rx;
	        OreData[etid][oreRY] = ry;
	        OreData[etid][oreRZ] = rz;

	        SetDynamicObjectPos(objectid, OreData[etid][oreX], OreData[etid][oreY], OreData[etid][oreZ]);
	        SetDynamicObjectRot(objectid, OreData[etid][oreRX], OreData[etid][oreRY], OreData[etid][oreRZ]);

			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, OreData[etid][oreLabel], E_STREAMER_X, OreData[etid][oreX]);
			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, OreData[etid][oreLabel], E_STREAMER_Y, OreData[etid][oreY]);
			Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, OreData[etid][oreLabel], E_STREAMER_Z, OreData[etid][oreZ] + 1.5);

		    Ore_Save(etid);
	        pData[playerid][EditingOreID] = -1;
	    }

	    if(response == EDIT_RESPONSE_CANCEL)
	    {
	        new etid = pData[playerid][EditingOreID];
	        SetDynamicObjectPos(objectid, OreData[etid][oreX], OreData[etid][oreY], OreData[etid][oreZ]);
	        SetDynamicObjectRot(objectid, OreData[etid][oreRX], OreData[etid][oreRY], OreData[etid][oreRZ]);
	        pData[playerid][EditingOreID] = -1;
	    }
	}
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	if(checkpointid == pData[playerid][LoadingPoint])
	{
	    if(GetPVarInt(playerid, "LoadingCooldown") > gettime()) return 1;
		new vehicleid = GetPVarInt(playerid, "LastVehicleID"), type[64], carid = -1;
		if(pData[playerid][CarryingLog] == 0)
		{
			type = "Metal";
		}
		else if(pData[playerid][CarryingLog] == 1)
		{
			type = "Coal";
		}
		else
		{
			type = "Unknown";
		}
		if(Vehicle_LogCount(vehicleid) >= LOG_LIMIT) return Error(playerid, "You can't load any more ores to this vehicle.");
		if((carid = Vehicle_Nearest2(playerid)) != -1)
		{
			if(pData[playerid][CarryingLog] == 0)
			{
				pvData[carid][cMetal] += 1;
			}
			else if(pData[playerid][CarryingLog] == 1)
			{
				pvData[carid][cCoal] += 1;
			}
		}
		LogStorage[vehicleid][ pData[playerid][CarryingLog] ]++;
		Info(playerid, "MINING: Loaded %s.", type);
		ApplyAnimation(playerid, "CARRY", "putdwn05", 4.1, 0, 1, 1, 0, 0, 1);
		Player_RemoveLog(playerid);
		return 1;
	}
	if(checkpointid == ShowRoomCP)
	{
		ShowPlayerDialog(playerid, DIALOG_BUYPVCP, DIALOG_STYLE_LIST, "Showroom", "Bikes\nCars\nUnique Cars\nJob Cars\nVip Cars", "Select", "Cancel");
	}
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(pData[playerid][pTrackCar] == 1)
	{
		Info(playerid, "Anda telah berhasil menemukan kendaraan anda!");
		pData[playerid][pTrackCar] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(pData[playerid][pTrackHouse] == 1)
	{
		Info(playerid, "Anda telah berhasil menemukan rumah anda!");
		pData[playerid][pTrackHouse] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(pData[playerid][pTrackBisnis] == 1)
	{
		Info(playerid, "Anda telah berhasil menemukan bisnis anda!");
		pData[playerid][pTrackBisnis] = 0;
		DisablePlayerRaceCheckpoint(playerid);
	}
	if(pData[playerid][pMission] > -1)
	{
		DisablePlayerRaceCheckpoint(playerid);
		Info(playerid, "/buy , /gps(My Mission) , /storeproduct.");
	}
	DisablePlayerRaceCheckpoint(playerid);
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	if(pData[playerid][CarryingLog] != -1)
	{
		if(GetPVarInt(playerid, "LoadingCooldown") > gettime()) return 1;
		new vehicleid = GetPVarInt(playerid, "LastVehicleID"), type[64], carid = -1;
		if(pData[playerid][CarryingLog] == 0)
		{
			type = "Metal";
		}
		else if(pData[playerid][CarryingLog] == 1)
		{
			type = "Coal";
		}
		else
		{
			type = "Unknown";
		}
		if(Vehicle_LogCount(vehicleid) >= LOG_LIMIT) return Error(playerid, "You can't load any more ores to this vehicle.");
		if((carid = Vehicle_Nearest2(playerid)) != -1)
		{
			if(pData[playerid][CarryingLog] == 0)
			{
				pvData[carid][cMetal] += 1;
			}
			else if(pData[playerid][CarryingLog] == 1)
			{
				pvData[carid][cCoal] += 1;
			}
		}
		LogStorage[vehicleid][ pData[playerid][CarryingLog] ]++;
		Info(playerid, "MINING: Loaded %s.", type);
		ApplyAnimation(playerid, "CARRY", "putdwn05", 4.1, 0, 1, 1, 0, 0, 1);
		Player_RemoveLog(playerid);
		DisablePlayerCheckpoint(playerid);
		return 1;
	}
	if(pData[playerid][pFindEms] != INVALID_PLAYER_ID)
	{
		pData[playerid][pFindEms] = INVALID_PLAYER_ID;
		DisablePlayerCheckpoint(playerid);
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if((newkeys & KEY_SECONDARY_ATTACK))
    {
		foreach(new did : Doors)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, dData[did][dExtpos][0], dData[did][dExtpos][1], dData[did][dExtpos][2]))
			{
				if(dData[did][dIntpos][0] == 0.0 && dData[did][dIntpos][1] == 0.0 && dData[did][dIntpos][2] == 0.0)
					return Error(playerid, "Interior entrance masih kosong, atau tidak memiliki interior.");

				if(dData[did][dLocked])
					return Error(playerid, "This entrance is locked at the moment.");
					
				if(dData[did][dFaction] > 0)
				{
					if(dData[did][dFaction] != pData[playerid][pFaction])
						return Error(playerid, "This door only for faction.");
				}
				if(dData[did][dFamily] > 0)
				{
					if(dData[did][dFamily] != pData[playerid][pFamily])
						return Error(playerid, "This door only for family.");
				}
				
				if(dData[did][dVip] > pData[playerid][pVip])
					return Error(playerid, "Your VIP level not enough to enter this door.");
				
				if(dData[did][dAdmin] > pData[playerid][pAdmin])
					return Error(playerid, "Your admin level not enough to enter this door.");

				if(dData[did][dCustom])
					SetPlayerPositionEx(playerid, dData[did][dIntpos][0], dData[did][dIntpos][1], dData[did][dIntpos][2], dData[did][dIntpos][3]);

				else
					SetPlayerPosition(playerid, dData[did][dIntpos][0], dData[did][dIntpos][1], dData[did][dIntpos][2], dData[did][dIntpos][3]);

				SetPlayerInterior(playerid, dData[did][dIntint]);
				SetPlayerVirtualWorld(playerid, dData[did][dIntvw]);
				SetCameraBehindPlayer(playerid);
				pData[playerid][pInDoor] = did;
				SetPlayerWeather(playerid, 24);
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.5, dData[did][dIntpos][0], dData[did][dIntpos][1], dData[did][dIntpos][2]))
			{
				if(dData[did][dFaction] > 0)
				{
					if(dData[did][dFaction] != pData[playerid][pFaction])
						return Error(playerid, "This door only for faction.");
				}
				
				if(dData[did][dCustom])
					SetPlayerPositionEx(playerid, dData[did][dExtpos][0], dData[did][dExtpos][1], dData[did][dExtpos][2], dData[did][dExtpos][3]);

				else
					SetPlayerPositionEx(playerid, dData[did][dExtpos][0], dData[did][dExtpos][1], dData[did][dExtpos][2], dData[did][dExtpos][3]);

				SetPlayerInterior(playerid, dData[did][dExtint]);
				SetPlayerVirtualWorld(playerid, dData[did][dExtvw]);
				SetCameraBehindPlayer(playerid);
				pData[playerid][pInDoor] = -1;
			}
        }
		//Houses
		foreach(new hid : Houses)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, hData[hid][hExtpos][0], hData[hid][hExtpos][1], hData[hid][hExtpos][2]))
			{
				if(hData[hid][hIntpos][0] == 0.0 && hData[hid][hIntpos][1] == 0.0 && hData[hid][hIntpos][2] == 0.0)
					return Error(playerid, "Interior house masih kosong, atau tidak memiliki interior.");

				if(hData[hid][hLocked])
					return Error(playerid, "This house is locked!");
					
				SetPlayerPositionEx(playerid, hData[hid][hIntpos][0], hData[hid][hIntpos][1], hData[hid][hIntpos][2], hData[hid][hIntpos][3]);

				SetPlayerInterior(playerid, hData[hid][hInt]);
				SetPlayerVirtualWorld(playerid, hid);
				SetCameraBehindPlayer(playerid);
				pData[playerid][pInHouse] = hid;
				SetPlayerWeather(playerid, 24);
			}
        }
		new inhouseid = pData[playerid][pInHouse];
		if(pData[playerid][pInHouse] != -1 && IsPlayerInRangeOfPoint(playerid, 2.5, hData[inhouseid][hIntpos][0], hData[inhouseid][hIntpos][1], hData[inhouseid][hIntpos][2]))
		{
			SetPlayerPositionEx(playerid, hData[inhouseid][hExtpos][0], hData[inhouseid][hExtpos][1], hData[inhouseid][hExtpos][2], hData[inhouseid][hExtpos][3]);

			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetCameraBehindPlayer(playerid);
			pData[playerid][pInHouse] = -1;
		}
		//Bisnis
		foreach(new bid : Bisnis)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, bData[bid][bExtpos][0], bData[bid][bExtpos][1], bData[bid][bExtpos][2]))
			{
				if(bData[bid][bIntpos][0] == 0.0 && bData[bid][bIntpos][1] == 0.0 && bData[bid][bIntpos][2] == 0.0)
					return Error(playerid, "Interior bisnis masih kosong, atau tidak memiliki interior.");

				if(bData[bid][bLocked])
					return Error(playerid, "This bisnis is locked!");
					
				SetPlayerPositionEx(playerid, bData[bid][bIntpos][0], bData[bid][bIntpos][1], bData[bid][bIntpos][2], bData[bid][bIntpos][3]);

				SetPlayerInterior(playerid, bData[bid][bInt]);
				SetPlayerVirtualWorld(playerid, bid);
				SetCameraBehindPlayer(playerid);
				pData[playerid][pInBiz] = bid;
				SetPlayerWeather(playerid, 24);
			}
        }
		new inbisnisid = pData[playerid][pInBiz];
		if(pData[playerid][pInBiz] != -1 && IsPlayerInRangeOfPoint(playerid, 2.5, bData[inbisnisid][bIntpos][0], bData[inbisnisid][bIntpos][1], bData[inbisnisid][bIntpos][2]))
		{
			SetPlayerPositionEx(playerid, bData[inbisnisid][bExtpos][0], bData[inbisnisid][bExtpos][1], bData[inbisnisid][bExtpos][2], bData[inbisnisid][bExtpos][3]);

			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			SetCameraBehindPlayer(playerid);
			pData[playerid][pInBiz] = -1;
		}
		//Family
		foreach(new fid : FAMILYS)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, fData[fid][fExtpos][0], fData[fid][fExtpos][1], fData[fid][fExtpos][2]))
			{
				if(fData[fid][fIntpos][0] == 0.0 && fData[fid][fIntpos][1] == 0.0 && fData[fid][fIntpos][2] == 0.0)
					return Error(playerid, "Interior masih kosong, atau tidak memiliki interior.");

				if(pData[playerid][pFamily] < 0)
					return Error(playerid, "You dont have registered for this door!");
					
				SetPlayerPositionEx(playerid, fData[fid][fIntpos][0], fData[fid][fIntpos][1], fData[fid][fIntpos][2], fData[fid][fIntpos][3]);

				SetPlayerInterior(playerid, fData[fid][fInt]);
				SetPlayerVirtualWorld(playerid, fid);
				SetCameraBehindPlayer(playerid);
				//pData[playerid][pInBiz] = fid;
				SetPlayerWeather(playerid, 24);
			}
			if(IsPlayerInRangeOfPoint(playerid, 2.5, fData[fid][fIntpos][0], fData[fid][fIntpos][1], fData[fid][fIntpos][2]))
			{
				SetPlayerPositionEx(playerid, fData[fid][fExtpos][0], fData[fid][fExtpos][1], fData[fid][fExtpos][2], fData[fid][fExtpos][3]);

				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetCameraBehindPlayer(playerid);
				//pData[playerid][pInBiz] = -1;
			}
        }
	}
	//Vehicle
	if((newkeys & KEY_YES ))
	{
		forex(i, MAX_RENTAL) if(RentData[i][rentExists])
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.0, RentData[i][rentPos][0], RentData[i][rentPos][1], RentData[i][rentPos][2]))
			{
				if(RentData[i][rentSpawn][0] == 0)
					return ErrorMsg(playerid, "Rental Point ini belum memiliki Spawn Point!");				

				new str[1024];
				format(str, sizeof(str), "Jenis Kendaraan\tHarga Rental            \nFaggio\t$1000            \n{BEBEBE}Wayfarer\t{BEBEBE}$1500            \n{FFFF00}> Pilih ini untuk mengembalikan kendaraan yang disewa dari negara.");			
				Dialog_Show(playerid, DIALOG_RENTALBIKE, DIALOG_STYLE_TABLIST_HEADERS, "{a8ecff}Konoha Roleplay{FFFFFF} - Rental Sepeda", str, "Pilih", "Batalkan");		
				AccountData[playerid][pRenting] = i;						
			}
		}			
		forex(i, MAX_ATM) if(AtmData[i][atmExists])
		{
			if(IsPlayerInDynamicArea(playerid, AtmData[i][atmArea]))
			{
				if(pData[playerid][IsLoggedIn] == false) return ErrorMsg(playerid, "Kamu harus login!");
				if(pData[playerid][pInjured] >= 1) return ErrorMsg(playerid, "Kamu tidak bisa melakukan ini!");			
				forex(ix, 38)
				{
					PlayerTextDrawShow(playerid, ATMTD[playerid][ix]);
				}
				PlayerTextDrawSetString(playerid, ATMTD[playerid][37], sprintf("%d", pData[playerid][pBankRek]));
				PlayerTextDrawSetString(playerid, ATMTD[playerid][8], pData[playerid][pName]);
				PlayerTextDrawSetString(playerid, ATMTD[playerid][13], sprintf("%s", FormatMoney(pData[playerid][pMoney])));
				PlayerTextDrawSetString(playerid, ATMTD[playerid][16], sprintf("%s", FormatMoney(pData[playerid][pBankMoney])));
				SelectTextDraw(playerid, -1);	
				Info(playerid, "Gunakan {FFFF00}'/cursor'{FFFFFF} jika cursor menghilang / textdraw tidak dapat ditekan");															
			}
		}	
				
		foreach(new gsid : GStation)
		{
			if(IsPlayerInRangeOfPoint(playerid, 4.0, gsData[gsid][gsPosX], gsData[gsid][gsPosY], gsData[gsid][gsPosZ]))
			{
				new vehicleid = GetNearestVehicle(playerid, 5.0);
				if(!pData[playerid][pFuelCar])
				{
					new string[128];
					if (GetMoney(playerid) < 1) 
						return Error(playerid, "Anda tidak mempunyai uang yang cukup!");
					if(pData[playerid][pFill] != -1)
						return Error(playerid, "You already filling vehicle. please wait!");					
					if(GetEngineStatus(vehicleid))
						return Error(playerid, "Matikan mesin kendaraan anda terlebih dahulu");	
					if(GetVehicleFuel(vehicleid) > 99)
						return Error(playerid, "Anda tidak bisa mengisi bensin lagi");	
					pData[playerid][pFuelCar] = 1;
					format(string,sizeof(string), "%d", pvData[vehicleid][cFuel]);
					pData[playerid][pFill] = gsid;

					vehicle3Dtext[vehicleid] = Create3DTextLabel(string, COLOR_WHITE, 0.0, 0.0, 0.0, 10.0, 0, 1);
					Attach3DTextLabelToVehicle(vehicle3Dtext[vehicleid], vehicleid, -0.7, 0.0, 2.0);							
				}		
				else
				{			
					pData[playerid][pFuelCar] = 0;
					Delete3DTextLabel(vehicle3Dtext[vehicleid]);
					vehiclecallsign[vehicleid] = 0;
					GivePlayerMoneyEx(playerid, -pData[playerid][pFuelMoney]);
					ClearAnimations(playerid, 1);						
				}
			}
		}			
	}
	if((newkeys & KEY_NO ))
	{
		if(AccountData[playerid][pInjured]) return 1;
	    if(pData[playerid][pProgress] == 1) return ErrorMsg(playerid, "Anda masih memiliki activity progress!");
		for(new i = 0; i < 54; i++)
		{
			PlayerTextDrawShow(playerid, PR_PANELSTD[playerid][i]);
		}
		SelectTextDraw(playerid, COLOR_WHITE);		
	}
	if(IsKeyJustDown(KEY_CTRL_BACK,newkeys,oldkeys))
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
		{
			ClearAnimations(playerid);
			StopLoopingAnim(playerid);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		}
    }
	if(IsKeyJustDown(KEY_SECONDARY_ATTACK, newkeys, oldkeys))
	{
		if(GetPVarInt(playerid, "UsingSprunk"))
		{
			DeletePVar(playerid, "UsingSprunk");
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_WASTED && pData[playerid][pJail] < 1)
    {	
		if(pData[playerid][pInjured] == 0)
        {
            pData[playerid][pInjured] = 1;
            SetPlayerHealthEx(playerid, 99999);

            pData[playerid][pInt] = GetPlayerInterior(playerid);
            pData[playerid][pWorld] = GetPlayerVirtualWorld(playerid);

            GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
            GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
        }
        else
        {
			pData[playerid][pSpaTime] = gettime() + 18000;
            pData[playerid][pHospital] = 1;
        }
	}
	//Spec Player
	new vehicleid = GetPlayerVehicleID(playerid);
	if(newstate == PLAYER_STATE_ONFOOT)
	{
		if(pData[playerid][playerSpectated] != 0)
		{
			foreach(new ii : Player)
			{
				if(pData[ii][pSpec] == playerid)
				{
					PlayerSpectatePlayer(ii, playerid);
					Servers(ii, ,"%s(%i) is now on foot.", pData[playerid][pName], playerid);
				}
			}
		}
	}
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
    {
		if(pData[playerid][pInjured] == 1)
        {
			pData[playerid][pSpaTime] = gettime() + 18000;
            RemoveFromVehicle(playerid);
            SetPlayerHealthEx(playerid, 99999);
        }
		foreach (new ii : Player) if(pData[ii][pSpec] == playerid) 
		{
            PlayerSpectateVehicle(ii, GetPlayerVehicleID(playerid));
        }
	}
	if(oldstate == PLAYER_STATE_PASSENGER)
	{
		forex(i, 39)
		{
			PlayerTextDrawHide(playerid, SPEEDOTD[playerid][i]);
		}
	}
	if(oldstate == PLAYER_STATE_DRIVER)
    {	
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED)
            return RemoveFromVehicle(playerid);
			
		forex(i, 39)
		{
			PlayerTextDrawHide(playerid, SPEEDOTD[playerid][i]);
		}
		
		if(pData[playerid][pTaxiDuty] == 1)
		{
			pData[playerid][pTaxiDuty] = 0;
			SetPlayerColor(playerid, COLOR_WHITE);
			Servers(playerid, "You are no longer on taxi duty!");
		}
		if(pData[playerid][pFare] == 1)
		{
			KillTimer(pData[playerid][pFareTimer]);
			Info(playerid, "Anda telah menonaktifkan taxi fare pada total: {00FF00}%s", FormatMoney(pData[playerid][pTotalFare]));
			pData[playerid][pFare] = 0;
			pData[playerid][pTotalFare] = 0;
		}

        switch (GetEngineStatus(GetNearestVehicleToPlayer(playerid)))
	    {
	        case false:
	        {
	            SwitchVehicleEngine(GetNearestVehicleToPlayer(playerid), false);
	        }
	        case true:
	        {
	            SwitchVehicleEngine(GetNearestVehicleToPlayer(playerid), false);
	            
	            SwitchVehicleLight(vehicleid, false);

	            SendNearbyMessage(playerid, 0.0, COLOR_WHITE, "ACTION: {D0AEEB}Mesin mati.");
	        }
	    }		
	}
	else if(newstate == PLAYER_STATE_DRIVER)
    {
		/*if(IsSRV(vehicleid))
		{
			new tstr[128], price = GetVehicleCost(GetVehicleModel(vehicleid));
			format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "LG_E"%s", GetVehicleName(vehicleid), FormatMoney(price));
			ShowPlayerDialog(playerid, DIALOG_BUYPV, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
		}
		else if(IsVSRV(vehicleid))
		{
			new tstr[128], price = GetVipVehicleCost(GetVehicleModel(vehicleid));
			if(pData[playerid][pVip] == 0)
			{
				Error(playerid, "Kendaraan Khusus VIP Player.");
				RemovePlayerFromVehicle(playerid);
				//SetVehicleToRespawn(GetPlayerVehicleID(playerid));
				SetTimerEx("RespawnPV", 3000, false, "d", vehicleid);
			}
			else
			{
				format(tstr, sizeof(tstr), ""WHITE_E"Anda akan membeli kendaraan "PINK_E"%s "WHITE_E"dengan harga "YELLOW_E"%d Coin", GetVehicleName(vehicleid), price);
				ShowPlayerDialog(playerid, DIALOG_BUYVIPPV, DIALOG_STYLE_MSGBOX, "Private Vehicles", tstr, "Buy", "Batal");
			}
		}*/
		
		if(IsEngineVehicle(vehicleid) && pData[playerid][pDriveLic] <= 0)
        {
			SwitchVehicleEngine(vehicleid, true);
            Info(playerid, "Anda tidak memiliki surat izin mengemudi, berhati-hatilah.");
        }
		
		if(pData[playerid][pHideSpeedo] == 0)
		{
			forex(i, 39)
			{
				PlayerTextDrawShow(playerid, SPEEDOTD[playerid][i]);
			}
		}
		new Float:health;
        GetVehicleHealth(GetPlayerVehicleID(playerid), health);
        VehicleHealthSecurityData[GetPlayerVehicleID(playerid)] = health;
        VehicleHealthSecurity[GetPlayerVehicleID(playerid)] = true;
		
		if(pData[playerid][playerSpectated] != 0)
  		{
			foreach(new ii : Player)
			{
    			if(pData[ii][pSpec] == playerid)
			    {
        			PlayerSpectateVehicle(ii, vehicleid);
				    Servers(ii, "%s(%i) is now driving a %s(%d).", pData[playerid][pName], playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), vehicleid);
				}
			}
		}
		SetPVarInt(playerid, "LastVehicleID", vehicleid);
	}
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart)
{

	return 1;
}

public OnPlayerUpdate(playerid)
{
    if(pData[playerid][pSpaTime] > 0)
	{
		pData[playerid][pSpaTime]--;
	}		
	if(pData[playerid][pFuelCar] == 1)
	{
		new vehicleid = GetNearestVehicle(playerid, 5.0);
		pData[playerid][pFuelMoney] += 3;
		pvData[vehicleid][cFuel] += 1;
		ApplyAnimation(playerid, "SAMP", "FishingIdle", 4.1, 0, 0, 0, 1, 0, 1);
		new sre[128];
		format(sre,sizeof(sre), "%d", pvData[vehicleid][cFuel]);
		Update3DTextLabelText(vehicle3Dtext[vehicleid], 0xFFFFFFFF, sre);
		Attach3DTextLabelToVehicle(vehicle3Dtext[vehicleid], vehicleid, 0.0, 0.0, 1.3);
		vehiclecallsign[vehicleid] = 1;
		if(pvData[vehicleid][cFuel] == 100)
		{
			pData[playerid][pFuelCar] = 0;
			Delete3DTextLabel(vehicle3Dtext[vehicleid]);
			vehiclecallsign[vehicleid] = 0;
			GiveMoney(playerid, -pData[playerid][pFuelMoney]);
			SetVehicleFuel(vehicleid, pvData[vehicleid][cFuel]);
			ClearAnimations(playerid, 1);	
		}
	}			
	return 1;
}

task VehicleUpdate[40000]()
{
	for (new i = 1; i != MAX_VEHICLES; i ++) if(IsEngineVehicle(i) && GetEngineStatus(i))
    {
        if(GetVehicleFuel(i) > 0)
        {
			new fuel = GetVehicleFuel(i);
            SetVehicleFuel(i, fuel - 15);

            if(GetVehicleFuel(i) >= 1 && GetVehicleFuel(i) <= 200)
            {
               Info(GetVehicleDriver(i), "This vehicle is low on fuel. You must visit a fuel station!");
            }
        }
        if(GetVehicleFuel(i) <= 0)
        {
            SetVehicleFuel(i, 0);
            SwitchVehicleEngine(i, false);
        }
    }
	foreach(new ii : PVehicles)
	{
		if(IsValidVehicle(pvData[ii][cVeh]))
		{
			if(pvData[ii][cPlateTime] != 0 && pvData[ii][cPlateTime] <= gettime())
			{
				format(pvData[ii][cPlate], 32, "NoHave");
				SetVehicleNumberPlate(pvData[ii][cVeh], pvData[ii][cPlate]);
				pvData[ii][cPlateTime] = 0;
			}
		}
	}
}

public OnVehicleSpawn(vehicleid)
{
    if(vehicleid == carvid)
    { 
    } 	
	foreach(new ii : PVehicles)
	{
		if(vehicleid == pvData[ii][cVeh])
		{
			if(pvData[ii][cClaim] < 1)
    		{
				pvData[ii][cClaim] = 1;
				foreach(new pid : Player) if (pvData[ii][cOwner] == pData[pid][pID])
        		{
            		Info(pid, "Kendaraan anda hancur dan masuk kedalam asurani");
				}
				if(IsValidVehicle(pvData[ii][cVeh]))
					DestroyVehicle(pvData[ii][cVeh]);
			}
		}
	}
	return 1;
}	

ptask PlayerVehicleUpdate[200](playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	if(IsValidVehicle(vehicleid))
	{
		if(!GetEngineStatus(vehicleid) && IsEngineVehicle(vehicleid))
		{	
			SwitchVehicleEngine(vehicleid, false);
		}
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(pData[playerid][pHideSpeedo] == 0)
			{
				new speedtd[64], strs[300], fFuel;
				fFuel = GetVehicleFuel(vehicleid);
				
				if(fFuel < 0) fFuel = 0;
				else if(fFuel > 900) fFuel = 100;				
				format(strs, sizeof(strs), "%d", fFuel);
				PlayerTextDrawSetString(playerid, SPEEDOTD[playerid][27], strs);		

				format(speedtd, sizeof(speedtd), "%i", GetVehicleSpeedKMH(vehicleid));
				PlayerTextDrawSetString(playerid, SPEEDOTD[playerid][22], speedtd);		
				new kecepatan = GetVehicleSpeedKMH(vehicleid);

				if(kecepatan > 5.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][0], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][0]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][0], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][0]);
				}
				if(kecepatan > 10.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][1], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][1]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][1], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][1]);
				}
				if(kecepatan > 15.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][2], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][2]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][2], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][2]);
				}
				if(kecepatan > 20.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][3], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][3]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][3], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][3]);
				}
				if(kecepatan > 25.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][4], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][4]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][4], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][4]);
				}
				if(kecepatan > 30.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][5], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][5]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][5], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][5]);
				}
				if(kecepatan > 35.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][6], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][6]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][6], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][6]);
				}
				if(kecepatan > 40.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][7], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][7]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][7], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][7]);
				}
				if(kecepatan > 45.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][8], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][8]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][8], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][8]);
				}
				if(kecepatan > 50.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][9], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][9]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][9], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][9]);
				}
				if(kecepatan > 55.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][10], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][10]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][10], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][10]);
				}				 				
				if(kecepatan > 60.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][11], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][11]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][11], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][11]);
				}				
				if(kecepatan > 65.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][12], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][12]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][12], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][12]);
				}						
				if(kecepatan > 70.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][13], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][13]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][13], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][13]);
				}			
				if(kecepatan > 75.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][14], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][14]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][14], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][14]);
				}	
				if(kecepatan > 80.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][15], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][15]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][15], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][15]);
				}		
				if(kecepatan > 85.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][16], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][16]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][16], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][16]);
				}			
				if(kecepatan > 90.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][17], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][17]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][17], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][17]);
				}				
				if(kecepatan > 95.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][18], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][18]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][18], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][18]);
				}		
				if(kecepatan > 100.0)
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][19], 512819199);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][19]);
				}
				else
				{
					PlayerTextDrawColor(playerid, SPEEDOTD[playerid][19], -1);
					PlayerTextDrawShow(playerid, SPEEDOTD[playerid][19]);
				}																																		
			}
		}
	}
}

ptask PlayerUpdate[999](playerid)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		IdlingCheck(playerid);
	}	
	//Anti-Cheat Vehicle health hack
	for(new v, j = GetVehiclePoolSize(); v <= j; v++) if(GetVehicleModel(v))
    {
        new Float:health;
        GetVehicleHealth(v, health);
        if( (health > VehicleHealthSecurityData[v]) && VehicleHealthSecurity[v] == false)
        {
			if(GetPlayerVehicleID(playerid) == v)
			{
				new playerState = GetPlayerState(playerid);
				if(playerState == PLAYER_STATE_DRIVER)
				{
					SetValidVehicleHealth(v, VehicleHealthSecurityData[v]);
					SendClientMessageToAllEx(COLOR_RED, "Anti-Cheat: "GREY2_E"%s have been auto kicked for vehicle health hack!", pData[playerid][pName]);
					KickEx(playerid);
				}
			}
        }
        if(VehicleHealthSecurity[v] == true)
        {
            VehicleHealthSecurity[v] = false;
        }
        VehicleHealthSecurityData[v] = health;
    }
	//Anti-Money Hack
	if(GetPlayerMoney(playerid) > pData[playerid][pMoney])
	{
		ResetPlayerMoney(playerid);
		GivePlayerMoney(playerid, pData[playerid][pMoney]);
		//SendAdminMessage(COLOR_RED, "Possible money hacks detected on %s(%i). Check on this player. "LG_E"($%d).", pData[playerid][pName], playerid, GetPlayerMoney(playerid) - pData[playerid][pMoney]);
	}
	//Weapon AC
	if (GetPlayerWeapon(playerid) != PlayerData[playerid][pWeapon])
	{
	    PlayerData[playerid][pWeapon] = GetPlayerWeapon(playerid);

		if (PlayerData[playerid][pWeapon] >= 1 && PlayerData[playerid][pWeapon] <= 45 && PlayerData[playerid][pGuns][g_aWeaponSlots[PlayerData[playerid][pWeapon]]] != GetPlayerWeapon(playerid))
		{
		    SendClientMessageToAllEx(C_ADMIN, "Eternals Cheat Detected | %s (%s | %d) telah ditendang oleh Eternals Bot, Reason: Fcrash/Weapon Flood", pData[playerid][pName], pData[playerid][pUCP], playerid);
			ResetPlayerWeaponsEx(playerid);
			KickEx(playerid);
		}
	}

	//Weapon Atth
	if(NetStats_GetConnectedTime(playerid) - WeaponTick[playerid] >= 250)
	{
		static weaponid, ammo, objectslot, count, index;
 
		for (new i = 2; i <= 7; i++) //Loop only through the slots that may contain the wearable weapons
		{
			GetPlayerWeaponData(playerid, i, weaponid, ammo);
			index = weaponid - 22;
		   
			if (weaponid && ammo && !WeaponSettings[playerid][index][Hidden] && IsWeaponWearable(weaponid) && EditingWeapon[playerid] != weaponid)
			{
				objectslot = GetWeaponObjectSlot(weaponid);
 
				if (GetPlayerWeapon(playerid) != weaponid)
					SetPlayerAttachedObject(playerid, objectslot, GetWeaponModel(weaponid), WeaponSettings[playerid][index][Bone], WeaponSettings[playerid][index][Position][0], WeaponSettings[playerid][index][Position][1], WeaponSettings[playerid][index][Position][2], WeaponSettings[playerid][index][Position][3], WeaponSettings[playerid][index][Position][4], WeaponSettings[playerid][index][Position][5], 1.0, 1.0, 1.0);
 
				else if (IsPlayerAttachedObjectSlotUsed(playerid, objectslot)) RemovePlayerAttachedObject(playerid, objectslot);
			}
		}
		for (new i = 4; i <= 8; i++) if (IsPlayerAttachedObjectSlotUsed(playerid, i))
		{
			count = 0;
 
			for (new j = 22; j <= 38; j++) if (PlayerHasWeapon(playerid, j) && GetWeaponObjectSlot(j) == i)
				count++;
 
			if(!count) RemovePlayerAttachedObject(playerid, i);
		}
		WeaponTick[playerid] = NetStats_GetConnectedTime(playerid);
	}
	
	//Player Update Online Data
	GetPlayerHealth(playerid, pData[playerid][pHealth]);
    GetPlayerArmour(playerid, pData[playerid][pArmour]);
	
	if(pData[playerid][pJail] <= 0)
	{
		if(pData[playerid][pHunger] > 100)
		{
			pData[playerid][pHunger] = 100;
		}
		if(pData[playerid][pHunger] < 0)
		{
			pData[playerid][pHunger] = 0;
		}
		if(pData[playerid][pEnergy] > 100)
		{
			pData[playerid][pEnergy] = 100;
		}
		if(pData[playerid][pEnergy] < 0)
		{
			pData[playerid][pEnergy] = 0;
		}
		if(pData[playerid][pBladder] > 100)
		{
			pData[playerid][pBladder] = 100;
		}
		if(pData[playerid][pBladder] < 0)
		{
			pData[playerid][pBladder] = 0;
		}
		/*if(pData[playerid][pHealth] > 100)
		{
			SetPlayerHealthEx(playerid, 100);
		}*/
	}
	if(AccountData[playerid][pSpawned])
	{
		if(pData[playerid][pHunger] > 100) pData[playerid][pHunger] = 100;
		else if(pData[playerid][pHunger] < 0) pData[playerid][pHunger] = 0; 
		if(pData[playerid][pEnergy] > 100) pData[playerid][pEnergy] = 100;
		else if(pData[playerid][pEnergy] < 0) pData[playerid][pEnergy] = 0;
		if(pData[playerid][pBladder] > 100) pData[playerid][pBladder] = 100;
		else if(pData[playerid][pBladder] < 0) pData[playerid][pBladder] = 0;		
		
		new
			Float:bardarah, Float: darah, Float:armor, Float:bararmor, Float:barhunger, Float:barthirst, Float:barstress;

		GetPlayerHealth(playerid, darah);
		GetPlayerArmour(playerid, armor);
		bararmor = armor * -18.000/100; 
		PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][23], 17.000, bararmor);
		PlayerTextDrawShow(playerid, HUDSERVER[playerid][23]);	

		bardarah = darah * -18.000/100; 
		PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][1], 17.000, bardarah);
		PlayerTextDrawShow(playerid, HUDSERVER[playerid][1]);	

		barhunger = pData[playerid][pHunger] * -18.000/100; 
		PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][3], 17.000, barhunger);
		PlayerTextDrawShow(playerid, HUDSERVER[playerid][3]);	

		barthirst = pData[playerid][pEnergy] * -18.000/100; 
		PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][5], 17.000, barthirst);
		PlayerTextDrawShow(playerid, HUDSERVER[playerid][5]);	

		barstress = pData[playerid][pBladder] * -18.000/100; 
		PlayerTextDrawTextSize(playerid, HUDSERVER[playerid][7], 17.000, barstress);
		PlayerTextDrawShow(playerid, HUDSERVER[playerid][7]);  
	}
	if(pData[playerid][pHospital] == 1)
    {
		if(pData[playerid][pInjured] == 1)
		{
			SetPlayerPosition(playerid, -2028.32, -92.87, 1067.43, 275.78, 1);
		
			SetPlayerInterior(playerid, 1);
			SetPlayerVirtualWorld(playerid, playerid + 100);
			pData[playerid][pSpaTime] = gettime() + 18000;

			SetPlayerCameraPos(playerid, -2024.67, -93.13, 1066.78);
			SetPlayerCameraLookAt(playerid, -2028.32, -92.87, 1067.43);
			ResetPlayerWeaponsEx(playerid);
			TogglePlayerControllable(playerid, 0);
			pData[playerid][pInjured] = 0;
		}
		pData[playerid][pHospitalTime]++;
		new mstr[64];
		format(mstr, sizeof(mstr), "~n~~n~~n~~w~Recovering... %d", 15 - pData[playerid][pHospitalTime]);
		InfoTD_MSG(playerid, 1000, mstr);

		ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
		ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
        if(pData[playerid][pHospitalTime] >= 15)
        {
            pData[playerid][pHospitalTime] = 0;
            pData[playerid][pHospital] = 0;
			pData[playerid][pHunger] = 50;
			pData[playerid][pEnergy] = 50;
			pData[playerid][pBladder] = 0;
			SetPlayerHealthEx(playerid, 75);
			pData[playerid][pSick] = 0;
			GivePlayerMoneyEx(playerid, -120);

            for (new i; i < 20; i++)
            {
                SendClientMessage(playerid, -1, "");
            }

			SendClientMessage(playerid, COLOR_GREY, "--------------------------------------------------------------------------------------------------------");
            SendClientMessage(playerid, COLOR_WHITE, "Kamu telah keluar dari rumah sakit, kamu membayar $800 kerumah sakit.");
            SendClientMessage(playerid, COLOR_GREY, "--------------------------------------------------------------------------------------------------------");
			
			SetPlayerPosition(playerid, 1182.8778, -1324.2023, 13.5784, 269.8747);

            TogglePlayerControllable(playerid, 1);
            SetCameraBehindPlayer(playerid);

            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
			ClearAnimations(playerid);
			pData[playerid][pSpawned] = 1;
			SetPVarInt(playerid, "GiveUptime", -1);
		}	
    }
	if(pData[playerid][pInjured] == 1 && pData[playerid][pHospital] != 1)
    {
		pData[playerid][pSpaTime] = gettime() + 18000;
        SetPlayerHealthEx(playerid, 99999);
    }
	if(pData[playerid][pInjured] == 0 && pData[playerid][pGender] != 0) //Pengurangan Data
	{
		if(pData[playerid][pSick] == 1)
		{
			if(++ pData[playerid][pSickTime] >= 200)
			{
				if(pData[playerid][pSick] >= 1)
				{
					new Float:hp;
					GetPlayerHealth(playerid, hp);
					SetPlayerDrunkLevel(playerid, 8000);
					ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,0,1,1,1,1,1);
					Info(playerid, "Sepertinya anda sakit, segeralah pergi ke dokter.");
					SetPlayerHealth(playerid, hp - 3);
					pData[playerid][pSickTime] = 0;
				}
			}		
		}
	}
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if (pData[playerid][pAdmin] >= 4 && pData[playerid][pAdminDuty] == 1)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(vehicleid > 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
            SetVehiclePos(vehicleid, fX, fY, fZ+10);
        }
        else
        {
            SetPlayerPosFindZ(playerid, fX, fY, 999.0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
        }
    }	
	//StartTracing(playerid, fX, fY, fZ);
	//SetTracingColor(playerid, 0xA020F0AA);
    return (true);
}


public OnPlayerEnterDynamicArea(playerid, areaid)
{
	//atm
	forex(i, MAX_ATM) if(AtmData[i][atmExists])
	{
		if(areaid == AtmData[i][atmArea])
		{
			ShowInfo(playerid, "Menggunakan ATM");								
		}
	}				
	if(areaid == PlayerButcherVars[playerid][ChickenTakeArea])
	{
		ShowInfo(playerid, "Ambil Ayam");
	}		
	return 1;
}

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
	HideInfo(playerid);
	return 1;	
}

stock ReturnCheatName(code)
{
	new name[32];
	format(name, sizeof(name), "Unknown Cheat");
    if(code == 0) { format(name, sizeof(name), "AirBreak (On Foot)"); }
	else if(code == 1) { format(name, sizeof(name), "AirBreak (In Vehicle)"); }
	else if(code == 2) { format(name, sizeof(name), "Teleport (On Foot)"); }
	else if(code == 3) { format(name, sizeof(name), "Teleport (In Vehicle)"); }
	else if(code == 4) { format(name, sizeof(name), "Teleport (Vehicle to Vehicle)"); }
	else if(code == 5) { format(name, sizeof(name), "Teleport (Vehicle to Player)"); }
	else if(code == 6) { format(name, sizeof(name), "Teleport (Pickups)"); }
	else if(code == 7) { format(name, sizeof(name), "FlyHack (On Foot)"); }
	else if(code == 8) { format(name, sizeof(name), "FlyHack (In Vehicle)"); }
	else if(code == 9) { format(name, sizeof(name), "SpeedHack (On Foot)"); }
	else if(code == 10) { format(name, sizeof(name), "SpeedHack (In Vehicle)"); }
	else if(code == 11) { format(name, sizeof(name), "Health Hack (In Vehicle)"); }
	else if(code == 12) { format(name, sizeof(name), "Health Hack (On Foot)"); }
	else if(code == 13) { format(name, sizeof(name), "Armour Hack"); }
	else if(code == 14) { format(name, sizeof(name), "Money Hack"); }
	else if(code == 15) { format(name, sizeof(name), "Weapon Hack"); }
	else if(code == 16) { format(name, sizeof(name), "Ammo Hack (Add)"); }
	else if(code == 17) { format(name, sizeof(name), "Ammo Hack (Infinite)"); }
	else if(code == 18) { format(name, sizeof(name), "Special Actions Hack"); }
	else if(code == 19) { format(name, sizeof(name), "GodMode (On Foot)"); }
	else if(code == 20) { format(name, sizeof(name), "GodMode (In Vehicle)"); }
	else if(code == 21) { format(name, sizeof(name), "Invisible Hack"); }
	else if(code == 22) { format(name, sizeof(name), "Lagcomp Spoof"); }
	else if(code == 23) { format(name, sizeof(name), "Tuning Hack"); }
	else if(code == 24) { format(name, sizeof(name), "Parkour Mod"); }
	else if(code == 25) { format(name, sizeof(name), "Quick Turn"); }
	else if(code == 26) { format(name, sizeof(name), "Rapid-Fire"); }
	else if(code == 27) { format(name, sizeof(name), "FakeSpawn"); }
	else if(code == 28) { format(name, sizeof(name), "FakeKill"); }
	else if(code == 29) { format(name, sizeof(name), "Pro Aim"); }
	else if(code == 30) { format(name, sizeof(name), "CJ Run"); }
	else if(code == 31) { format(name, sizeof(name), "CarShot"); }
	else if(code == 32) { format(name, sizeof(name), "CarJack"); }
	else if(code == 33) { format(name, sizeof(name), "UnFreeze"); }
	else if(code == 34) { format(name, sizeof(name), "AFK Ghost"); }
	else if(code == 35) { format(name, sizeof(name), "Full Aiming"); }

	else if(code == 36) { format(name, sizeof(name), "Fake NPC"); }
	else if(code == 37) { format(name, sizeof(name), "Reconnect Flood"); }
	else if(code == 38) { format(name, sizeof(name), "High Ping"); }
	else if(code == 39) { format(name, sizeof(name), "Dialog Hack"); }
	else if(code == 40) { format(name, sizeof(name), "Sandbox"); }
	else if(code == 41) { format(name, sizeof(name), "Invalid Version"); }
	else if(code == 42) { format(name, sizeof(name), "Rcon Hack"); }

	else if(code == 43) { format(name, sizeof(name), "Tuning Crasher"); }
	else if(code == 44) { format(name, sizeof(name), "Invalid Seat Crasher"); }
	else if(code == 45) { format(name, sizeof(name), "Dialog Crasher"); }
	else if(code == 46) { format(name, sizeof(name), "Attached Object Crasher"); }
	else if(code == 47) { format(name, sizeof(name), "Weapon Crasher"); }

	else if(code == 48) { format(name, sizeof(name), "Connection Flood"); }
	else if(code == 49) { format(name, sizeof(name), "Callback Flood"); }
	else if(code == 50) { format(name, sizeof(name), "Seat Changing Flood"); }

	else if(code == 51) { format(name, sizeof(name), "DoS"); }

	else if(code == 52) { format(name, sizeof(name), "NOPs"); }
	return name;
}

stock SendRemoveMessage(playerid, code)
{
	new string[128], name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	format(string, sizeof(string), "Eternals Cheat Detected | %s (%s | %d)  telah ditendang oleh Eternals Bot, Reason: %s", name, pData[playerid][pUCP], playerid, ReturnCheatName(code));
	SendClientMessageToAll(C_ADMIN, string);
	return Kick(playerid);
}

forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	if(!AccountData[playerid][pAdminDuty])
	{
		if(type) SendRemoveMessage(playerid, code);
		else
		{
			switch(code)
			{
				case 5, 6, 11, 14, 22, 32: return 1;
				case 40: SendClientMessageToAll(C_ADMIN, MAX_CONNECTS_MSG);
				case 41: SendClientMessageToAll(C_ADMIN, UNKNOWN_CLIENT_MSG);
				default:
				{
					new string[128], name[MAX_PLAYER_NAME];
					GetPlayerName(playerid, name, sizeof(name));
					format(string, sizeof(string), "Eternals Cheat Detected | %s (%s | %d) telah ditendang oleh Eternals Bot, Reason: %s", name, pData[playerid][pUCP], playerid, ReturnCheatName(code));
					SendClientMessageToAll(C_ADMIN, string);
				}
			}
			KickWithDesync(playerid, code);
		}
	}
	return 1;
}

Dialog:DIALOG_RENTALBIKE(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				new modelid = 462;
				pData[playerid][pBuyPvModel] = modelid;
				new id = AccountData[playerid][pRenting];
				new rental;
				if(modelid <= 0) return Error(playerid, "Invalid model id.");
				new cost = GetVehicleRental2Cost(modelid);
				if(pData[playerid][pMoney] < cost)
				{
					Error(playerid, "Uang anda tidak cukup");
					return 1;
				}			

				new count = 0, limit = MAX_PLAYER_VEHICLE;
				if(count >= limit) return Error(playerid, "Slot kendaraan anda sudah penuh");
				GivePlayerMoneyEx(playerid, -cost);
				rental = gettime() + (1 * 3600);
				OnVehRentPV(playerid, AccountData[playerid][pID], modelid, 1, 1, cost, RentData[id][rentSpawn][0], RentData[id][rentSpawn][1], RentData[id][rentSpawn][2], RentData[id][rentSpawn][3], rental);
				PutPlayerInVehicle(playerid, modelid, 0);
			}
			case 1:
			{
				new modelid = 463;
				pData[playerid][pBuyPvModel] = modelid;
				new id = AccountData[playerid][pRenting];
				new rental;
				if(modelid <= 0) return Error(playerid, "Invalid model id.");
				new cost = GetVehicleRental2Cost(modelid);
				if(pData[playerid][pMoney] < cost)
				{
					Error(playerid, "Uang anda tidak cukup");
					return 1;
				}			

				new count = 0, limit = MAX_PLAYER_VEHICLE;
				if(count >= limit) return Error(playerid, "Slot kendaraan anda sudah penuh");
				GivePlayerMoneyEx(playerid, -cost);
				rental = gettime() + (1 * 3600);
				OnVehRentPV(playerid, AccountData[playerid][pID], modelid, 1, 1, cost, RentData[id][rentSpawn][0], RentData[id][rentSpawn][1], RentData[id][rentSpawn][2], RentData[id][rentSpawn][3], rental);
				PutPlayerInVehicle(playerid, modelid, 0);
			}
			case 2:
			{
				new pvid = Vehicle_Nearest2(playerid);
					
				forex(i, MAX_RENTAL) if(RentData[i][rentExists])
				{
					if(IsPlayerInRangeOfPoint(playerid, 3.0, RentData[i][rentPos][0], RentData[i][rentPos][1], RentData[i][rentPos][2]))
					{	
						if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
						{
							if(Vehicle_IsOwner(playerid, pvid))
							{
								new query[128], xuery[128];
								mysql_format(g_SQL, query, sizeof(query), "DELETE FROM vehicle WHERE id = '%d'", pvid);
								mysql_tquery(g_SQL, query);

								mysql_format(g_SQL, xuery, sizeof(xuery), "DELETE FROM vstorage WHERE owner = '%d'", pvid);
								mysql_tquery(g_SQL, xuery);
								pvData[pvid][LoadedStorage] = false;

								if(IsValidVehicle(pvid)) DestroyVehicle(pvid);
								pvData[i][cVeh] = INVALID_VEHICLE_ID;
								Iter_SafeRemove(PVehicles, i, i);
							}
						}	
					}
				}
			}
		}
	}    
    return 1;
}

//TD DEATH
stock ShowTdDeath(playerid)
{
	forex(i, 9)
	{
		PlayerTextDrawShow(playerid, PINGSANTD[playerid][i]);
	}	
    return 1;
}
stock HideTdDeath(playerid)
{
	forex(i, 9)
	{
		PlayerTextDrawHide(playerid, PINGSANTD[playerid][i]);
	}
    return 1;
}

task PenguranganData[1000]()
{
    new string[512];
    foreach(new i : Player)
	{
        if(timernotif[i] > 0)
        {
            if(timernotif[i] > 0)
            {
                timernotif[i] --;
            }
            if(timernotif[i] <= 0)
            {
                timernotif[i]  = 0;
                TextDrawHideForAll(notifTD[0]);
                TextDrawHideForAll(notifTD[1]);
            }
        }		
        if(AccountData[i][pInjuredTime] > 0)
        {
            if(AccountData[i][pInjuredTime] > 0)
            {
                AccountData[i][pInjuredTime] --;
                if(AccountData[i][pInjuredTime]-60 < 1)
                {
                    format(string, sizeof(string), "~b~%d detik", AccountData[i][pInjuredTime]);
                }
                else
                {
                    format(string, sizeof(string), "~b~%d menit %d detik", AccountData[i][pInjuredTime]/60, AccountData[i][pInjuredTime]-(60*(AccountData[i][pInjuredTime]/60)));
                }
                PlayerTextDrawSetString(i, PINGSANTD[i][8], string);
                ShowTdDeath(i);
                TogglePlayerControllable(i, false);
                ApplyAnimation(i, "WUZI", "CS_Dead_Guy", 4.1, 1, 1, 1, 1, 0, 1);
            }
		}		
	}	
	return 1;
	
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    foreach(new ii : Player)
    {
        if(pData[ii][pFaction] == 1)
        {
          	new Float: X, Float: Y, Float: Z;
          	GetPlayerPos(playerid, X, Y, Z);
          	SetPlayerCheckpoint(ii,  X, Y, Z, 3.0);

          	for(new a = 0; a < 6; a++)
			{
				PlayerTextDrawShow(ii, notifshootgen[ii][a]);
			}
        	new pe [120]; //Telah Terjadi Penembakan Di Daerah
        	format(pe, sizeof(pe), "Telah terjadi penembakan - Lokasi : ~r~%s", GetLocation(X, Y, Z));
        	PlayerTextDrawSetString(ii, notifshootgen[playerid][5], pe);
        	SetTimerEx("spawntw", 8000, false, "d", ii);
        }
    }
    return 1;
}

forward spawntw(playerid, otherid);
public spawntw(playerid, otherid)
{
	for(new i = 0; i < 10; i++)
	{
		TextDrawHideForPlayer(playerid, PDLogsDeath[i]);
		//CancelSelectTextDraw(playerid);
	}

	for(new i = 0; i < 10; i++)
	{
		TextDrawHideForPlayer(playerid, SAMDLogsDeath[i]);
		//CancelSelectTextDraw(playerid);
	}

	for(new a = 0; a < 6; a++)
	{
		PlayerTextDrawHide(playerid, notifshootgen[playerid][a]);
	}
}

ptask Player_WeaponScore[1000](playerid) 
{
	if(pData[playerid][pLevel] < 5)
	{
		if(GetPlayerWeapon(playerid) > 18 && GetPlayerWeapon(playerid) < 39)
		{
			ResetWeapon(playerid, 22);
			ResetWeapon(playerid, 23);
			ResetWeapon(playerid, 24);
			ResetWeapon(playerid, 25);
			ResetWeapon(playerid, 26);
			ResetWeapon(playerid, 27);
			ResetWeapon(playerid, 28);
			ResetWeapon(playerid, 30);
			ResetWeapon(playerid, 31);
			ResetWeapon(playerid, 32);
			ResetWeapon(playerid, 33);
			ResetWeapon(playerid, 34);
			ResetWeapon(playerid, 35);
			ResetWeapon(playerid, 36);
			ResetWeapon(playerid, 37);
			ResetWeapon(playerid, 38);
		}
		return 1;
	}
	return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
    if ((22 <= weaponid <= 38) && (GetPlayerWeaponState(playerid) == WEAPONSTATE_LAST_BULLET && GetPlayerAmmo(playerid) == 1) && !IsPlayerAttachedObjectSlotUsed(playerid, 4))
 	{
  		switch (weaponid) {
 	        case 22: Inventory_Add(playerid, "Colt 45", 346);
 	        case 24: Inventory_Add(playerid, "Desert Eagle", 348);
 	        case 25: Inventory_Add(playerid, "Shotgun", 349);
 	        case 28: Inventory_Add(playerid, "Micro SMG", 352);
 	        case 29: Inventory_Add(playerid, "MP5", 353);
 	        case 30: Inventory_Add(playerid, "AK-47", 355);
			case 31: Inventory_Add(playerid, "M4", 356);
 	        case 32: Inventory_Add(playerid, "Tec-9", 372);
 	        case 33: Inventory_Add(playerid, "Rifle", 357);
 	        case 34: Inventory_Add(playerid, "Sniper", 358);
		}
 	    ResetWeapon(playerid, weaponid);

 	    HoldWeapon(playerid, weaponid);
 	    Info(playerid, "~r~Senjata anda kehabisan peluru!~w~, gunakan clip untuk menggunakan senjata kembali", 5);
	}
    return 1;
}
