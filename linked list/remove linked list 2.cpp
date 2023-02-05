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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        bool loop=true;
        while(curr!=NULL)
        {
            while(curr->next!=NULL && curr->val==curr->next->val)
                {curr->next=curr->next->next;
                loop =false;}
            if(loop==0)
            {
                pre->next=curr->next;
                curr=curr->next;
                loop=1;
            }
            else
            {
                pre=pre->next;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
