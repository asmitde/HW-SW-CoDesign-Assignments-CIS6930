#include <systemc.h>
#include "Cpu.h"
#include "Memory.h"
#include "SharedBus.h"

SC_MODULE(top)
{
	sc_clock clk;

	Cpu *_cpu;
	Memory *_mem;
	SharedBus *_bus;

	SC_CTOR(top) : clk("myClock")
	{
		// Create the modules
		_cpu = new Cpu("myCPU");
		_mem = new Memory("myMemory", 0x0, 0xFF);
		_bus = new SharedBus("myBus");

		// Connect the instances
		_cpu->clock(clk);
		_bus->clock(clk);
		_cpu->bus_port(*_bus);
		_bus->slave_port(*_mem);
	}

	~top()
	{
		if (_mem)
		{
			delete _mem;
		}

		if (_bus)
		{
			delete _bus;
		}

		if (_cpu)
		{
			delete _cpu;
		}

	}
};


int sc_main(int, char **)
{
	top top_module("top");

	sc_start(10000, SC_NS);

	return 0;
}