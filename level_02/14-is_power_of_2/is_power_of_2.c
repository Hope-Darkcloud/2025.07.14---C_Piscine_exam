#include <stdio.h>
int	    is_power_of_2(unsigned int n){
if (n == 0)
return 0;
while (n % 2 == 0)
n /= 2;
return (n == 1);
}
int main(void)
{
    unsigned int nums[] = {0, 1, 2, 3, 4, 5, 8, 16, 18, 32, 64, 100};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%u -> %d\n", nums[i], is_power_of_2(nums[i]));
    }

    return 0;
}
