struct box
{
    int ht;
    int wd;
    int ln;
};
int compare(void const *f,void const *s )
{
    struct box *b1=(struct box *)f;
    struct box *b2=(struct box *)s;
    return((b2->ln * b2->wd)-(b1->ln * b1->wd));
}

    
struct box BOX[600];
int H[600],W[600],L[600];
int maxHeight(int height[],int width[],int length[],int n)
{
    int temp[600];
    int i=0,j,n1=0;
    for(j=0;j<6*n;j=j+6)
    {
            L[j+0]=length[i];
            H[j+0]=height[i];
            W[j+0]=width[i];
            
            L[j+1]=length[i];
            H[j+1]=width[i];
            W[j+1]=height[i];
            
            L[j+2]=height[i];
            H[j+2]=length[i];
            W[j+2]=width[i];
            
            L[j+3]=height[i];
            H[j+3]=width[i];
            W[j+3]=length[i];
            
            L[j+4]=width[i];
            H[j+4]=length[i];
            W[j+4]=height[i];
            
            L[j+5]=width[i];
            H[j+5]=height[i];
            W[j+5]=length[i];
            i++;
        
    }
    for(i=0;i<6*n;i++)
    {
        if(L[i]<W[i])
        {
            L[i]=-1;
            H[i]=-1;
            W[i]=-1;
        }
        
    }
    n1=0;
    for(i=0;i<6*n;i++)
    {
        if(H[i]!=-1)
        {
            BOX[n1].ht=H[i];
            BOX[n1].ln=L[i];
            BOX[n1].wd=W[i];
            n1++;
        }
    }
    qsort(BOX,n1,sizeof(struct box),compare);
    /*for(i=0;i<n1;i++)
    {
        printf("%d   ",BOX[i].ln);
        printf("%d   ",BOX[i].wd);
        printf("%d   ",BOX[i].ht);
        printf("\n");
    }*/
    for(i=0;i<n1;i++)
    {
        temp[i]=BOX[i].ht;
    }
    /*for(i=0;i<n1;i++)
    {
        printf("%d ",temp[i]);
    }*/
    
    for(i=1;i<n1;i++)
    {
        for(j=0;j<i;j++)
        {
            if((BOX[j].ln>BOX[i].ln)&&(BOX[j].wd>BOX[i].wd)&&(BOX[i].ht+temp[j]>temp[i]))
            {
                temp[i]=temp[j]+BOX[i].ht;
            }
        }
    }
    int max=-1;
    for(i=0;i<n1;i++)
    {
        if(max<temp[i])
        {
            max=temp[i];
        }
        
    }
    /*for(i=0;i<n1;i++)
    {
        printf("%d  ",temp[i]);
    }
    printf("\n");*/
    return max;
}