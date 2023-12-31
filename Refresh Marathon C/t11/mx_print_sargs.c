void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
    int end = 0;
    while (end == 0) {
        end = 1;
        for (int i = 1; i < argc - 1; i++) {
            if (mx_strcmp(argv[i], argv[i + 1]) > 0) {
                char *temp = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = temp;
                end = 0;
            }
        }
    }
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
    return 0;
}
