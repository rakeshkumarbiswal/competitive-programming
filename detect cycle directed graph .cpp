#include<cstring>
bool tr;
void dfs(int s,vector<int> adj[],bool stack1[],bool vis[])
{
    int i;
    vis[s]=true;
    stack1[s]=true;
    for(i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
        {
            dfs(adj[s][i],adj,stack1,vis);
        }
        else
        {
            if(stack1[adj[s][i]]==1)
            tr=1;
        }
    }
    stack1[s]=0;
}
bool isCyclic(int V, vector<int> adj[])
{
    tr=0;
    bool stack1[1000];
    bool vis[1000];
    memset(stack1,0,sizeof(stack1));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        dfs(i,adj,stack1,vis);
    }
    return tr;
}