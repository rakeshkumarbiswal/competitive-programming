#include <stdio.h>
#include <string.h>
int max(int a, int b )
{
    if(a>b)
    return a;
    return b;
}

int LCS(char *X,char *Y,int m,int n)
{
    int LCS[101][101],i,j;
    for(i=0;i<m;i++)
    {
        LCS[i][0]=0;
    }
    for(i=0;i<=n;i++)
    {
        LCS[0][i]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i]==Y[j])
            LCS[i][j]=1+LCS[i-1][j-1];
            else
            {
                LCS[i][j]=max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
    }
    
    return LCS[m][n];
}
int main() {
	int t,m,n;
	char X[100],Y[100];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&m);
	    scanf("%d",&n);
	    scanf("%s",&X);
	    scanf("%s",&Y);
	    printf("%d\n",LCS(X,Y,m,n));
	}
	return 0;
}




