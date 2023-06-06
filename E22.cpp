#include<iostream>
using namespace std;
class hp
{
	public:
		int n;
		int *minheap,*maxheap;
		void get();
		void d_min()
		{
			cout<<"\nMinimum marks are:"<<minheap[0];
		}
		void d_max()
		{
			cout<<"\nMaximum marks are:"<<maxheap[0];
		}
		void upadjust(bool,int);
};
void hp::get()
{
	int k;
	cout<<"Enter no. of students:";
	cin>>n;
	minheap=new int[n];
	maxheap=new int[n];
	cout<<"Enter marks:";
	for(int i=0;i<n;i++)
	{
		cin>>k;
		minheap[i]=k;
		upadjust(0,i);
		maxheap[i]=k;
		upadjust(1,i);
	}
}
void hp::upadjust(bool m,int i)
{
	int s;
	if(!m)
	{
		while(minheap[(i-1)/2]>minheap[i])
		{
			s=minheap[i];
			minheap[i]=minheap[(i-1)/2];
			minheap[(i-1)/2]=s;
			i=(i-1)/2;
			if(i==-1)
				break;
		}
	}
	else
	{
		while(maxheap[(i-1)/2]<maxheap[i])
		{
			s=maxheap[i];
			maxheap[i]=maxheap[(i-1)/2];
			maxheap[(i-1)/2]=s;
			i=(i-1)/2;
			if(i==-1)
				break;
		}
	}
}
int main()
{
	hp h;
	h.get();
	h.d_min();
	h.d_max();
	return 0;
}
