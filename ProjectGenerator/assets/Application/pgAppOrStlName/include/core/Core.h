// Core.h
// -> Definitions of keybinds and types used throughout Application
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/15 13:07

#ifndef PGAPPORSTLNAME_CORE_H
#define PGAPPORSTLNAME_CORE_H


// ===================================================================================
//	Keyboard inputs
// ===================================================================================
/* Button actions */
#define TACO_RELEASE      0
#define TACO_PRESS        1
#define TACO_REPEAT       2
#define TACO_DOUBLE_CLICK 3

/* The unknown key */
#define TACO_KEY_UNKNOWN            -1

/* Printable keys */
#define TACO_KEY_NUMPAD_0           20
#define TACO_KEY_NUMPAD_1           21
#define TACO_KEY_NUMPAD_2           22
#define TACO_KEY_NUMPAD_3           23
#define TACO_KEY_NUMPAD_4           24
#define TACO_KEY_NUMPAD_5           25
#define TACO_KEY_NUMPAD_6           26
#define TACO_KEY_NUMPAD_7           27
#define TACO_KEY_NUMPAD_8           28
#define TACO_KEY_NUMPAD_9           29
#define TACO_KEY_SPACE              32
#define TACO_KEY_APOSTROPHE         39  /* ' */
#define TACO_KEY_COMMA              44  /* , */
#define TACO_KEY_MINUS              45  /* - */
#define TACO_KEY_PERIOD             46  /* . */
#define TACO_KEY_SLASH              47  /* / */
#define TACO_KEY_0                  48
#define TACO_KEY_1                  49
#define TACO_KEY_2                  50
#define TACO_KEY_3                  51
#define TACO_KEY_4                  52
#define TACO_KEY_5                  53
#define TACO_KEY_6                  54
#define TACO_KEY_7                  55
#define TACO_KEY_8                  56
#define TACO_KEY_9                  57
#define TACO_KEY_SEMICOLON          59  /* ; */
#define TACO_KEY_EQUAL              61  /* = */
#define TACO_KEY_A                  65
#define TACO_KEY_B                  66
#define TACO_KEY_C                  67
#define TACO_KEY_D                  68
#define TACO_KEY_E                  69
#define TACO_KEY_F                  70
#define TACO_KEY_G                  71
#define TACO_KEY_H                  72
#define TACO_KEY_I                  73
#define TACO_KEY_J                  74
#define TACO_KEY_K                  75
#define TACO_KEY_L                  76
#define TACO_KEY_M                  77
#define TACO_KEY_N                  78
#define TACO_KEY_O                  79
#define TACO_KEY_P                  80
#define TACO_KEY_Q                  81
#define TACO_KEY_R                  82
#define TACO_KEY_S                  83
#define TACO_KEY_T                  84
#define TACO_KEY_U                  85
#define TACO_KEY_V                  86
#define TACO_KEY_W                  87
#define TACO_KEY_X                  88
#define TACO_KEY_Y                  89
#define TACO_KEY_Z                  90
#define TACO_KEY_LEFT_BRACKET       91  /* [ */
#define TACO_KEY_BACKSLASH          92  /* \ */
#define TACO_KEY_RIGHT_BRACKET      93  /* ] */
#define TACO_KEY_GRAVE_ACCENT       96  /* ` */
#define TACO_KEY_WORLD_1            161 /* non-US #1 */
#define TACO_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define TACO_KEY_ESCAPE             256
#define TACO_KEY_ENTER              257
#define TACO_KEY_TAB                258
#define TACO_KEY_BACKSPACE          259
#define TACO_KEY_INSERT             260
#define TACO_KEY_DELETE             261
#define TACO_KEY_RIGHT              262
#define TACO_KEY_LEFT               263
#define TACO_KEY_DOWN               264
#define TACO_KEY_UP                 265
#define TACO_KEY_PAGE_UP            266
#define TACO_KEY_PAGE_DOWN          267
#define TACO_KEY_HOME               268
#define TACO_KEY_END                269
#define TACO_KEY_CAPS_LOCK          280
#define TACO_KEY_SCROLL_LOCK        281
#define TACO_KEY_NUM_LOCK           282
#define TACO_KEY_PRINT_SCREEN       283
#define TACO_KEY_PAUSE              284
#define TACO_KEY_F1                 290
#define TACO_KEY_F2                 291
#define TACO_KEY_F3                 292
#define TACO_KEY_F4                 293
#define TACO_KEY_F5                 294
#define TACO_KEY_F6                 295
#define TACO_KEY_F7                 296
#define TACO_KEY_F8                 297
#define TACO_KEY_F9                 298
#define TACO_KEY_F10                299
#define TACO_KEY_F11                300
#define TACO_KEY_F12                301
#define TACO_KEY_F13                302
#define TACO_KEY_F14                303
#define TACO_KEY_F15                304
#define TACO_KEY_F16                305
#define TACO_KEY_F17                306
#define TACO_KEY_F18                307
#define TACO_KEY_F19                308
#define TACO_KEY_F20                309
#define TACO_KEY_F21                310
#define TACO_KEY_F22                311
#define TACO_KEY_F23                312
#define TACO_KEY_F24                313
#define TACO_KEY_F25                314
#define TACO_KEY_KP_0               320
#define TACO_KEY_KP_1               321
#define TACO_KEY_KP_2               322
#define TACO_KEY_KP_3               323
#define TACO_KEY_KP_4               324
#define TACO_KEY_KP_5               325
#define TACO_KEY_KP_6               326
#define TACO_KEY_KP_7               327
#define TACO_KEY_KP_8               328
#define TACO_KEY_KP_9               329
#define TACO_KEY_KP_DECIMAL         330
#define TACO_KEY_KP_DIVIDE          331
#define TACO_KEY_KP_MULTIPLY        332
#define TACO_KEY_KP_SUBTRACT        333
#define TACO_KEY_KP_ADD             334
#define TACO_KEY_KP_ENTER           335
#define TACO_KEY_KP_EQUAL           336
#define TACO_KEY_LEFT_SHIFT         340
#define TACO_KEY_LEFT_CONTROL       341
#define TACO_KEY_LEFT_ALT           342
#define TACO_KEY_LEFT_SUPER         343
#define TACO_KEY_RIGHT_SHIFT        344
#define TACO_KEY_RIGHT_CONTROL      345
#define TACO_KEY_RIGHT_ALT          346
#define TACO_KEY_RIGHT_SUPER        347
#define TACO_KEY_MENU               348

