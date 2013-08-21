#include "StdAfx.h"
#include "FTFont.h"

using namespace FreetypeWrap;

FTFont::FTFont(FT_Library lib, const char* fontPath, unsigned int pixelSize)
{
	pin_ptr<FT_Face> pFace = &face;
	int error = FT_New_Face(lib, fontPath, 0, pFace );
	if ( error == FT_Err_Unknown_File_Format )
	{
		throw gcnew System::Exception();
	}
	else if( error != 0)
	{
		throw gcnew System::Exception();
	}

	//error = FT_Set_Char_Size( face, 0, /* char_width in 1/64th of points */ 16*64, 300, 300 );
	error = FT_Set_Pixel_Sizes(face, pixelSize, 0);

	defaultHeight = face->size->metrics.height;
}

void FTFont::RenderGlyph(unsigned short character, [System::Runtime::InteropServices::Out] Bitmap^% bitmap, [System::Runtime::InteropServices::Out] Metrics^% metrics)
{
	FT_GlyphSlot slot = face->glyph;
	int error = FT_Load_Char( face, character, FT_LOAD_RENDER );
	if(error != 0) throw gcnew System::Exception();

	//Now, the data is in slot->bitmap
	Bitmap^ b = gcnew Bitmap();
	
	b->buffer = System::IntPtr(slot->bitmap.buffer);
	b->width = slot->bitmap.width;
	b->height = slot->bitmap.rows;
	b->stride = slot->bitmap.pitch;

	bitmap = b;

	metrics = gcnew Metrics();
	metrics->horizontalAdvance = face->glyph->advance.x;
	metrics->bitmap_left = face->glyph->bitmap_left;
	metrics->bitmap_top = face->glyph->bitmap_top;

	return;
}