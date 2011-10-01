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

#ifndef ZBERAC_H_
#define ZBERAC_H_
#include <glibmm/ustring.h>
class Zberac {
public:
	Glib::ustring file;
	Glib::ustring typ;		//
	Glib::ustring meno;		//
	int kodekV;				//
	int pomer;				//
	Glib::ustring resolX;	//
	Glib::ustring resolY;	//
	int kontainer;			//
	Glib::ustring bitrateV;	//
	int nastav;				//
	int framerate;			//
	int x264;				//
	int kodekA;				//
	int nastavA;			//
	int channelA;			//
	int frekvenciaA;		//
	Glib::ustring bitrateA;	//
	Zberac();
	virtual ~Zberac();
};

#endif /* ZBERAC_H_ */
