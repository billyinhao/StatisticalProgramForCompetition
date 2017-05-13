#include"stdafx.h"
#include"listnode.h"
#include "main.h"

ifstream ifs("sports.txt");

PENode Makeenode() { //向新比赛项目结点中写入数据
	PENode node = new ENode;
	if (node != NULL) {
		string ch;
		if (ifs.eof()) return NULL; //判断是否读到文件结尾
		getline(ifs, ch);
		node->event = ch; //写入名称项
		if (ch[0] == 'm') node->sex = m; //写入性别项
		else node->sex = w;
		for (int i = 0; i <= 6; i++) { //写入排名项
			getline(ifs, ch, ' ');
			node->rank[i] = ch;
		}
		getline(ifs, ch);
		node->rank[7] = ch;
		node->next = NULL;
	}
	return node; //返回新比赛项目结点
}

void Addscore(INode &node, const PENode lastptr, int score) { //计算男女队分数
	if (score == 8) score++;
	if (lastptr->sex == m) node.mscore += score;
	else node.wscore += score;
}

void Makescore(INode node[], const EList *list) { //向院队结点中分数项赋值
	PENode lastptr = list->head->next;
	while (lastptr != NULL) {
		for (int j = 0; j <= 7;j++) {
			if (lastptr->rank[j] == "xinxi") Addscore(node[xinxi], lastptr, 8 - j);
			else if (lastptr->rank[j] == "guofang") Addscore(node[guofang], lastptr, 8 - j);
			else if (lastptr->rank[j] == "ruanjian") Addscore(node[ruanjian], lastptr, 8 - j);
			else if (lastptr->rank[j] == "caiye") Addscore(node[caiye], lastptr, 8 - j);
			else if (lastptr->rank[j] == "gongguan") Addscore(node[gongguan], lastptr, 8 - j);
			else if (lastptr->rank[j] == "waiyu") Addscore(node[waiyu], lastptr, 8 - j);
			else if (lastptr->rank[j] == "shengke") Addscore(node[shengke], lastptr, 8 - j);
			else if (lastptr->rank[j] == "mazhe") Addscore(node[mazhe], lastptr, 8 - j);
		}
		lastptr = lastptr->next;
	}
	for (int j = 0; j <= 7; j++) node[j].tscore = node[j].mscore + node[j].wscore; //计算总分
}

EList *Makeelist() { //建立比赛项目链表
	EList *elist = (EList*)malloc(sizeof(EList));
	elist->size = 0;
	PENode head = (PENode)malloc(sizeof(ENode));
	if (elist != NULL) {
		if (head != NULL) {
			elist->head = head;
			head->next = NULL;
			PENode lastptr, newptr = Makeenode();
			lastptr = elist->head;
			while (newptr != NULL) {
				lastptr->next = newptr;
				elist->size++;
				lastptr = newptr;
				newptr = Makeenode();
			}
		}
	}
	return elist;
}

IList *Makeilist() { //建立院队链表
	IList *ilist = (IList*)malloc(sizeof(IList));
	PINode head = (PINode)malloc(sizeof(INode));
	if (ilist != NULL) {
		if (head != NULL) {
			ilist->head = head;
			head->next = NULL;
			PINode preptr = NULL, lastptr = NULL, newptr = NULL;
			for (int i = 0; i <= 7; i++) {
				newptr = &node[i];
				newptr->next = NULL;
				preptr = ilist->head;
				lastptr = ilist->head->next;
				if (lastptr == NULL) ilist->head->next = newptr;
				else {
					while ((lastptr != NULL) && (newptr->tscore < lastptr->tscore)) { //使结点按分数从大到小排序
						preptr = lastptr;
						lastptr = lastptr->next;
					}
					if (lastptr != NULL) {
						preptr->next = newptr;
						newptr->next = lastptr;
					}
					else preptr->next = newptr;
				}
			}
		}
	}
	return ilist;
}

void Destroyelist(EList *elist) { //销毁链表
	PENode p, temp;
	p = elist->head;
	while (p != NULL) {
		temp = p->next;
		free(p);
		p = temp;
	}
	free(elist);
}