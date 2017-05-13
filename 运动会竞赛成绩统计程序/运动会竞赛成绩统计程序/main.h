#ifndef _MAIN_H
#define _MAIN_H
#define m 0
#define w 1
#define xinxi 0
#define guofang 1
#define ruanjian 2
#define caiye 3
#define gongguan 4
#define waiyu 5
#define shengke 6
#define mazhe 7

void gotoxy(HANDLE hout, int x, int y);
extern HANDLE hout;
void Grid();
void Ui(bool);
string Prtinst(string);
string Prtevent(string);
void Ranks();
void Score(INode[]);
void Searchsco();

#endif