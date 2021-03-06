/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Subscribe to see which companies asked this question.
*/


//对于每个l1和l2中的节点，将和相加，并判断是否为第一个节点。
//类似于手工代码实现两个数的相加及进位操作  
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0),*pHead=&head;
        int carry=0;
        while(l1 || l2 || carry) {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            pHead->next=new ListNode(sum%10);
            pHead=pHead->next;
            l1=l1?l1->next:0;
            l2=l2?l2->next:0;
        }
        return head.next;
    }
};
