//A program that finds the number of winners in a game where the players are announced as chucked out when the number assigned to them matches the numbers given in a given sequence

#include<cstdio>
#include<cstdlib>
#include "algorithm"
using namespace std;

void solve(int k,int q);//This function finds the number of winners and displays the count.
void handle_testcase();//Inputs the values of the number of elements i the sequence and the number bof rounds the game would proceed for.

int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t--){
        printf("%d\n",t);
        handle_testcase();
    }
}

void solve(int k,int q){
    int array[k];
    int sequence;
    for (int i=0;i<k;i++){
        printf("Enter elements in the sequence: ");
        scanf("%d",&sequence);
        array[i]=sequence;
    }
    int n;
    for (int i=0;i<q;i++){
        printf("Enter number of players: ");
        scanf("%d",&n);
        printf("the number of WINNER: %d\n", min(array[0]-1,n));
    }
}

void handle_testcase(){
    int k;
    int q;

    printf("Enter the number of elements in th sequence: ");
    scanf("%d",&k);
    printf("Enter the number of rounds: ");
    scanf("%d",&q);
    int arr[k];
    solve(k,q);
}