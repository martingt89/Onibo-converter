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

#ifndef KONTAINER_H_
#define KONTAINER_H_

#include "../makros.h"
#include "VideoKodeky.h"
#include <glibmm/ustring.h>
#include <list>
//#include <iterator>
class Kontainer {
private:
	Glib::ustring meno;
	Glib::ustring cesta;
	std::list<Glib::ustring> v_kodeky;
	std::list<Glib::ustring> a_kodeky;
public:
	Kontainer(Glib::ustring, Glib::ustring);
	virtual ~Kontainer();
	Glib::ustring getMeno();
	std::list<Glib::ustring> getVKodeky();
	Glib::ustring getCesta();
	std::list<Glib::ustring> getAKodeky();
	void addVKodek(Glib::ustring);
	void addAKodek(Glib::ustring);
	int getVKodekNum(Glib::ustring);
	int getAKodekNum(Glib::ustring);
};

#endif /* KONTAINER_H_ */
