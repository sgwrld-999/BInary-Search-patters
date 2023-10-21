#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int SearchInRotatedArray(vector<int>& ipVec, int low, int high, int target) {
    int  ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ipVec[mid] == target) {
            ans =  mid;
            return ans;
        } else if (ipVec[low] < ipVec[mid]) {
            if(ipVec[low] <= target && ipVec[mid] >= target){
                high = mid -1 ;
            }
            else{
                low = mid + 1 ;
            }
        } else {
            if(ipVec[mid] <= target && ipVec[high] >= target){
                low = mid + 1;
            }else{
                high = mid - 1 ;
            }
        }
    }
    return ans;
}

};

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    MySolution solution;
    int target;
    cin >> target;
    int result = solution.SearchInRotatedArray(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Required Element ans :  [" << result << "]"<< endl;
    return 0;
}
