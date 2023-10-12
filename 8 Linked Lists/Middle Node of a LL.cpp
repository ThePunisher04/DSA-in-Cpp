//TORTOISE ALGORITHM

Node* getMiddle(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty" << endl;
                return head;
        }
        if(head -> next == NULL) {
                //only 1 node in LL
                return head;
        }

        // LL have > 1 node
        Node* slow = head;
        Node* fast = head;

        while(slow != NULL && fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }
        }
        return slow;
}