#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,arr[1000000];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    int max_so_far=0;
	    int max_ending_here=0;
	    for(i=0;i<n;i++)
	    {
	        max_ending_here=max_ending_here+arr[i];
	        if(max_ending_here<0)
	        max_ending_here=0;
	        if(max_ending_here>max_so_far)
	        max_so_far=max_ending_here;
	    }
	    if(max_so_far!=0)
	    cout<<max_so_far<<endl;
	    else
	    cout<<arr[0]<<endl;
	}
	return 0;
}