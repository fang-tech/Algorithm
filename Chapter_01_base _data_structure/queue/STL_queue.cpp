/**
 * @author  方天宇
 * @date    2024/10/16
 * @brief   通过STL中的queue解决洛谷P1540
 */
#include <queue>
using namespace std;
const int N = 10e3 + 10;
int hash[N] {};
int main(){
    int m,n; scanf("%d %d", &m, &n);
    queue<int> me;
    int cnt = 0;
    while (n--) {
        int x; scanf("%d", &x);
        if (!hash[x]) {
            hash[x] = 1;
            cnt++;
            me.push(x);
            if (me.size() > m) {
                hash[me.front()] = 0;
                me.pop();
            }
        }    
    }
    printf("%d", cnt);
    return 0;
}