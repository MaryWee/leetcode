/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode h(0),*prenode=&h,*pre=head;
        h.next=head;
        int count=0;
        while(pre){
            pre=pre->next;
            count++;
        }
        while(count>=k) {
            ListNode *cur=prenode->next,*nex=cur->next;
            for(int i=1;i<k;i++) {
                cur->next=nex->next;
                nex->next=prenode->next;
                prenode->next=nex;
                nex=cur->next;
            }
            prenode=cur;
            count-=k;
        }
        return h.next;
    }
};
