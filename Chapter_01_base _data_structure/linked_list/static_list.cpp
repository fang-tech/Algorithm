/**
 * @author 方天宇
 * @date    2024/10/15
 * @brief   使用单向静态链表实现洛谷P1996
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
struct node{
    int id;
    int nextid;
}nodes[N];

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for (int i=1;i<n+1;i++){
        nodes[i].id = i;
        nodes[i].nextid = i+1;
    }
    nodes[n].nextid = 1;
    int now = 1, prev = 1;
    while ((n--) > 1) {
        for (int i=1; i<m; i++) {
            prev = now;
            now = nodes[now].nextid;
        }
        printf("%d ", nodes[now].id);
        nodes[prev].nextid = nodes[now].nextid;
        now = nodes[prev].nextid;
    }
    printf("%d", nodes[now].id);
    return 0;
}