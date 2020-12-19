#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "I Love China";
	char *p = str + 7;
	
	puts(str);
	// 从p位置开始到尾（\0）0位置
	puts(p);
// 操作的是字符数组，用"world"覆盖数组内的内容
	strcpy(str, "world");	

	puts(str);
	puts(p);

	char *str1 = "hello";
	printf("sizeof(str1) = %lu, strlen(str1) = %lu\n", sizeof(str1), strlen(str1));

// 不能直接写strcpy(str, "world"); -- 意思是用"world"覆盖"hello"这个字符串常量，因此报段错误

//	放弃指向"hello"，转而指向"world"
	str1 = "world";
	puts(str1);
	return 0;
}
