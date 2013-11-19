#include "serial.hpp"
#include "datawindow.hpp"
#include "display/display.hpp"
#include "display/datagen.hpp"

#include<cstdio>
int main()
{

	mm::SimpleSerial port("/dev/ttyUSB0",9600);
	
	mm::DataWindow<mm::Trio> data(1000);
	
	mm::BufferData buf(data);
	
	mm::Display d(800,600,data);
	
	while(true)
	{
		auto x=port.getTrio();
		std::printf("%5d\t%5d\t%5d\n",x.x(),x.y(),x.z());
		data.put(x);
		d.draw();
	}
}