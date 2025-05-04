#include <cstdio>
#include<cstdlib>

class list{
    private:
        int num_elements;
        typedef struct Node{
            int data;
            struct Node* next_ptr;
        }node;
        node*head;
    public:
    list(){
        num_elements=0;
        head=NULL;
    }
    int is_empty();
    void insert_beg(int value);
    void insert_end(int value);
    void insert_pos(int value, int ind);
    void delete_beg();
    void delete_end();
    void delete_pos(int ind);
    void display();
    void search(int value);
    void display_rev(node*new_node=NULL);
    void reverse();
};


int main(){
  printf("MENU DRIVEN PROGRAM TO IMPLEMENT LIST ABSTRACT DATATYPE\n");
  int flag=1;
  List_array list_1;
  while(flag!=0){
      printf("""1. insert(beginning)\n 2.insert(end)\n insert (given position)\n 4. delete(beginning)\n 5. delete(from the end)\n 6. delete(given position)\n 7.search\n 8. display\n 9. rotate\n 10. EXIT""");
      int option;
      printf("Enter option (1-10): ");
      scanf("%d", &option);
      printf("option: %d\n", option);
      //list_1.menu(flag, option);
      int data;
      int index;
      int result;
      switch(option){
       case 1:
       printf("insert(beginning)\n");
       printf("Enter data to be inserted: \n");
       scanf("%d",&data);
       list_1.insert_beg(data);

       break;

       case 2:
       printf("insert(end)\n"); 
       printf("Enter data to be inserted: \n");
       scanf("%d",&data);
       list_1.insert_end(data);
       break;

       case 3:
       printf("insert(any given position)\n");
       printf("Enter data to be inserted: \n");
       scanf("%d",&data);
       printf("Enter the index: \n");
       scanf("%d",&index);
       list_1.insert_pos(index, data);
       break;

       case 4:
       printf("Delete(beginning)\n");
       result=list_1.delete_beg();
       if(result==-1){
          printf("the list is empty");
       }
       else{
          printf("deleted element: %d\n", result);
       }

       break;

       case 5:
       printf("Delete(end)\n");
       result=list_1.delete_end();
       if(result==-1){
          printf("the list is empty\n");
       }
       else{
          printf("the element deleted: %d\n", result);
       }
       break;

       case 6:
       printf("Delete(any given position)\n");
       printf("Enter the index: \n");
       scanf("%d",&index);
       result=list_1.delete_pos(index);
       if(result==-1){
          printf("the list is empty\n");
       }
       else{
          printf("the element daleted: %d\n", result);
       }

       break;

       case 7:
       printf("Search\n");
       printf("Enter data to be searched: \n");
       scanf("%d",&data);
       result=list_1.search(data);
       if (result==-1){
          printf("The element was not found");

       }
       else{
          printf("the element was found at %d\n", result);
       }

       break;

       case 8:
       printf("Display\n");
       list_1.display();
       break;

       case 9:
       printf("Display Reverse\n");
       printf("Enter the number of times the list has to be rotated: \n");
       scanf("%d",&data);
       list_1.display_rev(node*new_node);
       break;            

       case 10:
       printf("REVERSE\n");
       list_1.reverse();
       break;

       case 11:
       printf("EXIT\n");
       flag=0;
       break;


  }
  }
  return 0;
}




int list:: is_empty(){
    if (head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void list:: insert_beg(int value){
    int res=is_empty();
    if (res==1){
         node* node1;
        node1=(node*)malloc(sizeof(node));
        node1->data=value;
        node1->next_ptr=NULL;
        head=node1;
    }
    else{
        node* node1;
        node1=(node*)malloc(sizeof(node));
        node1->data=value;
        node1->next_ptr=head;
        head=node1;
    }
}



void list:: insert_end(int value){
    int res=is_empty();
    if (res==1){
         node* node1;
        node1=(node*)malloc(sizeof(node));
        node1->data=value;
        node1->next_ptr=NULL;
        head=node1;
    }
    else{
        node* node1;
        node1=(node*)malloc(sizeof(node));
        node1->data=value;
        node1->next_ptr=NULL;
        node* cur=head;
        while (cur->next_ptr!=NULL){
            cur=cur->next_ptr;
        }
        cur->next_ptr=node1;
        }
}

void list:: insert_pos(int value, int ind){
    int res=is_empty();
    if (res==1){
        node* node1;
        node1=(node*)malloc(sizeof(node));
        node1->data=value;
        node1->next_ptr=NULL;
        head=node1;
    }
    else{
        if (ind==0){
            insert_beg(value);
        }
        else{
            node* node1;
            node1=(node*)malloc(sizeof(node));
            node1->data=value;   
            node* cur= head;
            for (int i=0; i<ind-1; i++){
                cur=cur->next_ptr;
            } 
            node1->next_ptr=cur->next_ptr;
            cur->next_ptr=node1;
        }
    }
}

void list:: delete_beg(){
    int res=is_empty();
    if (res==1){
        printf("The list is empty\n");
    }
    else{
        node* cur=head;
        head=cur->next_ptr;
        free(cur);
    }
}

void list:: delete_end(){
    int res=is_empty();
    if (res==1){
        printf("the list is empty\n");
    }
    else{
        node* cur=head;
        node* prev=NULL;
        while (cur->next_ptr!=NULL){
            prev=cur;
            cur=cur->next_ptr;
            }
        if (prev==NULL){
            head=NULL;
            free(cur);
        }
        else{
        prev->next_ptr=NULL;
        free(cur);
        }
    }
}


void list:: delete_pos(int ind){
    int res=is_empty();
    if (res==1){
        printf("The list is empty\n");
    }
    else{
        node* cur=head;
        if(ind==0){
            delete_beg();
        }
        else{
            for (int i=0;i<ind-1;i++){
                cur=cur->next_ptr;
            }
            node* temp;
            temp=cur->next_ptr;
            cur->next_ptr=temp->next_ptr;
            free(temp);
        }
    }
}


void list:: display(){
    node* cur=head;
    while (cur->next_ptr!=NULL){
        printf("%d: ", cur->data);
        printf("\n");
    }
    printf("End");
}

void list:: search(int value){
    int flag=0;
    node* cur=head;
    int i=0;
    while (cur->next_ptr!=NULL){
        if (cur->data==value){
            flag=1;
            printf("the value was found at %d\n", i);
        }
        i=i+1;
    }
    if (flag==0){
        printf("the value was not found\n");
    }
}

void list:: display_rev(node*new_node){
    //node* cur=new_node;
    int res=is_empty();
    if (res==1){
        printf("The list is empty\n");
    }
    else{
        if (new_node==NULL){
            return;
        }
        else{
            display_rev(new_node->next_ptr);
            printf("%d\n",new_node->data);
        }
    }
}

void list:: reverse(){
  int res=is_empty();
  if (res==1){
    printf("The list is empty\n");
  }
  else{
    node* cur=head;
    node*prev=NULL;
    node* next=NULL;
    while(cur!=NULL){
        next=cur->next_ptr;
        cur->next_ptr=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
  }
}

