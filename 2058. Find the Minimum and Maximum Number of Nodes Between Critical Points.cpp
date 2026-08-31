/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int f=-1;
        int pr=-1;
        ListNode* curr=head->next;
        ListNode* prev=head;
        int i=1;
        int mn=INT_MAX;
        while(curr->next!=NULL){
            if(((prev->val<curr->val&&curr->val>curr->next->val)||(prev->val>curr->val&&curr->val<curr->next->val))&&f==-1){
                f=i;
            }
            if((prev->val<curr->val&&curr->val>curr->next->val)||(prev->val>curr->val&&curr->val<curr->next->val)){
               if(pr!=-1) mn=min(mn,abs(pr-i));
                pr=i;
            }

            i++;
            prev=curr;
            curr=curr->next;
            
        }
        if (f==-1||f==pr) {
            return {-1,-1};
        }
        return {mn,pr-f};
    }
};
