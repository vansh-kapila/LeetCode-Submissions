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
    ListNode* swapNodes(ListNode* head, int k) {
        int x = 0;
        ListNode* p1=nullptr;
        ListNode* p2=nullptr;
        ListNode* dup = head;
        int n = 0;
        while(head!=nullptr)
        {   
            n++;
            head=head->next;
        }
        if(n<=1)
        {
            return dup;
        }
        head = dup;
        while(head!=nullptr)
        {   
            x++;
            if(p1==nullptr and x==n-k+1)
            {
                p1 = head;
            }
            if(p2==nullptr and x==k)
            {
                p2 = head;
            }
            head=head->next;
        }   
        swap(p1->val,p2->val);
        return dup;
    }
};