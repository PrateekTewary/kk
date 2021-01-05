#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    multimap<int , Node*> treeHb;
     //assign nodes with vertical levels
    void travel(Node* root, int n){
        if(root->left != NULL)  //assign vertical levels to left nodes of tree first
        {
            treeHb.insert(pair<int, Node*> (n-1,root->left) );
            travel(root->left, n-1);    //levels at left- ... -3, -2, -1
        } 
        if(root->right != NULL) //assign vertical levels to right nodes of tree
        {
            treeHb.insert(pair<int, Node*> (n+1,root->right) );
            travel(root->right, n+1);   //levels at right-                0, 1, 2, 3...
        }
        return;
    }
    
    void topView(Node * root) {
        if(root == NULL)
        return;
        treeHb.insert(pair<int, Node*> (0,root) );//insert root wth verticalHeight(Hb) =0
        travel( root, 0);   //insert left and right child with vertical height in MG
        
        //Perform Level-Order-Traversal and print element the same element if it exists in multigraph treeHb; thereafter delete all values with same key as printed
        //Standarad Level order traversal code
        queue<Node*> Q;
        Q.push(root);
        while( !Q.empty() ){
            Node* current = Q.front();
            if( current->left != NULL) Q.push(current->left);
            if( current->right != NULL ) Q.push(current->right);
            //check for same element as Q.front() in multigraph
            for(auto itr=treeHb.begin(); itr!=treeHb.end(); itr++ ){
                if( itr->second == Q.front() ){
                    cout << Q.front()->data << " ";
                    treeHb.erase( itr->first );
                    break;
                }
            }
            Q.pop();
        }
        
        return;
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
