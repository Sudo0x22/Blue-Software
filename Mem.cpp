#include"Mem.h"

#pragma region Misc Functions

using namespace std;

template<class cTime>
Mem::Mem(cTime& Input) {
	char* chNewpattern;
	for (int iwidth = 1; iwidth < MAX_PATH; iwidth++)
		if (chNewpattern[iwidth] == '*')
			std::cout << std::endl;
	std::cout << "Failed to find width\n";
	DWORD Ptr;
	class cTime;
	enum player_offsets {
		localPlayer,
		EnemyPlayer,
	};

	if (player_offsets::EnemyPlayer) {
		int process;
		DWORD newDwAddress = sizeof(process);
		bool isPid = false;
		if (!isPid)
			return;
		if (isPid)
			return;
		BYTE LoadKernelName(DWORD dwAddress, const char* title_name, sizeof(cTime)dwAddress);
		DWORD GetKernelversion(DWORD Pointer int new_address, float version_kernel, const char* title_name, sizeof(cTime)dwAddress);
	}
	else {
		fprintf(stderr, "failed to find kernel type and version\n");
		exit(EXIT_FAILURE);
	}
	struct get_info {
		union {
			float kernel_ver;
			char* chName;
			int total_num;
			bool isKernel = true;
		};
		DWORD GetInfo(float kernel_ver, char* chName, int total_num, bool isKernel, sizeof(cTime)dwAddress);
	};
	
}

Mem::~Mem()
{

}

int Mem::chSizeOf(char* chArray) {
	for (int iLength = 1; iLength < MAX_PATH; iLength++) 
		if (chArray[iLength] == '*')
			return iLength;
	std::cout << "Failed to read length\n";
	return 0;
}

int Mem::iSizeOf(int* iArray) {
	for (int iLength = 1; iLength < MAX_PATH; iLength++)
		if (iArray[iLength] == '*')
			return iLength;
	std::cout << "Failed to find array\n";
	return 0;
}

bool Mem::iFind(int *iAry, int iVal) {
	for (int i = 0; i < 64; i++)
		if (iVal == iAry[i] && iVal != 0)
			return true;
	return false;
}

#pragma endregion

#pragma region Memory Functions

void Mem::Process(char* ProcessName)
{
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);
	do
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			dwPID = ProcEntry.th32ProcessID;
			CloseHandle(hPID);
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
			return;
		}
	while (Process32Next(hPID, &ProcEntry));

	cout << "\nCouldn't find game\n";
	system("pause");
	exit(0);
}