namespace FreetypeWrap
{
	public ref struct Bitmap
	{
		int width, height;
		int stride;
		System::IntPtr buffer;
	};

	public ref struct Metrics
	{
		int horizontalAdvance;
		int bitmap_left, bitmap_top;
	};
}