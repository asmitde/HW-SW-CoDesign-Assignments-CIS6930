HW7 Solution
------------

Project members:
1. Asmit De | U72377278
2. Sheikh Ariful Islam | U20884520

----------------------------------

Project files:

matrixmult.c	- Algorithmic model
bus_master_if	- TLM Master interface
bus_slave_if	- TLM Slave interface
Cpu.h			- TLM CPU module (Master)
Memory.h		- TLM Memory channel
SharedBus.h		- TLM Bus channel
SharedBus.cpp	- TLM Bus channel implementation
top.cpp			- TLM top module for simulation
README.txt		- Project readme

------------------------------------------------

Compilation insructions:

g++ -I/<path to systemc include dir> -L<path to systemc library> -o top top.cpp -lsystemc

-----------------------------------------------------------------------------------------

Additional modification to the TLM model (Question 3):

The SharedBus model would be extended to include an arbiter attached to a slave port
and a custom HW component also attached to a slave port. The arbiter would arbitrate 
access between the Memory and custom HW as and when required. The custom HW is specifically 
designed to preform the MAC (multiply accumultor) of the matrix multiplication algorithm.
Refer to Cpu.h for the MAC operation.

The CPU would retrieve data from the memory in burst mode for the two matrices and offload the data
through the bus to the custom HW for the MAC operation. The custom HW, after performing MAC, would send
the calculated data back to the CPU. The CPU would then write the result back to the Memory in burst mode.

We are the trying to implement the above modification to the current design but due to deadline constrictions
we are unable to submit the same before the deadline.