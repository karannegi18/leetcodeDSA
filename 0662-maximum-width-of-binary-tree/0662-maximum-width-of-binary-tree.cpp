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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long maxWidth = 0;
        std::queue<std::pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            long long size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            maxWidth = std::max(maxWidth, end - start + 1);

            for (long long i = 0; i < size; ++i) {
                auto [node, index] = q.front();
                q.pop();
                long long normalizedIndex = index - start;
                
                if (node->left) {
                    q.push({node->left, 2 * normalizedIndex + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalizedIndex + 2});
                }
            }
        }
        return maxWidth;
    }
};