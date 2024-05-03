Folder::Folder() : root(NULL) {}

Folder::~Folder() {
    Node *current = root;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
