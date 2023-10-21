#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakElementIndex(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {return mid;}
        else if(arr[mid] > arr[mid-1]) low = mid + 1;
        else high = mid - 1;
        }
    return -1;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> arr;
    int sizeOfVec ;
    cout << "Enter the size of ipVec : " ;
    cin >> sizeOfVec ;
    for (int i = 0; i < sizeOfVec ; i++)
    {
        int temp ;
        arr.push_back(temp);
    }
    Solution obj;
    int resultantIndex = obj.peakElementIndex(arr);
    cout << "The peak is at the " << resultantIndex << " index in the array.";
    return 0;
}
