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
		  friend void bfs(linklist<int> l[], int root, int v)  ;  
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
              friend void bfs(linklist<int> l[], int root, int v);
      public:
             linklist()
             {
                       first=NULL;
                       last=NULL;
             }
             void add_at_end(T x);
             int length();
            // void display();
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
/*template<class T>
void linklist<T>::display()
{
	node<T> *temp=first;
	while(temp!=NULL)
	{
		cout<<temp->i<<" ";
		temp=temp->next;
	}
}*/

template<class T>
class queue;
template<class T>
class qnode
{
    	T i;
    	qnode<T> *next; 
        friend class queue<T>;     
    public:
        qnode(T s=0, qnode<T> *n=NULL)
        {
            i=s;
            next=n;
        }
};
template<class T>
class queue
{
        qnode<T> *front, *rear;
    public:
        queue()
        {
            front=NULL;
            rear=NULL;
        }
        void enqueue(T x);            
       	T dequeue();
		bool isEmpty()
		{
			if(front==NULL)
				return true;
			return false;	
		}               
};
template<class T>
void queue<T>::enqueue(T x)
{
    qnode<T> *n=new qnode<T>(x);
    if(n==NULL)
    {
    	cout<<"\n Overflow Condition: Out of memory!";
	}
    if(front==NULL)
	{
		front=n;
		rear=n;
	}
    else
    {
        qnode<T> *temp=rear;
        temp->next=n;
        rear=rear->next;
    }
}
template<class T>
T queue<T>::dequeue()
{
	if(front==NULL)
	{
		cout<<"\n Underflow Condition: Queue Empty! ";
		return 0;
	}
	else
	{
		qnode<T> *t=front;
		front=front->next;
	//	cout<<"\n "<<t->i<<" dequeued! ";
		return t->i;
	}
}

void bfs(linklist<int> l[], int root, int v)
{
	int i, vertex, j, adj;
	node<int> *temp;
	bool discover[v];
	for(i=0;i<v;i++)
		discover[i]=0;
	discover[root-1]=1;
	cout<<root<<" ";
	queue<int> q;
	q.enqueue(root);
	while(!q.isEmpty())
	{
		vertex=q.dequeue();
		temp=l[vertex-1].first;
		while(temp!=NULL)
		{
			adj=temp->i;
			if(!discover[adj-1])
			{
				q.enqueue(adj);
				discover[adj-1]=1;
				cout<<adj<<" ";
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
	cout<<"\n Breadth-First Search: ";
	bfs(l,root,v);
	/*cout<<endl;
	for(i=0;i<v;i++)
	{
		cout<<"\n"<<i+1<<" ";
		l[i].display();
	}*/
	return 0;
}
