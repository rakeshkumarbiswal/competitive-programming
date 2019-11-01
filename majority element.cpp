#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    int i;
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    int x=arr[0];
	    int count=1;
	    for(i=1;i<n;i++)
	    {
	        if(arr[i]==x)
	        {
	            count++;
	        }
	        else if(count>0)
	        count--;
	        else
	        {
	            count=1;
	            x=arr[i];
	        }
	        
	    }
	    count=0;
	    for(i=0;i<n;i++)
	    if(arr[i]==x)
	    count++;
	    if(count==(n/2)+1)
	    cout<<x<<endl;
	    else
	    cout<<"-1"<<endl;
	}
	return 0;
}