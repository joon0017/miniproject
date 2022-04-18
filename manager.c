#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int selectMenu(){
	int menu;
	printf("***Menu***\n");
	printf("1. View product\n");
	printf("2. Add product\n");
	printf("3. Update product\n");
	printf("4. Delete product\n");
	printf("5. Save file\n");
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
char* retreiveProduct(product p[],int a){
	char *rt = (char*) malloc((1024)*sizeof(char));
	for (int i = 0; i < a; i++)
	{
		if (p[i].name[0] == '\0') continue; //check for empty
		strcat(rt,"\n****************************\n");
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


// load filedata in buf.
// You should set a filesize in advance.
long int load_file(char *filename, char *buf, long int fsize)
{
 FILE *fp;
 long int rwsize = 0;
 fp = fopen(filename,"rb");
 if(fp==NULL) return -1;
 
 rwsize = fread(buf,1,fsize,fp);
 
 if(rwsize<=0){
  fclose(fp);
  return -1;
 }
 fclose(fp);
 return rwsize;
}

// save file.
long int save_file(char *filename, char *buf, long int datasize)
{
 FILE *fp;
 long int rwsize = 0;
 fp = fopen(filename,"wb");
 if(fp==NULL) return -1;
 
 rwsize = fwrite(buf,1,datasize,fp);
 
 if(rwsize<=0){
  fclose(fp);
  return -1;
 }
 fclose(fp);
 return rwsize;
}
long int get_file_length(char *filename)
{
 long int length = 0;
 FILE *fp;
 fp = fopen(filename,"rb");
 if( fp == NULL ) return -1;
 fseek(fp,0,2);
 length = ftell(fp);
 fclose(fp);
 return length;
}