/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxdistance = 0;
public:
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        return maxdistance;
    }

    int find(TreeNode* root, int start){
        int depth = 0;
        if(root == nullptr) return depth;

        int leftdepth = find(root->left, start);
        int rightdepth = find(root->right, start);

        if(root->val == start){
            maxdistance = max(leftdepth, rightdepth);
            depth = -1;
        }
        else if(leftdepth >= 0 and rightdepth >= 0){
            depth = max(leftdepth, rightdepth) + 1;
        }
        else{
            int distance = abs(leftdepth) + abs(rightdepth);
            maxdistance = max(maxdistance, distance);
            depth = min(leftdepth, rightdepth) - 1;
        }

        return depth;
    }
};