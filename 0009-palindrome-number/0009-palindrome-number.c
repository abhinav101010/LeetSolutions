bool isPalindrome(int x) {
    long reversed = 0;
    int original = x, remainder;

    if(x < 0){
        return false;
    }

    while (x != 0) {
        remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }

    if (original == reversed) {
        return true;
    } else {
        return false;
    }
}