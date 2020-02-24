#include <iostream>
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;

struct Node {
    int data;
    Node *right, *left;
}; 

class BSTRecursive{
    public: Node *root;

    public:

        void insertRec(Node *parentNode, Node *pNode, int pData, char leftorRight) {
            //cout<<"a 00000"<<endl;
             
            //if the pNode is the root then left aND RIGHT IS NULL
            if (pNode == NULL) {
                //cout<<"a 11111"<<endl;
                Node *newNode=new Node;
                newNode->data=pData;
                //cout<<"a 22222"<<endl;
                
                if (root== NULL)
                    root=newNode;
                //cout<<"a 33333"<<endl;

                if (leftorRight=='L')
                    parentNode->left = newNode;
                if (leftorRight=='R')
                    parentNode->right = newNode;
                //cout<<"a 444444"<<endl;
                
            }
            else {
                // if pNode is not root then decide whether the node has to be created to the left of the passed node or 
                // to the right of the passed node
                //cout<<"a 555555"<<endl;
                //cout<<"data:"<<pNode->data<<endl;
                //cout<<"a 66666"<<endl;

                if(pData< pNode->data)
                    insertRec(pNode, pNode->left, pData ,'L');
                else
                    insertRec(pNode, pNode->right, pData, 'R');
                
            }
            

        }
        void deleteRec(Node *parentNode, Node *pNode, int pData, char leftorRight) {
            //cout<<"a 00000"<<endl;
            if (pNode == NULL) {
                return;
            }
            else {
                //cout<<"00000 pNode data and pData:"<<pNode->data<<" "<<pData<<" "<<leftorRight<<endl;
                // if node to be deleted is to the left of the current root then traverse left
                if(pData < pNode->data) 
                    deleteRec(pNode, pNode->left, pData ,'L');
                // if node to be deleted is to the right of the current root then traverse right
                else if(pData> pNode->data) 
                    deleteRec(pNode, pNode->right, pData, 'R');
                else {
                    // found node to be deleted

                    //handle 3 scenarios
                    //1 - node has only left
                        //just remove the node
                    if (pNode->left == NULL) {
                        if (leftorRight == 'L')
                            parentNode->left = pNode->right;
                        if (leftorRight == 'R')
                            parentNode->right = pNode->right;
                        free(pNode);
                        return;
                    }
                    //2 - node has only right
                    else if (pNode->right == NULL) {
                        if (leftorRight == 'L')
                            parentNode->left = pNode->left;
                        if (leftorRight == 'R')
                            parentNode->right = pNode->left;
                        free(pNode);
                        return;
                    }
                    //3 - node has both left and right
                        //find min node to the right of the node
                        //copy the min node to the node to be deleted
                        //delete the min node
                    Node* current = pNode->right; 
                    Node* currentsParent = pNode; 
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL) { 
                        currentsParent = current;
                        current = current->left;
                    }
                    //cout<<endl<<"pNode's rights left: "<<current->data<<endl;
                    //cout<<"pNode's rights left parent: "<<currentsParent->data<<endl;

                    pNode->data = current->data;

                    deleteRec(pNode, pNode->right, current->data, 'R');

                }                

            }
           
        }
        int findNextRec(Node *parentNode, Node *pNode, int pData, char leftorRight) {
            //cout<<"a 00000"<<endl;
            int x;
            Node *tempNode;
            if(pData < pNode->data) 
                x=findNextRec(pNode, pNode->left, pData ,'L');
            // if node to be deleted is to the right of the current root then traverse right
            else if(pData> pNode->data) 
                x=findNextRec(pNode, pNode->right, pData, 'R');
            else {
                // match found then get the left if exists or right
                //cout<<"0000000 pNode data: "<<pNode->data<<endl;
                if (pNode->right!=NULL) {
                    //x=pNode->right->data;
                    tempNode = pNode->right;
                    // find next smallest, left most node to the right of the required number
                    while (tempNode->left != NULL) {
                        tempNode=tempNode->left;
                    }
                    x=tempNode->data;
                }
                else
                    if (parentNode != NULL && leftorRight=='L')
                        x=parentNode->data;
                    else
                        x=-99999999;
                
            }
            return x;
        }
        int findPrevRec(Node * parentNode, Node *pNode, int pData, char leftorRight) {
            //cout<<"a 00000"<<endl;
            int x;
            Node *tempNode;
            if(pData < pNode->data) 
                x=findPrevRec(pNode, pNode->left, pData ,'L');
            // if node to be deleted is to the right of the current root then traverse right
            else if(pData> pNode->data) 
                x=findPrevRec(pNode, pNode->right, pData, 'R');
            else {
                // match found then get the left if exists or right
                //cout<<"0000000 pNode data: "<<pNode->data<<endl;
                if (pNode->left!=NULL) {
                    //x=pNode->right->data;
                    tempNode = pNode->left;
                    // find prev greatest, left most node to the right of the required number
                    while (tempNode->right != NULL) {
                        tempNode=tempNode->right;
                    }
                    x=tempNode->data;
                }
                else
                    if (parentNode != NULL && leftorRight=='R')
                        x=parentNode->data;
                    else
                        x=-99999999;
                
            }
            return x;
        }
        int findMinRec(Node *pNode) {
            //cout<<"a 00000"<<endl;
            int x;
                
            if (pNode->left!=NULL)
                x=findMinRec(pNode->left);
            else
                return pNode->data;
            return x;            
        }    
        int findMaxRec(Node *pNode) {
            //cout<<"a 00000"<<endl;
            int x;
                
            if (pNode->right!=NULL)
                x=findMaxRec(pNode->right);
            else
                return pNode->data;
            return x;            
        }    
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
        
};
int main() {
    int x;
    BSTRecursive mytree;
    mytree.root=NULL;
    //struct Node *root;
    mytree.insertRec(mytree.root, mytree.root, 2, ' ');
    mytree.insertRec(mytree.root, mytree.root, 0, ' ');
    mytree.insertRec(mytree.root, mytree.root, 4, ' ');
    mytree.insertRec(mytree.root, mytree.root, 3, ' ');
    mytree.insertRec(mytree.root, mytree.root, 5, ' ');
    //mytree.insertRec(mytree.root, mytree.root, 12, ' ');
    //mytree.insertRec(mytree.root, mytree.root, 13, ' ');
    mytree.printTree(mytree.root);
/*
    cout<<endl;
    mytree.deleteRec(mytree.root, mytree.root, 5, ' ');
    cout<<"After delete"<<endl;
    mytree.printTree(mytree.root);
*/
    cout<<endl;
    x = mytree.findNextRec(mytree.root, mytree.root, 5, ' ');
    cout<<"find next: "<<x<<endl;

    cout<<endl;
    x = mytree.findPrevRec(mytree.root, mytree.root, 5, ' ');
    cout<<"find prev: "<<x<<endl;


    cout<<endl;
    x = mytree.findMinRec(mytree.root);
    cout<<"find min: "<<x<<endl;

    cout<<endl;
    x = mytree.findMaxRec(mytree.root);
    cout<<"find max: "<<x<<endl;
}