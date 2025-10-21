// WindowEvent.h
// -> Window event dispatching implementations
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/21 15:45

#ifndef PGAPPORSTLNAME_WINDOWEVENT_H
#define PGAPPORSTLNAME_WINDOWEVENT_H


#include "events/Event.h"

namespace pgName {
	
	// ===================================================================================
	//	Window Resize
	// ===================================================================================
	class WindowResizeEvent : public Event {
		
	public:
		WindowResizeEvent(uint32_t width, uint32_t height);
		
		uint32_t getWidth() const;
		uint32_t getHeight() const;
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(WindowResize)
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryApplication)
		
	private:
		uint32_t mWidth;
		uint32_t mHeight;
	};
	
	// ===================================================================================
	//	Window Close
	// ===================================================================================
	class WindowCloseEvent : public Event {
		
	public:
		WindowCloseEvent();
		
		EVENT_CLASS_TYPE_HEADER(WindowClose)
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryApplication)
	};
	
} // pgName


#endif // PGAPPORSTLNAME_WINDOWEVENT_H