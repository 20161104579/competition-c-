#include "head.h"

void Copy2(JudgeIn* J)
{
    int i;
	FILE* fp;
	fp = fopen("judge.csv", "w+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		for(i=0; i<L->last; i++)
		{
			fprintf(fp,"%s,%c,%s\n",J->elem[i].name,J->elem[i].sex,J->elem[i].phone);
		}
		printf("��Ϣ����ɹ���\n");
		fclose(fp);
		return;
	}
}

void Load2(JudgeIn* J)
{
	int i=0;
	char Name[20];
	char Num[13]
	char Sex;

	FILE* fp;
	fp = fopen("judge.csv", "a+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		while(fscanf(fp,"%s,%c,%s\n",&Name,&Sex,&Num)!=EOF)
		{
		    J->elem[i].name=Name;
		    J->elem[i].phone=Num;
		    J->elem[i].sex=Sex;
			i++;
			J->last=i;
		}
		fclose(fp);
	}
}

void UI2()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.�����ί��Ϣ------------|\n");
	printf("\t\t\t|------------2.��ʾȫ����ί��Ϣ--------|\n");
	printf("\t\t\t|------------3.��ί��Ϣ��ѯ------------|\n");
	printf("\t\t\t|------------0.�˳���ί��Ϣϵͳ--------|\n");
}

