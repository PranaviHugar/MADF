#include<stdio.h>
int a[50];
int tmp[50];
void mergesort(int a[],int low,int high);
void merge(int a[],int tmp[],int low1,int high1,int low2,int high2);
void copy(int a[],int tmp[],int low,int high);

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,tmp,low,mid,mid+1,high);
        copy(a,tmp,low,high);
    }
}

void merge(int a[],int tmp[],int low1,int high1,int low2,int high2)
{
    int i=low1,j=low2,k=low1;
    while(i<=high1&&j<=high2)
    {
        if(a[i]<=a[j])
        {
            tmp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            tmp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=high1)
    {
        tmp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high2)
    {
        tmp[k]=a[j];
        j++;
        k++;
    }
}

void copy(int a[],int tmp[],int low,int high)
{
    while(low<=high)
    {
        a[low]=tmp[low];
        low++;
    }

}

int main()
{
    int a[10],low,high,n,i;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nBefore sorting:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    low=0;
    high=n-1;
    mergesort(a,low,high);
    printf("\nAfter sorting:\t");
    for(int i=0;i<n;i++)
    printf("%d\t",tmp[i]);
}
