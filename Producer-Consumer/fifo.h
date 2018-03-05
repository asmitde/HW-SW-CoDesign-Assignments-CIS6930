#include <systemc.h>
#define BUFFER_SIZE 1024

class fifo : public sc_channel, public write_if, public read_if
{
private:
	char data[BUFFER_SIZE];
	int num_elements, first;
	sc_event write_event, read_event;
	
public:
	SC_CTOR(fifo)
	{
		num_elements = first = 0;
	}
	
	void write(char c)
	{
		// If the buffer is full, wait before taking in any data
		if (num_elements == BUFFER_SIZE)
		{
			cout << "full, waiting" << endl;
			wait(read_event);
		}
		
		// Write the data in the buffer and notify anyone waiting on an empty buffer
		data[(first + num_elements) % BUFFER_SIZE] = c;
		++num_elements;
		write_event.notify();
	}
	
	void read(char &c)
	{
		// If buffer is empty, wait till anyone writes to the buffer
		if (num_elements == 0)
		{
			cout << "empty, waiting" << endl;
			wait(write_event);
		}
		
		// Read from the buffer and notify anyone waiting on a full buffer
		c = data[first];
		--num_elements;
		first++;
		read_event.notify();
	}
	
	int num_available()
	{
		return num_elements;
	}
	
	void reset()
	{
		num_elements = 0;
		first = 0;
	}
};
