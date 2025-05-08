#include<iostream>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mI = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[mI])
            {
                mI = j;
            }
        }
        swap(arr[i],arr[mI]);
    }
}

int main()
{
    int arr[] = {64,25,12,22,11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }

    return 0;
}