#pragma once

#include <systemc.h>
#include "multiplier.h"

SC_MODULE(divider)
{
	sc_in<sc_uint<32>> in_n, in_d;
	sc_out<sc_uint<32>> out_q, out_r;
	sc_signal<sc_uint<32>> s_a, s_b;
	sc_signal<sc_uint<64>> s_m;
	multiplier *mul;

	void divide();

	SC_CTOR(divider)
	{
		mul = new multiplier("myMul");
		mul->in_a(s_a);
		mul->in_b(s_b);
		mul->out_m(s_m);

		SC_METHOD(divide);
		sensitive << in_n << in_d;
	}
};

