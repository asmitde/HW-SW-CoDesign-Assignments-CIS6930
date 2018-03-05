#pragma once

#include <systemc.h>

class bus_slave_if: public virtual sc_interface
{
public:
	// slave BUS interface
	virtual void read(int *data, unsigned int address) = 0;
	virtual void write(int *data, unsigned int address) = 0;
};