/*
	im not in  dream i own this <3
	i put hours into this and i it will become my job <3
	i dont care how much u try to stop me why you trying to stop me ? oh i just remembered
*/

#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<cmath>
#include<stdlib.h>
#include"Glow.h"
#include"Aimbot.h"


#define AppTitle BlueSoftware
#define boxSize 14 - 12
#define BoxHeight 12
#define BoxWidth 13

namespace mainFunctions {
	namespace features {
		void Init();
		void Setup();
		void Draw();
		void Login();
	}
	namespace GetFunctions {
		void Display();
	}
	namespace Loader {
		void Injector();
		void GetGameStrings();
	}
}

namespace calculator {
	namespace features {
		void Draw();
		void MathFunctions();
		void DrawStrings();
	}
}

void mainFunctions::features::Draw() {
	system("Color 09");
	std::cout << R"(
__________.__                    _________       _____  __                                 
\______   \  |  __ __   ____    /   _____/ _____/ ____\/  |___  _  _______ _______   ____  
 |    |  _/  | |  |  \_/ __ \   \_____  \ /  _ \   __\\   __\ \/ \/ /\__  \\_  __ \_/ __ \ 
 |    |   \  |_|  |  /\  ___/   /        (  <_> )  |   |  |  \     /  / __ \|  | \/\  ___/ 
 |______  /____/____/  \___  > /_______  /\____/|__|   |__|   \/\_/  (____  /__|    \___  >
        \/                 \/          \/                                 \/            \/ 	
)" << '\n';
	std::string about = "[+] Welcome To Blue Software Developed By Blue + Josh + Raily";
	if (about != "") {
		std::cout << about << std::endl;
	}
	else {
		fprintf(stderr, "[-] please reload the program...");
		Sleep(3);
		exit(EXIT_FAILURE);
	}
}

void calculator::features::Draw()
{
	int i = 13;
	int y = 12;
	for (int i = 0; i < i + 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i == 0)
				std::cout << "#";
			if (i == 1)
				std::cout << std::endl;
		}
		std::cout << std::endl;
		i++;
	}
	for (int k = 0; k < y + 1; k++) {
		if (y == 0)
			std::cout << "#";
		if (y == 1)
			std::cout << std::endl;
	}
}

void calculator::features::MathFunctions()
{
	float num1;
	float num2;
	float result;
	char op;
	printf("[+] Enter Number: ");
	std::cin >> num1;
	if (!num1)
		fprintf(stderr, "[-] please enter a number\n");
	printf("[+] Enter Opertor: ");
	std::cin >> op;
	if (!op)
		fprintf(stderr, "[-] please enter a opertor\n");
	printf("[+] Enter Another Number: ");
	std::cin >> num2;
	if (!num2)
		fprintf(stderr, "[-] please enter a number\n");
	switch (op) {
	case '+':
		result = num1 + num2;
		std::cout << "[++] Result is: " << result << std::endl;
		break;
	case '-':
		result = num1 - num2;
		std::cout << "[++] Result is: " << result << std::endl;
		break;
	case '*':
		result = num1 * num2;
		std::cout << "[++] Result is: " << result << std::endl;
		break;
	case '/':
		result = num1 / num2;
		std::cout << "[++] Result is: " << result << std::endl;
		break;
	default:
		fprintf(stderr, "[-] please enter a opertor\n");
		exit(EXIT_FAILURE);
	}
	printf("[+] Do you wish to use calculator again ? ");
	char use_again;
	std::cin >> use_again;
	if (use_again == 'Y') {
	jumpto:
		mainFunctions::GetFunctions::Display();
	}
	else {
		fprintf(stderr, "[-] Exiting now please wait....\n");
		exit(EXIT_FAILURE);
	}
}

void calculator::features::DrawStrings()
{
	calculator::features::Draw();
	calculator::features::MathFunctions();
	bool isCalculatorOpen = false;
}

namespace downloader {
	namespace down {
		void Downloader();
	}
	namespace LinkChecker {
		void Chcker();
	}
}

namespace Text {
	namespace toDraw{
		void DrawText();
	}
}

#include<cstdio>
#include<urlmon.h>
// code from a user credits to him
#define getURL URLOpenBlockingStreamA
void downloader::down::Downloader() {
	
}
void downloader::LinkChecker::Chcker()
{

}

#include"Injector.h"
#include<strsafe.h>

struct InjectInfo {
	LPCWSTR szProcessName;
	LPCWSTR szDllPath;
};

static bool Inject(const InjectInfo& info) {
	try {
		Injector injector;
		injector.attach(info.szProcessName);
		injector.Inject(info.szDllPath);
	}
	catch (const std::runtime_error& e) {
		MessageBoxA(nullptr, e.what(), nullptr, MB_ICONERROR);
		return false;
	}
	return true;
}

