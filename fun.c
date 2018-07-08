
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
		printf("信息保存成功！\n");
		fclose(fp);
		return;
	}
}

void menu()
{
	printf("|功能集合|\n");
	printf("|1.添加信息|\n");
	printf("|2.删除信息|\n");
	printf("|3.总成绩排名|\n");
	printf("|4.成绩查询|\n");
	printf("|5.修改信息|\n");
	printf("|6.显示全部信息|\n");
	printf("|7.插入新信息|\n");
	printf("|0.退出并保存|\n");
}

void Add(SeqList* L)
{
	int i;
	printf("增加学生信息：\n");

	i = L->last;
	printf("学号：");
	scanf("%lf", &L->elem[i].num);

	printf("姓名：");
	scanf("%s", L->elem[i].name);

	printf("成绩：（英语，计算机，数学）\n");

	scanf("%d%d%d", &L->elem[i].score[0], &L->elem[i].score[1],&L->elem[i].score[2]);


	L->elem[i].sum = L->elem[i].score[0] + L->elem[i].score[1] + L->elem[i].score[2];
	L->last++;
	printf("\n增加成功！------ 学号：%.0lf\n", L->elem[i].num);

}

void Del(SeqList* L)
{
	int i, s;

	printf("删除信息：\n");

	s = Find(L) - 1;

	for(i=s; i<L->last; i++)
	{
		L->elem[i] = L->elem[i+1];
	}

	L->last--;
	printf("删除成功！\n");
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
	printf("开始排序");

	quicksort(L, 0,L->last-1);

	printf("排序完成！\n");
}

int Find(SeqList* L)
{
	int i=0;
	double n;

	printf("输入要查找的学号：\n");

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
	printf("插入信息系统：\n");

	printf("插入位置：");

	scanf("%d", &s);
	s--;

	L->last++;

	for(i=L->last-1; i>s; i--)
	{
		L->elem[i] = L->elem[i-1];
	}

	printf("学号：");
	scanf("%lf", &L->elem[i].num);

	printf("姓名：");
	scanf("%s", L->elem[i].name);

	printf("成绩：（英语，计算机，数学）\n");

	scanf("%d%d%d", &L->elem[i].score[0], &L->elem[i].score[1],&L->elem[i].score[2]);

	L->elem[s].sum = L->elem[s].score[0] + L->elem[s].score[1] + L->elem[s].score[2];

	printf("\n添加成功！------ 学号为：%.0lf\n", L->elem[s].num);

}
void Query(SeqList* L)
{
	int i;

	printf("查找信息：\n");

	i = Find(L);

	if(i!=-1)
		printf("位置在%d\n",i);
	else
		printf("no such a person\n");

}

void Change(SeqList *L)
{
	int i, s;
	int have;
	printf("修改信息：\n");

	s = Find(L) - 1;

	if(s != -1)
	{
		printf("学号为%.0lf的学生信息。",L->elem[s].num);
		printf("选择要修改的信息：\n\t1.修改学号。\n\t2.修改名字。\n\t3.修改英语成绩。\n\t4.修改计算机成绩。\n\t5.修改数学成绩。\n");

		scanf("%d", &have);

		printf("请输入要修改的信息：");

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
		printf("修改成功!\n");
	}

	else
		printf("未找到学生信息！\n");
}

void Show(SeqList *L)
{
	printf("显示全部信息：\n");
	int i;
	printf("|     学号     |   姓名   | 英语成绩 | 计算机成绩 | 数学成绩 |  总成绩  |\n");
	for(i=0; i<L->last; i++)
	{
		printf("|%15.0lf|%10s|%5d|%5d|%5d|%5d|\n",L->elem[i].num, L->elem[i].name, L->elem[i].score[0], L->elem[i].score[1], L->elem[i].score[2],L->elem[i].sum);
	}
}


