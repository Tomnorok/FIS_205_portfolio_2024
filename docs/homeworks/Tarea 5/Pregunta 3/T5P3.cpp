#include <iostream>
#include <stdexcept> // Para std::out_of_range

// En la clase Folder
void insertNodeAt(string &name, int &age, int &ID, double &GPA, int i);
void deleteNodeAt(int i);
void swapNodes(int i, int j);
void reverseList();
int getListSize();

void Folder::insertNodeAt(string &name, int &age, int &ID, double &GPA, int i) {
    Node *newNode = new Node(name, age, ID, GPA);
    if (i == 0) {
        newNode->next = root;
        root = newNode;
        return;
    }

    Node *current = root;
    for (int k = 0; current != NULL && k < i - 1; ++k) {
        current = current->next;
    }
    
    if (current == NULL) {
        throw std::out_of_range("Index out of range");
    }

    newNode->next = current->next;
    current->next = newNode;
}

void Folder::deleteNodeAt(int i) {
    if (root == NULL) {
        throw std::out_of_range("List is empty");
    }
    Node *temp = root;
    if (i == 0) {
        root = root->next;
        delete temp;
        return;
    }

    for (int k = 0; temp != NULL && k < i - 1; ++k) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        throw std::out_of_range("Index out of range");
    }

    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void Folder::swapNodes(int i, int j) {
    if (i == j) return;

    Node **pi = &root, **pj = &root, *node_i, *node_j;

    for (int pos = 0; pos < i && *pi != NULL; pos++) {
        pi = &((*pi)->next);
    }
    for (int pos = 0; pos < j && *pj != NULL; pos++) {
        pj = &((*pj)->next);
    }

    if (*pi == NULL || *pj == NULL) {
        throw std::out_of_range("Index out of range");
    }

    node_i = *pi;
    node_j = *pj;
    std::swap(node_i->next, node_j->next);
    std::swap(*pi, *pj);
}

void Folder::reverseList() {
    Node *prev = NULL, *current = root, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    root = prev;
}

int Folder::getListSize() {
    int count = 0;
    Node *current = root;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
