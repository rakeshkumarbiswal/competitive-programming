int f[101];
bool vis[101];
int _time=0;
struct point
{
    int index;
    int ftime;
};
vector<int> adj1[101];
void transpose(int V,vector<int>adj[])
{
    int i,j,k;
    for(i=0;i<V;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adj1[adj[i][j]].push_back(i);
        }
    }
}
bool comp(point a,point b)
{
    return a.ftime>b.ftime;
}
void dfs(int V,vector<int> adj[],int s)
{
    vis[s]=1;
    int i;
    _time++;
    for(i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
        {
            dfs(V,adj,adj[s][i]);
        }
    }
    _time++;
    f[s]=_time;
    
}

int kosaraju(int V, vector<int> adj[])
{
    int i;
    for(i=0;i<V;i++)
    {
        vis[i]=0;
        f[i]=0;
    }
    _time=0;
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        dfs(V,adj,i);
    }
    struct point arr[101];
    int j=0;
    for(i=0;i<V;i++)
    {
        vis[i]=0;
        arr[i].index=i;
        arr[i].ftime=f[j++];
        //cout<<f[i]<<" ";
    }
    //cout<<endl;
    sort(arr,arr+V,comp);
    int count=0;
    transpose(V,adj);
    //for(i=0;i<adj1[2].size();i++)
    //cout<<adj1[2][i]<<" ";  
    for(i=0;i<V;i++)
    {
        if(vis[arr[i].index]==0)
        {
            count++;
            dfs(V,adj1,arr[i].index);
        }
    }
    for(i=0;i<V;i++)
    adj1[i].clear();
   return count;
}

