  1 #include<stdio.h>
  2 int factorial(int n)
  3 {
  4 int i,f=1;
  5 for(i=1;i<=n;i++)
  6 {
  7    f=f*i;
  8 }
  9 return f;
 10 }
 11 int main()
 12 {
 13 int n,result;
 14 printf("enter number:");
 15 scanf("%d",&n);
 16 result=factorial(n);
 17 printf("factorial = %d ",result);
 18 return 0;
 19 }


enter number:4
factorial = 24 