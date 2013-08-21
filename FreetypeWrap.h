// FreetypeWrap.h

#pragma once

using namespace System;

#include "FTFont.h"

namespace FreetypeWrap {

	public ref class Freetype
	{
	private:
		FT_Library library;
		// TODO: Add your methods for this class here.

	public:
		Freetype();
		~Freetype();

		FTFont^ CreateFont(System::String^ srcFile, unsigned int pixelSize);
	};
}
