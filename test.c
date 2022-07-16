#include"NBAstar.h"
void menu()
{
	printf("\t\t\t********   NBA球星管理系统    ********\n");
	printf("\t\t\t**************************************\n");
	printf("\t\t\t******  1.添加         2.删除   ******\n");
	printf("\t\t\t******  3.搜索         4.修改   ******\n");
	printf("\t\t\t******  5.展示         6.排序   ******\n");
	printf("\t\t\t******  7.保存         8.改密   ******\n");
	printf("\t\t\t******  0.退出                  ******\n");
	printf("\t\t\t**************************************\n");
}
int main()
{
	//加载函数
	/*Loding();*/
	//登录系统
	char pass[MAX_PD] = { "dongjiewo120" };
	int pl = login(&pass);
	Sleep(1000);
	system("cls");
	if (pl == 0)
	{
		return 0;
	};
	int input;
	int cap = 0;//当前链表内存在的数据数量
	Node sta;//创建球员信息类型
	Node * p = InitStarnum(&sta);//将头节点保存在p
	Node* ps = p;//将头指针存在p
	Node* add = p;//用于存储Addstarnum函数的尾部节点返回值
	Node* px = NULL;//查找函数返回值变量
	ResetStarnum(ps, &cap);
	do {

		menu();
		printf("请选择:>");
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
			Savestarnum(ps);//保存数据
			DestroyStarnum(ps);//销毁链表
			printf("退出");
			break;
		case SAVE:
			Savestarnum(ps);
			break;
		case CHANGEPS:
			ChangePs(&pass);
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
	return 0;
}