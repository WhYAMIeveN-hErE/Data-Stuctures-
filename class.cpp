#include<cstdlib>
#include<cstdio>

class area{
    public: 
        int length;
        int breadth;
        int height;
        int area_fig;
        int volume;
    void area_2d(){
        area_fig=length*breadth;
        printf("\nthe area= %d\n", area_fig);
    }
    void area_3d(){
        area_fig=(length*breadth+length*height+breadth*height)*2;
        printf("\nthe area= %d\n", area_fig);
        volume=length*breadth*height;
        printf("the volume= %d\n", volume);
    }
    
    void set_data(int len, int b, int h){
        length=len;
        breadth=b;
        height=h;
    }
};

void menu(int option){
  printf("Menu option chosen : %d\n", option);
  area a1;
  switch((option)){
    case 1:
    printf("Area of the square\n");
    printf("Enter the side of the square: ");
    scanf("%d",&a1.length);
    a1.set_data(a1.length, a1.length, 0);
    a1.area_2d();
    break;
    
    

    case 2:
    printf("Area of the rectangle\n");
    printf("enter the length of the rectangle: ");
    scanf("%d", &a1.length);
    printf("\n enter the breadth of the rectangle: ");
    scanf("%d", &a1.breadth);
    a1.set_data(a1.length, a1.breadth,0);
    a1.area_2d();
    break;


    case 3:
    printf("CUBE\n");
    printf("Enter the side of the cube: ");
    scanf("%d", &(a1.length));
    a1.set_data(a1.length, a1.length, a1.length);
    a1.area_3d();
    break;


    case 4:
    printf("CUBOID\n");
    printf("Enter the length of the cuboid: ");
    scanf("%d", &a1.length);
    printf("\nEnter the breadth of the cuboid: ");
    scanf("%d", &a1.breadth);
    printf("\nEnter the height ofthe cuboid: ");
    scanf("%d", &a1.height);
    a1.area_3d();
    break;
    
    case 5:
    printf("EXIT");

  }
}

int main(){
    int opt = 0;
    while (opt!=5){
    printf("""1.SQUARE\n 2. RECTANGLE\n 3.CUBE\n 4.CUBOID\n 5.EXIT\n""");
    printf("Enter option(1-5): ");
    scanf("%d",&opt);
    menu(opt);
  }
  return 0;
}


