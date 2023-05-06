#pragma once

namespace mfm
{
	class DebugConfig
	{
	private:
		DebugConfig() = delete;

	public:
		struct NodeConfig
		{
			bool pivot = false;
		};
		static const NodeConfig& GetNodeConfig()
		{
			const static NodeConfig ret
			{
				true
			};
			return ret;
		}
	};
}