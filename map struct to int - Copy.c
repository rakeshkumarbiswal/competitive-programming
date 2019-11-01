#include <iostream>
#include<string>
#include<map>
using namespace std;
struct stud
{
    string name;
    int mark;
};
bool operator <(const stud &t1,const stud &t2)
{
    if(t1.name<t2.name)
    return true;
    if(t1.name>t2.name)
    return false;
    if(t1.name==t2.name)
    {
        if(t1.mark>t2.mark)
        return true;
        else 
        return false;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    map<stud,int> mp;
	    int n,i;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
	        stud temp;
	        cin>>temp.name;
	        cin>>temp.mark;
	        if(mp.find(temp)==mp.end())
	        {
	            mp[temp]=1;
	            
	        }
	        else
	        {
	            mp[temp]=mp[temp]+1;
	        }
	    }
	    map<stud,int>::iterator it;
	    for(it=mp.begin();it!=mp.end();it++)
	    cout<<(it->first).name<<" "<<(it->first).mark<<" "<<it->second<<endl;
	    
	}
	
	return 0;
}


