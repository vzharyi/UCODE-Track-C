#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int counter = 0;
    bool status = true;
    if (str == NULL)
        return -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            status = true;
        else if (status == true) {
            status = false;
            counter++;
        }
    }
    return counter;
}
