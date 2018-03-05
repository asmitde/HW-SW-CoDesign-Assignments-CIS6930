#include "multiplier.h"

void multiplier::multiply()
{
	sc_uint<64> num_s = 0;

	for (sc_uint<32> i = 0; i < in_b.read(); i++)
	{
		num_s = num_s + in_a.read();
	}

	out_m.write(num_s);
}