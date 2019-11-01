#include <iostream>
using namespace std;
long long int merge(int *arr,int start,int end,int start2,int end2)
{
    int count=0;
    int arr1[1000000];
    int i=start;
    int j=start2;
    int k=0;
    while(i<=end&&j<=end2)
    {
        if(arr[i]<=arr[j])
        {
            arr1[k++]=arr[i++];
        }
        else
        {
            arr1[k++]=arr[j++];
            count=count+end-i+1;
        }
    }
    while(i<=end)
    arr1[k++]=arr[i++];
    while(j<=end2)
    arr1[k++]=arr[j++];
    k=0;
    for(i=start;i<=end2;i++)
    arr[i]=arr1[k++];
    
    return count;
}
long long int _mergesort(int *arr,int start,int end)
{
    int count=0;
    if(start<end)
    {
        int mid=(start+end)/2;
        long long int p=_mergesort(arr,start,mid);
        long long int q=_mergesort(arr,mid+1,end);
        count=p+q+merge(arr,start,mid,mid+1,end);
        
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
	    long long int p=_mergesort(arr,0,n-1);
	    //cout<<p<<endl;
	    /*for(i=0;i<n;i++)
	    {
	        cout<<arr[i]<<" ";
	    }*/
	    cout<<p<<endl;
	}
	return 0;
}