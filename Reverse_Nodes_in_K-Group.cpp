// https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/

/*
Runtime: 8 ms, faster than 99.30% of C++ online submissions for Reverse Nodes in k-Group.

Memory Usage: 11.3 MB, less than 93.84% of C++ online submissions for Reverse Nodes in k-Group.
*/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* p1=head;
        ListNode* p2=NULL;
        int count=0;
        while(count<k)
        {
            if(head==NULL)
            {
                ListNode* p3=NULL;
                while(p2!=NULL)
                {
                    ListNode* temp=p2;
                    p2=p2->next;
                    temp->next=p3;
                    p3=temp;
                }
                return p3;
            }
            ListNode* temp=head;
            head=head->next;
            temp->next=p2;
            p2=temp;
            count++;
        }
        p1->next=reverseKGroup(head,k);
        return p2;
    }
};