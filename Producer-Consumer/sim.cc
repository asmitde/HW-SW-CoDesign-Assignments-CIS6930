#include <systemc.h>
#include "producer.h"
#include "consumer.h"
#include "fifo.h"

// Main simulation module
SC_MODULE(sim)
{
	fifo *fifo_inst1, *fifo_inst2;				// Two instances of FIFO channel
	producer *prod_inst;						// Producer instance
	consumer *cons_inst;						// Consumer instance
	
	SC_CTOR(sim)
	{
		// Create the first fifo channel
		fifo_inst1 = new fifo("fifo1");
		
		// Create the producer instance and attach the out port to the 1st fifo channel
		prod_inst = new producer("producer1");
		prod_inst->out(*fifo_inst1);
		
		// Create the consumer instance and attach the in port to the 1st fifo channel
		cons_inst = new consumer("consumer1");
		cons_inst->in(*fifo_inst1);
		
		// Create the second fifo channel
		fifo_inst2 = new fifo("fifo2");
		
		// Attach the return read (ackrecv) port to the 2nd fifo channel
		prod_inst->ackrecv(*fifo_inst2);
		
		// Attach the return write (ack) port to the 2nd fifo channel
		cons_inst->ack(*fifo_inst2);
	}
};

int sc_main(int argc, char *argv[])
{
	sim("sim1");
	
	sc_start(1000, SC_SEC);
	
	return 0;
}
