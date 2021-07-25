#pragma once
#include<iostream>
#include<Windows.h>

namespace feature {
	namespace aimbot {
		void GetAimbotTarget();
		void InitAimbotTarget();
	}
	namespace slientAim {
		void InitSlientAimbot();

	}
}

class CBaseEntity {
public:
	CBaseEntity(int player, const char* playerName, BYTE PlayerInfo, DWORD dwAddress);
	~CBaseEntity();
	void InitPlayer(CBaseEntity gIntsPLayer, CBaseEntity& gIntsPlayerInfo, DWORD dwAddress);
	CBaseEntity GetLocalPlayer();
};

class PlayerHitBox {
public:
	float headHitSize = 1.4f;
	float bodyHitSize = 2.8f;
	PlayerHitBox getPlayerHitBoxSize(float toGetHitbox, float total_size, DWORD HeadSize);
};