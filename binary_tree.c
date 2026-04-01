#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构体
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// 前序遍历 (前根遍历)
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历 (中根遍历)
void inOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 后序遍历 (后根遍历)
void postOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// 查找节点
TreeNode* search(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// 查找最小值
TreeNode* findMin(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// 删除节点
TreeNode* delete(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        // 找到要删除的节点
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // 节点有两个子节点
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    
    return root;
}

// 释放树的内存
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 主函数
int main() {
    TreeNode* root = NULL;
    
    printf("=== 二叉搜索树实现演示 ===\n\n");
    
    // 插入节点
    printf("插入数据: 50, 30, 70, 20, 40, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // 前序遍历
    printf("\n前序遍历 (前根遍历): ");
    preOrder(root);
    printf("\n");
    
    // 中序遍历
    printf("中序遍历 (中根遍历): ");
    inOrder(root);
    printf("\n");
    
    // 后序遍历
    printf("后序遍历 (后根遍历): ");
    postOrder(root);
    printf("\n");
    
    // 搜索节点
    printf("\n搜索节点 40: ");
    if (search(root, 40) != NULL) {
        printf("找到\n");
    } else {
        printf("未找到\n");
    }
    
    printf("搜索节点 100: ");
    if (search(root, 100) != NULL) {
        printf("找到\n");
    } else {
        printf("未找到\n");
    }
    
    // 删除节点
    printf("\n删除节点 20\n");
    root = delete(root, 20);
    printf("删除后中序遍历: ");
    inOrder(root);
    printf("\n");
    
    // 释放内存
    freeTree(root);
    
    return 0;
}