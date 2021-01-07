/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode *temp=new ListNode(0),*head=new ListNode(0);
        int flag=0;
        if(l1==NULL && l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                if(flag==0){
                    head=l1;
                    temp=head;
                }
                else{
                    temp->next=l1;
                    temp=temp->next;
                }
                l1=l1->next;
            }
            else{
                if(flag==0){
                    head=l2;
                    temp=head;
                }
                else{
                    temp->next=l2;
                    temp=temp->next;
                }
                l2=l2->next;
            }
            flag=1;
        }
        while(l1 != NULL){
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2 != NULL){
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
       return head; 
}