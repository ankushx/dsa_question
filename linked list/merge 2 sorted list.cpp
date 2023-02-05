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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* ak=new ListNode(0);
        ListNode*head=ak;
        if(list1==NULL && list2==NULL)
            return NULL;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val>list2->val)
            {
                head->next=list2;
                list2=list2->next;
            }
            else
            {
                 head->next=list1;
                list1=list1->next;
            }
            head=head->next;
        }
       if(list1==NULL || list2==NULL)
           head->next=(list1)==NULL ?list2:list1;
        return ak->next;
    }
};
