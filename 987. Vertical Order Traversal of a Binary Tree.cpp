/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.


*/

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
    map<int, map<int, vector<int>>> hmap; // <col, <row, <list of values>>

    void dfs(TreeNode *node, int col, int row)
    {
        if (!node)
            return;

        hmap[col][row].push_back(node->val);

        dfs(node->left, col-1, row+1);
        dfs(node->right, col+1, row+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        if (!root)
            return result;

        dfs(root, 0, 0);

        for (auto cols : hmap)
        {
            vector<int> tmp;
            for (auto row : cols.second)
            {
                std::sort(row.second.begin(), row.second.end());
                for (auto val : row.second)
                    tmp.push_back(val);
            }
            result.push_back(tmp);
        }
        return result;
    }
   
};