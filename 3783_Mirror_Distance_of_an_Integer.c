int reverse_int(int x) {
    int y = 0;
    while(x > 0) {
        y = y * 10 + (x % 10);
        x /= 10;
    }

    return y;
}

int mirrorDistance(int n) {
    int r = reverse_int(n);
    return (n > r) ? (n - r) : (r - n);
}
