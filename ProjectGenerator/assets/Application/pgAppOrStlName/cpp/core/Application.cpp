// Application.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/21 14:53

#include "core/Application.h"
#include "utilities/Settings.h"


namespace pgName {
	
	// ===================================================================================
	// App Layer
	// ===================================================================================
	namespace AppLayer {
		void init() {
			
		}
		
		// void onAttach() { 
		
		// }
		
		// void onUpdate() { 
		
		// }
		
		// void onRender() { 
		
		// }
		
		void onEvent(Event& e) {
			
		}
	}
	
	// ===================================================================================
	// Application Data (typically utilized in AppEngine frameworks)
	// ===================================================================================
	// Stub methods
	// static void AppOnUpdate(SceneData& scene, float dt) { }
	// static void AppOnAttach(SceneData& scene) { }
	// static void AppOnRender(SceneData& scene) { }
	static void AppOnEvent(Event& e) { }

	// ===================================================================================
	// Application class
	// ===================================================================================
	Application::Application() {
		mRunning = true;
		
		Logger::Info("Initializing Application");
		mWindow = Window::create(1280, 800, "pgName Test Window");
		sInstance = this;
		
		mWindow->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}
	
	void Application::init() {
		CppUtils::CppUtils_Init();
		
#if SYS_ASSET_STORAGE
		Settings::appAssetsFolder = ASSETS_APP_DEST;
		Settings::appUserAssetsFolder = ASSETS_USER_DEST;
#else
		Settings::appAssetsFolder = ASSETS_APP_SOURCE;
		Settings::appUserAssetsFolder = ASSETS_USER_SOURCE;
#endif
		
		// Always initialize GLAD in app
		Logger::Debug("Initializing GLAD functions in app.");
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			
			Logger::Error("Unable to initialize GLAD.");
		}
		
		Input::init();
		
		Logger::Info("Done initializing Application");
	}

	void Application::run() {
		
		// if (!mAppData.appOnUpdate) { mAppData.appOnUpdate = AppOnUpdate; }
		// if (!mAppData.appOnAttach) { mAppData.appOnAttach = AppOnAttach; }
		// if (!mAppData.appOnRender) { mAppData.appOnRender = AppOnRender; }
		if (!mAppData.appOnEvent) { mAppData.appOnEvent = AppOnEvent; }
		
		while (mRunning) {
			float time = (float)glfwGetTime();
			float dt = time - mLastFrameTime;
			mLastFrameTime = time;
			
			// basic structure:
			
			beginFrame();
			// mAppData.appOnUpdate(mCurrentScene, dt);
			// mAppData.appOnRender(mCurrentScene, dt);
			endFrame();
			
			mWindow->render();
			mWindow->onUpdate();
			
			// Logger::Info("%s, %s .", dt, time);
		}
		
		mWindow->destroy();
	}

	bool Application::onWindowClose(WindowCloseEvent& e) {
		
		mRunning = false;
		return true;
	}

	void Application::onEvent(Event& e) {
		
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		
		mAppData.appOnEvent(e);
	}

	void Application::stop() {
		mRunning = false;
	}

	Window* Application::getWindow() const {
		return mWindow;
	}

	Application* Application::sInstance = nullptr;
	Application* Application::get() {
		if (!sInstance) {
			Logger::Error("Cannot get Application. It is nullptr.");
		}
		return sInstance;
	}
	
	void Application::setAppData(AppOnEventFn eventFn) {
		
		// mAppData.appOnAttach = attachFn;
		// mAppData.appOnUpdate = updateFn;
		// mAppData.appOnRender = renderFn;
		mAppData.appOnEvent = eventFn;
	}
	
	// ===================================================================================
	// Create application entry point
	// ===================================================================================
	Application* createApplication() {
		Application* app = new Application();
		app->setAppData(
		// 	AppLayer::onAttach,
		// 	AppLauer::onUpdate,
		// 	AppLayer::onRender,
			AppLayer::onEvent
		);
		
		return app;
	}

} // pgName