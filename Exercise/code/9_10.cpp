#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int max = 0;
        for (int val : nums){
            int len = 1;
            // 如果val - 1 不在集合中, 说明该元素是起始元素, 则遍历查看长度
            if (set.find(val - 1) == set.end()){
                while (set.find(++val) != set.end()) len++;
            }
            if (max < len) max = len; 
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2};
    cout << s.longestConsecutive(nums);
    return 0;
}