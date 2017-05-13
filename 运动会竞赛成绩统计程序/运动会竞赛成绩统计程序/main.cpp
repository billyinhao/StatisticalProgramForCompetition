// 运动会竞赛成绩统计程序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "listnode.h"
#include "main.h"
#pragma warning(disable: 4996)

void Grid();
void Ui(bool);
void Score();
bool Searchfile();

EList *elist;
IList *ilist;
INode node[8] = { { 0,0,0,"xinxi" },{ 0,0,0,"guofang" },{ 0,0,0,"ruanjian" },{ 0,0,0,"caiye" },
{ 0,0,0,"gongguan" },{ 0,0,0,"waiyu" },{ 0,0,0 ,"shengke" },{ 0,0,0,"mazhe" } }; //初始化院队结构体数组
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

int main(){
	bool flag = Searchfile();
	if (flag == true) {
		elist = Makeelist();
		Makescore(node, elist);
		ilist = Makeilist();
		Ui(true);
	}
	else Ui(false);
	return 0;
}

void gotoxy(HANDLE hout, int x, int y) { //光标定位函数
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hout, pos);
}

void Grid() { //边框
	gotoxy(hout, 0, 0);
	system("COLOR 2E");
	int a;
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
}

bool Searchfile() { //链接sports.txt
	FILE *fp;
	fp = fopen("sports.txt", "r");
	if (fp == NULL) return false;
	else {
		char ch = '\0';
		fscanf_s(fp, "%c", &ch, 1);
		if (ch == '\0' || ch == ' ') return false;
		else return true;
	}
}

void Ui(bool flag) { //显示主界面函数
	Grid();
	gotoxy(hout, 21, 2);
	cout << "★=====东北大学第51届运动大会=====★" << endl;
	gotoxy(hout, 25, 4);
	cout << "★=====竞赛总成绩统计=====★";
	gotoxy(hout, 30, 9);
	cout << "请输入数字选择项目：" << endl;
	gotoxy(hout, 30, 11);
	cout << "1.运动大会得分情况" << endl;
	gotoxy(hout, 30, 13);
	cout << "2.运动大会成绩排名" << endl;
	gotoxy(hout, 30, 15);
	cout << "3.成绩查询";
	gotoxy(hout, 30, 17);
	cout << "0.退出";
	gotoxy(hout, 2, 22);
	if (flag == true) cout << "sports.txt链接成功！";
	else {
		cout << "sports.txt不存在或为空！按任意键退出程序。";
		_getch();
		exit(0);
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '1':Score(node); break;
		case '2':Ranks(); break;
		case '3':Searchsco(); break;
		case '0':
			Destroyelist(elist);
			exit(0);
		default:continue;
		}
	}
}

string Prtinst(const string str) { //打印院队名称
	if (str == "xinxi") return "信息学院";
	else if (str == "guofang") return "国防教育学院";
	else if (str == "ruanjian") return "软件学院";
	else if (str == "caiye") return "材料与冶金学院";
	else if (str == "gongguan") return "工商管理学院";
	else if (str == "waiyu") return "外国语学院";
	else if (str == "shengke") return "生命与科学学院";
	else if (str == "mazhe") return "马克思主义学院";
	else return NULL;
}

string Prtevent(const string str) { //打印比赛项目名称
	if (str == "m800") return "男子800米";
	else if (str == "w800") return "女子800米";
	else if (str == "m4*100") return "男子4×100米接力";
	else if (str == "w4*100") return "女子4×100米接力";
	else if (str == "m100") return "男子100米";
	else if (str == "w100") return "女子100米";
	else if (str == "m1500") return "男子1500米";
	else if (str == "wsitup") return "女子仰卧起坐";
	else if (str == "mhjump") return "男子跳高";
	else if (str == "whjump") return "女子跳高";
	else if (str == "mljump") return "男子跳远";
	else if (str == "wljump") return "女子跳远";
	else if (str == "mtjump") return "男子三级跳";
	else if (str == "wtjump") return "女子三级跳";
	else if (str == "mball") return "男子掷垒球";
	else if (str == "wball") return "女子掷垒球";
	else if (str == "mmara") return "男子马拉松";
	else if (str == "wmara") return "女子马拉松";
	else return NULL;
}