#include<iostream>
using namespace std;

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n, int max)
{
    for (int exp = 1; max/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int n, *a, max;
	cout<<"\n Enter size of array: ";
	cin>>n;
	a=new int[n];
	cout<<"\n Enter array elements: ";
	max=-999;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
			max=a[i];
	}
	radixsort(a,n,max);
	cout<<"\n Sorted Array:";
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];
    return 0;
}
