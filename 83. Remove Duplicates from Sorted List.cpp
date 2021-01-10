/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]
*/

ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current_node=head;
        while(current_node!=NULL && current_node->next!=NULL){
            if(current_node->next->val==current_node->val){
                current_node->next=current_node->next->next;
            }
            else{
                current_node=current_node->next;
            }
        }
         return head;  
}