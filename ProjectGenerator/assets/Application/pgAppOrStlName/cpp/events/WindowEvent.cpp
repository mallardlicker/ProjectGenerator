// WindowEvent.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/21 15:45

#include "events/WindowEvent.h"


namespace pgName {
	
	// ===================================================================================
	//	Window Resize
	// ===================================================================================
	WindowResizeEvent::WindowResizeEvent(uint32_t width, uint32_t height) : 
														mWidth(width), mHeight(height) {}
	
	uint32_t WindowResizeEvent::getWidth() const {
		
		return mWidth;
	}
	
	uint32_t WindowResizeEvent::getHeight() const {
		
		return mHeight;
	}
	
	std::string WindowResizeEvent::toString() const {
		
		std::stringstream ss;
		ss << "WindowResizeEvent: " << mWidth << ", " << mHeight;
		return ss.str();
	}
	
	EVENT_CLASS_TYPE_IMPL(WindowResize, WindowResizeEvent)
	EVENT_CLASS_CATEGORY_IMPL(EventCategoryApplication, WindowResizeEvent)
	
	// ===================================================================================
	//	Window Close
	// ===================================================================================
	WindowCloseEvent::WindowCloseEvent() {}
	
	EVENT_CLASS_TYPE_IMPL(WindowClose, WindowCloseEvent)
	EVENT_CLASS_CATEGORY_IMPL(EventCategoryApplication, WindowCloseEvent)
	
} // pgName