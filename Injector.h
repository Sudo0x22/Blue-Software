#pragma once
#include"Memory.h"

struct Injector : public Memory {
	void Inject(const wchar_t* dllPath) const;
};