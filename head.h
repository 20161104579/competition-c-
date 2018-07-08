#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct entertain{
    char name[20];
    char type[13];
    char phone[13];
    double score;
};

typedef struct entertain NodeEntertain;

struct Seqlist {
    NodeEntertain elem[100];
    int last;
};

struct Judges {
	char sex;
	char name[20];
	char phone[13];
};

typedef struct Judges Judgesnode;

struct JudgeIn {
	Judgesnode elem[100];
	int last;
};

void Menu(Seqlist* L, JudgeIn* J);

void menu2(JudgeIn* J);
void add(JudgeIn* J);
void Copy2(JudgeIn* J);
void Load2(JudgeIn* J);
void Show(JudgeIn* J);
void Query2(JudgeIn* J);

void menu1(Seqlist* L, JudgeIn* J);
void Add(Seqlist* L);
void Del(Seqlist* L);
void Query1(Seqlist* L);
void Change(Seqlist* L);
void Show1(Seqlist* L);
void Sort(Seqlist* L);
void Copy1(Seqlist* L);
void Load1(Seqlist* L);
void Grade(Seqlist* L, Judges* J);
