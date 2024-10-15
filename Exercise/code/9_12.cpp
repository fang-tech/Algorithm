#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:

    int maxLengh(vector<int> nums){
        stack<int> s;
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
                last_status = now_status;
            }
        }

        int max = s.size();
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;

        return max;
    }
};

void test_0(){
    vector<int> vec = {5, 5, 1, 7, 7, 8, 6, 4, 6, 4, 5, 3, 2, 2, 3, 4};
    Solution s;
    cout << "test_0: " << s.maxLengh(vec) << endl;
}
void test_1(){
    vector<int> vec = {2,4,-1,9,0,5,-2};
    Solution s;
    cout << "test_1: " << s.maxLengh(vec) << endl;
}
void test() {
    vector<int> vec = {1, 5, 4, 6, 3, 8, 7};
    Solution s;
    cout << "Expected: 7" << endl; // 预期输出应该是 7，因为整个序列都是颠簸的
    cout << "Actual: " << s.maxLengh(vec) << endl; // 实际输出
}
void test_complex_1() {
    vector<int> vec = {1, 7, 4, 9, 2, 5, 1, 5, 3, 6, 2, 4, 6, 8, 3};
    Solution s;
    cout << "Expected: 12" << endl; // 预期输出是 12
    cout << "Actual: " << s.maxLengh(vec) << endl; // 实际输出
}
void test_complex_2() {
    vector<int> vec = {1, 5, 2, 6, 3, 7, 4, 8, 5, 9, 6, 10, 7, 11};
    Solution s;
    cout << "Expected: 14" << endl; // 预期输出是 8
    cout << "Actual: " << s.maxLengh(vec) << endl; // 实际输出
}
void test_complex_3() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Solution s;
    cout << "Expected: 2" << endl; // 预期输出是 2，因为最长颠簸序列只能是两两交替
    cout << "Actual: " << s.maxLengh(vec) << endl; // 实际输出
}
void test_complex_4() {
    vector<int> vec = {-1, 3, 0, -2, 5, -3, 4, 0, -6};
    Solution s;
    cout << "Expected: 7" << endl; // 预期输出是 7
    cout << "Actual: " << s.maxLengh(vec) << endl; // 实际输出
}

int main(){
    test_0();
    test_1();
    test();
    test_complex_1();
    test_complex_2();
    test_complex_3();
    test_complex_4();
    return 0;
}