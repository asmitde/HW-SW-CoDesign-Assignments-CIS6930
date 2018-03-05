#include "monitor.h"

void monitor::scope()
{
	cout << "Run #" << ++run << " -" << endl;
	cout << "n: " << m_n << ", d: " << m_d << endl;
	cout << "q: " << m_q << ", q: " << m_q << endl;
}
