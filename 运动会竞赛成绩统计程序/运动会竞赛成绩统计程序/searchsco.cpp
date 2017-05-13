#include"stdafx.h"
#include"listnode.h"
#include"main.h"

void Showinst(const string str) { //显示院队详细信息
	int irank = 1; //院队排名值
	system("CLS");
	Grid();
	PINode ilastptr = ilist->head->next;
	while (ilastptr->institute != str) {
		ilastptr = ilastptr->next;
		irank++;
	}
	gotoxy(hout, 2, 1);
	cout << "★成绩查询★\t\t\t\t\t    ===按任意键返回上一级===";
	gotoxy(hout, 2, 3);
	cout << "===" << Prtinst(str) << "===";
	gotoxy(hout, 3, 5);
	cout << "男队总分：" << ilastptr->mscore << "分  |  女队总分："<< ilastptr->wscore << "分";
	gotoxy(hout, 3, 7);
	cout << "团体总分：" << ilastptr->tscore << "分 → 第" << irank << "名";
	gotoxy(hout, 30, 9);
	cout << "---各项赛事排名---";
	PENode elastptr = elist->head->next;
	int num = 0;
	while (elastptr != NULL) {
		int i = 0, erank = 1;
		while (str != elastptr->rank[i++]) erank++; //计算该院队在各比赛项目中排名
		gotoxy(hout, 5 + (num / 6) * 23, 11 + num % 6 * 2);
		cout << Prtevent(elastptr->event) << "：第" << erank << "名";
		elastptr = elastptr->next;
		num++;
	}
	_getch();
}

void Searchsco() { //查询主函数
	while (true) {
		PINode lastptr = ilist->head->next;
		system("CLS");
		Grid();
		gotoxy(hout, 2, 1);
		cout << "★成绩查询★";
		gotoxy(hout, 24, 7);
		cout << "→ 请输入需查询的学院的代码：";
		int i = 0;
		while (lastptr != NULL) {
			gotoxy(hout, 22 + i / 4 * 20, 9 + i % 4 * 2);
			cout << i + 1 << "." << Prtinst(lastptr->institute);
			lastptr = lastptr->next;
			i++;
		}
		gotoxy(hout, 62, 21);
		cout << "0.返回主菜单";
	secho:
		char ch = _getch();
		if (ch == '0') break;
		else {
			switch (ch) {
			case '1':Showinst("xinxi"); break;
			case '2':Showinst("ruanjian"); break;
			case '3':Showinst("waiyu"); break;
			case '4':Showinst("guofang"); break;
			case '5':Showinst("gongguan"); break;
			case '6':Showinst("caiye"); break;
			case '7':Showinst("mazhe"); break;
			case '8':Showinst("shengke"); break;
			default:goto secho;
			}
		}
	}
	Ui(true);
}