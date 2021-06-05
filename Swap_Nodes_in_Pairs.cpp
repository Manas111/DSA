// https://leetcode.com/problems/swap-nodes-in-pairs/submissions/

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
    ListNode* swapPairs(ListNode* A) {
        if(A==NULL || A->next==NULL)
            return A;
    ListNode* new_Head=A->next;
    A->next=A->next->next;
    new_Head->next=A;
    while(A->next!=NULL && A->next->next!=NULL)
    {
        ListNode* temp=A->next->next;
        A->next->next=A->next->next->next;
        temp->next=A->next;
        A->next=temp;
        A=A->next->next;
    }
    return new_Head;
    }
};