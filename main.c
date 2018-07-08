#include "head.h"


int main()
{
 	/*SeqList *L=(SeqList *)malloc(sizeof(SeqList));
	L->last = 0;
	JudgeIn *J=(JudgeIn*)malloc(sizeof(JudgeIn));
	J->last = 0;
    */
    Seqlist L;
    JudgeIn J;

    L.last=0;
    J.last=0;

	Menu(&L, &J);

	return 0;
}



