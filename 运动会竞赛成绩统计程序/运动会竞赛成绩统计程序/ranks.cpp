#include "stdafx.h"
#include"listnode.h"
#include"main.h"

int tpage = 0; //比赛项目排名总页数
void Pin();
void Pev(int);

void Ranks() { //排名主函数
	tpage = (elist->size / 6) + 1;
	if (elist->size % 6 != 0) tpage++;
	Pin();
	_getch();
}

void Showevent(const PENode lastptr, int i) { //显示各比赛项目排名
	int j = 0;
	if (i > 2) j = 10;
	gotoxy(hout, 2 + 26 * (i % 3), 4 + j);
	cout << "---" << Prtevent(lastptr->event) << "---";
	for (int k = 0; k < 6; k++) {
		gotoxy(hout, 2 + 26 * (i % 3), 6 + j + k);
		cout << "第" << k + 1 << "名：" << Prtinst(lastptr->rank[k]);
	}
}

void Pin() { //显示院队排名页面
	system("CLS");
	Grid();
	gotoxy(hout, 2, 1);
	cout << "★运动大会成绩排名★\t\t\t\t0.主菜单    \t    2.下一页";
	PINode lastptr = ilist->head->next;
	gotoxy(hout, 32, 9);
	cout << "===团体成绩===" << endl;
	for (int i = 1; i < 4; i++) {
		gotoxy(hout, 28, 9 + 2 * i);
		cout << "第" << i << "名：" << Prtinst(lastptr->institute) << ' ' << lastptr->tscore << "分" << endl;
		lastptr = lastptr->next;
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '2':Pev(2); break;
		case '0':Ui(true); break;
		default:continue;
		}
	}
}

void Pev(int page) { //显示比赛项目排名页面
	system("CLS");
	Grid();
	if (page < 2) page = 2;
	else if (page > tpage) page = tpage;
	gotoxy(hout, 2, 1);
	if (page == tpage) cout << "★运动大会成绩排名★\t\t\t\t0.主菜单  1.上一页";
	else cout << "★运动大会成绩排名★\t\t\t\t0.主菜单  1.上一页  2.下一页";
	PENode lastptr = elist->head->next;
	for (int i = 0; i < (page - 2) * 6; i++) lastptr = lastptr->next;
	for (int j = 0; j < 6; j++) {
		Showevent(lastptr, j);
		lastptr = lastptr->next;
	}
	while (true) {
		char ch = _getch();
		switch (ch) {
		case '1':
			if (page == 2) Pin();
			else Pev(--page);
			break;
		case '0':
			Ui(true);
			break;
		case '2':
			if (page < tpage) Pev(++page);
		default:continue;
		}
	}
}