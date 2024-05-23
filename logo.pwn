//Converted with Gamer931215's Image2TextDraw converter
#include <a_samp>
#define USED_DRAWS 78
enum textdraw
{
	Text:txid,
	used
}
new TextDrawInfo[USED_DRAWS][textdraw];
public OnFilterScriptInit()
{
	TextDrawInfo[0][txid] = TextDrawCreate(295,1,".");TextDrawTextSize(TextDrawInfo[0][txid],1,1);TextDrawSetShadow(TextDrawInfo[0][txid],0);TextDrawFont(TextDrawInfo[0][txid],2);TextDrawColor(TextDrawInfo[0][txid],0xF1F1F5ff);TextDrawInfo[0][used] = 1;
	TextDrawInfo[1][txid] = TextDrawCreate(296,1,".");TextDrawTextSize(TextDrawInfo[1][txid],1,1);TextDrawSetShadow(TextDrawInfo[1][txid],0);TextDrawFont(TextDrawInfo[1][txid],2);TextDrawColor(TextDrawInfo[1][txid],0xF7F7FAff);TextDrawInfo[1][used] = 1;
	TextDrawInfo[2][txid] = TextDrawCreate(297,1,".");TextDrawTextSize(TextDrawInfo[2][txid],1,1);TextDrawSetShadow(TextDrawInfo[2][txid],0);TextDrawFont(TextDrawInfo[2][txid],2);TextDrawColor(TextDrawInfo[2][txid],0xF0F0F8ff);TextDrawInfo[2][used] = 1;
	TextDrawInfo[3][txid] = TextDrawCreate(301,1,".");TextDrawTextSize(TextDrawInfo[3][txid],1,1);TextDrawSetShadow(TextDrawInfo[3][txid],0);TextDrawFont(TextDrawInfo[3][txid],2);TextDrawColor(TextDrawInfo[3][txid],0xF0F0F4ff);TextDrawInfo[3][used] = 1;
	TextDrawInfo[4][txid] = TextDrawCreate(302,1,".");TextDrawTextSize(TextDrawInfo[4][txid],1,1);TextDrawSetShadow(TextDrawInfo[4][txid],0);TextDrawFont(TextDrawInfo[4][txid],2);TextDrawColor(TextDrawInfo[4][txid],0xF4F4F9ff);TextDrawInfo[4][used] = 1;
	TextDrawInfo[5][txid] = TextDrawCreate(303,1,".");TextDrawTextSize(TextDrawInfo[5][txid],1,1);TextDrawSetShadow(TextDrawInfo[5][txid],0);TextDrawFont(TextDrawInfo[5][txid],2);TextDrawColor(TextDrawInfo[5][txid],0xEDEDF6ff);TextDrawInfo[5][used] = 1;
	TextDrawInfo[6][txid] = TextDrawCreate(292,2,".");TextDrawTextSize(TextDrawInfo[6][txid],1,1);TextDrawSetShadow(TextDrawInfo[6][txid],0);TextDrawFont(TextDrawInfo[6][txid],2);TextDrawColor(TextDrawInfo[6][txid],0xECECF1ff);TextDrawInfo[6][used] = 1;
	TextDrawInfo[7][txid] = TextDrawCreate(295,2,".");TextDrawTextSize(TextDrawInfo[7][txid],1,1);TextDrawSetShadow(TextDrawInfo[7][txid],0);TextDrawFont(TextDrawInfo[7][txid],2);TextDrawColor(TextDrawInfo[7][txid],0xF2F2F5ff);TextDrawInfo[7][used] = 1;
	TextDrawInfo[8][txid] = TextDrawCreate(296,2,".");TextDrawTextSize(TextDrawInfo[8][txid],1,1);TextDrawSetShadow(TextDrawInfo[8][txid],0);TextDrawFont(TextDrawInfo[8][txid],2);TextDrawColor(TextDrawInfo[8][txid],0xF8F8FBff);TextDrawInfo[8][used] = 1;
	TextDrawInfo[9][txid] = TextDrawCreate(297,2,".");TextDrawTextSize(TextDrawInfo[9][txid],1,1);TextDrawSetShadow(TextDrawInfo[9][txid],0);TextDrawFont(TextDrawInfo[9][txid],2);TextDrawColor(TextDrawInfo[9][txid],0xF2F2FAff);TextDrawInfo[9][used] = 1;
	TextDrawInfo[10][txid] = TextDrawCreate(301,2,".");TextDrawTextSize(TextDrawInfo[10][txid],1,1);TextDrawSetShadow(TextDrawInfo[10][txid],0);TextDrawFont(TextDrawInfo[10][txid],2);TextDrawColor(TextDrawInfo[10][txid],0xF3F3F7ff);TextDrawInfo[10][used] = 1;
	TextDrawInfo[11][txid] = TextDrawCreate(292,3,".");TextDrawTextSize(TextDrawInfo[11][txid],1,1);TextDrawSetShadow(TextDrawInfo[11][txid],0);TextDrawFont(TextDrawInfo[11][txid],2);TextDrawColor(TextDrawInfo[11][txid],0xF0F0F5ff);TextDrawInfo[11][used] = 1;
	TextDrawInfo[12][txid] = TextDrawCreate(295,3,".");TextDrawTextSize(TextDrawInfo[12][txid],1,1);TextDrawSetShadow(TextDrawInfo[12][txid],0);TextDrawFont(TextDrawInfo[12][txid],2);TextDrawColor(TextDrawInfo[12][txid],0xF1F1F4ff);TextDrawInfo[12][used] = 1;
	TextDrawInfo[13][txid] = TextDrawCreate(296,3,".");TextDrawTextSize(TextDrawInfo[13][txid],1,1);TextDrawSetShadow(TextDrawInfo[13][txid],0);TextDrawFont(TextDrawInfo[13][txid],2);TextDrawColor(TextDrawInfo[13][txid],0xF8F8FBff);TextDrawInfo[13][used] = 1;
	TextDrawInfo[14][txid] = TextDrawCreate(297,3,".");TextDrawTextSize(TextDrawInfo[14][txid],1,1);TextDrawSetShadow(TextDrawInfo[14][txid],0);TextDrawFont(TextDrawInfo[14][txid],2);TextDrawColor(TextDrawInfo[14][txid],0xF2F2FAff);TextDrawInfo[14][used] = 1;
	TextDrawInfo[15][txid] = TextDrawCreate(300,3,".");TextDrawTextSize(TextDrawInfo[15][txid],1,1);TextDrawSetShadow(TextDrawInfo[15][txid],0);TextDrawFont(TextDrawInfo[15][txid],2);TextDrawColor(TextDrawInfo[15][txid],0xF2F2F7ff);TextDrawInfo[15][used] = 1;
	TextDrawInfo[16][txid] = TextDrawCreate(292,4,".");TextDrawTextSize(TextDrawInfo[16][txid],1,1);TextDrawSetShadow(TextDrawInfo[16][txid],0);TextDrawFont(TextDrawInfo[16][txid],2);TextDrawColor(TextDrawInfo[16][txid],0xECEBEFff);TextDrawInfo[16][used] = 1;
	TextDrawInfo[17][txid] = TextDrawCreate(293,4,".");TextDrawTextSize(TextDrawInfo[17][txid],1,1);TextDrawSetShadow(TextDrawInfo[17][txid],0);TextDrawFont(TextDrawInfo[17][txid],2);TextDrawColor(TextDrawInfo[17][txid],0xF4F4F9ff);TextDrawInfo[17][used] = 1;
	TextDrawInfo[18][txid] = TextDrawCreate(295,4,".");TextDrawTextSize(TextDrawInfo[18][txid],1,1);TextDrawSetShadow(TextDrawInfo[18][txid],0);TextDrawFont(TextDrawInfo[18][txid],2);TextDrawColor(TextDrawInfo[18][txid],0xF1F1F5ff);TextDrawInfo[18][used] = 1;
	TextDrawInfo[19][txid] = TextDrawCreate(296,4,".");TextDrawTextSize(TextDrawInfo[19][txid],1,1);TextDrawSetShadow(TextDrawInfo[19][txid],0);TextDrawFont(TextDrawInfo[19][txid],2);TextDrawColor(TextDrawInfo[19][txid],0xF8F8FBff);TextDrawInfo[19][used] = 1;
	TextDrawInfo[20][txid] = TextDrawCreate(297,4,".");TextDrawTextSize(TextDrawInfo[20][txid],1,1);TextDrawSetShadow(TextDrawInfo[20][txid],0);TextDrawFont(TextDrawInfo[20][txid],2);TextDrawColor(TextDrawInfo[20][txid],0xF2F1FAff);TextDrawInfo[20][used] = 1;
	TextDrawInfo[21][txid] = TextDrawCreate(299,4,".");TextDrawTextSize(TextDrawInfo[21][txid],1,1);TextDrawSetShadow(TextDrawInfo[21][txid],0);TextDrawFont(TextDrawInfo[21][txid],2);TextDrawColor(TextDrawInfo[21][txid],0xF1F1F6ff);TextDrawInfo[21][used] = 1;
	TextDrawInfo[22][txid] = TextDrawCreate(292,5,".");TextDrawTextSize(TextDrawInfo[22][txid],1,1);TextDrawSetShadow(TextDrawInfo[22][txid],0);TextDrawFont(TextDrawInfo[22][txid],2);TextDrawColor(TextDrawInfo[22][txid],0xE3E3E8ff);TextDrawInfo[22][used] = 1;
	TextDrawInfo[23][txid] = TextDrawCreate(293,5,".");TextDrawTextSize(TextDrawInfo[23][txid],1,1);TextDrawSetShadow(TextDrawInfo[23][txid],0);TextDrawFont(TextDrawInfo[23][txid],2);TextDrawColor(TextDrawInfo[23][txid],0xF5F5F8ff);TextDrawInfo[23][used] = 1;
	TextDrawInfo[24][txid] = TextDrawCreate(294,5,".");TextDrawTextSize(TextDrawInfo[24][txid],1,1);TextDrawSetShadow(TextDrawInfo[24][txid],0);TextDrawFont(TextDrawInfo[24][txid],2);TextDrawColor(TextDrawInfo[24][txid],0xF4F4FAff);TextDrawInfo[24][used] = 1;
	TextDrawInfo[25][txid] = TextDrawCreate(295,5,".");TextDrawTextSize(TextDrawInfo[25][txid],1,1);TextDrawSetShadow(TextDrawInfo[25][txid],0);TextDrawFont(TextDrawInfo[25][txid],2);TextDrawColor(TextDrawInfo[25][txid],0xEDEDF6ff);TextDrawInfo[25][used] = 1;
	TextDrawInfo[26][txid] = TextDrawCreate(296,5,".");TextDrawTextSize(TextDrawInfo[26][txid],1,1);TextDrawSetShadow(TextDrawInfo[26][txid],0);TextDrawFont(TextDrawInfo[26][txid],2);TextDrawColor(TextDrawInfo[26][txid],0xF5F5FAff);TextDrawInfo[26][used] = 1;
	TextDrawInfo[27][txid] = TextDrawCreate(297,5,".");TextDrawTextSize(TextDrawInfo[27][txid],1,1);TextDrawSetShadow(TextDrawInfo[27][txid],0);TextDrawFont(TextDrawInfo[27][txid],2);TextDrawColor(TextDrawInfo[27][txid],0xF0F0F8ff);TextDrawInfo[27][used] = 1;
	TextDrawInfo[28][txid] = TextDrawCreate(298,5,".");TextDrawTextSize(TextDrawInfo[28][txid],1,1);TextDrawSetShadow(TextDrawInfo[28][txid],0);TextDrawFont(TextDrawInfo[28][txid],2);TextDrawColor(TextDrawInfo[28][txid],0xF2F2F8ff);TextDrawInfo[28][used] = 1;
	TextDrawInfo[29][txid] = TextDrawCreate(293,6,".");TextDrawTextSize(TextDrawInfo[29][txid],1,1);TextDrawSetShadow(TextDrawInfo[29][txid],0);TextDrawFont(TextDrawInfo[29][txid],2);TextDrawColor(TextDrawInfo[29][txid],0xEEEEF5ff);TextDrawInfo[29][used] = 1;
	TextDrawInfo[30][txid] = TextDrawCreate(294,6,".");TextDrawTextSize(TextDrawInfo[30][txid],1,1);TextDrawSetShadow(TextDrawInfo[30][txid],0);TextDrawFont(TextDrawInfo[30][txid],2);TextDrawColor(TextDrawInfo[30][txid],0xF6F6FAff);TextDrawInfo[30][used] = 1;
	TextDrawInfo[31][txid] = TextDrawCreate(295,6,".");TextDrawTextSize(TextDrawInfo[31][txid],1,1);TextDrawSetShadow(TextDrawInfo[31][txid],0);TextDrawFont(TextDrawInfo[31][txid],2);TextDrawColor(TextDrawInfo[31][txid],0xF5F5FAff);TextDrawInfo[31][used] = 1;
	TextDrawInfo[32][txid] = TextDrawCreate(296,6,".");TextDrawTextSize(TextDrawInfo[32][txid],1,1);TextDrawSetShadow(TextDrawInfo[32][txid],0);TextDrawFont(TextDrawInfo[32][txid],2);TextDrawColor(TextDrawInfo[32][txid],0xEFEFF8ff);TextDrawInfo[32][used] = 1;
	TextDrawInfo[33][txid] = TextDrawCreate(297,6,".");TextDrawTextSize(TextDrawInfo[33][txid],1,1);TextDrawSetShadow(TextDrawInfo[33][txid],0);TextDrawFont(TextDrawInfo[33][txid],2);TextDrawColor(TextDrawInfo[33][txid],0xEEEEF7ff);TextDrawInfo[33][used] = 1;
	TextDrawInfo[34][txid] = TextDrawCreate(298,6,".");TextDrawTextSize(TextDrawInfo[34][txid],1,1);TextDrawSetShadow(TextDrawInfo[34][txid],0);TextDrawFont(TextDrawInfo[34][txid],2);TextDrawColor(TextDrawInfo[34][txid],0xF4F3F9ff);TextDrawInfo[34][used] = 1;
	TextDrawInfo[35][txid] = TextDrawCreate(293,7,".");TextDrawTextSize(TextDrawInfo[35][txid],1,1);TextDrawSetShadow(TextDrawInfo[35][txid],0);TextDrawFont(TextDrawInfo[35][txid],2);TextDrawColor(TextDrawInfo[35][txid],0xEFEFF4ff);TextDrawInfo[35][used] = 1;
	TextDrawInfo[36][txid] = TextDrawCreate(294,7,".");TextDrawTextSize(TextDrawInfo[36][txid],1,1);TextDrawSetShadow(TextDrawInfo[36][txid],0);TextDrawFont(TextDrawInfo[36][txid],2);TextDrawColor(TextDrawInfo[36][txid],0xEFEEF7ff);TextDrawInfo[36][used] = 1;
	TextDrawInfo[37][txid] = TextDrawCreate(295,7,".");TextDrawTextSize(TextDrawInfo[37][txid],1,1);TextDrawSetShadow(TextDrawInfo[37][txid],0);TextDrawFont(TextDrawInfo[37][txid],2);TextDrawColor(TextDrawInfo[37][txid],0xF4F4F9ff);TextDrawInfo[37][used] = 1;
	TextDrawInfo[38][txid] = TextDrawCreate(296,7,".");TextDrawTextSize(TextDrawInfo[38][txid],1,1);TextDrawSetShadow(TextDrawInfo[38][txid],0);TextDrawFont(TextDrawInfo[38][txid],2);TextDrawColor(TextDrawInfo[38][txid],0xF7F7FAff);TextDrawInfo[38][used] = 1;
	TextDrawInfo[39][txid] = TextDrawCreate(297,7,".");TextDrawTextSize(TextDrawInfo[39][txid],1,1);TextDrawSetShadow(TextDrawInfo[39][txid],0);TextDrawFont(TextDrawInfo[39][txid],2);TextDrawColor(TextDrawInfo[39][txid],0xF5F5FAff);TextDrawInfo[39][used] = 1;
	TextDrawInfo[40][txid] = TextDrawCreate(298,7,".");TextDrawTextSize(TextDrawInfo[40][txid],1,1);TextDrawSetShadow(TextDrawInfo[40][txid],0);TextDrawFont(TextDrawInfo[40][txid],2);TextDrawColor(TextDrawInfo[40][txid],0xF0EFF8ff);TextDrawInfo[40][used] = 1;
	TextDrawInfo[41][txid] = TextDrawCreate(299,7,".");TextDrawTextSize(TextDrawInfo[41][txid],1,1);TextDrawSetShadow(TextDrawInfo[41][txid],0);TextDrawFont(TextDrawInfo[41][txid],2);TextDrawColor(TextDrawInfo[41][txid],0xECECF6ff);TextDrawInfo[41][used] = 1;
	TextDrawInfo[42][txid] = TextDrawCreate(293,8,".");TextDrawTextSize(TextDrawInfo[42][txid],1,1);TextDrawSetShadow(TextDrawInfo[42][txid],0);TextDrawFont(TextDrawInfo[42][txid],2);TextDrawColor(TextDrawInfo[42][txid],0xEBEBF0ff);TextDrawInfo[42][used] = 1;
	TextDrawInfo[43][txid] = TextDrawCreate(294,8,".");TextDrawTextSize(TextDrawInfo[43][txid],1,1);TextDrawSetShadow(TextDrawInfo[43][txid],0);TextDrawFont(TextDrawInfo[43][txid],2);TextDrawColor(TextDrawInfo[43][txid],0xF4F3F9ff);TextDrawInfo[43][used] = 1;
	TextDrawInfo[44][txid] = TextDrawCreate(295,8,".");TextDrawTextSize(TextDrawInfo[44][txid],1,1);TextDrawSetShadow(TextDrawInfo[44][txid],0);TextDrawFont(TextDrawInfo[44][txid],2);TextDrawColor(TextDrawInfo[44][txid],0xF0F0F8ff);TextDrawInfo[44][used] = 1;
	TextDrawInfo[45][txid] = TextDrawCreate(296,8,".");TextDrawTextSize(TextDrawInfo[45][txid],1,1);TextDrawSetShadow(TextDrawInfo[45][txid],0);TextDrawFont(TextDrawInfo[45][txid],2);TextDrawColor(TextDrawInfo[45][txid],0xEFEFF7ff);TextDrawInfo[45][used] = 1;
	TextDrawInfo[46][txid] = TextDrawCreate(297,8,".");TextDrawTextSize(TextDrawInfo[46][txid],1,1);TextDrawSetShadow(TextDrawInfo[46][txid],0);TextDrawFont(TextDrawInfo[46][txid],2);TextDrawColor(TextDrawInfo[46][txid],0xF4F3F9ff);TextDrawInfo[46][used] = 1;
	TextDrawInfo[47][txid] = TextDrawCreate(298,8,".");TextDrawTextSize(TextDrawInfo[47][txid],1,1);TextDrawSetShadow(TextDrawInfo[47][txid],0);TextDrawFont(TextDrawInfo[47][txid],2);TextDrawColor(TextDrawInfo[47][txid],0xF6F5FAff);TextDrawInfo[47][used] = 1;
	TextDrawInfo[48][txid] = TextDrawCreate(299,8,".");TextDrawTextSize(TextDrawInfo[48][txid],1,1);TextDrawSetShadow(TextDrawInfo[48][txid],0);TextDrawFont(TextDrawInfo[48][txid],2);TextDrawColor(TextDrawInfo[48][txid],0xF3F3FAff);TextDrawInfo[48][used] = 1;
	TextDrawInfo[49][txid] = TextDrawCreate(300,8,".");TextDrawTextSize(TextDrawInfo[49][txid],1,1);TextDrawSetShadow(TextDrawInfo[49][txid],0);TextDrawFont(TextDrawInfo[49][txid],2);TextDrawColor(TextDrawInfo[49][txid],0xE6E6F4ff);TextDrawInfo[49][used] = 1;
	TextDrawInfo[50][txid] = TextDrawCreate(293,9,".");TextDrawTextSize(TextDrawInfo[50][txid],1,1);TextDrawSetShadow(TextDrawInfo[50][txid],0);TextDrawFont(TextDrawInfo[50][txid],2);TextDrawColor(TextDrawInfo[50][txid],0xE8E8EDff);TextDrawInfo[50][used] = 1;
	TextDrawInfo[51][txid] = TextDrawCreate(294,9,".");TextDrawTextSize(TextDrawInfo[51][txid],1,1);TextDrawSetShadow(TextDrawInfo[51][txid],0);TextDrawFont(TextDrawInfo[51][txid],2);TextDrawColor(TextDrawInfo[51][txid],0xEFEEF5ff);TextDrawInfo[51][used] = 1;
	TextDrawInfo[52][txid] = TextDrawCreate(295,9,".");TextDrawTextSize(TextDrawInfo[52][txid],1,1);TextDrawSetShadow(TextDrawInfo[52][txid],0);TextDrawFont(TextDrawInfo[52][txid],2);TextDrawColor(TextDrawInfo[52][txid],0xF3F3F9ff);TextDrawInfo[52][used] = 1;
	TextDrawInfo[53][txid] = TextDrawCreate(296,9,".");TextDrawTextSize(TextDrawInfo[53][txid],1,1);TextDrawSetShadow(TextDrawInfo[53][txid],0);TextDrawFont(TextDrawInfo[53][txid],2);TextDrawColor(TextDrawInfo[53][txid],0xF4F4FAff);TextDrawInfo[53][used] = 1;
	TextDrawInfo[54][txid] = TextDrawCreate(297,9,".");TextDrawTextSize(TextDrawInfo[54][txid],1,1);TextDrawSetShadow(TextDrawInfo[54][txid],0);TextDrawFont(TextDrawInfo[54][txid],2);TextDrawColor(TextDrawInfo[54][txid],0xF3F2F9ff);TextDrawInfo[54][used] = 1;
	TextDrawInfo[55][txid] = TextDrawCreate(298,9,".");TextDrawTextSize(TextDrawInfo[55][txid],1,1);TextDrawSetShadow(TextDrawInfo[55][txid],0);TextDrawFont(TextDrawInfo[55][txid],2);TextDrawColor(TextDrawInfo[55][txid],0xF1F1F9ff);TextDrawInfo[55][used] = 1;
	TextDrawInfo[56][txid] = TextDrawCreate(299,9,".");TextDrawTextSize(TextDrawInfo[56][txid],1,1);TextDrawSetShadow(TextDrawInfo[56][txid],0);TextDrawFont(TextDrawInfo[56][txid],2);TextDrawColor(TextDrawInfo[56][txid],0xF4F3FAff);TextDrawInfo[56][used] = 1;
	TextDrawInfo[57][txid] = TextDrawCreate(300,9,".");TextDrawTextSize(TextDrawInfo[57][txid],1,1);TextDrawSetShadow(TextDrawInfo[57][txid],0);TextDrawFont(TextDrawInfo[57][txid],2);TextDrawColor(TextDrawInfo[57][txid],0xF4F4FAff);TextDrawInfo[57][used] = 1;
	TextDrawInfo[58][txid] = TextDrawCreate(294,10,".");TextDrawTextSize(TextDrawInfo[58][txid],1,1);TextDrawSetShadow(TextDrawInfo[58][txid],0);TextDrawFont(TextDrawInfo[58][txid],2);TextDrawColor(TextDrawInfo[58][txid],0xF0EFF4ff);TextDrawInfo[58][used] = 1;
	TextDrawInfo[59][txid] = TextDrawCreate(295,10,".");TextDrawTextSize(TextDrawInfo[59][txid],1,1);TextDrawSetShadow(TextDrawInfo[59][txid],0);TextDrawFont(TextDrawInfo[59][txid],2);TextDrawColor(TextDrawInfo[59][txid],0xF0F0F7ff);TextDrawInfo[59][used] = 1;
	TextDrawInfo[60][txid] = TextDrawCreate(296,10,".");TextDrawTextSize(TextDrawInfo[60][txid],1,1);TextDrawSetShadow(TextDrawInfo[60][txid],0);TextDrawFont(TextDrawInfo[60][txid],2);TextDrawColor(TextDrawInfo[60][txid],0xF0F0F8ff);TextDrawInfo[60][used] = 1;
	TextDrawInfo[61][txid] = TextDrawCreate(297,10,".");TextDrawTextSize(TextDrawInfo[61][txid],1,1);TextDrawSetShadow(TextDrawInfo[61][txid],0);TextDrawFont(TextDrawInfo[61][txid],2);TextDrawColor(TextDrawInfo[61][txid],0xF2F1F9ff);TextDrawInfo[61][used] = 1;
	TextDrawInfo[62][txid] = TextDrawCreate(298,10,".");TextDrawTextSize(TextDrawInfo[62][txid],1,1);TextDrawSetShadow(TextDrawInfo[62][txid],0);TextDrawFont(TextDrawInfo[62][txid],2);TextDrawColor(TextDrawInfo[62][txid],0xF3F2F9ff);TextDrawInfo[62][used] = 1;
	TextDrawInfo[63][txid] = TextDrawCreate(299,10,".");TextDrawTextSize(TextDrawInfo[63][txid],1,1);TextDrawSetShadow(TextDrawInfo[63][txid],0);TextDrawFont(TextDrawInfo[63][txid],2);TextDrawColor(TextDrawInfo[63][txid],0xF5F4FAff);TextDrawInfo[63][used] = 1;
	TextDrawInfo[64][txid] = TextDrawCreate(300,10,".");TextDrawTextSize(TextDrawInfo[64][txid],1,1);TextDrawSetShadow(TextDrawInfo[64][txid],0);TextDrawFont(TextDrawInfo[64][txid],2);TextDrawColor(TextDrawInfo[64][txid],0xF9F9FBff);TextDrawInfo[64][used] = 1;
	TextDrawInfo[65][txid] = TextDrawCreate(301,10,".");TextDrawTextSize(TextDrawInfo[65][txid],1,1);TextDrawSetShadow(TextDrawInfo[65][txid],0);TextDrawFont(TextDrawInfo[65][txid],2);TextDrawColor(TextDrawInfo[65][txid],0xF4F4FAff);TextDrawInfo[65][used] = 1;
	TextDrawInfo[66][txid] = TextDrawCreate(302,10,".");TextDrawTextSize(TextDrawInfo[66][txid],1,1);TextDrawSetShadow(TextDrawInfo[66][txid],0);TextDrawFont(TextDrawInfo[66][txid],2);TextDrawColor(TextDrawInfo[66][txid],0xE9E9F5ff);TextDrawInfo[66][used] = 1;
	TextDrawInfo[67][txid] = TextDrawCreate(295,11,".");TextDrawTextSize(TextDrawInfo[67][txid],1,1);TextDrawSetShadow(TextDrawInfo[67][txid],0);TextDrawFont(TextDrawInfo[67][txid],2);TextDrawColor(TextDrawInfo[67][txid],0xF1F1F5ff);TextDrawInfo[67][used] = 1;
	TextDrawInfo[68][txid] = TextDrawCreate(296,11,".");TextDrawTextSize(TextDrawInfo[68][txid],1,1);TextDrawSetShadow(TextDrawInfo[68][txid],0);TextDrawFont(TextDrawInfo[68][txid],2);TextDrawColor(TextDrawInfo[68][txid],0xF2F2F7ff);TextDrawInfo[68][used] = 1;
	TextDrawInfo[69][txid] = TextDrawCreate(297,11,".");TextDrawTextSize(TextDrawInfo[69][txid],1,1);TextDrawSetShadow(TextDrawInfo[69][txid],0);TextDrawFont(TextDrawInfo[69][txid],2);TextDrawColor(TextDrawInfo[69][txid],0xF3F3F8ff);TextDrawInfo[69][used] = 1;
	TextDrawInfo[70][txid] = TextDrawCreate(298,11,".");TextDrawTextSize(TextDrawInfo[70][txid],1,1);TextDrawSetShadow(TextDrawInfo[70][txid],0);TextDrawFont(TextDrawInfo[70][txid],2);TextDrawColor(TextDrawInfo[70][txid],0xF2F2F8ff);TextDrawInfo[70][used] = 1;
	TextDrawInfo[71][txid] = TextDrawCreate(299,11,".");TextDrawTextSize(TextDrawInfo[71][txid],1,1);TextDrawSetShadow(TextDrawInfo[71][txid],0);TextDrawFont(TextDrawInfo[71][txid],2);TextDrawColor(TextDrawInfo[71][txid],0xF4F3F8ff);TextDrawInfo[71][used] = 1;
	TextDrawInfo[72][txid] = TextDrawCreate(301,11,".");TextDrawTextSize(TextDrawInfo[72][txid],2,1);TextDrawSetShadow(TextDrawInfo[72][txid],0);TextDrawFont(TextDrawInfo[72][txid],2);TextDrawColor(TextDrawInfo[72][txid],0xF7F7FAff);TextDrawInfo[72][used] = 1;
	TextDrawInfo[73][txid] = TextDrawCreate(302,11,".");TextDrawTextSize(TextDrawInfo[73][txid],1,1);TextDrawSetShadow(TextDrawInfo[73][txid],0);TextDrawFont(TextDrawInfo[73][txid],2);TextDrawColor(TextDrawInfo[73][txid],0xEFEEF8ff);TextDrawInfo[73][used] = 1;
	TextDrawInfo[74][txid] = TextDrawCreate(303,11,".");TextDrawTextSize(TextDrawInfo[74][txid],1,1);TextDrawSetShadow(TextDrawInfo[74][txid],0);TextDrawFont(TextDrawInfo[74][txid],2);TextDrawColor(TextDrawInfo[74][txid],0xF3F2F9ff);TextDrawInfo[74][used] = 1;
	TextDrawInfo[75][txid] = TextDrawCreate(302,12,".");TextDrawTextSize(TextDrawInfo[75][txid],1,1);TextDrawSetShadow(TextDrawInfo[75][txid],0);TextDrawFont(TextDrawInfo[75][txid],2);TextDrawColor(TextDrawInfo[75][txid],0xE9E9F0ff);TextDrawInfo[75][used] = 1;
	TextDrawInfo[76][txid] = TextDrawCreate(303,12,".");TextDrawTextSize(TextDrawInfo[76][txid],1,1);TextDrawSetShadow(TextDrawInfo[76][txid],0);TextDrawFont(TextDrawInfo[76][txid],2);TextDrawColor(TextDrawInfo[76][txid],0xEFEFF5ff);TextDrawInfo[76][used] = 1;
	TextDrawInfo[77][txid] = TextDrawCreate(304,12,".");TextDrawTextSize(TextDrawInfo[77][txid],1,1);TextDrawSetShadow(TextDrawInfo[77][txid],0);TextDrawFont(TextDrawInfo[77][txid],2);TextDrawColor(TextDrawInfo[77][txid],0xF1F1F6ff);TextDrawInfo[77][used] = 1;
	return 1;
}
public OnPlayerConnect(playerid)
{
	for(new i = 0;i<USED_DRAWS;i++)
	{
	    if(TextDrawInfo[i][used] == 1){TextDrawShowForPlayer(playerid,TextDrawInfo[i][txid]);}
	}
	return 1;
}

public OnFilterScriptExit()
{
	for(new i = 0;i<USED_DRAWS;i++)
	{
	    if(TextDrawInfo[i][used] == 1){TextDrawDestroy(TextDrawInfo[i][txid]);}
	}
	return 1;
}