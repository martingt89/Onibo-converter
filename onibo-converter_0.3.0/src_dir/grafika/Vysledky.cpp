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

#include "Vysledky.h"

Vysledky::Vysledky() {
	// TODO Auto-generated constructor stub

}

Vysledky::~Vysledky() {
	// TODO Auto-generated destructor stub
}
void Vysledky::set(Glib::ustring meno, int stat) {
	if (stat != -2) {
		mena.push_back(meno);
		Glib::ustring st;
		switch (stat) {
		case -1: {
			st = "file exist";
			break;
		}
		case 0: {
			st = "OK";
			break;
		}
		case 1: {
			st = "permission denied";
			break;
		}
		case 3: {
			st = "abort";
			break;
		}
		case 4: {
			st = "system error";
			break;
		}
		case 5: {
			st = "unknown format";
			break;
		}
		case 6: {
			st = "folder?";
			break;
		}
		case 7: {
			st = "Output folder doesn't exist";
			break;
		}
		case 10: {
			st = "Unknown error";
			break;
		}
		default: {
			st = "???";
		}
		}
		stavy.push_back(st);
	}
}
void Vysledky::setStop(std::list<Glib::ustring> sub) {
	std::list<Glib::ustring>::iterator it;
	for (it = sub.begin(); it != sub.end(); it++) {
		set(*it, 3);
	}
}
Glib::ustring Vysledky::getSprava() {
	Glib::ustring vys = "";
	for (unsigned int i = 0; i < mena.size(); i++) {
		vys += mena[i] + "    " + stavy[i] + "\n";
	}
	return vys;
}
void Vysledky::restart(){
	mena.clear();
	stavy.clear();
}
