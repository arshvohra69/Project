#include<stdio.h>
#include<stdlib.h>
struct LL
{
    int item;
    struct ll *next;
}*head=NULL;
typedef struct LL node;
    int ch;
    void insert();
    void count();
    void print();
    void insert_beg();
    void insert_mid();
    void insert_end();
    void delete();
    void delete_beg();
    void delete_mid();
    void delete_end();
int main()
{

    do{
    printf("Enter your choice\n");
    printf("1 means insert\n2 means print\n3 means count\n4 means delete an element\nElse invalid choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insert();
        break;
        case 2: print();
        break;
        case 3: count();
        break;
        case 4: delete();
        break;
        case 5: break;
    }
    }while(ch!=5);

}
void insert()
{
    if(head==NULL)
    {
        printf("LL empty, enter first element\n");
        head=(node *)malloc(sizeof(node));
        scanf("%d",&head->item);
        head->next=NULL;
    }
    else
    {
        int c;
        printf("ENTER CHOICE\n1 means insert at beginning\n2 means insert at middle\n3 means insert at end");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert_beg();
            break;
            case 2: insert_mid();
            break;
            case 3: insert_end();
            break;
            default: printf("Invalid choice\n");
        }
    }
}
void insert_beg()
{
    node *r;
    r=(node *)malloc(sizeof(node));
    printf("Enter the value\n");
    scanf("%d",&r->item);
    r->next=head;
    head=r;
}
void insert_mid()
{
    node *p,*q;
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    q=head;
    for(int i=1;i<pos;i++)
    {
        q = q->next;
    }
    p = (node *)malloc(sizeof(node));
    scanf("%d",&p->item);
    p->next = q->next;
    q->next = p->next;
}
void insert_end()
{
    node *r,*q;
    r = head;
    while(r->next!=NULL)
    r= r->next;
    q=(node *)malloc(sizeof(node));
    scanf("%d",&q->item);
    q->next=NULL;
    r->next=q;
}
void print()
{
    node *r;
    r = head;
    while(r!=NULL)
    {
        printf("%d\n", r->item);
        r=r->next;
    }
}
void count()
{
    int count=0;
    node *r;
    r = head;
    while(r!=NULL)
    {
        count++;
        r=r->next;
    }
    printf("%d\n",count);
}
void delete()
{
    int ch;
    printf("Enter 1 for delete from beginning, 2 for delete from middle or 3 for delete from end\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: delete_beg();
        break;
        case 2: delete_mid();
        break;
        case 3: delete_end();
        break;
        default: printf("Invalid choice, enter 1,2 or 3\n");
    }
}
 void delete_beg()
 {
     node *p;
     p=head;
     head=head->next;
     free(p);
 }
 void delete_mid()
 {
     int pos;
     printf("Enter the position which you want to clear\n");
     scanf("%d",&pos);
     node *ptr,*q;
     ptr=head;
     for(int i=1;i<pos-1;i++)
        ptr=ptr->next;
     q=ptr->next;
     ptr->next=q->next;
     free(q);
 }
 void delete_end()
 {
     node *q,*p;
     q=head;
     p= q->next;
     while(p->next != NULL)
       {
         q=q->next;
       }
     free(p);
     p=NULL;
 }
