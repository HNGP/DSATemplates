#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *head;

struct Node *GetNewNode (int x)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}


void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

void Print ()
{
  struct Node* temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void InsertAlterSum ()
{
  
  struct Node* temp = head;
  while (temp->next!= NULL)
    {
      int sum = 0;
      sum = temp->next->data + temp->data;
      struct Node *sumNode = GetNewNode(sum);

      sumNode->next = temp->next;
      temp->next = sumNode;
      sumNode->prev = temp;
      temp = temp->next->next;
    }

}




int main ()
{

  head = NULL;
  int n;
  int data;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&data);
    InsertAtTail(data);
  }
  InsertAlterSum();
  Print();
  

}