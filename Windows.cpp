#include<Windows.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>


#define get_tital blueSoftware
#define new_tital blueSoftware

class CMain {
	CMain(DWORD dwAddress, const char* chTitle, std::string tital_new);
	template<class cMain>
	inline void spec(float total_main)
	{
		int random_int;
		reinterpreter_cast<bool>(true, true);
		int total;
		if (total == 10 + random_int) {
			bool new_total_ready = true;
			for (int i = 0; i < total; i++) {
				std::cout << std::endl;
				total++;
			}
		}
		else {
			fprintf(stderr, "please reload the progam\n");
			exit(EXIT_FAILURE);
		}
		return total;
	}
	~CMain();
	template<typename T>
	void GetDisplay(T& Input) {
		reinterpreter_cast<int>(100, 2000);
	}
	void LoadDisplay()
	{
		bool isReady;
		float _get_fov = 14.0f;
		bool isAimbot = true;
		bool isGlowEnabled = true;
		bool menuOpen = false;
		return;
	}
};

namespace Menu {
	namespace Draw {
		void drawMenu();
		void MenuWindows();
		void MenuTitle(std::string cheat_title);
	}
	namespace features {
		void Aimbot();
		enum aimbot_features {
			aimbot_lock,
			aim_slient,
			aim_head_only,
		};
		void Esp();
		enum esp_features {
			player_outline,
			player_chams,
			player_info,
		};
		void Misc();
		enum misc_feautures {
			bunnyhop,
			fake_lag,
			third_person,
		};
	}
	struct player_offsets {
		char buffer[4];
		int new_buffer[5];
		float player_fov = 10.f;
		char new_buffer[10];
	};
}

class Vector {
public:
	Vector(float head_size, float body_size, float _total_size, const char* chHitBox);
	inline void GetHead(const Vector& isVec);

protected:


private:

};

namespace hitbox {
	void Gethead();
	void GetBody();
	void hitScan();
}

void hitbox::Gethead()
{

}

void Menu::features::Aimbot() {
	bool is_aimbot_enabled = false;
	GetAsyncKeyState(VK_F1);
	if (is_aimbot_enabled = GetAsyncKeyState(VK_F1) & 1) {
		bool is_aimbot_enabled = true;
		hitbox::Gethead();
		do
		{
			GetAsyncKeyState(VK_F1);
			bool isAimbot = true;
			Vector GetMainHitBox();
			Vector FindHitBox();
		} while (is_aimbot_enabled);
	} 
	else {
		printf("[+] Please enter f1 to enabled aimbot\n");
		exit(EXIT_FAILURE);
	}
}

void Menu::features::Esp()
{

}

void Menu::features::Misc() {

}