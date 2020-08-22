/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>
#include <iostream>
#include <queue>
  
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        /* BFS */
        queue<TreeNode*> bfslist;
        if(root == nullptr) return 0;
        root->val = -1;
        bfslist.push(root);
      

        int depth = 0;
        int flag = 1;
        bool test_and_set = false;
        TreeNode* temp = nullptr;

        while(true)
        {
            temp = bfslist.front();
            bfslist.pop();

            if(temp -> val == -1) depth+=1;

            if(temp->left != nullptr)
            {
                if(temp->val == -1)
                {
                    temp->left->val = -1;
                }
                else
                {
                    temp->left->val = 0;
                }

                bfslist.push(temp->left);
                test_and_set = true;
            }
            if(temp->right != nullptr)
            {
                if(!test_and_set)
                {
                    if(temp->val == -1)
                    {
                        temp->right->val = -1;
                    }
                    else
                    {
                        temp->right->val = 0;
                    }
                    
                    bfslist.push(temp->right);
                    test_and_set = true;
                }
                else
                {
                    temp->right->val = 0;
                    bfslist.push(temp->right);
                }
            }

            if(!test_and_set) break;

            test_and_set = false;
        }

        return depth;
    }
};