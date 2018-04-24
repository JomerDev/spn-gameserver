#pragma once

#include <memory>

#include <TcpServer/TcpServer.h>

#include "UpdateTracker.h"
#include "Field.h"
#include "Database.h"

class Game
{
	private:
		static constexpr const int DB_QUERY_INTERVAL = 60;

		TcpServer server;
		std::unique_ptr<Field> m_field;
		std::unique_ptr<db::IDatabase> m_database;
		int m_dbQueryCounter = 0;
		uint32_t m_currentFrame = 0;
		bool connectDB();
		void queryDB();
		void createBot(int bot_id);

	public:
		Game();

		bool OnConnectionEstablished(TcpSocket &socket);
		bool OnConnectionClosed(TcpSocket &socket);
		bool OnDataAvailable(TcpSocket &socket);
		bool OnTimerInterval();

		int Main();
};
