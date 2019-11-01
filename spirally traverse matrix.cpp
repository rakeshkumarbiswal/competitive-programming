#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int row,col,i,j,arr[10][10];
	    cin>>row>>col;
	    for(i=0;i<row;i++)
	    for(j=0;j<col;j++)
	    cin>>arr[i][j];
	    
	    int sr=0,er=row-1,sc=0,ec=col-1;
	    int count=row*col;
	    //cout<<"#"<<arr[0][0]<<" #";
	    while(sr<=er&&sc<=ec&&count>0)
	    {
	        for(i=sc;i<=ec&&count>0;i++)
	        {
	            cout<<arr[sr][i]<<" ";
	            count--;
	        }
	        sr++;
	        for(i=sr;i<=er&&count>0;i++)
	        {
	            cout<<arr[i][ec]<<" ";
	            count--;
	        }
	        ec--;
	        for(i=ec;i>=sc&&count>0;i--)
	        {
	            cout<<arr[er][i]<<" ";
	            count--;
	        }
	        er--;
	        for(i=er;i>=sr&&count>0;i--)
	        {
	            cout<<arr[i][sc]<<" ";
	            count--;
	        }
	        sc++;
	        //cout<<" @"<<sc<<" ";
	    }
	   cout<<endl;
	}
	return 0;
}