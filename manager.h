
#include <stdio.h>
typedef struct
{
	char name[20];
	char info[20];
	char weight[20];
	int price;
	int delivery;
}product;
int selectMenu();
void addProduct(product *p);
int readProduct(product p[], int a);
void updateProduct(product *p);
void deleteProduct(product *p);

