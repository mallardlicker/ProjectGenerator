// Input.h
// -> Input handler through the Event(.h) system
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 21:00

#ifndef PGAPPORSTLNAME_INPUT_H
#define PGAPPORSTLNAME_INPUT_H


#include "externalLibs.h"

namespace pgName {
	
	class Input {
		public:
			static void init();
			
			static void keyCallback(int key, int scanCode, int action, int mods);
			static void cursorCallback(double xPos, double yPos);
			static void mouseButtonCallback(int button, int action, int mods);
			static void scrollCallback(double xOffset, double yOffset);
			
			static bool keyPressed(int keyCode);
			static bool mouseButtonPressed(int mouseButton);
			static float mouseX();
			static float mouseY();
			static float scrollX();
			static float scrollY();
			static void endFrame();
			static glm::vec2 mousePos();
			
		private:
			Input() = default;
			
			static bool sInitialized;
		
			static bool sKeyPressed[TACO_KEY_LAST]; // GLFW_KEY_LAST
			static bool sMouseButtonPressed[TACO_MOUSE_BUTTON_LAST]; // GLFW_MOUSE_BUTTON_LAST
			static float sXPos;
			static float sYPos;
			static float sScrollX;
			static float sScrollY;
	};
	
} // pgName


#endif // PGAPPORSTLNAME_INPUT_H