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

#ifndef PROFIL_H_
#define PROFIL_H_
#include <glibmm/ustring.h>

class Profil {
private:
	Glib::ustring subor;
	Glib::ustring meno;
	Glib::ustring typ;
	int kodekV;
	int pomer;
	Glib::ustring resolX;
	Glib::ustring resolY;
	int kontainer;
	Glib::ustring bitrateV;
	int nastav;
	int framerate;
	int x264;
	//audio
	int kodekA;
	int nastavA;
	int channelA;
	int frekvenciaA;
	Glib::ustring bitrateA;
public:
	Profil(Glib::ustring typ, Glib::ustring men, int kon, int kod,
			Glib::ustring bit, int nas, int pom, Glib::ustring x, Glib::ustring y,
			int fra, int x26, int akod, int anas, int chan, int frek,
			Glib::ustring bitA, Glib::ustring sub);
	virtual ~Profil();
	Glib::ustring getSub(){return subor;}

	Glib::ustring getTyp(){return typ;}
	Glib::ustring getX(){return resolX;}
	Glib::ustring getY(){return resolY;}
	Glib::ustring getMeno(){return meno;}
	int getKontainer(){return kontainer;}
	int getKodek(){return kodekV;}
	Glib::ustring getBitrateV(){return bitrateV;}
	int getNastav(){return nastav;}
	int getPomer(){return pomer;}
	int getFramerate(){return framerate;}
	int getX264(){return x264;}
	//
	int getKodekA();
	int getNastavA();
	int getChannel();
	int getFrekvencia();
	Glib::ustring getBitrateA();
};
#endif /* PROFIL_H_ */
