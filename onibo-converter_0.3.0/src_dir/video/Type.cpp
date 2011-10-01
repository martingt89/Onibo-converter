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

#include "Type.h"
//#include <iostream>
Type::Type(Glib::ustring ty, Glib::ustring nam) {
	typ= ty;
	name.push_back(nam);
}

Type::~Type() {
	// TODO Auto-generated destructor stub
}
int Type::addMember(Glib::ustring ty, Glib::ustring nam){
	if(ty.compare(typ) != 0){
		return -1;
	}
	std::list<Glib::ustring>::iterator it;
	for(it = name.begin() ; it!= name.end(); it++){
		if(it->compare(nam) == 0){
			return 0;
		}
	}
	name.push_back(nam);
	return 0;
}
Glib::ustring Type::getName(){
	return typ;
}
std::list<Glib::ustring> Type::getList(Glib::ustring ty){
	if(ty.compare(typ) == 0){
		return name;
	}
	std::list<Glib::ustring> empty;
	return empty;
}
std::list<Glib::ustring> Type::getList(){
	return name;
}
