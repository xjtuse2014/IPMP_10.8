/*
 * DBConn.h
 *
 *  Created on: Aug 14, 2015
 *      Author: syq
 */

#ifndef DBCONN_H_
#define DBCONN_H_
#include <string>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include  <mysql/mysql.h>
#include "../utils/json/json.h"
class DBConn{
public:
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_FIELD *field;
	MYSQL_ROW row;
	string query;
	vector<vector<string> > result;
	int t;
public:
	DBConn();
	DBConn(MYSQL mysql);
	~DBConn();
	void Init_mysql();
	int Connect_mysql();
	string Query_mysql(string query);

	string Query_single_mysql(string sql);
	void FreeResult(MYSQL_RES *result);


	/*查询一个字段*/
	string Query_single_info(string sql);

	string Query_all_mysql(string sql,string ObjectName);

	int Execute_mysql(string sql);
	int Insert_mysql(string sql);
//	int Insert_user_mysql(char u_id,char u_name,char u_department,char u_phone,int u_gender);
//	int Update_user_mysql(string u_id,string u_name,string u_department,string u_phone,int u_gender);
	void Close_mysql();
};




#endif /* DBCONN_H_ */
