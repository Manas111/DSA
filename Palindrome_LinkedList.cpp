// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        auto* slow=head;
        auto* fast=head;
        
        // Dealing edge cases
        if(head->next==NULL)
            return true;
        else if(head->next->next==NULL)
            return(head->val==head->next->val);
        
        // Dividng the SLL into two halves
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        auto* head2=slow->next;
        slow->next==NULL;

        // Reversing the 2nd half
        auto* new_head2=head2;
        head2=head2->next;
        new_head2->next=NULL;

        while(head2!=NULL)
        {
            ListNode* temp=head2;
            head2=head2->next;
            temp->next=new_head2;
            new_head2=temp;
        }

        // Checking whether the values are equal on both the sides or not
        while(head!=NULL && new_head2!=NULL)
        {
            if(head->val!=new_head2->val)
                return false;
            head=head->next;
            new_head2=new_head2->next;
        }

        return true;
    }
};