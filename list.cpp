#include<cstdio>
#include<cstdlib>

class List_array{
    private:
    int array[5];
    int num_elements=0;

    public:
    List_array(){
        num_elements=0;
    }
    int is_empty();
    void insert_beg(int value);
    void insert_end(int value);
    void insert_pos(int ind, int value);
    int delete_beg();
    int delete_end();
    int delete_pos(int ind);
    int search(int value);
    void display();
    void rotate(int k);
    void reverse(int start, int end);
    //void menu(int flag_var, int opt);

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
         printf("Rotate\n");
         printf("Enter the number of times the list has to be rotated: \n");
         scanf("%d",&data);
         list_1.rotate(data);
         break;            

         case 10:
         printf("EXIT\n");
         flag=0;
         break;


    }
    }
    return 0;
}


int List_array:: is_empty(){
    if(num_elements==0){
        return 1;
    }
    else{
        return 0;
    }
}

void List_array:: display(){
    int res=is_empty();
    if(res==1){
        printf("the list is empty");
    }
    else{
        for(int i=0;i<num_elements;i++){
            printf("%d\n",array[i]);
    }
        }
}


void List_array:: insert_beg(int value){
    if (num_elements>=5){
        printf("the list is full\n");
        display();
    }
    else if(num_elements==0){
        array[0]=value;
        num_elements++;
        display();
    }
    else{
        for(int i=(num_elements); i>=1;i--){
            array[i]=array[i-1];
        }
        array[0]=value;
        num_elements++;
        display();
    }
}


void List_array:: insert_end(int value){
    if (num_elements>=5){
        printf("the list is empty\n");
    }
    else if(num_elements==0){
        array[0]=value;
        num_elements++;
        display();
    }
    else{
        array[num_elements]=value;
        num_elements++;
        display();
    }
}

void List_array:: insert_pos(int ind, int value){
    if (num_elements>=5){
        printf("the list is full\n");
    }
    else if(num_elements==0){
        array[0]=value;
        num_elements++;
        display();
    }
    else{
        for(int i=(num_elements); i>ind;i--){
            array[i]=array[i-1];
        }
        array[ind]=value;
        num_elements++;
        display();
    }
}

int List_array:: delete_beg(){
    int res=is_empty();
    if(res==1){
        return -1;
    }
    else{
        int temp=array[0];
        for(int i=0;i<num_elements;i++){
            array[i]=array[i+1];
        }
        num_elements--;
        display();
        return temp;
    }
}

int List_array:: delete_end(){
    int res=is_empty();
    if(res==1){
        return -1;
    }
    else{
        int temp=array[num_elements-1];
        num_elements--;
        display();
        return temp;
    }
}

int List_array:: delete_pos(int ind){
    int res=is_empty();
    if(res==1){
        return -1;
    }
    else{
        int temp=array[ind];
        for(int i=ind;i<num_elements;i++){
            array[i]=array[i+1];
        }
        num_elements--;
        display();
        return temp;            return 1;
    }
}



int List_array:: search(int value){
    int flag;
    int temp;
    flag=0;
    for(int i=0;i<num_elements;i++){
        if(array[i]==value){
            flag=1;
            temp=i;
        }
    }
    if (flag==1){
        return temp;
    }
    else{            return 1;
        return -1;
    }
}


void List_array:: reverse(int start, int end){
    while(start<=end){
        int temp=array[start];
        array[start]=array[end];
        array[end]=array[start];
    }
}
void List_array:: rotate(int k){
    int res=is_empty();
    if(res==1){
        printf("the list is empty");
    }
    else{
        k%=num_elements;
        reverse(0,num_elements-1);
        reverse(0,k);
        reverse(num_elements-k-1, num_elements-1);
        display();
    }
}














/*void List_array:: menu(int flag_var, int opt){
    switch(opt){
         case 1:
         printf("insert(beginning)\n");
         break;

         case 2:
         printf("insert(end)\n");
         break;

         case 3:
         printf("insert(any given position)\n");
         break;

         case 4:
         printf("Delete(beginning)\n");
         break;

         case 5:
         printf("Delete(end)\n");
         break;

         case 6:
         printf("Delete(any given position)\n");
         break;

         case 7:
         printf("Search\n");
         break;

         case 8:
         printf("Display\n");
         break;

         case 9:
         printf("Rotate\n");
         break;

         case 10:
         printf("EXIT\n");
         int flag_var;
         flag_var=0;
         break;
    }
}
*/