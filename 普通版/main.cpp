#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

void welcome_1();

typedef struct ListNode ListNode;

int user_num = 0;

bool login_status = false;
bool admin_status = false;

int stu_num = 0;
int course_num = 0;

int inf_num;

//���ݽṹ===================================================================================================

struct System
{
    char account[100];
    char password[100];
}user[101];

struct Student
{
    char id[100];
    char name[100];
    char cla[100];

}stu[101];

struct Course
{
    char name[100];
    char teacher[100];
    char time[100];

}cor[101];

struct ListNode
{
	char stu_name[100];
	char corse_name[100];
	char status[100];

	ListNode *next;

}*head;

struct Map
{
    char id[100];
	char stu_name[100];
	char corse_name[100];
	char teacher[100];
	char time[100];
	char status[100];
}rep[101];

//��һģ��===================================================================================================

void welcome_1() //��ӭ����1
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** �о��� ����ϵͳ ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|             ��ӭʹ���о�������ϵͳ!             |\n");
    printf("\t\t\t\t|     ���ȵ�¼�����˻�����û���˻�������ע�ᡣ    |\n");
    printf("\t\t\t\t|                     1.��¼                      |\n");
    printf("\t\t\t\t|                     2.ע��                      |\n");
    printf("\t\t\t\t|                     3.�鿴�����˻�              |\n");
    printf("\t\t\t\t|                     4.�ӱ��ص����˻�            |\n");
    printf("\t\t\t\t|                     5.�˳�                      |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

int Find_user(char key[]) //�����û�
{
	for (int i = 0; i < user_num; i++)
	{
		if (strcmp(key, user[i].account) == 0) return i;
	}

	return -1;
}

void write_to_txt() //�����û���Ϣ
{
     FILE *fp;
     fp = fopen("user_information.txt", "a");

     for (int i = 0; i < user_num; i ++)
         fprintf(fp, "%s %s\n", user[i].account, user[i].password);

     fclose(fp);
}

void import_user() //���ص���
{
	FILE *fp;
    fp = fopen("user_information.txt", "r");

    for (int i = 0; !feof(fp); i++)
    {
    	char x[100], y[100];
    	fscanf(fp, "%s %s", x, y);

    	strcpy(user[i].account, x);
		strcpy(user[i].password, y);

    	user_num ++;
	}

	printf("�ѵ��룡\n");
	system("pause");

}

void look_txt() //�鿴
{
	FILE * fp;
	fp = fopen("user_information.txt", "r");

	if (fp == NULL)
    {
    	printf("�����ļ������ڣ�����ע�ᣡ\n");
    	system("pause");
    	return ;
	}

	printf("%-10s %-10s\n", "�˻�", "����");
	
	
	while (!feof(fp))
	{
		char x[100], y[100];
		fscanf(fp, "%s %s", x, y);

		printf("%-10s %-10s\n", x, y);
	}

	system("pause");
}

void sign_in() //��¼
{
	system("cls");

	printf("��ӭ��¼��������ʾ������Ա�˺�����Ϊ��Admin��\n");

	char acc[100], pas[100];
	printf("�����������˺ţ�");
	scanf("%s", acc);
	printf("�������������룺");
	scanf("%s", pas);

	int sta = Find_user(acc);

	if (sta == -1)
	{
		printf("��������˻������ڣ��밴1����!\n");

		int opt;
		scanf("%d", opt);

		if (opt == 1) sign_in();
		else return;

	}

	if (strcmp(user[sta].password, pas) != 0)
	{
		printf("���������������밴1����!\n");

		int opt;
		scanf("%d", &opt);

		if (opt == 1) sign_in();
		else return;

	}

	login_status = true;

	if (strcmp(user[sta].account, "Admin") == 0)
		admin_status = true;

    if (admin_status) printf("��ϲ�����Թ���Ա��ݵ�¼�ɹ���\n");
    else printf("��ϲ��������ͨ��ݵ�¼�ɹ���\n");

    system("pause");

}

void sign_up() //ע��
{
	system("cls");

	printf("��ӭע�ᣡ������ʾ������Ա�˺�����Ϊ��Admin��\n");

	char acc[100], pas[100];
	printf("�����������˺ţ�");
	scanf("%s", acc);

	if (Find_user(acc) != -1)
	{
		printf("���˺��Ѵ��ڣ������ԣ�\n");
		system("pause");
		return ;
	}
	else
		strcpy(user[user_num].account, acc);

	printf("�������������룺");
	scanf("%s", pas);

	strcpy(user[user_num].password, pas);

	user_num ++;

	write_to_txt();

	printf("ע��ɹ���\n");

	return ;


}

//�ڶ�ģ��===================================================================================================

void welcome_2() //��ӭ����2
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** �о��� ����ϵͳ ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|             ��ӭʹ���о�������ϵͳ!             |\n");
    printf("\t\t\t\t|                   1.ѧ������                    |\n");
    printf("\t\t\t\t|                   2.�γ̹���                    |\n");
    printf("\t\t\t\t|                   3.���ڼ�¼                    |\n");
    printf("\t\t\t\t|                   4.���ɱ���                    |\n");
    printf("\t\t\t\t|                   5.�˳�                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}


void welcome_3() //��ӭ����3
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** �о��� ����ϵͳ ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              ��ӭʹ��ѧ��������!              |\n");
    printf("\t\t\t\t|                   1.�����Ϣ                    |\n");
    printf("\t\t\t\t|                   2.�޸���Ϣ                    |\n");
    printf("\t\t\t\t|                   3.ɾ����Ϣ                    |\n");
    printf("\t\t\t\t|                   4.�鿴��Ϣ                    |\n");
    printf("\t\t\t\t|                   5.��ѧ������                  |\n");
    printf("\t\t\t\t|                   6.��ӡ��Ϣ                    |\n");
    printf("\t\t\t\t|                   7.�˳�                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

void welcome_4() //��ӭ����4
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** �о��� ����ϵͳ ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              ��ӭʹ�ÿγ̹�����!              |\n");
    printf("\t\t\t\t|                   1.�����Ϣ                    |\n");
    printf("\t\t\t\t|                   2.�޸���Ϣ                    |\n");
    printf("\t\t\t\t|                   3.ɾ����Ϣ                    |\n");
    printf("\t\t\t\t|                   4.�鿴��Ϣ                    |\n");
    printf("\t\t\t\t|                   5.���γ�������                |\n");
    printf("\t\t\t\t|                   6.��ӡ��Ϣ                    |\n");
    printf("\t\t\t\t|                   7.�˳�                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

/****************************************/
//ѧ��������
int Find_stu(char key[])
{
    for (int i = 0; i < stu_num; ++i)
        if (strcmp(key, stu[i].id) == 0)
			return i;

    return -1;
}

void add_1()
{
	int op;
	printf("��ѡ����ӷ�ʽ(��1�ֶ���ӣ���2�ӱ��ص���):");
	scanf("%d", &op);

	if (op == 1)
	{
		printf("������ѧ����ѧ�š��������༶��\n");
    	scanf("%s %s %s", stu[stu_num].id, stu[stu_num].name, stu[stu_num].cla);

    	stu_num ++;
	}
	else if (op == 2)
	{
		FILE *fp;
		fp = fopen("stu_information.txt", "r+");

		if (fp == NULL)
		{
			printf("��ȡʧ�ܣ������ԣ�\n");
			system("pasue");
			return ;
		}

		for (int i = 0; !feof(fp); i++)
		{
			stu_num ++;
			//char x[100], y[100], z[100];
			fscanf(fp, "%s %s %s", stu[i].id, stu[i].name, stu[i].cla);
		}

		fclose(fp);
	}
	else
	{
		printf("�������������ԣ�\n");
		system("pasue");
		return ;
	}


	printf("��ӳɹ���\n");
	system("pause");
}

void fix_1()
{
    char s1[100], s2[100], s3[100];
    printf("������Ҫ�޸�ѧ����ѧ�š��������༶��\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_stu(s1);

    if (t == -1)
    {
        printf("��ѧ����Ϣ�����ڣ������ԣ�");
        return ;
    }

    strcpy(stu[t].name, s2);
    strcpy(stu[t].cla, s3);

	printf("�޸ĳɹ���\n");

	system("pause");

}

void del_1()
{
    char s1[100], s2[100], s3[100];
    printf("������Ҫɾ����ѧ����ѧ�š��������༶��\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_stu(s1);

    if (t == -1)
    {
        printf("��ѧ����Ϣ�����ڣ������ԣ�");
        return ;
    }

	struct Student tmp;

	for (int i = t; i < stu_num; ++i)
		stu[i] = stu[i+1];

	stu_num --;

	printf("ɾ���ɹ���\n");
	system("pause");

}

void look_1()
{
	printf("%-10s %-10s %-10s\n", "ѧ��", "����", "�༶");

    for (int i = 0; i < stu_num; ++i)
    {
        printf("%-10s %-10s %-10s\n", stu[i].id, stu[i].name, stu[i].cla);
    }

    system("pause");

}

void sort_1()
{
	int op;
	printf("��ѧ������������1����2����");
	scanf("%d", &op);

	if (op == 1)
	{
		/*for (int i = 0; i < stu_num; i++)
		{
			for (int j = i; j < stu_num; j++)
			{
				if (stu[i].id > stu[j].id)
				{
					Student tmp = stu[j];
					stu[j] = stu[i];
					stu[i] = tmp;
				}
			}
		}*/

		int i = 0;
	    for (i = 0; i < stu_num - 1; i++)
	    {
	        int min = i;
	        int j = 0;
	        for (j = i+1; j < stu_num; j++)
	        {
	            if (stu[j].id < stu[min].id)
	            {
	                min = j;
	            }
	        }
	        Student tmp = stu[i];
	        stu[i] = stu[min];
			stu[min] = tmp;
	    }
	}

	if (op == 2)
	{
		for (int i = 0; i < stu_num; i++)
		{
			for (int j = i; j < stu_num; j++)
			{
				if (stu[i].id < stu[j].id)
				{
					Student tmp = stu[j];
					stu[j] = stu[i];
					stu[i] = tmp;
				}
			}
		}
	}

	printf("����ɹ���\n");

	system("pause");

}

void print_1()
{
    FILE *fp;
    fp = fopen("stu_information", "w+");

    printf("%10s %10s %10s\n", "ѧ��", "����", "�༶");
    for (int i = 0; i < stu_num; ++i)
    {
        fprintf(fp, "%10s %10s %10s\n", stu[i].id,  stu[i].name,  stu[i].cla);
    }

	printf("��ӡ�ɹ���\n");

    system("pause");


}

/****************************************/
//�γ̹�����
int Find_Course(char key[])
{
    for (int i = 0; i < course_num; ++i)
        if (strcmp(key, cor[i].name) == 0) return i;

    return -1;
}

void add_2()
{
	int op;
	printf("��ѡ����ӷ�ʽ(��1�ֶ���ӣ���2�ӱ��ص���):");
	scanf("%d", &op);

	if (op == 1)
	{
		printf("������γ̵����֡���ʦ��ʱ�䣺\n");
    	scanf("%s %s %s", cor[course_num].name, cor[course_num].teacher, cor[course_num].time);

    	course_num ++;
	}
	else if (op == 2)
	{
		FILE *fp;
		fp = fopen("cor_information.txt", "r+");

		if (fp == NULL)
		{
			printf("��ȡʧ�ܣ������ԣ�\n");
			system("pasue");
			return ;
		}

		for (int i = 0; !feof(fp); i++)
		{
			course_num ++;
			//char x[100], y[100], z[100];
			fscanf(fp, "%s %s %s", cor[i].name, cor[i].teacher, cor[i].time);
		}

		fclose(fp);
	}
	else
	{
		printf("�������������ԣ�\n");
		system("pasue");
		return ;
	}

	printf("��ӳɹ���\n");

	system("pause");
}

void fix_2()
{
    char s1[100], s2[100], s3[100];
    printf("������Ҫ�޸ĵĿγ̵����֡���ʦ��ʱ�䣺\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_Course(s1);

    if (t == -1)
    {
        printf("�˿γ���Ϣ�����ڣ������ԣ�");
        system("pause");
        return ;
    }

    strcpy(cor[t].teacher, s2);
    strcpy(cor[t].time, s3);

	printf("�޸ĳɹ���\n");
	system("pause");

}

void del_2()
{
    char s1[100], s2[100], s3[100];
    printf("������Ҫɾ���Ŀγ̵����֡���ʦ��ʱ�䣺\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_Course(s1);

    if (t == -1)
    {
        printf("�˿γ���Ϣ�����ڣ������ԣ�");
        system("pause");
        return ;
    }

	struct Course tmp;

	for (int i = t; i < course_num; ++i)
		cor[i] = cor[i+1];

	course_num --;

	printf("ɾ���ɹ���\n");
	system("pause");


}

void look_2()
{
	printf("%-10s %-10s %-10s\n", "�γ�", "��ʦ", "ʱ��");
    for (int i = 0; i < course_num; ++i)
    {
        printf("%-10s %-10s %-10s\n", cor[i].name, cor[i].teacher, cor[i].time);
    }

    system("pause");

}

void sort_2()
{
	int op;
	printf("���γ�����������1����2����");
	scanf("%d", &op);

	if (op == 1)
	{
		for (int i = 0; i < course_num; i++)
		{
			for (int j = i; j < course_num; j++)
			{
				if (cor[i].name > cor[j].name)
				{
					Course tmp = cor[j];
					cor[j] = cor[i];
					cor[i] = tmp;
				}
			}
		}
	}

	if (op == 2)
	{
		for (int i = 0; i < course_num; i++)
		{
			for (int j = i; j < course_num; j++)
			{
				if (stu[i].name < stu[j].name)
				{
					Course tmp = cor[j];
					cor[j] = cor[i];
					cor[i] = tmp;
				}
			}
		}
	}

	printf("����ɹ���\n");

	system("pause");

}

void print_2()
{
    FILE *fp;
    fp = fopen("cor_information", "r");

    printf("%10s %10s %10s\n", "����", "��ʦ", "ʱ��");
    for (int i = 0; i < course_num; i++)
    {
        fprintf(fp, "%10s %10s %10s", cor[i].name, cor[i].teacher, cor[i].time);
    }

	printf("��ӡ�ɹ���\n");

    system("pause");


}

/****************************************/

void student_manage() //ѧ�����
{
    while (1)
	{
		system("cls");
		welcome_3();

		printf("�������Ӧ�������������ܣ�");
		int opt;
		scanf("%d", &opt);

		if (opt == 1) add_1();
		if (opt == 2) fix_1();
		if (opt == 3) del_1();
		if (opt == 4) look_1();
		if (opt == 5) sort_1();
		if (opt == 6) print_1();
		if (opt == 7) return ;
	}
}

void course_manage() //�γ����
{
    while (1)
	{
		system("cls");
		welcome_4();

		printf("�������Ӧ�������������ܣ�");
		int opt;
		scanf("%d", &opt);

		if (opt == 1) add_2();
		if (opt == 2) fix_2();
		if (opt == 3) del_2();
		if (opt == 4) look_2();
		if (opt == 5) sort_2();
		if (opt == 6) print_2();
		if (opt == 7) return ;
	}

}

//=====================================================================================================

void welcome_5() //��ӭ����5
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** �о��� ����ϵͳ ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              ��ӭʹ�ó��ڹ�����!              |\n");
    printf("\t\t\t\t|                  1.��ӳ��ڼ�¼                 |\n");
    printf("\t\t\t\t|                  2.������ڼ�¼                 |\n");
    printf("\t\t\t\t|                  3.�޸ĳ��ڼ�¼                 |\n");
    printf("\t\t\t\t|                  4.���ҳ��ڼ�¼                 |\n");
    printf("\t\t\t\t|                  5.ɾ�����ڼ�¼                 |\n");
    printf("\t\t\t\t|                  6.�鿴���ڼ�¼                 |\n");
    printf("\t\t\t\t|                  7.ͳ�Ƴ��ڼ�¼                 |\n");
    printf("\t\t\t\t|                  8.������״̬����               |\n");
    printf("\t\t\t\t|                  9.��ӡ��Ϣ                     |\n");
    printf("\t\t\t\t|                  10.�˳�                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

/***************************************************/

ListNode* Create(int n) //����
{

	printf("��ѡ�񴴽�����ķ�ʽ(1Ϊ�ֶ����룬2Ϊ���ļ�����):");
	int op;
	scanf("%d", &op);

	if (op == 1)
	{
		ListNode *head,*p,*end;
		head = (ListNode*)malloc(sizeof(ListNode)); /////
		end=head;

		for(int i=0; i<n; i++)
		{
			p = (ListNode*)malloc(sizeof(ListNode));

			printf("������ѧ��������");
			scanf("%s", p->stu_name);
			printf("������γ�����");
			scanf("%s", p->corse_name);
			printf("������ѧ���������(1�ѵ�2�ٵ�3����4ȱ��)��");
			scanf("%s", p->status);

			end->next=p;
			end=p;
		}

		end->next=NULL; //�����β��nextָ���

		return head;
	}
	else if (op == 2)
	{
		ListNode *head,*p,*end;
		head = (ListNode*)malloc(sizeof(ListNode));
		end=head;

		FILE *fp;
		fp = fopen("check_information.txt", "r+");

		if (fp == NULL)
		{
		    printf("�ļ���ʧ�ܣ������ԡ�\n");
		    system("pause");
		    return NULL;
		}

		for(int i=0; !feof(fp); i++)
		{
			p = (ListNode*)malloc(sizeof(ListNode));

			char x[100], y[100], z[100];
			fscanf(fp, "%s %s %s", x, y, z);

			strcpy(p->stu_name, x);
			strcpy(p->corse_name, y);
			strcpy(p->status, z);

			end->next=p;
			end=p;
		}

		end->next=NULL; //�����β��nextָ���

		printf("����ɹ���\n");

		return head;
	}
	else
	{
		printf("�������������ԣ�\n");
		system("pause");
		return NULL;
	}

}

ListNode* Insert(ListNode* head, int x) //����
{
	ListNode *dummy, *ins;
	dummy = (ListNode*)malloc(sizeof(ListNode));
	dummy -> next = head;

	ins = (ListNode*)malloc(sizeof(ListNode));

	printf("��������Ҫ��������ݣ�");
	scanf("%s %s %s", ins->stu_name, ins->corse_name, ins->status);

	ListNode* p = dummy;
	for (int i = 0; i < x; i++) p=p->next;

	ins -> next = p -> next;
	p -> next = ins;

}

void Fix(ListNode* head, int x)
{
	ListNode* p = head;
	for (int i = 0; i < x; i++) p=p->next;

	char s1[100], s2[100], s3[100];
	printf("������Ҫ�޸ĵ����ݣ�");
	scanf("%s %s %s", s1, s2, s3);

	strcpy(p->stu_name, s1);
	strcpy(p->corse_name, s2);
	strcpy(p->status, s3);

}

bool Find(ListNode* head, char x[]) //����ĳ�����ֵ�ѧ��
{

	for (ListNode* p = head; p; p=p->next)
		if (strcmp(x, p->stu_name) == 0) return true;

	return false;
}

ListNode* Del(ListNode* head, int x) //ɾ��
{

	ListNode *dummy;
	dummy = (ListNode*)malloc(sizeof(ListNode));
	dummy -> next = head;

	ListNode* p = dummy;
	for (int i = 0; i < x; i++) p=p->next;

	p -> next = p -> next -> next;

	return dummy -> next;

}

void Look(ListNode* head)
{
	if (head == NULL)
	{
		printf("��¼Ϊ�գ�\n");
		system("pause");
		return ;
	}

	printf("%-10s %-10s %-10s\n", "����", "�γ�", "����");
	for (ListNode* p = head; p; p=p->next)
		if (p != head)
			printf("%-10s %-10s %-10s\n", p->stu_name, p->corse_name, p->status);

	system("pause");
}

void Count(ListNode* head)  //
{
    int arrive_num=0, late_num=0, leave_early_num=0, absence_num=0;
    int cnt = 0;

    if (head == NULL) printf("��¼Ϊ�գ�\n");

	ListNode *p;
    p = (ListNode*)malloc(sizeof(ListNode));

    for (p = head; p; p = p -> next)
    {
    	if (p == head) continue;
    	
        if (strcmp(p->status, "1") == 0) arrive_num ++;
        if (strcmp(p->status, "2") == 0) late_num ++;
        if (strcmp(p->status, "3") == 0) leave_early_num ++;
        if (strcmp(p->status, "4") == 0) absence_num ++;
        
        cnt ++;
    }

    printf("����������%d\n", arrive_num);
    printf("�ٵ�������%d\n", late_num);
    printf("����������%d\n", leave_early_num);
    printf("ȱϯ������%d\n", absence_num);

	puts("");

    printf("�����ʣ�%.2lf\n", arrive_num*1.0/cnt);
    printf("�ٵ��ʣ�%.2lf\n", late_num*1.0/cnt);
    printf("�����ʣ�%.2lf\n", leave_early_num*1.0/cnt);
    printf("ȱϯ�ʣ�%.2lf\n", absence_num*1.0/cnt);

    system("pause");

}

void Sort(ListNode* head) //������״̬����  ???
{
	int op;
	printf("������״̬��������1����2����");
	scanf("%d", &op);

	if (op == 1)
	{
		ListNode *p, *q;
	    p = (ListNode*)malloc(sizeof(ListNode));
	    q = (ListNode*)malloc(sizeof(ListNode));

	    for (p = head; p; p=p->next)
	    {
	    	if (p == head) continue;
	        for (q = p -> next; q; q=q->next)
	        {
	            if (strcmp(p->status, q->status) > 0)
	            {
	                char tmp1[100], tmp2[100], tmp3[100];
	                strcpy(tmp1, p->stu_name);
	                strcpy(tmp2, p->corse_name);
	                strcpy(tmp3, p->status);

	                strcpy(p->stu_name, q->stu_name);
	                strcpy(p->corse_name, q->corse_name);
	                strcpy(p->status, q->status);

	                strcpy(q->stu_name, tmp1);
	                strcpy(q->corse_name, tmp2);
	                strcpy(q->status, tmp3);
	            }
	        }
	    }
	}
	else if (op == 2)
	{
		ListNode *p, *q;
	    p = (ListNode*)malloc(sizeof(ListNode));
	    q = (ListNode*)malloc(sizeof(ListNode));

	    for (p = head; p; p=p->next)
	    {
	        for (q = p -> next; q; q=q->next)
	        {
	            if (strcmp(p->status, q->status) < 0)
	            {
	                char tmp1[100], tmp2[100], tmp3[100];
	                strcpy(tmp1, p->stu_name);
	                strcpy(tmp2, p->corse_name);
	                strcpy(tmp3, p->status);

	                strcpy(p->stu_name, q->corse_name);
	                strcpy(p->stu_name, q->corse_name);
	                strcpy(p->status, q->status);

	                strcpy(q->stu_name, tmp1);
	                strcpy(q->corse_name, tmp2);
	                strcpy(q->status, tmp3);
	            }
	        }
	    }
	}
	else
	{
		printf("�������������ԣ�");
		system("pause");
		return ;
	}

	printf("����ɹ���\n");

	system("pause");

}

void Print(ListNode* head)
{
    FILE *fp;
    fp = fopen("check_information", "w+");

    //printf("%-10s %-10s\n", "����", "�γ�","����״̬");

    ListNode *p;
    p = (ListNode*)malloc(sizeof(ListNode));

    for (p = head; p; p=p->next)
    {
        fprintf(fp, "%-10s %-10s %-10s\n", p->stu_name, p->corse_name, p->status);
    }

    printf("��ӡ�ɹ���\n");
    system("pause");

}

/***************************************************/

void print_rep(ListNode *head)
{
    if (head == NULL)
	{
		printf("��¼Ϊ�գ�\n");
		system("pause");
		return ;
	}

	int i = 0;

	char k1[100], k2[100], k3[100];

	ListNode *p;
    p = (ListNode*)malloc(sizeof(ListNode));

    int pos1 = -1, pos2 = -1;

	for (p = head; p; p=p->next)
    {
        if (p == head) continue;

        strcpy(k1, p->stu_name);
        strcpy(k2, p->corse_name);
        strcpy(k3, p->status);

        strcpy(rep[i].stu_name, k1);
        strcpy(rep[i].corse_name, k2);
        strcpy(rep[i].status, k3);

        for (int j = 0; j < stu_num; j ++)
        {
            if (strcmp(k1, stu[j].name) == 0)
                pos1 = j;
        }

        strcpy(rep[i].id, stu[pos1].id);

        for (int j = 0; j < course_num; j ++)
        {
            if (strcmp(k2, cor[j].name) == 0)
                pos2 = j;
        }

        strcpy(rep[i].teacher, cor[pos2].teacher);
        strcpy(rep[i].time, cor[pos2].time);

        i ++;
    }

    printf("���ɵı������£�\n");

    printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", "ѧ��", "����", "�γ�", "�ڿν�ʦ", "ʱ��", "����״̬");

    for (int j = 0; j < i; j++)
    {
        printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", rep[j].id, rep[j].stu_name, rep[j].corse_name, rep[j].teacher, rep[j].time, rep[j].status);
    }

    FILE *fp;
    fp = fopen("report.txt", "w+");

    fprintf(fp, "%-15s %-15s %-15s %-15s %-15s %-15s\n", "ѧ��", "����", "�γ�", "�ڿν�ʦ", "ʱ��", "����״̬");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%-15s %-15s %-15s %-15s %-15s %-15s\n", rep[j].id, rep[j].stu_name, rep[j].corse_name, rep[j].teacher, rep[j].time, rep[j].status);
    }

    printf("�ѳɹ���ӡ�����أ�\n");
    system("pause");


}

/***************************************************/

void attendance() //�������
{
	while (1)
	{
		system("cls");
		welcome_5();

		printf("�������Ӧ�������������ܣ�");
		int opt;
		scanf("%d", &opt);

		if (opt == 1) //���
		{
			int n;
			printf("��������ڼ�¼��������");

			scanf("%d", &n);

			inf_num = n;

			//��������
			head = Create(inf_num); //nΪ�ڵ���

			system("pause");

		}

		if (opt == 2) //����
		{
			int pos;
			printf("������һ���±꣬�������������±��Ӧ�Ľڵ�֮ǰ���߲�����β�ڵ�:");
			scanf("%d", &pos);
			if (pos > inf_num + 1)
			{
				printf("���ݷ�ΧԽ�磡\n");
				return ;
			}
			Insert(head, pos);

			inf_num ++;

			system("pause");
		}


		if (opt == 3) //�޸�
		{
			int pos;
			printf("��������Ҫ�޸ĵ����ݵ��±꣺\n");
			scanf("%d", &pos);
			Fix(head, pos);

			system("pause");
		}

		if (opt == 4) //����
		{
			char key[100];
			printf("��������Ҫ���ҵ�ѧ����������\n");
			scanf("%s", key);

			if (Find(head, key))
				printf("���ҵ���\n");
			else
				printf("δ�ҵ���\n");

			system("pause");
		}

		if (opt == 5) //ɾ��
		{
			int pos;
			printf("������һ���±꣬ɾ������:");
			scanf("%d", &pos);

			if (pos > inf_num)
			{
				printf("���ݷ�ΧԽ�磡\n");
				return ;
			}

			head = Del(head, pos);

			inf_num --;

			system("pause");
		}

		if (opt == 6) Look(head);

		if (opt == 7) Count(head); //

		if (opt == 8) Sort(head);

		if (opt == 9) Print(head);

		if (opt == 10) return ;

	}


}


//������===================================================================================================

int main()
{
	system("title �о�������ϵͳ"); 
	
	//��һģ�飺��ӭ��ע�ᣬ��¼
	while (1)
	{
		system("cls");
		welcome_1();

		printf("�������Ӧ�������������ܣ�");
		int opt;
		scanf("%d", &opt);

		if (opt == 1)
			sign_in();
		if (opt == 2)
			sign_up();
		if (opt == 3)
			look_txt();
		if (opt == 4)
			import_user();
		if (opt == 5)
			return 0;

		if (login_status) break;
	}

	//�ڶ�ģ��,����ѧ�����γ�

    while (1)
	{
		system("cls");
		welcome_2();

		printf("�������Ӧ�������������ܣ�");
		int opt;
		scanf("%d", &opt);

		if (opt == 1)
			student_manage();
		if (opt == 2)
			course_manage();

		if (opt == 3)
		{
			if (!admin_status)
			{
				printf("�ǹ���Ա��ݣ��޷��鿴����������˳����ԣ�\n");
				system("pause");
				return 0;
			}
			else
				attendance();
		}

		if (opt == 4)
            print_rep(head);

        if (opt == 5)
			return 0;

	}

    return 0;
}