int wmain(int argc, wchar_t* argv[]) {
	if (argc == 1 || argc > 3) {
		std::wcerr << "Usage: " << argv[0] << " [DLL Path] [Process]" << '\n'
			<< "       " << argv[0] << " [DLL Path]" << '\n';

		return 1;
	}
	wchar_t szProcessName[MAX_PATH];

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(nullptr, "Error: could not get console handle!", nullptr, MB_ICONERROR);
		return 1;
	}

	SetConsoleTitleA("Injector by: incognito04");


	if (argc == 3)
		StringCbCopyW(szProcessName, MAX_PATH, argv[2]);
	else
	{
		std::cout << "Process> ";
		std::wcin.getline(szProcessName, MAX_PATH);
	}

	const bool bStatus = Inject({ szProcessName, argv[1] });
	std::cout << "\n[*] DLL injection " << (bStatus ? "completed sucessfully" : "failed") << '\n';

	return 0;
}


void mainFunctions::GetFunctions::Display() {
	std::string OptionsStrings = "[+] Enter C For Calculator, [+] Enter L For Link Checker, [+] Enter D For Downloader: ";
	char options_t;
	std::cout << OptionsStrings;
	std::cin >> options_t;
	switch (options_t) {
	case 'C':
		calculator::features::MathFunctions();
		break;
	case 'L':
		downloader::LinkChecker::Chcker();
		break;
	case 'D':
		downloader::down::Downloader();
		break;
	default:
		fprintf(stderr, "[-] Please enter a option");
		exit(EXIT_FAILURE);
	}

}

void Text::toDraw::DrawText() {
	mainFunctions::GetFunctions::Display();
}


void mainFunctions::features::Login() {
	char toLogin;
	printf("[+] Enter Y to being the login process: ");
	std::cin >> toLogin;
	switch (toLogin) {
	case 'Y':
		int key;
		printf("[+] Enter Key: ");
		std::cin >> key;
		if (key == 0) {
			fprintf(stderr, "[-] please enter a key\n");
			exit(EXIT_FAILURE);
		}
		if (key != 0) {
			std::string user;
			printf("[+] Enter Login Username: ");
			std::cin >> user;
			if (user == "") {
				fprintf(stderr, "please enter a username\n");
				exit(EXIT_FAILURE);
			}
			std::cout << "[+] Enter Password: ";
			char s[10] = { 0 };
			int i;
			for (i = 0; i < 10; i++) {
				s[i] = _getch();
				if (s[i] == 13) {
					break;
				}
				else {
					_putch('*');
				}
			};
			getchar();
			if (user != "") {
				printf("\n");
				std::cout << "[+] Welcome: " << " [ " << user << " ] " << std::endl;
			}
		}
		break;
	case 'n':
		printf("[-] Enter y to being the login process\n");
		Sleep(3);
		exit(EXIT_FAILURE);
		break;
	default:
		fprintf(stderr, "[-] please enter a letter\n");
		exit(EXIT_FAILURE);
	}
}

void mainFunctions::Loader::Injector() {

}

void mainFunctions::Loader::GetGameStrings() {
	const char* strings;
	std::string totalStrings;
	int process;
	int total;
	total = sizeof(strings);
	DWORD memory;
#define MemoryAddress 0x100
#define Address 0xA1
	bool isInjector = false;
	do {
		DWORD gameAddress = sizeof(process);
		if (gameAddress) {
			DWORD getGameAddress = sizeof(memory);
			std::cout << "[+] Loading Memory Into Games Process Memory" << std::endl;
		}
		else {
			fprintf(stderr, "[-] is game open to inject\n");
			exit(EXIT_FAILURE);
		}
	} while (isInjector == true);
}

void mainFunctions::features::Setup() {
	bool isStartUP = true;
	DWORD hModule;
	if (isStartUP == false) {
		fprintf(stderr, "please reload the program\n");
		exit(EXIT_FAILURE);
	}
	else {
		int process;
		bool settingUp = true;
		bool InitProgram = true;
		int set = 1;
		if (set == 1) {
			settingUp++;
			std::string Message = "[+] Setting Up Program Now....";
			if (Message != "") {
				std::cout << Message << std::endl;
				Sleep(2000);
				if (Sleep) {
					system("cls");
					mainFunctions::features::Draw();
					mainFunctions::features::Login();
					Text::toDraw::DrawText();
				}
				else {
					fprintf(stderr, "[-] Dont Tell me i cant do it because i wont listen to you\n");
					exit(EXIT_FAILURE);
				}
			}
			else {
				fprintf(stderr, "[-] Please reopen the program\n");
				exit(EXIT_FAILURE);
			}
			settingUp++;
		}
		else {
			fprintf(stderr, "please reload the program\n");
			exit(EXIT_FAILURE);
		}
		DWORD dwAddress = sizeof(process);
		do {
			int FindNewProcess;
			if (FindNewProcess = sizeof(process), 1) {
				DWORD moduleAddress = sizeof(hModule);
			}
			else {
				DWORD getNewModule = sizeof(hModule);
				fprintf(stderr, "[-] Getting new Modules....");
				Sleep(2);
				if (getNewModule) {
					printf("[+] New Module added\n");
					Sleep(4);
				}
				else {
					fprintf(stderr, "[-] Please reload the program\n");
					exit(EXIT_FAILURE);
				}
			}
		} while (isStartUP == true);
	}
}

void mainFunctions::features::Init()
{

}

int main()
{
	mainFunctions::features::Setup();
}