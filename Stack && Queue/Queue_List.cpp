struct Node {
    int value;
    Node* next = nullptr;
};

struct Queue {
    Node *head = nullptr;
    Node *tail = nullptr;

    void push(int key) {
        Node *temp = new Node;
        temp->value = key;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int pop() {
        int key = head->value;
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        return key;
    }
};