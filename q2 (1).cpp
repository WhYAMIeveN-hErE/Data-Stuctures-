//A program that finds the relative strengths of the players in a game

#include<cstdio>
#include<cstdlib>

void pretty_print(int array[], int len);//Displays the elements in an array
void insertion_sort(int array[], int length);//Sorts the elements of an array in ascending order
void solve();//Finds the relative strengths of the players in a team.

int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}

void pretty_print(int array[], int len){
    for(int i=0; i<len; i++){
        printf("%d ",array[i]);
    }
}

void insertion_sort(int array[], int length){
    int temp;
    int data;
    int j;
    for (int i=1;i<length;i++){
        temp=array[i];
        j=i-1;
        while (j>=0 && temp<=array[j]){
            data=array[j+1];
            array[j+1]=array[j];
            array[j]=data;
            j--;
        }
        array[j+1]=temp;
    }
}


void solve(){
   int num_players;
    int strengths;
    printf("Enter the number of players: ");
    scanf("%d",&num_players);
    int players[num_players];
    int shallow_copy[num_players];
    for (int i=0;i<num_players;i++){
        printf("Enter the strength of each player: ");
        scanf("%d",&strengths);
        players[i]=strengths;
        shallow_copy[i]=strengths;
    }
    printf("The strength of each player: \n");
    pretty_print(players,num_players);
    printf("\n");
    insertion_sort(shallow_copy, num_players);
    int max1=shallow_copy[num_players-1];
    int max2=shallow_copy[num_players-2];

    for (int i=0;i<num_players;i++){
        if(players[i]!=max1){
            players[i]=players[i]-max1;
        }
        else{
            players[i]=players[i]-max2;
        }
    }
    printf("The relative strength of each player: \n");
    pretty_print(players,num_players);
    printf("\n");
}