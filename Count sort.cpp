#include<iostream>
using namespace std;

void count_sort(int a[], int k, int n)
{
	int c[k+1], i, j, b[n+1];
	for(i=0;i<=k;i++)
		c[i]=0;
	for(j=0;j<n;j++)
		c[a[j]]=c[a[j]]+1;
	for(i=1;i<=k;i++)
		c[i]=c[i]+c[i-1];
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
	cout<<"\n Sorted array: ";
	for(i=1;i<n+1;i++)
		cout<<b[i]<<" ";
}
int main()
{
	int n, *a, k;
	cout<<"\n Enter size of array: ";
	cin>>n;
	cout<<"\n Enter range(k): ";
	cin>>k;
	a=new int[n];
	cout<<"\n Enter array elements(0 to k): ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	count_sort(a,k,n);
	return 0;
}
