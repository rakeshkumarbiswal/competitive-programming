#include <bits/stdc++.h> 
struct node
{
    int name;
    int key;
};

class myComparator 
{ 
public: 
    int operator() (const node& p1, const node& p2) 
    { 
        return p1.key > p2.key; 
    } 
}; 

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    priority_queue<node,vector<node>,myComparator> pq;
     
    cout<<endl;
}
