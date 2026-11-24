#include <stdio.h>

int ADR(int N){
    int tmp, i, count;
    tmp = N;
    i = 0;
    count = 0;
    while(tmp != 0){
        if((tmp % 2 == 1)){
            if((tmp/2)%2 != 0){
                tmp = tmp + 1;
            }
            count++;
        }
        tmp = tmp/2;
        i++;
    }
    
    return(count);
}

int main(){
    int N;

    scanf("%d", &N);

    printf("%d\n", ADR(N));
    
    return 0;
}
