// https://leetcode.com/problems/path-sum-ii/submissions/

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
public:
    vector<vector<int>>answer;
    void dfs(TreeNode * cur, int targetSum, int total, vector<int>v) {
        if(!cur) return;
        total += cur-> val;
        v.push_back(cur->val);
        if(total == targetSum && !(cur->left) && !(cur->right)){
            answer.push_back(v);
            return;
        }
        dfs(cur->left, targetSum, total, v);
        dfs(cur->right, targetSum, total, v);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0, vector<int>());
        return answer;
    }
};
