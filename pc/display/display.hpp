#ifndef ACCP_DISPLAY_HPP
#define ACCP_DISPLAY_HPP

#include <GL/glew.h>
#include <SFML/Window.hpp>

#include "../datawindow.hpp"
#include "../trio.hpp"
#include "datagen.hpp"
#include "program.h"


#include<iostream>
namespace mm
{
	void GlewInit();
	class Display
	{
	public:
		Display(int x_,int y_,DataWindow<Trio>& d):
		x(x_),y(y_),data(d)
		{
			win=new sf::Window(sf::VideoMode(x,y),"plot");
			setup();
			
		}
		void setup()
		{
			GlewInit();
			glClearColor(1.0f,1.0f,1.0f,1.0f);
			prog = new mm::Program
			(
				{
					mm::Shader(GL_VERTEX_SHADER,"vert.glsl"),
					mm::Shader(GL_FRAGMENT_SHADER,"frag.glsl")
				}
			);
			
			glUseProgram(prog->getHandle());
			
// 			float buf[] = {0.0f,0.0f,1.0f,0.0f,1.0f,1.0f};
			
			BufferData buf(data);
			
			glGenVertexArrays(1,&vao);
			glBindVertexArray(vao);
			glGenBuffers(1,&vbo);
			
			glBindBuffer(GL_ARRAY_BUFFER,vbo);
			glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.x,GL_DYNAMIC_DRAW);
			glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,0);
			glEnableVertexAttribArray(0);
			
			
			
		}
		void draw()
		{
			if(!win->isOpen())
				return;
			glClear(GL_COLOR_BUFFER_BIT);
			
			BufferData buf(data);
			glBindBuffer(GL_ARRAY_BUFFER,vbo);
			glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.x,GL_DYNAMIC_DRAW);		
			glDrawArrays(GL_LINE_STRIP,0,1000);
			
			
			
			
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
		sf::Window* win;
		
		GLuint vao;
		GLuint vbo;
		
		mm::Program* prog;
		
	};
	
}

#endif