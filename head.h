#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct

struct entertain{
    char name[20];
    char type[13];
    char phone[13];
    double score;
};

typedef struct player NodePlayer;

struct Seqlist {
    NodePlayer elem[100];
    int last;
};

struct Judges {
	char sex;
	char name[20];
	char phone[20];
};

typedef struct Judge Judgesnode;

struct JudgeIn {
	Judgesnode elem[100];
	int last;
};
char* Trim(char & str);
void Menu(Seqlist* L, Judges* J);

void menu2(Judges* J);
void add(Judges* J);
void Copy2(Judges* J);
void Load2(Judges* J);
void Show(Judges* J);
void Query2(Judges* J);

void menu1(Seqlist* L, Judges* J);
void Add(Seqlist* L);
void Del(Seqlist* L);
void Query1(Seqlist* L);
void Change(Seqlist* L);
void Show1(Seqlist* L);
void Sort(Seqlist* L);
void Copy1(Seqlist* L);
void Load1(Seqlist* L);
void Grade(Seqlist* L, Judges* J);
