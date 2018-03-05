#pragma once

#include <systemc.h>

#include "bus_request.h"
#include "bus_master_if.h"
#include "bus_slave_if.h"


class SharedBus : public bus_master_if, public sc_channel
{
public:
	// ports
	sc_in_clk clock;
	sc_port<bus_slave_if> slave_port;
	
	// constructor
	SC_CTOR(SharedBus)
	{
		dont_initialize();
		sensitive << clock.neg();
	}

	// master BUS interface
	void burst_read(int *data
		, unsigned int start_address
		, unsigned int length = 1);
	void burst_write(int *data
		, unsigned int start_address
		, unsigned int length = 1);


private:
	sc_mutex bus_mutex;
};