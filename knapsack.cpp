//Dynamic Programming - Knapsack Problem

#include<iostream>
using namespace std;

int knapsack(int value[], int n, int wt[], int s)
{
	if(n<=0)
		return 0;
	if(s==0)
		return 0;
	if(wt[n-1]>s)
		return knapsack(value,n-1,wt,s);
	int x, y;
	x=value[n-1]+knapsack(value,n-1,wt,s-wt[n-1]);
	y=knapsack(value,n-1,wt,s);
	if(x>y)
		return x;
	else 
		return y;
	
}

int main()
{
	int n, s;
	cout<<"\n Enter size of set: ";
	cin>>n;
	int value[n], wt[n];
	cout<<"\n Enter elements(Value, Weight):"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Element "<<i+1<<": ";
		cin>>value[i];
		cin>>wt[i];
	}
	cout<<"\n Enter Target Sum/Capacity: ";
	cin>>s;
	int val_sum=knapsack(value,n,wt,s);
	if(val_sum==0)
		cout<<"\n No solution possible";
	else
		cout<<"\n Maximum Value Possible: "<<val_sum;
	return 0;
}
