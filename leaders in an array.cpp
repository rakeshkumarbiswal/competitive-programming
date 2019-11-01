#include <iostream>
using namespace std;
#include<stack>
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    stack<int >s;
	    int n;
	    cin>>n;
	    int i,arr[1000000];
	    for(i=0;i<n;i++)
	        cin>>arr[i];
	        int max=-99;
	    for(i=n-1;i>=0;i--)
	    {
	        if(arr[i]>=max)
	        {
	            max=arr[i];
	            s.push(max);
	        }
	    }
	    while(!s.empty())
	    {
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}