#include <iostream>
using namespace std;
#include<map>
#include<algorithm>
struct Elem
{
    int elem;
    int freq;
};
bool comm(Elem a,Elem b)
{
    return a.elem<b.elem;
}
bool comp(Elem a,Elem b)
{
    return a.freq>b.freq;
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    map<int,int>mp;
	    int n;
	    cin>>n;
	    Elem arr[n];
	    int ar[n];
	    int i,j;
	    for(i=0;i<n;i++)
	    {
	        cin>>ar[i];
	        mp[ar[i]]++;
	    }
	    //map<int,int>::iterator it;
	   // it=mp.begin();
	    j=0;
	    for(i=0;i<n;i++)
	    {
	        arr[j].elem=ar[i];
	        arr[j].freq=mp[ar[i]];
	        j++;
	    }
	    sort(arr,arr+n,comm);
	    stable_sort(arr,arr+n,comp);
	    for(i=0;i<n;i++)
	    cout<<arr[i].elem<<" ";
	    cout<<endl;
	}
	return 0;
}