#ifndef WRITE_IF_H
#define WRITE_IF_H

#include <systemc.h>

class write_if : public sc_interface
{
public:
	virtual void write(char) = 0;
	virtual void reset() = 0;
};

#endif
