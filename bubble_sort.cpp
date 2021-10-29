#include<iostream>
using namespace std;
int compare=0;

void bsort(int t[], int n)
{
	int i, j;
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(t[j]>t[j+1])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
			compare++;
		}
	}
}
int main()
{
	int s, ch, *arr;
	cout<<"\n Enter size of list: ";
	cin>>s;
	arr=new int[s];
	cout<<"\n Enter List: ";
	for(int i=0;i<s;i++)
		cin>>arr[i];
	bsort(arr,s);
	cout<<"\n Sorted List:";
	for(int i=0;i<s;i++)
		cout<<" "<<arr[i];
	cout<<"\n\n Number of Comparisons: "<<compare;
	return 0;
}
