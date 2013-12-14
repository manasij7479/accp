#ifndef ACCP_DATA_WINDOW_HPP
#define ACCP_DATA_WINDOW_HPP

#include <queue> 


namespace mm
{
	template<typename T>
	class DataWindow
	{
	public:
		DataWindow(int size):m_size(size)
		{
			for(int i=0;i<size;++i)
			data.push_back(T());	
		}
		void put(const T& t)
		{
			data.pop_front();
			data.push_back(t);
		}
		
		int size()
		{
			return m_size;
		}
		typename std::deque<T>::iterator begin(){return data.begin();}
		typename std::deque<T>::iterator end(){return data.end();}
		typename std::deque<T>::const_iterator cbegin(){return data.cbegin();}
		typename std::deque<T>::const_iterator cend(){return data.cend();}
		
		
	private:
		int m_size;
		std::deque<T> data;
		
	};
	
}

#endif