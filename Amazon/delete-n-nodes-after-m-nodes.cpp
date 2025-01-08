class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* temp = head;
        int skip = m;
        while(temp->next){
            if(skip == 1){
                Node* t = temp->next;
                int nodes = n;
                while(t and nodes--){
                    t = t->next;
                }
                temp->next = t;
                if(t == nullptr) return head;
                skip = m;
            }
            else skip--;
            temp = temp->next;
        }
        return head;
    }
};