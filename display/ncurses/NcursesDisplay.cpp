/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** NcursesDisplay.cpp
*/
#include <iostream>
#include <time/TimeModule.hpp>
#include <sys/ioctl.h>
#include "CPU/CPUModule.hpp"
#include "PC/PCModule.hpp"
#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay(): _mainwin(), _modules()
{
//	_modules.push_back(new PCModule(0, 0, 0, 0));
	_modules.push_back(new TimeModule(0, 0, 50, 50));

}

bool NcursesDisplay::setup()
{
	_mainwin = initscr();
	noecho();
	curs_set(0);
	timeout(100);
	return false;
}

bool NcursesDisplay::render()
{
	while (true) {
		auto c = static_cast<char>(getch());
		if (c == 'q')
			return false;
		clearRender();
		for (auto &n : _modules) {
			struct winsize size;
			if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0)
				return false;
			if (!n->setup())
				continue;
			n->render(*this);
			n->event(c);
		}
		refreshRender();
	}
}

bool NcursesDisplay::refreshRender()
{
	refresh();
	return true;
}

bool NcursesDisplay::teardown()
{
	delwin(_mainwin);
	endwin();
	refresh();
	return true;
}

WINDOW *NcursesDisplay::getWindow() const
{
	return _mainwin;
}

bool NcursesDisplay::clearRender()
{
	clear();
	return true;
}

NcursesDisplay::~NcursesDisplay()
{
	for (auto &n : _modules) {
		delete n;
	}
}
