// bigfile: a header-only C++ library for
//			reading data from Electronic Arts
//			BIG archives.
//
// (c) 2020 Lily <lily.modeco80@protonmail.ch> under the terms of the MIT License.

// Implemntation of utlity functions used in bigfile.

#include <cstring>
#include <bigfile/archive_type.hpp>

namespace bigfile {

	ArchiveType GetArchiveType(char* value) {
		constexpr static char BigfMagic[] = "BIGF";

		if(!value)
			return ArchiveType::NotArchive;

		if(!strncmp(value, BigfMagic, 4))
			return ArchiveType::BIGF;

		if (value[0] == 0xC0 && value[1] == 0xFB)
			return ArchiveType::CoFb;

		return ArchiveType::NotArchive;
	}

}
