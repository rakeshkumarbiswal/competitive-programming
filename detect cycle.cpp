int tr;
void dfs(int s, vector<int> g[], bool vis[],int par[])
{
    vis[s] = 1;
    int i;
    for(i=0;i<g[s].size();i++)
    {
        if(!vis[g[s][i]])
        {
            par[g[s][i]]=s;
            dfs(g[s][i],g,vis,par);
        }
        else
        {
            if(par[s]!=g[s][i])
            tr=1;
        }
            
    }
}
bool isCyclic(vector<int> adj[], int V)
{
    tr=0;
    int i;
    int par[100];
    bool vis[100];
    for(i=0;i<100;i++)
    vis[i]=0;
    for(i=0;i<100;i++)
    par[i]=-1;
    for(i=0;i<V;i++)
    {
        if(vis[i]==0)
        dfs(i,adj,vis,par);
    }
   
    if(tr==0)
    return 0;
    else
    return 1;
}
