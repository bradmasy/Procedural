#include <stdio.h>

/*
 * Author: Bradley Masciotra
 */
int main() {

    int count = 15;

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            count += 8;
        }
        count += 9;
    }

    printf("count = %s\n", count);
    printf("hi");
    return 0;
}


