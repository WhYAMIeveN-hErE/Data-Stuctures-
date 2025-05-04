#include<cstdlib>
#include<cstdio>
#include<cmath>

void is_palindrome(int* ptr, int* length, int* num_ptr);
void is_armstrong(int* ptr, int* length, int* num_ptr);
void is_perfect(int* ptr, int* length, int* num_ptr);
void menu(bool* flag, int*ptr, int* length, int*option, int* num_ptr);
int* splitter(int* ptr, int*length, int* ptr_num);

int main(){
  bool* flag;
  flag=(bool*)malloc(1*sizeof(bool));
  *flag=true;

  int* number;
  number=(int*)malloc(1*(sizeof(int)));
  printf("Enter number: ");
  scanf("%d", number);
  
  int*num;
  num=(int*)malloc(100*(sizeof(int)));

  int*n;
  n=(int*)malloc(100*(sizeof(int)));
  n=splitter(num, n, number);

  while (*flag!=false){
    printf("""1.to check whether or not the given number is a palindrome\n 2. to check whether or not the the given number is an armstrong number\n 3.to check whether the given number is a perfect number\n 4.EXIT\n""");
    int* opt;
    opt=(int*)malloc(1*sizeof(int));
    printf("Enter option(1-4)");
    scanf("%d",opt);
    menu(flag, num, n, opt, number);

  }
  return 0;
}

void menu(bool* flag, int*ptr, int* length, int* option, int* num_ptr){
  bool* res;
  res=(bool*)malloc(1*sizeof(bool));
  printf("Menu option chosen : %d\n", *option);
  
  switch(*(option)){
    case 1:
    printf("Palindrome\n");
    is_palindrome(ptr,length,num_ptr);
    break;
    
    

    case 2:
    printf("Armstrong\n");
    is_armstrong(ptr,length,num_ptr);
    break;


    case 3:
    printf("Perfect number\n");
    is_perfect(ptr, length, num_ptr);
    break;


    case 4:
    printf("Exited");
    *(flag)=false;
    break;



  }
}

int* splitter(int* ptr, int* length, int* ptr_num){
  int* i;
  i=(int*)malloc(1*sizeof(int));
  *(i)=0;
  int* temp;
  temp=(int*)malloc(1*sizeof(int));
  *(temp)=*(ptr_num);
  while(*(temp)!=0){
    *(ptr+*(i))=*(temp)%10;
    *(temp)=*(temp)/10;
    *(i)+=1;
  }
  return i;
}

void is_palindrome(int* ptr, int* length, int* num_ptr){
  int* i;
  i=(int*)malloc(1*sizeof(int));
  int*c;
  c=(int*)malloc(1*sizeof(int));
  for(*(i)=0; *(i)<(*(num_ptr)/2+1); *(i)++){
    if (*(ptr+*(i))!=*(ptr+*(length)-1+*(i))){
      printf("Is not a palindromic number\n");
      *(c)=1;
      break;
    }
  }
  if(*(c)!=1){
        printf("is a palindromic number\n");
  }
      
  }

void is_armstrong(int* ptr, int* length, int* num_ptr){
  double* sum;
  sum=(double*)malloc(1*sizeof(double));
  *(sum)=0;
  int*i;
  i=(int*)malloc(1*sizeof(int));
  for(*(i)=0;*i<*(length); *i=*i+1){
    *(sum)= *sum + pow(*(ptr+*(i)),*(length));
  }
  if (*(num_ptr)==*(sum)){
      printf("is an armstrong number\n");
  }
  else{
    printf("is not an armstrong number\n");
  }

}

void is_perfect(int* ptr, int* length, int* num_ptr){
  int*i;
  i=(int*)malloc(1*sizeof(int));
  int* sum;
  sum=(int*)malloc(1*sizeof(int));
  *(sum)=0;
  for(*(i)=1; *(i)<=(*num_ptr); *(i)=*(i)+1){
    if(*(num_ptr)% *(i)==0){
      *(sum)=*(sum)+*(i);
    }
  }
  if (*(sum)==(*(num_ptr)*2)){
    printf("is a perfect number\n");
  }
  else{
    printf("is not a perfect number\n");
  }
}






