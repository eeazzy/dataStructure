//
//  create_tree.c
//  dataStructure
//
//  Created by 김현서 on 7/9/24.
//

#include <stdio.h>
#include <stdlib.h>
// 이진 탐색 트리 만들기

typedef int element;
typedef struct TreeNode{
    struct TreeNode *left;
    element key;
    struct TreeNode *right;
}TreeNode;

TreeNode *new_node(element item){ // 초기화 & 값넣기
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    
    return temp; // 20 넣으면 20의 주소 리턴
}

TreeNode *insert_node(TreeNode * node, element key){
    if(node == NULL) return new_node(key); // 처음 삽입

    if (key < node->key){ // 30이 20보다 작음?
        node->left = insert_node(node->left, key);
        // 30이 가리키고 있는 왼쪽은 NULL이므로 new node 호출된다
    }
    else if (key > node->key){
        node->right = insert_node(node->right, key);
    }
    
    return node;
}

// 중위 순회 LVR
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}
// 전위 순회 VLR
void preorde(TreeNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->key);
        preorde(root->left);
        preorde(root->right);
    }
}

// 후위 순회 LRV
void postorde(TreeNode *root) {
    if (root != NULL) {
        postorde(root->left);
        postorde(root->right);
        printf("[%d] ", root->key);
    }
}

int main(void){
    TreeNode *root = NULL;
    root = insert_node(root,30);
    root = insert_node(root,20); // (30의 주소, 20)
    root = insert_node(root,40); // (30의 주소, 40)
    root = insert_node(root,10); // (30의 주소, 10)
    root = insert_node(root,50);
    
    inorder(root);  printf("\n");
    preorde(root);  printf("\n");
    postorde(root); printf("\n");
}
