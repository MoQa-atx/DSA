#include <stdio.h>

/*
 * ============================================================================
 * DATA STRUCTURES & ALGORITHMS - LAB ASSIGNMENT: AVL BALANCE FACTOR & LEFT ROTATION
 * ============================================================================
 *
 * OVERVIEW & LOGIC:
 *
 * 1. BST Insertion & Height Calculation:
 *    - insertBST() inserts keys (10, 20, 30) into the tree.
 *    - height() computes the height of any subtree recursively.
 *
 * 2. balanceFactor(Node* root):
 *    - Computes height(root->left) - height(root->right) to monitor balance.
 *    - A balance factor of -2 indicates a Right-Right (RR) heavy imbalance.
 *
 * 3. rotateLeft(Node* root):
 *    - Restores balance on RR imbalance by promoting y = root->right to the
 *      new subtree root, moving root to y->left, and attaching y's old
 *      left child (temp) to root->right.
 *
 * 4. Traversal Verification:
 *    - Prints both inorder() and preorder() traversals along with the new
 *      root and updated balance factor (0) to confirm rebalancing.
 * ============================================================================
 */

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int value){
	
	Node* newNode =malloc(sizeof(Node));
	if(newNode==NULL){
		
			return;
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
	
	Node* root = NULL;

    printf("Inserting 10...\n");
    root = insertBST(root, 10);
    printf("10 inserted. Root BF: %d\n\n", balanceFactor(root));

    printf("Inserting 20...\n");
    root = insertBST(root, 20);
    printf("20 inserted. Root BF: %d\n\n", balanceFactor(root));

    printf("Inserting 30...\n");
    root = insertBST(root, 30);
    printf("30 inserted. Root BF: %d\n\n", balanceFactor(root));

    if(balanceFactor(root) == -2){
        printf("RR Imbalance detected!\n");
        printf("Performing Left Rotation...\n");

        root = rotateLeft(root);
    }

    printf("\nRotation completed!\n");
    printf("New Root: %d\n", root->data);
    printf("Root Balance Factor: %d\n", balanceFactor(root));

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\n");


   

    return 0;
}
