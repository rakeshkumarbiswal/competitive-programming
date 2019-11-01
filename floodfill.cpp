#include <iostream>
using namespace std;

void floodfill(int arr[100][100],int n,int m,int x,int y,int k,bool vis[100][100])
{
    if(x-1>=0&&arr[x][y]==arr[x-1][y]&&vis[x-1][y]==0)
    {
        vis[x-1][y]=1;
        floodfill(arr,n,m,x-1,y,k,vis);
    }
    if(x+1<n&&arr[x][y]==arr[x+1][y]&&vis[x+1][y]==0)
    {
        vis[x+1][y]=1;
        floodfill(arr,n,m,x+1,y,k,vis);
    }
    if(y-1>=0&&arr[x][y]==arr[x][y-1]&&vis[x][y-1]==0)
    {
        vis[x][y-1]=1;
        floodfill(arr,n,m,x,y-1,k,vis);
    }
    if(y+1>=0&&arr[x][y]==arr[x][y+1]&&vis[x][y+1]==0)
    {
        vis[x][y+1]=1;
        floodfill(arr,n,m,x,y+1,k,vis);
    }
    /*if(x-1>=0&&y-1>=0&&arr[x][y]==arr[x-1][y-1]&&vis[x-1][y-1]==0)
    {
        vis[x-1][y-1]=1;
        floodfill(arr,n,m,x-1,y-1,k,vis);
    }
    if(x+1>=0&&y+1>=0&&arr[x][y]==arr[x+1][y+1]&&vis[x+1][y+1]==0)
    {
        vis[x+1][y+1]=1;
        floodfill(arr,n,m,x+1,y+1,k,vis);
    }
    if(x-1>=0&&y+1>=0&&arr[x][y]==arr[x-1][y+1]&&vis[x-1][y+1]==0)
    {
        vis[x-1][y+1]=1;
        floodfill(arr,n,m,x-1,y+1,k,vis);
    }
    if(x+1>=0&&y-1>=0&&arr[x][y]==arr[x+1][y-1]&&vis[x+1][y-1]==0)
    {
        vis[x+1][y-1]=1;
        floodfill(arr,n,m,x+1,y-1,k,vis);
    }*/
    arr[x][y]=k;
}
#include<cstring>
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int i,j,arr[100][100];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cin>>arr[i][j];
	    }
	    int x,y,k;
	    cin>>x>>y>>k;
	    bool vis[100][100];
	    memset(vis,0,sizeof(vis));
	    floodfill(arr,n,m,x,y,k,vis);
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}