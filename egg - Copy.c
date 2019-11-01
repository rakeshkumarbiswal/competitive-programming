#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int a[11][51];

int Egg(int n,int k)
{
    int i,j,l,min=999,x,t1,t2;
    //intialization
    for(i=1;i<=k;i++)
    a[1][i]=i;
    //____________________
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
           if(i>j)
           a[i][j]=a[i-1][j];
           else
           {
               for(l=1;l<=j;l++)
               {
                   if(l==1)
                   t1=0;
                   else
                   {
                       t1=a[i-1][l-1];
                       
                   }
                   if(l==j)
                   {
                       t2=0;
                   }
                   else
                   {
                       t2=a[i][j-l];
                   }
                   //if(i==2&&j==3)
                   //{
                     //  printf(" %d   %d   %d\n",l,t1,t2);
                   //}
                   x=1+max(t1,t2);
                   if(x<min)
                   min=x;
               }
               a[i][j]=min;
               min=999;
           }
        }
    }
    return a[n][k];
}

int main() {
    int t,n,k,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&k);
        printf("%d\n",Egg(n,k));
        //for(i=0;i<=n;i++)
        //{
            //for(j=0;j<=k;j++)
            //{
               // printf("%d  ",a[i][j]);
            //}
            //printf("\n");
        //}
        
        
      
    }
	return 0;
}