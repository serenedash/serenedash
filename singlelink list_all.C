#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertbeg(struct link *);
void insertend(struct link *node);
void insertposi(struct link *node);
void insertafter(struct link *node);
void deletebegin(struct link *node);
void deletelast(struct link *node);
void deleteafter(struct link *node);
void deleteposition(struct link *node);
void sort(struct link *node);
void search(struct link *node);
void creat(struct link *);
void  display(struct link *);
int count(struct link *node);

struct link
{
int data;
struct link *next;
};
struct link *node,*start;

int main()
{
int choce;
int data;
//clrscr();
node=(struct link*)malloc(sizeof(struct link));
if(node==NULL)
{
printf("momery con't create:");
exit(0);
}
start=node;
creat(node);
//clrscr();
while(1)
{
printf("\n 1  choose for insert at beginning node:\n");
printf("2  choose for insert at end node:\n");
printf("3  choose for insert at any position:\n");
printf("4  choose for insert after values:\n");
printf("5 choose for deleting node beginning:\n");
printf("6  choose for deleting node end:\n");
printf("7  choose for deleting at any position:\n");
printf("8  choose for deleting after values:\n");
printf("9 choose for  display node:\n");
printf("10  choose for sorting:\n");
printf("11  choose for reverse linklist:\n");
printf("12  choose for searching:\n");
printf("13  choose for counting node:\n");
printf("14  choose for exit:\n");

printf("\n enter your choice");
scanf("%d",&choce);
switch(choce)
{
case 1:
insertbeg(node);
break;
case 2:
insertend(node);
break;
case 3:
insertposi(node);
break;
case 4:
insertafter(node);
break;
case 5:
deletebegin(node);
break;
case 6:
deletelast(node);
break;
case 7:
deleteposition(node);
break;
case 8:
deleteafter(node);
break;
case 9:
display(node);
break;
case 10:
sort(node);
break;
case 12:
search(node);
break;
case 13:
count(node);
break;
case 14:
exit(0);
default:
printf("\n enter between 1to14:");

}
}
//getch();
return 0;
}//end main
void creat(struct link *node)
{
char ch='y';
printf("enter the data:");
scanf("%d",&node->data);
node->next=NULL;
printf("do u want to continue(y/n?)");
fflush(stdin);
scanf("%c",&ch);
while(ch=='y')
{
node->next= (struct link*)malloc(sizeof(struct link));
node=node->next;
 printf("renter the data:");
scanf("%d",&node->data);
node->next=NULL;
printf("do u want to continue(y/n?)");
fflush(stdin);
scanf("%c",&ch);
}
}
void  display(struct link *start)
 {
while(start!=NULL)
{
printf("\n%d",start->data);
start=start->next;
}
}
//insert node begin of linklist
void insertbeg(struct link *node)
{
 struct link *new1;
 new1=(struct link*)malloc(sizeof(struct link));
printf("\n enter the data in newnode:");
scanf("%d",&new1->data);
new1->next=node;
node=new1;
display(node);
}
    //insert node at end
     void insertend(struct link *node)
{
 struct link *enew1;
 while(node->next!=NULL)
 node=node->next;
 enew1=(struct link*)malloc(sizeof(struct link));
printf("\n  enter the data in newnode:");
scanf("%d",&enew1->data);
enew1->next=NULL;
node->next=enew1;
display(node);
}

void insertposi(struct link *node)
{
int pos,c=0,i=1;
struct link *curr,*prev;
printf("\n enter the position:");
scanf("%d",&pos);
c=count(node);
if(pos>c)
{
printf("\n position more than nodes:");
return;
}
curr=(struct link*)malloc(sizeof(struct link));
while(i<pos)
{
prev=node;
node=node->next;
i++;
}
printf("\nenter the node values:");
scanf("%d",&curr->data);

if(pos==1)
{
node=curr;
curr->next=node;
}
else
prev->next=curr;
curr->next=node;
display(node);
}
//counting node
int count(struct link *node)
{
int i=0;
while(node!=NULL)
{
i++;
node=node->next;
}
printf("count=%d",i);
return i;
}
// insert after node valu
void insertafter(struct link *node)
{
int no;
struct link *new1;
printf("\n enter the node value after which node wii be insert:");
scanf("%d",&no);
while(node!=NULL)
{
if(no==node->data)
break;
node=node->next;
}
if(node==NULL)
{
printf("%dis not in to list",node);
return;
}
new1=(struct link*)malloc(sizeof(struct link));
if(new1==NULL)
{
printf("out of memory");
exit(0);
}
printf("enter the value to be insert:");
scanf("%d",&new1->data);
new1->next=node->next;
node->next=new1;
}
//delete 1st node
void deletebegin(struct link *node)
{
struct link *temp;
temp=node;
if(node==NULL)
{
printf("underflow:");
exit(0);
}
node=node->next;
free(temp);
start=node;
}
//delete last node
void deletelast(struct link *node)
{
struct link *prev;

if(node==NULL)
{
printf("underflow:");
exit(0);
}
while(node->next!=NULL)
{
prev=node;
node=node->next;
}
prev->next=NULL;
//free(node);
start=node;
}
//deleting node by position
void deleteposition(struct link *node)
{
int pos, c=0,i=1;
struct link *prev;
if(node==NULL)
{
printf("\n list is empty:");
exit(0);
}
printf("enter the position to delete:");
scanf("%d",&pos);
c=count(node);
if(c==1)
node=NULL;
if(pos>c)
{
printf("\n%d position is not in the list",pos);
return;
}
while(i<pos)
{
prev=node;
node=node->next;
i++;
}
if(pos==1)
start=node->next;
else
prev->next=node->next;
free(node);
}
//deleting node after value
void deleteafter(struct link *node)
{
 int no;
struct link *curr;
printf("\n enter the node value after which node wii be insert:");
scanf("%d",&no);
while(node!=NULL)
{
if(no==node->data)
break;
node=node->next;
}
if(node==NULL)
{
printf("%dis not in to list",node);
exit(0);
}
curr=node->next;
node->next=curr->next;
free(curr);
}
//sorting link list
void sort(struct link *node)
{
	struct link *i,*j;
	int c;
	for(i=node;i->next!=NULL;i=i->next)
	{
	for(j=i->next;j!=NULL;j=j->next)
	{
	if(i->data>j->data)
	{
	c=i->data;
	i->data=j->data;
	j->data=c;
	}
	}
	}
}
//search a node
void search(struct link *node)
{
int i=1,data;
printf("enter the data for search:");
scanf("%d",&data);
while(node!=NULL)
{
if(node->data==data)
{
printf("%dfound at %d position",data,i);
return;
}
i++;
node=node->next;
}
printf("%dis not presentint he list:",data);
}