#include<iostream>
using namespace std;
class off
{
	int n, adj[10][10],i,j;
	string offices[10];
	public:
		 void input();
		 void display();
		 void prims();
};
void off::input()
{
	cout<<"Enter no. of offices:";
	cin>>n;
	cout<<"Name of offices: ";
	for(i=0;i<n;i++)
	{
		cin>>offices[i];
	}
	cout<<"Enter cost:";
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
			{
				adj[i][j]=0;
				continue;
			}
			cout<<"Enter the cost to connect "<<offices[i]<<" to "<<offices[j]<<":";
			cin>>adj[i][j];
			adj[j][i]=adj[i][j];
		}
	}
}
void off::display()
{
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<adj[i][j]<<"\t";
	}
}
void off::prims()
{
	int visit[n],index,count=n-1,mincost=0,cost=0;
	for(i=0;i<n;i++)
		visit[i]=0;
	cout<<"Shortest Path:";
	visit[0]=1;
	cout<<offices[0]<<"->";
	while(count--)
	{
	mincost=100;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(visit[i]==1&&adj[i][j]!=0&&adj[i][j]<mincost&&visit[j]==0)
			{
				mincost=adj[i][j];
				index=j;
			}
		}
	}
	visit[index]=1;
	cost=cost+mincost;
	cout<<offices[index]<<"->";
	}
	cout<<"End";
	cout<<"\nMin cost:"<<cost;
}
int main () {
    off o1;
    int choice;
    do {
        cout << "\n\nMINIMUM SPANNING TREE"
             << "\n1. Input data"
             << "\t2. Display data"
             << "\t3. Calculate minimum cost"
             <<"\t4. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o1.input ();
                break;
            case 2:
                o1.display ();
                break;
            case 3:
                o1.prims ();
                break;
            case 4:
                exit(0);
        }
    } while (choice != 4);
    return 0;
}

