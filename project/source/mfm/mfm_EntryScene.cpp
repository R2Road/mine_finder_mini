#include "mfm_EntryScene.h"

#include "r2bix/r2bix_Director.h"

#include "mfm_TextureTable.h"
#include "mfm_TextureFrameAnimationTable.h"

#include "mfm_CompanyScene.h"

namespace mfm
{
	class EntrySceneComponent : public r2bix_component::Component<EntrySceneComponent>
	{
	public:
		EntrySceneComponent( r2bix_node::Node& owner_node ) : r2bix_component::Component<EntrySceneComponent>( owner_node ) {}

		//
		//
		//
		void Update( const float delta_time ) override
		{
			r2bix_component::iComponent::Update( delta_time );

			//
			// Table Load
			//
			mfm::TextureTable::GetInstance().Load();
			mfm::TextureFrameAnimationTable::GetInstance().Load();

			//
			// Scene
			//
			auto next_scene = mfm::CompanyScene::Create( mOwnerNode.GetDirector() );

			//
			// Go Next 
			//
			mOwnerNode.GetDirector().Setup( std::move( next_scene ) );
		}
	};

	r2bix_node::SceneNodeUp EntryScene::Create( r2bix::Director& director )
	{
		auto ret( r2bix_node::SceneNode::Create( director ) );
		if( ret )
		{
			ret->AddComponent<EntrySceneComponent>();
		}

		return ret;
	}
}