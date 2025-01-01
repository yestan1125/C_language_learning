#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的节点结构
typedef struct TreeNode {
    int value;               // 节点的值
    struct TreeNode *left;   // 左子树
    struct TreeNode *right;  // 右子树
} TreeNode;

// 创建一个新的树节点
TreeNode* createNode(int value) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入一个节点到二叉搜索树
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// 前序遍历（根 -> 左 -> 右）
void preOrder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历（左 -> 根 -> 右）
void inOrder(TreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

// 后序遍历（左 -> 右 -> 根）
void postOrder(TreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

// 查找二叉树中某个节点
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    
    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// 删除二叉树中的一个节点
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) return root;

    // 找到要删除的节点
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // 节点被找到，进行删除操作

        // 如果节点没有子节点
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // 如果节点有一个子节点
        else if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        // 如果节点有两个子节点
        else {
            // 找到右子树中的最小节点
            TreeNode *minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }

            // 用右子树的最小节点替换当前节点
            root->value = minNode->value;

            // 删除右子树中的最小节点
            root->right = deleteNode(root->right, minNode->value);
        }
    }
    
    return root;
}

// 释放二叉树的内存
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// 主函数，测试二叉树的功能
int main() {
    TreeNode* root = NULL;

    // 插入一些节点到二叉树中
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // 打印树的前序遍历
    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    // 打印树的中序遍历
    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    // 打印树的后序遍历
    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    // 查找一个节点
    int searchValue = 40;
    TreeNode* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Found node with value: %d\n", searchResult->value);
    } else {
        printf("Node with value %d not found\n", searchValue);
    }

    // 删除一个节点
    printf("Deleting node with value 20\n");
    root = deleteNode(root, 20);

    // 打印树的中序遍历，确认删除
    printf("Inorder traversal after deletion: ");
    inOrder(root);
    printf("\n");

    // 释放树的内存
    freeTree(root);

    return 0;
}
