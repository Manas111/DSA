//https://leetcode.com/problems/sort-list/

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
    ListNode* merge(ListNode* A, ListNode* B)
    {
        ListNode* head;
        if((A->val)<=(B->val))
        {
            head=A;
            A=A->next;
        }
        else
        {
            head=B;
            B=B->next;
        }
        
        ListNode* returnable_head=head;
        
        while(A!=NULL && B!=NULL)
        {
            if((A->val)<=(B->val))
            {
                head->next=A;
                head=A;
                A=A->next;
            }
            else
            {
                head->next=B;
                head=B;
                B=B->next;
            }
        }
        
        if(A!=NULL) { head->next=A; }
        if(B!=NULL) { head->next=B; }
        
        return returnable_head;
    }
        
    ListNode* sortList(ListNode* head) {
        if(head==NULL || (head->next)==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* head2=slow->next;
        slow->next=NULL;

        ListNode* A=sortList(head);
        ListNode* B=sortList(head2);
        
        ListNode* new_head=merge(A,B);
        //cout<<"Manas"<<endl;
        return new_head;
    }
};