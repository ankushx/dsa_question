class Solution {
public:
    ListNode* reverseLi(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* pre=NULL;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* reverse=reverseLi(slow);
        while(reverse!=NULL)
        {
            if(head->val!=reverse->val)
                return 0;
            reverse=reverse->next;
            head=head->next;
        }
        return 1;
    }
};
