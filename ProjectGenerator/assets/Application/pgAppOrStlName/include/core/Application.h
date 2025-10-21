// Application.h
// -> A basic application structure, which contains a Window
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/06 22:23

#ifndef PGAPPORSTLNAME_APPLICATION_H
#define PGAPPORSTLNAME_APPLICATION_H


#include "externalLibs.h"
#include "core/Window.h"
#include "events/Event.h"

namespace pgName {
	
	// ===================================================================================
	// App Layer
	// ===================================================================================
	namespace AppLayer {
		void init();
		
		// void onAttach();
		// void onUpdate();
		// void onRender();
		void onEvent(Event& e);
	}
	
	// ===================================================================================
	// Application Data (typically utilized in AppEngine frameworks)
	// ===================================================================================
	// typedef void (*AppOnUpdateFn)(SceneData& scene, float dt);
	// typedef void (*AppOnAttachFn)(SceneData& scene);
	// typedef void (*AppOnRenderFn)(SceneData& scene);
	typedef void (*AppOnEventFn)(Event& e);

	struct ApplicationData {
		
	// 	AppOnUpdateFn appOnUpdate = nullptr; // <callback function to update the app.>
	// 	AppOnAttachFn appOnAttach = nullptr; // <callback function to attach the app.>
	// 	AppOnRenderFn appOnRender = nullptr; // <callback function to render the app.>
		AppOnEventFn appOnEvent = nullptr; // <callback function to forward events to the app.>
	};
	
	// ===================================================================================
	// Application class
	// ===================================================================================
	class Application {
		public:
			Application();
			virtual ~Application() = default;
			
			virtual void init();
			virtual void shutdown() { }
			
			void run();
			void stop();
			
			virtual void onEvent(Event& e);
			Window* getWindow() const;
			
			static Application* get();
			
			// void setAppData(AppOnAttachFn attachFn, AppOnUpdateFn updateFn, AppOnRenderFn renderFn, AppOnEventFn eventFn);
			void setAppData(AppOnEventFn eventFn);
			
		protected:
			virtual void beginFrame() { }
			virtual void endFrame() { }
			
		private:
			bool onWindowClose(WindowCloseEvent& e);
			
			static Application* sInstance;
			
			bool mRunning;
			
			float mLastFrameTime = 0;
			
		protected:
			Window* mWindow;
			ApplicationData mAppData;
	};

	// defined by CLIENT
	Application* createApplication();

} // pgName


#endif // PGAPPORSTLNAME_APPLICATION_H