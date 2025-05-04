#include<cstdlib>
#include<cstdio>

void menu(int flag, int* arr, int len, int opt);
int* bubble_sort(int* arr, int len);
int* selection_sort(int* arr, int len);
int* insertion_sort(int* arr, int len);
void get_elements(int* arr, int len);
void display(int* arr, int len);

int main(){
    printf("menu-driven program to sort a given array in ascending order\n");
    int flag_var=1;

    int length;
    printf("ENter the number of elements of the array");
    scanf("%d",&length);
    int* array;
    array=(int*)malloc(length*(sizeof(int)));
    get_elements(array, length);
    

    while (flag_var!=0){
        int option;
        printf("choose any on eof the options:\n 1: bubble sort \n 2: selection sort \n 3: insertion sort \n 4:EXIT \n");
        scanf("%d", &option);
        menu(flag_var, array, length, option);
    }

    free(array);
    return 0;
}

void menu(int flag, int* arr, int len, int opt){
    //arr=(int*)malloc(len*(sizeof(int)));
    //get_elements(arr, len);
    switch(opt){
        case 1:
        printf("BUBBLE SORT\n");
        X=bubble_sort(arr, len);
        display(X, len);
        break;
        case 2:
        printf("SELECTION SORT\n");
        X=selection_sort(arr, len);
        display(X, len);
        display(arr, len);
        break;
        case 3:
        printf("INSERTION SORT\n");
        X=insertion_sort(arr,len);
        display(X, len);
        break;
        case 4:
        printf("EXIT\n");
        flag=0;
        break;
    }
}

void display(int* arr, int len){
    for(int i=0; i<len; i++){
        printf("%d\n", *(arr+i));
    }
}


void get_elements(int* arr, int len){
    for(int i=0; i<len;i++){
        int element;
        printf("Enter element:");
        scanf("%d", (arr+i));
    }

}

int* bubble_sort(int* arr, int len){
    for (int i=0;i<len;i++){
        for (int j=0; j<(len-1); j++){
            if (*(arr+i)<*(arr+j)){
                int temp;
                temp=*(arr+i);
                *(arr+i)=*(arr+j);
                *(arr+j)=temp;
            }

        }
    }
    return arr;
}

int* selection_sort(int* arr, int len){
    for(int i=0; i<len; i++){
        int index=i;
        for (int j=i+1; j<(len-1);j++){
            if (*(arr+j)<*(arr+index)){
                int temp;
                temp=*(arr+index);
                *(arr+index)=*(arr+j);
                *(arr+j)=temp;
                index=j;
            }
        }
    }
    return arr;
}

int* insertion_sort(int* arr, int len){
    for(int i=1; i<len; i++){
        int j=i-1;
        while(j>=0 && *(arr+j)>*(arr+i)){
            int temp;
            temp=*(arr+i);
            *(arr+i)=*(arr+j);
            *(arr+j)=temp;
            j=j-1;
        }

    }
    return arr;
}
