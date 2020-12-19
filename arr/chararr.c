#include <stdio.h>
#include <string.h>
#define N		32
#define STRSIZE 3


int main()
{
	char str[] = {'a','b','c','d'};
	char str2[N] = "hello";
	char str3[N];
	int i;
//	gets(str3);
//	puts(str);



#if 0
	scanf("%s", str3);
	printf("%s\n%s\n%s\n", str, str2, str3);	

	for(i = 0; i < N; i++)
		printf("%c ", str2[i]);
	printf("\n");
#endif

// frequently used functions:
/*	strlen & sizeof
	strcpy & strncpy
	strcat & strncat
	strcmp & strncmp
*/
	printf("str is %s\n", str);
	printf("length of str is %lu\n", strlen(str));
	printf("size of str is %lu\n", sizeof(str));
	printf("str2 is %s\n", str2);
	printf("length of str2 is %lu\n", strlen(str2));
    printf("size of str2 is %lu\n", sizeof(str2));

	char dest[STRSIZE];

	printf("copy str2 to dest\n");
//	strcpy(dest, str2);
	strncpy(dest, str2, STRSIZE);	
	printf("dest is ");
	puts(dest);

	printf("\n");
//	strcat(str2, " ");
//	strcat(str2, " world!");
	
	char s2[] = " world!";

	strncat(str2, s2, sizeof(str2)- strlen(s2) - 1);
	strncat(str2, " world!", N);

	puts(str2);

	printf("\n");


	char str1[N] = "horld";

	char s1[N] = "e";
	char s3[N] = "o";

	printf("Compare 'hello' with 'holrd': %d\n", strcmp(str2, str1));
	printf("Compare 'e' with 'o': %d\n", strcmp(s1, s3));

	return 0;
}




