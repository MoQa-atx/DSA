#include <stdio.h>
#include <stdlib.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: FULL AVL TREE & ALL ROTATIONS
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. Rotation Operations:
 *    - rotateRight(root): Single right rotation for Left-Left (LL) imbalance.
 *    - rotateLeft(root): Single left rotation for Right-Right (RR) imbalance.
 *    - LR(root) & RL(root): Double rotations (Left-Right and Right-Left).
 *
 * 2. insertAVL(Node* root, int value):
 *    - Recursively inserts value like a standard BST, then computes
 *      balance = balanceFactor(root) on the way back up and rebalances:
 *      * LL Case (balance > 1 && value < root->left->data): rotateRight(root)
 *      * LR Case (balance > 1 && value > root->left->data):
 *        rotateLeft(root->left) followed by rotateRight(root)
 *      * RR Case (balance < -1 && value > root->right->data): rotateLeft(root)
 *      * RL Case (balance < -1 && value < root->right->data):
 *        rotateRight(root->right) followed by rotateLeft(root)
 *
 * 3. Comprehensive Rotation Tests:
 *    - Builds four separate AVL trees (rootA, rootB, rootC, rootD) to
 *      trigger and verify LL, RR, LR, and RL rotations via preorder() output.
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int balanceFactor(Node* root);
Node* createNode(int value){
	
	Node* newNode =malloc(sizeof(Node));
	if(newNode==NULL){
		
			return NULL;
		}
	
	
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->data=value;
	return newNode;
	
	
}



Node* insertBST(Node* root, int value){
	
	if(root==NULL){
		
		return	createNode(value);
		
	}
	
	if(value < root->data){
		
		root->left=insertBST(root->left,value);
			
				
		
	}
	else if(value > root->data){
		
		root->right=insertBST(root->right,value);
		
	}
	
	return root;
}

Node* rotateLeft(Node* root){
	
	
	Node * y = root->right;
	
	Node* temp = y->left;
	
	y->left= root;
	
	root->right=temp;
	
	return y;
}

Node* rotateRight(Node* root){


	Node* y = root->left;

	Node* temp = y->right;

	y->right = root;

	root->left = temp;

	return y;




}

Node* LR(Node* root){

root->left=rotateLeft(root->left);
return rotateRight(root);

}

Node* RL(Node* root){


root->right=rotateRight(root->right);
return rotateLeft(root);

}

Node* insertAVL(Node* root,int value){

	if(root==NULL){
		
		return	createNode(value);
		
	}

	
	if(value < root->data){
		
		root->left=insertAVL(root->left,value);
			
				
		
	}
	else if(value > root->data){
		
		root->right=insertAVL(root->right,value);
		
	}



	int balance = balanceFactor(root);

	if(balance > 1 && value < root->left->data ){

		return rotateRight(root);

	}
	else if(balance > 1 && value > root->left->data ){


		root->left=rotateLeft(root->left);

		return rotateRight(root);

	}
	else if(balance < -1 && value > root->right->data ){


		return rotateLeft(root);

	}
	else if(balance < -1 && value < root->right->data ){


		root->right=rotateRight(root->right);
		return rotateLeft(root);

	}


	return root;
}


int height(Node* root){
	
	if(root==NULL){
		
		return 0;
		
	}
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	
	
	
}

int balanceFactor (Node* root){
	
	if(root==NULL){
		
		return 0;
		
	}
	
	return height(root->left) - height(root->right);
	
	
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	
	
}

void preorder (Node* root){
	if(root==NULL){
		return;
	}
	
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	
}

int main(void){

    Node* rootA = NULL;
    Node* rootB = NULL;
    Node* rootC = NULL;
    Node* rootD = NULL;

    // Test A - LL
    rootA = insertAVL(rootA, 30);
    rootA = insertAVL(rootA, 20);
    rootA = insertAVL(rootA, 10);

    // Test B - RR
    rootB = insertAVL(rootB, 10);
    rootB = insertAVL(rootB, 20);
    rootB = insertAVL(rootB, 30);

    // Test C - LR
    rootC = insertAVL(rootC, 30);
    rootC = insertAVL(rootC, 10);
    rootC = insertAVL(rootC, 20);

    // Test D - RL
    rootD = insertAVL(rootD, 10);
    rootD = insertAVL(rootD, 30);
    rootD = insertAVL(rootD, 20);


    printf("Test A (LL)\n");
    printf("Root: %d\n", rootA->data);
    printf("Preorder: ");
    preorder(rootA);

    printf("\n\n");


    printf("Test B (RR)\n");
    printf("Root: %d\n", rootB->data);
    printf("Preorder: ");
    preorder(rootB);

    printf("\n\n");


    printf("Test C (LR)\n");
    printf("Root: %d\n", rootC->data);
    printf("Preorder: ");
    preorder(rootC);

    printf("\n\n");


    printf("Test D (RL)\n");
    printf("Root: %d\n", rootD->data);
    printf("Preorder: ");
    preorder(rootD);

    printf("\n");

    return 0;
}
