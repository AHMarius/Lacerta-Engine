#pragma once
#include "Core.h"
namespace Lacerta
{
	class LCT_API Application
	{
	public:
		Application();
		virtual ~Application(); // will be overridden by linked project
		void Run();
	};
	//To be defined in the client application
	Application* CreateApplication(); // To be defined in the client application
}