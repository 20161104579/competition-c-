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
		printf("信息保存成功！\n");
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
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.添加评委信息------------|\n");
	printf("\t\t\t|------------2.显示全部评委信息--------|\n");
	printf("\t\t\t|------------3.评委信息查询------------|\n");
	printf("\t\t\t|------------0.退出评委信息系统--------|\n");
}

void menu2(JudgeIn* J)
{
	UI2();
	//	load2(J);//加载文件中评委数据
	int i, have = 1;
	printf("选择要进行的功能：");
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
			printf(" 裁判信息保存成功\n");
			break;

		}
		printf("选择要进行的功能：");
	}
}

void add(JudgeIn* J)
{
	int i;
	i = J->last;
	printf("\t  进入评委添加系统。\n");
	printf("\t  输入评委名字：");
	scanf("%d",J->elem[i].name);
	printf("\t  输入评委性别：");
	scanf("%d",J->elem[i].sex);
	printf("\t  输入评委电话：");
	scanf("%d",J->elem[i].phone);
	J->last++;
	printf(" 添加评委信息成功。\n");
}

void Show(JudgeIn* J)
{
    int i;

	printf("进入显示全部评委信息系统：\n");
	printf("\t\t|      姓名      | 性别 |        电话号码        |\n");
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

	printf("\t  请输入要查找的评委名字:\n");
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
	printf("\t  已进入评委信息查找系统\n");

	i = Find2(J);
	if (i != -1) {
		printf("查找结束，已经找到信息.姓名为%s",J->elem[i].name);
		printf("|  姓名  | 性别 |        电话号码        |\n");
        printf("|%16s",J->elem[i].name);
		printf("|%6c",J->elem[i].sex);
		printf("|%24s",J->elem[i].phone);
	}
	else
		printf("\t  抱歉，没有此人信息。\n");
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
		printf("信息保存成功！\n");
		fclose(fp);
		return;
	}
}


void UI1()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.添加选手信息------------|\n");
	printf("\t\t\t|------------2.删除选手信息------------|\n");
	printf("\t\t\t|------------3.对总成绩排名------------|\n");
	printf("\t\t\t|------------4.成绩查询----------------|\n");
	printf("\t\t\t|------------5.修改选手信息------------|\n");
	printf("\t\t\t|------------6.显示全部选手信息--------|\n");
	printf("\t\t\t|------------7.对选手进行打分----------|\n");
	printf("\t\t\t|------------0.退出选手信息系统--------|\n");
}

void menu1(Seqlist* L, JudgeIn* J)
{
	UI1();
	int i, have = 1;
	printf("选择要进行的功能：\n");

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
		printf("选择要进行的功能：\n");
	}
}

void Add(Seqlist* L)
{
    int i = L->last;

	printf("进入选手信息添加系统。\n");

	printf("\t  节目类型：\n");
	scanf("%s",&L->elem[i].type);

	printf("\t  节目名称：\n");
	scanf("%s",&L->elem[i].name);

	printf("\t  选手电话号：\n");
	scanf("%s",&L->elem[i].phone);

	L->elem[i].score = -1;
	L->last++;

	printf("\t  选手信息添加成功。\n");
}

int Find2(Seqlist* L)
{
    int have, i=0;
    char name[20];
	char type[13];
	char phone[13];

	printf("\t  选择要查找的方式：\n");

	printf("1.类型查找\n2.电话号号查找\n3.节目名字查找\n");


	scanf("%d",&have);
	switch (have)
	{
		case 1: {
			printf("\t  输入类型：\n");
			scanf("%s",&name);
			while((i<L->last)&&(!(type==L->elem[i].type)))
				i++;
		}
				break;
		case 2: {
			printf("\t  输入电话：\n");
			scanf("%s",&phones);
			while ((i<L->last) && (!(phone == L->elem[i].phone)))
				i++;
		}
				break;
		case 3: {
			printf"\t  输入节目名字：\n");
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
	printf("已进入选手信息删除系统\n");

	s = Find2(L);

	if (s == -1)
		printf("未找到选手信息！\n");

	else
	{
		printf("\t  要删除的选手信息是：\n");
		printf("\t\t|  节目类型  |   节目名称   |	电话号	| 成绩 |\n");

		printf("|%12s",L->elem[s].type);
		printf("|%14s",L->elem[s].name);
		printf("|%12s",L->elem[s].phone);
		printf("|%6s\n",L->elem[s].score);
		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;

		printf("\t删除成功\n");
	}
}

void Query1(Seqlist* L)
{
	printf("\t  进入选手信息查询系统。\n");
	int s = Find2(L);
	if (s == -1)
		printf("未找到选手信息！\n");
	else
	{
		printf("\t  查找成功,找到的是节目%s\n" ,L->elem[s].name);
		printf("\t\t|  节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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

	printf("\t  进入选手信息修改系统");

	if (s == -1)
		printf("未找到选手信息！\n");
	else
	{
		printf("即将修改名字为%s的节目信息\n",L->elem[s].name);
		printf("\t  选择要修改的信息:\n1.修改节目名字 \n2.修改节目类型\n3.修改电话号码\n");
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
		printf("\t  修改完成，新信息为：\n");
		printf("\t\t|  节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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
	int num;//评委数
	int people = J->last;

	num = J->last;

	s = Find2(L);

	if (s == -1)
		printf("未找到选手信息。\n");
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

void Show1(Seqlist* L)
{
    int i;
	printf("已进入选手信息显示系统，即将显示全部选手的信息：\n");

	printf("\t\t|  节目类型  |   节目名称   |	电话号	| 成绩 |\n");

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

	printf("\t  进入自动排序系统");
	printf("\t  选择排名方法:\n1.从小到大\n2.从大到小\n");

	scanf("%d",&have);
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);

	printf("排序完成！\n");

	Show1(L);
}

void UI()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.进入选手信息系统--------|\n");
	printf("\t\t\t|------------2.进入评委信息系统--------|\n");
	printf("\t\t\t|------------0.退出系统----------------|\n");
}

void Menu(Seqlist* L, Judges* J)
{
	UI();//加载菜单
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("选择要进行的功能：");
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

		printf("选择要进行的功能：");
	}
}
