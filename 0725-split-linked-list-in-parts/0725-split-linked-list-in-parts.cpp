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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v(k);
        ListNode* temp=head;
        int sz=0;
        while(temp)
        {
            temp=temp->next;
            sz++;
        }
        int sza=sz/k;
        int rem=sz%k;
        temp=head;
        int ind=0;
        while(temp)
        {
            v[ind]=temp;
            ListNode*prev;
            if(rem)prev=temp,temp=temp->next,rem--;
            for(int i=0;i<sza;i++)
            {
                prev=temp;
                temp=temp->next;  
            }
            prev->next=nullptr;
            ind++;
        }
        return v;
    }
};