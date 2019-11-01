#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct point
{
    int x;
    int y;
};
bool comp(struct point a,struct point b)
{
    if(a.x>b.x)
        return false;
}
int main()
{
    int i,n;
    stack<int >s;
    cin>>n;
    struct point arr[n];
    //int arr1[10000];
    for(i=0;i<n;i++)
    {
        cin>>arr[i].x;
        cin>>arr[i].y;
    }
    sort(arr,arr+n,comp);
    s.push(0);
    int p=0;
    for(i=1;i<n;i++)
    {
        if(!s.empty()&&arr[i].y<arr[s.top()].y)
        {
            s.push(i);
        }
        else
        {
            p++;
        }
    }
    cout<<p<<endl;
    return 0;
}
