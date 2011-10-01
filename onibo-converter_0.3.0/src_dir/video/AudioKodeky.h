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

#ifndef AUDIOKODEKY_H_
#define AUDIOKODEKY_H_
#include <glibmm/ustring.h>
#include <list>
class AudioKodeky {
protected:
	std::list<Glib::ustring> nastavenia;
private:
	Glib::ustring meno;
	Glib::ustring kodek;
public:
	AudioKodeky();
	virtual ~AudioKodeky();
	void set(Glib::ustring, Glib::ustring);
	void setNastavenia(std::list<Glib::ustring>);
	void setAuto();
	std::list<Glib::ustring> getNastavenia();
	Glib::ustring getMeno();
	Glib::ustring getKodek();
	virtual Glib::ustring getQuality(Glib::ustring);
};

#endif /* AUDIOKODEKY_H_ */
