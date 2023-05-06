#pragma once

#include "r2_Point.h"

namespace r2
{
	using PointUint = r2::Point<uint32_t>;

	struct Hash4PointUint
	{
		std::size_t operator()( const r2::PointUint& point ) const
		{
			return ( point.GetY() * 10000 ) + point.GetX();
		}
	};
}