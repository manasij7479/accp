#include "display.hpp"



namespace mm
{
	void GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
			std::cerr<<"Error "<<glewGetErrorString(err);
	}
	Display::Display(int x_,int y_,DataWindow<Trio>& d):
	x(x_),y(y_),data(d)
	{
		win=new sf::Window(sf::VideoMode(x,y),"plot");
		GlewInit();
		glClearColor(1.0f,1.0f,1.0f,1.0f);
		prog = new mm::Program
		(
			{
				mm::Shader(GL_VERTEX_SHADER,"display/vert.glsl"),
				mm::Shader(GL_FRAGMENT_SHADER,"display/frag.glsl")
			}
		);
		
		glUseProgram(prog->getHandle());
		
		col_loc = glGetUniformLocation(prog->getHandle(),"col");
		
		BufferData buf(data);
		
		glGenVertexArrays(1,&vao);
		glBindVertexArray(vao);
		glGenBuffers(1,&vbo);
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.x,GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,0);
		glEnableVertexAttribArray(0);
		
	}
	void Display::update()
	{
		if(!win->isOpen())
			return;
		glClear(GL_COLOR_BUFFER_BIT);
		
		BufferData buf(data);
		
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.x,GL_DYNAMIC_DRAW);
		glUniform4f(col_loc,1.0f,0.0f,0.0f,1.0f);
		glDrawArrays(GL_LINE_STRIP,0,data.size());
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.y,GL_DYNAMIC_DRAW);		
		glUniform4f(col_loc,0.0f,1.0f,0.0f,1.0f);
		glDrawArrays(GL_LINE_STRIP,0,data.size());
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,data.size()*2*sizeof(float),buf.z,GL_DYNAMIC_DRAW);		
		glUniform4f(col_loc,0.0f,0.0f,1.0f,1.0f);
		glDrawArrays(GL_LINE_STRIP,0,data.size());
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		float x[4]={-1.0f,-1.0f+2.0f/3,1.0f,-1.0f+2.0f/3};
		glBufferData(GL_ARRAY_BUFFER,4*sizeof(float),x,GL_DYNAMIC_DRAW);		
		glUniform4f(col_loc,0.0f,0.0f,0.0f,1.0f);
		glDrawArrays(GL_LINE_STRIP,0,2);
		
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		float y[4]={-1.0f,-1.0f+4.0f/3,1.0f,-1.0f+4.0f/3};
		glBufferData(GL_ARRAY_BUFFER,4*sizeof(float),y,GL_DYNAMIC_DRAW);		
		glUniform4f(col_loc,0.0f,0.0f,0.0f,1.0f);
		glDrawArrays(GL_LINE_STRIP,0,2);
		
		
		

		win->display();
		sf::Event event;
		while(win->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win->close();
		}
	}
}