/*
 *  Onibo converter - universal video and audio converter for linux
 *  Copyright (C) 2010  Martin Geier
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef JADRO_H_
#define JADRO_H_
#include "Generator.h"
#include "Info.h"
#include "../video/Information.h"
#include "../grafika/GUI.h"
#include <glibmm/thread.h>
#include <glibmm/dispatcher.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <cstring>
#include <cstdlib>
#include <ctime>
class Jadro {
private:
	Glib::ustring subor;
	Glib::Thread* thread;
	Glib::Mutex mutex;
	int status;
	int dlzkaVidea;
	int chipid;
	Info* info;
	GUI_onb gui;
	Information *information;
	double ex_duration;			//duration with filter
	void run();
public:
	Glib::Dispatcher thread_done;
	Glib::Dispatcher message;
	Jadro();
	virtual ~Jadro();
	
	void set(Information*, GUI_onb, Info *, int);
	void start();
	void analyza(Glib::ustring);
	void exit();
};

#endif /* JADRO_H_ */
