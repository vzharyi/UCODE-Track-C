unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long step = 1;
    unsigned long result = 0;
    int size = 0;
    for (int i = 0; hex[i] != '\0'; i++)
        size++;
    if (!hex)
        return 0;

    for (int i = size - 1; i >= 0; i--) {
        if (!(hex[i] >= 'a' && hex[i] <= 'f') && !(hex[i] >= '0' && hex[i] <= '9')
            && !(hex[i] >= 'A' && hex[i] <= 'F'))
            return 0;
        if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += (hex[i] - 87) * step;
            step *= 16;
        }
        else if (hex[i] >= '0' && hex[i] <= '9') {
            result += (hex[i] - 48) * step;
            step *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += (hex[i] - 55) * step;
            step *= 16;
        }
    }
    return result;
}
