// externalLibs.h
// -> Inclusion of all external libraries for larger projects (Applications)
// Author: Justin Bunting
// Created: 2025/10/06
// Last Modified: 2025/10/10 22:06

#ifndef PGAPPORSTLNAME_EXTERNALLIBS_H
#define PGAPPORSTLNAME_EXTERNALLIBS_H


// ===================================================================================
//	GLM
// ===================================================================================
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/matrix.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtc/type_ptr.hpp>

// ===================================================================================
//	Std Libraries
// ===================================================================================
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <tuple>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <functional>
#include <typeinfo>
#include <filesystem>

// ===================================================================================
//	GLFW and GLAD
// ===================================================================================
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// ===================================================================================
//	CppUtils
// ===================================================================================
#include <CppUtils/CppUtils.h>
using namespace CppUtils;

// ===================================================================================
//	EnTT
// ===================================================================================
#include <entt/entt.hpp>

// add in definitions from Core.h for completeness
#include "core/Core.h"


#endif // PGAPPORSTLNAME_EXTERNALLIBS_H