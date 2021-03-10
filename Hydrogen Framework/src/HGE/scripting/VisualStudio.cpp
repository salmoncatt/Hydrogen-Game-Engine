#include "hpch.h"
#include "VisualStudio.h"

namespace HGE {

	void VisualStudio::openVisualStudio(const string& solutionPath) {
		ShellExecute(NULL, "open", solutionPath.c_str(), NULL, NULL, SW_SHOW);
	}


}