#include<iostream>
using namespace std;
int compare=0;

void isort(int t[], int n)
{
	int i, j;
	int temp;
	for(i=1;i<=n-1;i++)
	{
		temp=t[i];
		for(j=i-1;j>=0 && temp<t[j];j--)
		{
			t[j+1]=t[j];
			compare++;
		}
		compare++;
		t[j+1]=temp;
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
	isort(arr,s);
	cout<<"\n Sorted List:";
	for(int i=0;i<s;i++)
		cout<<" "<<arr[i];
	cout<<"\n\n Number of Comparisons: "<<compare;
	return 0;
}
