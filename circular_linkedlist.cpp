#include<iostream>
#include<cstring>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
class CircularLinkedList
{
	Node* head;
	Node* pre=NULL;
	public:
		void create(int val)
		{
			Node* new_node=new Node;
			new_node->data=val;
			if(pre==NULL)
			{
				new_node->next=NULL;
				pre=new_node;
				head=new_node;
			}
			else
			{
				new_node->next=head;
				pre->next=new_node;
				pre=new_node;
			}
		}
		//PROGRAM 1
		void insert_begin(int d)
		{
			Node* temp=head;
			Node * new_node=new Node;
 			while(temp!=NULL)
			{
			if(temp->next==head)
			{
				new_node->next=head;
				break;
			}
			temp=temp->next;
			}
			new_node->data=d;
			temp->next=new_node;
			head=new_node;
		}
		//PROGRAM 2
		void insert(int p,int a)
		{
			Node* new_node=head;
			Node* new_node1=new Node;
			Node* temp;
			while(new_node->data!=p)
			{
				new_node=new_node->next;
			}
			new_node1->data=a;
			temp=new_node->next;
			new_node->next=new_node1;
			new_node1->next=temp;
		}
		//PROGRAM 3
		void insert_end(int d)
		{
			Node* temp=head;
			Node * new_node=new Node;
 			while(temp!=NULL)
			{
			if(temp->next==head)
			{
				new_node->next=head;
				break;
			}
			temp=temp->next;
			}
			new_node->data=d;
			temp->next=new_node;
		}
		//PROGRAM 4
		void delete_first()
		{
			Node* new_node=head;
			Node* pre=NULL;
			Node* temp=NULL;
			while(new_node!=NULL)
			{
				if(new_node->next==head)
				{
					temp=new_node;
					new_node=new_node->next;
					pre=new_node->next;
					delete new_node;
					break;
				}
				new_node=new_node->next;
			}
			temp->next=pre;
			head=pre;

		}
		//PROGRAM 5
		void delete_middle(int b)
		{
			Node* new_node=head;
			Node* pre=NULL;
			Node* temp=NULL;
			while(new_node!=NULL)
			{
				if(new_node->data==b)
				{
					temp=new_node->next;
					delete new_node;
					break;
				}
				pre=new_node;
				new_node=new_node->next;
			}
			pre->next=temp;
		}
		//PROGRAM 6
		void delete_end()
		{
			Node* new_node=head;
			Node* pre=NULL;
			while(new_node!=NULL)
			{
				pre=new_node;
				new_node=new_node->next;
				if(new_node->next==head)
				{
					delete new_node;
					break;
				}
			}
			pre->next=head;
		}
		//PROGRAM 7
		void search(int t)
		{
			int count=0;
			Node* new_node=head;
			do
			{
				new_node=new_node->next;
				if(new_node->data==t)
				{
					cout<<"Yes the element exists"<<endl;
					count++;
				}
			}
			while(new_node!=head);
			if(count==0)
			cout<<"Does not exists"<<endl;
		}
		//PROGRAM 8
		void display()
		{
			Node* new_node=head;
			do
			{
				cout<<new_node->data<<" ";
				new_node=new_node->next;
			}
			while(new_node!=head);
		}
};
int main()
{
	CircularLinkedList l;
	l.create(10);
	l.create(20);
	l.create(30);
	l.create(40);
	l.create(50);
	cout<<"The current circular linked list is"<<endl;
	l.display();
	int a;
	do
	{
		cout<<endl;
		cout<<"MENU : "<<endl;
		cout<<"1.INSERT AT THE BEGINNING OF THE LINKED LIST"<<endl;
		cout<<"2.INSERT ANYWHERE IN THE LINKED LIST"<<endl;
		cout<<"3.INSERT AT THE END OF THE LINKED LIST"<<endl;
		cout<<"4.DELETION OF A NODE AT THE BEGINNING"<<endl;
		cout<<"5.DELETION OF A SPECIFIC NODE"<<endl;
		cout<<"6.DELETION OF A NODE AT THE END"<<endl;
		cout<<"7.SEARCH A NODE"<<endl;
		cout<<"8.Display.\n9.Exit"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"Enter the choice:"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
				{
					int i;
					cout<<"Enter the element you want to insert:"<<endl;
					cin>>i;
					l.insert_begin(i);
				}
				break;
			case 2:
			{

				int i,j;
				cout<<"Enter the element you want to insert and after which element:"<<endl;
				cin>>i>>j;
				l.insert(j,i);

			}break;
			case 3:
				{
					int i;
					cout<<"Enter the element you want to insert:"<<endl;
					cin>>i;
					l.insert_end(i);
				}
				break;
			case 4:
				{
					l.delete_first();
				}
				break;
			case 5:
			{
				int i,j;
				cout<<"Enter the element you want to delete"<<endl;
				cin>>i;
				l.delete_middle(i);

			}break;
			case 6:
				{
					l.delete_end();
				}
				break;
			case 7:
			{
				int i;
				cout<<"Enter the element you want to search:"<<endl;
				cin>>i;
				l.search(i);
			}break;
			case 8:
			{
				l.display();

			}break;
			case 9:
				{
					exit(0);
				}
			default: cout<<"Invalid Choice"<<endl;
		}
	}
	while(a!=9);
}


