#include <stdio.h>
#include<string.h>
int mat[100][100];
int substring(char *str1,char *str2,int n1,int n2)
{
    int i,j,max=0;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            mat[i][j]=mat[i-1][j-1]+1;
        }
    }
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(mat[i][j]>max)
            max=mat[i][j];
        }
    }
   
    return max;
}
int main() {
	char str1[100],str2[100];
	int n1,t,n2;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n1);
	    scanf("%d",&n2);
	    scanf("%s",str1);
	    scanf("%s",str2);
	    printf("%d\n",substring(str1,str2,n1,n2));
	    
	}
	return 0;
}