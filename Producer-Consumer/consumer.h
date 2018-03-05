#include <systemc.h>
#include "read_if.h"
#include "write_if.h"

#define BUFFER_SIZE 1024

SC_MODULE(consumer)
{
	sc_port<read_if> in;				// Input port for reading data
	sc_port<write_if> ack;				// Output port for sending back data
	
	SC_CTOR(consumer)
	{
		SC_THREAD(main);
	}
	
	void main()
	{
		char str[BUFFER_SIZE];
		int count = 0;
		
		cout << "Consumer reads: ";
		while(true)
		{
			in->read(str[count]);		// Read each character coming through the input port
			cout << str[count++];
			
			// Stop reading when there are no more characters to read
			if (in->num_available() == 0)
			{
				cout << endl << "reading finished" << endl;
				break;
			}
		}
		
		// Convert each character to uppercase and write back to the output port
		cout << "Consumer sends acknowledgement: ";
		count = 0;
		while(true)
		{
			cout << str[count];
			ack->write(toupper(str[count++]));
			
			if (count == strlen(str))
			{
				cout << endl << "Writing finished" << endl;
				break;
			}
		}
	}
};
