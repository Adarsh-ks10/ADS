#include<stdio.h>
int main()
{
int a[5]={1,3,5,7,9};
int b[5]={2,4,6,8,10};
int c[10];
int i,j,k;
printf("\n first array:");
for(i=0;i<5;i++)
printf("%d",a[i]);
printf("\n second array:");
for(i=0;i<5;i++)
printf("%d",b[i]);
 i=0;
 j=0;
 k=0;
while(i<5 && j<5)
{
if(a[i] <b [j])
   c[k++] = a[i++];
else
   c[k++] = b[j++];
}
while(i<5)
   c[k++] = a[i++];
while(j<5)
   c[k++] = b[j++];
printf("\n merged array:");
for(i=0; i<10; i++)
printf("%d ", c[i]);
return 0;
}


 ____OUTPUT____

 first array:13579
 second array:246810
 merged array:1 2 3 4 5 6 7 8 9 10 