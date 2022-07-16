#include"NBAstar.h"
//加载系统
void Loding()
{
	printf("\n\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~欢迎进入NBA球星管理系统~~~~~~~~~~~~~~~~~~~~~\n");
	printf("加载中......\n");
	printf("=================================================================\r");
	for (int i = 0; i < 64; i++)
	{
		printf(">");
		int j = rand() % 200;
		Sleep(j);
	}
	printf("\n");
	system("cls");
}
//改密函数
void ChangePs(char* pass)
{
	char ps[MAX_PD] = { 0 };
	printf("请输入旧的密码:>(三次机会)");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%s", ps, MAX_PD);
		if (0 == strcmp(ps, pass))
		{
			printf("请输入新的密码:>\n");
			scanf_s("%s", pass, MAX_PD);
			printf("修改成功！\n");
				return;
		}
		else
		{
			printf("请重新输入\n");
		}
	}
	printf("修改失败\n");
	return;
}

//登录系统
int login(char *passnum)
{
	char password[MAX_PD] = { 0 };
	printf("******************欢迎使用NBA球星管理系统*****************\n");
	printf("请输入密码:>(三次机会输入)\n");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%s", password, MAX_PD);
		if (0 == strcmp(password, passnum))
		{
			printf("输入密码正确！\n");
			return 1;
		}
		else
		{
			printf("请重新输入！\n");
		}
	}
	return 0;
}
//初始化函数
Node* InitStarnum(Node* ps)
{
	LinkNode head;
	head = (LinkNode)malloc(sizeof(Node));//创建头节点
	if(head)
	{
		head->next = NULL;
		return head;
	}
	else
	{
		return NULL;
	}
}
//将文件中的数据导入链表
Node* ResetStarnum(Node* ps, int* cap)
{
	//int i = 3;
	//ps->next = NULL;
	Node* PN = ps;
	StNu tmp = { 0 };//创建临时球员类型
	FILE* pfread = fopen("Starnum.text", "r");
	if (pfread == NULL)
	{
		printf("ResetStarnum::%s\n", strerror(errno));
		return NULL;
	}
	//读取数据到链表
	Node* pNew = (LinkNode)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("Addcontact::%s\n", strerror(errno));
		return;
	}
	while(fread(&tmp, sizeof(StNu), 1, pfread))
	{
		//尾插插入
		    pNew = (LinkNode)malloc(sizeof(Node));
			if (pNew == NULL)
			{
				printf("ResetStarnum::%s\n", strerror(errno));
				return;
			}
			pNew->data = tmp;
			pNew->next = NULL;
			PN->next = pNew;
			PN = pNew;
			(*cap)++;
	}
	return PN;
	fclose(pfread);
}
//添加数据的函数
Node* Addstarnum(Node* ps, int* cap)
{
	Node* PN = ps;
	//首先创建节点
	Node *pNew = (LinkNode)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("Addcontact::%s\n", strerror(errno));
		return NULL;
	}
	else
	{
		//写入数据
		printf("输入姓名:>");
		scanf_s("%s", pNew->data.name, MAX_NAME);
		printf("输入年龄:>");
		scanf_s("%d", &(pNew->data.age));
		printf("输入身高:>");
		scanf_s("%d", &(pNew->data.hei));
		printf("输入体重:>");
		scanf_s("%d", &(pNew->data.wei));
		printf("输入生日:>");
		scanf_s("%s", pNew->data.bir, MAX_BIR);
		printf("输入球队:>");
		scanf_s("%s", pNew->data.team, MAX_TEAM);
		printf("输入成就:>");
		scanf_s("%s", pNew->data.achieve, MAX_ACH);
		//连接节点r
		PN->next = pNew;
		PN = PN->next;
		PN->next = NULL;
		(*cap)++;
	}
	system("cls");
	return PN;
}
//输出数据函数
void ShowStarnum(Node* ps)
{
	ps = ps->next;
	if (ps == NULL)
	{
		printf("系统中无球员！\n");	
		Sleep(100);
		system("cls");
		return;
	}
	printf("%-20s\t%-4s\t%-8s\t%-8s\t%-15s\t%-25s\t%-50s\n\n", "姓名", "年龄", "身高(cm)", "体重(kg)", "生日", "球队", "成就");
	while (ps!= NULL)
	{
		printf("%-20s\t%-4d\t%-8d\t%-8d\t%-15s\t%-25s\t%-50s\n\n", ps->data.name, ps->data.age, ps->data.hei
			, ps->data.wei, ps->data.bir, ps->data.team, ps->data.achieve);
		ps = ps->next;
	}
}
//删除数据函数
void Delstarnum(Node* ps, int* cap)
{
	Node* PN = ps;
	char sname[MAX_NAME] = { 0 };
	//先找到要删除的球员
	printf("请输入要删除的球员的名称:>");
	scanf_s("%s",sname,MAX_NAME);
	Node* l = PN->next;
	while (l != NULL)
	{
		if (0 == strcmp(l->data.name, sname))
		{
			PN->next = l->next;
			(*cap)--;
			printf("删除成功！\n");
			Sleep(1000);
			system("cls");
			return NULL;
		}
		PN = l;
		l = l->next;
	}
	free(l);//释放删除节点的内存空间
	 l = NULL;
	//然后进行删除
	 printf("删除失败，不存在该球员\n");
	 Sleep(500);
	 system("cls");
}
//将文件保存到文件
void Savestarnum(Node* ps)
{
	Node* PN = ps;
	Node* l;
	FILE* pfwrite = fopen("Starnum.text", "w");
	if (pfwrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	else
	{
		//写数据到Starnum.cn
		l = PN->next;
		while (l != NULL)
		{
			fwrite(&(l->data), sizeof(StNu), 1, pfwrite);
			//ps = l;
			l = l->next;
		}
		fclose(pfwrite);
		pfwrite = NULL;
	}
}
//销毁链表数据
void DestroyStarnum(Node * ps)
{
	Node* pf = ps->next;
	Node* pl = ps->next;
	while (pf != NULL)
	{
		pf = pf->next;
		free(pl);
		pl = pf;
	}
}
//链表内数据搜索函数
Node* SearchStarnum(Node* ps)
{
	char a;
	char name[MAX_NAME] = { 0 };//创建姓名变量存储用户输入的姓名字符串
	Node* p = ps->next;
	printf("请输入要查找/修改的球员姓名:>");
	scanf_s("%s", name,MAX_NAME);
	//遍历链表找出该节点
	while (p != NULL)
	{
		if (0 == strcmp(p->data.name, name))
		{ 
			//如果找到就打印出来
				printf("%-20s\t%-4s\t%-4s\t%-4s\t%-20s\t%-30s\t%-50s\n", "姓名", "年龄", "身高", "体重", "生日", "球队", "成就");
				printf("%-20s\t%-4d\t%-4d\t%-4d\t%-20s\t%-30s\t%-50s\n", p->data.name, p->data.age, p->data.hei
					, p->data.wei, p->data.bir, p->data.team, p->data.achieve);
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	printf("不存在该球员\n");
	//system("cls");
	return NULL;
}
//排序的菜单
void Modmenu()
{
	printf("选择要修改的数据:>");
	printf("**************************************\n");
	printf("******  1.姓名         2.年龄   ******\n");
	printf("******  3.身高         4.体重   ******\n");
	printf("******  5.生日         6.球队   ******\n");
	printf("******  7.成就         0.退出   ******\n");
	printf("**************************************\n");
}
//修改链表内信息
void ModifyStarnum(Node* ps)
{
	int input;
	Modmenu();//打印修改菜单
	do
	{
		printf("选择要修改的数据:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1://球员姓名
			printf("输入要修改后的信息:>");
			scanf_s("%s", ps->data.name, MAX_NAME);
			break;
		case 2://球员年龄
			printf("输入要修改后的信息:>");
			scanf_s("%d", &(ps->data.age));
			break;
		case 3://球员身高
			printf("输入要修改后的信息:>");
			scanf_s("%d", &(ps->data.hei));
			break;
		case 4://球员体重
			printf("输入要修改后的信息:>");
			scanf_s("%d", &(ps->data.wei));
			break;
		case 5://球员生日
			printf("输入要修改后的信息:>");
			scanf_s("%s", ps->data.bir, MAX_BIR);
			break;
		case 6://球员球队
			printf("输入要修改后的信息:>");
			scanf_s("%s", ps->data.team, MAX_TEAM);
			break;
		case 7://球员成就
			printf("输入要修改后的信息:>");
			scanf_s("%s", ps->data.achieve, MAX_ACH);
			break;
		default:
			printf("输入错误！");
			break;
		}
	} while (input);
}
//希尔排序整型排序年龄
void SelectSortage(Node* ps, int t)
{
	//创建三个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };//中间变量用于节点之间数据的交换
	while (p != NULL)//外层循环从第一个节点遍历到最后一个节点
	{
		q = p->next;
		while (q != NULL)//从外层指针p的下一个指针开始遍历，遍历到最后一个指针
		{
			if (p->data.age > q->data.age && t == 1)//t == 1，也就是进行升序排序
			{
				l = p->data;
				p->data = q->data;//与选择排序交换数据的原理相同
				q->data = l;
			}
			if (p->data.age < q->data.age && t == 0)//t == 0,也就是进行降序排序
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}
//选择排序整型身高
void SelectSorthei(Node* ps, int t)
{
	//创建三个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->data.hei > q->data.hei && t == 1)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			if (p->data.hei < q->data.hei && t == 0)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}//对生日的选择排序
//对生日进行排序
void SelectSortbir(Node* ps, int t)
{
	//创建2个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//与上部分整型相似只是将比较对象由整型换成字符串
			if (strcmp(p->data.bir,q->data.bir) > 0 && t == 1)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			if (strcmp(p->data.bir, q->data.bir) < 0 && t == 0)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}
//对体重的排序
void SelectSortwei(Node* ps, int t)
{
	//创建三个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->data.wei > q->data.wei && t == 1)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			if (p->data.wei < q->data.wei && t == 0)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}
//对姓名的排序
void SelectSortname(Node* ps, int t)
{
	//创建三个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//与上部分整型相似只是将比较对象由整型换成字符串
			if (strcmp(p->data.name, q->data.name) > 0 && t == 1)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			if (strcmp(p->data.name, q->data.name) < 0 && t == 0)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}
//对球队的排序
void SelectSortteam(Node* ps, int t)
{
	//创建三个指针变量
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//与上部分整型相似只是将比较对象由整型换成字符串
			if (strcmp(p->data.team, q->data.team) > 0 && t == 1)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			if (strcmp(p->data.team, q->data.team) < 0 && t == 0)
			{
				l = p->data;
				p->data = q->data;
				q->data = l;
			}
			q = q->next;
		}
		p = p->next;
	}
}
//对链表内数据进行排序
void SortStarnum(Node* ps,int cap)
{
	int input = 0;
	int t = 0;//升序降序判断变量
	//调用希尔排序
	//选择排序的项目
	printf("选择要排序的项目:>");
	scanf_s("%d", &input);
	switch (input)
	{
	case 0:
		break;
	case 1://球员姓名.字符串
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSortname(ps, t);
		break;
	case 2://球员年龄.整型
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSortage(ps, t);
		break;
	case 3://球员身高.整型
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSorthei(ps, t);
		break;
		break;
	case 4://球员体重.整型
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSortwei(ps, t);
		break;
	case 5://球员生日.字符串
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSortbir(ps, t);
		break;
	case 6://球员球队.字符串
		printf("升序打1，降序打0\n");
		scanf_s("%d", &t);
		SelectSortteam(ps, t);
		break;
	default:
		printf("输入错误！");
		break;
	}
	//在调用排序
}