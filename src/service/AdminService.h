/*
 * AdminService.h
 *
 *  Created on: 2015年9月22日
 *      Author: syq
 */

#ifndef SERVICE_ADMINSERVICE_H_
#define SERVICE_ADMINSERVICE_H_
#include "../utils/univer.h"
#include "../utils/constant.h"
#include "../utils/Utils.h"
#include "../dao/DBConn.h"
#include "../bean/Admin.h"
#include "../utils/json/json.h"

class AdminService {
private:
	Admin admin;

public:
	/* 添加管理员*/
	int addAdmin(Admin admin);

	/* 删除管理员*/
	int deleteSingleAdmin(string a_id);

	/* 删除所有管理员*/
	int deleteAllAdmin();


	/* 更新管理员*/
	int updateAdmin(Admin admin);

	/*按id查询单个管理员*/
	string selectSingleAdmin(string a_id);

	/* 查询所有管理员*/
	string selectAllAdmin();

	/* 管理员登录*/
	int LoginSys(string a_id,string a_psd);
	/* 管理员推出*/
	int Logout(string a_id);

	/*检查是否已有此id的admin*/
	int SelectAdminExist(string a_id);

	/*通过用户id来获得权限值*/
	string GetAdminPriority(string a_id);
	/**
	 * @return Admin
	 * 解析JSON 获取对象属性
	 */
	Admin GetParasFRomJson(string jsonString);

public:
	AdminService();
	virtual ~AdminService();

	const Admin& getAdmin() const {
		return admin;
	}

	void setAdmin(const Admin& admin) {
		this->admin = admin;
	}
};

#endif /* SERVICE_ADMINSERVICE_H_ */
