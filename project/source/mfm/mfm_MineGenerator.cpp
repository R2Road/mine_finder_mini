#include "mfm_MineGenerator.h"

#include "r2/r2_Assert.h"

namespace mfm
{
	MineGenerator::MineGenerator( const unsigned int start, const unsigned int end ) :
		mRange(
			start < end ? start : end
			, start < end ? end : start
		)
		, mRangeContainer()
	{
		Clear();
	}

	void MineGenerator::Clear()
	{
		mRangeContainer.clear();
		mRangeContainer.push_back( mRange );
	}
}