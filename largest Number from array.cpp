#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

bool comp(string a,string b)
{
    long long int temp1=stoi(a+b);
    long long int temp2=stoi(b+a);
    if(temp1>temp2)
    return true;
    return false;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i;
	    string arr[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n,comp);
	    for(i=0;i<n;i++)
	    {
	        cout<<arr[i];
	    }
	    cout<<endl;
	}
	return 0;
}