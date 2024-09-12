/**
 * @brief   : 问题描述 -> 
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin();
        auto right = height.end() - 1;

        vector<int> result;

        while (left != right){
            result.push_back(min(*left, *right) * (right - left));
            if (*left <= *right){
                left++;
            }else{
                right--;
            }
        }

        int max_area = *max_element(result.begin(), result.end());
        return max_area;
    }
};

int main(){

    Solution s;
    vector<int> q = {1,8,6,2,5,4,8,3,7};
    int ret = s.maxArea(q);
    cout << ret;
    return 0;
}