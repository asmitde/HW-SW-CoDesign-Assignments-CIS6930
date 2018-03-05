#pragma once

#include <systemc.h>

SC_MODULE(monitor)
{
	sc_in<sc_uint<32>> m_a, m_b;
	sc_in<sc_uint<64>> m_p;
	int run = 0;

	void scope();

	SC_CTOR(monitor)
	{
		SC_METHOD(scope);
		sensitive << m_p;
	}
};

