// MouseEvent.h
// -> Mouse event dispatching implementations
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 21:10

#ifndef PGAPPORSTLNAME_MOUSEEVENT_H
#define PGAPPORSTLNAME_MOUSEEVENT_H


#include "events/Event.h"

namespace pgName {
	
	// ===================================================================================
	//	Mouse Moved
	// ===================================================================================
	class MouseMovedEvent : public Event {
		
	public:
		MouseMovedEvent(float x, float y);
		
		inline float getX() const;
		inline float getY() const;
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(MouseMoved)
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryInput | EventCategoryMouse)
		
	private:
		float mMouseX;
		float mMouseY;
	};
	
	// ===================================================================================
	//	Mouse Scrolled
	// ===================================================================================
	class MouseScrolledEvent : public Event {
		
	public:
		MouseScrolledEvent(float xOffset, float yOffset);
		
		float getXOffset() const;
		float getYOffset() const;
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(MouseScrolled)
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryInput | EventCategoryMouse)
		
	private:
		float mXOffset;
		float mYOffset;
	};
	
	// ===================================================================================
	//	Mouse Button (Base)
	// ===================================================================================
	class MouseButtonEvent : public Event {
		
	public:
		int getMouseButton() const;
		
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryInput | EventCategoryMouse)
		
	protected:
		MouseButtonEvent(int button);
		
		int mButton;
	};
	
	// ===================================================================================
	//	Mouse Button Pressed
	// ===================================================================================
	class MouseButtonPressedEvent : public MouseButtonEvent {
		
	public:
		MouseButtonPressedEvent(int button);
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(MouseButtonPressed)
	};
	
	// ===================================================================================
	//	Mouse Button Released
	// ===================================================================================
	class MouseButtonReleasedEvent : public MouseButtonEvent {
		
	public:
		MouseButtonReleasedEvent(int button);
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(MouseButtonReleased)
	};
	
} // pgName


#endif // PGAPPORSTLNAME_MOUSEEVENT_H