#include"NBAstar.h"
//����ϵͳ
void Loding()
{
	printf("\n\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~��ӭ����NBA���ǹ���ϵͳ~~~~~~~~~~~~~~~~~~~~~\n");
	printf("������......\n");
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
//���ܺ���
void ChangePs(char* pass)
{
	char ps[MAX_PD] = { 0 };
	printf("������ɵ�����:>(���λ���)");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%s", ps, MAX_PD);
		if (0 == strcmp(ps, pass))
		{
			printf("�������µ�����:>\n");
			scanf_s("%s", pass, MAX_PD);
			printf("�޸ĳɹ���\n");
				return;
		}
		else
		{
			printf("����������\n");
		}
	}
	printf("�޸�ʧ��\n");
	return;
}

//��¼ϵͳ
int login(char *passnum)
{
	char password[MAX_PD] = { 0 };
	printf("******************��ӭʹ��NBA���ǹ���ϵͳ*****************\n");
	printf("����������:>(���λ�������)\n");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%s", password, MAX_PD);
		if (0 == strcmp(password, passnum))
		{
			printf("����������ȷ��\n");
			return 1;
		}
		else
		{
			printf("���������룡\n");
		}
	}
	return 0;
}
//��ʼ������
Node* InitStarnum(Node* ps)
{
	LinkNode head;
	head = (LinkNode)malloc(sizeof(Node));//����ͷ�ڵ�
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
//���ļ��е����ݵ�������
Node* ResetStarnum(Node* ps, int* cap)
{
	//int i = 3;
	//ps->next = NULL;
	Node* PN = ps;
	StNu tmp = { 0 };//������ʱ��Ա����
	FILE* pfread = fopen("Starnum.text", "r");
	if (pfread == NULL)
	{
		printf("ResetStarnum::%s\n", strerror(errno));
		return NULL;
	}
	//��ȡ���ݵ�����
	Node* pNew = (LinkNode)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("Addcontact::%s\n", strerror(errno));
		return;
	}
	while(fread(&tmp, sizeof(StNu), 1, pfread))
	{
		//β�����
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
//������ݵĺ���
Node* Addstarnum(Node* ps, int* cap)
{
	Node* PN = ps;
	//���ȴ����ڵ�
	Node *pNew = (LinkNode)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("Addcontact::%s\n", strerror(errno));
		return NULL;
	}
	else
	{
		//д������
		printf("��������:>");
		scanf_s("%s", pNew->data.name, MAX_NAME);
		printf("��������:>");
		scanf_s("%d", &(pNew->data.age));
		printf("�������:>");
		scanf_s("%d", &(pNew->data.hei));
		printf("��������:>");
		scanf_s("%d", &(pNew->data.wei));
		printf("��������:>");
		scanf_s("%s", pNew->data.bir, MAX_BIR);
		printf("�������:>");
		scanf_s("%s", pNew->data.team, MAX_TEAM);
		printf("����ɾ�:>");
		scanf_s("%s", pNew->data.achieve, MAX_ACH);
		//���ӽڵ�r
		PN->next = pNew;
		PN = PN->next;
		PN->next = NULL;
		(*cap)++;
	}
	system("cls");
	return PN;
}
//������ݺ���
void ShowStarnum(Node* ps)
{
	ps = ps->next;
	if (ps == NULL)
	{
		printf("ϵͳ������Ա��\n");	
		Sleep(100);
		system("cls");
		return;
	}
	printf("%-20s\t%-4s\t%-8s\t%-8s\t%-15s\t%-25s\t%-50s\n\n", "����", "����", "���(cm)", "����(kg)", "����", "���", "�ɾ�");
	while (ps!= NULL)
	{
		printf("%-20s\t%-4d\t%-8d\t%-8d\t%-15s\t%-25s\t%-50s\n\n", ps->data.name, ps->data.age, ps->data.hei
			, ps->data.wei, ps->data.bir, ps->data.team, ps->data.achieve);
		ps = ps->next;
	}
}
//ɾ�����ݺ���
void Delstarnum(Node* ps, int* cap)
{
	Node* PN = ps;
	char sname[MAX_NAME] = { 0 };
	//���ҵ�Ҫɾ������Ա
	printf("������Ҫɾ������Ա������:>");
	scanf_s("%s",sname,MAX_NAME);
	Node* l = PN->next;
	while (l != NULL)
	{
		if (0 == strcmp(l->data.name, sname))
		{
			PN->next = l->next;
			(*cap)--;
			printf("ɾ���ɹ���\n");
			Sleep(1000);
			system("cls");
			return NULL;
		}
		PN = l;
		l = l->next;
	}
	free(l);//�ͷ�ɾ���ڵ���ڴ�ռ�
	 l = NULL;
	//Ȼ�����ɾ��
	 printf("ɾ��ʧ�ܣ������ڸ���Ա\n");
	 Sleep(500);
	 system("cls");
}
//���ļ����浽�ļ�
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
		//д���ݵ�Starnum.cn
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
//������������
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
//������������������
Node* SearchStarnum(Node* ps)
{
	char a;
	char name[MAX_NAME] = { 0 };//�������������洢�û�����������ַ���
	Node* p = ps->next;
	printf("������Ҫ����/�޸ĵ���Ա����:>");
	scanf_s("%s", name,MAX_NAME);
	//���������ҳ��ýڵ�
	while (p != NULL)
	{
		if (0 == strcmp(p->data.name, name))
		{ 
			//����ҵ��ʹ�ӡ����
				printf("%-20s\t%-4s\t%-4s\t%-4s\t%-20s\t%-30s\t%-50s\n", "����", "����", "���", "����", "����", "���", "�ɾ�");
				printf("%-20s\t%-4d\t%-4d\t%-4d\t%-20s\t%-30s\t%-50s\n", p->data.name, p->data.age, p->data.hei
					, p->data.wei, p->data.bir, p->data.team, p->data.achieve);
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	printf("�����ڸ���Ա\n");
	//system("cls");
	return NULL;
}
//����Ĳ˵�
void Modmenu()
{
	printf("ѡ��Ҫ�޸ĵ�����:>");
	printf("**************************************\n");
	printf("******  1.����         2.����   ******\n");
	printf("******  3.���         4.����   ******\n");
	printf("******  5.����         6.���   ******\n");
	printf("******  7.�ɾ�         0.�˳�   ******\n");
	printf("**************************************\n");
}
//�޸���������Ϣ
void ModifyStarnum(Node* ps)
{
	int input;
	Modmenu();//��ӡ�޸Ĳ˵�
	do
	{
		printf("ѡ��Ҫ�޸ĵ�����:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1://��Ա����
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%s", ps->data.name, MAX_NAME);
			break;
		case 2://��Ա����
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%d", &(ps->data.age));
			break;
		case 3://��Ա���
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%d", &(ps->data.hei));
			break;
		case 4://��Ա����
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%d", &(ps->data.wei));
			break;
		case 5://��Ա����
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%s", ps->data.bir, MAX_BIR);
			break;
		case 6://��Ա���
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%s", ps->data.team, MAX_TEAM);
			break;
		case 7://��Ա�ɾ�
			printf("����Ҫ�޸ĺ����Ϣ:>");
			scanf_s("%s", ps->data.achieve, MAX_ACH);
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);
}
//ϣ������������������
void SelectSortage(Node* ps, int t)
{
	//��������ָ�����
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };//�м�������ڽڵ�֮�����ݵĽ���
	while (p != NULL)//���ѭ���ӵ�һ���ڵ���������һ���ڵ�
	{
		q = p->next;
		while (q != NULL)//�����ָ��p����һ��ָ�뿪ʼ���������������һ��ָ��
		{
			if (p->data.age > q->data.age && t == 1)//t == 1��Ҳ���ǽ�����������
			{
				l = p->data;
				p->data = q->data;//��ѡ�����򽻻����ݵ�ԭ����ͬ
				q->data = l;
			}
			if (p->data.age < q->data.age && t == 0)//t == 0,Ҳ���ǽ��н�������
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
//ѡ�������������
void SelectSorthei(Node* ps, int t)
{
	//��������ָ�����
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
}//�����յ�ѡ������
//�����ս�������
void SelectSortbir(Node* ps, int t)
{
	//����2��ָ�����
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//���ϲ�����������ֻ�ǽ��Ƚ϶��������ͻ����ַ���
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
//�����ص�����
void SelectSortwei(Node* ps, int t)
{
	//��������ָ�����
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
//������������
void SelectSortname(Node* ps, int t)
{
	//��������ָ�����
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//���ϲ�����������ֻ�ǽ��Ƚ϶��������ͻ����ַ���
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
//����ӵ�����
void SelectSortteam(Node* ps, int t)
{
	//��������ָ�����
	Node* p = ps->next;
	Node* q = ps->next;
	StNu l = { 0 };
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			//���ϲ�����������ֻ�ǽ��Ƚ϶��������ͻ����ַ���
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
//�����������ݽ�������
void SortStarnum(Node* ps,int cap)
{
	int input = 0;
	int t = 0;//�������жϱ���
	//����ϣ������
	//ѡ���������Ŀ
	printf("ѡ��Ҫ�������Ŀ:>");
	scanf_s("%d", &input);
	switch (input)
	{
	case 0:
		break;
	case 1://��Ա����.�ַ���
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSortname(ps, t);
		break;
	case 2://��Ա����.����
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSortage(ps, t);
		break;
	case 3://��Ա���.����
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSorthei(ps, t);
		break;
		break;
	case 4://��Ա����.����
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSortwei(ps, t);
		break;
	case 5://��Ա����.�ַ���
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSortbir(ps, t);
		break;
	case 6://��Ա���.�ַ���
		printf("�����1�������0\n");
		scanf_s("%d", &t);
		SelectSortteam(ps, t);
		break;
	default:
		printf("�������");
		break;
	}
	//�ڵ�������
}