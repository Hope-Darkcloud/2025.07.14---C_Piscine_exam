unsigned int gcd(unsigned int x, unsigned int y)
{
    while (y != 0)
    {
        unsigned int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

