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

#ifndef ZAMOK_H_
#define ZAMOK_H_
#include <glibmm/thread.h>
#include <glibmm/ustring.h>

class Zamok {
private:
	Glib::Mutex mutex;
	bool konvertovanie;
	std::list<Glib::ustring> vid;
	std::list<Glib::ustring> aud;
	bool prepis;
public:
	Zamok();
	virtual ~Zamok();
	void setKonvert(bool konvert);
	bool getKonvert();
	void setVideo(std::list<Glib::ustring>);
	void setAudio(std::list<Glib::ustring>);
	std::list<Glib::ustring> getVideo();
	std::list<Glib::ustring> getAudio();
	void setPrepisat(bool);
	bool getPrepisat();
};

#endif /* ZAMOK_H_ */