void menu2(JudgeIn* J)
{
	UI2();
	//	load2(J);//�����ļ�����ί����
	int i, have = 1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while (!scanf("%d",&i))
	{
		have = 1;

		switch (i)
		{
		case 1:
		    add(J);
		    break;
		case 2:
		    Show(J);
            break;
		case 3:
		    Query2(J);
		    break;
		case 0:
		    have = 0;
		    break;
		}
		Copy2(J);
		if (have == 0) {
			printf(" ������Ϣ����ɹ�\n");
			break;

		}
		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}

void add(JudgeIn* J)
{
	int i;
	i = J->last;
	printf("\t  ������ί���ϵͳ��\n");
	printf("\t  ������ί���֣�");
	scanf("%d",J->elem[i].name);
	printf("\t  ������ί�Ա�");
	scanf("%d",J->elem[i].sex);
	printf("\t  ������ί�绰��");
	scanf("%d",J->elem[i].phone);
	J->last++;
	printf(" �����ί��Ϣ�ɹ���\n");
}

void Show(JudgeIn* J)
{
    int i;

	printf("������ʾȫ����ί��Ϣϵͳ��\n");
	printf("\t\t|      ����      | �Ա� |        �绰����        |\n");
	for (i = 0; i < J->last; i++)
	{
		printf("\t\t|%16s",J->elem[i].name);
		printf("|%6c",J->elem[i].sex);
		printf("|%24s\n",J->elem[i].phone);
	}

}

int Find2(JudgeIn* J)
{
	char Name[20];
	int i=0;

	printf("\t  ������Ҫ���ҵ���ί����:\n");
	scanf("%d",&Name);
	while ((i < J->last) && !(J->elem[i].name == Name)) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void Query2(JudgeIn* J)
{
    int i;
	printf("\t  �ѽ�����ί��Ϣ����ϵͳ\n");

	i = Find2(J);
	if (i != -1) {
		printf("���ҽ������Ѿ��ҵ���Ϣ.����Ϊ%s",J->elem[i].name);
		printf("|  ����  | �Ա� |        �绰����        |\n");
        printf("|%16s",J->elem[i].name);
		printf("|%6c",J->elem[i].sex);
		printf("|%24s",J->elem[i].phone);
	}
	else
		printf("\t  ��Ǹ��û�д�����Ϣ��\n");
}

void Load1(Seqlist* L)
{

	int i=0;
	char Name[20];
	char Type[13];
	char Num[13];
	double score;

	FILE* fp;
	fp = fopen("entertain.csv", "a+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		while(fscanf(fp,"%s,%s,%s,%lf\n",&Name,&Type,&Num,%score)!=EOF)
		{
		    L->elem[i].name=Name;
		    L->elem[i].type=Type;
		    L->elem[i].phone=Num;
		    L->elem[i].score=score;
			i++;
			L->last=i;
		}
		fclose(fp);
	}
}
string doubleTranStr(double integer) {
	stringstream ss;
	ss << integer;
	return ss.str();
}
void Copy1(Seqlist* L)
{
	int i;
	FILE* fp;
	fp = fopen("entertain.csv", "w+");
	if(fp == NULL)
		printf("The file can't be opened!\n");
	else
	{
		for(i=0; i<L->last; i++)
		{
			fprintf(fp,"%s,%s,%s,%lf\n",L->elem[i].name,L->elem[i].type,L->elem[i].phone,L->elem[i].score);
		}
		printf("��Ϣ����ɹ���\n");
		fclose(fp);
		return;
	}
}


void UI1()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.���ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------2.ɾ��ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------3.���ܳɼ�����------------|\n");
	printf("\t\t\t|------------4.�ɼ���ѯ----------------|\n");
	printf("\t\t\t|------------5.�޸�ѡ����Ϣ------------|\n");
	printf("\t\t\t|------------6.��ʾȫ��ѡ����Ϣ--------|\n");
	printf("\t\t\t|------------7.��ѡ�ֽ��д��----------|\n");
	printf("\t\t\t|------------0.�˳�ѡ����Ϣϵͳ--------|\n");
}

void menu1(Seqlist* L, JudgeIn* J)
{
	UI1();
	int i, have = 1;
	printf("ѡ��Ҫ���еĹ��ܣ�\n");

	while (!scanf("%d",&i))
	{
		switch (i)
		{
			case 1:
			    Add(L);
			    break;
			case 2:
			    Del(L);
			    break;
			case 3:
			    Sort(L);
			    break;
			case 4:
			    Query1(L);
			    break;
			case 5:
			    Change(L);
			    break;
			case 6:
			    Show1(L);
			    break;
			case 7:
			    Grade(L, J);
			    break;
			case 0:
			    have = 0;
			    break;
		}
		Copy1(L);
		if (have == 0)
			break;
		printf("ѡ��Ҫ���еĹ��ܣ�\n");
	}
}

void Add(Seqlist* L)
{
    int i = L->last;

	printf("����ѡ����Ϣ���ϵͳ��\n");

	printf("\t  ��Ŀ���ͣ�\n");
	scanf("%s",&L->elem[i].type);

	printf("\t  ��Ŀ���ƣ�\n");
	scanf("%s",&L->elem[i].name);

	printf("\t  ѡ�ֵ绰�ţ�\n");
	scanf("%s",&L->elem[i].phone);

	L->elem[i].score = -1;
	L->last++;

	printf("\t  ѡ����Ϣ��ӳɹ���\n");
}

int Find2(Seqlist* L)
{
    int have, i=0;
    char name[20];
	char type[13];
	char phone[13];

	printf("\t  ѡ��Ҫ���ҵķ�ʽ��\n");

	printf("1.���Ͳ���\n2.�绰�źŲ���\n3.��Ŀ���ֲ���\n");


	scanf("%d",&have);
	switch (have)
	{
		case 1: {
			printf("\t  �������ͣ�\n");
			scanf("%s",&name);
			while((i<L->last)&&(!(type==L->elem[i].type)))
				i++;
		}
				break;
		case 2: {
			printf("\t  ����绰��\n");
			scanf("%s",&phones);
			while ((i<L->last) && (!(phone == L->elem[i].phone)))
				i++;
		}
				break;
		case 3: {
			printf"\t  �����Ŀ���֣�\n");
			scanf("%s",&name);
			while ((i<L->last) && (!(name == L->elem[i].name)))
				i++;
		}
				break;
	}
	if (i < L->last)
		return i;
	else
		return -1;
}

