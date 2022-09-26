#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* add2sum(ListNode* l1, ListNode* l2) {

    int num1=0;
    int num2=0;
    int mult1 = 1;
    int mult2=1;

    for(ListNode * temp = l1; temp != nullptr; temp = temp->next){
        num1 += (temp->val)*mult1;
        mult1*=10;
    }



    for(ListNode * temp = l2; temp != nullptr; temp = temp->next){
        num2 += (temp->val)*mult2;
        mult2*=10;
    }

    int sum = num1 + num2;
    int mult = 1;
    int c = -1;
    while(c!=sum){
        c = sum % mult;
        mult*=10;
    }
    mult/=10;
    cout<<sum<<endl;
    ListNode * ret = new ListNode();
    for(ListNode*temp = ret; mult!=1; mult/=10){
        if(mult==10){
            int temp2 = sum;
            temp->val = temp2;
            cout<<temp2<<endl;
            break;
        }
        int temp2 = sum%(10);
        cout<<temp2<<endl;
        temp->val = temp2;
        sum-=temp2;
        sum/=10;
        temp->next = new ListNode();
        temp = temp->next;
    }
    return ret;
}
int main(){
    ListNode * l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);

    ListNode * l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);

    ListNode * l3 = add2sum(l1,l2);
}