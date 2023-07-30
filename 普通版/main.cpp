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

//数据结构===================================================================================================

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

//第一模块===================================================================================================

void welcome_1() //欢迎界面1
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** 研究生 考勤系统 ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|             欢迎使用研究生考勤系统!             |\n");
    printf("\t\t\t\t|     请先登录您的账户，如没有账户，请先注册。    |\n");
    printf("\t\t\t\t|                     1.登录                      |\n");
    printf("\t\t\t\t|                     2.注册                      |\n");
    printf("\t\t\t\t|                     3.查看已有账户              |\n");
    printf("\t\t\t\t|                     4.从本地导入账户            |\n");
    printf("\t\t\t\t|                     5.退出                      |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

int Find_user(char key[]) //查找用户
{
	for (int i = 0; i < user_num; i++)
	{
		if (strcmp(key, user[i].account) == 0) return i;
	}

	return -1;
}

void write_to_txt() //保存用户信息
{
     FILE *fp;
     fp = fopen("user_information.txt", "a");

     for (int i = 0; i < user_num; i ++)
         fprintf(fp, "%s %s\n", user[i].account, user[i].password);

     fclose(fp);
}

void import_user() //本地导入
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

	printf("已导入！\n");
	system("pause");

}

void look_txt() //查看
{
	FILE * fp;
	fp = fopen("user_information.txt", "r");

	if (fp == NULL)
    {
    	printf("本地文件不存在，请先注册！\n");
    	system("pause");
    	return ;
	}

	printf("%-10s %-10s\n", "账户", "密码");
	
	
	while (!feof(fp))
	{
		char x[100], y[100];
		fscanf(fp, "%s %s", x, y);

		printf("%-10s %-10s\n", x, y);
	}

	system("pause");
}

void sign_in() //登录
{
	system("cls");

	printf("欢迎登录！友情提示：管理员账号名称为：Admin。\n");

	char acc[100], pas[100];
	printf("请输入您的账号：");
	scanf("%s", acc);
	printf("请输入您的密码：");
	scanf("%s", pas);

	int sta = Find_user(acc);

	if (sta == -1)
	{
		printf("您输入的账户不存在，请按1重试!\n");

		int opt;
		scanf("%d", opt);

		if (opt == 1) sign_in();
		else return;

	}

	if (strcmp(user[sta].password, pas) != 0)
	{
		printf("您输入的密码错误，请按1重试!\n");

		int opt;
		scanf("%d", &opt);

		if (opt == 1) sign_in();
		else return;

	}

	login_status = true;

	if (strcmp(user[sta].account, "Admin") == 0)
		admin_status = true;

    if (admin_status) printf("恭喜！您以管理员身份登录成功！\n");
    else printf("恭喜！您以普通身份登录成功！\n");

    system("pause");

}

void sign_up() //注册
{
	system("cls");

	printf("欢迎注册！友情提示：管理员账号名称为：Admin。\n");

	char acc[100], pas[100];
	printf("请输入您的账号：");
	scanf("%s", acc);

	if (Find_user(acc) != -1)
	{
		printf("该账号已存在，请重试！\n");
		system("pause");
		return ;
	}
	else
		strcpy(user[user_num].account, acc);

	printf("请输入您的密码：");
	scanf("%s", pas);

	strcpy(user[user_num].password, pas);

	user_num ++;

	write_to_txt();

	printf("注册成功！\n");

	return ;


}

//第二模块===================================================================================================

