#include <stdio.h>

static void base_convert(void)
{
	int num, base;
	int n[128];
	int i = 0;

	printf("Please enter the number you want to be converted: ");
	scanf("%d", &num);
	printf("Please enter the base: ");
	scanf("%d", &base);

	do
	{
		n[i] = num % base;
		num = num / base;
		i++;
	} while (num != 0);
// 在执行完最后一次的i++并跳出循环后，i指向的空间是数组的下一个地址
// 因此使用i--，得到数组的最后一个位置，并用i--逆序输出
	for(i -- ; i >= 0;  i -- )
	{
		if(n[i] >= 10)
			printf("%c", n[i] - 10 + 'A');
		else printf("%d", n[i]);
	}
	printf("\n"); 
}



int main()
{

	base_convert();

	return 0;
}
