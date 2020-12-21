#include <stdio.h>


union test_un
{
	int i;
	float f;
//	double d;
	char ch;
};

int main()
{
	union test_un a;
	union test_un *p = &a;
	union test_un arr[3];

	a.f = 345.678f;

	printf("sizeof(a) = %lu\n", sizeof(a));

	printf("%f\n", a.f);

//	printf("%d\n", a.i);

//	func(&a); // func(p);

	return 0;
}
