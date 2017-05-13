#include"stdafx.h"
#include"listnode.h"
#include"main.h"

void Score(INode node[]) { //得分情况函数
	system("CLS");
	Grid();
	gotoxy(hout, 2, 1);
	cout << "★运动大会得分情况★";
	gotoxy(hout, 3, 4);
	cout << "信息学院 → 男队总分：" << node[xinxi].mscore << "分 女队总分：" << node[xinxi].wscore << "分 团体总分：" << node[xinxi].tscore << "分";
	gotoxy(hout, 3, 6);
	cout << "软件学院 → 男队总分：" << node[ruanjian].mscore << "分 女队总分：" << node[ruanjian].wscore << "分 团体总分：" << node[ruanjian].tscore << "分";
	gotoxy(hout, 3, 8);
	cout << "外国语学院 → 男队总分：" << node[waiyu].mscore << "分 女队总分：" << node[waiyu].wscore << "分 团体总分：" << node[waiyu].tscore << "分";
	gotoxy(hout, 3, 10);
	cout << "国防教育学院 → 男队总分：" << node[guofang].mscore << "分 女队总分：" << node[guofang].wscore << "分 团体总分：" << node[guofang].tscore << "分";
	gotoxy(hout, 3, 12);
	cout << "工商管理学院 → 男队总分：" << node[gongguan].mscore << "分 女队总分：" << node[gongguan].wscore << "分 团体总分：" << node[gongguan].tscore << "分";
	gotoxy(hout, 3, 14);
	cout << "材料与冶金学院 → 男队总分：" << node[caiye].mscore << "分 女队总分：" << node[caiye].wscore << "分 团体总分：" << node[caiye].tscore << "分";
	gotoxy(hout, 3, 16);
	cout << "马克思主义学院 → 男队总分：" << node[mazhe].mscore << "分 女队总分：" << node[mazhe].wscore << "分 团体总分：" << node[mazhe].tscore << "分";
	gotoxy(hout, 3, 18);
	cout << "生命科学与健康学院 → 男队总分：" << node[shengke].mscore << "分 女队总分：" << node[shengke].wscore << "分 团体总分：" << node[shengke].tscore << "分";
	gotoxy(hout, 27, 22);
	cout << "===按任意键返回主菜单===";
	_getch();
	Ui(true);
}