#include "hpch.h"
#include "Debug.h"
#include "HGE/math/vectors/Vec2.h"
#include "HGE/math/vectors/Vec3.h"
#include "HGE/math/vectors/Vec4.h"
#include "HGE/graphics/image/Pixel.h"
#include "HGE/ECS/components/Transform.h"

namespace HGE {

	std::array<Profile, HGE_MAX_PROFILES> Debug::profiles{};
	unsigned long Debug::profilerIndex = 0;
	std::unordered_map<std::string, unsigned long> Debug::profilerNames{};

	void Debug::log(const std::string& message) {
		std::string out = message + "\n";
		std::cout << out;
	}

	void Debug::log(const char& in) {
		std::cout << in << std::endl;
	}

	void Debug::log(const double& in) {
		std::cout << std::fixed;
		std::cout << in << std::endl;
	}

	void Debug::log(const int& in) {
		std::cout << std::fixed;
		std::cout << in << std::endl;
	}

	void Debug::logScientific(const double& in) {
		std::cout << std::scientific;
		std::cout << in << std::endl;
	}

	void Debug::logScientific(const int& in) {
		std::cout << std::scientific;
		std::cout << in << std::endl;
	}

	void Debug::log(const std::vector<float>& array) {
		for (int i = 0; i < array.size(); i++) {
			Debug::log(array[i]);
		}
	}

	void Debug::log(const Vec3f& in) {
		std::string x = std::to_string(in.x);
		std::string y = std::to_string(in.y);
		std::string z = std::to_string(in.z);

		std::cout << "Vec3f: [" + x + "][" + y + "][" + z + "]\n";
	}

	void Debug::log(const Vec2i& in) {
		std::string x = std::to_string(in.x);
		std::string y = std::to_string(in.y);

		std::cout << "Vec2i: [" + x + "][" + y + "]\n";
	}

	void Debug::log(const Vec2f& in) {
		std::string x = std::to_string(in.x);
		std::string y = std::to_string(in.y);

		std::cout << "Vec2f: [" + x + "][" + y + "]\n";
	}

	void Debug::log(const Pixel& in) {
		std::string r = std::to_string(in.r);
		std::string g = std::to_string(in.g);
		std::string b = std::to_string(in.b);
		std::string a = std::to_string(in.a);

		std::cout << "Pixel: [" + r + "][" + g + "][" + b + "][" + a + "]\n";
	}

	void Debug::log(const std::vector<Pixel>& array) {
		for (int i = 0; i < array.size(); i++) {
			Debug::log(array[i]);
		}
	}

	void Debug::log(const std::vector<std::vector<Pixel>>& array) {
		for (int i = 0; i < array.size(); i++) {
			for (int j = 0; j < array[i].size(); j++) {
				Debug::log(array[i][j]);
			}
		}
	}

	void Debug::log(const std::vector<unsigned char>& array) {
		for (int i = 0; i < array.size(); i++) {
			Debug::log((unsigned char)array[i] & 0xFF);
		}
	}

	void Debug::log(const Transform& in) {
		log("Transform: ");
		
		std::cout <<"   position: ";
		log(in.position);

		std::cout <<"   rotation: ";
		log(in.rotation);
		
		std::cout <<"   scale: ";
		log(in.scale);
	}

	void Debug::systemLog(const std::string& SystemMessage) {
		Debug::setTextColor(DebugColor::Yellow);
		std::string out = "System Message: " + SystemMessage + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}

	void Debug::systemLog(const std::string& SystemMessage, const DebugColor& color) {
		Debug::setTextColor(color);
		std::string out = "System Message: " + SystemMessage + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}

	void Debug::systemErr(const std::string& SystemError) {
		Debug::setTextColor(DebugColor::Red);
		std::string out = "System Error: " + SystemError + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}
	
	void Debug::systemErr(const std::string& SystemError, const DebugColor& color) {
		Debug::setTextColor(color);
		std::string out = "System Error: " + SystemError + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}

	void Debug::systemSuccess(const std::string& SystemMessage) {
		Debug::setTextColor(DebugColor::LightGreen);
		std::string out = "System Success: " + SystemMessage + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}
	
	void Debug::systemSuccess(const std::string& SystemMessage, const DebugColor& color) {
		Debug::setTextColor(color);
		std::string out = "System Success: " + SystemMessage + "\n";
		std::cout << out;
		Debug::resetTextColor();
	}

	void Debug::newLine() {
		std::cout << "\n";
	}

	void Debug::waterMark() {
		Debug::setTextColor(DebugColor::Aqua);
		std::cout << "Hydrogen Game Engine v0.7 alpha: created by Salmoncatt\n";
		Debug::resetTextColor();
	}

	void Debug::closingWaterMark() {
		Debug::setTextColor(DebugColor::Aqua);
		std::cout << "Engine is Closing, thanks for coming\n";
		Debug::resetTextColor();
	}

	void Debug::setTextColor(const DebugColor& color) {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, (WORD)color);
	}

	void Debug::resetTextColor() {
		Debug::setTextColor(DebugColor::White);
	}

	void Debug::storeProfile(const Profile& profile) {
		if (profilerNames.find(profile.name) == profilerNames.end()) {
			profilerNames[profile.name] = profilerIndex;

			profiles[profilerIndex] = profile;
			profilerIndex += 1;
		}
		else {
			profiles[profilerNames[profile.name]] += profile;
		}
	}
	
	Profile Debug::getProfile(const std::string& name) {
		if (profilerNames.find(name) != profilerNames.end())
			return profiles[profilerNames[name]];
		else
			return Profile();
	}

}
