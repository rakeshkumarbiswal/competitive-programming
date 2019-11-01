#include <stdio.h>
int a[100][100];
char result[100];
void print(int l,int m)
{
    if(l==m)
    return;
    else
    {
        int k=a[l][m];
        result[2*(k-1)-2]=')';
        print(1,k);
        print(k+1,m);
    }
}
int mcm(int *arr,int n)
{
    long long int m[100][100];
    long long int i,j,k,l,min=999999999,x;
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(l=1;l<n-1;l++)
    {
        for(i=1;i<n-l;i++)
        {
            j=l+i;
            for(k=i;k<j;k++)
            {
                x=(m[i][k]+m[k+1][j])+(arr[i-1]*arr[k]*arr[j]);
                if(x<min)
                {
                    min=x;
                    a[i][j]=k;
                }
            
            }
            m[i][j]=min;
            min=999999999;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d  ",m[i][j]);
        printf("\n");
    }*/
    //printf("%d\n",n);
    return m[1][n-1];
}
int main() {
	int t,n,i,arr[100],j;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    //printf("%d\n",mcm(arr,n));
	  long long int x= mcm(arr,n);
	  for(i=0;i<n;i++)
	  {
	      for(j=0;j<n;j++)
	      printf("%d  ",a[i][j]);
	      printf("\n");
	  }
	  j=1;
	  for(i=1;i<n;i++)
	  {
	      result[j]=64+i;
	      j=j+3;
	  }
	  result[0]='(';
	  result[j-1]=')';
	  print(1,n-1);
	  for(i=0;i<j;i++)
	  {
	      if(result[i]!=0)
	      printf("%c",result[i]);
	  }
	 
	}
	return 0;
}