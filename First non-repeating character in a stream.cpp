#include <iostream>
using namespace std;
#include<queue>
#include<unordered_map>
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        queue<char>q;
        unordered_map<char,int>mp;
        int n;
        cin>>n;
        while(n--)
        {
            char next;
            cin>>next;
            mp[next]++;
            if(mp[next]==1)
            {
                
                if(q.empty())
                {
                    cout<<next<<" ";
                    q.push(next);
                    //mp[next]++;
                }
                else
                {
                    while(!q.empty()&&mp[q.front()]!=1)
                    q.pop();
                    if(q.empty())
                    {
                        cout<<next<<" ";
                        q.push(next);
                        //mp[next]++;
                    }
                    else
                    {
                        cout<<q.front()<<" ";
                        q.push(next);
                        //mp[next]++;
                    }
                }
            }
            else
            {
                if(q.empty())
                {
                    cout<<"-1"<<" ";
                }
                else
                {
                    while(!q.empty()&&mp[q.front()]!=1)
                    q.pop();
                    if(q.empty())
                    {
                        cout<<"-1"<<" ";
                    }
                    else
                    {
                        cout<<q.front()<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
	return 0;
}