#pragma once

#include <systemc.h>

class bus_master_if	: public virtual sc_interface
{
public:
	// master BUS interface
	virtual void burst_read(int *data
		, unsigned int start_address
		, unsigned int length = 1) = 0;
	virtual void burst_write(int *data
		, unsigned int start_address
		, unsigned int length = 1) = 0;

};