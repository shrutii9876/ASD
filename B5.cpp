#include <iostream>
#include <string>
using namespace std;
struct node
{
	string label;
	int count;
	node *child[50];
}*root;
class Book
{
	public:
	Book()
	{
		root==NULL;
	}
	void insert();
	void display();
};
void Book::insert()
{
	root=new node();
	cout<<"\nEnter name of the book:";
	getline(cin>>ws,root->label);
	cout<<"\nEnter total no. of chapters:";
	cin>>root->count;
	for(int i=0;i<root->count;i++)
	{
		root->child[i]=new node();
		cout<<"\nName of the chapter "<<i+1<<":";
		getline(cin>>ws,root->child[i]->label);
		cout<<"\nEnter total no. of sections:";
		cin>>root->child[i]->count;
		for(int j=0;j<root->child[i]->count;j++)
		{
			root->child[i]->child[j]=new node();
			cout<<"\nName of the section "<<i+1<<"."<<j+1<<":";
			getline(cin>>ws,root->child[i]->child[j]->label);
			cout<<"\nEnter total no. of sub sections:";
			cin>>root->child[i]->child[j]->count;
			for(int k=0;k<root->child[i]->child[j]->count;k++)
			{
				root->child[i]->child[j]->child[k]=new node();
				cout<<"\nName of the sub section "<<i+1<<"."<<j+1<<"."<<k+1<<":";
				getline(cin>>ws,root->child[i]->child[j]->child[k]->label);
			}
		}
	}
}
void Book::display()
{
	if(root!=NULL)
	{
		cout<<"Book Hierarchy:";
		cout<<"Book Name: "<<root->label<<"\n";
		for(int i=0;i<root->count;i++)
		{
			cout<<"->"<<root->child[i]->label<<"\n";
			for(int j=0;j<root->child[i]->count;j++)
			{
				cout<<"-->"<<root->child[i]->child[j]->label<<"\n";
				for(int k=0;k<root->child[i]->child[j]->count;k++)
				{
					cout<<"--->"<<root->child[i]->child[j]->child[k]->label<<"\n";
				}
			}
		}
	}
}
int main()
{
	Book b;
	int ch;
	do
	{
		cout<<"\n1.Insert 2.Display 3.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:b.insert();
					break;
			case 2:b.display();
					break;
			case 3:exit(0);
		}
	}while(ch<3);
	return 0;
}

