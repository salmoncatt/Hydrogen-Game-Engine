#include "hpch.h"
#include "ProjectManager.h"

namespace HGE {

	void ProjectManager::createMSVCSolution(const std::string& solutionName, const std::string& projectName, const std::string& path) {
		std::string solutionFile = Util::readAsString(HGE_RES + "templates/MSVC/MSVCSolution.sln", HGE_NORMAL_READ);
		std::string projectFile = Util::readAsString(HGE_RES + "templates/MSVC/MSVCProject.vcxproj", HGE_NORMAL_READ);

		/*
		solution:
		{0} = project / script name
		{1} = project / script name
		{2} = project / script name
		{3} = project guid
		{4} = solution guid

		project:
		{0} = script name
		{1} = project guid
		{2} = HGE_Path
		{3} = HGE_Dependencies
		
		*/

		std::string projectGUID = HGUID::generateGUID();
		std::string solutionGUID = HGUID::generateGUID();

		Util::toUpper(projectGUID);
		Util::toUpper(solutionGUID);

		char* solutionFileData = new char[solutionFile.length() * 2];

		sprintf(solutionFileData, solutionFile.c_str(), projectName.c_str(), projectName.c_str(), projectName.c_str(), projectGUID.c_str(), solutionGUID.c_str());

		std::string test = solutionFileData;

		Debug::log(test);


		delete[] solutionFileData;
	}

}