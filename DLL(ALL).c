#include<stdio.h>
struct node{
  int val;
  struct node *prev, *next;
};
struct node *head = NULL , *tail = NULL;

int main(){
int choice, count = 1;
printf("1. Insert new node\n");
printf("2. Insert node at beginning\n");
printf("3. Insert node at any position\n");
printf("4. Delete node from last position\n");
printf("5. Delete node from beginning\n");
printf("6. Delete node from any position\n");
printf("7. Exit\n");
while(count==1){
printf("\n\nEnter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
    create();
    break;

case 2:
    beginning();
    break;

case 3:
    insert_random();
    break;

case 4:
    delete_last();
    break;

case 5:
    delete_first();
    break;

case 6:
    delete_random();
    break;

case 7:
    printf("The program has ended!!",count++);
    break;
default:
    printf("Error!! The option is not found!!\n\n");
   }
  }
return 0;
}
void create(){
struct node *curr;
int n,i,value;
printf("\n\nTotal numbers of elements: ");
scanf("%d",&n);
printf("Entering the elements: ");
for(i=0 ; i<n ;i++){
    scanf("%d",&value);
curr = (struct node*)malloc(sizeof(struct node));
curr -> val = value;
curr -> prev = NULL;
curr -> next = NULL;
if(head == NULL){
    head = curr;
    tail = curr;
   }
else{
    curr -> prev = tail;
    tail -> next = curr;
    tail = curr;
    }
  }
  print();
}

void print(){
struct node *curr;
 curr = head;
 printf("The elements are: ");
 while(curr != NULL){
    printf("%d <-> ",curr-> val);
    curr = curr -> next;
 }
printf("NULL");
}

void beginning(){
 struct node *curr, *check;
 check = head;
 if(check != NULL){
 int value;
   printf("\n\nEnter the value that you want to insert in the starting: ");
   scanf("%d",&value);
   curr = (struct node*)malloc(sizeof(struct node));
   curr -> val = value;
   curr -> prev = NULL;
   curr -> next = NULL;
if(head == NULL){
    head = curr;
    tail = curr;
   }
else{
    curr -> next = head;
    head -> prev = curr;
    head = curr;
 }
 updated();
 }
 else{
     printf("LINK LIST is empty!! Create it first!!\n");
     main();
     }
}


void insert_random(){
 struct node *curr , *temp1, *temp2, *check;
 check = head;
 if(check != NULL){
 int value,pos;

   printf("\n\nEnter the value that you want to insert: ");
   scanf("%d",&value);
   curr = (struct node*)malloc(sizeof(struct node));
   curr -> val = value;
   curr -> prev = NULL;
   curr -> next = NULL;
   printf("\nEnter the position that you want to insert: ");
   scanf("%d",&pos);

if(head == NULL){
    head = curr;
    tail = curr;
}
else{
      temp1 = head;
      for(int i = 1; i<=pos-1 ; i++){
        temp2 = temp1;
        temp1 = temp1 -> next;
      }
   temp2 -> next = curr;
   temp1 -> prev = curr;
   curr -> prev = temp2;
   curr -> next = temp1;
 }
 updated();
}
else{
     printf("LINK LIST is empty!! Create it first!!\n");
     main();
     }
}
void delete_last(){
struct node *temp;
//since we can access the 2nd last element using prev pointer
    if(head != NULL){
     temp = tail;
     tail = tail -> prev;
     tail -> next = NULL;
     free(temp);
     updated();
   }
 else{
     printf("LINK LIST is empty!! Create it first!!\n");
     main();
     }
}
void delete_first(){
 if(head != NULL){
    struct node *temp;
    temp = head;
    head = head -> next;
    head -> prev = NULL;
    free(temp);
    updated();
   }
 else{
     printf("LINK LIST is empty!! Create it first!!\n");
     main();
     }
}
// limitation only deletes the first element which matches the key
void delete_random(){
struct node *temp1,*temp2,*check;
check = head;
if(check != NULL){
int num;
printf("\nEnter the number you want to delete: ");
scanf("%d",&num);
if(head != NULL){
    temp1 = head;
    while(temp1 -> next != NULL && temp1->val != num){
        temp2 = temp1;
        temp1 = temp1 -> next;
    }
    if(temp1 ->val == num){
        temp2 -> next = temp1 -> next;
        temp1 -> next -> prev = temp2;
        free(temp1);
    }
    else
        printf("The value is not present in the list\n");
}
   updated();
}
else{
     printf("LINK LIST is empty!! Create it first!!\n");
     main();
    }
}

void updated(){
struct node *curr;
 curr = head;
 printf("The updated elements are: ");
 while(curr != NULL){
    printf("%d <-> ",curr-> val);
    curr = curr -> next;
 } printf("NULL");
}
