#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;



struct Node* newNode(int item) {

	Node* newNode = malloc(sizeof(Node));
	
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->data=item;

return newNode;
}

struct Node* searchBST(struct Node* root, int key) {
    
    
    
    
    if(root==NULL){
    	
    	return NULL;
	}
	
	if(root->data<key){
		
		return searchBST(root->right,key);
		
	}
    else if (root->data>key){
    	
    	return 	searchBST(root->left,key);
	}
	
	else if(root->data==key){
		
		
		 return root;
	}
	
	
	
    
    
   
   
}

struct Node* insert(struct Node* node, int data) {
    
    if(node==NULL){
    	
    	return newNode(data);
	}
    
    
    if(data < node->data){
    	
    	node->left = insert(node->left,data);
    	
	}
    
    else if(data > node->data){
    	
    	node->right = insert(node->right,data);
    	
	}
    
    return node;
}




int height(Node* root){
	
	if(root == NULL){
		
		return 0;
		
	}
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	
	if(leftHeight>rightHeight){
		
		return leftHeight+1;
		
		
	}
	else{
		return rightHeight+1;
	}
	
}







int main(void){
	
	Node* root = NULL;
	
	root = insert(root,50);
	insert(root,10);
	insert(root,20);
	insert(root,30);
	insert(root,40);
	insert(root,60);
	insert(root,80);
	
	int item = 0;
	
	printf("hangi lavugu bulak:");
	scanf("%d",&item);
	
	
	Node* found = searchBST(root,item);
	
	if(found){
		
		printf("buldun:%d\n",item);
	}
	else{
		printf("yok knk\n");
	}
	int heights = height(root);
	
	printf("yukseklik:%d\n",heights);
	
	
	return 0;
}