/*
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true
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

bool containsX(TreeNode<int>* root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root==NULL)
        return 0;
    if(root->data==x)
        return true;
    bool ans = false;
    for(int i=0;i<root->children.size();i++){
        bool temp = containsX(root->children[i], x);
        if(temp==1 && ans ==0)
            ans=temp;
    }
    return ans;

}