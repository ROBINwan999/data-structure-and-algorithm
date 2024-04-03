#ifndef BST_H
#define BST_H

template<typename T>
class Bst;

template<typename T>
class TreeNode {
public:
    TreeNode();

    explicit TreeNode(const T &val);

private:
    T val_;
    TreeNode *left_;
    TreeNode *right_;

    friend class Bst<T>;
};

template<typename T>
TreeNode<T>::TreeNode() : val_(), left_(nullptr), right_(nullptr) {}

template<typename T>
TreeNode<T>::TreeNode(const T &val) : val_(val), left_(nullptr), right_(nullptr) {}

template<typename T>
class Bst {
public:
    typedef void (*func_ptr)(const T &);

    Bst();

    explicit Bst(const T &val);

    Bst(const Bst &rhs);

    Bst &operator=(const Bst &rhs);

    ~Bst();

    void insert(const T &val);

    bool search(const T &val) const;

    void preOrderTraversal(func_ptr fp) const;

    void inOrderTraversal(func_ptr fp) const;

    void postOrderTraversal(func_ptr fp) const;

private:
    TreeNode<T> *copy(TreeNode<T> *rhs);

    void destroy(TreeNode<T> *root);

    TreeNode<T> *insert(TreeNode<T> *root, const T &val);

    bool search(TreeNode<T> *root, const T &val) const;

    void preorder(TreeNode<T> *root, func_ptr fp) const;

    void inorder(TreeNode<T> *root, func_ptr fp) const;

    void postorder(TreeNode<T> *root, func_ptr fp) const;

private:
    TreeNode<T> *root_;
};

template<typename T>
Bst<T>::Bst(): root_(new TreeNode<T>()) {}

template<typename T>
Bst<T>::Bst(const T &val) : root_(new TreeNode<T>(val)) {}

template<typename T>
Bst<T>::Bst(const Bst &rhs) {
    if (rhs.root_ == nullptr)
        root_ = nullptr;
    else
        root_ = copy(rhs.root_);
}

template<typename T>
Bst<T> &Bst<T>::operator=(const Bst<T> &rhs) {
    if (this != &rhs) {
        if (root_ != nullptr) {
            destroy(root_);
        }

        if (rhs.root_ == nullptr) {
            root_ = nullptr;
        } else {
            root_ = copy(rhs.root_);
        }
    }

    return *this;
}

template<typename T>
Bst<T>::~Bst() {
    destroy(root_);
}

template<typename T>
TreeNode<T> *Bst<T>::copy(TreeNode<T> *rhs) {
    if (rhs != nullptr) {
        auto *lhs = new TreeNode<T>(rhs->val_);
        lhs->left_ = copy(rhs->left_);
        lhs->right_ = copy(rhs->right_);
        return lhs;
    } else {
        return nullptr;
    }
}

template<typename T>
void Bst<T>::insert(const T &val) {
    root_ = insert(root_, val);
}

template<typename T>
bool Bst<T>::search(const T &val) const {
    return search(root_, val);
}

template<typename T>
void Bst<T>::preOrderTraversal(func_ptr fp) const {
    preorder(root_, fp);
}

template<typename T>
void Bst<T>::inOrderTraversal(func_ptr fp) const {
    inorder(root_, fp);
}

template<typename T>
void Bst<T>::postOrderTraversal(func_ptr fp) const {
    postorder(root_, fp);
}

template<typename T>
void Bst<T>::destroy(TreeNode<T> *root) {
    if (root == nullptr)
        return;

    destroy(root->left_);
    destroy(root->right_);
    delete root;
}

template<typename T>
TreeNode<T> *Bst<T>::insert(TreeNode<T> *root, const T &val) {
    if (root == nullptr) {
        return new TreeNode<T>(val);
    } else {
        if (val < root->val_) {
            root->left_ = insert(root->left_, val);
        } else {
            root->right_ = insert(root->right_, val);
        }
    }

    return root;
}

template<typename T>
bool Bst<T>::search(TreeNode<T> *root, const T &val) const {
    if (root == nullptr) {
        return false;
    }

    if (val == root->val_) {
        return true;
    }

    return search(val < root->val_ ? root->left_ : root->right_, val);
}

template<typename T>
void Bst<T>::preorder(TreeNode<T> *root, func_ptr fp) const {
    if (root == nullptr)
        return;

    fp(root->val_);
    preorder(root->left_, fp);
    preorder(root->right_, fp);
}

template<typename T>
void Bst<T>::inorder(TreeNode<T> *root, func_ptr fp) const {
    if (root == nullptr)
        return;

    inorder(root->left_, fp);
    fp(root->val_);
    inorder(root->right_, fp);
}

template<typename T>
void Bst<T>::postorder(TreeNode<T> *root, func_ptr fp) const {
    if (root == nullptr)
        return;

    postorder(root->left_, fp);
    postorder(root->right_, fp);
    fp(root->val_);
}

#endif