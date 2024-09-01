
class Solution {
    ListNode* reverseLinkedList(ListNode *head)
{

   ListNode* temp = head;  
   ListNode* prev = NULL;  

   while(temp != NULL){  

       ListNode* front = temp->next;  

       temp->next = prev;  

       prev = temp;  

       temp = front; 
   }

   return prev;  
}

ListNode* getKthNode(ListNode* temp, int k){

    k -= 1; 

    while(temp != NULL && k > 0){

        k--; 

        temp = temp -> next; 
    }

    return temp; 
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 

    ListNode* prevLast = NULL; 

    while(temp != NULL){

        ListNode* kThNode = getKthNode(temp, k); 

        // If the Kth node is NULL
        // (not a complete group)
        if(kThNode == NULL){
            // If there was a previous group,
            // link the last node to the current node
            if(prevLast){
                prevLast -> next = temp; 
            }
            
            // Exit the loop
            break; 
        }
        
        // Store the next node
        // after the Kth node
        ListNode* nextNode = kThNode -> next; 

        // Disconnect the Kth node
        // to prepare for reversal
        kThNode -> next = NULL; 

        // Reverse the nodes from
        // temp to the Kth node
        reverseLinkedList(temp); 
        
        // Adjust the head if the reversal
        // starts from the head
        if(temp == head){
            head = kThNode;
        }else{
            // Link the last node of the previous
            // group to the reversed group
            prevLast -> next = kThNode; 
        }

        // Update the pointer to the
        // last node of the previous group
        prevLast = temp; 

        // Move to the next group
        temp = nextNode; 
    }
    
    // Return the head of the
    // modified linked list
    return head; 
    }
};