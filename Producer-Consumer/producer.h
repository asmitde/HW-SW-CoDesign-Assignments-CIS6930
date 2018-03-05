#include <systemc.h>
#include "write_if.h"
#include "read_if.h"

#define BUFFER_SIZE 1024

SC_MODULE(producer)
{
	sc_port<write_if> out;				// Output port for producing data
	sc_port<read_if> ackrecv;			// Input port for receiving back data
	
	SC_CTOR(producer)
	{
		SC_THREAD(main);
	}
	
	void main()
	{
		char str[BUFFER_SIZE] = "this is a sample string";
		char rcv[BUFFER_SIZE];
		char c;
		int count = 0;
		
		cout << "Producer writes: ";
		while(true)
		{
			cout << str[count];
			out->write(str[count++]);	// Write each character to the output port
			
			if (count == strlen(str))
			{
				cout << endl << "Writing finished" << endl;
				break;
			}
		}
		
		// Read the characters sent back by the consumer
		cout << "Producer receives acknowledgement: ";
		count = 0;
		while(true)
		{
			ackrecv->read(c);
			cout << c;
			
			// Store the sequence of received characters after converting them to lowercase
			rcv[count++] = tolower(c);
			
			if (ackrecv->num_available() == 0)
			{
				cout << endl << "Reading finished" << endl;
				break;
			}
		}
		
		// If the received string matches the one that was sent, then the transfer in both directions were correct
		if (!strcmp(str, rcv))
		{
			cout << "String properly transferred to consumer\n";
		}
		else
		{
			cout << "String not transferred properly to consumer\n";
		}
	}
};
