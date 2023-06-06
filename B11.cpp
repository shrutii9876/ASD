#include<iostream>
using namespace std;
class node
{
	public:
	string word,mean;
	node *left, *right;
	node(string x, string y)
	{
		word=x;
		mean=y;
		left=NULL;
		right=NULL;
	}
	friend class Dict;
};
class Dict
{
	public:
		node *root, *q;
		Dict()
		{
			root=NULL;
			q=NULL;
		}
		void insert(node*,string,string);
		void d_asc(node*);
		void d_desc(node*);
		void cmp(node*,string);
		void update(node*,string);
		node* min(node*);
		void del(node*,string);
};
void Dict::insert(node* p, string key, string keym)
{
	if(key<p->word)
	{
		if(p->left!=NULL)
			insert(p->left,key,keym);
		else
			p->left=new node(key,keym);
	}
	else if(key>p->word)
	{
		if(p->right!=NULL)
			insert(p->right,key,keym);
		else
			p->right=new node(key,keym);
	}
}
void Dict::d_asc(node* p)
{
	if(p->left!=NULL)
		d_asc(p->left);
	cout<<"\n"<<p->word<<"->"<<p->mean;
	if(p->right!=NULL)
		d_asc(p->right);
}
void Dict::d_desc(node* p)
{
	if(p->right!=NULL)
		d_desc(p->right);
	cout<<"\n"<<p->word<<"->"<<p->mean;
	if(p->left!=NULL)
		d_desc(p->left);
}
void Dict::cmp(node* p,string key)
{
	static int count=0;
	while(p!=NULL)
	{
		if(key<p->word)
		{
			count++;
			p=p->left;
		}
		else if(key>p->word)
		{
			count++;
			p=p->right;
		}
		else if(key==p->word)
		{
			count++;
			cout<<"No. of cmp:"<<count;
			count=0;
			return;
		}
	}
	cout<<"Not found";
}
void Dict::update(node* p,string key)
{
	while(p!=NULL)
	{
		if(key<p->word)
			p=p->left;
		else if(key>p->word)
			p=p->right;
		else if(key==p->word)
		{
			cout<<"Enter new meaning:";
			cin>>p->mean;
			return;
		}
	}
	cout<<"Not found";
}
node* Dict::min(node* p)
{
	while(p->left!=NULL)
	{
		q=p;
		p=p->left;
	}
	return p;
}
void Dict::del(node* p,string key)
{
	node *s;
	while(p!=NULL)
	{
		if(key<p->word)
		{
			q=p;
			p=p->left;
		}
		else if(key>p->word)
		{
			q=p;
			p=p->right;
		}
		else if(key==p->word)
		{
			if(p->left==NULL && p->right==NULL)
			{
				if(q->left==p)
				{
					delete p;
					q->left=NULL;
					return;
				}
				if(q->right==p)
				{
					delete p;
					q->right=NULL;
					return;
				}
			}
			if(p->left!=NULL && p->right==NULL)
			{
				if(q->left==p)
				{
					q->left=p->left;
					delete p;
					return;
				}
				else if(q->right==p)
				{
					q->right=p->left;
					delete p;
					return;
				}
			}
			else if(p->left==NULL && p->right!=NULL)
			{
				if(q->left==p)
				{
					q->left=p->right;
					delete p;
					return;
				}
				else if(q->right==p)
				{
					q->right=p->right;
					delete p;
					return;
				}
			}
			else if(p->left!=NULL && p->right!=NULL)
			{
				s=min(p->right);
				p->word=s->word;
				p->mean=s->mean;
				del(s,s->word);
				return;
			}
		}
	}
	cout<<"Not found";
}
int main()
{
	int ch,n;
	string nword,nmean,sword;
	Dict d;
	do
	{
		cout<<"\n1.Insert 2.Asc 3.Desc 4.Search and cmp 5.Update 6.Delete 7.Exit";
		cout<<"\nEnter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter no. of words you want to insert:";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\nEnter word:";
					cin>>nword;
					cout<<"\nEnter meaning:";
					cin>>nmean;
					if(d.root==NULL)
						d.root=new node(nword,nmean);
					else
						d.insert(d.root,nword,nmean);
				}
				break;
			case 2:
				d.d_asc(d.root);
				break;
			case 3:
				d.d_desc(d.root);
				break;
			case 4:
				cout<<"Enter word:";
				cin>>sword;
				d.cmp(d.root,sword);
				break;
			case 5:
				cout<<"Enter word:";
				cin>>sword;
				d.update(d.root,sword);
				break;
			case 6:
				cout<<"Enter word:";
				cin>>sword;
				d.del(d.root,sword);
				break;
			
		}
	}while(ch!=7);
	return 0;
}
