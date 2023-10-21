#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int binarySearchRecursive(vector<int>& ipVec, int low, int high, int target) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            if (ipVec[mid] == target) {
                return mid;
            } else if (ipVec[mid] > target) {
                return binarySearchRecursive(ipVec, low, mid - 1, target);
            } else {
                return binarySearchRecursive(ipVec, mid + 1, high, target);
            }
        }
        return -1;
    }
    int binarySearchIterative(vector<int>& ipVec, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (ipVec[mid] == target) {
                return mid;
            } else if (ipVec[mid] > target) {
                high = mid - 1 ;
            } else {
                low = mid + 1;
            }
        }
        return -1;
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
    int result = solution.binarySearchRecursive(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Result using the Recursive Method: " << result << endl;
    result = solution.binarySearchIterative(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Result using the Iterative Method: " << result << endl;
    return 0;
}
