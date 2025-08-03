#include <iostream>
#include <Lacerta.h>
class Sandbox : public Lacerta::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lacerta::Application* Lacerta::CreateApplication()
{
	return new Sandbox();
}
