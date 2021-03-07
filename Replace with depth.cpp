/*
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
0 
1 1 1 
2 2
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
void replaceWithDepthValueHelper(TreeNode<int> *root,int depth){
	root->data=depth;
	
	for(int i=0;i<root->children.size();i++){
		replaceWithDepthValueHelper(root->children[i],depth+1);
	}
}
void replaceWithDepthValue(TreeNode<int> *root){    
    if(root==NULL){
		return;
	}
	replaceWithDepthValueHelper(root,0);
}
