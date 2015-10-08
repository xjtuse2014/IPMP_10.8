/*
 * FacilityService.cpp
 *
 *  Created on: 2015年9月23日
 *      Author: syq
 */

#include "FacilityService.h"

FacilityService::FacilityService() {
	// TODO Auto-generated constructor stub

}

FacilityService::~FacilityService() {
	// TODO Auto-generated destructor stub
}

Facility FacilityService::GetParasFRomJson(string json){
			Json::Reader reader;
			Json::Value root;
			Facility facility;
			if(reader.parse(json,root)){
				facility.setOp(root["m_op"].asString());
				facility.setFacilityId(root["facility_id"].asString());
				facility.setAvailableState(root["available_state"].asString());
				facility.setFacilityIp(root["facility_ip"].asString());
				facility.setMeetroomId(root["meetroom_id"].asString());
				facility.setFacilityName(root["facility_name"].asString());
			}
			return facility;
}

int FacilityService::Add(Facility fac){
	string sql="insert into facility(facility_id,facility_name,available_state,meetroom_id,facility_ip)values('"+fac.getFacilityId()+"','"+fac.getFacilityName()+"','"+fac.getAvailableState()+"','"+fac.getMeetroomId()+"','"+fac.getFacilityIp()+"')";
	cout<<"addFac sql:"<<sql<<endl;
	int check=this->SelectFacilityExist(fac.getFacilityId(),fac.getFacilityIp(),fac.getMeetroomId());
	cout<<"check res is :"<<check<<endl;
	DBConn db;
	if(check==500){
		db.Execute_mysql(sql);
		db.Close_mysql();
		return 500;
	}else if(check==501){
		db.Close_mysql();
		return 501;
	}else{
		db.Close_mysql();
		return 502;
	}
}
string FacilityService::SelectAll(){
	DBConn db;
	string sql="select * from facility";
	string res=db.Query_all_mysql(sql,"Facility");
	return res;
}
/**
 *查询同一个会议室的IP是否有重
 */
int FacilityService::SelectFacilityExist(string id ,string ip,string mr_id){
	string sql="select  facility_id from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	cout<<"check sql:"<<sql<<endl;
	string sql1="select  meetroom_id from facility where facility_ip="+Utils::AddSingleQuoteMark(ip);
	cout<<"check sql:"<<sql1<<endl;
	DBConn db;
	string facility_id=db.Query_mysql(sql);
	db.Close_mysql();
	//用户增加一个设备的情况
	if(ip.empty()&mr_id.empty()){
		if(facility_id.empty()){
			return 500;
		}else{
			return 501;//ID已存在
		}
	}else{
		DBConn db;
		string meetroom_id=db.Query_mysql(sql1);
		db.Close_mysql();
		if(meetroom_id==mr_id){
			return 502;//IP重复
		}else{
			return 500;
		}
	}
/*
	string sql="select  facility_id from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	cout<<"check sql:"<<sql<<endl;
	string sql1="select  meetroom_id from facility where facility_ip="+Utils::AddSingleQuoteMark(ip);
	cout<<"check sql:"<<sql1<<endl;

	DBConn db;
	string facility_id=db.Query_mysql(sql);
	string res_id=db.Query_mysql(sql1);
	db.Close_mysql();
	if(facility_id.empty()){
		if(res_id!=mr_id){
			return 500;//同一个会议室内无重复IP，可以插入
		}else{
			return 501;//IP 重复
		}
	}else{
		return 502;//ID被用
	}*/
}

int FacilityService::SelectFacilityExist(string id,string ip){
	string sql="select  facility_name from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	cout<<"check sql:"<<sql<<endl;
	string sql1="select  facility_id from facility where facility_ip="+Utils::AddSingleQuoteMark(ip);
	cout<<"check sql:"<<sql1<<endl;

	DBConn db;
	string res_name=db.Query_mysql(sql);
	string res_id=db.Query_mysql(sql1);
	db.Close_mysql();
	if(!res_id.empty()){//查看该IP是否被占用
		if(res_name.empty()){//查看该ID是否存在
			return 500;//可以添加
		}else{
			return 502;//该ID已存在
		}
	}else{
		return 501;//IP被占用
	}
}

//更新设备成功 700 失败701
int FacilityService::Update(Facility fac){
	string sql="update facility set facility_name='"+fac.getFacilityName()+"',available_state='"+fac.getAvailableState()+"',meetroom_id='"+fac.getMeetroomId()+"',facility_ip='"+fac.getFacilityIp()+"'";
	cout<<"update Facility sql:"<<sql<<endl;
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 700;
	}else
		db.Close_mysql();
		return 701;
}

string FacilityService::SelectSignle(string id){
	string sql="select * from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	DBConn db;
	string res=db.Query_single_mysql(sql);
	return res;
}
//删除facility成功600 失败601
int FacilityService::DeleteSignle(string id){
	string sql="delete from facility where facility_id="+Utils::AddSingleQuoteMark(id);
	DBConn db;
	if(db.Execute_mysql(sql)==0){
		db.Close_mysql();
		return 600;
	}else{
		db.Close_mysql();
			return 601;
	}

}
