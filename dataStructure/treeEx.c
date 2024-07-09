//
//  treeEx.c
//  dataStructure
//
//  Created by 김현서 on 7/9/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
// 이진 탐색 트리
//          15
//       4         20
//    1          16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

// 중위 순회 LVR
void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left); // 왼쪽 서브트리 순회
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

// 전위 순회 VLR
void preorde(TreeNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->data); // root먼저
        preorde(root->left);
        preorde(root->right);
    }
}

// 후위 순회 LRV
void postorde(TreeNode *root) {
    if (root != NULL) {
        postorde(root->left);
        postorde(root->right);
        printf("[%d] ", root->data); 
    }
}
int main(void)
{
    printf("중위 순회=");
    inorder(root);
    printf("\n");

    printf("전위 순화=");
    preorde(root);
    printf("\n");

    printf("후위 순회=");
    postorde(root);
    printf("\n");
    return 0;
}
