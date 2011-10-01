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

#include "Davkovac.h"
#include <iostream>
Davkovac::Davkovac() {
	// TODO Auto-generated constructor stub
	i=0;
	pocet = 0;
	set = false;
}

Davkovac::~Davkovac() {
	// TODO Auto-generated destructor stub
}
void Davkovac::setListInfo(std::list<Information> fil){
	set = true;
	filtre = fil;

	it_fil = filtre.begin();
	i = 0;
	pocet = filtre.size();
}
int Davkovac::getPocet(){
	return pocet;
}
Information* Davkovac::getNextInfo(){
	if(it_fil != filtre.end()){
		Information *akt_filter;
		akt_filter = &(*it_fil);
		it_fil++;
		i++;
		return akt_filter;
	}
	return NULL;
}
void Davkovac::setEnd(){
	if(set){
		for(; it_fil!= filtre.end(); it_fil++){
			abort_m.push_back(it_fil->getName());
		}
		it_fil = filtre.end();
	}
}
int Davkovac::getKtory(){
	return i;
}
void Davkovac::back(){
	i--;
	it_fil--;
}
std::list<Glib::ustring> Davkovac::getAbort(){
	std::list<Glib::ustring> ab = abort_m;
	abort_m.clear();
	return ab;
}
void Davkovac::refresh(){
	set = true;
	it_fil = filtre.begin();
	i = 0;
	pocet = filtre.size();
}
