#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int singleElement(vector<int>& ipVec,int low,int high){
        while(high >= low){
            int mid = low + (high - low) / 2 ;
            if((mid%2 != 0) && ipVec[mid] == ipVec[mid-1]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return high;
    }
};
int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    Solution obj;
    int result = obj.singleElement(ipVec, 0, sizeOfIpVec - 1);
    cout << "The single non-repeating element is: " << result << endl;
    return 0;
}
