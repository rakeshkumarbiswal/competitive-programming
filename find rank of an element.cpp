#include <iostream>
using namespace std;
void swap(int *arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int *arr,int start,int end)
{
    int mm=(end+start)/2;
    swap(arr,end,mm);
    int pivot=arr[end],i;
    int pindex=start;
    for(i=start;i<=end-1;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr,i,pindex);
            pindex++;
        }
    }
    swap(arr,pindex,end);
    return pindex;
}
int find(int *arr,int start,int end,int key)
{
    if(start>end)
    return -1;
    int p,i;
    p=partition(arr,start,end);
    //cout<<"#"<<p<<"#";
    if(arr[p]==key)
    {
        return p;
    }
    if(arr[p]>key)
    return find(arr,start,p-1,key);
    return find(arr,p+1,end,key);
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n],i;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int k;
	    cin>>k;
	    int p; 
	    p=find(arr,0,n-1,k);
	    cout<<n-p<<endl;
	}
	return 0;
}