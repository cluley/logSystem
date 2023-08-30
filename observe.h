#pragma once

#include <vector>

#include "logCommand.h"

class Subject;

class Observer {
public:
	virtual void bond(Subject* obsrvd_) = 0;
	virtual void onWarning(const std::string& message) = 0;
	virtual void onError(const std::string& message) = 0;
	virtual void onFatalError(const std::string& message) = 0;
protected:
	LogCommand* cmd = NULL;
	Subject* obsrvd = NULL;
};

class Subject {
public:

	void addObserver(Observer* obsrvr);
	void removeObserver(Observer* obsrvr);

	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatalError(const std::string& message) const;
private:
	std::vector<Observer*> observers;
};

class warnObserver : public Observer {
public:
	warnObserver() { cmd = new ConsoleLog; }
	~warnObserver() { 
		delete cmd; 
		obsrvd->removeObserver(this);
	}

	void bond(Subject* obsrvd_) override;
	void onWarning(const std::string& message) override;
	void onError(const std::string& message) {}
	void onFatalError(const std::string& message) {}
private:

};

class errObserver : public Observer {
public:
	errObserver() { cmd = new FileLog; }
	~errObserver() { 
		delete cmd; 
		obsrvd->removeObserver(this);
	}

	void bond(Subject* obsrvd_) override;
	void onWarning(const std::string& message) {}
	void onError(const std::string& message) override;
	void onFatalError(const std::string& message) {}
};

class fatalObserver : public Observer {
public:
	fatalObserver() { cmd = new ConsoleLog; }
	~fatalObserver() {
		delete cmd;
		delete f_cmd;
		obsrvd->removeObserver(this);
	}

	void bond(Subject* obsrvd_) override;
	void onWarning(const std::string& message) {}
	void onError(const std::string& message) {}
	void onFatalError(const std::string& message) override;
private:
	LogCommand* f_cmd = new FileLog;
};