/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *>q;      
        vector<vector<int>>vv;
        if(!root)
            return vv;
        
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
              vector<int>v;
            for(int i=0;i<l;i++)
            {
                TreeNode * temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
            vv.push_back(v);
        }
        reverse(vv.begin(),vv.end());
        return vv;
}