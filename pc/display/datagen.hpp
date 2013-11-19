#ifndef ACCP_DATAGEN_HPP
#define ACCP_DATAGEN_HPP
#include "../datawindow.hpp"
#include "../trio.hpp"
#include<iostream>
namespace mm
{
	class BufferData
	{
	public:
		BufferData(DataWindow<Trio>& d)
		{
			x=new float[d.size()*2];
			y=new float[d.size()*2];
			z=new float[d.size()*2];
			
			auto it=d.begin();
			for(int i=0;i<1000;++i,++it)
			{
				
				x[2*i]=-1.0f+2.0f/1000*i;
				x[2*i+1]=-1.0f+5*2.0f/6+ 1.0f/256* it->x(); 
				
				y[2*i]=-1.0f+2.0f/1000*i;
				y[2*i+1]=-1.0f+3*2.0f/6+ 1.0f/256* it->y(); 
				
				z[2*i]=-1.0f+2.0f/1000*i;
				z[2*i+1]=-1.0f+1*2.0f/6+ 1.0f/6*1.0f/128* it->z(); 
				
			}
			
		}
		~BufferData()
		{
			delete [] x;
			delete [] y;
			delete [] z;
		}
		float* x,*y,*z;
	};
}

#endif