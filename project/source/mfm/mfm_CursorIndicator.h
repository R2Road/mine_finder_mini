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



	private:
		const uint32_t mWidth;
		const uint32_t mHeight;
	};
}