#ifndef ACCP_TRIO_HPP
#define ACCP_TRIO_HPP

namespace mm
{
	struct Trio
	{
		Trio()
		{
			data[0]=0;
			data[1]=0;
			data[2]=0;
		}
		Trio(char x,char y,char z)
		{
			data[0]=x;
			data[1]=y;
			data[2]=z;
		}
		char data[3];
		char& x(){return data[0];}
		char& y(){return data[1];}
		char& z(){return data[2];}
	};
}

#endif