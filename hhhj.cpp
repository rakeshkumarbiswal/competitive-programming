#include <iostream>
using namespace std;
int _merge(int *arr,int start,int mid,int end)
{
    int temp[10000];
    int i=start,n1=mid,j=mid,n2=end,k=0;
    int count=0;
    while(i<n1&&j<n2)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            count=count+(mid-i);
            temp[k++]=arr[j++];
        }
    }
    while(i<n1)
    temp[k++]=arr[i++];
    while(j<n2)
    temp[k++]=arr[j++];
    k=0;
    for(i=start;i<end;i++)
    {
        arr[i]=temp[k++];
    }
    return count;
}

int _mergesort(int *arr,int start,int end)
{
    int count=0;
    if(start<end)
    {
        int mid=(start+end)/2;
        _mergesort(arr,start,mid);
        _mergesort(arr,mid+1,end);
        count=count+_merge(arr,start,mid,end);

    }
    else return count;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,arr[100];
	    cin>>n;
	    int i;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int p=_mergesort(arr,0,n);
	    cout<<p<<endl;
	}
	return 0;
}
