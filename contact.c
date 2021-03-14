#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu(void)
{
	printf("*************通讯录*************\n");
	printf("****[1]ADD          [2]DEL*****\n");
	printf("****[3]SEARCH       [4]MODIFY**\n");
	printf("****[5]SHOW         [6]SORT****\n");
	printf("****[0]EXIT         ***********\n");
}

void init_contact(struct con* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->Size = 0;
}

void add(struct con* ps)
{
	if (ps->Size == MAX_DATA)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("添加信息\n");
		printf("请输入姓名:>");
		scanf("%s", ps->data[ps->Size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->Size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->Size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->Size].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[ps->Size].addr);
		printf("添加成功\n");
		(ps->Size)++;
	}
}

void show(const struct con* ps)
{
	if (ps->Size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		for (i = 0; i < ps->Size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-15s\t%-20s\n"
				, ps->data[i].name
				, ps->data[i].age
				, ps->data[i].sex
				, ps->data[i].tele
				, ps->data[i].addr);
		}
	}
}

static int find_byname(const struct con* ps, char name[MAX_NAME])
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < ps->Size; i++)
	{
		ret = strcmp(ps->data[i].name, name);
		if (ret == 0)
		{
			return i;
		}	
	}
	return -1;
}

void del(struct con* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的姓名：>");
	scanf("%s", name);
	int ret = find_byname(ps,name);
	if (-1==ret)
		printf("要删除的人不存在\n");
	else
	{
		int j = 0;
		for (j = ret; j < ps->Size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->Size--;
		printf("删除成功\n");
	}
}

void search(const struct con* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的姓名:>");
	scanf("%s", name);
	//找到返回下标，没找到返回-1
	int pos=find_byname(ps, name);
	if (-1 == pos)
		printf("未查询到此人\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-15s\t%-20s\n"
			, ps->data[pos].name
			, ps->data[pos].age
			, ps->data[pos].sex
			, ps->data[pos].tele
			, ps->data[pos].addr);
	}
}

void modify(struct con* ps)
{
	char name[MAX_NAME];
	printf("请输入要更改信息的人的姓名:>");
	scanf("%s", name);
	//找到返回下标，没找到返回-1
	int pos = find_byname(ps, name);
	if (-1 == pos)
		printf("未查询到此人\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-15s\t%-20s\n"
			, ps->data[pos].name
			, ps->data[pos].age
			, ps->data[pos].sex
			, ps->data[pos].tele
			, ps->data[pos].addr);
		printf("请输入更改后的姓名:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入更改后的年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入更改后的性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入更改后的电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入更改后的住址:>");
		scanf("%s", ps->data[pos].addr);
		printf("更改成功\n");
	}
}

void sort(struct con* ps)
{
	//排序
	int input = 0;
	do
	{
		printf("***********排序***********\n");
		printf("[1]按姓名从小到大\n");
		printf("[2]按年龄从小到大\n");
		printf("[0]退出\n");
		printf("选择何种排序：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			_sort(ps,input);
			input = 0;
			break;
		case 2:
			_sort(ps, input);
			input = 0;
			break;
		case 0:
			printf("取消排序\n");
			break;
		default:
			printf("选择无效，请重新选择\n");
			break;
		}
	} while (input);
}


void _sort(struct con* ps, int input)
{
	//判断是何种排序
	struct contact data;
	int age = 0;
	if (2 == input)//年龄
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < ps->Size-1; i++)
		{
			for (j = 0; j < ps->Size - i - 1; j++)
			{
				if (((ps->data[j].age)-(ps->data[j + 1].age)) > 0)
				{
					data = ps->data[j];
					ps->data[j] = ps->data[j + 1];
					ps->data[j + 1] = data;
				}
			}
		}
	}
	else//姓名
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < ps->Size - 1; i++)
		{
			for (j = 0; j < ps->Size - i - 1; j++)
			{
				if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)
				{
					data = ps->data[j];
					ps->data[j] = ps->data[j + 1];
					ps->data[j + 1] = data;
				}
			}
		}
	}
	printf("排序完成\n");
	show(ps);
}