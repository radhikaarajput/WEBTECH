#include<iostream>
#include<cmath>
using namespace std;
int compare=0;

void merge(int a[], int p, int q, int r)
{
	int n1=q-p+1, i, j, k;
	int n2=r-q;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[p+i];
	for(j=0;j<n2;j++)
		R[j]=a[q+1+j];
	i=j=0;
	k=p;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
		compare++;
	}
	while(i<n1)
		a[k++]=L[i++];
	while(j<n2)
		a[k++]=R[j++];
}
void mergesort(int a[], int p, int r)
{
	if(p<r)
	{
		int q=floor((p+r)/2);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
	compare++;
}
int main()
{
	int n, *a;
	cout<<"\n Enter size of array: ";
	cin>>n;
	a=new int[n];
	cout<<"\n Enter elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	cout<<"\n Sorted Array: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"\n Number of Comparisons: "<<compare;
	return 0;
}
