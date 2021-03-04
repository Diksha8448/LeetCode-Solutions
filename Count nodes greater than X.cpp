/*
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
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

int nodesGreaterThanX(TreeNode<int> *root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root==NULL)
        return 0;
    int count=0;
    if (root->data > x) 
        count++; 
   // bool ans = false;
   // int numChildren = root->children.size(); 
    for(int i=0;i<root->children.size();i++){
       // int temp = nodesGreaterThanX(root->children[i], x);
        count += nodesGreaterThanX(root->children[i], x);
       // if(temp==1 && ans ==0)
        //    ans=temp;
    }
    return count;
}