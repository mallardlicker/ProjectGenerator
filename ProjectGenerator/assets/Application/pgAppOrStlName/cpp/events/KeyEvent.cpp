// KeyEvent.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 21:07

#include "events/KeyEvent.h"


namespace pgName {
	
	// ===================================================================================
	//	Base
	// ===================================================================================
	KeyEvent::KeyEvent(int keycode) : mKeyCode(keycode) {
		
	}
	
	int KeyEvent::getKeyCode() const {
		
		return mKeyCode;
	}
	
	EVENT_CLASS_CATEGORY_IMPL(EventCategoryKeyboard | EventCategoryInput, KeyEvent)
	
	// ===================================================================================
	//	Key Pressed
	// ===================================================================================
	KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), mRepeatCount(repeatCount) {
		
	}
	
	int KeyPressedEvent::getRepeatCount() const {
		
		return mRepeatCount;
	}
	
	std::string KeyPressedEvent::toString() const {
		
		std::stringstream ss;
		ss << "KeyPressedEvent: " << mKeyCode << "(" << mRepeatCount << ")";
		return ss.str();
	}
	
	EVENT_CLASS_TYPE_IMPL(KeyPressed, KeyPressedEvent)
	
	// ===================================================================================
	//	Key Released
	// ===================================================================================
	KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode) {
		
	}
	
	std::string KeyReleasedEvent::toString() const {
		
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << mKeyCode;
		return ss.str();
	}
	
	EVENT_CLASS_TYPE_IMPL(KeyReleased, KeyReleasedEvent)
	
	// ===================================================================================
	//	Key Typed
	// ===================================================================================
	KeyTypedEvent::KeyTypedEvent(int keycode) : KeyEvent(keycode) {
		
	}
	
	std::string KeyTypedEvent::toString() const {
		
		std::stringstream ss;
		ss << "KeyTypedEvent: " << mKeyCode;
		return ss.str();
	}
	
	EVENT_CLASS_TYPE_IMPL(KeyTyped, KeyTypedEvent)
	
} // pgName