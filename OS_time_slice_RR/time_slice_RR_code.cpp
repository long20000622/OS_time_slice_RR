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

typedef int status;
typedef struct pcb
{
	string ProName;
	int runtime;//进程运行完成总共所需时间
	int cometime;//进程到达的时间
	char state;//进程的状态，R为就绪，F为完成，B为阻塞
	int leftruntime;//进程完成还需时间
	struct pcb *next;//指向下一个进程节点的指针
}PCB, *PCBptr;

typedef struct ReadyQueue
{
	PCBptr head;//队首指针
	PCBptr tail;//队尾指针
}ReadyQ;

typedef struct BlockQueue
{
	PCBptr head;//队首指针
	PCBptr tail;//队尾指针
}BlockQ;

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
void sort_pcb(PCBptr *tmparr,int num)
{

}

//用于输入进程的函数，队首指针指向最早到达的进程，队尾指针指向最晚到达的指针。
status Importpro(ReadyQ *rq, PCBptr *tmparr)
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
		tmparr[i] = t;
		cout << "是否继续输入？（Y/N）：";
		cin >> tmpc;
		if (tmpc == 'N' || tmpc == 'n')
			break;
		i++;
	}
	//调用排序函数，排序的key是到达时间
	sort_pcb(tmparr, i);
	PCB *tmp,*chg;
	tmp = rq->head;
	// 头插法，将到达时间更早的插入队首
	if (rq->head != rq->tail)
	{
		chg = rq->head->next;
		rq->head->next = tmp;
		tmp->next = chg;
	}
	else
	{
		rq->head->next = tmp;
		tmp->next = NULL;
		rq->tail = tmp;
	}
	return OK;
}
int main()
{
	return 0;
}
