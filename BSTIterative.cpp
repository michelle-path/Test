#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;

struct Node {
    int data;
    Node *right, *left;
}; 

class BSTIterative{
    public: Node *root;

    public:
        void printTree( Node *pNode) {

            //int i;
            if(pNode==NULL) {
                return;
            }
            //cout<<pNode->data<<" ";
            printTree(pNode->left);
            cout<<pNode->data<<" ";
            printTree(pNode->right);
           
        }
        void insertIter(int pData) {
            //cout<<"a 00000"<<endl;
            Node *tempNode, *parentNode;
            char leftOrRight;
            
	        Node *newNode=new Node;
	        newNode->data=pData;

            if (root== NULL)
                //root node
                root=newNode;
            else {
                //not root node, find position to insert
                tempNode = root;
                while (tempNode!= NULL) {
                    
                    parentNode = tempNode;
                    //cout<<"pData tempNode parentNode: "<<pData<<" "<<tempNode->data<<" "<<parentNode->data<<endl;
                    if (pData < tempNode->data) {
                        tempNode = tempNode->left;
                        leftOrRight='L';
                    }
                    else {
                        tempNode = tempNode->right;
                        leftOrRight='R';
                    }
                }
                //cout<<"********* out of loop: LR: "<<leftOrRight<<endl;
                if (leftOrRight=='L')
                    parentNode->left = newNode;
                else                
                    parentNode->right = newNode;
            }
            

        }
        
        void deleteIter(int pData) {
            Node *tempNode, *parentNode;
            char leftOrRight;
            bool found=false;
            
            //cout<<"a 00000"<<endl;
            if (root == NULL) {
                return;
            }
            else {
                
                tempNode = root;
                parentNode=NULL;
                while (tempNode!= NULL) {
                    
                    
                    //cout<<"pData tempNode parentNode: "<<pData<<" "<<tempNode->data<<" "<<parentNode->data<<endl;
                    if (pData < tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->left;
                        leftOrRight='L';
                    }
                    else if (pData > tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->right;
                        leftOrRight='R';
                    }
                    else {
                        //data found in tempNode
                        found=true;
                        break;
                    }
                }
                if (found) {
                    //handle 3 scenarios
                    //1 - node has only left
                        //just remove the node
                    if (tempNode->left == NULL) {
                        if (leftOrRight == 'L')
                            parentNode->left = tempNode->right;
                        if (leftOrRight == 'R')
                            parentNode->right = tempNode->right;
                        free(tempNode);
                        return;
                    }
                    //2 - node has only right
                    else if (tempNode->right == NULL) {
                        if (leftOrRight == 'L')
                            parentNode->left = tempNode->left;
                        if (leftOrRight == 'R')
                            parentNode->right = tempNode->left;
                        free(tempNode);
                        return;
                    }
                    //3 - node has both left and right
                        //find min node to the right of the node
                        //copy the min node to the node to be deleted
                        //delete the min node
                    Node* current = tempNode->right; 
                    Node* currentsParent = tempNode; 
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL) { 
                        currentsParent = current;
                        current = current->left;
                    
                    }
                    //cout<<endl<<"pNode's rights left: "<<current->data<<endl;
                    //cout<<"pNode's rights left parent: "<<currentsParent->data<<endl;
                    currentsParent->left = current->right; 
                    tempNode->data = current->data;

                    free(current);
                    return;
                }
                

            }
           
        }
        int findNextIter(int pData) {
            Node *tempNode, *parentNode;
            char leftOrRight;
            bool found=false;
            int x=-99999999;
            
            //cout<<"a 00000"<<endl;
            if (root == NULL) {
                return x;
            }
            else {
                
                tempNode = root;
                parentNode=NULL;
                while (tempNode!= NULL) {
                    
                    
                    //cout<<"pData tempNode parentNode: "<<pData<<" "<<tempNode->data<<" "<<parentNode->data<<endl;
                    if (pData < tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->left;
                        leftOrRight='L';
                    }
                    else if (pData > tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->right;
                        leftOrRight='R';
                    }
                    else {
                        //data found in tempNode
                        found=true;
                        break;
                    }
                }
                if (found) {
                    // match found then get the left if exists or right
                    //cout<<"0000000 pNode data: "<<pNode->data<<endl;
                    if (tempNode->right!=NULL) {
                        //x=pNode->right->data;
                        tempNode = tempNode->right;
                        // find next smallest, left most node to the right of the required number
                        while (tempNode->left != NULL) {
                            tempNode=tempNode->left;
                        }
                        x=tempNode->data;
                    }
                    else
                        if (parentNode != NULL && leftOrRight=='L')
                            x=parentNode->data;
                        else
                            x=-99999999;
                }
                
            }      
            return x;
        }   
            
 
        int findPrevIter(int pData) {
            Node *tempNode, *parentNode;
            char leftOrRight;
            bool found=false;
            int x=-99999999;
            
            //cout<<"a 00000"<<endl;
            if (root == NULL) {
                return x;
            }
            else {
                
                tempNode = root;
                parentNode=NULL;
                while (tempNode!= NULL) {
                    
                    
                    //cout<<"pData tempNode parentNode: "<<pData<<" "<<tempNode->data<<" "<<parentNode->data<<endl;
                    if (pData < tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->left;
                        leftOrRight='L';
                    }
                    else if (pData > tempNode->data) {
                        parentNode = tempNode;
                        tempNode = tempNode->right;
                        leftOrRight='R';
                    }
                    else {
                        //data found in tempNode
                        found=true;
                        break;
                    }
                }
                if (found) {
                    // match found then get the left if exists or right
                    //cout<<"0000000 pNode data: "<<pNode->data<<endl;
                    if (tempNode->left!=NULL) {
                        //x=pNode->right->data;
                        tempNode = tempNode->left;
                        // find next smallest, left most node to the right of the required number
                        while (tempNode->right != NULL) {
                            tempNode=tempNode->right;
                        }
                        x=tempNode->data;
                    }
                    else
                        if (parentNode != NULL && leftOrRight=='R')
                            x=parentNode->data;
                        else
                            x=-99999999;
                }
                
            }      
            return x;
        } 
        int findMinIter() {
            //cout<<"a 00000"<<endl;
            Node * tempNode=root;
            Node * parentNode=NULL;
            
            while (tempNode!=NULL) {
                parentNode = tempNode;
                tempNode=tempNode->left;
            }
            return parentNode->data;
                        
        }    
        int findMaxIter() {
            Node * tempNode=root;
            Node * parentNode=NULL;
            
            while (tempNode!=NULL) {
                parentNode = tempNode;
                tempNode=tempNode->right;
            }
            return parentNode->data;
        }    

        
};
int main() {
    int x;
    BSTIterative mytree;
    mytree.root=NULL;
    //struct Node *root;
    mytree.insertIter(2);
    mytree.insertIter(0);
    mytree.insertIter(4);
    mytree.insertIter(3);
    mytree.insertIter(5);

    mytree.printTree(mytree.root);

/*

    cout<<endl;
    mytree.deleteIter(3);
    cout<<"After delete 3"<<endl;
    mytree.printTree(mytree.root);

*/
/*    
    cout<<endl;
    x = mytree.findNextIter(5);
    cout<<"find next: "<<x<<endl;
*/

/*    
    cout<<endl;
    x = mytree.findPrevIter(5);
    cout<<"find prev: "<<x<<endl;
*/
    cout<<endl;
    x = mytree.findMinIter();
    cout<<"find min: "<<x<<endl;


    cout<<endl;
    x = mytree.findMaxIter();
    cout<<"find max: "<<x<<endl;

}