#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        // up[i] 表示以 nums[i] 结尾的上升颠簸子序列的最大长度
        // down[i] 表示以 nums[i] 结尾的下降颠簸子序列的最大长度
        vector<int> up(n, 1), down(n, 1);
        int maxLen = 1;

        for (int i = 1; i < n; i++) {
            int j = i - 1;
            if (nums[i] > nums[j]) {
                up[i] = max(up[j], down[j] + 1);
                down[i] = down[j];
            } else if (nums[i] < nums[j]) {
                down[i] = max(down[j], up[j] + 1);
                up[i] = up[j];
            } else if (nums[i] == nums[i]){
                down[i] = down[j];
                up[i] = up[j]
            }
           // for (int j = 0; j < i; jj++) {
            //     if (nums[i] > nums[j]) {
            //         up[i] = max(up[i], down[j] + 1);
            //     } else if (nums[i] < nums[j]) {
            //         down[i] = max(down[i], up[j] + 1);
            //     }
            // }
            maxLen = max({maxLen, up[i], down[i]});
        }

        return maxLen;
    }
};
void runTest(const vector<int>& testCase, int expectedOutput, int testNumber) {
    Solution s;
    int result = s.maxLength(const_cast<vector<int>&>(testCase));
    
    cout << "Test case " << testNumber << ":" << endl;
    cout << "Input: {";
    for (size_t i = 0; i < testCase.size(); ++i) {
        cout << testCase[i];
        if (i < testCase.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
    cout << "Expected output: " << expectedOutput << endl;
    cout << "Actual output: " << result << endl;
    cout << (result == expectedOutput ? "PASSED" : "FAILED") << endl;
    cout << "-------------------------" << endl;
}
int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 1, 1, 7, 4, 9, 2, 5, 1, 5, 3, 6, 2, 4, 6, 8, 3}, 13},
        {{5, 5, 1, 7, 7, 7 ,7 ,7, 8, 8, 6, 4, 6, 4, 5, 3, 2, 2, 3, 4}, 9},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2},
        {{9, 8, 7, 6, 5, 4, 3, 2, 1}, 2},
        {{1, 10, 2, 9, 3, 8, 4, 7, 5, 6}, 10},
        {{-1, 3, 0, -2, 5, -3, 4, 0, -6}, 7},
        {{1000, 1, 999, 2, 998, 3, 997, 4}, 8},
        {{1, 1, 1, 1, 1, 1, 1}, 1},
        {{1, 2}, 2},
        {{}, 0},
        {{1, 5, 2, 6, 3, 7, 4, 8, 5, 9, 6, 10, 7, 11}, 14},
        {{1, 5, 4, 6, 3, 8, 7}, 7}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        runTest(testCases[i].first, testCases[i].second, i + 1);
    }

    return 0;
}