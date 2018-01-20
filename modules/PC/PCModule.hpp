/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** PCModule.hpp
*/

#ifndef CPP_RUSH3_PCMODULE_HPP_
	#define CPP_RUSH3_PCMODULE_HPP_

	#include <AMonitorModule.hpp>
	#include "AMonitorModule.hpp"
	#include <string>
	#include <map>

class PCModule : public AMonitorModule {
public:
	explicit PCModule(int x, int y, int w, int h);
	~PCModule();
	bool render(IMonitorDisplay &display) const;
	const std::map<std::string, std::string> &getOsInfos() const;
	const std::string &getKernelVersion() const;
	const std::string &getPCModel() const;

protected:
private:
	std::string _type;
	const std::string osReleaseFile = "/etc/os-release";
	const std::string kernelOSReleaseFile = "/proc/sys/kernel/osrelease";
	const std::string kernelOSTypeFile = "/proc/sys/kernel/ostype";
	const std::string pcModelFile =
	"/sys/devices/virtual/dmi/id/product_name";
	std::map<std::string, std::string> osInfos;
	std::string kernelVersion;
	std::string pcModel;
};

#endif /* !CPP_RUSH3_PCMODULE_HPP_ */
