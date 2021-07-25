#pragma once

#include<Windows.h>
#include<ostream>

struct Module {
	uintptr_t baseAddress;
	DWORD dw_Size;
};

class Memory {
public:
	Memory() = default;
	~Memory() {
		if (m_hProcess != nullptr || m_hProcess != INVALID_HANDLE_VALUE) {
			CloseHandle(m_hProcess);
			m_hProcess = nullptr;
		}
	}
	void attach(const wchar_t* szProcessName, DWORD dwAccessRights = PROCESS_ALL_ACCESS);
	Module getModuleInfo(const wchar_t* zsModuleName);
	inline bool writeBuf(uintptr_t addr, LPCVOID Buffer, uint32_t nSize) const {
		return WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(addr), Buffer, nSize, nullptr);
	}
	template<typename T>
	inline bool write(uintptr_t addr, T Data, uint32_t nSize = sizeof(T)) const {
		return WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(addr), &Data, nSize, nullptr);
	}
	template<typename T>
	T Read(uintptr_t addr) const {
		T Data;
		ReadProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(addr), &Data, sizeof(Data), nullptr);
		return Data;
	}
protected:
	DWORD m_pId;
	HANDLE m_hProcess;
private:
	const wchar_t* m_szProcessName;
	friend std::wostream& operator<<(std::wostream&, const Memory&);

};