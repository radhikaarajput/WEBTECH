#include<iostream>
#include<cmath>
using namespace std;
int compare=0;
void max_heapify(int a[], int i, int n)
{

	int l=2*i+1, largest, temp;
	int r=2*i+2;
	if(l<n && a[l]>a[i])
		largest=l;
	else
		largest=i;
	compare+=2;
	if(r<n && a[r]>a[largest])
		largest=r;
	compare+=2;
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		max_heapify(a,largest,n);
	}
	compare++;
}
void build_max_heap(int a[], int n)
{
	int x=floor(n/2), temp;
	for(int i=x;i>=0;i--)
	{
		max_heapify(a,i,n);
	}
}
void heapsort(int a[],int n)
{
	build_max_heap(a,n);
	int temp, t;
	for(int i=n-1;i>=1;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		max_heapify(a,0,i);
	}
	cout<<"\n Number of Comparisons: "<<compare<<endl;	
}
int main()
{
	int n, *a, i;
	cout<<"\n Enter size of array: ";
	cin>>n;
	cout<<"\n Enter elements: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	heapsort(a,n);
	cout<<"\n Sorted Array: ";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
