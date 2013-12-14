#include "comm/serial.hpp"
#include "data/datawindow.hpp"
#include "display/display.hpp"
#include "mouse/data.hpp"

#include<cstdio>
#include<iostream>
int main()
{

	mm::SimpleSerial port("/dev/ttyUSB0",9600);
	
	mm::DataWindow<mm::Trio> display_data(1000),mouse_data(10);
	
	mm::Display display(1366,768,display_data);
	
	mm::MouseHandler m(mouse_data);
	
	while(true)
	{
		auto x=port.getTrio();
		std::printf("%5d\t%5d\t%5d\n",x.x(),x.y(),x.z());
		
		display_data.put(x);
		mouse_data.put(x);
		
		display.update();
		m.update();
	}
}