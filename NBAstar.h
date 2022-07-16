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
//�˵�ö��
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

//��Ա��Ϣ����
typedef struct StarNumber
{
	char name[MAX_NAME];
	int age;
	int hei;//���
	int wei;//����
	char bir[MAX_BIR];//����
	char team[MAX_TEAM];//���
	char achieve[MAX_ACH];//�ɾ�
}StNu;
//�ڵ���������
typedef struct node
{
	struct StarNumber data;//������
	struct node* next;//ָ����
}Node,*LinkNode;
//����ϵͳ
void Loding();
//���ܺ���
void ChangePs(char* pass);
//��¼ϵͳ
int login(char* passnum);

//��ʼ������
Node* InitStarnum(Node* ps);

//������ݵĺ���
Node* Addstarnum(Node* ps, int* cap);

//������ݺ���
void ShowStarnum(Node* ps);

//ɾ�����ݺ���
void Delstarnum(Node* ps, int* cap);

//���ļ����浽�ļ�
void Savestarnum(Node* ps);

//���ļ��е����ݵ�������
Node* ResetStarnum(Node* ps, int* cap);

//������������������
Node* SearchStarnum(Node* ps);

//������������
void DestroyStarnum(Node* ps);

//�޸���������Ϣ
void ModifyStarnum(Node* ps);

//�����������ݽ�������
void SortStarnum(Node* ps,int cap);
//
//����ѡ����������
void SelectSortage(Node* ps,int t);

//ѡ�������������
void SelectSorthei(Node* ps,int t);

//�����յ�ѡ������
void SelectSortwei(Node* ps, int t);

//�����ص�����
void SelectSortwei(Node* ps, int t);

//������������
void SelectSortname(Node* ps, int t);

//������������
void SelectSortteam(Node* ps, int t);