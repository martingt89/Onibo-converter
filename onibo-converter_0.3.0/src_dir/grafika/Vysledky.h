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

#ifndef VYSLEDKY_H_
#define VYSLEDKY_H_
#include <glibmm/ustring.h>
#include <vector>
#include <list>
#include <iterator>
class Vysledky {
private:
	std::vector<Glib::ustring> mena;
	std::vector<Glib::ustring> stavy;
public:
	Vysledky();
	virtual ~Vysledky();
	void set(Glib::ustring, int);
	void setStop(std::list<Glib::ustring>);
	Glib::ustring getSprava();
	void restart();
};

#endif /* VYSLEDKY_H_ */
