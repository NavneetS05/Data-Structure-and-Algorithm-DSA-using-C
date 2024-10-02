#include <stdio.h>

void address20(int arr2[2][3], int baseaddress) {
    int element_size = sizeof(int);
    int rowmajor, columnmajor;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            rowmajor = baseaddress + (i * 3 + j) * element_size;
            columnmajor = baseaddress + (j * 2 + i) * element_size;
            printf("\nAddress of index arr2[%d][%d]: Row Major Address = %d, Column Major Address = %d", i, j, rowmajor, columnmajor);
        }
    }
}

void address30(int arr[2][3][4], int baseaddress) {
    int element_size = sizeof(int);
    int rowmajor, columnmajor;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                rowmajor = baseaddress + (i * 3 * 4 + j * 4 + k) * element_size;
                columnmajor = baseaddress + (k * 2 * 3 + j * 2 + i) * element_size;
                printf("\nAddress of index arr[%d][%d][%d]: Row Major Address = %d, Column Major Address = %d", i, j, k, rowmajor, columnmajor);
            }
        }
    }
}

void address40(int arr[2][3][4][5], int baseaddress) {
    int element_size = sizeof(int);
    int rowmajor, columnmajor;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 5; l++) {
                    rowmajor = baseaddress + (i * 3 * 4 * 5 + j * 4 * 5 + k * 5 + l) * element_size;
                    columnmajor = baseaddress + (l * 2 * 3 * 4 + k * 2 * 3 + j * 2 + i) * element_size;
                    printf("\nAddress of index arr[%d][%d][%d][%d]: Row Major Address = %d, Column Major Address = %d", i, j, k, l, rowmajor, columnmajor);
                }
            }
        }
    }
}

int main() {
    int arr2[2][3];
    int arr3[2][3][4];
    int arr4[2][3][4][5];
    int baseaddress = 1000;
    int choice;

    printf("Enter choice (1 for 2D, 2 for 3D, 3 for 4D): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            address20(arr2, baseaddress);
            break;
        case 2:
            address30(arr3, baseaddress);
            break;
        case 3:
            address40(arr4, baseaddress);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
