// main.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/21 15:14

#include "externalLibs.h"
#include "core/Application.h"

extern pgName::Application* pgName::createApplication();

int main() {
	
	Logger::Info("Hello pgName!");
	using namespace pgName;
	
	Application* application = createApplication();
	
	application->init();
	
	application->run();
	
	application->shutdown();
	
	delete application;
	return 0;
}
