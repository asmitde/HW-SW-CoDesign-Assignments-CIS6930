#pragma once

#include <systemc.h>

SC_MODULE(driver)
{
	sc_out<sc_uint<32>> d_a, d_b;

	void generate();

	SC_CTOR(driver)
	{
		SC_THREAD(generate);
	}
};

