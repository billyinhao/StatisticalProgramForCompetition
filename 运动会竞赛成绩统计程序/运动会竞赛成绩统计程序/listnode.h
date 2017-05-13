#ifndef _LISTNODE_H
#define _LISTNODE_H

typedef struct Institute { //定义院队链表结点
	int mscore; //男队总分
	int wscore; //女队总分
	int tscore; //团体总分
	string institute; //院队名称
	struct Institute *next; //指向下一结点的指针
}INode, *PINode;

typedef struct Event{ //定义比赛项目链表结点
	string event; //项目名称
	int sex; //项目性别
	string rank[8]; //项目各院队排名
	struct Event *next; //指向下一结点的指针
}ENode, *PENode;

typedef struct { //定义院队链表
	PINode head; //链表头结点
}IList;

typedef struct { //定义比赛项目链表
	PENode head; //链表头结点
	int size; //链表结点个数
}EList;

extern EList *Makeelist();
extern IList *Makeilist();
void Makescore(INode node[], const EList *);
void Destroyelist(EList *);
extern EList *elist;
extern IList *ilist;
extern INode node[8];

#endif