
#ifndef HGE_DEBUG_HEADER_INCLUDE
#define HGE_DEBUG_HEADER_INCLUDE

#include HGE_API

#define HGE_MAX_PROFILES 100
#include "time/Profile.h"

namespace HGE {

	class Pixel;
	struct Vec3f;
	struct Vec2f;
	struct Vec2i;
	struct Transform;
	class Profiler;

	const enum class DLL_API DebugColor
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Aqua = 3,
		Red = 4,
		Purple = 5,
		Yellow = 6,
		White = 7,
		Gray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightAqua = 11,
		LightRed = 12,
		LightPurple = 13,
		LightYellow = 14,
		BrightWhite = 15
	};

	class DLL_API Debug {
	private:
		static std::array<Profile, HGE_MAX_PROFILES> profiles;
		static unsigned long profilerIndex;
		static std::unordered_map<std::string, unsigned long> profilerNames;

	public:
		static void log(const std::string& message);
		static void log(const char& in);
		static void log(const double& in);
		static void log(const int& in);
		static void log(const Vec3f& vector);
		static void log(const Vec2i& vector);
		static void log(const Vec2f& vector);
		static void log(const Pixel& pixel);
		static void log(const std::vector<Pixel>& in);
		static void log(const std::vector<std::vector<Pixel>>& in);
		static void log(const std::vector<float>& in);
		static void log(const std::vector<unsigned char>& in);
		static void log(const Transform& in);

		static void logScientific(const double& in);
		static void logScientific(const int& in);

		static void systemLog(const std::string& message);
		static void systemLog(const std::string& message, const DebugColor& color);
		static void systemErr(const std::string& message);
		static void systemErr(const std::string& message, const DebugColor& color);
		static void systemSuccess(const std::string& message);
		static void systemSuccess(const std::string& message, const DebugColor& color);

		static void newLine();
		static void waterMark();
		static void closingWaterMark();
		static void setTextColor(const HGE::DebugColor& color);
		static void resetTextColor();
		
		static void storeProfile(const Profile& profile);
		static Profile getProfile(const std::string& name);

	};

}

#endif