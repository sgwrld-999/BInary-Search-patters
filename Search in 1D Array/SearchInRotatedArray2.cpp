#include <bits/stdc++.h>
using namespace std;

class MySolution {
public:
    int SearchInRotatedArrayWithDuplicates(std::vector<int>& ipVec, int low, int high, int target) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            while ((low < mid && ipVec[low] == ipVec[mid]) && (mid < high && ipVec[mid] == ipVec[high])) {
                low++;
                high--;
            }
            if (ipVec[mid] == target) {
                ans = mid;
                break;
            }
            if (ipVec[low] <= ipVec[mid]) {
                if (ipVec[low] <= target && target <= ipVec[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (ipVec[mid] <= target && target <= ipVec[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        std::cin >> ipVec[i];
    }
    MySolution solution;
    int target;
    std::cin >> target;
    int result = solution.SearchInRotatedArrayWithDuplicates(ipVec, 0, sizeOfIpVec - 1, target);
    std::cout << "Required Element ans: [" << result << "]" << std::endl;
    return 0;
}
