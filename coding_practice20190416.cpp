//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList  剑指offer
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    //using namespace std;
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if(head==NULL)
            return result;
        stack<ListNode*> reverse;
        ListNode* node=head;
        while(node!=NULL){
            reverse.push(node);
            node=node->next;
            
        }
        while(!reverse.empty()){
            node=reverse.top();
            result.push_back(node->val);
            reverse.pop();
        }
        return result;
    }
};