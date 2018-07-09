#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*
#ifndef HEAD
#define HEAD

extern "C" void CopyJ(JudgeIn* J);
extern "C" void LoadJ(JudgeIn* J);
extern "C" void CopyL(Seqlist* L);
extern "C" void LoadL(Seqlist* L);
#endif HEAD

*/



struct entertain{
    char name[20];
    char type[13];
    char phone[13];
    double score;
};

typedef struct entertain NodeEntertain;

typedef struct {
    NodeEntertain elem[100];
    int last;
}Seqlist;

struct Judges {
	char sex[2];
	char name[20];
	char phone[13];
};

typedef struct Judges Judgesnode;

typedef struct {
	Judgesnode elem[100];
	int last;
}JudgeIn;



void UI();
void Menu(Seqlist* L, JudgeIn* J);

void UIJ();
int FindJ(JudgeIn* J);
void MenuJ(JudgeIn* J);
void AddJ(JudgeIn* J);

void ShowJ(JudgeIn* J);
void QueryJ(JudgeIn* J);

void UIL();
int FindL(Seqlist* L);
void MenuL(Seqlist* L, JudgeIn* J);
void AddL(Seqlist* L);
void DelL(Seqlist* L);
void QueryL(Seqlist* L);
void ChangeL(Seqlist* L);
void ShowL(Seqlist* L);
void SortL(Seqlist* L);


void Grade(Seqlist* L, JudgeIn* J);


extern void CopyJ(JudgeIn* J);
extern void LoadJ(JudgeIn* J);
extern void CopyL(Seqlist* L);
extern void LoadL(Seqlist* L);
