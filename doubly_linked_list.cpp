#include <cstdio>
#include <cstdlib>

class List {
private:
    typedef struct Node {
        int data;
        struct Node* next_ptr;
        struct Node* prev_ptr;
    } node;

    node* head;
    node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        node* cur = head;
        while (cur != NULL) {
            node* next_node = cur->next_ptr;
            free(cur);
            cur = next_node;
        }
    }

    int is_empty(); // checks whether the list is empty
    void insert_beg(int value); // Inserts an element in the first position or the 0th index
    void insert_end(int value); // Inserts an element in the last position
    void insert_pos(int value, int ind); // Inserts an element at any given position
    int delete_beg(); // Deletes the first element 
    int delete_end(); // Deletes the last element
    int delete_pos(int ind); // Deletes the element at any given position
    void display(); // Displays the list
    int search(int value);//Returns the index at which the element was found
};

int main() {
    int flag = 1;
    List list1;
    int element;
    int index;
    int buffer;

    while (flag != 0) {
        int option;
        printf("1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. EXIT\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Insert beginning\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &element);
                list1.insert_beg(element);
                list1.display();
                break;

            case 2:
                printf("Insert End\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &element);
                list1.insert_end(element);
                list1.display();
                break;

            case 3:
                printf("Insert position\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &element);
                printf("Enter the index where the element has to be inserted: ");
                scanf("%d", &index);
                list1.insert_pos(element, index);
                list1.display();
                break;

            case 4:
                printf("Delete Beginning\n");
                buffer = list1.delete_beg();
                if (buffer == -1) {
                    printf("The list is empty\n");
                } else {
                    printf("The deleted element: %d\n", buffer);
                }
                break;

            case 5:
                printf("Delete End\n");
                buffer = list1.delete_end();
                if (buffer == -1) {
                    printf("The list is empty\n");
                } else {
                    printf("The deleted element: %d\n", buffer);
                }
                break;

            case 6:
                printf("Delete Position\n");
                printf("Enter the index whose element has to be deleted: ");
                scanf("%d", &index);
                buffer = list1.delete_pos(index);
                if (buffer == -1) {
                    printf("The list is empty or index is out of bounds\n");
                } else {
                    printf("The deleted element: %d\n", buffer);
                }
                break;

            case 7:
                printf("Search\n");
                printf("Enter the element that needs to be found: ");
                scanf("%d",&element);
                buffer=list1.search(element);
                if(buffer!=-1){
                    printf("The element was found at: %d\n",buffer);
                }
                else{
                    printf("The element was not found");
                }
                // Search functionality can be implemented here
                break;

            case 8:
                printf("Display\n");
                list1.display();
                break;

            case 9:
                printf("EXIT\n");
                flag = 0;
                break;
        }
    }
    return 0;
}

int List::is_empty() {
    return head == NULL;
}

void List::display() {
    node* cur = head;
    if (is_empty()) {
        printf("The list is empty\n");
        return;
    }
    printf("List elements: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next_ptr;
    }
    printf("\n");
}

void List::insert_beg(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next_ptr = head;
    new_node->prev_ptr = NULL;

    if (head != NULL) {
        head->prev_ptr = new_node;
    } else {
        tail = new_node; // If the list was empty, tail should also point to the new node
    }
    head = new_node;
}

void List::insert_end(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next_ptr = NULL;
    new_node->prev_ptr = tail;

    if (tail != NULL) {
        tail->next_ptr = new_node;
    } else {
        head = new_node; // If the list was empty, head should also point to the new node
    }
    tail = new_node;
}

void List::insert_pos(int value, int ind) {
    if (ind < 0) {
        printf("Invalid index\n");
        return;
    }
    if (ind == 0) {
        insert_beg(value);
        return;
    }

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    node* cur = head;

    for (int i = 0; i < ind - 1 && cur != NULL; i++) {
        cur = cur->next_ptr;
    }

    if (cur == NULL) {
        printf("Index out of bounds\n");
        free(new_node);
        return;
    }

    new_node->next_ptr = cur->next_ptr;
    new_node->prev_ptr = cur;

    if (cur->next_ptr != NULL) {
        cur->next_ptr->prev_ptr = new_node;
    } else {
        tail = new_node; // If we are inserting at the end
    }
    cur->next_ptr = new_node;
}

int List::delete_beg() {
    if (is_empty()) {
        return -1;
    }
    node* cur = head;
    int temp = cur->data;
    head = cur->next_ptr;

    if (head != NULL) {
        head->prev_ptr = NULL;
    } else {
        tail = NULL; // List is now empty
    }
    free(cur);
    return temp;
}

int List::delete_end() {
    if (is_empty()) {
        return -1;
    }
    node* cur = tail;
    int temp = cur->data;
    tail = cur->prev_ptr;

    if (tail != NULL) {
        tail->next_ptr = NULL;
    } else {
        head = NULL; // List is now empty
    }
    free(cur);
    return temp;
}

int List::delete_pos(int ind) {
    if (is_empty() || ind < 0) {
        return -1;
    }
    if (ind == 0) {
        return delete_beg();
    }

    node* cur = head;
    for (int i = 0; i < ind && cur != NULL; i++) {
        cur = cur->next_ptr;
    }

    if (cur == NULL) {
        return -1; // Index out of bounds
    }

    int temp = cur->data;
    if (cur->prev_ptr != NULL) {
        cur->prev_ptr->next_ptr = cur->next_ptr;
    }
    if (cur->next_ptr != NULL) {
        cur->next_ptr->prev_ptr = cur->prev_ptr;
    }

    if (cur == tail) {
        tail = cur->prev_ptr; // Update tail if needed
    }
    free(cur);
    return temp;
}


int List::search(int value) {
    int index = 0; // To track the index of the current node
    node* cur = head;

    while (cur != NULL) {
        if (cur->data == value) {
            return index; // Return the index if the value is found
        }
        cur = cur->next_ptr; // Move to the next node
        index++; // Increment the index
    }

    return -1; // Return -1 if the value is not found
}