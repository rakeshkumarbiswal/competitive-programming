#include <iostream>
using namespace std;
long long int _merge(int *arr,int start,int mid,int end)
{
    int temp[1000000];
    int i=start,n1=mid,j=mid,n2=end,k=0;
    long long int count=0;
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

long long int _mergesort(int *arr,int start,int end)
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
	    int n,arr[1000000];
	    cin>>n;
	    int i;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    long long int p=_mergesort(arr,0,n);
	    cout<<p<<endl;
	}
	return 0;
}