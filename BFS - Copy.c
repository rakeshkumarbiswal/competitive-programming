#include <stdio.h>
int queue[100];
int front=-1; 
int rear=-1;
void enqueue(int data)
{
    rear++;
    queue[rear]=data;
}
int dequeue()
{
    if(rear==front)
    {
        printf("underflow");
        return -99;
    }
    front++;
    return queue[front];
    
}
int isEmpty()
{
    if(front==rear)
    return 1;
    return 0;
}
void BFS(int s,int adj[6][6],int n)
{
    int visited[100],v,i,u;
    for(i=0;i<n;i++)
    visited[i]=0;
    enqueue(s);
    visited[s]=1;
    printf("%d-->",s);
    while(isEmpty()==0)
    {
        u=dequeue();
        for(i=0;i<n;i++)
        {
            if(adj[u][i]==1)
            v=i;
            if(visited[v]==0)
            {
                visited[v]=1;
                printf("%d-->",v);
                enqueue(v);
            }
        }
    }
}
int main() {
	int adj[6][6]={0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0};
	BFS(0,adj,6);
	return 0;
}