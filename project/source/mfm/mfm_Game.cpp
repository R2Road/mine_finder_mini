#include "mfm_Game.h"

namespace mfm
{
	Game::Game( const uint32_t room_width, const uint32_t room_height ) :
		mStage( room_width, room_height )
	{}
}