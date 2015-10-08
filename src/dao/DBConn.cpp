/*
 * DBConn.cpp
 *
 *  Created on: Aug 14, 2015
 *      Author: syq
 */

#include "DBConn.h"

DBConn::DBConn() {
	Init_mysql();
	Connect_mysql();
}

DBConn::DBConn(MYSQL mysql) {
	this->mysql = mysql;
	Init_mysql();
	Connect_mysql();
}

DBConn::~DBConn() {
//	if (res != NULL) {
//		delete res;
//		res = NULL;
//	}
//	if (row != NULL) {
//		row = NULL;
//	}

}

void DBConn::Init_mysql() {
//	printf("init_mysql ...  \n");
	mysql_init(&mysql);
}

int DBConn::Connect_mysql() {
	if (!mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "ipmp", 0,
			NULL, 0)) {
		printf("Connect failed\n");
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return -1;
	}
	printf("Connect successful\n");
	return 0;
}

/**
 * @return a string ,usual means user's password or name and so on
 */
string DBConn::Query_mysql(string querySQL) {
	string result;
	if (mysql_real_query(&mysql, querySQL.c_str(),(unsigned int) strlen(querySQL.c_str())) == 0) {
		res = mysql_store_result(&mysql);
		while (row = mysql_fetch_row(res)) {
			for (t = 0; t < mysql_num_fields(res); t++) {
				printf("%s\t", row[t]);
				result = row[t];
			}
			printf("query successful\n");
			printf("\n");
		}
		this->FreeResult(res);
		return result;
	} else {
		printf("query failed\n");
		this->FreeResult(res);
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return "failed";
	}
}


/**
 * @return json string
 * eg:
 *
 * {
 * 		"userNum":3,
 * 		"Users":
 * 		[
 * 			{
 * 				"m_strUserName":"syq",
 * 				"m_strUserPhone":"15237872320",
 * 				"m_strUserDepartment":"software college"
 * 			},
 * 			{
 * 				"m_strUserName":"claire",
 * 				"m_strUserPhone":"15237872320",
 * 				"m_strUserDepartment":"software college"
 * 			}
 * 		]
 * }
 *
 */

string DBConn::Query_all_mysql(string sql, string ObjectName) {

	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;
	int t = mysql_real_query(&mysql, sql.c_str(),
			(unsigned int) strlen(sql.c_str()));
	if (t == -1) {
		cout << "query failed:%s\n" << mysql_errno(&mysql)
				<< mysql_error(&mysql) << endl;
	} else {
		res = mysql_store_result(&mysql); //返回查询的全部结果集
		//获取表的列数
		//int numb=mysql_num_fields(res);
		//printf("name: %s   count: %d\n", namebuf[i], rows);

		//获取并输出表头
		field = mysql_fetch_fields(res);
		//int length=mysql_fetch_lengths(res);
		int length = mysql_num_rows(res);
		int userNum = 0;
		int i = 1;
		while (row = mysql_fetch_row(res)) {	//mysql_fetch_row取结果集的下一行
			for (t = 0; t < mysql_num_fields(res); t++) {	//结果集的列的数量
//				printf("field[t].name,row[t]:%s,%s\n", field[t].name, row[t]);
				item[field[t].name] = Json::Value(row[t]);
			}
			arrayObj.append(item);
			item.clear();
//			printf("\n");
			userNum++;
		}
//		string flaf_num=ObjectName+string("Num");
		root["Num"] = Json::Value(userNum);
		root[ObjectName] = arrayObj;
//		cout << "the result set is:" << endl << root.toStyledString() << endl;
		return root.toStyledString();
	}
}

void DBConn::Close_mysql() {
	//mysql_free_result(res);
cout<<"i'm before DBConn Close"<<endl;


//	mysql_close(&mysql);


cout<<"i'm after DBConn Close"<<endl;

}

//SQL语句执行成功返回0，出错返回非0。
int DBConn::Insert_mysql(string sql) {
	if (!mysql_query(&mysql, sql.c_str())) {
		return 0;
	} else {
		cout << mysql_errno(&mysql) << endl;
						cout << mysql_error(&mysql) << endl;
		return -1;
	}
}
/**
 * 执行SQL
 */
int DBConn::Execute_mysql(string sql) {
cout<<"DBconn::Execute_mysql------"<<endl;

	if (!mysql_query(&mysql, sql.c_str())) {

		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		//this->FreeResult(res);
		return 0;
	} else {
		cout << mysql_errno(&mysql) << endl;
		cout << mysql_error(&mysql) << endl;
		return -1;
	}
}
/**
 * @params id table
 * @return  a user's all parameters of the Json format
 */
string DBConn::Query_single_mysql(string sql) {

	Json::Value item;
	int t = mysql_real_query(&mysql, sql.c_str(),
			(unsigned int) strlen(sql.c_str()));
	if (t == -1) {
		cout << "query failed:" << mysql_errno(&mysql) << mysql_error(&mysql)
				<< endl;
	} else {
		res = mysql_store_result(&mysql);	//返回查询的全部结果集
		field = mysql_fetch_fields(res);
		while (row = mysql_fetch_row(res)) {	//mysql_fetch_row取结果集的下一行
			for (t = 0; t < mysql_num_fields(res); t++) {	//结果集的列的数量
//				printf("field[t].name,row[t]:%s,%s\n", field[t].name, row[t]);
				item[field[t].name] = Json::Value(row[t]);
			}
		}
		cout << "the single user's info set is:" << endl<< item.toStyledString() << endl;
		this->FreeResult(res);
		return item.toStyledString();
	}
}
/**
 * 释放空间
 */

void DBConn::FreeResult(MYSQL_RES *result){
	if(result){
		mysql_free_result(result);
	}
}



