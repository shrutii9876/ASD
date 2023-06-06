#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
struct node
{	
	int roll;
	char div;
	char name[10],addr[10];
};
class student
{
	node x;
	int i;
	public:
		void create();
		void display();
		void del();
		void insert();
		int search();
		void get();
		void put();
};
void student::get()
{
	cout<<"Roll:";
	cin>>x.roll;
	cout<<"Name:";
	cin>>x.name;
	cout<<"Div:";
	cin>>x.div;
	cout<<"Addr:";
	cin>>x.addr;
}
void student::put()
{
	cout<<"Roll:"<<x.roll;
	cout<<"Name:"<<x.name;
	cout<<"Div:"<<x.div;
	cout<<"Addr:"<<x.addr;
}
void student::create()
{
	fstream f;
	int n;
	cout<<"Enter no. of records:";
	cin>>n;
	f.open("stud.txt",ios::out);
	for(i=0;i<n;i++)
	{
		get();
		f.write((char*)&x,sizeof(x));
	}
	cout<<"Record created successfully";
	f.close();
}
void student::display()
{
	fstream f;
	f.open("stud.txt",ios::in);
	cout<<"\n";
	while(f.read((char*)&x,sizeof(x)))
	{
		put();
	}
	f.close();
}
void student::insert()
{
	fstream f;
	f.open("stud.txt",ios::app|ios::out);
	get();
	f.write((char*)&x,sizeof(x));
	cout<<"Success";
	f.close();
}
int student::search()
{
	int key,flag=0;
	cout<<"Enter roll to search:";
	cin>>key;
	fstream f;
	f.open("stud.txt",ios::in);
	while(f.read((char*)&x,sizeof(x)))
	{
		if(x.roll==key)
		{
			cout<<"Record found";
			put();
			flag=1;
			f.close();
		}
	}
	return flag;
}
void student::del()
{
	int key;
	cout<<"Enter roll to delete:";
	cin>>key;
	fstream f1,f2;
	f1.open("stud.txt",ios::in);
	f2.open("temp.txt",ios::out);
	while(f1.read((char*)&x,sizeof(x)))
	{
		if(x.roll!=key)
		{
			f2.write((char*)&x,sizeof(x));
		}
		f1.close();
		f2.close();
		remove("stud.txt");
		rename("temp.txt","stud.txt");
	}
	cout<<"Success";
}
int main()
{
	student s;
	int ch,fl;
	do
	{
		cout<<"\n1.Create 2.Display 3.Insert 4.Search 5.Delete";
		cout<<"\nChoice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.create();
				break;
			case 2:
				s.display();
				break;
			case 3:
				s.insert();
				break;
			case 4:
				fl=s.search();
				if(fl==0)
					cout<<"Record not found";
				break;
			case 5:
				s.del();
				break;
		}
	}while(ch!=6);
	return 0;
}
