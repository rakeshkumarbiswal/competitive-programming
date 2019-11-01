#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}

int Knapsack(int *wt,int *val,int W,int n)
{
    int i,j,x,y;
    int knapsack[100][100];
    for(i=0;i<=W;i++)
    knapsack[0][i]=0;
    for(i=0;i<=W;i++)
    knapsack[i][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(j>wt[i-1])
            x=val[i-1]+knapsack[n-1][j-wt[i-1]];
            else 
            x=0;
            y=knapsack[i-1][j];
            knapsack[i][j]=max(x,y);
        }
       
    }
     
    return knapsack[n][W];
}
int main() {
	int i,W,j,wt[100],val[100],t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    scanf("%d",&W);
	    for(i=0;i<n;i++)
	    scanf("%d",&wt[i]);
	    for(i=0;i<n;i++)
	    scanf("%d",&val[i]);
	    printf("%d\n",Knapsack(wt,val,W,n));
	}
	return 0;
}



