// Settings.h
// -> A location for all modifyable internal and user settings.
// Author: Justin Bunting
// Created: 2025/10/11
// Last Modified: 2025/10/21 14:38

#ifndef PGAPPORSTLNAME_SETTINGS_H
#define PGAPPORSTLNAME_SETTINGS_H


#include "externalLibs.h"

namespace pgName {
	
	namespace Settings {
		// ===================================================================================
		// Internal settings (controlled by engine)
		// ===================================================================================
		
		static std::filesystem::path appAssetsFolder; // = "/Library/pgName" ? _EXPORT_ASSETS : "/pgName/assets/app"
		static std::filesystem::path appUserAssetsFolder; // = "~/Library/Containers/pgName" ? _EXPORT_ASSETS : "/pgName/assets/appUser"
		// static std::filesystem::path appUserPreferences; // = "~/Library/Preferences/pgName.plist" ? _EXPORT_ASSETS : "/pgName/assets/pgNameUserPreferences.plist"

		// ===================================================================================
		// User settings (modified by user and saved/loaded across launches)
		// ===================================================================================
		
	}

} // pgName


#endif // PGAPPORSTLNAME_SETTINGS_H