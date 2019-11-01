#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int count=0;
	    while(n!=1)
	    {
	        if(n%2==0)
	        {
	            count++;
	            n=n/2;
	        }
	        else
	        {
	            count++;
	            n=n-1;
	        }
	    }
	    cout<<count<<endl;
	    
	}
	return 0;
}