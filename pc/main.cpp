#include "comm/serial.hpp"
#include "data/datawindow.hpp"
#include "display/display.hpp"
#include "data/datagen.hpp"

#include<cstdio>
int main()
{

	mm::SimpleSerial port("/dev/ttyUSB0",9600);
	
	mm::DataWindow<mm::Trio> data(1000);
	
	mm::BufferData buf(data);
	
	mm::Display display(1600,1000,data);
	
	while(true)
	{
		auto x=port.getTrio();
		
		std::printf("%5d\t%5d\t%5d\n",x.x(),x.y(),x.z());
		data.put(x);
		display.update();
	}
}