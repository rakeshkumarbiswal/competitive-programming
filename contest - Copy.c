#include <iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    stack<long long int>S;
	    long long  int n,i,tk=0,temp;
	    cin>>n;
	    tk=1;
	    
	    if(n<=9)
	    {
	        cout<<n;
	        goto l;
	    }
	    while(n>9&&tk)
	    {
	        tk=0;
	        for(i=9;i>1;i--)
	        {
	            if(n%i==0)
	            {
	                n=n/i;
	                S.push(i);
	                tk=1;
	            }
	            
	        }
	        if(n<=9&&n!=1)
	        S.push(n);
	    }
	   
	    if(tk==1)
	    {
	        while(!S.empty())
	        {
	            cout<<S.top();
	            S.pop();
	        }
	    }
	    else
	    cout<<"-1";
	    l:cout<<endl;
	}
	return 0;
}