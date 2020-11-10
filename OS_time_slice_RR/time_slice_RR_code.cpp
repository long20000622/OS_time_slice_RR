/*----------------------------------------------------*/
//此程序为模拟时间片轮转调度法的程序
//姓名：彭龙
//学号：E01814162
/*----------------------------------------------------*/
#include <string>
#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

#define OK 1
#define PERROR -1
#define EMPTY 0

int curtime = 0;//全局变量，模拟处理机当前的时间
int emptytime = 0;//处理机每遇到一次就绪队列空的情况就加一，如果此数字超过10就终止循环退出程序

typedef int status;
typedef struct pcb
{
	string ProName;
	int runtime;//进程运行完成总共所需时间
	int cometime;//进程到达的时间
	char state;//进程的状态，R为就绪，F为完成
	int leftruntime;//进程完成还需时间
	struct pcb *next;//指向下一个进程节点的指针
}PCB, *PCBptr;

typedef struct ReadyQueue
{
	PCBptr head;//队首指针
	PCBptr tail;//队尾指针
}ReadyQ;


//就绪队列的初始化函数，初始队列为空时队首指针和对位指针指向一个不保存进程信息的无效节点。
status InitReadyQ(ReadyQ *rq)
{
	PCB *t = new pcb;
	if (t == NULL)
	{
		cout << "错误！" << endl;
		return ERROR;
	}
	rq->head = t;
	rq->tail = t;
	t->next = NULL;
	return OK;
}

//冒泡排序，排序的key是到达时间。参数分别是保存进程的结构体数组和进程数
//数组排序后由小到大
void sort_pcb(PCBptr tmparr,int num)
{
	int i, j;
	PCB tmp;
	for (i = 0; i < num-1; i++)
		for (j = i; j < num; j++)
			if (tmparr[i].cometime > tmparr[j].cometime)
			{
				tmp = tmparr[i];
				tmparr[i] = tmparr[j];
				tmparr[j] = tmp;
			}
}

//用于输入进程的函数，队首指针指向最早到达的进程，队尾指针指向最晚到达的指针。
status Importpro(ReadyQ *rq, PCBptr tmparr)
{
	PCB *t;
	t = new pcb;
	if (t == NULL)
	{
		cout << "Error!";
		return PERROR;
	}
	int i = 0;//此变量记录了输入进来的进程个数
	while (1)
	{
		char tmpc = ' ';
		cout << "请输入进程名：";
		cin >> t->ProName;
		cout << "请输入进程到达时间：";
		cin >> t->cometime;
		cout << "请输入进程运行时间：";
		cin >> t->runtime;
		t->state = 'R';
		tmparr[i] = *t;
		cout << "是否继续输入？（Y/N）：";
		cin >> tmpc;
		i++;
		if (tmpc == 'N' || tmpc == 'n')
			break;
	}
	//调用排序函数，排序的key是到达时间
	sort_pcb(tmparr, i);
	// 尾插法，将到达时间晚的插入队尾
	for (int j = 0; j < i; j++)
	{
		rq->tail->next = &tmparr[j];
		rq->tail = &tmparr[j];
    }
	return OK;
}

//进程运行模拟函数，本函数模拟的时间片设置为1
status RunProcess1(ReadyQ *rq)
{
	if (rq->head == rq->tail)
	{
		cout << "就绪队列内无程序，等待......";
		curtime++;
		emptytime++;
		return EMPTY;
	}
	if (curtime >= rq->head->cometime)
	{
		curtime++;
		rq->head->leftruntime--;
		if (rq->head->leftruntime == 0)
		{
			rq->head->state = 'F';
			cout << "进程名：" << rq->head->ProName;
			cout << "进程开始时间：" << rq->head->cometime;
			cout << "进程剩余运行时间：" << rq->head->leftruntime;
			cout << "进程结束时间：" << curtime;
		}
	}
}
int main()
{
	return 0;
}
