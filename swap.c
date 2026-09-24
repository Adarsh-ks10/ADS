#include<stdio.h>
void swap(int*a,int*b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
int main()
{
   int a,b;
printf("enter first number:");
scanf("%d",&a);
printf("enter second number:");
scanf("%d",&b);
printf("before swapping:a=%d,b=%d\n",a,b);
swap(&a,&b);
printf("after swapping:a=%d,b=%d\n",a,b);
return 0;
}

__OUTPUT__

enter first number:22
enter second number:33
before swapping:a=22,b=33
after swapping:a=33,b=22
