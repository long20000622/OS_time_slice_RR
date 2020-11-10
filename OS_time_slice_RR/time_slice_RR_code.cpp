/*----------------------------------------------------*/
//�˳���Ϊģ��ʱ��Ƭ��ת���ȷ��ĳ���
//����������
//ѧ�ţ�E01814162
/*----------------------------------------------------*/
#include <string>
#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

#define OK 1
#define PERROR -1
#define EMPTY 0

int curtime = 0;//ȫ�ֱ�����ģ�⴦�����ǰ��ʱ��
int emptytime = 0;//�����ÿ����һ�ξ������пյ�����ͼ�һ����������ֳ���10����ֹѭ���˳�����

typedef int status;
typedef struct pcb
{
	string ProName;
	int runtime;//������������ܹ�����ʱ��
	int cometime;//���̵����ʱ��
	char state;//���̵�״̬��RΪ������FΪ���
	int leftruntime;//������ɻ���ʱ��
	struct pcb *next;//ָ����һ�����̽ڵ��ָ��
}PCB, *PCBptr;

typedef struct ReadyQueue
{
	PCBptr head;//����ָ��
	PCBptr tail;//��βָ��
}ReadyQ;


//�������еĳ�ʼ����������ʼ����Ϊ��ʱ����ָ��Ͷ�λָ��ָ��һ�������������Ϣ����Ч�ڵ㡣
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

//ð�����������key�ǵ���ʱ�䡣�����ֱ��Ǳ�����̵Ľṹ������ͽ�����
//�����������С����
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

//����������̵ĺ���������ָ��ָ�����絽��Ľ��̣���βָ��ָ���������ָ�롣
status Importpro(ReadyQ *rq, PCBptr tmparr)
{
	PCB *t;
	t = new pcb;
	if (t == NULL)
	{
		cout << "Error!";
		return PERROR;
	}
	int i = 0;//�˱�����¼����������Ľ��̸���
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
		tmparr[i] = *t;
		cout << "�Ƿ�������룿��Y/N����";
		cin >> tmpc;
		i++;
		if (tmpc == 'N' || tmpc == 'n')
			break;
	}
	//�����������������key�ǵ���ʱ��
	sort_pcb(tmparr, i);
	// β�巨��������ʱ����Ĳ����β
	for (int j = 0; j < i; j++)
	{
		rq->tail->next = &tmparr[j];
		rq->tail = &tmparr[j];
    }
	return OK;
}

//��������ģ�⺯����������ģ���ʱ��Ƭ����Ϊ1
status RunProcess1(ReadyQ *rq)
{
	if (rq->head == rq->tail)
	{
		cout << "�����������޳��򣬵ȴ�......";
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
			cout << "��������" << rq->head->ProName;
			cout << "���̿�ʼʱ�䣺" << rq->head->cometime;
			cout << "����ʣ������ʱ�䣺" << rq->head->leftruntime;
			cout << "���̽���ʱ�䣺" << curtime;
		}
	}
}
int main()
{
	return 0;
}
