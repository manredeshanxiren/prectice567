#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME 20
#define MAX_BIR 15
#define MAX_TEAM 25
#define MAX_ACH 50
#define MAX_PD 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<errno.h>
//菜单枚举
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE,
	CHANGEPS
};

//球员信息类型
typedef struct StarNumber
{
	char name[MAX_NAME];
	int age;
	int hei;//身高
	int wei;//体重
	char bir[MAX_BIR];//生日
	char team[MAX_TEAM];//球队
	char achieve[MAX_ACH];//成就
}StNu;
//节点数据类型
typedef struct node
{
	struct StarNumber data;//数据域
	struct node* next;//指针域
}Node,*LinkNode;
//加载系统
void Loding();
//改密函数
void ChangePs(char* pass);
//登录系统
int login(char* passnum);

//初始化函数
Node* InitStarnum(Node* ps);

//添加数据的函数
Node* Addstarnum(Node* ps, int* cap);

//输出数据函数
void ShowStarnum(Node* ps);

//删除数据函数
void Delstarnum(Node* ps, int* cap);

//将文件保存到文件
void Savestarnum(Node* ps);

//将文件中的数据导入链表
Node* ResetStarnum(Node* ps, int* cap);

//链表内数据搜索函数
Node* SearchStarnum(Node* ps);

//销毁链表数据
void DestroyStarnum(Node* ps);

//修改链表内信息
void ModifyStarnum(Node* ps);

//对链表内数据进行排序
void SortStarnum(Node* ps,int cap);
//
//整型选择排序年龄
void SelectSortage(Node* ps,int t);

//选择排序整型身高
void SelectSorthei(Node* ps,int t);

//对生日的选择排序
void SelectSortwei(Node* ps, int t);

//对体重的排序
void SelectSortwei(Node* ps, int t);

//对姓名的排序
void SelectSortname(Node* ps, int t);

//对姓名的排序
void SelectSortteam(Node* ps, int t);