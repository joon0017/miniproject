#include <stdio.h>
#include "manager.h"

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int main()
{
	product p[20];
	int menu;
	int curSize=0;
	while(1)
	{
		menu = selectMenu();
		if (menu==1)
		{
			DPRINT(printf("\n reading menu template"););
			readProduct(p,curSize);
		}
		else if (menu==2)
		{
			addProduct(&p[curSize]);
			DPRINT(printf("\nsuccessfully added"););
			curSize++;
		}
		else if (menu == 3)
		{
			readProduct(p,curSize);
			printf("\n번호는 (취소: 0)? ");
			int a;
			scanf("%d",&a);
			if (a==0) continue;
			updateProduct(&p[a-1]);
			DPRINT(printf("\nupdate complete on list index %d",a-1););
		}
		else if (menu == 4)
		{
			readProduct(p,curSize);
			printf("\n번호는 (취소: 0)? ");
			int a;
			scanf("%d",&a);
			if (a==0) continue;
			int b;
			printf("\n정말로 삭제하시겠습니까? (삭제: 1)? ");
			scanf("%d",&b);
			if (b==1) deleteProduct(&p[a-1]); DPRINT(printf("\nSuccessfully deleted"););

		}
		else break;
	}
	printf("\n\n Exiting CRUD...\n");
	return 0;
}	