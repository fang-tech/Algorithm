/**
 * @author 方天宇
 * @date    2024/10/15
 * @brief   使用双向静态链表实现洛谷P1996
 */
#include <bits/stdc++.h>

const int N = 105;

struct node{
    int id, nextid, previd;
}nodes[N];

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) {
        nodes[i].previd = i - 1;
        nodes[i].id = i;
        nodes[i].nextid = i + 1;
    }
    nodes[n].nextid = 1;
    nodes[1].previd = n;
    int now = 1;
    while((n--) > 1) {
        for (int i=1;i<m;i++) {
            now = nodes[now].nextid;
        }
        printf("%d ", nodes[now].id);
        int prev = nodes[now].previd;
        int next = nodes[now].nextid;
        nodes[next].previd = prev;
        nodes[prev].nextid = next;
        now = next;
    }
    printf("%d", nodes[now].id);
    return 0;
}