#define TACO_KEY_LAST               TACO_KEY_MENU

#define TACO_MOUSE_BUTTON_1         0
#define TACO_MOUSE_BUTTON_2         1
#define TACO_MOUSE_BUTTON_3         2
#define TACO_MOUSE_BUTTON_4         3
#define TACO_MOUSE_BUTTON_5         4
#define TACO_MOUSE_BUTTON_6         5
#define TACO_MOUSE_BUTTON_7         6
#define TACO_MOUSE_BUTTON_8         7
#define TACO_MOUSE_BUTTON_LAST      TACO_MOUSE_BUTTON_8
#define TACO_MOUSE_BUTTON_LEFT      TACO_MOUSE_BUTTON_1
#define TACO_MOUSE_BUTTON_RIGHT     TACO_MOUSE_BUTTON_2
#define TACO_MOUSE_BUTTON_MIDDLE    TACO_MOUSE_BUTTON_3

#define TACO_JOYSTICK_1             0
#define TACO_JOYSTICK_2             1
#define TACO_JOYSTICK_3             2
#define TACO_JOYSTICK_4             3
#define TACO_JOYSTICK_5             4
#define TACO_JOYSTICK_6             5
#define TACO_JOYSTICK_7             6
#define TACO_JOYSTICK_8             7
#define TACO_JOYSTICK_9             8
#define TACO_JOYSTICK_10            9
#define TACO_JOYSTICK_11            10
#define TACO_JOYSTICK_12            11
#define TACO_JOYSTICK_13            12
#define TACO_JOYSTICK_14            13
#define TACO_JOYSTICK_15            14
#define TACO_JOYSTICK_16            15
#define TACO_JOYSTICK_LAST          TACO_JOYSTICK_16

