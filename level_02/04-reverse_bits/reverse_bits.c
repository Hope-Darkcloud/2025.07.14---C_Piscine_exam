unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	int i = 0;

	while (i < 8)
	{
		result <<= 1;             ≈
		result |= (octet & 1);     
		octet >>= 1;       
		i++;
	}
	return result;
}

