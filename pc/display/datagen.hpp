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
			y=z=nullptr;
			
			auto it=d.begin();
			for(int i=0;i<1000;++i,++it)
			{
				
				x[2*i]=-1.0f+2.0f/1000*i;
				x[2*i+1]=-1.0f+5*2.0f/6+ 2.0f/(3*(it->x())+128); 
				
// 				std::cout<<i<<"\t"<<x[2*i]<<'\t'<<x[2*i+1]<<std::endl;
				
			}
			
		}
		~BufferData()
		{
			delete [] x;
// 			delete [] y;
// 			delete [] z;
		}
		float* x,*y,*z;
	};
}

#endif