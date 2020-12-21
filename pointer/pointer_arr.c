#include <stdio.h>
#include <string.h>

int main()
{	
	char * arr[5] = {"Follow me","Basic","Great","Fortran","Computer"};
	int i,j,k;
	char * temp = NULL;
	
	for(i = 0; i < 5-1; i++)
	{
		k = i;
		for(j = i+1; j < 5; j++)
		{
			if(strcmp(arr[k],arr[j]) > 0)
				k = j;
		}	
		if(k != i)
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}

	for(i = 0; i < 5; i++)
	{
		puts(arr[i]);
	}
	
	return 0;
}
