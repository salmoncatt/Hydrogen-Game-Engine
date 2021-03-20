#include "hfpch.h"

namespace HFR {

	std::string HGUID::generateGUID()
	{
		std::string out;

		UUID guid;
		HRESULT guidResult = CoCreateGuid(&guid);
		
		if (SUCCEEDED(guidResult)) {
			WCHAR* charGUID = NULL;

			RPC_STATUS convertResult = ::UuidToStringW(&guid, (RPC_WSTR*)&charGUID);

			if (charGUID != NULL && convertResult == RPC_S_OK) {
				std::wstring wstring(charGUID);

				for (wchar_t c : wstring) {
					out += (char)c;
				}
				
				//free memory
				::RpcStringFreeW((RPC_WSTR*)&charGUID);
				return out;
			}
			else
				Debug::systemErr("Couldn't generate guid, probably because not enough free memory");

		}

		return std::string();
	}

}