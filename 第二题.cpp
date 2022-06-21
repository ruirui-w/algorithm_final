class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
        return devided(lists, 0, lists.size()-1);
    }
    ListNode* devided(vector<ListNode *> lists, int l, int r) {
        if(l == r) {return lists[l];}
        if(l > r) {return nullptr;}
        int mid = (l+r)/2;
        return mergetwo(devided(lists, l, mid), devided(lists, mid+1, r));
    }
    ListNode* mergetwo(ListNode* h1, ListNode* h2) {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        
        while(h1 && h2) {
            if(h1->val < h2->val) {
                p->next = h1;h1 = h1->next;p = p->next;
            } else {
                p->next = h2;h2 = h2->next;p = p->next;
            }
        }
        if(h1) p->next = h1;
        else p->next = h2;
        return head->next;
    }
};
