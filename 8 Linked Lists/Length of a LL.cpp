int getLength(Node* head) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp -> next; 
                len++;
        }
        return len;
}