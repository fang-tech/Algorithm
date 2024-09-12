#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:

    int maxLengh(vector<int> nums){
        stack<int> s;

        // //  获取趋势数组
        // vector<int> trend;
        // for (int i = 0; i < nums.size() - 1; i++){
        //     int temp = nums[i+1] - nums[i];
        //     if (temp > 0){
        //         trend.push_back(1);
        //     }
        //     else if (temp == 0){
        //         trend.push_back(0);
        //     }
        //     else {
        //         trend.push_back(-1);
        //     }
        // }

        // // 将元素根据趋势压入栈中
        // 相同的趋势则舍弃去
        if (nums.size() <= 2){
            return nums.size();
        }

        s.push(nums[0]);
        int last_status = 0;
        for (int i = 1; i < nums.size(); i++){
            // 判断第一个元素和栈顶元素之间的关系
            // 需要记录上一个趋势是怎么样的
            // 如果是连续增加, 则不断更新栈顶元素为新的元素
            // 如果是变化了升降关系, 则push入栈
            int now_status = 0;
            if (nums[i] < s.top()){
                now_status = -1;
            }else if (nums[i] == s.top()){
                now_status = 0;
            }else if (nums[i] > s.top()){
                now_status = 1;
            }
            // 状态相同的时候, 更新元素
            if (now_status == last_status){
                s.pop();
                s.push(nums[i]);
            }
            // 状态变化了, 则压入元素
            if (now_status != last_status){
                s.push(nums[i]);
                now_status = last_status;
            }
        }
        
        int max = s.size();
        return max;
    }
};

void test_0(){
    vector<int> vec = {2,3,1,3,89,100,99,2,3,45211,12,3,5};
    Solution s;
    cout << "test_0: " << s.maxLengh(vec) << endl;
}

int main(){
    test_0();
    return 0;
}