#include "multiplier.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	// Declare I/O signals
	sc_signal<sc_uint<32>> a, b;
	sc_signal<sc_uint<64>> p;

	// Instantiate a multiplier module and bind the signals to the ports
	multiplier mult_inst("myMultiplier");
	mult_inst.in_a(a);
	mult_inst.in_b(b);
	mult_inst.out_m(p);

	// Instantiate a driver module and bind the signals to the ports
	driver drv_inst("myDriver");
	drv_inst.d_a(a);
	drv_inst.d_b(b);

	// Instantiate a monitor module and bind the signals to the ports
	monitor mon_inst("myMonitor");
	mon_inst.m_a(a);
	mon_inst.m_b(b);
	mon_inst.m_p(p);

	sc_start(100, SC_NS);

	return 0;
}