#include <iostream>

using namespace std;

class Solution{
private:
    int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

public:

    int cut_rod(int n){
    /**
     * @brief   : 使用暴力递归解决问题
     */
        if (n <= 0) {
            return 0;
        }
        int q = -1;
        for (int i = 1; i <= n; i++) {
            int p = price[i-1];
            q = max(q, p + cut_rod(n-i)); 
        }
        return q;
    }

    void print_array(){
        for (auto v : price) {
            cout << v << " ";
        }
        cout << endl;
    }
};


void test(){
    Solution s;
    cout << "Test case 1: Length 0, Expected: 0, Got: " << s.cut_rod(0) << endl;
    cout << "Test case 2: Length 1, Expected: 1, Got: " << s.cut_rod(1) << endl;
    cout << "Test case 3: Length 2, Expected: 5, Got: " << s.cut_rod(2) << endl;
    cout << "Test case 4: Length 10, Expected: 30, Got: " << s.cut_rod(10) << endl;
    cout << "Test case 5: Length 11, Expected: 31, Got: " << s.cut_rod(11) << endl;
}
int main(){
    test();
    return 0;
}