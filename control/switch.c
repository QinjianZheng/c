#include <stdio.h>
#include <stdlib.h>


int main()

{
	int score;

	printf("Please enter:");
	scanf("%d", &score);

	if (score < 0 || score > 100)
	{
		fprintf(stderr, "EINVAL\n");
		exit(1);
	}	
	switch(score/10)
	{
		case 10:
		case 9:
			puts("A");
			break;
		case 8:
            puts("B");
			break;
        case 7:
            puts("C");
        case 6:
            puts("D");
			break;
//      case 5:
//		case 4:
//		case 3:
//      case 2:
//      case 1:
//      case 0:
//          puts("E");
//			break;

		default:
			puts("E");
			break;
	}

	return 0;
}
