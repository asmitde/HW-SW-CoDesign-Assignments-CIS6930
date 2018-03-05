#pragma once

#include <systemc.h>

SC_MODULE(monitor)
{
	sc_in<sc_uint<32>> m_n, m_d, m_q, m_r;
	int run = 0;

	void scope();

	SC_CTOR(monitor)
	{
		SC_METHOD(scope);
		sensitive << m_q << m_r;
	}
};

