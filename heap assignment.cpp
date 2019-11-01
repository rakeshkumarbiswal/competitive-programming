#include<map>
#include<iostream>
using namespace std;

struct vertices
{
	int name;
	int key;
};
//______________________________________________________________________

void swap(vertices arr[],int par,int loc,map<int,int>&mp)
{
	mp[arr[par].name]=loc;
	mp[arr[loc].name]=par;
	vertices temp=arr[loc];
	arr[loc]=arr[par];
	arr[par]=temp;
	
}
void bottomUpHeapify(vertices arr[],int loc,int V,map<int,int>&mp)
{
	int par;
	while(loc>=0)
	{
		par=(loc-1)/2;
		if(arr[par].key>arr[loc].key)
		{
			swap(arr,par,loc,mp);
			loc=par;
		}
		else
			break;
	}
}

//______________________________________________________________________

void decreasekey(vertices arr[],int V,int Name,int Key,map<int,int>&mp)
{
	int loc=mp[Name];
	arr[loc].key=Key;
	bottomUpHeapify(arr,loc,V,mp);
}
bool contains(int name,map<int,int>&mp)
{
	if(mp.find(name)==mp.end())
		return 0;
	else 
		return 1;
}
void topDownHeapify(vertices arr[],int loc,int V,map<int,int>&mp)
{
	int left=2*loc+1;
	int right=2*loc+2;
	while(right<V)
	{
		int minindex;
		if(arr[left].key<arr[right].key)
		{
			minindex=left;
		}
		else
			minindex=right;
		if(arr[minindex].key<arr[loc].key)
		{
			swap(arr,minindex,loc,mp);
			loc=minindex;
			right=2*loc+2;
			left=2*loc+1;
		}
		else
			break;
	}
	if(left==(V-1)&&arr[loc].key>arr[left].key)
		swap(arr,left,loc,mp);
	
}
int extractMin(vertices arr[],int V,map<int,int>&mp)
{
	swap(arr,0,V-1,mp);
	V--;
	topDownHeapify(arr,0,V,mp);
	mp.erase(arr[V].name);
	return arr[V].name;
} 
int main()
{
    int i;
	vertices arr[10];
	for(i=0;i<10;i++)
	{
		arr[i].name=i;
		arr[i].key=i;
	}
	map<int,int>mp;
	for(i=0;i<10;i++)
		mp[i]=i;
		
	for(i=0;i<10;i++)
	{
	    cout<<arr[i].name<<"   "<<arr[i].key<<endl;
	}
	cout<<"map"<<endl;
	map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
	extractMin(arr,10,mp);
	cout<<"****"<<endl;
	for(i=0;i<10;i++)
	{
	    cout<<arr[i].name<<"   "<<arr[i].key<<endl;
	}
	cout<<"map"<<endl;
	//map<int,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
	
}