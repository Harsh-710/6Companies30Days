class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){ return NULL; }
        if(lists.size()==1){ return lists[0]; }
    
        ListNode* ans = new ListNode;
        ListNode* t = ans;
        priority_queue<int,vector<int>, greater<int>> p;

        for(int i=0; i<lists.size(); i++){
            ListNode* tem = lists[i];
            while(tem != NULL){
                p.push(tem->val);
                tem = tem->next;
            }
        }
        while(!p.empty()){
            ListNode* n = new ListNode;
            n->val = p.top(); p.pop();
            t->next = n; t = n;
        }
        return ans->next;
    }
};