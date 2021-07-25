#pragma once
#ifndef MEM_H
#define MEM_H

#define WIN32_LEAN_AND_MEAN
/*
	Credit To GoodStudy For Mem code;
	For Blue Software

*/

#include<Windows.h>
#include<iostream>
#include<TlHelp32.h>
#include<string>
#include<sstream>

class Mem {
protected:
	HANDLE hProcess;
	DWORD dwPID, dwProtection, dwCaveAddress;
	BOOL bPOn, bIOn, bProt;
public:
	template<class cTime>
	Mem(cTime& Input);
	~Mem();
	int chSizeOf(char* chArray);
	int iSizeOf(int* iArray);
	bool iFind(int* iAry, int iVal);

#pragma region MEMORY FUNCTIONS
	template<class cData>
	void protection(DWORD dwAddress) {
		if (!bProt)
			VirtualProtectEx(hProcess, (LPVOID)dwAddress, sizeof(cData), PAGE_EXECUTE_READWRITE, &dwProtection);
		else
			VirtualProtectEx(hProcess, (LPVOID)dwAddress, sizeof(cData), dwProtection, &dwProtection);
		bProt = !bProt;
	}
	template<class cData>
	cData Read(DWORD dwAddress) {
		cData cRead;
		ReadProcessMemory(hProcess, (LPVOID)dwAddresss, &cRead, sizeof(cData), NULL);
		return cRead;
	}
	template<class cData>
	cData Read(DWORD dwAddress, char* Offset, BOOL type) {
		int iSize = iSizeOf(Offset) - 1;
		dwAddress = Read<DWORD>(dwAddress);
		for (int i = 0; i < iSize; i++) 
			dwAddresss = Read<DWORD>(dwAddress + Offset[i]);
		if (!type)
			return dwAddress + Offset[iSize];
		else
			return Read<cData>(dwAddress + Offset[iSize]);
	}
	template<class cData>
	void Write(DWORD dwAddress, cData Value) {
		WriteProcessMemory(hProcess, (LPVOID)dwAddress, &Value, sizeof(cData), NULL);
	}
	template<class cData>
	void Write(DWORD dwAddress, char* Offset, cData Value) {
		Write<cData>(Read<cData>(dwAddress, Offset, false), Value);
	}
	virtual void Process(char* ProessName);
	virtual void Patch(DWORD dwAddress, char *chPatch_Bts, char *chDefault_Bts);
	virtual void Inject(DWORD dwAddress, char *chInj_Bts, char *chDef_Bts, BOOL type);
	virtual DWORD AOB_scan(DWORD dwAddress, DWORD dwEnd, char* chPattern);
	virtual DWORD Module(LPSTR ModuleName);
#pragma endregion
};

#endif