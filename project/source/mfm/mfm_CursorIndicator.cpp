#include "mfm_CursorIndicator.h"

namespace mfm
{
	CursorIndicator::CursorIndicator( const uint32_t width, const uint32_t height ) :
		mWidth( width )
		, mHeight( height )
		, mCursorX( 0 )
		, mCursorY( 0 )
	{}



	void CursorIndicator::Move( const eMoveDirection move_direction )
	{
		switch( move_direction )
		{
		case eMoveDirection::Up:
			mCursorY = ( mCursorY > 0 ? mCursorY - 1 : mCursorY );
			break;
		case eMoveDirection::Down:
			mCursorY = ( mCursorY < mHeight - 1 ? mCursorY + 1 : mCursorY );
			break;

		case eMoveDirection::Left:
			mCursorX = ( mCursorX > 0 ? mCursorX - 1 : mCursorX );
			break;
		case eMoveDirection::Right:
			mCursorX = ( mCursorX < mWidth - 1 ? mCursorX + 1 : mCursorX );
			break;

		default:
			break;
		}
	}
}