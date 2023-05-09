#include "r2_GridIndexConverter.h"

#include <algorithm>
#include <limits> // std::numeric_limits

namespace r2
{
	GridIndexConverter::GridIndexConverter( const int width ) :
		mWidth( std::max( 1, width ) )
		, mHeight( std::numeric_limits<int>::max() / mWidth )
		, mLinearEnd( To_Linear( mWidth, mHeight ) )
	{}

	GridIndexConverter::GridIndexConverter( const int width, const int height ) :
		mWidth( std::max( 1, width ) )
		, mHeight( std::max( 1, height ) )
		, mLinearEnd( To_Linear( mWidth, mHeight ) )
	{}

	r2::PointInt GridIndexConverter::To_Point( int linear_index ) const
	{
		linear_index = std::min( std::max( 0, linear_index ), mLinearEnd );

		const int y = linear_index / mWidth;
		const int x = linear_index - ( y * mWidth );
		return r2::PointInt{ x, y };
	}
	int GridIndexConverter::To_Linear( const r2::PointInt point_index ) const
	{
		return To_Linear( point_index.GetX(), point_index.GetY() );
	}
	int GridIndexConverter::To_Linear( int x, int y ) const
	{
		x = std::min( std::max( 0, x ), mWidth - 1 );
		y = std::min( std::max( 0, y ), mHeight - 1 );

		return x + ( y * mWidth );
	}
}
