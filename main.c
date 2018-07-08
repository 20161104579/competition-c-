#include "head.h"


int main()
{
	int flag;
	SeqList *L=(SeqList *)malloc(sizeof(SeqList));
	L->last = 0;
	load(L);


	while(menu(),printf("Ñ¡Ôñ¹¦ÄÜ£º"),scanf("%d",&flag)!=EOF)
	{
		switch(flag)
		{
			case 1: Add(L);break;
			case 2: Del(L);break;
			case 3: sortscore(L);break;
			case 4: Query(L);break;
			case 5: Change(L);break;
			case 6: Show(L);break;
			case 7: Insert(L);break;
			case 0:
				copydata(L);
				return 0;
		}

	}
	return 0;
}



