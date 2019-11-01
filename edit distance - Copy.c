#include <stdio.h>
int arr[102][102];
int min(int a,int b,int c)
{
    if(a<=b&&a<=c)
    return a;
    if(b<=a&&b<=c)
    return b;
    if(c<=a&&c<=b)
    return c;
}
int Editdistance(char *str1,char *str2,int n1,int n2)
{
    int i,j;
    for(i=0;i<=n1;i++)
    arr[i][0]=i;
    for(i=0;i<=n2;i++)
    arr[0][i]=i;
    /*for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        printf("%d   ",arr[i][j]);
        printf("\n");
    }*/
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                arr[i][j]=arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=1+min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
            }
        }
    }
    return arr[n1][n2];
}

int main() 
{
	int t,n1,n2;
	char str1[101],str2[101];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n1);
	    scanf("%d",&n2);
	    scanf("%s",str1);
	    scanf("%s",str2);
	    //printf("%s",str1);
	    //printf("%s",str2);
	    printf("%d\n",Editdistance(str1,str2,n1,n2));
	}
	return 0;
}