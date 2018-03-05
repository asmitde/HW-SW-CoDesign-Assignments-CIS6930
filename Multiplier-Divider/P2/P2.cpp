#include "divider.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char *argv[])
{
	// Declare I/O signals
	sc_signal<sc_uint<32>> n, d, q, r;

	// Instantiate a divider module and bind the signals to the ports
	divider div_inst("myDivider");
	div_inst.in_n(n);
	div_inst.in_d(d);
	div_inst.out_q(q);
	div_inst.out_q(r);

	// Instantiate a driver module and bind the signals to the ports
	driver drv_inst("myDriver");
	drv_inst.d_a(n);
	drv_inst.d_b(d);

	// Instantiate a monitor module and bind the signals to the ports
	monitor mon_inst("myMonitor");
	mon_inst.m_n(n);
	mon_inst.m_d(d);
	mon_inst.m_q(q);

	sc_start(100, SC_NS);

	return 0;
}