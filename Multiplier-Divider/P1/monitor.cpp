#include "monitor.h"

void monitor::scope()
{
	cout << "Run #" << ++run << " -" << endl;
	cout << "a: " << m_a << ", b: " << m_b << endl;
	cout << "product: " << m_p << endl << endl;
}
