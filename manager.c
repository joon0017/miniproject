#include <stdio.h>
#include "manager.h"


int selectMenu(){
	int menu;
	printf("***Menu***\n");
	printf("1. View product\n");
	printf("2. Add product\n");
	printf("3. Update product\n");
	printf("4. Delete product\n");
	printf("Choose option: ");
	scanf("%d",&menu);
	return menu;
}


int readProduct(product p[],int a){
	for (int i = 0; i < a; i++)
	{
		if (p[i].name[0] == '\0') continue; //check for empty
		printf("\n****************************\n");
		printf("%d)\n",i+1);
		printf("%s %s\n",p[i].name,p[i].weight);
		printf("%s \n",p[i].info);
		printf("%d원\n",p[i].price);
		printf("Delivery: %d\n",p[i].delivery);
	}
	
	printf("\n****************************\n\n");
	return 0;
}
void addProduct(product *p)
{
	printf("\nName? ");
	getchar();
	fgets(p->name,sizeof(p->name),stdin);
	printf("Info? ");
	getchar();
	fgets(p->info,sizeof(p->info),stdin);
	printf("weight? ");
	scanf("%s",p->weight);
	printf("Price? ");
	scanf("%d",&p->price);
	printf("Delivery? ");
	scanf("%d",&p->delivery);
	printf("\nAdded!\n\n");
}
void updateProduct(product *p)
{

	printf("Name? ");
	getchar();
	fgets(p->name,sizeof(p->name),stdin);
	printf("Info? ");
	fgets(p->info,sizeof(p->info),stdin);
	printf("weight? ");
	scanf("%s",p->weight);
	printf("Price? ");
	scanf("%d",&p->price);
	printf("Delivery(0 or 1)? ");
	scanf("%d",&p->delivery);
	printf("\nUpdate complete!\n\n");
}
void deleteProduct(product *p)
{
	p->name[0] = '\0';
	p->info[0] = '\0';
	p->weight[0] = '\0';
	printf("\nDeleted!\n\n");
}
