#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int compareTo(void const* first,void const* second)
{
    int *a=(int *)first;
    int *b=(int *)second;
    if(*a>*b)
    return 1;
    else if(*a<*b)
    return -1;
    else 
    return 0;
}
int mr[301][301];
int coin(int *arr,int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
    mr[i][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(arr[i-1]<j)
            mr[i][j]=mr[i-1][j];
            else
            {
                mr[i][j]=mr[i][j-arr[i-1]]+mr[i-1][j];
            }
        }
    }
    return mr[n][m];
}


int main() {
	int t,n,m,arr[301],j,i;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    scanf("%d",&m);
	    qsort(arr,n,sizeof(int),compareTo);
	    printf("%d\n",coin(arr,n,m));
	    for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=m;j++)
	        {
	            printf("%d  ",mr[i][j]);
	        }
	        printf("\n");
	    }
	}
	return 0;
}