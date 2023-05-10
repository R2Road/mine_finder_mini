#pragma once

namespace r2
{
	class Direction8SequentialState
	{
	public:
		enum class eState
		{
			NONE = -1,

			Up,
			Up_Right,
			Right,
			Down_Right,
			Down,
			Down_Left,
			Left,
			Up_Left,

			FIRST = Up,
			END = Up_Left,

			SIZE = END + 1,
			HALF_SIZE = SIZE / 2,
		};

		static eState GetRandomState_F2E();
		static eState GetRandomState_N2E();

		static void ConvertState2Point( const eState state, int* out_x, int* out_y );
		static void ConvertPoint2State( const int x, const int y, eState& out_state );

		static eState ConvertInteger2State( const int value );

		static bool IsDiagonalDirection8State( const eState state );

		static eState Rotate( const eState state, const bool bRight );
		static eState Reverse( const eState state );
	};
}
