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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int a=0;
       if(n == 1 && head->next==NULL) return NULL; 
       ListNode*temp,*tempa=head;
       temp=tempa;
       while(temp)
       {
        a++;
        temp=temp->next;
       } 
       a-=n;
       temp=tempa;
       for(int i=1;i<a;i++)
       {
        temp=temp->next;
       }
       if(a!=0)
       {
            temp->next=temp->next->next;
       }
       else head=head->next;
       return head;
    }
};