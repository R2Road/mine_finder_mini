#pragma once

namespace r2
{
	class Direction4SequentialState
	{
	public:
		enum class eState
		{
			NONE = -1,

			Up,
			Right,
			Down,
			Left,

			FIRST = Up,
			END = Left,

			SIZE = END + 1,
			HALF_SIZE = SIZE / 2,
		};

		static eState GetRandomState();

		static void ConvertState2Point( const eState state, int* out_x, int* out_y );
		static eState ConvertPoint2State( const int x, const int y );

		static eState ConvertInteger2State( const int value );

		static eState Rotate( const eState state, const bool bRight );
		static eState Reverse( const eState state );
	};
}
