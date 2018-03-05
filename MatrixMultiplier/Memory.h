#pragma once

#include <systemc.h>
#include "bus_slave_if.h"


class Memory : public bus_slave_if, public sc_channel
{
public:
	Memory(sc_module_name name_
		, unsigned int start_address
		, unsigned int end_address)
		: sc_channel(name_)
		, _start_address(start_address)
		, _end_address(end_address)
	{
		sc_assert(_start_address < _end_address);

		unsigned int size = (_end_address - _start_address + 1);
		MEM = new sc_uint<32>[size];
		memset(MEM, 0, size);
	}

	void read(int *data, unsigned int address)
	{
		*data = MEM[(address - _start_address)];
	}

	void write(int *data, unsigned int address)
	{
		MEM[(address - _start_address)] = *data;
	}


private:
	sc_uint<32> *MEM;
	unsigned int _start_address;
	unsigned int _end_address;

};