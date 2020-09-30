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
    void print();
    void insert_beg();
    void insert_mid();
    void insert_end();
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
        case 3: break;
    }
    }while(ch!=3);

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
