#include <cstdio>
#include <cstdlib>

class list {
private:
    int num_elements;
    typedef struct Node {
        int data;
        struct Node* next_ptr;
    } node;
    node* head;
public:
    list() {
        num_elements = 0;
        head = NULL;
    }
    int is_empty();
    void insert_beg(int value);
    void insert_end(int value);
    void insert_pos(int value, int ind);
    int delete_beg();
    int delete_end();
    int delete_pos(int ind);
    void display();
    int search(int value);
    void display_rev(node* new_node = NULL);
    void reverse();
};

int main() {
    printf("MENU DRIVEN PROGRAM TO IMPLEMENT LIST ABSTRACT DATATYPE\n");
    int flag = 1;
    list list_1;
    while (flag != 0) {
        printf("1. insert(beginning)\n2. insert(end)\n3. insert(given position)\n4. delete(beginning)\n5. delete(from the end)\n6. delete(given position)\n7. search\n8. display\n9. display reverse\n10. reverse\n11. EXIT\n");
        int option;
        printf("Enter option (1-11): ");
        scanf("%d", &option);
        printf("option: %d\n", option);
        
        int data;
        int index;
        int result;
        switch (option) {
            case 1:
                printf("insert(beginning)\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                list_1.insert_beg(data);
                break;

            case 2:
                printf("insert(end)\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                list_1.insert_end(data);
                break;

            case 3:
                printf("insert(any given position)\n");
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the index: ");
                scanf("%d", &index);
                list_1.insert_pos(data, index);  // Fixed parameter order
                break;

            case 4:
                printf("Delete(beginning)\n");
                result = list_1.delete_beg();
                if (result == -1) {
                    printf("The list is empty\n");
                }
                else {
                    printf("Deleted element: %d\n", result);
                }
                break;

            case 5:
                printf("Delete(end)\n");
                result = list_1.delete_end();
                if (result == -1) {
                    printf("The list is empty\n");
                }
                else {
                    printf("The element deleted: %d\n", result);
                }
                break;

            case 6:
                printf("Delete(any given position)\n");
                printf("Enter the index: ");
                scanf("%d", &index);
                result = list_1.delete_pos(index);
                if (result == -1) {
                    printf("The list is empty\n");
                }
                else {
                    printf("The element deleted: %d\n", result);
                }
                break;

            case 7:
                printf("Search\n");
                printf("Enter data to be searched: ");
                scanf("%d", &data);
                result = list_1.search(data);
                if (result == -1) {
                    printf("The element was not found\n");
                }
                else {
                    printf("The element was found at position %d\n", result);
                }
                break;

            case 8:
                printf("Display\n");
                list_1.display();
                break;

            case 9:
                printf("Display Reverse\n");
                list_1.display_rev(list_1.get_head());  // Need a way to access head
                break;

            case 10:
                printf("REVERSE\n");
                list_1.reverse();
                break;

            case 11:
                printf("EXIT\n");
                flag = 0;
                break;

            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}

int list::is_empty() {
    return head == NULL;
}

void list::insert_beg(int value) {
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = value;
    node1->next_ptr = head;
    head = node1;
    num_elements++;
}

void list::insert_end(int value) {
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = value;
    node1->next_ptr = NULL;
    
    if (is_empty()) {
        head = node1;
    }
    else {
        node* cur = head;
        while (cur->next_ptr != NULL) {
            cur = cur->next_ptr;
        }
        cur->next_ptr = node1;
    }
    num_elements++;
}

void list::insert_pos(int value, int ind) {
    if (ind < 0 || ind > num_elements) {
        printf("Invalid position\n");
        return;
    }
    
    if (ind == 0) {
        insert_beg(value);
    }
    else if (ind == num_elements) {
        insert_end(value);
    }
    else {
        node* node1 = (node*)malloc(sizeof(node));
        node1->data = value;
        node* cur = head;
        for (int i = 0; i < ind - 1; i++) {
            cur = cur->next_ptr;
        }
        node1->next_ptr = cur->next_ptr;
        cur->next_ptr = node1;
        num_elements++;
    }
}

int list::delete_beg() {
    if (is_empty()) {
        return -1;
    }
    node* temp = head;
    int data = temp->data;
    head = head->next_ptr;
    free(temp);
    num_elements--;
    return data;
}

int list::delete_end() {
    if (is_empty()) {
        return -1;
    }
    if (head->next_ptr == NULL) {
        int data = head->data;
        free(head);
        head = NULL;
        num_elements--;
        return data;
    }
    node* cur = head;
    while (cur->next_ptr->next_ptr != NULL) {
        cur = cur->next_ptr;
    }
    int data = cur->next_ptr->data;
    free(cur->next_ptr);
    cur->next_ptr = NULL;
    num_elements--;
    return data;
}

int list::delete_pos(int ind) {
    if (is_empty() || ind < 0 || ind >= num_elements) {
        return -1;
    }
    if (ind == 0) {
        return delete_beg();
    }
    if (ind == num_elements - 1) {
        return delete_end();
    }
    node* cur = head;
    for (int i = 0; i < ind - 1; i++) {
        cur = cur->next_ptr;
    }
    node* temp = cur->next_ptr;
    int data = temp->data;
    cur->next_ptr = temp->next_ptr;
    free(temp);
    num_elements--;
    return data;
}

void list::display() {
    if (is_empty()) {
        printf("The list is empty\n");
        return;
    }
    node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next_ptr;
    }
    printf("\n");
}

int list::search(int value) {
    if (is_empty()) {
        return -1;
    }
    node* cur = head;
    int pos = 0;
    while (cur != NULL) {
        if (cur->data == value) {
            return pos;
        }
        cur = cur->next_ptr;
        pos++;
    }
    return -1;
}

void list::display_rev(node* new_node) {
    if (is_empty()) {
        printf("The list is empty\n");
        return;
    }
    if (new_node == NULL) {
        return;
    }
    display_rev(new_node->next_ptr);
    printf("%d ", new_node->data);
}

void list::reverse() {
    if (is_empty() || head->next_ptr == NULL) {
        return;
    }
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next_ptr;
        current->next_ptr = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Helper function to access head for display_rev
node* list::get_head() {
    return head;
}
