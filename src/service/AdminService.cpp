/*
 * AdminService.cpp
 *
 *  Created on: 2015年9月22日
 *      Author: syq
 */

#include "AdminService.h"

AdminService::AdminService() {
	// TODO Auto-generated constructor stub

}

AdminService::~AdminService() {
	// TODO Auto-generated destructor stub
}
/**
 * return 100;//登录成功
 * return 101;//登录失败 ：密码错误
 * return 102;//登录失败：ID不存在
 */
int AdminService::LoginSys(string a_id,string a_psd){
	DBConn db;
	string sql="select a_psd from admin where a_id="+Utils::AddSingleQuoteMark(a_id);
	string sql1="update admin set a_loginState='1' where a_id='"+a_id+"'";
	string res=db.Query_mysql(sql);
	db.Close_mysql();
	if(res.empty()==true){
		return 102;
	}else if(res==a_psd){
cout<<"AdminServcie::LoginSys-------- i'm before db.Execute_mysql"<<endl;
        DBConn db;
		db.Execute_mysql(sql1);    //如果登录成功，就把loginState设为“1”
cout<<"AdminServcie::LoginSys-------- i'm after db.Execute_mysql"<<endl;
		db.Close_mysql();
		return 100;
	}else{
		return 101;
	}
}

Admin AdminService::GetParasFRomJson(string jsonString){
	Json::Reader reader;
		Json::Value root;
		Admin admin;
		if(reader.parse(jsonString,root)){
			admin.setOp(root["m_op"].asString());
			admin.setPsd(root["a_psd"].asString());
			admin.setId(root["a_id"].asString());
			admin.setPriority(root["a_priority"].asString());
			admin.setName(root["a_name"].asString());
			admin.setLoginId(root["a_loginId"].asString());
		}
		return admin;
}

//添加管理员
/**
 * return 103;//管理员添加成功
 * return 104;//管理员添加失败
 * return 105;//管理员添加失败：ID重复
 */
int AdminService::addAdmin(Admin admin){
	string sql="insert into admin(a_id,a_name,a_psd,a_priority)values('"+admin.getId()+"','"
			+admin.getName()+"','"+admin.getPsd()+"','"+admin.getPriority()+"')";
	string sql1="update admin set a_loginState='0' where a_id='"+admin.getId()+"'";
cout<<"insert admin sql:"<<sql<<endl;
	int tmp = this->SelectAdminExist(admin.getId());
	if(tmp==0){
		DBConn db;
		if(db.Execute_mysql(sql)==0){
			db.Execute_mysql(sql1);           //添加成功一个admin，默认登录状况为未登录把loginState设置为“0”
			db.Close_mysql();
			return 103;      //添加成功
		}
		db.Close_mysql();
		return 104;         //添加失败
	}else{
		return 105;         //添加失败：ID重复
	}
}


//删除管理员
/**
 * return 106;//管理删除成功
 * return 107;//管理员删除失败
 */
int AdminService::deleteSingleAdmin(string a_id){

	string sql="delete from admin where a_id="+Utils::AddSingleQuoteMark(a_id);
		DBConn db;
		if(db.Execute_mysql(sql)==0){
			db.Close_mysql();
				return 106;
		}else{
			db.Close_mysql();
				return 107;
		}
}

//删除管理员
/**
 * return 106;//管理删除成功
 * return 107;//管理员删除失败
 */
int AdminService::deleteAllAdmin(){

	string sql="delete from admin";
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 108;
	}else{
		db.Close_mysql();
		return 109;
	}
}

// 更新管理员
/**
 * return 108;//管理员更新成功
 * return 109;//管理员更新失败
 */
int AdminService::updateAdmin(Admin admin){

	string sql = "update admin set a_name='"+ admin.getName() + "',a_psd='" + admin.getPsd() + "',a_priority='"+ admin.getPriority() +"' where u_id='"+admin.getId()+"'";
cout<<"AdminService::updateAdmin ---- update sql="<<sql<<endl;
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 108;
	}else{

		db.Close_mysql();
		return 109;
	}
}

/* 查询所有管理员*/
string AdminService::selectAllAdmin(){
	DBConn db;
	string res = db.Query_all_mysql(SELECT_ALL_ADMIN_SQL, "Admin");
cout<<"AdminService::selectAllAdmin(), res="<<res<<endl;
    db.Close_mysql();
    return res;
}


/*按id查询单个管理员*/
string AdminService::selectSingleAdmin(string a_id){
cout<<"AdminService::slelectSingleAdmin  ---------i'm here"<<endl;
	DBConn db;
	string sql = SELECT_SINGLE_ADMIN_SQL+Utils::AddSingleQuoteMark(a_id);
cout<<"select single sql= "<<sql<<endl;
	string res = db.Query_single_mysql(sql);
cout<<"AdminService::selectSingleAdmin(), res="<<res<<endl;
	db.Close_mysql();
	return res;
}

/*按id查询管理员权限*/
string AdminService::GetAdminPriority(string a_id){
	Json::Value value;
	Json::Reader reader;
	string reVal;
	DBConn db;
	string sql = "select a_priority from admin where a_id='"+a_id+"'";
cout<<"AdminService::GetAdminPriority-----sql="<<sql<<endl;
	if (reader.parse(db.Query_single_mysql(sql),value)) {
		reVal = value["a_priority"].asString();
	}
cout<<"AdminService::GetAdminPriority-----res="<<reVal<<endl;
    return reVal;
}

/*检查是否已有此id的admin
 *@return 0:无重复   -1：重复
 *
 * */
int AdminService::SelectAdminExist(string a_id){
	DBConn db;
    string sql = "select a_id from admin where a_id='"+a_id+"'";

cout<<"i'm in the AdminService::SelectAdminExist, sql="<<sql<<endl;

	string res = db.Query_mysql(sql);

cout<<"i'm in the AdminService::SelectAdminExist, res="<<res<<endl;
    if(res.empty()==true){
    	cout<<"无重复，可插入!"<<endl;
    	return 0;
    }
    cout<<"重复，不可插入!"<<endl;
    return -1;
}







