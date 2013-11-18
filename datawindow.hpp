#ifndef BIRD_DATA_WINDOW_HPP
#define BIRD_DATA_WINDOW_HPP

#include <queue> 

namespace mm
{
	template<typename T>
	class DataWindow
	{
	public:
		DataWindow(size_t size):m_size(size){};
		void put(const T& t)
		{
			if(data.size()>=m_size)
			{
				data.pop();
				put(t);
			}
			data.push(t);
		}
		
		typename std::queue<T>::iterator begin(){return data.begin();}
		typename std::queue<T>::iterator end(){return data.end();}
		
	private:
		size_t m_size;
		std::queue<T> data;
		
	};
	
}

#endif