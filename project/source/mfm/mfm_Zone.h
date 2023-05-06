#pragma once

#include "r2/r2_Grid.h"

namespace mfm
{
	using Tile = enum class Tile {
		Empty,
		Wall,
	};



	class Zone
	{
	public:
		using Terrain = r2::Grid<Tile>;
		using ActorContainer = std::vector<class Actor*>;



		Zone( const uint32_t width, const uint32_t height );



		//
		// Getter
		//
		std::size_t GetWidth() const
		{
			return mTerrain.GetWidth();
		}
		std::size_t GetHeight() const
		{
			return mTerrain.GetHeight();
		}
		std::size_t GetSize() const
		{
			return mTerrain.GetSize();
		}



		//
		// Terrain
		//
		const Terrain::CellT& GetTile( const std::size_t x, const std::size_t y ) const
		{
			return mTerrain.Get( x, y );
		}
		void SetTile( const std::size_t x, const std::size_t y, const Terrain::CellT& new_value )
		{
			mTerrain.Set( x, y, new_value );
		}



	private:
		Terrain mTerrain;
		ActorContainer mActorContainer;
	};

	void RoomBuilder( Zone* out_room );
}