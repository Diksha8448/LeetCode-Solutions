/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.

Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 1 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
	void autoCompleteHelper(TrieNode *root,string pattern,string output){
		if(root==NULL){
			return;
		}
		if(pattern.size()==0){
			if(root->isTerminal){
				cout<<output<<endl;
			}
		}
		for(int i=0;i<26;++i){
			if(root->children[i]!=NULL){
				string s=output+root->children[i]->data;
				print(root->children[i],s);
			}
		}
		return;
		
		int index=pattern[0]-'a';
		output+=pattern[0];
		autoCompleteHelper(root->children[index],pattern.substr(1),output);
	}
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
		for(int i=0;i<input.size();++i){
			insertWord(input[i]);
		}
		string output="";
		autoCompleteHelper(root,pattern,output);
    }
};