#define TACO_GAMEPAD_BUTTON_A               0
#define TACO_GAMEPAD_BUTTON_B               1
#define TACO_GAMEPAD_BUTTON_X               2
#define TACO_GAMEPAD_BUTTON_Y               3
#define TACO_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define TACO_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define TACO_GAMEPAD_BUTTON_BACK            6
#define TACO_GAMEPAD_BUTTON_START           7
#define TACO_GAMEPAD_BUTTON_GUIDE           8
#define TACO_GAMEPAD_BUTTON_LEFT_THUMB      9
#define TACO_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define TACO_GAMEPAD_BUTTON_DPAD_UP         11
#define TACO_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define TACO_GAMEPAD_BUTTON_DPAD_DOWN       13
#define TACO_GAMEPAD_BUTTON_DPAD_LEFT       14
#define TACO_GAMEPAD_BUTTON_LAST            TACO_GAMEPAD_BUTTON_DPAD_LEFT

#define TACO_GAMEPAD_BUTTON_CROSS       TACO_GAMEPAD_BUTTON_A
#define TACO_GAMEPAD_BUTTON_CIRCLE      TACO_GAMEPAD_BUTTON_B
#define TACO_GAMEPAD_BUTTON_SQUARE      TACO_GAMEPAD_BUTTON_X
#define TACO_GAMEPAD_BUTTON_TRIANGLE    TACO_GAMEPAD_BUTTON_Y

#define TACO_GAMEPAD_AXIS_LEFT_X        0
#define TACO_GAMEPAD_AXIS_LEFT_Y        1
#define TACO_GAMEPAD_AXIS_RIGHT_X       2
#define TACO_GAMEPAD_AXIS_RIGHT_Y       3
#define TACO_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define TACO_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define TACO_GAMEPAD_AXIS_LAST          TACO_GAMEPAD_AXIS_RIGHT_TRIGGER

#define TACO_MOD_SHIFT           0x0001

#define TACO_MOD_CONTROL         0x0002
  
#define TACO_MOD_ALT             0x0004

#define TACO_MOD_SUPER           0x0008

#define TACO_MOD_CAPS_LOCK       0x0010

#define TACO_MOD_NUM_LOCK        0x0020

namespace pgName {
	
	// ===============================================================================
	//	fixed-size primitive types
	// ===============================================================================
	// typedef uint8_t uint8;
	// typedef uint16_t uint16;
	// typedef uint32_t uint32;
	// typedef uint64_t uint64;

	// typedef int8_t int8;
	// typedef int16_t int16;
	// typedef int32_t int32;
	// typedef int64_t int64;

	typedef std::array<float, 2> vec2f;
	typedef std::array<float, 3> vec3f;
	typedef std::array<float, 4> vec4f;
	
	// struct variables
	struct mat2f {
		vec2f row1;
		vec2f row2;
		
		const float* data() {
			float* data = new float[sizeof(mat2f) / sizeof(float)];
			int n = sizeof(mat2f) / sizeof(vec2f);
			
			for (int i = 0; i < n; i++) {
				*(data + i) = row1.at(i);
				*(data + n + i) = row2.at(i);
			}
			
			return data;
		}
	};
	
	struct mat3f {
		vec3f row1;
		vec3f row2;
		vec3f row3;
		
		const float* data() {
			float* data = new float[sizeof(mat3f) / sizeof(float)];
			int n = sizeof(mat3f) / sizeof(vec3f);
			
			for (int i = 0; i < n; i++) {
				*(data + i) = row1.at(i);
				*(data + n + i) = row2.at(i);
				*(data + 2 * n + i) = row3.at(i);
			}
			
			return data;
		}
	};
	
	struct mat4f {
		vec4f row1;
		vec4f row2;
		vec4f row3;
		vec4f row4;
		
		const float* data() {
			float* data = new float[sizeof(mat4f) / sizeof(float)];
			int n = sizeof(mat4f) / sizeof(vec4f);
			
			for (int i = 0; i < n; i++) {
				*(data + i) = row1.at(i);
				*(data + n + i) = row2.at(i);
				*(data + 2 * n + i) = row3.at(i);
				*(data + 3 * n + i) = row4.at(i);
			}
			
			return data;
		}
	};
	
} // pgName


#endif // PGAPPORSTLNAME_CORE_H