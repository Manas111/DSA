// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* t=NULL;
    ListNode* reverseList(ListNode* A) {
            if(A==NULL)
            return t;
        ListNode* temp=A;
        A=A->next;
        temp->next=t;
        t=temp;
        return reverseList(A);
    }
};