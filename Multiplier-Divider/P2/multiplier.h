#pragma once

#include <systemc.h>

SC_MODULE(multiplier)
{
	sc_in<sc_uint<32>> in_a, in_b;
	sc_out<sc_uint<64>> out_m;

	void multiply();

	SC_CTOR(multiplier)
	{
		SC_METHOD(multiply);
		sensitive << in_a << in_b;
	}
};

