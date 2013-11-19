#ifndef ACCP_DISPLAY_HPP
#define ACCP_DISPLAY_HPP

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "../data/datawindow.hpp"
#include "../data/trio.hpp"
#include "../data/datagen.hpp"
#include "program.h"


#include<iostream>
namespace mm
{
	void GlewInit();
	class Display
	{
	public:
		Display(int x_,int y_,DataWindow<Trio>& d);
		void update();
	private:
		int x,y;
		DataWindow<Trio>& data;
		sf::Window* win;
		
		GLuint vao;
		GLuint vbo;
		
		GLint col_loc;
		
		mm::Program* prog;
		
	};
	
}

#endif