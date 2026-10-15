// https://leetcode.com/problems/merge-k-sorted-lists/solutions/8415746/c-optimal-solution-23-merge-k-sorted-lis-3d4m/

#include <queue>

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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; //For min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq; //min heap

        //Add head nodes from each list
        for(ListNode* head: lists){
            if(head) pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail=tail->next;

            if(node->next) pq.push(node->next);
        }

        return dummy.next;
        
    }
};