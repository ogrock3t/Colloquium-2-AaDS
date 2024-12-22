struct Node {
    int value;
    Node* next;
};

struct Stack {
    Node *tail = nullptr;

    void push(int key) {
        Node *temp = new Node;
        temp->value = key;
        temp->next = tail;
        tail = temp;
    }

    int pop() {
        Node *temp = tail;
        int key = temp->value;
        tail = tail->next;
        delete temp;

        return key;
    }
};
