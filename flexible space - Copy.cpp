#include<iostream>
using namespace std;

int main()
{
	int ,sum=0,k,i,j,m,n,arr[100],result[10000];
	cin>>m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			sum=sum+arr[j];
			result[k++]=sum;
		}
	}
	sort(result,result+k);
	cout<<result[0]<<" ";
	for(i=1;i<k;i++)
	{
		if(result[i]!=result[i-1])
			cout<<result[i]<<" ";
	}
}