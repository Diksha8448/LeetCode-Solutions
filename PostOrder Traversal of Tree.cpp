/*
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.

Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10

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

void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
     if(root ==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";

}
