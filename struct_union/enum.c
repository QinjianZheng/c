#include <stdio.h>
#include <time.h>

enum week_day
{
	MON = 1,
	TUS,
	WES,
	THR,
	FRI,
	SAT,
	SUN
};

// 代替定义宏，搭配switch case使用
enum
{
	STATE_RUNNING = 1,
	STATE_CANCELED,
	STATE_OVER

};

struct job_st
{
	int id;
	int state;
	time_t start, end;
};

int main()
{

#if 0
	enum week_day a = FRI;

	printf("%d\n", a);	
#endif

	struct job_st job1;

// 获取任务状态	

	switch(job1.state)
	{
		case STATE_RUNNING:
				break;
		case STATE_CANCELED:
				break;
		case STATE_OVER:
				break;
		default:
				printf("Not Correct State!");
	}

	return 0;
}
