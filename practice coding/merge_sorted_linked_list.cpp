
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* resultList;
        if(l1 == NULL && l2 == NULL){
            return l1;
        }else if(l1 == NULL && l2 != NULL){
            return l2;
        }else if(l1 != NULL && l2 == NULL){
            return l1;
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        while (temp1 != nullptr && temp2 != nullptr){
            if(temp1->val < temp2->val){
                //cout << temp1->val << endl;
                ListNode* newNode = new ListNode(temp1->val);
                if(tail == nullptr){
                    resultList = newNode;
                    tail = resultList;
                }else{
                    tail->next = newNode;
                    tail = newNode;
                }
                
                temp1 = temp1->next;
            }else{
                //cout << temp2->val << endl;
                ListNode* newNode = new ListNode(temp2->val);
                if(tail == nullptr){
                    resultList = newNode;
                    tail = resultList;
                }else{
                    tail->next = newNode;
                    tail = newNode;
                }
                temp2 = temp2->next;
            }
        }
        
        if (temp1 != nullptr){
            while(temp1 != nullptr){
                //cout << temp1->val << endl;
                ListNode* newNode = new ListNode(temp1->val);
                tail->next = newNode;
                tail = newNode;
                temp1 = temp1->next;
            }
        }
        else if (temp2 != nullptr){
            while(temp2 != nullptr){
                //cout << temp2->val << endl;
                ListNode* newNode = new ListNode(temp2->val);
                tail->next = newNode;
                tail = newNode;
                temp2 = temp2->next;
            }
        }
        
        return resultList;
    }
private:
    ListNode* tail;
};