#include <iostream>
using namespace std;
#include<map>
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    map<int,int>mp1;
	    map<int,int>mp2;
	    map<int,int>mp3;
	    
	    int i;
	    for(i=0;i<n1;i++)
	    {
	        int temp;
	        cin>>temp;
	        mp1[temp]=1;
	    }
	    for(i=0;i<n2;i++)
	    {
	        int temp;
	        cin>>temp;
	        mp2[temp]=1;
	    }
	    for(i=0;i<n3;i++)
	    {
	        int temp;
	        cin>>temp;
	        mp3[temp]=1;
	    }
	    map<int,int>::iterator it=mp1.begin();
	    int tr=0;
	    for(it;it!=mp1.end();it++)
	    {
	        if(mp2.find(it->first)!=mp2.end()&&mp3.find(it->first)!=mp3.end())
	        {
	            cout<<it->first<<" ";
	            tr=1;
	        }
	        
	    }
	    if(tr==0)
	    cout<<"-1"<<" ";
	    cout<<endl;
	}
	return 0;
}