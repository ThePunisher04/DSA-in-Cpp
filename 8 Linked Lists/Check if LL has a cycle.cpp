//FLOYD CYCLE DETECTION ALGORITHM

bool checkForLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return false;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                        //loop present
                        return true;
                }
        }
        //fast NULL hogya
        return false;

}