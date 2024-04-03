#ifndef AVL_H
#define AVL_H

#include <queue>
#include <iostream>

using std::max;

template<typename T>
class AVL;

template<typename T>
class TreeNode {
public:
    TreeNode();

    explicit TreeNode(const T &data);

    friend AVL<T>;
private:
    T val;
    int height;
    TreeNode *left;
    TreeNode *right;
};

template<typename T>
TreeNode<T>::TreeNode() : val(), height(0), left(nullptr), right(nullptr) {}

template<typename T>
TreeNode<T>::TreeNode(const T &data) : val(data), height(1), left(nullptr), right(nullptr) {}

template<typename T>
class AVL {
public:
    AVL();

    AVL(const AVL<T> &rhs);

    AVL &operator=(const AVL<T> &rhs);

    ~AVL();

    void insert(const T &data);

    bool search(const T &data);

    void preorder();

    void inorder();

    void postorder();

private:
    TreeNode<T> *copy(TreeNode<T> *rhs);

    void destroy(TreeNode<T> *root);

    int height(TreeNode<T> *root) const;

    TreeNode<T> *leftRotation(TreeNode<T> *root);

    TreeNode<T> *rightRotation(TreeNode<T> *root);

    TreeNode<T> *insert(TreeNode<T> *root, const T &data);

    bool search(TreeNode<T> *root, const T &data) const;

    void preorder(TreeNode<T> *root);

    void inorder(TreeNode<T> *root);

    void postorder(TreeNode<T> *root);

private:
    TreeNode<T> *root_;
};

template<typename T>
AVL<T>::AVL() : root_(nullptr) {}

template<typename T>
AVL<T>::AVL(const AVL<T> &rhs):root_(copy(rhs.root_)) {}

template<typename T>
AVL<T> &AVL<T>::operator=(const AVL<T> &rhs) {
    if (this != &rhs) {
        if (root_ != nullptr) {
            destroy(root_);
        }

        if (rhs.root_ == nullptr) {
            root_ = copy(rhs.root_);
        } else {
            root_ = rhs.root_;
        }
    }

    return *this;
}

template<typename T>
AVL<T>::~AVL() {
    destroy(root_);
}

template<typename T>
void AVL<T>::insert(const T &data) {
    root_ = insert(root_, data);
}

template<typename T>
bool AVL<T>::search(const T &data) {
    return search(root_, data);
}

template<typename T>
void AVL<T>::preorder() {
    preorder(root_);
    std::cout << '\n';
}

template<typename T>
void AVL<T>::inorder() {
    inorder(root_);
    std::cout << '\n';
}

template<typename T>
void AVL<T>::postorder() {
    postorder(root_);
    std::cout << '\n';
}

template<typename T>
TreeNode<T> *AVL<T>::copy(TreeNode<T> *rhs) {
    if (rhs != nullptr) {
        auto *lhs = new TreeNode<T>();
        lhs->val = rhs->val;
        lhs->left = copy(rhs->left);
        lhs->right = copy(rhs->right);
        return lhs;
    } else {
        return nullptr;
    }
}

template<typename T>
void AVL<T>::destroy(TreeNode<T> *root) {
    if (root == nullptr)
        return;

    destroy(root->left);
    destroy(root->right);
    delete root;
}

template<typename T>
int AVL<T>::height(TreeNode<T> *root) const {
    if (root == nullptr)
        return 0;

    return root->height;
}

template<typename T>
TreeNode<T> *AVL<T>::leftRotation(TreeNode<T> *root) {
    TreeNode<T> *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = 1 + max(height(root->left), height(root->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));

    return tmp;
}

template<typename T>
TreeNode<T> *AVL<T>::rightRotation(TreeNode<T> *root) {
    auto tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = 1 + max(height(root->left), height(root->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));

    return tmp;
}

template<typename T>
TreeNode<T> *AVL<T>::insert(TreeNode<T> *root, const T &data) {
    if (root == nullptr)
        return new TreeNode<T>(data);

    if (data < root->val)
        root->left = insert(root->left, data);
    else if (data > root->val)
        root->right = insert(root->right, data);

    root->height = 1 + max(height(root->left), height(root->right));
    int balance_factor = height(root->left) - height(root->right);

    if (balance_factor > 1) {
        if (data < root->left->val) {
            return rightRotation(root);
        } else {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    } else if (balance_factor < -1) {
        if (data > root->right->val) {
            return leftRotation(root);
        } else {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}

template<typename T>
bool AVL<T>::search(TreeNode<T> *root, const T &data) const {
    if (root == nullptr)
        return false;

    std::queue<TreeNode<T> *> q;
    q.push(root);

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        if (tmp->val == data)
            return true;

        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }

    return false;
}

template<typename T>
void AVL<T>::preorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;

    std::cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

template<typename T>
void AVL<T>::inorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->val << ' ';
    inorder(root->right);
}

template<typename T>
void AVL<T>::postorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << ' ';
}

#endif