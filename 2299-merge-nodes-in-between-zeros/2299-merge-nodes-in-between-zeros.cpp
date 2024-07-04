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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head,*prev;
        while(temp->next)
        {
            prev=temp;
            if(temp->next->val!=0)
            {
                temp->val+=temp->next->val;
                temp->next=temp->next->next;
            }
            else temp=temp->next;
        }
        prev->next=nullptr;
        return head;
    }
};