//https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:

    // Function to get the length of a SLL
    int getLength(ListNode* head)
    {
        if(head==NULL) return 0;
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA==NULL || headB==NULL) return NULL; //edge case
		
        int lenA=getLength(headA);
        int lenB=getLength(headB);
        int diff=lenA-lenB;
		
		// Removing the extra elements from the beginning of the laregst LL between the two
        if(diff>0)
        {
            while(diff!=0)
            {
                headA=headA->next;
                diff--;
            }
        }
        else if(diff<0)
        {
            while(diff!=0)
            {
                headB=headB->next;
                diff++;
            }
        }
		
		// Check whether there is any intersection or not
        while(headA)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
		
		//if there is no intersection
        return NULL;
    }
};