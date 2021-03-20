#include "hpch.h"
#include "ProjectManager.h"
#include "HGE/scripting/VisualStudio.h"

namespace HGE {

	std::string HGE_PROJECTS_PATH = Util::getDirectory(HGE_FOLDER_DOCUMENTS) + R"(\Hydrogen Game Engine\)";

	void ProjectManager::createEngineProject(const std::string& projectName, const std::string& scriptName) {
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
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		*/

		CHAR documentRawPath[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, documentRawPath);
		
		std::string documentpath = Util::getDirectory(HGE_FOLDER_DOCUMENTS);
		std::string dependencies = documentpath + R"(\Hydrogen Game Engine\Dependencies)";

		std::string projectGUID = HGUID::generateGUID();
		std::string solutionGUID = HGUID::generateGUID();

		Util::toUpper(projectGUID);
		Util::toUpper(solutionGUID);

		char* solutionFileData = new char[solutionFile.length() * 2];
		char* projectFileData = new char[projectFile.length() * 2];

		//solution
		sprintf_s(solutionFileData, solutionFile.length() * 2, solutionFile.c_str(), scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), solutionGUID.c_str());

		std::string HGE_Path = HGE_SOLUTION_DIRECTORY;

		//project																												//i have to do this because its %(AdditionalDependencies) and that gets turned into (AdditionalDependencies), which breaks everything
		sprintf_s(projectFileData, projectFile.length() * 2, projectFile.c_str(), projectName.c_str(), projectGUID.c_str(), HGE_Path.c_str(), dependencies.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str());

		std::string solutionOutputData = solutionFileData;
		std::string projectOutputData = projectFileData;

		Debug::setSystemLogMode(HGE_DONT_LOG_ON_SUCCESS, HGE_LOG_ON_FAIL);
		Util::writeAsString(solutionOutputData, documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + projectName + ".sln", HGE_NORMAL_WRITE);
		Util::writeAsString(projectOutputData, documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj", HGE_NORMAL_WRITE);
		//show all files on startup (so you dont have to)
		Util::writeAsString(Util::readAsString(HGE_RES + "templates/MSVC/MSVCProject.vcxproj.user", HGE_NORMAL_READ), documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj.user", HGE_NORMAL_WRITE);
		Debug::setSystemLogMode(HGE_LOG_ON_SUCCESS, HGE_LOG_ON_FAIL);

		//add a base script
		VisualStudio::addScriptToProject(documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj", "scriptNamespace_Change_to_whatever_you_want", scriptName);
		
		//open up visual studio
		VisualStudio::openVisualStudio(documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + projectName + ".sln");

		delete[] solutionFileData;
		delete[] projectFileData;
	}

}