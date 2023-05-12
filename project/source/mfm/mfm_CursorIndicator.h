#pragma once

#include <stdint.h>

namespace mfm
{
	class CursorIndicator
	{
	public:
		CursorIndicator( const uint32_t width, const uint32_t height );



		//
		// Getter
		//
		uint32_t GetWidth() const
		{
			return mWidth;
		}
		uint32_t GetHeight() const
		{
			return mHeight;
		}
		uint32_t GetCursorX() const
		{
			return mCursorX;
		}
		uint32_t GetCursorY() const
		{
			return mCursorY;
		}



	private:
		const uint32_t mWidth;
		const uint32_t mHeight;
		uint32_t mCursorX;
		uint32_t mCursorY;
	};
}