#include<iostream>
using namespace std;
int main()
{
    int arr[10], i, sn, mid, first, last;
    cout<<"Enter 10 elements in descending order:";
    for(i=0; i<10; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter search number:";
    cin>>sn;
    first=0;
    last=9;
    mid=(first+last)/2;
    while(first<=last)
    {
        if(arr[mid]>sn)
            first=mid+1;
        else if(arr[mid]==sn)
        {
            cout<<"The number "<<sn<<" is found at position:"<<mid+1;
            break;
        }
        else
            last=mid-1;
        mid=(first+last)/2;
    }
    if(first>last)
        cout<<"the number is not found in the array";
        cout<<endl;
    return 0;
}
