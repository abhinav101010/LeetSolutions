int reverse(int x) {
    int reversed = 0;
    int remainder;

    while (x != 0) {
        remainder = x % 10;
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10)
            return 0; // overflow detected
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    printf("Reversed Number: %ld\n", reversed);
    return reversed;
}