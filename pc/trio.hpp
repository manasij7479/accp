#ifndef ACCP_TRIO_HPP
#define ACCP_TRIO_HPP

namespace mm
{
	struct Trio
	{
		char data[3];
		char& x(){return data[0];}
		char& y(){return data[1];}
		char& z(){return data[2];}
	};
}

#endif