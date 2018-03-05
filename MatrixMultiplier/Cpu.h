#pragma once

#include <systemc.h>
#include <ctime>
#include "bus_master_if.h"


SC_MODULE(Cpu)
{
	sc_in_clk clock;
	sc_port<bus_master_if> bus_port;

	SC_HAS_PROCESS(Cpu);

	SC_CTOR(Cpu)
	{
		SC_THREAD(main);
		sensitive << clock.pos();
	}

	void main()
	{
		const unsigned int len = 2;
		int array1[len], array2[len], array3[len];
		unsigned int result;
		unsigned int addr1 = 0x0, addr2 = 0x4, addr3 = 0x8;

		srand(time(NULL));

		// Write matrix A in row-major order and matrix B in column major order
		for (int i = 0; i < len * 2; i++)
		{
			memset(array1, 0, len);
			for (int j = 0; j < len; j++)
			{
				array1[j] = rand() % 100;
			}

			wait();
			bus_port->burst_write(array1, addr1, len);
			addr1 += len;
		}

		// Verify stored matrices
		cout << "Matrix A:" << endl;
		addr1 = 0x0;
		for (int i = 0; i < len; i++)
		{
			memset(array1, 0, len);
			wait();
			bus_port->burst_read(array1, addr1, len);
			addr1 += len;
			
			for (int j = 0; j < len; j++)
			{
				cout << array1[j] << "\t";
			}

			cout << endl;
		}

		cout << endl << "Matrix B transpose:" << endl;
		addr2 = 0x4;
		for (int i = 0; i < len; i++)
		{
			memset(array2, 0, len);
			wait();
			bus_port->burst_read(array2, addr2, len);
			addr2 += len;

			for (int j = 0; j < len; j++)
			{
				cout << array2[j] << "\t";
			}

			cout << endl;
		}

		// Multiply matrices
		addr1 = 0x0; addr3 = 0x8;
		for (int i = 0; i < len; i++)
		{
			memset(array1, 0, len);
			wait();
			bus_port->burst_read(array1, addr1, len);

			addr2 = 0x4;
			for (int j = 0; j < len; j++)
			{
				memset(array2, 0, len);
				wait();
				bus_port->burst_read(array2, addr2, len);

				result = 0;
				for (int k = 0; k < len; k++)
				{
					// This loop when moved entirely to a custom hardware component
					// capable of performing the multiplicaiton and addition will 
					// achieve a better performance

					// MAC:
					result += (array1[k] * array2[k]);
				}

				array3[j] = result;
				addr2 += len;
			}

			wait();
			bus_port->burst_write(array3, addr3, len);
			addr3 += len;
			addr1 += len;
			memset(array3, 0, len);
		}

		// Retrirve calculated matrix from memory and display
		cout << endl << "Matrix C (A * B):" << endl;
		addr3 = 0x8;
		for (int i = 0; i < len; i++)
		{
			memset(array3, 0, len);
			wait();
			bus_port->burst_read(array3, addr3, len);
			addr3 += len;

			for (int j = 0; j < len; j++)
			{
				cout << array3[j] << "\t";
			}

			cout << endl;
		}
	}
};