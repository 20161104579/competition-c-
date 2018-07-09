#include "head.h"

void AddJ(JudgeIn* J)
{
	int i;
	i = J->last;

	printf("��ί��ӣ�\n");

	printf("������ί���֣�\n");
	scanf("%s",&J->elem[i].name);
	getchar();

	printf("������ί�Ա�");
	scanf("%s",&J->elem[i].sex);
    getchar();

	printf("������ί�绰��");
	scanf("%s",&J->elem[i].phone);
    getchar();

	J->last++;
	printf(" �����ί��Ϣ�ɹ���\n");
}

void ShowJ(JudgeIn* J)
{
    int i;

	printf("��ʾȫ����ί��Ϣ��\n");
	printf("|      ����      | �Ա� |        �绰����        |\n");
	for (i = 0; i < J->last; i++)
	{
		printf("|%16s",J->elem[i].name);
		printf("|%6s",J->elem[i].sex);
		printf("|%24s\n",J->elem[i].phone);
	}

}

int FindJ(JudgeIn* J)
{
	char Name[20];
	int i=0;

	printf("����Ҫ���ҵ���ί����:\n");
	scanf("%s",&Name);
	getchar();

	while ((i < J->last) && (strcmp(Name,J->elem[i].name))) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void QueryJ(JudgeIn* J)
{
    int i;
	printf("��ί��Ϣ����\n");

	i = FindJ(J);

	if (i != -1) {
		printf("���ҽ������Ѿ��ҵ���Ϣ\n");
		printf("|  ���� | �Ա� |  �绰����        |\n");
        printf("|%6s",J->elem[i].name);
		printf("|%3s",J->elem[i].sex);
		printf("|%13s|\n",J->elem[i].phone);
	}
	else
		printf("��Ǹ��û�д�����Ϣ��\n");
}
/*
void LoadL(Seqlist* L)
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

		while(fscanf(fp,"%s,%s,%s,%lf",&Name,&Type,&Num,&score)!=EOF)
		{

		    strcpy(L->elem[i].name, Name);

		    strcpy(L->elem[i].type, Type);
		    strcpy(L->elem[i].phone, Num);

		    L->elem[i].score=score;

			i++;
			L->last=i;
		}
		fclose(fp);
	}
}

void CopyL(Seqlist* L)
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
*/

void AddL(Seqlist* L)
{
    int i = L->last;

	printf("��ӽ�Ŀ��\n");

	printf("��Ŀ���ͣ�\n");
	scanf("%s",&L->elem[i].type);
    getchar();

	printf("��Ŀ���ƣ�\n");
	scanf("%s",&L->elem[i].name);
    getchar();

	printf("��ϵ��ʽ���绰�ţ���\n");
	scanf("%s",&L->elem[i].phone);
    getchar();

	L->elem[i].score = -1;
	L->last++;

	printf("��Ŀ��Ϣ��ӳɹ���\n");
}

int FindL(Seqlist* L)
{
    int have, i=0;
    char name[20];
	char type[13];
	char phone[13];

	printf("ѡ��Ҫ���ҵķ�ʽ��\n");

	printf("1.���Ͳ���\n2.�绰�źŲ���\n3.��Ŀ���ֲ���\n");
	scanf("%d",&have);

	switch (have)
	{
		case 1: {
			printf("�������ͣ�\n");
			scanf("%s",&type);
			getchar();

			while((i<L->last)&&(strcmp(type,L->elem[i].type)))
				i++;
            }
				break;
		case 2: {
			printf("����绰��\n");
			scanf("%s",&phone);
			getchar();

			while ((i<L->last) && (strcmp(phone,L->elem[i].phone)))
				i++;
            }
				break;
		case 3: {
			printf("�����Ŀ���֣�\n");
			scanf("%s",&name);
			getchar();

			while ((i<L->last) && (strcmp(name,L->elem[i].name)))
				i++;
            }
				break;
    }

	if (i <L->last)
		return i;
	else
		return -1;
}

void DelL(Seqlist* L)
{
	int s, i;
	printf("ɾ����Ŀ��Ϣ\n");

	s = FindL(L);

	if (s == -1){
		printf("δ�ҵ���Ŀ��Ϣ��\n");
	}
	else
	{
		printf(" Ҫɾ���Ľ�Ŀ�ǣ�\n");
		printf(" ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);

		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;

		printf("ɾ���ɹ�\n");
	}
}

void QueryL(Seqlist* L)
{
    int s = FindL(L);
	printf("���ҽ�Ŀ��\n");

	if (s == -1){
		printf("δ�ҵ���Ŀ��Ϣ\n");
		printf("%s",L->elem[s+1].type);
	}
	else
	{
		printf("  ���ҳɹ�\n");
		printf("|  ��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
	}
}

void ChangeL(Seqlist* L)
{
    int s = FindL(L);
	int have;

	printf("�޸Ľ�Ŀ��Ϣ");

	if (s == -1)
		printf("δ�ҵ���Ŀ��Ϣ��\n");
	else
	{
		printf("�����޸�����Ϊ%s�Ľ�Ŀ��Ϣ\n",L->elem[s].name);
		printf("ѡ��Ҫ�޸ĵ���Ϣ:\n1.�޸Ľ�Ŀ���� \n2.�޸Ľ�Ŀ����\n3.�޸ĵ绰����\n");
		scanf("%d",&have);

		switch (have)
		{
			case 1:
			    scanf("%s",L->elem[s].name);
			    getchar();
			    break;
			case 2:
			    scanf("%s",L->elem[s].type);
			    getchar();
			    break;
			case 3:
			    scanf("%s",L->elem[s].phone);
			    getchar();
			    break;
		}
		printf("�޸���ɣ�����ϢΪ��\n");
		printf("��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
	}
}

void Grade(Seqlist* L,JudgeIn* J)
{
	int s, i, min, max;
	double sum = 0.0;
	int score[100];
	int num;
	int people = J->last;

	num = J->last;

	s = FindL(L);

	if (s == -1)
		printf("δ�ҵ���Ŀ��\n");
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

void ShowL(Seqlist* L)
{
    int i;
	printf("��ʾȫ���Ľ�Ŀ��Ϣ��\n");

	printf("��Ŀ����  |   ��Ŀ����   |	�绰��	| �ɼ� |\n");

	for (i = 0; i < L->last; i++)
	{
		printf("|%12s",L->elem[i].type);
		printf("|%14s",L->elem[i].name);
		printf("|%12s",L->elem[i].phone);
		printf("|%6s\n",L->elem[i].score);
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

void SortL(Seqlist* L)
{
	int have;

	printf("�Զ�����\n");
	printf("ѡ����������:\n1.��С����\n2.�Ӵ�С\n");

	scanf("%d",&have);
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);

	printf("������ɣ�\n");

	ShowL(L);
}

void UIL()
{
	printf("-------�˵�\n");
	printf("1.��ӽ�Ŀ\n");
	printf("2.ɾ����Ŀ\n");
	printf("3.���ܳɼ�����\n");
	printf("4.��ѯ\n");
	printf("5.�޸Ľ�Ŀ��Ϣ\n");
	printf("6.��ʾȫ����Ŀ��Ϣ|\n");
	printf("7.�Խ�Ŀ���д��\n");
	printf("0.�˳�\n");
}


void UIJ()
{
	printf("---�˵�\n");
	printf("1.�����ί��Ϣ\n");
	printf("2.��ʾȫ����ί��Ϣ\n");
	printf("3.��ί��Ϣ��ѯ\n");
	printf("0.�˳�\n");
}


void UI()
{
	printf("-------�˵�\n");
	printf("|1.��Ŀ��Ϣ|\n");
	printf("|2.��ί��Ϣ|\n");
	printf("|0.�˳�|\n");
}

void MenuL(Seqlist* L, JudgeIn* J)
{
	int i, have = 1;

	while (UIL(),printf("ѡ��Ҫ���еĹ��ܣ�\n"),scanf("%d",&i))
	{
		switch (i)
		{
			case 1:
			    AddL(L);
			    break;
			case 2:
			    DelL(L);
			    break;
			case 3:
			    SortL(L);
			    break;
			case 4:
			    QueryL(L);
			    break;
			case 5:
			    ChangeL(L);
			    break;
			case 6:
			    ShowL(L);
			    break;
			case 7:
			    Grade(L, J);
			    break;
			case 0:
			    have = 0;
			    break;
		}

		CopyL(L);
		if (have == 0)
			break;
	}
}

void MenuJ(JudgeIn* J)
{
	int i, have = 1;

	while (UIJ(),printf("ѡ��Ҫ���еĹ��ܣ�"),scanf("%d",&i))
	{
		have = 1;

		switch (i)
		{
		case 1:
		    AddJ(J);
		    break;
		case 2:
		    ShowJ(J);
            break;
		case 3:
		    QueryJ(J);
		    break;
		case 0:
		    have = 0;
		    break;
		}

		CopyJ(J);

		if (have == 0) {
			printf(" ��ί��Ϣ����ɹ�\n");
			break;

		}
	}
}

void Menu(Seqlist* L, JudgeIn* J)
{
	int i, have = 1;

	while (UI(),printf("ѡ��Ҫ���еĹ��ܣ�"),scanf("%d",&i))
	{
		switch (i)
		{
		case 1:
		    LoadL(L);
		    MenuL(L, J);
		    break;
		case 2:
		    LoadJ(J);
		    MenuJ(J);
		    break;
		case 0:
		    have = 0;
		    break;
		}
		if (have == 0)
			break;
	}
}
