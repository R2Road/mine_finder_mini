#pragma once

#include "r2_PointInt.h"

namespace r2
{
	class GridIndexConverter
	{
	public:
		explicit GridIndexConverter( const int width );
		explicit GridIndexConverter( const int width, const int height );

		int GetWidth() const
		{
			return mWidth;
		}
		int GetHeight() const
		{
			return mHeight;
		}
		int GetLinerEnd() const
		{
			return mLinearEnd;
		}

		r2::PointInt To_Point( int linear_index ) const;
		int To_Linear( const r2::PointInt point_index ) const;
		int To_Linear( int x, int y ) const;

	private:
		int mWidth;
		int mHeight;
		int mLinearEnd;	
	};
}
