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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) {
            return result;
        }
        string path = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
        } else {
            if (root->left != nullptr) {
                dfs(root->left, path, result);
            }
            if (root->right != nullptr) {
                dfs(root->right, path, result);
            }
        }
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        path += "->" + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, path, result);
        }
        if (node->right != nullptr) {
            dfs(node->right, path, result);
        }
    }
};
