#include <stdio.h>
struct activity
{
    int starttime;
    int finishtime;
};
int compareTo(void const *f,void const *s)
{
    struct activity *a=(struct activity *)f;
    struct activity *b=(struct activity *)s;
    return a->finishtime-b->finishtime;
}
int main() {
	int t,i,j,s[1000],f[1000],n;
	struct activity act[1000];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    scanf("%d",&s[i]);
	    for(i=0;i<n;i++)
	    scanf("%d",&f[i]);
	    for(i=0;i<n;i++)
	    {
	        act[i].starttime=s[i];
	        act[i].finishtime=f[i];
	    }
	    qsort(act,n,sizeof(struct activity),compareTo);
	    int result=1;
	    int maxf=act[0].finishtime;
	    for(i=1;i<n;i++)
	    {
	        if(act[i].starttime>=maxf)
	        {
	            result++;
	            maxf=act[i].finishtime;
	        }
	    }
	    printf("%d\n",result);
	}
	return 0;
}