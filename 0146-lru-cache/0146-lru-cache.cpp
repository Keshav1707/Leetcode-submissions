

class LRUCache {
public:
    class ListNode{
    public:
    int key;
    int val;
    ListNode*prev;
    ListNode*next;
    ListNode(int k,int v)
    {
        key=k;
        val=v;
    }
};
ListNode*head=new ListNode(-1,-1);
ListNode*tail=new ListNode(-1,-1);
int size;
unordered_map<int,ListNode*>cache;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
       if(cache.find(key)!=cache.end())
       {
            ListNode*temp=cache[key];
            ListNode*tempb=temp->next;
            ListNode*tempc=temp->prev;
            tempc->next=tempb;
            tempb->prev=tempc;
            ListNode*nxt=head->next;
            head->next=temp;
            temp->next=nxt;
            nxt->prev=temp;
            temp->prev=head;
            return temp->val;
       } 
       else return -1;
    }
    
    void put(int key, int value) {
    
        if(cache.find(key)!=cache.end())
       {
        
            cache[key]->val=value;
            ListNode*temp=cache[key];
            ListNode*tempb=temp->next;
            ListNode*tempc=temp->prev;
            tempc->next=tempb;
            tempb->prev=tempc;
            ListNode*nxt=head->next;
            head->next=temp;
            temp->next=nxt;
            nxt->prev=temp;
            temp->prev=head;

       }
       else
       {
         ListNode*temp=new ListNode(key,value);
         ListNode*nxt=head->next;
            head->next=temp;
            temp->next=nxt;
            nxt->prev=temp;
            temp->prev=head;
       }
       cache[key]=head->next;
       if(cache.size()>size)
        {
            cache.erase(tail->prev->key);
            ListNode*temp=tail->prev->prev;
            temp->next=tail;
            tail->prev=temp;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */