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

class Solution {
public:
struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto i : lists)
        {
            ListNode*temp=i;
            while(temp)
            {
                ListNode*nxt=temp->next;
                temp->next=nullptr;
                pq.push(temp);
                temp=nxt;
            }
        }
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(!pq.empty())
        {
            temp->next=pq.top();
            temp=temp->next;
            pq.pop();
        }
        return dummy->next;
    }
};