void Del(Seqlist* L)
{
	int s, i;
	printf("�ѽ���ѡ����Ϣɾ��ϵͳ\n");

	s = Find2(L);

	if (s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");

	else
	{
		printf("\t  Ҫɾ����ѡ����Ϣ�ǣ�\n");
		printf("\t\t|  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;

		printf("\tɾ���ɹ�\n");
	}
}

void Query1(Seqlist* L)
{
	printf("\t  ����ѡ����Ϣ��ѯϵͳ��\n");
	int s = Find2(L);
	if (s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("\t  ���ҳɹ�,�ҵ����ǽ�Ŀ%s\n" ,L->elem[s].name);
		printf("\t\t|  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
	}
}

void Change(Seqlist* L)
{
    int s = Find2(L);
	int have;

	printf("\t  ����ѡ����Ϣ�޸�ϵͳ");

	if (s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("�����޸�����Ϊ%s�Ľ�Ŀ��Ϣ\n",L->elem[s].name);
		printf("\t  ѡ��Ҫ�޸ĵ���Ϣ:\n1.�޸Ľ�Ŀ���� \n2.�޸Ľ�Ŀ����\n3.�޸ĵ绰����\n");
		scanf("%d",&have);

		switch (have)
		{
			case 1:
			    scanf("%s",L->elem[s].name);
			    break;
			case 2:
			    scanf("%s",L->elem[s].type);
			    break;
			case 3:
			    scanf("%s",L->elem[s].phone);
			    break;
		}
		printf("\t  �޸���ɣ�����ϢΪ��\n");
		printf("\t\t|  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
	}
}

void Grade(Seqlist* L, Judges* J)
{
	int s, i, min, max;
	double sum = 0.0;
	int score[100];
	int num;//��ί��
	int people = J->last;

	num = J->last;

	s = Find2(L);

	if (s == -1)
		printf("δ�ҵ�ѡ����Ϣ��\n");
	else
	{
		printf("�����Խ�Ŀ%s��֡�\n������ί��ֳɼ�����%d����ί��\n",L->elem[s].name,num);
		for (i = 0; i<J->last; i++)
		{
			printf("�Խ�Ŀ%s��ί�����ķ����ǣ�",J->elem[i].name);

			scanf("%d",&score[i]);
			sum += score[i];
		}

		min = score[0];
		max = score[0];

		for (i = 0; i<J->last; i++)
		{
			if (score[i]<min)
				min = score[i];
			if (score[i]>max)
				max = score[i];
		}
		if (num > 2)
		{
			sum = sum - max;
			sum = sum - min;
			people -= 2;
		}
		sum = sum / people;
		L->elem[s].score = sum;

		printf("������ĵ÷��ǣ�%d\n",sum);
	}
}

void Show1(Seqlist* L)
{
    int i;
	printf("�ѽ���ѡ����Ϣ��ʾϵͳ��������ʾȫ��ѡ�ֵ���Ϣ��\n");

	printf("\t\t|  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

	for (i = 0; i < L->last; i++)
	{
		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
	}
}

void quicksort_min(Seqlist* L, int left, int right)
{
	NodeEntertain t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score >= temp.score && i<j)
			j--;
		while (L->elem[i].score <= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_min(L, left, i - 1);
	quicksort_min(L, i + 1, right);
}

void quicksort_max(Seqlist* L, int left, int right)
{
	NodeEntertain t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score <= temp.score && i<j)
			j--;
		while (L->elem[i].score >= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_max(L, left, i - 1);
	quicksort_max(L, i + 1, right);
}

void Sort(Seqlist* L)
{
	int have;

	printf("\t  �����Զ�����ϵͳ");
	printf("\t  ѡ����������:\n1.��С����\n2.�Ӵ�С\n");

	scanf("%d",&have);
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);

	printf("������ɣ�\n");

	Show1(L);
}

void UI()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.����ѡ����Ϣϵͳ--------|\n");
	printf("\t\t\t|------------2.������ί��Ϣϵͳ--------|\n");
	printf("\t\t\t|------------0.�˳�ϵͳ----------------|\n");
}

void Menu(Seqlist* L, Judges* J)
{
	UI();//���ز˵�
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while (cin>>i)
	{
		switch (i)
		{
		case 1:
		    menu1(L, J);
		    break;
		case 2:
		    menu2(J);
		    break;
		case 0:
		    have = 0;
		    break;
		}
		if (have == 0)
			break;
		UI();

		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}
