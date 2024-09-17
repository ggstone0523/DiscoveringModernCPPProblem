#include <iostream>
#include <string>
#include <occi.h>
#include <memory>

using namespace std;
using namespace oracle::occi;

struct environment_deleter
{
	void operator()(Environment* env)
	{ Environment::terminateEnvironment(env); };
};

struct connection_deleter
{
	connection_deleter(shared_ptr<Environment> env)
		: env{env} {};
	void operator()(Connection* conn)
	{ env->terminateConnection(conn); };
	shared_ptr<Environment> env;
};

struct statement_deleter
{
	statement_deleter(shared_ptr<Connection> conn)
		: conn{conn} {};
	void operator()(Statement* stmt)
	{ conn->terminateStatement(stmt); };
	shared_ptr<Connection> conn;
};

struct result_set_deleter
{
	result_set_deleter(shared_ptr<Statement> stmt)
		: stmt{stmt} {};
	void operator()(ResultSet* rs)
	{ stmt->closeResultSet(rs); };
	shared_ptr<Statement> stmt;
};

class db_manager
{
	public:
		using ResultSetSharedPtr = std::shared_ptr<ResultSet>;

		db_manager(string const& dbConnection, string const& dbUser,
			   string const& dbPw)
			: environment{Environment::createEnvironment(), environment_deleter{}},
			  connection{environment->createConnection(dbUser, dbPw, dbConnection),
				     connection_deleter{environment}}
		{};

		ResultSetSharedPtr query(const std::string& q) const
		{
			shared_ptr<Statement> statement(connection->createStatement(q),
					                statement_deleter{connection});
			ResultSet *rs = statement->executeQuery();
			auto deleter = result_set_deleter{statement};
			return ResultSetSharedPtr{rs, deleter};
		};
	private:
		shared_ptr<Environment> environment;
		shared_ptr<Connection> connection;
};
