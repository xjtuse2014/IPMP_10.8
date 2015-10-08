/*
 * constant.h
 *
 *  Created on: 2015年9月20日
 *      Author: syq
 */

#ifndef UTILS_CONSTANT_H_
#define UTILS_CONSTANT_H_
/**
 * user
 * m_op
 */
#define ADD_USER "addUser"
#define DELETE_USER "deleteUser"
#define UPDATE_USER "updateUser"
#define SELECT_SINGLE_USER "selectSUser"
#define SELECT_ALL_USER "selectUser"

/**
 *admin
 * m_op
 */
#define ADD_ADMIN "addAdmin"
#define DELETE_SINGLE_ADMIN "deleteSingleAdmin"
#define DELETE_ALL_ADMIN "deleteALLAdmin"
#define UPDATE_ADMIN "updateAdmin"
#define SELECT_SINGLE_ADMIN "selectSingleAdmin"
#define SELECT_ALL_ADMIN "selectAllAdmin"

#define LOGIN "login"



/**
 *object:  1->User 2->MRoom 3->Meeting 4->History 5->File 6->Facility
 */
/*
#define  USER 1
#define  Meetroom 2
#define Meeting 3
#define History 4
#define File 5
#define Facilitry 6
#define ADMIN 7
*/
 /**
 * table: user
 */
#define SELECT_SINGLE_USER_SQL "select * from user where u_id="
#define SELECT_ALL_USER_SQL "select * from user"
#define DELETE_ALL_USER_SQL "delete from user"
#define DELETE_SINGLE_USER_SQL "delete from user where u_id="
#define ADD_USER_SQL "insert into user(u_id,u_name,u_department,u_phone,u_gender)values"

/**
 * table: admin
 */
#define SELECT_SINGLE_ADMIN_SQL "select * from admin where a_id="
#define SELECT_ALL_ADMIN_SQL "select * from admin"
#define DELETE_ALL_ADMIN_SQL "delete from admin"
#define DELETE_SINGLE_ADMIN_SQL "delete from admin where a_id="
#define ADD_ADMIN_SQL "insert into admin(a_id,a_name,a_psd,a_priority)values"





#endif /* UTILS_CONSTANT_H_ */
