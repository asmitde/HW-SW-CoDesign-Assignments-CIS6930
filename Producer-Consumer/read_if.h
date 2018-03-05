#ifndef READ_IF_H
#define READ_IF_H

#include <systemc.h>

class read_if : public sc_interface
{
public:
	virtual void read(char &) = 0;
	virtual int num_available() = 0;
};

#endif
