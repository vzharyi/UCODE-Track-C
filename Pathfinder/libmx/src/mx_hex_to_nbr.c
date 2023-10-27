#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long step = 1;
    unsigned long result = 0;
    int size = 0;
    for (int i = 0; hex[i] != '\0'; i++)
	    size++;
    if (!hex)
	    return 0;
    for (int i = size - 1; i >= 0; i--) {
	if(!mx_islower(hex[i]) && !mx_isupper(hex[i]) && !mx_isdigit(hex[i]))
		return 0;
        if (mx_isdigit(hex[i])) {
            result += (hex[i] - 48) * step;
            step *= 16;
        }
        else if (mx_isupper(hex[i]) ) {
            result += (hex[i] - 55) * step;
            step *= 16;
        }
        else if (mx_islower(hex[i]) ) {
            result += (hex[i] - 87) * step;
            step *= 16;
        }
    }
    return result;
}
