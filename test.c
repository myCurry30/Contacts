#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


int main()
{
	int input = 0;
	struct con con;
	//��ʼ��ͨѶ¼;
	init_contact(&con);
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(&con);
			break;
		case DEL:
			del(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case SORT:
			sort(&con);
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("������Ч������������\n");
			break;
		}
	} while (input);
}