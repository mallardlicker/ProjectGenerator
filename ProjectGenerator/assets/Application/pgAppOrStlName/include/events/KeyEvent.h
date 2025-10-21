// KeyEvent.h
// -> Key event dispatching implementations
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 21:06

#ifndef PGAPPORSTLNAME_KEYEVENT_H
#define PGAPPORSTLNAME_KEYEVENT_H


#include "events/Event.h"

namespace pgName {
	
	// ===================================================================================
	//	Base
	// ===================================================================================
	class KeyEvent : public Event {
		
	public:
		int getKeyCode() const;
		
		EVENT_CLASS_CATEGORY_HEADER(EventCategoryKeyboard | EventCategoryInput)
		
	protected:
		// Abstract class, should not be instantiated
		KeyEvent(int keycode);
		
		int mKeyCode;
	};
	
	// ===================================================================================
	//	Key Pressed
	// ===================================================================================
	class KeyPressedEvent : public KeyEvent {
		
	public:
		KeyPressedEvent(int keycode, int repeatCount);
		
		inline int getRepeatCount() const;
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(KeyPressed)
		
	private:
		int mRepeatCount;
	};
	
	// ===================================================================================
	//	KeyReleased
	// ===================================================================================
	class KeyReleasedEvent : public KeyEvent {
		
	public:
		KeyReleasedEvent(int keydode);
		
		std::string toString() const override;
		
		EVENT_CLASS_TYPE_HEADER(KeyReleased)
	};
	
	// ===================================================================================
	//	KeyTyped
	// ===================================================================================
	class KeyTypedEvent : public KeyEvent {
		
		public:
			KeyTypedEvent(int keydode);
			
			std::string toString() const override;
			
			EVENT_CLASS_TYPE_HEADER(KeyTyped)
	};
	
} // pgName


#endif // PGAPPORSTLNAME_KEYEVENT_H