// https://leetcode.com/problems/copy-list-with-random-pointer/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* A) {
        //handle edge case
        if(A==NULL) return NULL;

            Node* p1=A;
           // Node* cloneHead=NULL; // There is an alternative ahead
        
        /*Now creating the copy of the given list...but inside the list.
        For example if the given list is 1->2->3->4->NULL ... then our intention is           making it look like 1->1->2->2->3->3->4->4->NULL. So that the random field of         a node(lets say x) in copied list is the next of random of x's prev node.             Here in this example.... if 1->random is 5, then in copied list.... 
        1->random = 1->random(the original one)->next.*/
            while(p1)
            {
                Node* temp=new Node(p1->val);
               // if(cloneHead==NULL) cloneHead=temp;
                temp->next=p1->next;
                p1->next=temp;
                p1=temp->next;
            }
        // Assigning the random fields of the copied list
            p1=A;
            while(p1)
            {
                if(p1->random) // Checking if a node's random field is NULL or not
                    p1->next->random=p1->random->next;
                else
                    p1->next->random=NULL;
                p1=p1->next->next;
            }
        
            p1=A;
        Node* cloneHead=p1->next; // This is the above mentioned alternative
        //to store the HEAD of the copied list
        
        // Now separating the copied list from the original list
            while(p1)
            {
                Node* temp=p1->next;
                p1->next=p1->next->next;
                if(p1->next)
                    temp->next=p1->next->next;
                else
                    temp->next=NULL;
                p1=p1->next;
            }
            return cloneHead;
    }
};