#include"Injector.h"
#include"Memory.h"
#include<iostream>

#define LOABLIDRARYW "LoadLibraryW"
#define KERNEL32 "Kernel32.dll"

void Injector::Inject(const wchar_t* dllPath) const {
	WCHAR szFullPath[261];
	UINT nSize = sizeof(szFullPath);

	ZeroMemory(szFullPath, nSize);
	GetFullPathNameW(dllPath, 260, szFullPath, nullptr);
	HMODULE hModule = GetModuleHandleA(KERNEL32);
	LPVOID addr = GetProcAddress(hModule, LOABLIDRARYW);

	LPVOID lpParam = VirtualAllocEx(m_hProcess, nullptr, nSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (lpParam == nullptr) {
		throw std::runtime_error("Error: Please Try Again....");
	}
	std::cout << "\n[+] found Process " << nSize << " bytes in memory\n";
	if (!writeBuf(reinterpret_cast<uintptr_t>(lpParam), szFullPath, nSize)) {
		VirtualFreeEx(m_hProcess, addr, 0, MEM_RELEASE);
		throw std::runtime_error("Error: could not write dll path to process");
	}
	std::cout << "[+} Wrote Dll Path to: " << std::hex << reinterpret_cast<uintptr_t>(addr) << std::endl;
	HANDLE hThread = CreateRemoteThread(m_hProcess, nullptr, 0, static_cast<LPTHREAD_START_ROUTINE>(addr), lpParam, 0, nullptr);
	if (hThread == nullptr) {
		VirtualFreeEx(m_hProcess, addr, 0, MEM_RELEASE);
		throw std::runtime_error("Error: Could not create thread");
	}
	std::cout << "[+] Executing Dll In Target " << std::endl;
	WaitForSingleObject(hThread, INFINITE);

	VirtualFreeEx(m_hProcess, addr, 0, MEM_RELEASE);
	CloseHandle(hThread);
}

