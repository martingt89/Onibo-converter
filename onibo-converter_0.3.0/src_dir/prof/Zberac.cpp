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

#include "Zberac.h"

Zberac::Zberac() {
	file = "/home/";
	kodekV = 0;				//
	pomer = 0;				//
	resolX = "0";	//
	resolY = "0";	//
	kontainer = 0;			//
	bitrateV = "0";	//
	nastav = 0;				//
	framerate = 0;			//
	x264 = 0;				//
	kodekA = 0;				//
	nastavA = 0;			//
	channelA = 0;			//
	frekvenciaA = 0;		//
	bitrateA = "0";	//
}

Zberac::~Zberac() {
	// TODO Auto-generated destructor stub
}
