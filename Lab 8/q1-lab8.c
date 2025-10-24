#include <stdio.h>

int main() {
    int arr1[5], arr2[5];
    int uarr[10];  
    int ucount = 0;
    int flag;

    printf("Enter 5 numbers for array 1:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 5 numbers for array 2:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr2[i]);
    }

    
    for (int i = 0; i < 5; i++) {
        flag = 0;
        for (int j = 0; j < ucount; j++) {
            if (arr1[i] == uarr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            uarr[ucount++] = arr1[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        flag = 0;
        for (int j = 0; j < ucount; j++) {
            if (arr2[i] == uarr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            uarr[ucount++] = arr2[i];
        }
    }

    printf("\nUnion of the two arrays is:\n");
    for (int i = 0; i < ucount; i++) {
        printf("| %d ", uarr[i]);
    }
    printf("|\n");

    return 0;
}

