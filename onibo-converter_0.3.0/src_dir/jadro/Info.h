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

#ifndef INFO_H_
#define INFO_H_
#include <glibmm/thread.h>
#include <glibmm/ustring.h>
#include <list>

class Info {
	Glib::Mutex mutex;
	Glib::ustring nazov;
	int status;
	double fragment;
	bool prepisat;
	int pocet;
	int akt;
	bool convert;
	std::list<double> video_cas;
	std::list<double> rozdiel_merania;
	int mn_merani;
	double last;
	double last_roz;
	double do_konca;
public:
	Info();
	virtual ~Info();
	Glib::ustring getNazov();
	void setNazov(Glib::ustring);
	Glib::ustring getText();
	void setFragment(double);
	double getFragment();
	void setStatus(int);
	int getStatus();
	void setPrepis(bool);
	bool getPrepis();
	void setPocet(int);
	void setDalsi();
	void setBack();
	void clr();
	void setCovert(bool);
	bool getConvert();
	void addTime(double, double, double);
};

#endif /* INFO_H_ */
