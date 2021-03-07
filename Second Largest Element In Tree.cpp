/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
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
template<typename T>
class SecondLargestReturnType{
	public:
	  TreeNode<T> *largest;
	  TreeNode<T> *secondLargest;
	  
	  SecondLargestReturnType(TreeNode<T> *first,TreeNode<T> *second){
		  this->largest=first;
		  this->secondLargest=second;
	  }
};
SecondLargestReturnType<int> *getSecondLargestNodeHelper(TreeNode<int> *root){
	if(root==NULL){
		return new SecondLargestReturnType<int>(NULL,NULL);
	}
	
	SecondLargestReturnType<int> *ans=new SecondLargestReturnType<int>(rrot,NULL);
	
	for(int i=0;i<root->children.size();i++){
		SecondLargestReturnType<int> *childAns=getSecondLargestNodeHelper(root->children[i]);
		
		if(childAns->Largest->data>ans->Largest->data){
			if(childAns->secondLargest==NULL){
				ans->secondLargest=ans->largest;
				ans->largest=childAns->largest;
			}else{
				if(childAns->secondLargest->data>ans->largest->data){
					ans->secondLargest=childAns->secondLargest;
					ans->largest=childAns->largest;
				}else{
					ans->secondLargest=ans->largest;
					ans->largest=childAns->largest;
				}
			}
		}else{
			if(ans->largest->data!=childAns->largest->data &&(ans->secondLargest==NULL||childAns->largest->data >ans->secondLargest->data)){
				ans->secondLargest=childAns->largest;
			}
		}
	}
	return ans;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    return getSecondLargestNodeHelper(root)->secondLargest;
}
