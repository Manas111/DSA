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
	// Finding the new HEAD of the to_be sorted List
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
        
	// Storing the head to return at the end
        ListNode* returnable_head=head;
        
	// Sorting ......
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
	// Dealing with edge cases at first and at recursive calls as well
        if(head==NULL || (head->next)==NULL)
            return head;
	
	// Devide the LL at the center
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
	// Fixing the HEAD of the 2nd half of the given LL
        ListNode* head2=slow->next;
	// Disconnecting the 1st half and the 2nd half
        slow->next=NULL;

	// Recursive calls to solve the problem from unit level : Recursion 
        ListNode* A=sortList(head);
        ListNode* B=sortList(head2);
    
	// Merging 2 Sorted LL
        ListNode* new_head=merge(A,B);
		

        return new_head;
    }
};
