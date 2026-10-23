#include <stdio.h>
#include <string.h>
#define SIZE 5
struct job
{
 int jobID;
 char name[50];
};
struct job J[SIZE];
int rear = 0; 
int front = 0; 
int id = 1;
void enqueue(struct job J[SIZE], char name[50])
{
 
 if (rear == SIZE)
 {
 printf("Queue is full!\n");
 return;
 }
 strcpy(J[rear].name, name);
 J[rear].jobID = id++;
 printf("\nPrint job added\nid = %d and name = %s\n", J[rear].jobID,
J[rear].name);
 rear++;
}
void dequeue()
{
 
 if (front == rear)
 {
 printf("Queue is empty!\n");
 return;
 }
 int element = J[front].jobID;
 char elem[50];
 strcpy(elem, J[front].name);
 J[front].jobID = -1;
 J[front].name[0] = '\0';
 front++;
 printf("\nPrint job processed\nid = %d and name = %s\n", element, elem);
}
void display()
{
 if (front == rear)
 {
 printf("Queue is empty!\n");
 return;
 }
 printf("\nPending print jobs are:\n");
 for (int i = front; i < rear; i++)
 {
 printf("%d %s\n", J[i].jobID, J[i].name);
 }
}
int main()
{
 int choice;
 char name[50];
 do
 {
 printf("\n===== Printer Queue Manager (Linear Queue) =====\n");
 printf("1. Add a Print Job (Enqueue)\n");
 printf("2. Process a Print Job (Dequeue)\n");
 printf("3. Display All Pending Print Jobs\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 if (scanf("%d", &choice) != 1)
 {
 
 while (getchar() != '\n')
 ;
 printf("Invalid input! Please enter a number.\n");
 choice = 0;
 continue;
 }
 switch (choice)
 {
 case 1:
 printf("Enter job name: ");
 scanf(" %49[^\n]", name); 
 enqueue(J, name);
 display();
 break;
 case 2:
 dequeue();
 display();
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice! Please enter 1-4.\n");
 }
 } while (choice != 4);
 return 0;
}