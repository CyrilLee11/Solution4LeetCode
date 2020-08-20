/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count1 = 0;
        int count2 =0;
        int sum=0;
        int res=0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        for(int i=0;cur1!=nullptr;i++,cur1 = cur1->next)
        {
            //a = cur1->val * pow(10,i) + a; 
            count1++;
        }

        for(int i=0;cur2!=nullptr;i++,cur2 = cur2->next)
        {
            //a = cur2->val * pow(10,i) + a; 
            count2++;
        }

        int count = max(count1, count2);
        cur1 = l1;
        cur2 = l2;
        ListNode* modify = count > count1 ? l2 : l1;
        // ListNode* head = count <= count1 ? l1 : l2;
        int k=0;
        while(k < count)
        {
            if(k >= count1 || k >= count2)
            {
                if(modify->val >= 10)
                {
                    res = modify->val - 10;
                    modify->val = res;
                    if(modify->next == nullptr)
                    {
                        modify->next = new ListNode(1);
                    }
                    else
                    {
                        modify->next->val = modify->next->val + 1;
                    }
                }
                modify = modify -> next;
                k++;
            }
            else
            {
                sum = cur1->val + cur2 -> val;
                
                if(sum / 10 >= 1)
                {
                    res = sum - 10;
                    modify->val = res;
                    if(modify->next == nullptr)
                    {
                        modify->next = new ListNode(1);
                    }
                    else{
                        modify->next->val = modify->next->val + 1;
                    }
                }
                else{
                    modify->val = sum;
                }

                cur1 = cur1->next;
                cur2 = cur2->next;
                modify = modify -> next;
                k++;
            }
        }




        return count > count1 ? l2 : l1;
    }
};