void welcome_2() //欢迎界面2
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** 研究生 考勤系统 ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|             欢迎使用研究生考勤系统!             |\n");
    printf("\t\t\t\t|                   1.学生管理                    |\n");
    printf("\t\t\t\t|                   2.课程管理                    |\n");
    printf("\t\t\t\t|                   3.考勤记录                    |\n");
    printf("\t\t\t\t|                   4.生成报表                    |\n");
    printf("\t\t\t\t|                   5.退出                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}


void welcome_3() //欢迎界面3
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** 研究生 考勤系统 ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              欢迎使用学生管理功能!              |\n");
    printf("\t\t\t\t|                   1.添加信息                    |\n");
    printf("\t\t\t\t|                   2.修改信息                    |\n");
    printf("\t\t\t\t|                   3.删除信息                    |\n");
    printf("\t\t\t\t|                   4.查看信息                    |\n");
    printf("\t\t\t\t|                   5.按学号排序                  |\n");
    printf("\t\t\t\t|                   6.打印信息                    |\n");
    printf("\t\t\t\t|                   7.退出                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

void welcome_4() //欢迎界面4
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** 研究生 考勤系统 ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              欢迎使用课程管理功能!              |\n");
    printf("\t\t\t\t|                   1.添加信息                    |\n");
    printf("\t\t\t\t|                   2.修改信息                    |\n");
    printf("\t\t\t\t|                   3.删除信息                    |\n");
    printf("\t\t\t\t|                   4.查看信息                    |\n");
    printf("\t\t\t\t|                   5.按课程名排序                |\n");
    printf("\t\t\t\t|                   6.打印信息                    |\n");
    printf("\t\t\t\t|                   7.退出                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

/****************************************/
//学生管理函数
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
	printf("请选择添加方式(输1手动添加，输2从本地导入):");
	scanf("%d", &op);

	if (op == 1)
	{
		printf("请输入学生的学号、姓名、班级：\n");
    	scanf("%s %s %s", stu[stu_num].id, stu[stu_num].name, stu[stu_num].cla);

    	stu_num ++;
	}
	else if (op == 2)
	{
		FILE *fp;
		fp = fopen("stu_information.txt", "r+");

		if (fp == NULL)
		{
			printf("读取失败，请重试！\n");
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
		printf("输入有误，请重试！\n");
		system("pasue");
		return ;
	}


	printf("添加成功！\n");
	system("pause");
}

void fix_1()
{
    char s1[100], s2[100], s3[100];
    printf("请输入要修改学生的学号、姓名、班级：\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_stu(s1);

    if (t == -1)
    {
        printf("此学生信息不存在，请重试！");
        return ;
    }

    strcpy(stu[t].name, s2);
    strcpy(stu[t].cla, s3);

	printf("修改成功！\n");

	system("pause");

}

void del_1()
{
    char s1[100], s2[100], s3[100];
    printf("请输入要删除的学生的学号、姓名、班级：\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_stu(s1);

    if (t == -1)
    {
        printf("此学生信息不存在，请重试！");
        return ;
    }

	struct Student tmp;

	for (int i = t; i < stu_num; ++i)
		stu[i] = stu[i+1];

	stu_num --;

	printf("删除成功！\n");
	system("pause");

}

void look_1()
{
	printf("%-10s %-10s %-10s\n", "学号", "姓名", "班级");

    for (int i = 0; i < stu_num; ++i)
    {
        printf("%-10s %-10s %-10s\n", stu[i].id, stu[i].name, stu[i].cla);
    }

    system("pause");

}

void sort_1()
{
	int op;
	printf("按学号排序，请输入1升序，2倒序：");
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

	printf("排序成功！\n");

	system("pause");

}

void print_1()
{
    FILE *fp;
    fp = fopen("stu_information", "w+");

    printf("%10s %10s %10s\n", "学号", "姓名", "班级");
    for (int i = 0; i < stu_num; ++i)
    {
        fprintf(fp, "%10s %10s %10s\n", stu[i].id,  stu[i].name,  stu[i].cla);
    }

	printf("打印成功！\n");

    system("pause");


}

/****************************************/
//课程管理函数
int Find_Course(char key[])
{
    for (int i = 0; i < course_num; ++i)
        if (strcmp(key, cor[i].name) == 0) return i;

    return -1;
}

void add_2()
{
	int op;
	printf("请选择添加方式(输1手动添加，输2从本地导入):");
	scanf("%d", &op);

	if (op == 1)
	{
		printf("请输入课程的名字、教师、时间：\n");
    	scanf("%s %s %s", cor[course_num].name, cor[course_num].teacher, cor[course_num].time);

    	course_num ++;
	}
	else if (op == 2)
	{
		FILE *fp;
		fp = fopen("cor_information.txt", "r+");

		if (fp == NULL)
		{
			printf("读取失败，请重试！\n");
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
		printf("输入有误，请重试！\n");
		system("pasue");
		return ;
	}

	printf("添加成功！\n");

	system("pause");
}

void fix_2()
{
    char s1[100], s2[100], s3[100];
    printf("请输入要修改的课程的名字、教师、时间：\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_Course(s1);

    if (t == -1)
    {
        printf("此课程信息不存在，请重试！");
        system("pause");
        return ;
    }

    strcpy(cor[t].teacher, s2);
    strcpy(cor[t].time, s3);

	printf("修改成功！\n");
	system("pause");

}

void del_2()
{
    char s1[100], s2[100], s3[100];
    printf("请输入要删除的课程的名字、教师、时间：\n");
    scanf("%s %s %s", s1, s2, s3);

    int t = Find_Course(s1);

    if (t == -1)
    {
        printf("此课程信息不存在，请重试！");
        system("pause");
        return ;
    }

	struct Course tmp;

	for (int i = t; i < course_num; ++i)
		cor[i] = cor[i+1];

	course_num --;

	printf("删除成功！\n");
	system("pause");


}

void look_2()
{
	printf("%-10s %-10s %-10s\n", "课程", "教师", "时间");
    for (int i = 0; i < course_num; ++i)
    {
        printf("%-10s %-10s %-10s\n", cor[i].name, cor[i].teacher, cor[i].time);
    }

    system("pause");

}

void sort_2()
{
	int op;
	printf("按课程名排序，输入1升序，2倒序：");
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

	printf("排序成功！\n");

	system("pause");

}

void print_2()
{
    FILE *fp;
    fp = fopen("cor_information", "r");

    printf("%10s %10s %10s\n", "姓名", "教师", "时间");
    for (int i = 0; i < course_num; i++)
    {
        fprintf(fp, "%10s %10s %10s", cor[i].name, cor[i].teacher, cor[i].time);
    }

	printf("打印成功！\n");

    system("pause");


}

/****************************************/

void student_manage() //学生相关
{
    while (1)
	{
		system("cls");
		welcome_3();

		printf("请输入对应的数字启动功能：");
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

void course_manage() //课程相关
{
    while (1)
	{
		system("cls");
		welcome_4();

		printf("请输入对应的数字启动功能：");
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

void welcome_5() //欢迎界面5
{
	printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|**************** 研究生 考勤系统 ****************|\n");
    printf("\t\t\t\t|-------------------------------------------------|\n");
    printf("\t\t\t\t|              欢迎使用出勤管理功能!              |\n");
    printf("\t\t\t\t|                  1.添加出勤记录                 |\n");
    printf("\t\t\t\t|                  2.插入出勤记录                 |\n");
    printf("\t\t\t\t|                  3.修改出勤记录                 |\n");
    printf("\t\t\t\t|                  4.查找出勤记录                 |\n");
    printf("\t\t\t\t|                  5.删除出勤记录                 |\n");
    printf("\t\t\t\t|                  6.查看出勤记录                 |\n");
    printf("\t\t\t\t|                  7.统计出勤记录                 |\n");
    printf("\t\t\t\t|                  8.按出勤状态排序               |\n");
    printf("\t\t\t\t|                  9.打印信息                     |\n");
    printf("\t\t\t\t|                  10.退出                        |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t|                                                 |\n");
    printf("\t\t\t\t---------------------------------------------------\n");
}

/***************************************************/

ListNode* Create(int n) //创建
{

	printf("请选择创建链表的方式(1为手动输入，2为从文件导入):");
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

			printf("请输入学生姓名：");
			scanf("%s", p->stu_name);
			printf("请输入课程名：");
			scanf("%s", p->corse_name);
			printf("请输入学生出勤情况(1已到2迟到3早退4缺勤)：");
			scanf("%s", p->status);

			end->next=p;
			end=p;
		}

		end->next=NULL; //链表的尾部next指向空

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
		    printf("文件打开失败！请重试。\n");
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

		end->next=NULL; //链表的尾部next指向空

		printf("导入成功！\n");

		return head;
	}
	else
	{
		printf("输入有误，请重试！\n");
		system("pause");
		return NULL;
	}

}

ListNode* Insert(ListNode* head, int x) //插入
{
	ListNode *dummy, *ins;
	dummy = (ListNode*)malloc(sizeof(ListNode));
	dummy -> next = head;

	ins = (ListNode*)malloc(sizeof(ListNode));

	printf("请输入您要插入的数据：");
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
	printf("输入你要修改的数据：");
	scanf("%s %s %s", s1, s2, s3);

	strcpy(p->stu_name, s1);
	strcpy(p->corse_name, s2);
	strcpy(p->status, s3);

}

bool Find(ListNode* head, char x[]) //查找某个名字的学生
{

	for (ListNode* p = head; p; p=p->next)
		if (strcmp(x, p->stu_name) == 0) return true;

	return false;
}

ListNode* Del(ListNode* head, int x) //删除
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
		printf("记录为空！\n");
		system("pause");
		return ;
	}

	printf("%-10s %-10s %-10s\n", "姓名", "课程", "考勤");
	for (ListNode* p = head; p; p=p->next)
		if (p != head)
			printf("%-10s %-10s %-10s\n", p->stu_name, p->corse_name, p->status);

	system("pause");
}

void Count(ListNode* head)  //
{
    int arrive_num=0, late_num=0, leave_early_num=0, absence_num=0;
    int cnt = 0;

    if (head == NULL) printf("记录为空！\n");

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

    printf("出勤人数：%d\n", arrive_num);
    printf("迟到人数：%d\n", late_num);
    printf("早退人数：%d\n", leave_early_num);
    printf("缺席人数：%d\n", absence_num);

	puts("");

    printf("出勤率：%.2lf\n", arrive_num*1.0/cnt);
    printf("迟到率：%.2lf\n", late_num*1.0/cnt);
    printf("早退率：%.2lf\n", leave_early_num*1.0/cnt);
    printf("缺席率：%.2lf\n", absence_num*1.0/cnt);

    system("pause");

}

void Sort(ListNode* head) //按出勤状态排序  ???
{
	int op;
	printf("按出勤状态排序，输入1升序，2降序：");
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
		printf("输入有误，请重试！");
		system("pause");
		return ;
	}

	printf("排序成功！\n");

	system("pause");

}

void Print(ListNode* head)
{
    FILE *fp;
    fp = fopen("check_information", "w+");

    //printf("%-10s %-10s\n", "姓名", "课程","考勤状态");

    ListNode *p;
    p = (ListNode*)malloc(sizeof(ListNode));

    for (p = head; p; p=p->next)
    {
        fprintf(fp, "%-10s %-10s %-10s\n", p->stu_name, p->corse_name, p->status);
    }

    printf("打印成功！\n");
    system("pause");

}

/***************************************************/

void print_rep(ListNode *head)
{
    if (head == NULL)
	{
		printf("记录为空！\n");
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

    printf("生成的报表如下：\n");

    printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", "学号", "姓名", "课程", "授课教师", "时间", "考勤状态");

    for (int j = 0; j < i; j++)
    {
        printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", rep[j].id, rep[j].stu_name, rep[j].corse_name, rep[j].teacher, rep[j].time, rep[j].status);
    }

    FILE *fp;
    fp = fopen("report.txt", "w+");

    fprintf(fp, "%-15s %-15s %-15s %-15s %-15s %-15s\n", "学号", "姓名", "课程", "授课教师", "时间", "考勤状态");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%-15s %-15s %-15s %-15s %-15s %-15s\n", rep[j].id, rep[j].stu_name, rep[j].corse_name, rep[j].teacher, rep[j].time, rep[j].status);
    }

    printf("已成功打印至本地！\n");
    system("pause");


}

/***************************************************/

void attendance() //出勤情况
{
	while (1)
	{
		system("cls");
		welcome_5();

		printf("请输入对应的数字启动功能：");
		int opt;
		scanf("%d", &opt);

		if (opt == 1) //添加
		{
			int n;
			printf("请输入出勤记录的数量：");

			scanf("%d", &n);

			inf_num = n;

			//创建链表
			head = Create(inf_num); //n为节点数

			system("pause");

		}

		if (opt == 2) //插入
		{
			int pos;
			printf("请输入一个下标，插入数据至此下标对应的节点之前或者插入至尾节点:");
			scanf("%d", &pos);
			if (pos > inf_num + 1)
			{
				printf("数据范围越界！\n");
				return ;
			}
			Insert(head, pos);

			inf_num ++;

			system("pause");
		}


		if (opt == 3) //修改
		{
			int pos;
			printf("请输入你要修改的数据的下标：\n");
			scanf("%d", &pos);
			Fix(head, pos);

			system("pause");
		}

		if (opt == 4) //查找
		{
			char key[100];
			printf("请输入您要查找的学生的姓名：\n");
			scanf("%s", key);

			if (Find(head, key))
				printf("已找到！\n");
			else
				printf("未找到！\n");

			system("pause");
		}

		if (opt == 5) //删除
		{
			int pos;
			printf("请输入一个下标，删除数据:");
			scanf("%d", &pos);

			if (pos > inf_num)
			{
				printf("数据范围越界！\n");
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


//主函数===================================================================================================

int main()
{
	system("title 研究生考勤系统"); 
	
	//第一模块：欢迎，注册，登录
	while (1)
	{
		system("cls");
		welcome_1();

		printf("请输入对应的数字启动功能：");
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

	//第二模块,管理学生、课程

    while (1)
	{
		system("cls");
		welcome_2();

		printf("请输入对应的数字启动功能：");
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
				printf("非管理员身份，无法查看与操作，请退出重试！\n");
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
