#include "mfm_MineGenerator.h"

#include "r2/r2_Assert.h"

namespace mfm
{
	MineGenerator::MineGenerator( const unsigned int start, const unsigned int end ) :
		mRange( start, end )
		, mRangeContainer()
	{}
}