#pragma once

#include "mfm_Stage.h"

namespace mfm
{
	class Game
	{
	public:
		Game( const uint32_t room_width, const uint32_t room_height );

		const Stage& GetRoom() const
		{
			return mStage;
		}

	private:
		Stage mStage;
	};
}