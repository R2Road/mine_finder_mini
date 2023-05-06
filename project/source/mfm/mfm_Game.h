#pragma once

#include "mfm_Zone.h"

namespace mfm
{
	class Game
	{
	public:
		Game( const uint32_t room_width, const uint32_t room_height );

		const Zone& GetRoom() const
		{
			return mZone;
		}

	private:
		Zone mZone;
	};
}