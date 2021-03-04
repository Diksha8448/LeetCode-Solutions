/*
Given a generic tree, find and return the height of given tree.

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3
*/
// Following is the given Tree node structure.
/**************
 template <typename T>
 class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;
 
        TreeNode(T data) {
            this->data = data;
        }
 
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
 };
***************/
int height(TreeNode<int>* root) {
    if(root==NULL)
        return 0;
    int max = 0;
    for(int i=0;i<root->children.size();i++){
        int temp = height(root->children[i]);
        if(temp>max)
            max=temp;
    }
    return max+1;

}
