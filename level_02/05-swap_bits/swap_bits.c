#include <unistd.h>
unsigned char	swap_bits(unsigned char octet){
return ((octet & 0x0F)<<4 | (octet & 0xF0) >>4);
}
int main(void){
unsigned char c;
c = 't';
write(1, &c, 1);
c = swap_bits(c);
write(1, &c, 1);
return 0;
}
