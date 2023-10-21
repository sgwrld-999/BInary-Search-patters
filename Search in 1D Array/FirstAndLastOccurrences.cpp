#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    pair<int,int> firstAndLastOccurrences(vector<int>& ipVec, int low, int high, int target) {
    pair<int,int> ans{-1,-1};
    
    // First occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ipVec[mid] == target) {
            ans.first = mid;
            high = mid - 1;
        } else if (ipVec[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Reset low and high for the Last Occurrence
    low = 0;
    high = ipVec.size() - 1;
    
    // Last Occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ipVec[mid] == target) {
            ans.second = mid;
            low = mid + 1;
        } else if (ipVec[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
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
    pair<int,int> result = solution.firstAndLastOccurrences(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "First and Last appearences of the key is [" << result.first << "," << result.second << "]"<< endl;
    return 0;
}
