#include <algorithm>
#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void insert(struct node **root, int data);
void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);
int size(struct node *root);
int height(struct node *root);
int sumOfWeight(struct node *root);
int maxPathWeight(struct node *root);
void mirror(struct node **root);
void destruct(struct node **root);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int dataNum;
    struct node *root = nullptr;
    cin >> dataNum;
    for (int i = 0; i < dataNum; i++) {
      int data;
      cin >> data;
      insert(&root, data);
    }
    cout << size(root) << endl;
    cout << height(root) << endl;
    cout << sumOfWeight(root) << endl;
    cout << maxPathWeight(root) << endl;
    mirror(&root);
    preOrder(root);
    cout << "\n";
    inOrder(root);
    cout << "\n";
    postOrder(root);
    cout << "\n";
    destruct(&root);
    if (root == nullptr) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 데이터 삽입(recursion)
void insert(struct node **root, int data) {
  if ((*root) == nullptr) {
    node *newNode = new node();
    newNode->data = data;
    *root = newNode;
  }

  if (data < (*root)->data)
    insert(&(*root)->left, data);
  else if (data > (*root)->data)
    insert(&(*root)->right, data);
}

// 전위(preorder)탐색(recursion)
void preOrder(struct node *root) {
  if (root == nullptr)
    return;
  else {
    cout << (root->data) << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}
// 중위(inorder)탐색(recursion)
void inOrder(struct node *root) {
  if (root == nullptr)
    return;
  else {
    inOrder(root->left);
    cout << (root->data) << " ";
    inOrder(root->right);
  }
}
// 후위(postorder)탐색(recursion)
void postOrder(struct node *root) {
  if (root == nullptr)
    return;
  else {
    postOrder(root->left);
    postOrder(root->right);
    cout << (root->data) << " ";
  }
}

// 노드의 개수(recursion)
int size(struct node *root) {
  if (root == nullptr) return 0;

  int result = 1;
  result += size(root->left) + size(root->right);
  return result;
}

// 높이(recursion)
int height(struct node *root) {
  if (root == nullptr) return 0;

  int leftHeight = 0;
  int rightHeight = 0;
  if (root->left != nullptr) leftHeight = 1 + height(root->left);
  if (root->right != nullptr) rightHeight = 1 + height(root->right);
  return leftHeight > rightHeight ? leftHeight : rightHeight;
}

// 미러 이미지로 변환하기(recursion)
void mirror(struct node **root) {
  if (*root == nullptr) return;

  mirror(&(*root)->left);
  mirror(&(*root)->right);
  swap((*root)->left, (*root)->right);
}

// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node *root) {
  if (root == nullptr)
    return 0;
  else
    return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data;
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion)
int maxPathWeight(struct node *root) {
  if (root == nullptr)
    return 0;
  else {
    return root->data +
           max(maxPathWeight(root->left), maxPathWeight(root->right));
  }
}

// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node **root) {
  if ((*root)->left != nullptr) {
    destruct(&(*root)->left);
  }
  if ((*root)->right != nullptr) {
    destruct(&(*root)->right);
  }
  if (*root != nullptr) {
    *root = nullptr;
    delete *root;
  }
}