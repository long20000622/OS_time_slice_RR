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
	int runtime;
	int cometime;
	char state;
	int leftruntime;
	struct pcb *next;
}PCB, *PCBptr;

typedef struct ReadyQueue
{
	PCBptr head;
	PCBptr tail;
}ReadyQ;

typedef struct BlockQueue
{
	PCBptr head;
	PCBptr tail;
}BlockQ;

status InitReadyQ(ReadyQ *rq)
{
	PCB *t = new pcb;
	if (t == NULL)
	{
		cout << "����" << endl;
		return ERROR;
	}
	rq->head = t;
	rq->tail = t;
	t->next = NULL;
	return OK;
}

void sort_pcb(PCBptr *tmparr)
{

}

status Importpro(ReadyQ *rq, PCBptr *tmparr)
{
	PCB *t;
	t = new pcb;
	if (t == NULL)
	{
		cout << "Error!";
		return PERROR;
	}
	int i = 0;
	while (1)
	{
		char tmpc = ' ';
		cout << "�������������";
		cin >> t->ProName;
		cout << "��������̵���ʱ�䣺";
		cin >> t->cometime;
		cout << "�������������ʱ�䣺";
		cin >> t->runtime;
		t->state = 'R';
		tmparr[i] = t;
		cout << "�Ƿ�������룿��Y/N����";
		cin >> tmpc;
		if (tmpc == 'N' || tmpc == 'n')
			break;
		i++;
	}
	sort_pcb(tmparr);
	PCB *tmp;
	return OK;
}
int main()
{
	return 0;
}
