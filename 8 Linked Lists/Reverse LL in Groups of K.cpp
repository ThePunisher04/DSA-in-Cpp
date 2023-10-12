Node* reverseKNodes(Node* &head, int k) {
        if(head == NULL) {
                cout << "LL is empty" << endl;
                return NULL;
        }
        int len = getLength(head);
        if(k > len) {
                //cout << "Enter valid value for k " << endl;
                return head;
        }

        //it means number of nodes in LL is >= k
        //Step A: reverse first k nodes of LL
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr -> next;
        int count = 0;

        while(count < k) {
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                count++;
        }

        //Step B: recursive call
        if(forward != NULL) {
                // we still have nodes left to reverse
                Node* recursionKaAns = reverseKNodes(forward, k);
                head -> next = recursionKaAns;
        }

        //step C: return head of the modified LL
        return prev;
}