//对于每个l1和l2中的节点，将和相加，并判断是否为第一个节点。
//类似于手工代码实现两个数的相加及进位操作  
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool first_val=true;
        ListNode* result,*last_node;
        bool carry=false;
        while(l1 || l2){
            int l1val=0;
            int l2val=0;
            if(l1)
                l1val=l1->val;
            if(l2)
                l2val=l2->val;
            int value=l1val+l2val+carry;
            if(value>=10){
                carry=true;
                value-=10;
            }
            else
                carry=false;
            if(first_val) {
                result=new ListNode(value);
                last_node=result;
                first_val=false;
            }
            else {
                last_node->next=new ListNode(value);
                last_node=last_node->next;
            }
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        //l1 and l2 both visit completly,but there still an carry
        if(carry) 
            last_node->next=new ListNode(carry);

        return result;
    }
