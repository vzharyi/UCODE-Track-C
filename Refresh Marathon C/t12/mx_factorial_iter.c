int mx_factorial_iter(int n) {
    int factorial = 1;
    if (n > 12 || n < 0)
        return 0;
    for (int i = 1; i <= n; i++)
        factorial *= i;
    return factorial;
}
