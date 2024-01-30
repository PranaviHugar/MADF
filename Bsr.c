#include<stdio.h>
int RBinarySearch(int [],int,int,int);//function declaration

int RBinarySearch(int a[],int x,int low,int high)//function definition
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(x==a[mid])
    {
        return(mid);
    }
    else if(x<a[mid])
    {
        RBinarySearch(a,x,low,mid-1); //calling its own function
    }
    else
    {
        RBinarySearch(a,x,mid+1,high);//calling its own function
    }

}

int main()//main function
{
    int a[50],size,item,i,result;//declaration of variables
    printf("\n\nEnter the size of array:\t");//size of array
    scanf("%d",&size);
    printf("\nEnter the elements:");//to enter elements
    for(i=0;i<size;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("\nEnter the element to be searched:\t");//to enter the element to be searched
    scanf("%d",&item);
    result=RBinarySearch(a,item,0,size-1);
    if(result==-1)
        printf("\nElement %d not present",item);
    else
        printf("\nElement %d is present",item);
    return 0;

}
