#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int sum=0,arr[1000000],i;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    int ls=0,rs;
	    bool tr=0;
	    for(i=0;i<n;i++)
	    {
	        rs=sum-ls-arr[i];
	        if(ls==rs)
	        {
	            cout<<i+1<<endl;
	            tr=1;
	        }
	        ls=ls+arr[i];
	        
	    }
	    if(tr==0)
	    cout<<"-1"<<endl;
	}
	return 0;
}