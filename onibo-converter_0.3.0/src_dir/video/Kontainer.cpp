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

#include "Kontainer.h"
//#include <iostream>
Kontainer::Kontainer(Glib::ustring meno, Glib::ustring link) {
	this->meno = meno;
	this->cesta = link;
}
Kontainer::~Kontainer() {
	// TODO Auto-generated destructor stub
}
Glib::ustring Kontainer::getMeno() {
	return meno;
}
std::list<Glib::ustring> Kontainer::getVKodeky() {
	return v_kodeky;
}
Glib::ustring Kontainer::getCesta() {
	return cesta;
}
std::list<Glib::ustring> Kontainer::getAKodeky() {
	return a_kodeky;
}
void Kontainer::addVKodek(Glib::ustring u){
	v_kodeky.push_back(u);
}
void Kontainer::addAKodek(Glib::ustring u){
	a_kodeky.push_back(u);
}
int Kontainer::getVKodekNum(Glib::ustring u){
	std::list<Glib::ustring>::iterator it;
	int i=0;
	for(it=v_kodeky.begin(); it!=v_kodeky.end(); it++){
//		std::cout<<u<<" "<<*it<<std::endl;
		if(it->compare(u)==0){

			return i;
		}
		i++;
	}
	return -1;
}
int Kontainer::getAKodekNum(Glib::ustring u){
	std::list<Glib::ustring>::iterator it;
	int i=0;
	for(it=a_kodeky.begin(); it!=a_kodeky.end(); it++){
		if(it->compare(u)==0){
			return i;
		}
		i++;
	}
	return -1;
}
