

Q.Write a menu driven program to perform following operations on strings: 
a) Show address of each character in string 
b) Concatenate two strings without using strcat function. 
c) Concatenate two strings using strcat function. 
d) Compare two strings 
e) Calculate length of the string (use pointers) 
f) Convert all lowercase characters to uppercase 
g) Convert all uppercase characters to lowercase 
h) Calculate number of vowels
 i) Reverse the string

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char str[20],str1[20],ch,*ptr;
  int i,j,count=0;

  do
{
  printf("\n****MENU****");
   printf("\n a) Show address of each character in string ");
  printf("\n  b) Concatenate two strings without using strcat function. ");
  printf("\n  c) Concatenate two strings using strcat function. ");
  printf("\n  d) Compare two strings :");
  printf("\n  e) Calculate length of the string (use pointers") ;
  printf("\n  f) Convert all lowercase characters to uppercase"); 
  printf("\n  g) Convert all uppercase characters to lowercase"); 
  printf("\n  h) Calculate number of vowels");
   printf("\n i) Reverse the string:"); 

  printf("\n  j):Exit");
  printf("\nEnter your choice(only lower case letter): ");
  scanf("%c",&ch);

  switch(ch)
{
  case 'a':
    printf("\nEnter the string: ");
  fflush(stdin);
    scanf("%s",&str);
   for(i=0;str[i]!='\0';i++)
    printf("\nThe positionof char is: %c address %u",str[i],&str[i]);
    break;

  case 'b':
			printf("\nEnter the first string: ");
  fflush(stdin);
			scanf("%s",&str);
			printf("\nEnter the second string: ");
			fflush(stdin);
			scanf("%s",&str1);
			while(str[i]!='\0')
	{
			i++;
			  while(str1[j]!='\0')
			  {
				str[i]=str1[j];
				j++;
				i++;
			  }
	
		  str[i]='\0';
	}
		  printf("\nConcatenated String is %s",str);
			break;
		  
		  
 case 'c':
			printf("\nEnter the first string: ");
 fflush(stdin);
			scanf("%s",&str);
			printf("\nEnter the second string: ");
			fflush(stdin);
			scanf("%s",&str1);
			strcat(str,str1);
			
		  str[i]='\0';
		  printf("\nConcatenated String is %s",str);

		   break;

  case 'd':
    printf("\nEnter the first string: ");
  fflush(stdin);
    scanf("%s",&str);
    printf("\nEnter the second string: ");
	fflush(stdin);
    scanf("%s",&str1);
    j=strcmp(str,str1);
    if(j==0)
  {
    printf("\nThe string is same");
  }
    else
  {
    printf("\nThe string is not same");
  }
    break;



  case 'e':
	 *ptr;
  count=0;
    printf("\nEnter the first string: ");
	fflush(stdin);
    scanf("%s",&str);
   ptr=str;
   while ( *ptr != '\0') 
	   {
        count++;
        ptr++;
    }

    printf("\nThe length of string is: %d",count);
    break;

 case 'f':
	 
    printf("\nEnter the lower case string: ");
	fflush(stdin);
    scanf("%s",&str);
	printf("\n upper String is %s",strupr(str));
	 break;
	 
	  case 'g':
	 
    printf("\nEnter the upper case string: ");
	fflush(stdin);
    scanf("%s",&str);
	printf("\n LOWER String is %s",strlwr(str));
	 break;

	  
case 'h':

count=0;
i=0;
  printf("Input a string\n");
  fflush(stdin);
  gets(str);
  while (str[i] != '\0')
	  {
    if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] =='o' || str[i]=='O' || str[i] == 'u' || str[i] == 'U')
      count++;
    i++;
  }
  printf("Number of vowels in the string: %d", count);
	
	 break;

case 'i':
  printf("Input a string\n");
fflush(stdin);
  gets(str);
  printf("\nthe reverse string is:%s",strrev(str));
  break;

 
  case 'j':
    exit(0);
    break;

}
}
  while(ch!=5);

return 0;
}
