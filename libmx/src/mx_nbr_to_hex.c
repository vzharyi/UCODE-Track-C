#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int digits = 0;
    unsigned long temp = nbr;

    while (temp != 0) {
        temp /= 16;
        digits++;
    }

    char *hexStr = (char *) malloc(digits + 1);

    for (int i = digits - 1; i >= 0; i--) {
        int residue = nbr % 16;
        if (residue >= 10)
            hexStr[i] = (residue - 10) + 'a';
        else
            hexStr[i] = residue + '0';
        nbr /= 16;
    }
    hexStr[digits] = '\0';
    return hexStr;
}
