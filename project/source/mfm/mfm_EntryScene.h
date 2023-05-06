#pragma once

#include "r2bix/r2bix_node_SceneNode.h"

namespace mfm
{
	class EntryScene : public r2bix_node::SceneNode
	{
	private:
		EntryScene() = delete;

	public:
		static r2bix_node::SceneNodeUp Create( r2bix::Director& director );
	};
}