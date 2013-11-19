#include "display.hpp"



namespace mm
{
		void GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
			std::cerr<<"Error "<<glewGetErrorString(err);
	}
}