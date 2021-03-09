
#ifndef HGE_DEBUG_HEADER_INCLUDE
#define HGE_DEBUG_HEADER_INCLUDE

#include HGE_API

#define HGE_MAX_PROFILES 5000
#include HGE_PROFILE

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
		static std::array<Profile, HGE_MAX_PROFILES> lastFrameProfiles;
		static unsigned long profiledAmount;
		static std::unordered_map<std::string, unsigned long> profilerNames;
		static int succeedLogMode;
		static int failLogMode;

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
		static void newLine(const int& lines);
		static void waterMark();
		static void closingWaterMark();
		static void setTextColor(const HGE::DebugColor& color);
		static void resetTextColor();
		
		static void storeProfile(const Profile& profile);
		static Profile getProfile(const std::string& name);
		static void resetProfiles();
		static void logProfile(const Profile& profile);

		//returns that amount of different functions that were profiled ever
		static unsigned long getAmountOfProfiles();

		static void update();

		//if a function succeeds like writeAsString(); for instance and this is set to HGE_LOG_ON_SUCCESS, it will log that it succeeds. Possible values are HGE_LOG_ON_SUCCESS, HGE_DONT_LOG_ON_SUCCESS, HGE_DONT_LOG_ON_FAIL
		static void setSystemLogMode(const int& succeedMode, const int& failMode);
	};																																						

}

#endif