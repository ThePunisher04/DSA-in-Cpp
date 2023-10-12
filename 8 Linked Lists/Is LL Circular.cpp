bool isCircular(Node* head){
    if(!head) return true;
    if(!head->next) return true;

    Node* temp = head;
    temp = temp->next;
    
    while(temp){
        if(temp == head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}