#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy value
    int k = s;
    for (int i = 0; i< len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge two sorted array
    int index1 = 0;
    int index2 = 0;
    int main = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[main++] = first[index1++];
        }
        else
        {
            arr[main++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[main++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[main++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid + 1, e);

    //
    merge(arr, s, e);
}

int main()
{
    int arr[10];
    int n =10;
    for(int I=0;I<n;I++){
        cout<<"Enter the "<<I+1<<"element";
        cin>>arr[I];
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
