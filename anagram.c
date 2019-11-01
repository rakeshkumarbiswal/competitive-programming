#include <iostream>
#include<set>
#include<cstring>
#include<string>
using namespace std;

int main() {
	long long int arr1[26],arr2[26];
	
	int t;
	string str1,str2;
	
	cin>>t;
	while(t--)
	{
	    for(int i=0;i<26;i++)
	    {
	        arr1[i]=0;
	        arr2[i]=0;
	    }
	    cin>>str1;
	    cin>>str2;
	    
	    int i;
	    string::iterator it1;
	    string::iterator it2;
	    
	    for(it1=str1.begin();it1!=str1.end();it1++)
	    {
	        arr1[*it1-'a']++;
	    }
	    for(it2=str2.begin();it2!=str2.end();it2++)
	    {
	        arr2[*it2-'a']++;
	    }
	    for(i=0;i<26;i++)
	    {
	        if(arr1[i]!=arr2[i])
	        {
	            cout<<"NO"<<endl;
	            goto l;
	        }
	    }
	    cout<<"YES"<<endl;
	    l:i;
	}
	return 0;
}