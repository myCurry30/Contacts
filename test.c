#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


int main()
{
	int input = 0;
	struct con con;
	//初始化通讯录;
	init_contact(&con);
	do
	{
		menu();
		printf("请输入:>");
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
			printf("退出\n");
			break;
		default:
			printf("输入无效，请重新输入\n");
			break;
		}
	} while (input);
}