class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = head;
        int carry = 0;
        
        while(p != NULL || q != NULL) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            
            
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            if(p)
                p = p -> next;
            if(q)
                q = q -> next; 
        }
        
        if(carry > 0) {
            curr -> next = new ListNode(carry);
        }
        return head -> next;
    }
};