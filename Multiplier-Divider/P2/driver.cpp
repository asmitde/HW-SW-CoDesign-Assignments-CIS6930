#include "driver.h"
#include <ctime>

void driver::generate()
{
	srand(time(NULL));

	while (true)
	{
		sc_uint<32> a = rand() % UINT32_MAX;
		sc_uint<32> b = rand() % UINT32_MAX;

		d_a.write(a);
		d_b.write(b);

		wait(5, SC_NS);
	}
}