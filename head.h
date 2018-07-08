#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



struct student{
	double num;
	char name[20];
	int score[3];
	int sum;
};

typedef struct student ElemType;
typedef struct
{
	ElemType  elem[100];
	int       last;
}SeqList;

void Query(SeqList* L);
void Add(SeqList* L);
void menu();
void Change(SeqList *L);
void Insert(SeqList* L);
void quicksort(SeqList* L, int left, int right);
void sortscore(SeqList* L);
void Show(SeqList *L);
int Find(SeqList* L);
void load(SeqList* L);
void copydata(SeqList* L);
void Del(SeqList* L);

