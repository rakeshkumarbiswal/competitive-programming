#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    int k;
	    cin>>k;
	    int arr1[k-1];
	    int arr2[k-1];
	    for(i=0;i<k-1;i++)
	    {
	        arr1[i]=-99;
	        arr2[i]=0;
	    }
	   
	    int j,tr=0;
	    for(i=0;i<n;i++)
	    {
	        tr=0;
	        for(j=0;j<k-1;j++)
	        {
	            if(arr[i]==arr1[j])
	            {
	                arr2[j]++;
	                tr=1;
	            }
	        }
	        if(tr==0)
	        {
	            for(j=0;j<k-1;j++)
	            {
	                if(arr2[j]==0)
	                {
	                    arr2[j]++;
	                    arr1[j]=arr[i];
	                    tr=1;
	                }
	            }
	        }
	        if(tr==0)
	        {
	            for(j=0;j<k-1;j++)
	            {
	                arr2[j]--;
	            }
	        }
	    }
	    
	    
	    int max=-99,temp;
	    for(j=0;j<k-1;j++)
	    {
	        if(max<arr2[j])
	        {
	            arr2[j]=max;
	            temp=arr1[j];
	        }
	    }
	    int count=0;
	   
	    for(i=0;i<n;i++)
	    {
	        if(arr[i]==temp)
	        count++;
	    }
	    if(count>(n/k))
	        cout<<temp<<endl;
	    else
	    cout<<"-1"<<endl;
	}
	return 0;
}