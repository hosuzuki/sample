unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	unsigned int	byte;

	result = 0;
	byte = 8;
	while (byte--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (octet);
}
