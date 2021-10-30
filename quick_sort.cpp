#include<iostream>
using namespace std;
int compare=0;

int extendSmallRegion(int e[], int pivot, int low, int highVac)
{
	int lowVac, curr;
	lowVac=highVac;
	curr=low;
	while(curr<highVac)
	{
		if(e[curr]>=pivot)
		{
			e[highVac]=e[curr];
			lowVac=curr;
			break;
		}
		curr++;
		compare++;
	}
	return lowVac;
}

int extendLargeRegion(int e[], int pivot, int lowVac, int high)
{
	int highVac, curr;
	highVac=lowVac;
	curr=high;
	while(curr>lowVac)
	{
		if(e[curr]<pivot)
		{
			e[lowVac]=e[curr];
			highVac=curr;
			break;
		}
		curr--;
		compare++;
	}
	return highVac;
}

int partition(int e[], int pivot, int first, int last)
{
	int low, high;
	low=first, high=last;
	while(low<high)
	{
		int highVac=extendLargeRegion(e,pivot,low,high);
		int lowVac=extendSmallRegion(e,pivot,low+1,highVac);
		low=lowVac;
		high=highVac-1;
	}
	return low;
}

void quickSort(int e[], int first, int last)
{
	if(first<last)
	{
		int pivot=e[first];
		int splitpt=partition(e,pivot,first,last);
		e[splitpt]=pivot;
		quickSort(e,first,splitpt-1);
		quickSort(e,splitpt+1,last);
	}
}

int main()
{
	int n;
	cout<<"\n Enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"\n Enter elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	cout<<"\n Sorted Array: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n Number of Comparisons: "<<compare;
	return 0;
}
