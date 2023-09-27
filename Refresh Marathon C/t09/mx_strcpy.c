#include <stdio.h>

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

int main() {
    char src[] = "Hello, world!";
    char dst[40];

    mx_strcpy(dst, src);

    printf("Copied string: %s\n", dst);

    return 0;
}
