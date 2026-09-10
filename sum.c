  1 #include<stdio.h>
  2 int sum(int a[],int n)
  3 {
  4     int i,sum=0;
  5     for(i=0;i<n;i++)
  6     {
  7         sum=sum+a[i];
  8     }
  9     return sum;
 10 }
 11 int main()
 12 {
 13     int a[100],n,i,result;
 14 printf("enter number of elements:");
 15 scanf("%d",&n);
 16 printf("enter elements:\n");
 17 for(i=0;i<n;i++)
 18 {
 19     scanf("%d",&a[i]);
 20 }
 21 result=sum(a,n);
 22 printf("sum=%d",result);
 23 return 0;
 24 }



enter number of elements:3
enter elements:
2
3
4
sum=9