#include<cstdlib>
#include<cstdio>
#include header

void menu(int flag, int* arr, int len, int opt);
void linear_search(int* arr, int len, int data);
void binary_search(int* arr, int len, int data)

int main(){
    printf("menu-driven program to search a given data\n");
    int flag_var=1;

    int length;
    printf("ENter the number of elements of the array");
    scanf("%d",&length);
    int* array;
    array=(int*)malloc(length*(sizeof(int)));
    get_elements(array, length);
    
    int data_to_be_searched;
    printf("Enter data to be searched: ");
    scanf("%d",&data_to_be_searched);

    while (flag_var!=0){
        int option;
        printf("choose any on eof the options:\n 1: linear search \n 2: binary search \n 3: EXIT \n ");
        scanf("%d", &option);
        menu(flag_var, array, length, option, );
    }

    free(array);
    return 0;
}



void menu(int flag, int* arr, int len, int opt, int data){
    //arr=(int*)malloc(len*(sizeof(int)));
    //get_elements(arr, len);
    switch(opt){
        case 1:
        printf("LINEAR SEARCH\n");
        linear_search(int* arr, int len, int data);
        break;
        case 2:
        printf("BINARY SEARCH\n");
        binary_search(int* arr, int len, int data);
        break;
        case 3:
        printf("EXIT\n");
        flag=0;
        break;
    }
}

void linear_search(int* arr, int len, int data){
  int i;
  for(i=0;i<len;i++){
    if(arr[i]==data){
      printf("Element found at index %d\n", i);
      return;
      
}

void binary_search(int* arr, int len, int data){
  int low = 0
  int high = len - 1 
  while(low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] < data) {
      low = mid + 1;
      } else if (arr[mid] > data) {
        high = mid - 1;
        } else {
          printf("Element found at index %d\n", mid);
          return;
}