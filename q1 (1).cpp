#include<cstdlib>
#include<cstdio>
#include<iterator>
#include<algorithm>
using namespace std;

void solve();

int main(){
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d",&t);
    while(t!=0){
        printf("%d\n",t);
        solve();
        t--;
    }
    return 0;
}

void solve(){
    int n;
    printf("Enter the number of elements in the sequence: ");
    scanf("%d",&n);
    int elements;
    int sequence[n];
    for (int i=0;i<n;i++){
        printf("Enter the elements of the sequence: ");
        scanf("%d",&elements);
        sequence[i]=elements;
    }
    int steps=0;
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (sequence[i]==sequence[j]){
                printf(" i: %d arr[i]: %d j: %d arr[j]: %d\n",i,sequence[i],j, sequence[j]);
                for(int k=i;k>=steps-1;k--){
                    steps++;
                    printf("steps: %d\n",steps);
                }
                break;
            }
        }
    }
    printf("%d\n",steps);
}