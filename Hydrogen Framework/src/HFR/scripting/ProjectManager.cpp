#include "hfpch.h"
#include "ProjectManager.h"
#include "HFR/scripting/VisualStudio.h"

namespace HFR {

	void ProjectManager::createEngineProject(const std::string& projectName, const std::string& scriptName) {
		std::string solutionFile = Util::readAsString(HFR_RES + "templates/MSVC/MSVCSolution.sln", HFR_NORMAL_READ);
		std::string projectFile = Util::readAsString(HFR_RES + "templates/MSVC/MSVCProject.vcxproj", HFR_NORMAL_READ);

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
		{2} = HFR_Path
		{3} = HFR_Dependencies
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		{3} = %(AdditionalDependencies)
		*/

		CHAR documentRawPath[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, documentRawPath);
		
		std::string documentpath = Util::getDirectory(HFR_FOLDER_DOCUMENTS);
		std::string dependencies = documentpath + R"(\Hydrogen Game Engine\Dependencies)";

		std::string projectGUID = HGUID::generateGUID();
		std::string solutionGUID = HGUID::generateGUID();

		Util::toUpper(projectGUID);
		Util::toUpper(solutionGUID);

		char* solutionFileData = new char[solutionFile.length() * 2];
		char* projectFileData = new char[projectFile.length() * 2];

		//solution
		sprintf_s(solutionFileData, solutionFile.length() * 2, solutionFile.c_str(), scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), projectGUID.c_str(), solutionGUID.c_str());

		std::string HFR_Path = HFR_SOLUTION_DIRECTORY;

		//project																												//i have to do this because its %(AdditionalDependencies) and that gets turned into (AdditionalDependencies), which breaks everything
		sprintf_s(projectFileData, projectFile.length() * 2, projectFile.c_str(), projectName.c_str(), projectGUID.c_str(), HFR_Path.c_str(), dependencies.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str(), "%", scriptName.c_str(), scriptName.c_str(), scriptName.c_str());

		std::string solutionOutputData = solutionFileData;
		std::string projectOutputData = projectFileData;

		Debug::setSystemLogMode(HFR_DONT_LOG_ON_SUCCESS, HFR_LOG_ON_FAIL);
		Util::writeAsString(solutionOutputData, documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + projectName + ".sln", HFR_NORMAL_WRITE);
		Util::writeAsString(projectOutputData, documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj", HFR_NORMAL_WRITE);
		//show all files on startup (so you dont have to)
		Util::writeAsString(Util::readAsString(HFR_RES + "templates/MSVC/MSVCProject.vcxproj.user", HFR_NORMAL_READ), documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj.user", HFR_NORMAL_WRITE);
		Debug::setSystemLogMode(HFR_LOG_ON_SUCCESS, HFR_LOG_ON_FAIL);

		//add a base script
		VisualStudio::addScriptToProject(documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + scriptName + R"(\)" + scriptName + ".vcxproj", projectName, scriptName);
		
		//open up visual studio
		VisualStudio::openVisualStudio(documentpath + R"(\Hydrogen Game Engine\)" + projectName + R"(\Scripts\)" + projectName + ".sln");

		delete[] solutionFileData;
		delete[] projectFileData;
	}

}