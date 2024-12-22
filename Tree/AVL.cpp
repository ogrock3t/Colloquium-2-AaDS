#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int key) : value(key), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    if (node != nullptr) return node->height;
    return 0;
}

void fix_height(Node* node) {
    if (node != nullptr) node->height = 1 + std::max(height(node->left), height(node->right));
}

int get_balance_factor(Node* node) {
    if (node != nullptr) return height(node->right) - height(node->left);
    return 0;
}

Node* left_rotation(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    fix_height(node);
    fix_height(temp);

    return temp;
}

Node* right_rotation(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    fix_height(node);
    fix_height(temp);

    return temp;
}

Node* balance(Node* node) {
    fix_height(node);
    int balance = get_balance_factor(node);

    if (balance > 1) {
        if (get_balance_factor(node->right) < 0) node->right = right_rotation(node->right);

        return left_rotation(node);
    }
    if (balance < -1) {
        if (get_balance_factor(node->left) > 0) node->left = left_rotation(node->left);

        return right_rotation(node);
    }

    return node;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->value) node->left = insert(node->left, key);
    else if (key > node->value) node->right = insert(node->right, key);
    else return node;

    return balance(node);
}

Node* find_max(Node* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* del(Node* node, int key) {
    if (node == nullptr) return nullptr;

    if (key < node->value) {
        node->left = del(node->left, key);
    } else if (key > node->value) {
        node->right = del(node->right, key);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp;

            if (node->left != nullptr) temp = node->left;
            else temp = node->right;

            delete node;
            return temp;
        } else {
            Node* max_left = find_max(node->left);
            node->value = max_left->value;
            node->left = del(node->left, max_left->value);
        }
    }
    return balance(node);
}
