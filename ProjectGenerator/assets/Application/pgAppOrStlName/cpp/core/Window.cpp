// Window.cpp
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/21 15:46

#include "core/Window.h"


namespace pgName {

	static void GLAPIENTRY MessageCallback(GLenum source, 
											GLenum type, 
											GLuint id, 
											GLenum severity, 
											GLsizei length, 
											const GLchar* message, 
											const void* userParam) {
		
		if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) {
			return;
		}
		
		// suppress useless warnings
		switch (id) {
			case 131218:
				return;
			default:
				break;
		}
		
		std::stringstream ss;
		ss << "--OpenGL-callback--\n";
		ss << "Message: " << message << "\n";
		ss << "Type: ";
		
		switch (type) {
			
			case GL_DEBUG_TYPE_ERROR:
				ss << "ERROR\n";
				break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
				ss << "DEPRECIATED_BEHAVIOR\n";
				break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				ss << "UNDEFINED_BEHAVIOR\n";
				break;
			case GL_DEBUG_TYPE_PORTABILITY:
				ss << "PORTABILITY\n";
				break;
			case GL_DEBUG_TYPE_PERFORMANCE:
				ss << "PERFORMANCE\n";
				break;
			case GL_DEBUG_TYPE_OTHER:
				ss << "OTHER\n";
				break;
		}
		
		ss << "Id: " << id << "\n";
		ss << "Severity: ";
		switch (severity) {
			
			case GL_DEBUG_SEVERITY_LOW:
				ss << "LOW\n";
				break;
			case GL_DEBUG_SEVERITY_MEDIUM:
				ss << "MEDIUM\n";
				break;
			case GL_DEBUG_SEVERITY_HIGH:
				ss << "HIGH\n";
				break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:
				ss << "NOTIFICATION\n";
				break;
			default:
				ss << "UNKNOWN\n";
		}
		
		Logger::Warning(ss.str());
	}

	Window* Window::create(uint32_t width, uint32_t height, const std::string& name, bool fullscreenMode) {
		return new Window(width, height, name, fullscreenMode);
	}

	Window::Window(uint32_t width, uint32_t height, const std::string& name, bool fullscreenMode) {
		init(width, height, name, fullscreenMode);
	}

	void Window::init(uint32_t width, uint32_t height, const std::string& name, bool fullScreenMode) {
		
		Logger::Debug("Initializing GLFW");
		glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);
		Logger::Assert(glfwInit(), "Unable to initialize GLFW");
		
			
		// Decide GL+GLSL versions
		#if defined(__APPLE__)
		// GL 3.2 + GLSL 150
		// const char* glsl_version = "#version 150";
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
		
		// Window size is doubled on mac -> this will help keep it accurate
		glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);
		#else
		// GL 3.0 + GLSL 130
		// const char* glsl_version = "#version 130";
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
		#endif
			
		// Only supply the monitor if we would like to start in fullscreen mode
		GLFWmonitor* primaryMonitor = fullScreenMode ? glfwGetPrimaryMonitor() : nullptr;
		
		GLFWwindow* window = glfwCreateWindow(width, height, name.c_str(), primaryMonitor, NULL); // primaryMonitor, NULL
		mWindowHandle = window;
		Logger::Assert(mWindowHandle != nullptr, "GLFW unable to create window.");
		
		glfwMakeContextCurrent(window);
		
		Logger::Debug("Initializing GLAD");
		Logger::Assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Unable to initialize GLAD."); // TODO: should this be done twice?
		glfwSetWindowUserPointer(window, this);
		
		// Set up event callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in window size callback.");
			
			userWin->setWidth(width);
			userWin->setHeight(height);
			
			WindowResizeEvent e(width, height);
			userWin->mEventCallback(e);
		});
		
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in window close callback.");
			
			WindowCloseEvent e;
			userWin->mEventCallback(e);
		});
		
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in key callback.");
			
			Input::keyCallback(key, scancode, action, mods);
			switch (action) {
				
				case TACO_PRESS: {
					KeyPressedEvent e(key, 0);
					userWin->mEventCallback(e);
					break;
				}
				
				case TACO_RELEASE: {
					KeyReleasedEvent e(key);
					userWin->mEventCallback(e);
					break;
				}
				
				case TACO_REPEAT: {
					KeyPressedEvent e(key, 1);
					userWin->mEventCallback(e);
					break;
				}
			
			}
		});
		
		glfwSetCharCallback(window, [](GLFWwindow* window, uint32_t keycode)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in char callback.");
			
			// KeyTypedEvent e(keycode);
			// userWin->mEventCallback(e);
		});
		
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in mouse button callback.");
			
			Input::mouseButtonCallback(button, action, mods);
			switch (action) {
				
				case TACO_PRESS: {
					MouseButtonPressedEvent e(button);
					userWin->mEventCallback(e);
					break;
				}
				
				case TACO_RELEASE: {
					MouseButtonReleasedEvent e(button);
					userWin->mEventCallback(e);
					break;
				}
				
			}
		});
		
		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in scroll callback.");
			
			Input::scrollCallback(xoffset, yoffset);
			MouseScrolledEvent e((float)xoffset, (float)yoffset);
			userWin->mEventCallback(e);
		});
		
		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
		{
			Window* userWin = static_cast<Window*>(glfwGetWindowUserPointer(window));
			Logger::Assert(userWin != nullptr, "Window is nullpointer in cursor pos callback.");
			
			Input::cursorCallback(xpos, ypos);
			MouseMovedEvent e((float)xpos, (float)ypos);
			userWin->mEventCallback(e);
		});
		
		// during init, enable debug output
		glEnable(GL_DEBUG_OUTPUT);
		// glDebugMessageCallback(MessageCallback, 0); // TODO: find why this causes a segmentation fault
		
		setVSync(true);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		// clear using dk grey
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		
		// Set viewport
		glViewport(0, 0, width, height);
	}

	void Window::setEventCallback(const EventCallbackFn& callback) {
		
		mEventCallback = callback;
	}

	void Window::onUpdate() {
		
		glfwPollEvents();
	}

	void Window::render() {
		
		glClear(GL_COLOR_BUFFER_BIT); // TODO: should clearing color be done here?
		glfwSwapBuffers((GLFWwindow*)mWindowHandle);
	}

	// Window attributes
	void Window::setVSync(bool enabled) {
		
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		
		mVSync = enabled;
	}

	bool Window::isVSync() const {
		
		return mVSync;
	}

	void* Window::getNativeWindow() const {
		
		return mWindowHandle;
	}

	glm::vec2 Window::getWindowPos() {
		
		GLFWwindow* win = static_cast<GLFWwindow*>(mWindowHandle);
		int x, y;
		glfwGetWindowPos(win, &x, &y);
		return { x, y };
	}

	void Window::setTitle(const char* newTitle) {
		
		GLFWwindow* win = static_cast<GLFWwindow*>(mWindowHandle);
		glfwSetWindowTitle(win, newTitle);
	}

	void Window::setSize(const glm::vec2& size) {
		
		GLFWwindow* win = static_cast<GLFWwindow*>(mWindowHandle);
		Logger::Assert(size.x >= 0 && size.y >= 0, "Window width or height cannot be 0.");
		glfwSetWindowSize(win, (int)size.x, (int)size.y);
	}

	glm::vec2 Window::getMonitorSize() {
		
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		return { mode->width, mode->height };
	}

	void Window::destroy() {
		
		NFD_Quit();
		glfwDestroyWindow((GLFWwindow*)mWindowHandle);
	}

	bool Window::isRunning() {
		return mRunning;
	}
	
} // pgName