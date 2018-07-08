
#include "head.h"

void load(SeqList *L)
{
	int i = 0, Score[5], Sum;
	double Num;
	char Name[20];
	FILE* fp;
	fp = fopen("student.txt", "a+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		while(fscanf(fp,"%lf %s %d %d %d %d",&Num, Name, &Score[0], &Score[1], &Score[2], &Sum)!=EOF)
		{
			L->elem[i].num = Num;
			strcpy(L->elem[i].name, Name);
			L->elem[i].score[0] = Score[0];
			L->elem[i].score[1] = Score[1];
			L->elem[i].score[2] = Score[2];
			L->elem[i].sum = Sum;
			i++;
			L->last++;
		}
		fclose(fp);
	}
}

void copydata(SeqList* L)
{
	int i;
	FILE* fp;
	fp = fopen("student.txt", "w+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		for(i=0; i<L->last; i++)
		{
			fprintf(fp,"%lf %s %d %d %d %d\n",L->elem[i].num, L->elem[i].name, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2], L->elem[i].sum);
		}
		printf("��Ϣ����ɹ���\n");
		fclose(fp);
		return;
	}
}

void menu()
{
	printf("|���ܼ���|\n");
	printf("|1.�����Ϣ|\n");
	printf("|2.ɾ����Ϣ|\n");
	printf("|3.�ܳɼ�����|\n");
	printf("|4.�ɼ���ѯ|\n");
	printf("|5.�޸���Ϣ|\n");
	printf("|6.��ʾȫ����Ϣ|\n");
	printf("|7.��������Ϣ|\n");
	printf("|0.�˳�������|\n");
}

void Add(SeqList* L)
{
	int i;
	printf("����ѧ����Ϣ��\n");

	i = L->last;
	printf("ѧ�ţ�");
	scanf("%lf", &L->elem[i].num);

	printf("������");
	scanf("%s", L->elem[i].name);

	printf("�ɼ�����Ӣ����������ѧ��\n");

	scanf("%d%d%d", &L->elem[i].score[0], &L->elem[i].score[1],&L->elem[i].score[2]);


	L->elem[i].sum = L->elem[i].score[0] + L->elem[i].score[1] + L->elem[i].score[2];
	L->last++;
	printf("\n���ӳɹ���------ ѧ�ţ�%.0lf\n", L->elem[i].num);

}

void Del(SeqList* L)
{
	int i, s;

	printf("ɾ����Ϣ��\n");

	s = Find(L) - 1;

	for(i=s; i<L->last; i++)
	{
		L->elem[i] = L->elem[i+1];
	}

	L->last--;
	printf("ɾ���ɹ���\n");
}


void quicksort(SeqList* L,int left, int right)
{
	ElemType t, temp;
	int i, j;

	if(left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while(i!=j)
	{
		while(L->elem[j].sum>=temp.sum && i<j)
			j--;

		while(L->elem[i].sum<=temp.sum && i<j)
			i++;

		if(i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort(L, left, i-1);
	quicksort(L, i+1, right);
}

void sortscore(SeqList* L)
{
	printf("��ʼ����");

	quicksort(L, 0,L->last-1);

	printf("������ɣ�\n");
}

int Find(SeqList* L)
{
	int i=0;
	double n;

	printf("����Ҫ���ҵ�ѧ�ţ�\n");

	scanf("%lf", &n);

	while ((i <= L->last) && (L->elem[i].num != n))
		i++;
	if(i<=L->last)
		return i+1;
	else
		return -1;
}

void Insert(SeqList* L)
{
	int i, s;
	printf("������Ϣϵͳ��\n");

	printf("����λ�ã�");

	scanf("%d", &s);
	s--;

	L->last++;

	for(i=L->last-1; i>s; i--)
	{
		L->elem[i] = L->elem[i-1];
	}

	printf("ѧ�ţ�");
	scanf("%lf", &L->elem[i].num);

	printf("������");
	scanf("%s", L->elem[i].name);

	printf("�ɼ�����Ӣ����������ѧ��\n");

	scanf("%d%d%d", &L->elem[i].score[0], &L->elem[i].score[1],&L->elem[i].score[2]);

	L->elem[s].sum = L->elem[s].score[0] + L->elem[s].score[1] + L->elem[s].score[2];

	printf("\n��ӳɹ���------ ѧ��Ϊ��%.0lf\n", L->elem[s].num);

}
void Query(SeqList* L)
{
	int i;

	printf("������Ϣ��\n");

	i = Find(L);

	if(i!=-1)
		printf("λ����%d\n",i);
	else
		printf("no such a person\n");

}

void Change(SeqList *L)
{
	int i, s;
	int have;
	printf("�޸���Ϣ��\n");

	s = Find(L) - 1;

	if(s != -1)
	{
		printf("ѧ��Ϊ%.0lf��ѧ����Ϣ��",L->elem[s].num);
		printf("ѡ��Ҫ�޸ĵ���Ϣ��\n\t1.�޸�ѧ�š�\n\t2.�޸����֡�\n\t3.�޸�Ӣ��ɼ���\n\t4.�޸ļ�����ɼ���\n\t5.�޸���ѧ�ɼ���\n");

		scanf("%d", &have);

		printf("������Ҫ�޸ĵ���Ϣ��");

		switch(have)
		{
			case 1:
				scanf("%lf",&L->elem[s].num);
				break;
			case 2:
				scanf("%s",L->elem[s].name);
				break;
			case 3:
				scanf("%d",&L->elem[s].score[0]);
				break;
			case 4:
				scanf("%d",&L->elem[s].score[1]);
				break;
			case 5:
				scanf("%d",&L->elem[s].score[2]);
				break;
		}

		if( have==3 || have==4 || have==5 )
			L->elem[s].sum = L->elem[s].score[0] + L->elem[s].score[1] + L->elem[s].score[2];
		printf("�޸ĳɹ�!\n");
	}

	else
		printf("δ�ҵ�ѧ����Ϣ��\n");
}

void Show(SeqList *L)
{
	printf("��ʾȫ����Ϣ��\n");
	int i;
	printf("|     ѧ��     |   ����   | Ӣ��ɼ� | ������ɼ� | ��ѧ�ɼ� |  �ܳɼ�  |\n");
	for(i=0; i<L->last; i++)
	{
		printf("|%15.0lf|%10s|%5d|%5d|%5d|%5d|\n",L->elem[i].num, L->elem[i].name, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2],L->elem[i].sum);
	}
}


