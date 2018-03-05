#include <systemc.h>
#include "SharedBus.h"

void SharedBus::burst_read(int *data
	, unsigned int start_address
	, unsigned int length)
{
	bus_mutex.lock();

	for (int i = 0; i < length; i++)
	{
		wait(clock->posedge_event());
		slave_port->read(&data[i], start_address + i);
	}

	bus_mutex.unlock();
}

void SharedBus::burst_write(int *data
	, unsigned int start_address
	, unsigned int length)
{
	bus_mutex.lock();

	for (int i = 0; i < length; i++)
	{
		wait(clock->posedge_event());
		slave_port->write(&data[i], start_address + i);
	}

	bus_mutex.unlock();
}