/**
 * @author  方天宇
 * @date    2024/10/15
 * @brief   洛谷 P1160 队列安排 https://www.luogu.com.cn/problem/P1160
 */

#include <iostream>
using namespace std;

const int N = 10e5 + 10;
struct node
{
    int id;
    int nextid;
    int previd;
}nodes[N];

int main(){
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n; cin>>n;
    nodes[1].id = 1;nodes[1].nextid = 0;nodes[1].previd = 0;
    int head = 1, tail = 1;
    for (int i=2;i<=n;i++) {
        int k,p; cin>>k>>p;
        int prev = nodes[k].previd;
        int next = nodes[k].nextid;
        nodes[i].id = i;
        if (p) {
            // 插入在k后面
            nodes[i].previd = k;
            nodes[i].nextid = next;
            if (next == 0) {
                tail = i;
                nodes[k].nextid = i;
            } else {
                nodes[next].previd = i;
                nodes[k].nextid = i;
            }
        } else {
            // 插入在k前面
            nodes[k].previd = i;
            nodes[i].nextid = k;
            nodes[i].previd = prev;
            if (prev == 0) {
                // 头节点的时候
                head = i;
            } else {
                nodes[prev].nextid = i;
            }
        }
    }
    int m; cin>>m;
    for (int i=0;i<m;i++) {
        int x; cin>>x;
        if (nodes[x].id == -1) {
            continue;
        }
        nodes[x].id = -1;
        int prev = nodes[x].previd;
        int next = nodes[x].nextid;
        if (x == head) {
            nodes[next].previd = nodes[x].previd;
            head = next;
        }else if (x == tail) {
            nodes[prev].nextid = nodes[x].nextid;
            tail = prev;
        } else {
            nodes[prev].nextid = next;
            nodes[next].previd = prev;
        }
    }
    int now = head;
    while (now) {
        cout << nodes[now].id << " ";
        now = nodes[now].nextid;
    }
    return 0;
}