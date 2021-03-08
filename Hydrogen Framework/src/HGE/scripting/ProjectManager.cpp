#include "hpch.h"
#include "ProjectManager.h"
//for getting documents folder
#include <shlobj.h>

#pragma comment(lib, "shell32.lib")

namespace HGE {

	void ProjectManager::createMSVCSolution(const std::string& solutionName, const std::string& projectName) {
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

		CHAR documentRawPath[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, documentRawPath);

		std::string dependencies;
		std::string documentpath;

		if (result == S_OK) {
			documentpath = documentRawPath;
			dependencies = documentpath;
			dependencies += R"(\Hydrogen Game Engine\Dependencies)";
		}
		else {
			Debug::systemErr("Couldn't find docuemnts folder for some reason");
			return;
		}

		std::string projectGUID = HGUID::generateGUID();
		std::string solutionGUID = HGUID::generateGUID();

		Util::toUpper(projectGUID);
		Util::toUpper(solutionGUID);

		char* solutionFileData = new char[solutionFile.length() * 2];
		char* projectFileData = new char[projectFile.length() * 2];

		//solution
		sprintf(solutionFileData, solutionFile.c_str(), projectName.c_str(), projectName.c_str(), projectName.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), solutionGUID.c_str());

		std::string HGE_Path = HGE_SOLUTION_DIRECTORY;
		HGE_Path += R"(Hydrogen FrameWork\src)";

		//project
		sprintf(projectFileData, projectFile.c_str(), projectName.c_str(), projectGUID.c_str(), HGE_Path.c_str(), dependencies.c_str());

		std::string solutionOutputData = solutionFileData;
		std::string projectOutputData = projectFileData;

		//Util::writeAsString(solutionOutputData, documentpath + R"(\)", HGE_NORMAL_WRITE);
		//Util::writeAsString(projectOutputData, R"(C:\Users\salmo\Desktop\test2.txt)", HGE_NORMAL_WRITE);


		delete[] solutionFileData;
		delete[] projectFileData;
	}

}