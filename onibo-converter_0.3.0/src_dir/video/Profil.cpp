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

#include "Profil.h"
Profil::Profil(Glib::ustring typ, Glib::ustring men, int kon, int kod,
		Glib::ustring bit, int nas, int pom, Glib::ustring x, Glib::ustring y,
		int fra, int x26, int akod, int anas, int chan, int frek,
		Glib::ustring bitA, Glib::ustring sub) {
	subor = sub;
	this->typ = typ;
	nastav = nas;
	meno = men;
	resolX = x;
	resolY = y;
	pomer = pom;
	kontainer = kon;
	kodekV = kod;
	bitrateV = bit;
	framerate = fra;
	x264 = x26;
	kodekA = akod;
	nastavA = anas;
	channelA = chan;
	frekvenciaA = frek;
	bitrateA = bitA;
}

Profil::~Profil() {
}
int Profil::getKodekA() {
	return kodekA;
}
int Profil::getNastavA() {
	return nastavA;
}
int Profil::getChannel() {
	return channelA;
}
int Profil::getFrekvencia() {
	return frekvenciaA;
}
Glib::ustring Profil::getBitrateA() {
	return bitrateA;
}
