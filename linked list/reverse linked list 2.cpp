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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* sabse_prev=dummy;
        //traverse upto l-1;
        for(int i=1;i<=l-1;i++)
        {
            
            sabse_prev=sabse_prev->next;
            curr=curr->next;
        }
        //traverse and reverse upto r-l+1, +1 so that prev become new head
        ListNode* pre=NULL;
        int i=0;
        while(i<(r-l+1))
        {
           // cout<<curr->val<<" "<<i<<endl;
            ListNode* temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
            i++;
        }
        
        //now  1--->      NULL<--2<--3<---4---->5
        //    sabse_pre   curr  pre  
        
        //1
        sabse_prev->next->next=curr;
        //2
        sabse_prev->next=pre;
        return dummy->next;
    }
};
