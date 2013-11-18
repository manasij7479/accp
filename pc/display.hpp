#ifndef ACCP_DISPLAY_HPP
#define ACCP_DISPLAY_HPP

#include <SFML/Graphics.hpp>

#include "datawindow.hpp"
#include "trio.hpp"

namespace mm
{
	class Display
	{
	public:
		Display(int x_,int y_,DataWindow<Trio>& d):
		x(x_),y(y_),data(d)
		{
			win=new sf::RenderWindow(sf::VideoMode(x,y),"plot");
			
		}
		void draw()
		{
			if(!win->isOpen())
				return;
			win->clear(sf::Color::White);
			win->display();
			sf::Event event;
			while(win->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					win->close();
			}
		}
		
	private:
		int x,y;
		DataWindow<Trio>& data;
		sf::RenderWindow* win;
	};
	
}

#endif