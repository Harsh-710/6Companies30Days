class Solution {
public:    
    int solve(TreeNode* root, int &sum, int &minVal, int &maxVal) {
        if (!root) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return 0;
        }

        int leftSum = 0, rightSum = 0;
        int leftMin = INT_MAX, leftMax = INT_MIN;
        int rightMin = INT_MAX, rightMax = INT_MIN;

        leftSum = solve(root->left, sum, leftMin, leftMax);
        rightSum = solve(root->right, sum, rightMin, rightMax);

        bool isValidBST = (!root->left || root->val > leftMax) &&
                          (!root->right || root->val < rightMin);

        if (isValidBST) {
            int currSum = root->val + leftSum + rightSum;
            sum = max(sum, currSum);
            minVal = min(root->val, leftMin);
            maxVal = max(root->val, rightMax);
            return currSum;
        } else {
            minVal = INT_MIN;
            maxVal = INT_MAX;
            return 0;
        }
    }
    
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        int minVal, maxVal;
        solve(root, maxSum, minVal, maxVal);
        return maxSum;
    }
};