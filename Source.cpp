#include "Header.h"

int main() {
    try {
        AutoTest();
    }
    catch (int err) { printf("error=%d\n", err); }
    return 0;