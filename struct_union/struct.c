#include <stdio.h>
#define NAMESIZE 32


// 定义一个简单结构体
struct simple_st
{
	int i; 
// char ch1; struct simple_st a -- sizeof(a) -- 16

	float f;
	char ch;
//	char ch1; struct simple_st a -- sizeof(a) -- 12

};//__attribute__((packed));




// 定义一个“生日”结构体
#if 0
struct birthday_st
{
	int year;
	int month;
	int day;
};
#endif

// 定义一个“学生”结构体
struct student_st
{
	int id;
//	struct birthday_st birth;
	// 嵌套定义
	struct birthday_st
	{
		int year;
		int month;
		int day;
	} birth_day;
	
//	int year, month, day;
	char name[NAMESIZE];
	int age;
};
// 临时创建了一个结构体（开销很大，占用内存空间）
// void print_size(struct simple_st b)
// 传递了指针，占用空间等于指针的大小 8个字节
void print_size(struct simple_st *b)
{
	printf("%lu\n", sizeof(b));	
}


int main()
{	
// 定义结构体变量
// TYPE NAME = VALUE;

	struct simple_st a = {123, 456.789f, 'a'};
	struct simple_st *q = &a;

	printf("sizeof(struct) = %lu\n", sizeof(a));
	printf("sizeof(pointer) = %lu\n", sizeof(q));	

//	print_size(a);
// print_size(a.i, a.f, a.ch);
	a.i = 112233;
	print_size(q);


	printf("%d %f %c\n", a.i, a.f, a.ch);

	struct student_st std ={10011, {2010,1,1}, "Alan", 18};
//	struct student_st std = {.age = 18, .name = "Alan"};
	struct student_st *p = &std;
	struct student_st arr[2] = {{10011, {2010,1,1}, "Alan", 18}, {10012, {2010,1,2}, "John", 20}};
	
	p = &arr[0];


#if 0
	printf("id = %d\n"
			"birthday = %d-%d-%d\n"
			"name = %s\n"
			"age = %d\n",
		   	std.id, std.birth_day.year, std.birth_day.month, std.birth_day.day, std.name, std.age);
	printf("id = %d\n"
            "birthday = %d-%d-%d\n"
            "name = %s\n"
            "age = %d\n",
            p->id, p->birth_day.year, p->birth_day.month, p->birth_day.day, p->name, p->age);

	for(int i = 0; i < 2; i++, p++) // p++ == p = p + 1 -- p指向结构体类型，p+1指向下一个结构体
	{
		printf("id = %d\n"
            "birthday = %d-%d-%d\n"
            "name = %s\n"
            "age = %d\n",
            p->id, p->birth_day.year, p->birth_day.month, p->birth_day.day, p->name, p->age);
	
	}
#endif


	return 0;
}
