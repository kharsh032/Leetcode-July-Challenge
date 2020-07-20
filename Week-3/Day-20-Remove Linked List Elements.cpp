Problem Link :- https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/

/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

//Solution

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL &&  head->val==val )
                 head=head->next;
        if(head==NULL) 
            return NULL;
        ListNode* temp=head;
        cout<<temp->val<<"     "<<head->val;
        while(temp!=NULL && temp->next!=NULL)
        {
            
            if(temp->next->val == val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        
        return head;
    }
};