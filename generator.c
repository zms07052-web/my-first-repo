#include <stdio.h>

/* Simple generator function that yields integers */
int generator(int *state) {
    /* Increment and return the next value */
    return ++(*state);
}

int main() {
    int state = 0;
    
    printf("Generator output:\n");
    for (int i = 0; i < 5; i++) {
        int value = generator(&state);
        printf("Generated value: %d\n", value);
    }
    
    return 0;
}