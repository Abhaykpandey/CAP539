#include <iostream>
#include <vector>
using namespace std;
int bSearch(vector<int> arr,int low,int high,int sn) {
    if (low <= high) {
        int mid=low+(high-low)/2;
        if (arr[mid]==sn) {
            return mid;
        } else if (arr[mid]>sn) {
            return bSearch(arr,low,mid-1,sn);
        } else {
            return bSearch(arr,mid+1,high,sn);
        }
    }
    return 1;
}

int main() {
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    int sn;
    cout <<"Enter the search number: ";
    cin >>sn;
    int n=arr.size();
    int index=bSearch(arr,0,n-1,sn);
    if (index==1) {
        cout<<"search number is not found"<<endl;
    } else {
        cout <<"search number is found"<<"\t"<<index << endl;
    }
    return 0;
}
