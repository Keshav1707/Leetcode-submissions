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
ListNode*a;
ListNode*rev(ListNode*temp)
{
    if(temp->next==nullptr)
    {
        a=temp;
        return temp;
    }
    rev(temp->next)->next=temp;
    return temp;
}
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        rev(head);
        head->next=nullptr;
        return a;
    }
};