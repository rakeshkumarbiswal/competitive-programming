#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

int main() {
	stack <char>s;
	char str[100000],pp;
	int t,i,tr=0;
	cin>>t;
	while(t--)
	{
	    while(!s.empty())
	    s.pop();
	    tr=0;
	    cin>>str;
	    for(i=0;i<strlen(str);i++)
	    {
	        if(str[i]=='('||str[i]=='{'||str[i]=='[')
	        s.push(str[i]);
	        else if(str[i]==')')
	        {
	            if(!s.empty())
	            {
	                pp=s.top();
	                
	                if(pp=='(')
	                s.pop();
	                else
	                {
	                    tr=1;
	                    goto l;
	                }
	            }
	            else
	            {
	                tr=1;
	                goto l;
	            }
	        }
	        else if(str[i]=='}')
	        {
	            if(!s.empty())
	            {
	                pp=s.top();
	                if(pp=='{')
	                s.pop();
	                else
	                {
	                    tr=1;
	                    goto l;
	                }
	            }
	            else
	            {
	                tr=1;
	                goto l;
	            }
	        }
	        else if(str[i]==']')
	        {
	            if(!s.empty())
	            {
	                pp=s.top();
	                if(pp=='[')
	                s.pop();
	                else
	                {
	                    tr=1;
	                    goto l;
	                }
	            }
	            else
	            {
	                tr=1;
	                goto l;
	            }
	        }
	        
	    }
	   l: if(tr==0&&s.empty())
	    cout<<"balanced"<<endl;
	    else
	    cout<<"not balanced"<<endl;
	    
	    tr=0;
	}
	return 0;
}