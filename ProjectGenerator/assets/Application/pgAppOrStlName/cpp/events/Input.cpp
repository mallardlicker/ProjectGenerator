// Input.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 22:42

#include "events/Input.h"

#include "core/Application.h"

namespace pgName {
	
	bool Input::sInitialized = false;
	bool Input::sKeyPressed[TACO_KEY_LAST]{ };
	bool Input::sMouseButtonPressed[TACO_MOUSE_BUTTON_LAST]{ };
	float Input::sXPos = 0.0f;
	float Input::sYPos = 0.0f;
	float Input::sScrollX = 0.0f;
	float Input::sScrollY = 0.0f;
	
	void Input::init() {
		
		Logger::Debug("Initializing Input");
		Logger::Assert(!sInitialized, "Input already initialized.");
		sInitialized = true;
		const glm::vec2& windowSize = Application::get()->getWindow()->getSize();
	}
	
	void Input::keyCallback(int key, int scanCode, int action, int mods) {
		
		sKeyPressed[key] = (action == TACO_PRESS || action == TACO_REPEAT) ? true : false;
	}
	
	bool Input::keyPressed(int keyCode) {
		
		if (keyCode > TACO_KEY_UNKNOWN && keyCode <= TACO_KEY_LAST) {
			
			return sKeyPressed[keyCode];
		}
		
		return false;
	}
	
	void Input::mouseButtonCallback(int button, int action, int mods) {
		
		sMouseButtonPressed[button] = action == TACO_PRESS ? true : false;
	}
	
	bool Input::mouseButtonPressed(int mouseButton) {
		
		if (mouseButton >= 0 && mouseButton < 3) {
			
			return sMouseButtonPressed[mouseButton];
		}
		
		return false;
	}
	
	void Input::cursorCallback(double xPos, double yPos) {
		
		sXPos = (float)xPos;
		sYPos = (float)yPos;
	}
	
	float Input::mouseX() {
		
		return sXPos;
	}
	
	float Input::mouseY() {
		
		return sYPos;
	}
	
	void Input::scrollCallback(double xOffset, double yOffset) {
		
		sScrollX = (float)xOffset;
		sScrollY = -(float)yOffset;
	}
	
	float Input::scrollX() {
		
		return sScrollX;
	}
	
	float Input::scrollY() {
		
		return sScrollY;
	}
	
	void Input::endFrame() {
		
		sScrollX = 0;
		sScrollY = 0;
	}
	
	glm::vec2 Input::mousePos() {
		
		return glm::vec2{ sXPos, sYPos };
	}
	
} // pgName