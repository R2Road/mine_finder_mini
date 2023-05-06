#pragma once

#include <list>

#include "r2/r2_RangeUInt.h"

namespace mfm
{
	class MineGenerator
	{
	public:
		using ContainerT = std::list<r2::RangeUInt>;



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
		const ContainerT& GetRangeContainer() const
		{
			return mRangeContainer;
		}



		void Clear();
		void Ready();



	private:
		const r2::RangeUInt mRange;
		ContainerT mRangeContainer;
	};
}