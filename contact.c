#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu(void)
{
	printf("*************ͨѶ¼*************\n");
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
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("�����Ϣ\n");
		printf("����������:>");
		scanf("%s", ps->data[ps->Size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->Size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->Size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->Size].tele);
		printf("������סַ:>");
		scanf("%s", ps->data[ps->Size].addr);
		printf("��ӳɹ�\n");
		(ps->Size)++;
	}
}

void show(const struct con* ps)
{
	if (ps->Size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("������Ҫɾ���˵�������>");
	scanf("%s", name);
	int ret = find_byname(ps,name);
	if (-1==ret)
		printf("Ҫɾ�����˲�����\n");
	else
	{
		int j = 0;
		for (j = ret; j < ps->Size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->Size--;
		printf("ɾ���ɹ�\n");
	}
}

void search(const struct con* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//�ҵ������±꣬û�ҵ�����-1
	int pos=find_byname(ps, name);
	if (-1 == pos)
		printf("δ��ѯ������\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("������Ҫ������Ϣ���˵�����:>");
	scanf("%s", name);
	//�ҵ������±꣬û�ҵ�����-1
	int pos = find_byname(ps, name);
	if (-1 == pos)
		printf("δ��ѯ������\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-4d\t%-5s\t%-15s\t%-20s\n"
			, ps->data[pos].name
			, ps->data[pos].age
			, ps->data[pos].sex
			, ps->data[pos].tele
			, ps->data[pos].addr);
		printf("��������ĺ������:>");
		scanf("%s", ps->data[pos].name);
		printf("��������ĺ������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("��������ĺ���Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("��������ĺ�ĵ绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("��������ĺ��סַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("���ĳɹ�\n");
	}
}

void sort(struct con* ps)
{
	//����
	int input = 0;
	do
	{
		printf("***********����***********\n");
		printf("[1]��������С����\n");
		printf("[2]�������С����\n");
		printf("[0]�˳�\n");
		printf("ѡ���������>");
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
			printf("ȡ������\n");
			break;
		default:
			printf("ѡ����Ч��������ѡ��\n");
			break;
		}
	} while (input);
}


void _sort(struct con* ps, int input)
{
	//�ж��Ǻ�������
	struct contact data;
	int age = 0;
	if (2 == input)//����
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
	else//����
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
	printf("�������\n");
	show(ps);
}