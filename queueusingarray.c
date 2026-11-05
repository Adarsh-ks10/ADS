#include <stdio.h>
#include <stdlib.h>
int main()
{
int i, n, v, ch;
printf("Enter size: ");
scanf("%d", &n);
if (n < 1)
{
printf("Invalid size\n");
return 0;
}
int q[n];
int f = -1, r = -1;
while (1)
{
printf("\nMenu\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
printf("4. Exit\n");

printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) 
{
case 1:
if (r == n - 1) 
{
printf("Queue is full\n");
} 
else 
{
printf("Enter element to be inserted: ");
scanf("%d", &v);
r++;
q[r] = v;
if (f == -1) 
{
f = 0;
 }
}
break;

case 2:
if (f == -1 || f > r) {
printf("Empty queue\n");
}
else
{
printf("Deleted %d\n", q[f]);
f++;
if (f > r) 
{
f = r = -1;
 }
}
break;

case 3:
if (f == -1 || f > r) 
{
printf("Queue empty\n");
}
else
{
for (i = f; i <= r; i++) 
{
printf("%d\t", q[i]);
}
printf("\n");
}
break;

case 4:
exit(0);
default:
printf("Invalid choice\n");
 }
}
return 0;
}


---OUTPUT---

Enter size: 3

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to be inserted: 30

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to be inserted: 50

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to be inserted: 10

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
30      50      10

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Deleted 30

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
50      10

Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting
