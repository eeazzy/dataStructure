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

TreeNode *min_value_node(TreeNode *node){
    TreeNode *current = node;
    while (current->left != NULL) { // 가장 작은 값 찾기
        current = current->left;
    }
    return current;
}

TreeNode *delete_node(TreeNode *root, int key){
    if(root == NULL) return root; // 비워져있는 상태
    
    if(root->key > key){ // 찾으려는 값이 루트의 값보다 작다면
        root->left = delete_node(root->left, key);
    }
    else if (root->key < key){
        root->right = delete_node(root->right, key);
    }else{ // 삭제 값 찾음
        // 차수가 0인 경우, 1인 경우
        if(root->left == NULL){ // 오른쪽 자식 없는지 확인 안함
            TreeNode *temp = root->right;
            free(root);
            return temp; // 오른쪽 자식을 리턴해서 부모에게 넣어주려고
        }
        else if (root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 차수가 2인 경우
        TreeNode *temp = min_value_node(root->right);
        // 오른쪽에 있는것 중 가장 작은값 주소
        root->key = temp->key; // 루트에 값 복사
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

//       30
//   20      40
// 10          50
//           45  60

int main(void){
    TreeNode *root = NULL;
    root = insert_node(root,30);
    root = insert_node(root,20); // (30의 주소, 20)
    root = insert_node(root,40); // (30의 주소, 40)
    root = insert_node(root,10); // (30의 주소, 10)
    root = insert_node(root,50);
    root = insert_node(root,60);
    root = insert_node(root,45);
    
    inorder(root);  printf("\n");
    
    root = delete_node(root,10); // 10삭제
    printf("10삭제 : "); inorder(root);  printf("\n");
    root = delete_node(root,40); // 40삭제
    printf("40삭제 : "); inorder(root);  printf("\n");
    root = delete_node(root,50); // 50삭제
    printf("50삭제 : ");inorder(root);  printf("\n");
    
}
