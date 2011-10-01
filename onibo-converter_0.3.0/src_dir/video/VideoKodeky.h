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

#ifndef VIDEOKODEKY_H_
#define VIDEOKODEKY_H_
#include <glibmm/ustring.h>
#include <list>
class VideoKodeky {
private:
	std::list<Glib::ustring> nastavenia;
	std::list<Glib::ustring> x264;
	Glib::ustring meno;
	Glib::ustring kodek;
public:
	VideoKodeky(Glib::ustring, Glib::ustring);
	virtual ~VideoKodeky();
	void setX264(std::list<Glib::ustring>);
	std::list<Glib::ustring> getX264();
	Glib::ustring getMeno();
	Glib::ustring getKodek();
};
#endif /* VIDEOKODEKY_H_ */
