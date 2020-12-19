#include <stdio.h>
/*

int scanf(const char *restrict format, 地址表...);

*/
#define STRSIZE 32
int main()
{	
	
	int i;
	float f;
	char ch, str[STRSIZE];
	int ret;

	
	printf("Please enter\n");

	scanf("%d", &i);

	scanf("%*c%c", &ch); 
//	ch = getchar();

	printf("i = %d, ch = %d\n", i, ch);

/*	
	while(1)
	{
		ret = scanf("%d", &i);
		if (ret != 1)
		{
			printf("Enter Error!\n");
			break;
		}
		printf("i = %d\n", i);
	}
*/
//	scanf("%s", str);	

//	printf("str = %s\n", str);
//	scanf("%d,%f", &i, &f);
//	printf("i = %d\n", i);
//	printf("f = %f\n", f);
	
	return 0;
}
