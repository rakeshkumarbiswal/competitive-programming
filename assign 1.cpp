#include <iostream>
using namespace std;
#include<algorithm>
int findRank(int *arr,int i,int j,int r);
void swap(int *arr,int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int pivot(int arr[],int s,int e)
{
    if(e-s+1<5)
    {
        sort(arr+s,arr+e);
        return (e+s)/2;
    }
    int i=s+5;
    int j=s;
    for(i;i<=e;i+=5)
    {
        sort(arr+(i-5),arr+i);
        swap(arr,j,i-2);
        j++;
    }
    return findRank(arr,s,s+((e-s+1)/5),((e-s+1)/10)+1);
}
void Swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than or  
        // equal to pivot  
        if (arr[j] <= pivot)  
        {  
            i++; // increment index of smaller element  
            Swap(&arr[i], &arr[j]);  
        }  
    }  
    Swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

int findRank(int *arr,int i,int j,int r)
{
    int k=pivot(arr,i,j);
    swap(arr,i,k);
    k=partition(arr,i,j);
    int p;
    
    for(p=0;p<6;p++)
    cout<<arr[p]<<" ";
    
    cout<<endl;
    
    if(j-k+1==r)
    return k;
    else if(j-k+1<r) findRank(arr,i,k-1,r-(j-k+1));
    else findRank(arr,k+1,j,r);
}
int main() {
	int arr[]={2,3,9,5,1,4,6},i;
	
	 int k=findRank(arr,0,6,6);
	    cout<<arr[k]<<" ";
	cout<<endl;
	return 0;
}