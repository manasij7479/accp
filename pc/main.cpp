#include "serial.hpp"
#include "datawindow.hpp"
int main()
{
	SimpleSerial port("/dev/ttyUSB0",9600);
	while(true)
	{
		auto x=port.getTrio();
		std::printf("%5d\t%5d\t%5d\n",x[0],x[1],x[2]);
	}
}