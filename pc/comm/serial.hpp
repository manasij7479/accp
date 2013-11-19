#ifndef ACCP_SERIAL_HPP
#define ACCP_SERIAL_HPP

#include <boost/asio.hpp>

#include "../data/trio.hpp"

//Adapted from example code
namespace mm
{
	class SimpleSerial
	{
	public:
		/**
		* Constructor.
		* \param port device name, example "/dev/ttyUSB0" or "COM4"
		* \param baud_rate communication speed, example 9600 or 115200
		* \throws boost::system::system_error if cannot open the
		* serial device
		*/
		SimpleSerial(std::string port, unsigned int baud_rate)
		: io(), serial(io,port)
		{
			serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
		}

		/**
		* Write a string to the serial device.
		* \param s string to write
		* \throws boost::system::system_error on failure
		*/
	//     void writeString(std::string s)
	//     {
	//         boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
	//     }

		/**
		* Blocks until a line is received from the serial device.
		* Eventual '\n' or '\r\n' characters at the end of the string are removed.
		* \return a string containing the received line
		* \throws boost::system::system_error on failure
		*/
	//     std::string readLine()
	//     {
	//         //Reading data char by char, code is optimized for simplicity, not speed
	// 
	//         char c;
	//         std::string result;
	//         for(;;)
	//         {
	//             asio::read(serial,asio::buffer(&c,1));
	//             switch(c)
	//             {
	//                 case '\r':
	//                     break;
	//                 case '\n':
	//                     return result;
	//                 default:
	//                     result+=c;
	//             }
	//         }
	//     }
	//     
		Trio getTrio()
		{

			Trio result;
			while(true)//magic number sync for testing
			{
				char s;
				boost::asio::read(serial,boost::asio::buffer(&s,1));
				if(s==27)
					break;
			}
			boost::asio::read(serial,boost::asio::buffer(result.data,3));
			return result;
		}

	private:
		boost::asio::io_service io;
		boost::asio::serial_port serial;
	};
}
#endif