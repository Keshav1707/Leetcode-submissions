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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempa=l1,*tempb=l2,*preva=nullptr,*prevb=nullptr;
        
        int carry=0;
        while(tempa!=nullptr||tempb!=nullptr)
        {
            int sum =carry;
            if(tempa!=nullptr)
            {
                sum+=tempa->val;
                preva=tempa;
                tempa=tempa->next;
            }
            if(tempb!=nullptr)
            {
                sum+=tempb->val;
                prevb=tempb;
                tempb=tempb->next;
            }
            carry=sum/10;

            if(preva!=nullptr)
            preva->val=sum%10;
            if(tempa==nullptr&&tempb!=nullptr)
            {
                preva->next=tempb;
                tempa=tempb;
                tempb=nullptr;
            }
        }
        if(carry>0)
        {
            preva->next=new ListNode(carry);
        }
        return l1;
    }
};