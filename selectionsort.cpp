#include <iostream>
using namespace std;
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    cout<<arr[i]<<endl;
}

void selectionSort(int *arr, int n)
{
    int temp;
    int min;

    for (int i = 0; i < n; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j]<arr[min])
                min=j;
        }
        if (min !=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

int main()
{
    int arr[] = {2,95,45,48,98,485,65,54,1,478, 10, 232};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Selection Sort :"<<endl;
    printArray(arr,n);
    selectionSort(arr,n);
    cout<<"After Selection Sort:"<<endl;
    printArray(arr,n);
    return (0);
}
