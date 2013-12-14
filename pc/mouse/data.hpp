#ifndef ACCP_MOUSE_DATA_HPP
#define ACCP_MOUSE_DATA_HPP
#include "../data/datawindow.hpp"
#include "../data/trio.hpp"
#include "mouse.hpp"
namespace mm
{
	class MouseHandler
	{
	public:
		MouseHandler(DataWindow<Trio>& d):data(d){};
		void update() ///Nothing works here!! Need to study Kalman filters in DSP :'(
		{
			Trio a=*data.begin(),b=data.back();
			int x=b.x()-a.x();
			int y=b.y()-a.y();
			
			m.move(x,y);
		}
	private:
		DataWindow<Trio>& data;
		Mouse m;
		
	};
}
#endif