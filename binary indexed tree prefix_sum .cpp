#include<iostream>
using namespace std;

int getNext(int index)
{
    int temp=index;
    temp=-1*temp;
    int temp2=index&temp;
    index+=temp2;
    return index;
}
getParent(int index)
{
    int temp=-1*index;
    int temp2=temp&index;
    return index-temp2;
}
int prefixSum(int bit[],int last)
{
    int sum=0;
    sum+=bit[last+1];
    int par=getParent(last+1);
    while(par>0)
    {
        sum+=bit[par];
        par=getParent(par);
    }
    return sum;
}
void constructBit(int arr[],int bit[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        bit[i+1]+=arr[i];
        int nextindex=getNext(i+1);
        while(nextindex<n)
        {
            bit[nextindex]+=arr[i];
            nextindex=getNext(nextindex);
        }
    }
}
int main()
{
    int arr[]={3,2,-1,6,5,4,-3,3,7,2,3};
    int bit[12]={0};
    int i=0;
    constructBit(arr,bit,11);
    /*for(i=0;i<12;i++)
        cout<<bit[i]<<" ";*/
    cout<<prefixSum(bit,7);
}
