#include "observe.h"

void Subject::addObserver(Observer* obsrvr) {
	observers.push_back(obsrvr);
}
void Subject::removeObserver(Observer* obsrvr) {
	auto it = std::remove(observers.begin(), observers.end(), obsrvr);
	observers.erase(it, observers.end());
}

void Subject::warning(const std::string& message) const {
	for (auto obsrvr : observers)
	{
		obsrvr->onWarning(message);
	}
}
void Subject::error(const std::string& message) const {
	for (auto obsrvr : observers)
	{
		obsrvr->onError(message);
	}
}
void Subject::fatalError(const std::string& message) const {
	for (auto obsrvr : observers)
	{
		obsrvr->onFatalError(message);
	}
}

void warnObserver::bond(Subject* obsrvd_) {
	obsrvd = obsrvd_;
}
void warnObserver::onWarning(const std::string& message) {
	cmd->print(message);
}

void errObserver::bond(Subject* obsrvd_) {
	obsrvd = obsrvd_;
}
void errObserver::onError(const std::string& message) {
	cmd->print(message);
}

void fatalObserver::bond(Subject* obsrvd_) {
	obsrvd = obsrvd_;
}
void fatalObserver::onFatalError(const std::string& message) {
	cmd->print(message);
	f_cmd->print(message);
}