#include<stdio.h>
struct node{
  int val;
  struct node *next;
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
printf("7. Reversed Linked List\n");
printf("8. Remove Duplicate data from link list\n");
printf("9. Exit\n");
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
    reverse();
    break;

case 8:
    duplicate();
    break;
case 9:
    printf("The program is ended!!",count++);
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
curr -> next = NULL;
if(head == NULL){
    head = curr;
    tail = curr;
   }
else{
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
    printf("%d ",curr-> val);
    curr = curr -> next;
 }

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
   curr -> next = NULL;
if(head == NULL){
    head = curr;
    tail = curr;
   }
else{
    curr -> next = head;
    head = curr;
 }
 updated();
 }
 else{
     printf("LINK LIST is empty!! Create it first!!");
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
    curr -> next = temp1;
 }
 updated();
}
else{
     printf("LINK LIST is empty!! Create it first!!");
     main();
     }
}
void delete_last(){
struct node *curr,*temp;
    if(head != NULL){
    curr = head;
    while(curr -> next != NULL){
        temp = curr;
        curr = curr -> next;
    }
    temp -> next = NULL;
    free(curr);
     updated();
   }
 else{
     printf("LINK LIST is empty!! Create it first!!");
     main();
     }
}
void delete_first(){
 if(head != NULL){
    struct node *temp;
    temp = head;
    head = head -> next;
    free(temp);
    updated();
   }
 else{
            printf("LINK LIST is empty!! Create it first!!");
     main();
     }
}

void delete_random(){
struct node *curr,*temp,*check;
check = head;
if(check != NULL){
int num;
printf("\nEnter the number you want to delete: ");
scanf("%d",&num);
if(head != NULL){
    curr = head;
    while(curr -> next != NULL && curr ->val != num){
        temp = curr;
        curr = curr -> next;
    }
    if(curr ->val == num){
        temp -> next = curr -> next;
        free(curr);
    }

    else
        printf("The value is not present in the list\n");
}
   updated();
}
else{
     printf("LINK LIST is empty!! Create it first!!");
     main();
    }
}

void reverse(){
  struct node *prev_node, *curr_node,*check;
   check = head;
   if(check != NULL){
    prev_node = head;
    head = head->next;
    curr_node = head;
    prev_node->next = NULL;
    while(head!=NULL)
    {
        head = head->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = head;
    }
    head = prev_node;
    updated();
   }
else{
     printf("LINK LIST is empty!! Create it first!!");
     main();
     }
}


void duplicate(){
    struct node *temp, *temp1, *dupe,*check;
    check = head;
    if(check != NULL){
    temp = head;
    while (temp!=NULL&&temp->next != NULL)
    {
        temp1 = temp;

        while (temp1->next != NULL)
        {
            if (temp->val == temp1->next->val)
            {
                dupe = temp1->next;
                temp1->next = temp1->next->next;
                free(dupe);
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
    updated();
}
else{
     printf("LINK LIST is empty!! Create it first!!");
     main();
     }
}

void updated(){
struct node *curr;
 curr = head;
 printf("The updated elements are: ");
 while(curr != NULL){
    printf("%d ",curr-> val);
    curr = curr -> next;
 }
}


