// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
        int carry=A->val+B->val;
    ListNode* ans=new ListNode(carry%10);
    ListNode* res=ans;
    carry/=10;
    A=A->next;
    B=B->next;
    while(A!=NULL && B!=NULL)
    {
        carry+=(A->val+B->val);
        ans->next=new ListNode(carry%10);
        ans=ans->next;
        carry/=10;
        A=A->next;
        B=B->next;
    }
    while(A!=NULL)
    {
        carry+=A->val;
        ans->next=new ListNode(carry%10);
        carry/=10;
        ans=ans->next;
        A=A->next;
    }
    while(B!=NULL)
    {
        carry+=B->val;
        ans->next=new ListNode(carry%10);
        carry/=10;
        ans=ans->next;
        B=B->next;
    }
    while(carry!=0)
    {
        ans->next=new ListNode(carry%10);
        carry/=10;
        ans=ans->next;
    }
    return res;
    }
};