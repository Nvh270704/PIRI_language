#include <stdio.h>
#include <setjmp.h>

#define TRY if (!setjmp(exception_buf))
#define CATCH else
#define END_TRY

static jmp_buf exception_buf;

void handle_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    longjmp(exception_buf, 1);
}

int divide(int a, int b) {
    if (b == 0) {
        handle_error("Division by zero");
    }
    return a / b;
}

int main() {
    TRY {
        int result = divide(10, 2);
        printf("Result: %d\n", result);

        result = divide(5, 0);  // This will trigger an error
        printf("Result: %d\n", result);
    }
    CATCH {
        printf("An error occurred, handling it...\n");
    }
    END_TRY;

    return 0;
}
