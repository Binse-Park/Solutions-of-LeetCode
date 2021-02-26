struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* checking;
    struct ListNode* storage;
    struct ListNode dummy;
    
    if (head == 0) {
        return head;
    }
    
    dummy.next = head; 
    storage = &dummy;
    checking = head;
    
    while (checking != 0) {
        if (checking->next == 0 || checking->val != checking->next->val) {
            if (storage->next == checking) {
                //printf("[%d, %d]", storage->val, checking->val);
                storage = checking;
            } else {
                if (storage->next == head) {
                    head = checking->next;
                }
                storage->next = checking->next;

                //printf("<%d, %d, %d>", storage->val, checking->val, head->val);
            }
        }
        
        checking = checking->next;
    }
    
    return head;
}