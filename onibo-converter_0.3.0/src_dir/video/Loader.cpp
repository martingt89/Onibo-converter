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

#include "Loader.h"
//#include <iostream>
Loader::Loader() {
	this->scanFiles();
}

Loader::~Loader() {
	for (unsigned int i = 0; i < profi.size(); i++) {
		delete profi[i];
	}
}
int Loader::scanFiles(){
	for (unsigned int i = 0; i < profi.size(); i++) {
		delete profi[i];
	}
	profi.clear();
	type.clear();
	typy.clear();
	std::vector<Zberac*> data;
	File_convert file;

	data = file.getZberac();
	for(unsigned int i = 0; i<data.size(); i++){
		profi.push_back(new Profil(data[i]->typ, data[i]->meno, data[i]->kontainer,
				data[i]->kodekV, data[i]->bitrateV, data[i]->nastav, data[i]->pomer,
				data[i]->resolX, data[i]->resolY, data[i]->framerate, data[i]->x264,
				data[i]->kodekA, data[i]->nastavA, data[i]->channelA,
				data[i]->frekvenciaA, data[i]->bitrateA, data[i]->file));
	}

	profi.push_back(new Profil(CUSTOMPROFIL, CUSTOMPROFIL, -1, 0, "0", 0, 0, "0", "0",
			0, 0, 0, 0, 0, 0, "17", "-1")); //natvrdo posledny

	for (unsigned int i = 0; i < profi.size(); i++) {
		bool bol = false;
		for (unsigned int j = 0; j < type.size(); j++) {
			if (type[j]->addMember(profi[i]->getTyp(), profi[i]->getMeno())
					!= -1) {
				bol = true;
			}
		}
		if (bol == false) {
			type.push_back(new Type(profi[i]->getTyp(), profi[i]->getMeno()));
		}
	}
	for (unsigned int i = 0; i < type.size(); i++) {
		typy.push_back(type[i]->getName());
	}
	return 0;
}
std::list<Glib::ustring> Loader::getMena(Glib::ustring typ) {
	std::list<Glib::ustring> nazvy;
	for (unsigned int i = 0; i < type.size(); i++) {
		nazvy = type[i]->getList(typ);
		if (nazvy.size() != 0) {
			return nazvy;
		}
	}
//	std::cout << "hoy2" << std::endl;
	return type[0]->getList();
}

std::list<Glib::ustring> Loader::getTypy() {
	return typy;
}

Profil* Loader::getProfil(Glib::ustring typ, Glib::ustring meno) {
	for(unsigned int i = 0; i< profi.size(); i++){
		if(typ.compare(profi[i]->getTyp())== 0 &&
				meno.compare(profi[i]->getMeno()) == 0){
			return profi[i];
		}
	}
	return profi[0];
}

int Loader::getCustomProfil() {
	return type.size()-1;
}

