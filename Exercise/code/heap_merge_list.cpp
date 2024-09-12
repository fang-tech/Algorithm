/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* mergedList = nullptr;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i++; i < lists.size()){
            minHeap.push(lists[i]->val);
        }

        while (!minHeap.empty()){
            if (mergedList == nullptr){
                mergedList = new ListNode(minHeap.top());
            }
            else{
                mergedList->next = new ListNode(minHeap.top());
            }
            
        }
    }
};