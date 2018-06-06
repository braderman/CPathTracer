#include <stdio.h>
#include <freeimage.h>

int main(int argc, char* argv[])
{
	FreeImage_Initialise(FALSE);

	int nx = 200;
	int ny = 100;

	FIBITMAP* bmp = FreeImage_Allocate(nx, ny, 24, FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);
	unsigned int pitch  = FreeImage_GetPitch(bmp);
	BYTE *pRowPtr = FreeImage_GetBits(bmp);
	BYTE *pColPtr;

	for(int y = 0; y < ny; ++y)
	{
		pColPtr = pRowPtr;

		for(int x = 0; x < nx; ++x)
		{
			float r = (float)x / (float)nx;
			float g = (float)y / (float)ny;
			float b = 0.2f;
			
			int ir = (int)(r * 255.99);
			int ig = (int)(g * 255.99);
			int ib = (int)(b * 255.99);

			pColPtr[FI_RGBA_RED]   = ir;
      		pColPtr[FI_RGBA_GREEN] = ig;
      		pColPtr[FI_RGBA_BLUE]  = ib;
			pColPtr += 3;
		}

		pRowPtr += pitch;
	}

	FreeImage_Save(FIF_PNG, bmp, "output.png", 0);
	FreeImage_Unload(bmp);
	FreeImage_DeInitialise();
}