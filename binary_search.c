#include<stdio.h>
#include<stdlib.h>
struct abc* create (int);
struct abc* insert(struct abc*, int );
void inorder(struct abc*);
void postorder(struct abc*);
void preorder(struct abc*);
void binary_search(struct abc* , int);
struct abc{
    int data;
    struct abc*left, *right;

};
void main(){
    struct abc*root = NULL;
    int key;
    root = insert(root , 10);
    root = insert(root , 5);
    root = insert(root , 20);
    root = insert(root , 4);
    root = insert(root , 6);
    root = insert(root , 18);
    root = insert(root , 30);
    root = insert(root , 40);
    printf("\nINORDER TRAVERSAL :\n");
    inorder(root);
    printf("\nPREORDER TRAVERSAL :\n");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL :\n");
    postorder(root);
    printf("\nENTER the number you want to search : ");
    scanf("%d" , &key);
    binary_search(root,key);
    
}
struct abc*create(int d){
    struct abc*temp;
    temp = (struct abc*)malloc(sizeof(struct abc));
    temp->data =d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct abc*insert(struct abc*root , int d){
    if(root==NULL){
        return create(d);
    }
    else if(root->data>d){
        root->left = insert(root->left , d);

    }
    else{
        root->right = insert(root->right ,d);
    }
    return root;
}
void inorder(struct abc*root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    printf("%d " , root->data);
    inorder(root->right);
}
void preorder(struct abc*root){
  
    if(root ==NULL){
        return;
    }
     printf("%d " , root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct abc*root){
    if(root ==NULL){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
 printf("%d " , root->data);
}
void binary_search(struct abc*root ,int key){
    if(root==NULL){
        printf(" NUMBER NOT FOUND\n");
    }
    if(root->data == key){
        printf("NUMBER IS PRESENT\n");
    }
    else if(root->data<key){
        binary_search(root->right ,key);
    }
    else{
        binary_search(root->left , key);

    }
}