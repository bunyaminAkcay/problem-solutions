#include <stdio.h>
#define N 20

void rotateDirection(int* direction){
    int sign = 1;
    if (direction[1] != 0){
        sign = -1;
    }
    int temp = direction[1];
    direction[1] = direction[0];
    direction[0] = temp * sign;
}

int main() {

    int direction[2] = {1, 0};
    int location[2] = {(N-1)/2, (N-1)/2};
    int area[N][N] = {{0}};

    int l = 1;
    int ll = l;

    int index = 0;

    area[location[0]][location[1]] = 1;

    while (index < N*N){

        for(int t=0; t < l ;t++){
            location[0] += direction[0];
            location[1] += direction[1];

            area[location[0]][location[1]] = index + 2;
            index++;
        }

        rotateDirection(direction);
        if (l == ll)
            ll++;
        else
            l++;
    }

    for (int i=0; i < N; i++){
        for (int j=0; j < N; j++){
            printf("%d\t", area[j][i]);
        }
        printf("\n");
    }
    return 0;
}
