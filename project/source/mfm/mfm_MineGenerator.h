#pragma once

#include <list>

#include "r2/r2_RangeUInt.h"

namespace mfm
{
	class MineGenerator
	{
	public:
		MineGenerator( const unsigned int start, const unsigned int end );



		const r2::RangeUInt::ValueT GetStart() const
		{
			return mRange.GetStart();
		}
		const r2::RangeUInt::ValueT GetEnd() const
		{
			return mRange.GetEnd();
		}
		const r2::RangeUInt& GetRange() const
		{
			return mRange;
		}



	private:
		const r2::RangeUInt mRange;
		std::list<r2::RangeUInt> mRangeContainer;
	};
}