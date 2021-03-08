#include "hpch.h"
#include "GUID.h"

namespace HGE {

	std::string HGUID::generateGUID()
	{
		std::string out;

		UUID guid;
		RPC_STATUS guidResult = UuidCreate(&guid);
		
		if (guidResult == RPC_S_OK) {
			WCHAR* charGUID = NULL;

			RPC_STATUS convertResult = ::UuidToStringW(&guid, (RPC_WSTR*)&charGUID);

			if (charGUID != NULL && convertResult == RPC_S_OK) {
				std::wstring wstring(charGUID);

				for (wchar_t c : wstring) {
					out += (char)c;
				}

				return out;
			}
			else
				Debug::systemErr("Couldn't generate guid, probably because not enough free memory");

		}

		return std::string();
	}

}