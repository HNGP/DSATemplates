#include<stdio.h>


void insert(struct node **head, int item)
{
    
   struct node *ptr = (struct node *) malloc(sizeof(struct node));
   struct node *temp;
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
          
   }
   else
   {
       
        ptr->data=item;
       if(*head == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           *head = ptr;
       }
       else
       {
          temp = *head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
       }
   }
}

void node_swap(struct node *left, struct node *right)
{
  struct node *tmp;
  tmp = left->prev;
  if (tmp)
      tmp->next = right;
  right->prev = tmp;

  left->prev = right;
  left->next = right->next;
  right->next = left;
  if(left->next != NULL)
      left->next->prev = left;
}

void display(struct node **head)
{
    if(*head==NULL)
    {
        return;
    }
    struct node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node* getnode( struct node **head,int k)
{
    struct node *temp = *head;
    int i = 0;
    for (i = 0; i < (k - 1); i++)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    int n;
    struct node *head;
    head=NULL;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        insert(&head,temp);
    }
    int k;
    printf("k=");
    scanf("%d", k);
    struct node *left = getnode(&head, k);
    struct node *right = getnode(&head, k + 1);
    node_swap(left, right);
    display(&head);
    return 0;
}