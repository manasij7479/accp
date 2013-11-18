#ifndef BIRD_DATA_WINDOW_HPP
#define BIRD_DATA_WINDOW_HPP

#include <queue> 


namespace mm
{
	template<typename T>
	class DataWindow
	{
	public:
		DataWindow(int size):m_size(size){};
		void put(const T& t)
		{
			if(data.size()>=m_size)
			{
				data.pop_front();
				put(t);
			}
			data.push_back(t);
		}
		
		typename std::deque<T>::iterator begin(){return data.begin();}
		typename std::deque<T>::iterator end(){return data.end();}
		
	private:
		int m_size;
		std::deque<T> data;
		
	};
	
}

#endif