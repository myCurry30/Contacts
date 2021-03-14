#ifndef __CONTACT_H_
#define __CONTACT_H_

#include <stdio.h>
#include <string.h>
#define MAX_DATA 1000
#define MAX_NAME 20
#define MAX_SEX	 5
#define MAX_TELE 12
#define MAX_ADDR 30

struct contact 
{
	char name[MAX_NAME];
	unsigned int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct con 
{
	struct contact data[MAX_DATA];
	int Size;
};

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


void menu(void);
void init_contact(struct con* ps); 
void add(struct con* ps);
void show(const struct con* ps);
void del(struct con* ps);
void search(const struct con* ps);
void modify(struct con* ps);
void sort(struct con* ps);
void _sort(struct con* ps, int input);
#endif