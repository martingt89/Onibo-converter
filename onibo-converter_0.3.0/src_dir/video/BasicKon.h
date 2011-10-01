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

#ifndef BASICKON_H_
#define BASICKON_H_

#define KONTAINERY 11
#include "Kontainer.h"
#include <glibmm/ustring.h>
class BasicKon {
private:
	Kontainer* zoznam[KONTAINERY];
	std::list<Glib::ustring> poMenach;

public:
	BasicKon();
	virtual ~BasicKon();
	std::list<Glib::ustring> getKontainery();
	Kontainer* getKontainer(int i);
	int getNumber(Glib::ustring);
};

#endif /* BASICKON_H_ */
