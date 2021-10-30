// Bucket Sort

#include<iostream>
#include<cmath>
using namespace std;

template<class T>
class linklist;
template<class T>
class node
{
          T i;
          node<T> *next; 
          friend class linklist<T>;     
      public:
             node(T s=0, node<T> *n=NULL)
             {
                      i=s;
                      next=n;
             }
};
template<class T>
class linklist
{
              node<T> *first, *last;
      public:
             linklist()
             {
                       first=NULL;
                       last=NULL;
             }
             void add_at_end(T x);
             int length();
             void add_at_beg(T x);
             void sorted_insert(T x);
             T extract_min();
};
template<class T>
T linklist<T>::extract_min()
{
	if(first!=NULL)
	{
		T temp=first->i;
		node<T> *t=first;
		first=first->next;
		delete t;
		return temp;
	}
	T temp=-1;
	return temp;
}
template<class T>
void linklist<T>::sorted_insert(T x)
{
	if(first==NULL)
	{
		node<T> *n=new node<T>(x);
		first=n;
		last=n;
	}
	else
	{
		if(first->i>x)
			add_at_beg(x);
		else if(last->i<x)
			add_at_end(x);
		else
		{
			node<T> *temp=first;
			while(temp->next!=NULL)
			{
				if(x<temp->next->i)
				{
					node<T> *n=new node<T>(x);
					n->next=temp->next;
					temp->next=n;
					break;	
				}
				temp=temp->next;
			}
		}
	}
}
template<class T>
void linklist<T>::add_at_end(T x)
{
     node<T> *n=new node<T>(x);
     if(first==NULL)
	 {
				first=n;
				last=n;
	 }
     else
     {
         node<T> *temp=last;
         temp->next=n;
         last=last->next;
     }
}
template<class T>
int linklist<T>::length()
{
	node<T> *temp=first;
	int l=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		l++;
	}
	return l;
}
template<class T>
void linklist<T>::add_at_beg(T x)
{
      node<T> *n=new node<T>(x);
      if(first==NULL)
	  {
	  		first=n;
	  		last=n;
	  }
      else
      {
          n->next=first;
          first=n;
      } 
}

void bucket_sort(double a[], int n)
{
	linklist<double> l[n];
	int i, x;
	for(i=0;i<n;i++)
	{
		x=floor(n*a[i]);
		l[x].sorted_insert(a[i]);
	}
	double result[n], temp;
	int k=0;
	for(i=0;i<n;i++)
	{
		temp=l[k].extract_min();
		while(temp==-1)
		{
			k++;
			temp=l[k].extract_min();
		}
		result[i]=temp;
	}
	cout<<"\n Sorted Array: ";
	for(i=0;i<n;i++)
		cout<<result[i]<<" ";
}
int main()
{
	int n;
	double *a;
	cout<<"\n Enter size of array: ";
	cin>>n;
	a=new double[n];
	cout<<"\n Enter array elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	bucket_sort(a,n);
	return 0;
}
