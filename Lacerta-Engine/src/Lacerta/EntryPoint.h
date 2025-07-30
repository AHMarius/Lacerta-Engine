#pragma once
#ifdef LCT_PLATFORM_WINDOWS

extern Lacerta::Application* Lacerta::CreateApplication();

int main(int argc, char** argv)
{  
	Lacerta::Application* app = Lacerta::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // LCT_PLATFORM_WINDOWS
