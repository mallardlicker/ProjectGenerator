// event.h
// -> Event and EventDispatcher classes, utilized to pass events throughout application
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 20:42

#ifndef PGAPPORSTLNAME_EVENT_H
#define PGAPPORSTLNAME_EVENT_H


#include "externalLibs.h"

#pragma warning ( push )
#pragma warning ( disable : 26812 )

namespace pgName {
	
	// ===================================================================================
	// Event enums
	// ===================================================================================
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	enum EventCategory {
		None = 0,
		EventCategoryApplication = 	0x00000001,
		EventCategoryInput = 		0x00000010,
		EventCategoryKeyboard = 	0x00000100,
		EventCategoryMouse = 		0x00001000,
		EventCategoryMouseButton = 	0x00010000
	};
	
	// ===================================================================================
	// Event helper macros
	// ===================================================================================
	#define EVENT_CLASS_TYPE_HEADER(type) static EventType getStaticType(); \
						virtual EventType getType() const override; \
						virtual const char* getName() const override;
	
	#define EVENT_CLASS_TYPE_IMPL(type, clazz) EventType clazz::getStaticType() { return EventType::type; } \
						EventType clazz::getType() const { return getStaticType(); } \
						const char* clazz::getName() const { return #type; }
	
	#define EVENT_CLASS_CATEGORY_HEADER(category) int getCategoryFlags() const override;
	#define EVENT_CLASS_CATEGORY_IMPL(category, clazz) int clazz::getCategoryFlags() const { return category; }
	
	// ===================================================================================
	// Event base class
	// ===================================================================================
	class Event {
		friend class EventDispatcher;
		
		public:
			virtual EventType getType() const = 0;
			virtual const char* getName() const = 0;
			virtual int getCategoryFlags() const = 0;
			virtual std::string toString() const { return getName(); }
			
			bool isInCategory(EventCategory category) const { return getCategoryFlags() & category; }
			
			bool handled = false;
	};
	
	// ===================================================================================
	// Event dispatcher
	// ===================================================================================
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
		
		public:
			EventDispatcher(Event& e) : mEvent(e) { }
			
			template<typename T>
			bool dispatch(EventFn<T> function) {
				if (mEvent.getType() == T::getStaticType()) {
					
					mEvent.handled = function(*(T*)&mEvent);
					return true;
				}
				
				return false;
			}
			
		private:
			Event& mEvent;
	};
	
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
	
}

#include "events/Input.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

#pragma warning ( pop )


#endif // PGAPPORSTLNAME_EVENT_H