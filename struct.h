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
