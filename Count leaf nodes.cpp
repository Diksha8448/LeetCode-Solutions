/*
Given a generic tree, count and return the number of leaf nodes present in the given tree.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4

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
int numLeafNodes(TreeNode<int>* root) {
    if(root==NULL)
        return 0;
    if(root->children.size()==0)
        return 1;
    int smallAns=0;
    for(int i=0;i<root->children.size();i++){
        smallAns+=numLeafNodes(root->children[i]);
    }
    return smallAns;
}
