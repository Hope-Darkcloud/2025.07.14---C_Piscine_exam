#include <unistd.h>
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	int i = 0;

	while (i < 8)
	{
		result <<= 1;             
		result |= (octet & 1);     
		octet >>= 1;       
		i++;
	}
	return result;
}
int main (void){
    unsigned char c;
    c = '&';
    write(1, &c, 1);
    write(1, "\n", 1);
    c =reverse_bits(c);
    write(1, &c, 1);
    write(1, "\n", 1);
    return 0;
}

