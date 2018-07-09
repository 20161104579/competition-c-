#include "head.h"

void UIJ()
{
	printf("------菜单\n");
	printf("-----1.添加评委信息\n");
	printf("-----2.显示全部评委信息\n");
	printf("-----3.评委信息查询\n");
	printf("-----0.退出评委信息系统\n");
}

void MenuJ(JudgeIn* J)
{
	int i, have = 1;

	while (UIJ(),printf("选择要进行的功能："),scanf("%d",&i))
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
			printf(" 裁判信息保存成功\n");
			break;

		}
	}
}

void AddJ(JudgeIn* J)
{
	int i;
	i = J->last;

	printf("进入评委添加系统。\n");

	printf("输入评委名字：\n");
	scanf("%s",&J->elem[i].name);
	getchar();

	printf("输入评委性别：");
	scanf("%s",&J->elem[i].sex);
    getchar();

	printf("输入评委电话：");
	scanf("%s",&J->elem[i].phone);
    getchar();

	J->last++;
	printf(" 添加评委信息成功。\n");
}

void ShowJ(JudgeIn* J)
{
    int i;

	printf("进入显示全部评委信息系统：\n");
	printf("|      姓名      | 性别 |        电话号码        |\n");
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

	printf("请输入要查找的评委名字:\n");
	scanf("%s",&Name);
	getchar();

	while ((i < J->last) && !(J->elem[i].name == Name)) {
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
	printf("已进入评委信息查找系统\n");

	i = FindJ(J);
	if (i != -1) {
		printf("查找结束，已经找到信息.姓名为%s",J->elem[i].name);
		printf("|  姓名  | 性别 |        电话号码        |\n");
        printf("|%16s",J->elem[i].name);
		printf("|%6s",J->elem[i].sex);
		printf("|%24s",J->elem[i].phone);
	}
	else
		printf("抱歉，没有此人信息。\n");
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
		printf("信息保存成功！\n");
		fclose(fp);
		return;
	}
}
*/

void UIL()
{
	printf("-------菜单\n");
	printf("1.添加选手信息\n");
	printf("2.删除选手信息|\n");
	printf("3.对总成绩排名\n");
	printf("4.成绩查询\n");
	printf("5.修改选手信息\n");
	printf("6.显示全部选手信息|\n");
	printf("7.对选手进行打分\n");
	printf("0.退出选手信息系统\n");
}

void MenuL(Seqlist* L, JudgeIn* J)
{
	int i, have = 1;

	while (UIL(),printf("选择要进行的功能：\n"),scanf("%d",&i))
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

void AddL(Seqlist* L)
{
    int i = L->last;

	printf("进入选手信息添加系统。\n");

	printf("节目类型：\n");
	scanf("%s",&L->elem[i].type);
    getchar();

	printf("节目名称：\n");
	scanf("%s",&L->elem[i].name);
    getchar();

	printf("选手电话号：\n");
	scanf("%s",&L->elem[i].phone);
    getchar();

	L->elem[i].score = -1;
	L->last++;

	printf("选手信息添加成功。\n");
}

int FindL(Seqlist* L)
{
    int have, i=0;
    char name[20];
	char type[13];
	char phone[13];

	printf("选择要查找的方式：\n");

	printf("1.类型查找\n2.电话号号查找\n3.节目名字查找\n");


	scanf("%d",&have);
	switch (have)
	{
		case 1: {
			printf("输入类型：\n");
			scanf("%s",&name);
			getchar();

			while((i<L->last)&&(!(type==L->elem[i].type)))
				i++;
            }
				break;
		case 2: {
			printf("输入电话：\n");
			scanf("%s",&phone);
			getchar();

			while ((i<L->last) && (!(phone == L->elem[i].phone)))
				i++;
            }
				break;
		case 3: {
			printf("输入节目名字：\n");
			scanf("%s",&name);
			getchar();

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

void DelL(Seqlist* L)
{
	int s, i;
	printf("已进入选手信息删除系统\n");

	s = FindL(L);

	if (s == -1)
		printf("未找到选手信息！\n");

	else
	{
		printf(" 要删除的选手信息是：\n");
		printf(" 节目类型  |   节目名称   |	电话号	| 成绩 |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;

		printf("删除成功\n");
	}
}

void QueryL(Seqlist* L)
{
    int s = FindL(L);
	printf("进入选手信息查询系统。\n");

	if (s == -1)
		printf("未找到选手信息！\n");
	else
	{
		printf("  查找成功,找到的是节目%s\n" ,L->elem[s].name);
		printf("|  节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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

	printf("  进入选手信息修改系统");

	if (s == -1)
		printf("未找到选手信息！\n");
	else
	{
		printf("即将修改名字为%s的节目信息\n",L->elem[s].name);
		printf("选择要修改的信息:\n1.修改节目名字 \n2.修改节目类型\n3.修改电话号码\n");
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
		printf("修改完成，新信息为：\n");
		printf("节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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
		printf("未找到节目。\n");
	else
	{
		printf("即将对节目%s打分。\n输入评委打分成绩（共%d个评委）\n",L->elem[s].name,num);
		for (i = 0; i<J->last; i++)
		{
			printf("对节目%s评委给他的分数是：",J->elem[i].name);

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

		printf("最后他的得分是：%d\n",sum);
	}
}

void ShowL(Seqlist* L)
{
    int i;
	printf("显示全部选手的信息：\n");

	printf("节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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

	printf("自动排序\n");
	printf("选择排名方法:\n1.从小到大\n2.从大到小\n");

	scanf("%d",&have);
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);

	printf("排序完成！\n");

	ShowL(L);
}

void UI()
{
	printf("-------菜单\n");
	printf("|1.选手信息|\n");
	printf("|2.评委信息|\n");
	printf("|0.退出|\n");
}

void Menu(Seqlist* L, JudgeIn* J)
{
	int i, have = 1;

	LoadJ(J);

	LoadL(L);

	while (UI(),printf("选择要进行的功能："),scanf("%d",&i))
	{
		switch (i)
		{
		case 1:
		    MenuL(L, J);
		    break;
		case 2:
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
