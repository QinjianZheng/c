#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define NAMESIZE 32

struct student_st
{
	int id;
	char name[NAMESIZE];
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
	*p = *q;
}


void std_set_id(struct student_st *p, const int new_id)
{
	p->id = new_id;
}

void std_set_name(struct student_st *p, const char * new_name)
{
    strncpy(p->name, new_name, NAMESIZE);
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
