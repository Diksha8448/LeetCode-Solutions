/*
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     TreeNode<int>* max = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp->data>max->data)
            max=temp;
    }
    return max;

}
