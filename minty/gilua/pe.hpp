#pragma once
#include <Windows.h>
#include <cstdint>

namespace util::pe
{
	const PIMAGE_SECTION_HEADER get_section_by_name(HMODULE base, const char* name)
	{
		const PIMAGE_DOS_HEADER hdos = (PIMAGE_DOS_HEADER)base;
		const PIMAGE_NT_HEADERS hpe = (PIMAGE_NT_HEADERS)((PBYTE)hdos + hdos->e_lfanew);
		const PIMAGE_SECTION_HEADER sections = IMAGE_FIRST_SECTION(hpe);
		for (int i = 0; i < hpe->FileHeader.NumberOfSections; i++)
		{
			if (strcmp((const char*)sections[i].Name, name) == 0)
			{
				return &sections[i];
			}
		}
		return NULL;
	}
}