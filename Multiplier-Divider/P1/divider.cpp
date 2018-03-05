#include "divider.h"

void divider::divide()
{
	sc_uint<32> num_n = in_n.read(),  num_d = in_d.read(), num_q = 0, num_r;

	while (num_r >= 0)
	{
		s_a.write(num_q);
		s_b.write(num_d);

		num_r = num_n - s_m.read();
		num_q++;
	}

	out_q.write(num_q - 1);
	out_q.write(num_r + num_d);
}