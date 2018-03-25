#pragma once
#include <sol.hpp>

class Bot;

class LuaBot
{
	public:
		bool init();
		bool step(Bot& bot, float &next_heading, bool &speed);

	private:
		bool m_initialized = false;
		sol::state m_lua_state;
		sol::environment m_lua_safe_env;

		void setQuota(uint32_t num_instructions, double seconds);
		sol::environment createEnvironment();
		sol::table createFunctionTable(const std::string& obj, const std::vector<std::string>& items);

		void findFood(Bot &bot, std::vector<sol::table> &foodVector);
		void findSnakeSegments(Bot &bot, std::vector<sol::table> &snakeSegmentVector);

};
