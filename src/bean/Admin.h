/*
 * Admin.h
 *
 *  Created on: 2015年9月22日
 *      Author: syq
 */

#ifndef BEAN_ADMIN_H_
#define BEAN_ADMIN_H_
#include "../utils/univer.h"
class Admin {
private:
	string a_id;
	string a_name;
	string a_psd;
	string a_priority;
	string a_loginState;
	string a_loginId;
	string m_op;
public:

	Admin();
	virtual ~Admin();

	const string& getId() const {
		return a_id;
	}

	void setId(const string& id) {
		a_id = id;
	}

	const string& getName() const {
		return a_name;
	}

	void setName(const string& name) {
		a_name = name;
	}

	const string& getPriority() const {
		return a_priority;
	}

	void setPriority(const string& priority) {
		a_priority = priority;
	}

	const string& getPsd() const {
		return a_psd;
	}

	void setPsd(const string& psd) {
		a_psd = psd;
	}

	const string& getOp() const {
		return m_op;
	}

	void setOp(const string& op) {
		m_op = op;
	}

	const string& getLoginState() const {
		return a_loginState;
	}

	void setLoginState(const string& loginState) {
		a_loginState = loginState;
	}

	const string& getLoginId() const {
		return a_loginId;
	}

	void setLoginId(const string& loginId) {
		a_loginId = loginId;
	}
};

#endif /* BEAN_ADMIN_H_ */
