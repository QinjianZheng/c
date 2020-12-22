#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NAMESIZE 32

struct student_st
{
	int id;
//	char name[NAMESIZE];

// 重构代码，使用动态内存管理
	char *name;
	int math;
	int chinese;	

};

void std_set(struct student_st *p)
{
//	p->id = 10011;
	strncpy(p->name, "Alan", NAMESIZE);
	p->math = 90;
	p->chinese = 98;
}

void menu(void)
{
	printf("Please enter the command:");

	printf("\n1 set info\n2 set id\n3 set name\n4 show info\nq quit\n");
}


void std_set_info(struct student_st *p, const struct student_st *q)
{
	// *p = *q;
	p->id = q->id;
	p->name = malloc(strlen(q->name)+1);
	if(p->name == NULL)
		exit(1);
// 已经分配内存空间，不需要使用strncpy
	// strncpy(p->name, q->name, NAMESIZE);
	strcpy(p->name, q->name);
	p->math = q->math;
	p->chinese = q->chinese;
}


void std_set_id(struct student_st *p, const int new_id)
{
	p->id = new_id;
}

void std_set_name(struct student_st *p, const char * new_name)
{
	free(p->name);
	p->name = malloc(strlen(new_name)+1);
    // strncpy(p->name, new_name, NAMESIZE);
	strcpy(p->name, new_name);

}

void std_show(struct student_st *p)
{
	printf("%d %s %d %d\n", p->id, p->name, p->math, p->chinese);

}

int main()
{
	struct student_st std, temp;
	char new_name[NAMESIZE];
	int choice;
	int new_id;
	int ret;
	do
	{
		menu();
		ret = scanf("%d", &choice);
		if(ret != 1)
			break;

		switch(choice)
		{
			case 1:	
				temp.name = malloc(NAMESIZE);
				printf("Please enter info for the student[id name math chinese]:\n");
				scanf("%d%s%d%d", &temp.id, temp.name, &temp.math, &temp.chinese);
				std_set_info(&std, &temp);
				break;
			case 2:
				printf("Please set the new id:\n");
				scanf("%d", &new_id);
				std_set_id(&std, new_id);
				break;
			case 3:
				printf("Please set the new name:\n");
				scanf("%s", new_name); 
				std_set_name(&std, new_name);
				break;
			case 4:
				std_show(&std);
				break;
			default:
				printf("Command not found!\n");
				break;
		}
		sleep(1);
	} while(1);
	return 0;
}
