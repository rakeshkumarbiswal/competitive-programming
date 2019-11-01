#include <stdio.h>

int function(int *arr,int n)
{
    int temp[301],i,j,max=0;
    temp[0]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(temp[j]>max&&arr[j]<arr[i])
            {
                max=temp[j];
            }
            temp[i]=max+1;
        }
        max=0;
    }
    max=0;
    for(i=0;i<n;i++)
    {
        if(temp[i]>max)
        max=temp[i];
    }
   return max;
}
int main() 
{
	int t,arr[301],n,i;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    printf("%d\n",function(arr,n));
	}
	
	return 0;
}