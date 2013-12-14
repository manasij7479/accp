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
		void update()
		{
			m.move(1,1);
		}
	private:
		DataWindow<Trio>& data;
		Mouse m;
	};
}
#endif