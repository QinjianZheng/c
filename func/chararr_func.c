#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{	
	char *ret = dest;
		
	if(dest != NULL && src != NULL)
		while((*dest++ = *src++) != '\0');

	return ret;

}	

char *my_strncpy(char *dest, const char *src, size_t n)
{
	int i;
	
	for(i = 0; i < n && (dest[i] = src[i]); i++)
		;
	
	for(; i < n; i++)
		dest[i] = '\0';

	return dest;

}


int main()
{
	char str1[] = "helloworld";
	char str2[128];
		
	int n = 5;

//	my_strcpy(str2, str1);

	puts(str2);

	my_strncpy(str2, str1, n);

	puts(str2);

	return 0;
}
