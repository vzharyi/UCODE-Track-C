#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    while ((str = mx_strstr(str, sub)) != 0) {
	str += mx_strlen(sub);
	counter++;
    }
    return counter;    
}
