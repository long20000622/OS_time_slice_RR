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

typedef int status;
typedef struct pcb
{
	string ProName;
	int runtime;//������������ܹ�����ʱ��
	int cometime;//���̵����ʱ��
	char state;//���̵�״̬��RΪ������FΪ��ɣ�BΪ����
	int leftruntime;//������ɻ���ʱ��
	struct pcb *next;//ָ����һ�����̽ڵ��ָ��
}PCB, *PCBptr;

typedef struct ReadyQueue
{
	PCBptr head;//����ָ��
	PCBptr tail;//��βָ��
}ReadyQ;

typedef struct BlockQueue
{
	PCBptr head;//����ָ��
	PCBptr tail;//��βָ��
}BlockQ;

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
void sort_pcb(PCBptr *tmparr,int num)
{

}

//����������̵ĺ���������ָ��ָ�����絽��Ľ��̣���βָ��ָ���������ָ�롣
status Importpro(ReadyQ *rq, PCBptr *tmparr)
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
		tmparr[i] = t;
		cout << "�Ƿ�������룿��Y/N����";
		cin >> tmpc;
		if (tmpc == 'N' || tmpc == 'n')
			break;
		i++;
	}
	//�����������������key�ǵ���ʱ��
	sort_pcb(tmparr, i);
	PCB *tmp,*chg;
	tmp = rq->head;
	// ͷ�巨��������ʱ�����Ĳ������
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
