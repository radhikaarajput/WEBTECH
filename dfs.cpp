// DFS

#include<iostream>
using namespace std;

template<class T>
class linklist;
template<class T>
class node
{
          T i;
          node<T> *next; 
          friend class linklist<T>; 
		  friend void dfs(linklist<int> l[], int root, int v);  
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
              friend void dfs(linklist<int> l[], int root, int v);
      public:
             linklist()
             {
                       first=NULL;
                       last=NULL;
             }
             void add_at_end(T x);
             int length();
};
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
class stack;
template<class T>
class snode
{
    	T i;
    	snode<T> *next; 
    	friend class stack<T>;     
    public:
        snode(T s=0, snode<T> *n=NULL)
        {
            i=s;
            next=n;
        }
};
template<class T>
class stack
{
        snode<T> *top;
    public:
        stack()
        {
            top=NULL;
        }
        void push(T x);
        T pop(); 
		bool isEmpty()
		{
			if(top==NULL)
				return true;
			return false;
		}       
};
template<class T>
void stack<T>::push(T x)
{
    snode<T> *n=new snode<T>(x);
    if(n==NULL)
    {
    	cout<<"\n Overflow Condition: Out of memory!";
    	return;
	}
    if(top==NULL)
		top=n;
    else
    {
        n->next=top;
        top=n;
    }
}
template<class T>
T stack<T>::pop()
{
	if(top==NULL)
	{
		return 0;	
	}
	else
	{
		snode<T> *t=top;
		top=top->next;
		T temp=t->i;
		delete t;
		return temp;
	}
}

void dfs(linklist<int> l[], int root, int v)
{
	int i, vertex, j, adj;
	node<int> *temp;
	bool discover[v];
	for(i=0;i<v;i++)
		discover[i]=0;
	discover[root-1]=1;
	stack<int> stck;
	stck.push(root);
	while(!stck.isEmpty())
	{
		vertex=stck.pop();
		cout<<vertex<<" ";
		temp=l[vertex-1].first;
		while(temp!=NULL)
		{
			adj=temp->i;
			if(!discover[adj-1])
			{
				stck.push(adj);
				discover[adj-1]=1;
				//cout<<adj<<" ";
			}
			temp=temp->next;
		}
	}
}

int main()
{
	int v, i, e, j, adj, root;
	cout<<"\n Enter number of vertices: ";
	cin>>v;
	cout<<"\n Enter root: ";
	cin>>root;
	linklist<int> l[v];;
	cout<<"\n Enter Adjacency List: ";
	for(i=0;i<v;i++)
	{
		cout<<"\n Vertex "<<i+1<<":";
		cout<<"\n Enter number of edges: ";
		cin>>e;
		if(e==0)
			continue;
		cout<<" Enter adjacent vertices: ";
		for(j=0;j<e;j++)
		{
			cin>>adj;
			l[i].add_at_end(adj);
		}
	}
	cout<<"\n Depth-First Search: ";
	dfs(l,root,v);
	return 0;
}
