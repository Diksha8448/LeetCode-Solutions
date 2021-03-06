/*
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:
*/
// Following is the given TreeNode structure.
/*

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
*/

#include<queue>

void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(pending.size()!=0){
        cout<<pending.front()->data<<":";
        for(int i=0;i<pending.front()->children.size();i++){
            cout<<pending.front()->children[i]->data;
            pending.push(pending.front()->children[i]);
            if(i<pending.front()->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
        pending.pop();
    }
}
