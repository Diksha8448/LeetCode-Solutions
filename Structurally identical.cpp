/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
*/
// Following is the Tree node structure
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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    queue<TreeNode<int>*> queue1;
    queue<TreeNode<int>*> queue2;
    queue1.push(root1);
    queue2.push(root2);
    bool ans = true;
    for(int i=0;i<root1->children.size();i++){
        queue1.push(root1->children[i]);
    }
    for(int i=0;i<root2->children.size();i++){
        queue2.push(root2->children[i]);
    }
    if(queue1.size()!=queue2.size())
        return false;
    for(int i=0;i<queue1.size();i++){
        if(queue1.front()->data == queue2.front()->data && ans!= false)
            ans = true;
    }
    return ans;

}