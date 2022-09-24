
 
class Solution {
     //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1, num2;
        int mult1 = 1;
        for(ListNode * temp = l1; temp->next != nullptr; temp = temp->next){
            num1 += (temp->val)*mult1;
            mult1*=10;
        }
        int mult2=1;
        for(ListNode * temp = l2; temp->next != nullptr; temp = temp->next){
            num2 += (temp->val)*mult2;
            mult2*=10;
        }
        int sum = num1 + num2;
        ListNode * res;
        int mult = -1;
        if(mult1>mult2){
            mult = mult1;
        }
        else{
            mult = mult2;
        }
        for(ListNode * temp = res; mult !=1; mult/=10){
            temp->val = sum % mult;
            ListNode * temp2;
            temp -> next = temp2;
            temp = temp2;
        }
    }
};
