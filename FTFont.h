#pragma once

#include "Structures.h"

namespace FreetypeWrap
{
public ref class FTFont
{
private:
	FT_Face face;
internal:
	FTFont(FT_Library library, const char* fontPath, unsigned int pixelSize);
public:
	void RenderGlyph(unsigned short character, [System::Runtime::InteropServices::Out] Bitmap^% bitmap, [System::Runtime::InteropServices::Out] Metrics^% metrics);
	int defaultHeight;
};

}
