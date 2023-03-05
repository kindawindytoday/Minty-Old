#pragma once
#include <array>
#include <optional>

namespace util::scanner
{
	bool cmp_pat(const uint8_t* pat, const char* mask, size_t pattern_len, const uint8_t* ptr)
	{
		for (int i = 0; i < pattern_len; i++)
			if (mask[i] == 'x' && pat[i] != ptr[i])
				return false;

		return true;
	}

	const uint8_t* find_pat(const uint8_t* pat, const char* mask, const uint8_t* start, size_t size, bool reverse = false)
	{
		auto pattern_len = strlen(mask);
		auto end = start + size - pattern_len;

		if (reverse)
		{
			for (auto ptr = end; ptr >= start; ptr--)
				if (cmp_pat(pat, mask, pattern_len, ptr) == true)
					return ptr;
		}
		else
		{
			for (auto ptr = start; ptr <= end; ptr++)
				if (cmp_pat(pat, mask, pattern_len, ptr) == true)
					return ptr;
		}

		return 0;
	}

	const uint8_t* find_ref_relative(const uint8_t* addr, const uint8_t* start, size_t size, bool reverse = false)
	{
		auto end = start + size - 4;

		if (reverse)
		{
			for (auto ptr = end; ptr >= start; ptr--)
				if (*(uint32_t*)(ptr)+ptr + 4 == addr)
					return ptr;
		}
		else
		{
			for (auto ptr = start; ptr <= end; ptr++)
				if (*(uint32_t*)(ptr)+ptr + 4 == addr)
					return ptr;
		}

		return 0;
	}
}