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

#include "Doplnky.h"

Doplnky::Doplnky() {
	// TODO Auto-generated constructor stub

}

Doplnky::~Doplnky() {
	// TODO Auto-generated destructor stub
}
//Glib::ustring Doplnky::doubleToUstring(double i){
//	Glib::ustring stra;
//	std::stringstream strstream;
//	strstream << i;
//	strstream >> stra;
//	return stra;
//}

Glib::ustring Doplnky::XtoY(Glib::ustring x, Glib::ustring y, Glib::ustring mod){
	int X = atoi(x.c_str());
	int Y = atoi(y.c_str());
	if(mod.compare(VIDEORESOLUTION43)==0){
		return Glib::ustring::format((int)(X/4.0)*3);
	}
	if(mod.compare(VIDEORESOLUTION169)==0){
		return Glib::ustring::format((int)(X/16.0)*9);
	}
	return Glib::ustring::format(Y);
}
Glib::ustring Doplnky::YtoX(Glib::ustring x, Glib::ustring y, Glib::ustring mod){
	int X = atoi(x.c_str());
	int Y = atoi(y.c_str());
	if(mod.compare(VIDEORESOLUTION43)==0){
		return Glib::ustring::format((int)(Y/3.0)*4);
	}
	if(mod.compare(VIDEORESOLUTION169)==0){
		return Glib::ustring::format((int)(Y/9.0)*16);
	}
	return Glib::ustring::format(X);
}
