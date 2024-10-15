/**
 * @author 方天宇
 * @date    2024/10/15
 * @brief   使用STL链表实现洛谷P1996
 */
#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> nodes;
    int n, m; cin>>n>>m;
    for (int i=0;i<n;i++) {
        nodes.push_back(i+1);
    }
    list<int>::iterator it = nodes.begin();
    while (nodes.size() > 1) {
        for (int i=1;i<m;i++) {
            it++;
            if (it == nodes.end()) it = nodes.begin();
        }
        cout << *it << " ";
        list<int>::iterator next = ++it;
        if (next == nodes.end()) next = nodes.begin();
        nodes.erase(--it);
        it = next;
    }
    cout << *it;
    return 0;
}