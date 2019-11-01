#include <iostream>
#include<cstring>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int tr;
void check(int *arr,int V,bool adj[11][11])
{
    int tt=1;
    int i;
    for(i=1;i<V-1;i++)
    {
        int j=i+1;
        if(adj[i][j]==0)
        tt=0;
    }
    if(tt==1)
    tr=1;
}
void print(int *arr,int V)
{
    int i;
    for(i=1;i<V;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
void permutation(int *arr,int start,int end,int V,bool adj[11][11])
{
    if(start==end)
    {
        check(arr,V,adj);
        //print(arr,V);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i),(arr+start));
        permutation(arr,start+1,end,V,adj);
        swap((arr+i),(arr+start));
    }
    
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int V,E,i;
	    bool adj[11][11];
	    cin>>V>>E;
	    memset(adj,0,sizeof(adj));
	    for(i=0;i<E;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        adj[u][v]=1;
	        adj[v][u]=1;
	    }
	    tr=0;
	    int arr[11];
	    for(i=1;i<=V;i++)
	    arr[i]=i;
	    permutation(arr,1,V,V+1,adj);
	    if(tr)
	    cout<<"1"<<endl;
	    else
	    cout<<"0"<<endl;
	}
	return 0;
}