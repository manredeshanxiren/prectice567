#include"NBAstar.h"
void menu()
{
	printf("\t\t\t********   NBA���ǹ���ϵͳ    ********\n");
	printf("\t\t\t**************************************\n");
	printf("\t\t\t******  1.���         2.ɾ��   ******\n");
	printf("\t\t\t******  3.����         4.�޸�   ******\n");
	printf("\t\t\t******  5.չʾ         6.����   ******\n");
	printf("\t\t\t******  7.����         8.����   ******\n");
	printf("\t\t\t******  0.�˳�                  ******\n");
	printf("\t\t\t**************************************\n");
}
int main()
{
	//���غ���
	/*Loding();*/
	//��¼ϵͳ
	char pass[MAX_PD] = { "dongjiewo120" };
	int pl = login(&pass);
	Sleep(1000);
	system("cls");
	if (pl == 0)
	{
		return 0;
	};
	int input;
	int cap = 0;//��ǰ�����ڴ��ڵ���������
	Node sta;//������Ա��Ϣ����
	Node * p = InitStarnum(&sta);//��ͷ�ڵ㱣����p
	Node* ps = p;//��ͷָ�����p
	Node* add = p;//���ڴ洢Addstarnum������β���ڵ㷵��ֵ
	Node* px = NULL;//���Һ�������ֵ����
	ResetStarnum(ps, &cap);
	do {

		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			add = Addstarnum(add, &cap);
			break;
		case DEL:
			Delstarnum(ps, &cap);
			break;
		case SEARCH:
			SearchStarnum(ps);
			break;
		case MODIFY:
		    px = SearchStarnum(ps);
			ModifyStarnum(px);
			break;
		case SHOW:
			ShowStarnum(ps);
			break;
		case SORT:
			SortStarnum(ps,cap);
			break;
		case EXIT:
			Savestarnum(ps);//��������
			DestroyStarnum(ps);//��������
			printf("�˳�");
			break;
		case SAVE:
			Savestarnum(ps);
			break;
		case CHANGEPS:
			ChangePs(&pass);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}