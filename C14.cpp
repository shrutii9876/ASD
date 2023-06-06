#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
	string name;
	int time;
};
class adjmat
{
	int m[10][10],i,j,n;
	node *temp=NULL;
	string v[20];
	char ch;
	public:
		void getgraph();
		void displaym();
};
void adjmat::getgraph()
{
	cout<<"\nEnter no. of cities: ";
	cin>>n;
	cout<<"\nEnter name of cities: ";
	for(i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\nIs there a path between "<<v[i]<<" and "<<v[j]<<" y or n?";
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nEnter time to travel:";
				cin>>m[i][j];
			}
			else if(ch=='n')
				m[i][j]=0;
			else
			cout<<"unknown entry";
		}
	}
}
void adjmat::displaym()
{
	cout<<"\n";
	for(j=0;j<n;j++)
	{
		cout<<"\t"<<v[j];
	}
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<v[i];
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<m[i][j];
		}
		cout<<"\n";
	}
}
   
int main()
{  int m;   
   adjmat a;

   while(1)
   {
   cout<<"\n 1.enter graph";
   cout<<"\n 2.display adjacency matrix for cities";
   cout<<"\n 3.exit";
   cout<<"\n\n enter the choice:";
   cin>>m;
  
        switch(m)
       {            case 1: a.getgraph();
                                    break;
                    case 2: a.displaym();
                                   break;
                    case 3: exit(0);
                
                    default:  cout<<"\n unknown choice";
         }
    }
    return 0;
}
