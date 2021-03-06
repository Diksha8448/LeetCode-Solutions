/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/
// Following is the given Tree node structure
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

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    queue<TreeNode<int>*> pending;
    if(root==NULL)
        return root;
    pending.push(root);
    int ans=0;
    TreeNode<int>* ansNode=root;
    while(pending.size()!=0){
        int roots = pending.front()->data;
        int temp=0;
        for(int i = 0;i<pending.front()->children.size();i++){
            temp+= pending.front()->children[i]->data;
            pending.push(pending.front()->children[i]);
        }
        roots = temp+roots;
        if(roots>ans){
            ans=roots;
            ansNode = pending.front();
        }
        pending.pop();
    }
    return ansNode;

}
