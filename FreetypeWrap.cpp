// This is the main DLL file.
#include "stdafx.h"

#include "FreetypeWrap.h"

using namespace FreetypeWrap;

Freetype::Freetype()
{
	pin_ptr<FT_Library> pLib = &library;
	if(FT_Init_FreeType( pLib ) != 0)
	{
		throw gcnew System::Exception();
	}
}

Freetype::~Freetype()
{
	FT_Done_FreeType(library);
}

FTFont^ Freetype::CreateFont(System::String^ srcFile, unsigned int pixelSize)
{
	char* path = (char*)(void*) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(srcFile);
		
	FTFont^ f = gcnew FTFont(library, path, pixelSize);
	System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)path);
	return f;
}