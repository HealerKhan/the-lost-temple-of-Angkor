#include <stdio.h>

int main() {
    int gridsystem[20][20];
    int myProduct = 0;

    // get the input for grid from user
    printf("Enter your 20x20 grid numbers \n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            scanf("%d", &gridsystem[i][j]);
        }
    }

    // checking for horizontal lines
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 17; j++) { // we use it upto 17th column we are using four consecutive number to ifnd the product
            int product = gridsystem[i][j] * gridsystem[i][j+1] * gridsystem[i][j+2] * gridsystem[i][j+3];
            if (product > myProduct) {
                myProduct = product;
            }
        }
    }

    // check for vertical lines
    for (int i = 0; i < 17; i++) { // same logic as we used in horizontal
        for (int j = 0; j < 20; j++) {
            int product = gridsystem[i][j] * gridsystem[i+1][j] * gridsystem[i+2][j] * gridsystem[i+3][j];
            if (product > myProduct) {
                myProduct = product;
            }
        }
    }

    // checking diagonal lines from top left to bottom right
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) { //we check diagonally i-e 1 number then next will be under it + 1
            int product = gridsystem[i][j] * gridsystem[i+1][j+1] * gridsystem[i+2][j+2] * gridsystem[i+3][j+3];
            if (product > myProduct) {
                myProduct = product;
            }
        }
    }

    // checking diagonal lines form bottom left to top right
    for (int i = 3; i < 20; i++) {
        for (int j = 0; j < 17; j++) {  //we start from 3 because from bottom we make sure that it has to be 4 consecutive numbers
            int product = gridsystem[i][j] * gridsystem[i-1][j+1] * gridsystem[i-2][j+2] * gridsystem[i-3][j+3];
            if (product > myProduct) {
                myProduct = product;
            }
        }
    }

    printf("this is your product: %d\n", myProduct);

    return 0;
}
