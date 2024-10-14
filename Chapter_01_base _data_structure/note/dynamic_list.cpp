#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node* next;
};

int main(){
    int m, n; scanf(" %d %d", &n, &m);
    node* head;
    head = new node;
    head->data = 1;
    node* now = head;
    for (int i=0; i<n-1; i++) {
        node* newNode = new node;
        newNode->data = i+2;
        newNode->next = nullptr;
        now->next = newNode;
        now = newNode;
    }
    now->next = head;
    now = head;
    node* prev = now;
    while((n--) > 1) {
        for (int i=1; i<m; i++) {
            prev = now;
            now = now->next;
        }
        printf("%d ", now->data);
        prev->next = now->next;
        delete now;
        now = prev->next;
    }
    printf("%d", now->data);
    delete now;
    return 0;
}