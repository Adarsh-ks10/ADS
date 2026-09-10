 1 #include<stdio.h>
  2 void swap(int*a,int*b)
  3 {
  4     int temp;
  5     temp=*a;
  6     *a=*b;
  7     *b=temp;
  8 }
  9 int main()
 10 {
 11     int a,b;
 12 printf("enter first number:");
 13 scanf("%d",&a);
 14 printf("enter second number:");
 15 scanf("%d",&b);
 16 printf("before swapping:a=%d,b=%d\n",a,b);
 17 swap(&a,&b);
 18 printf("after swapping:a=%d,b=%d\n",a,b);
 19 return 0;
 20 }
 21
