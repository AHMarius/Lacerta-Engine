#pragma once
#ifdef LCT_PLATFORM_WINDOWS

extern Lacerta::Application* Lacerta::CreateApplication();

int main(int argc, char** argv)
{  
	Lacerta::Logger::Init(); // Initialize the logger
	LCT_CORE_WARN("Lacerta Engine started with {} arguments", argc);
	LCT_CORE_INFO("Lacerta Engine version: 0.1.0");
	LCT_CLIENT_WARN("Client application started with {} arguments", argc);
	Lacerta::Application* app = Lacerta::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // LCT_PLATFORM_WINDOWS
