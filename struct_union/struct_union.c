#include <stdio.h>
#include <stdint.h>

struct sim_st
{
	int i;
	char ch;
	union
	{
		int a;
		char c;
	} un;
	float f;
};

union sim_un
{

	int a;
	double d;
	struct
	{
		int arr[10];
		float f;
	
	} s;
};

// union内存空间共用，struct内存空间顺序排列
// y占32位，i和j分别占用16位
// 因此：
// |		i		|		j		|
// |				y				|
//			16bits			16bits
//					32bits

union
{
	struct
	{
		uint16_t i;
		uint16_t j;
	
	} x;
	uint32_t y;
} a;


int main()
{
	struct sim_st s;
	union sim_un u;

	printf("sizeof(s) = %lu\n", sizeof(s));
	printf("sizeof(u) = %lu\n", sizeof(u));

// 高16位与低16位相加

// i >> 16 丢弃了最后的16位，将高16位移到低16位的位置
// i & 0xFFFF 0xFFFF高16位全为0，低16位全为1，按位与保留低16位，丢弃高16位
	unsigned int i = 0x11223344;

	printf("%x\n", (i >> 16) + i & 0xFFFF);

	a.y = 0x11223344;

	printf("%x\n", a.x.i + a.x.j);
	


	return 0;
}
