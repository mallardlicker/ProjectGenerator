// Window.h
// -> A basic window built on the GLFW framework
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 21:14

#ifndef PGAPPORSTLNAME_WINDOW_H
#define PGAPPORSTLNAME_WINDOW_H


#include "externalLibs.h"
#include "events/Event.h"

namespace pgName {
	
	class Window {
		public:
			using EventCallbackFn = std::function<void(Event&)>;
			
			Window(uint32_t width, uint32_t height, const std::string& name, bool fullscreenMode = false);
			
			void init(uint32_t width, uint32_t height, const std::string& name, bool fullscreenMode = false);
			void onUpdate();
			
			// Window attributes
			void setVSync(bool enabled);
			bool isVSync() const;
			
			void* getNativeWindow() const;
			
			static Window* create(uint32_t width, uint32_t height, const std::string& name, bool fullscreenMode = false);
			
			bool isRunning();
			void setEventCallback(const EventCallbackFn& callback);
			glm::vec2 getWindowPos();
			
			void setWidth(const int newWidth) { mSize.x = (float)newWidth; }
			void setHeight(const int newHeight) { mSize.y = (float)newHeight; }
			void setSize(const glm::vec2& size);
			void setTitle(const char* newTitle);
			glm::vec2 getMonitorSize();
			int getWidth() const { return (int)mSize.x; };
			int getHeight() const { return (int)mSize.y; };
			const glm::vec2& getSize() const { return mSize; }
			
			float getTargetAspectRatio() const { return mTargetAspectRatio; }
			void render();
			
			void destroy();
			
		private:
			Window() = default;
			
			void* mWindowHandle = nullptr;
			
			EventCallbackFn mEventCallback = nullptr;
			bool mVSync = false;
			bool mRunning = true;
			glm::vec2 mSize{ 1280, 800 };
			float mTargetAspectRatio = 2560.0f / 1600.0f;
	};

} // pgName

#endif // PGAPPORSTLNAME_WINDOW_H
