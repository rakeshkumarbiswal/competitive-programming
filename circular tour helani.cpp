#include<stack>
int tour(petrolPump p[],int n)
{
    
    int arr[n],i,sum=0;
    for(i=0;i<n;i++)
    {
        arr[i]=p[i].petrol-p[i].distance;
        sum=sum+arr[i];
    }
    //for(i=0;i<n;i++)
    //cout<<arr[i]<<" ";
    if(sum<0)
    return -1;
    
    int curr_sum=0,tempIndex=0;
    for(i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum<=0)
        curr_sum=0;
        else
        {
            tempIndex=i;
            while(i<n&&curr_sum>0)
            {
                curr_sum+=arr[i];
                i++;
            }
        }
    }
 
    return tempIndex;
}
