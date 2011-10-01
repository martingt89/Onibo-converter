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
#ifndef GUI_ONB_H
#define GUI_ONB_H
#include <glibmm/ustring.h>

class GUI_onb{
public:
Glib::ustring kontainer;
Glib::ustring vKodek;
Glib::ustring vOptions;
Glib::ustring vPomer;
Glib::ustring vX;
Glib::ustring vY;
Glib::ustring vBitrate;
Glib::ustring vFrame;
Glib::ustring x264;
Glib::ustring aKodek;
Glib::ustring aOptions;
Glib::ustring aBitrate;
Glib::ustring aFrekvenci;
Glib::ustring aChannels;
//
Glib::ustring vystupFol;

void set(Glib::ustring kontainer, Glib::ustring vKodek, Glib::ustring vOptions, Glib::ustring vPomer, Glib::ustring vX, Glib::ustring vY,
	Glib::ustring vBitrate, Glib::ustring vFrame, Glib::ustring x264, Glib::ustring aKodek, Glib::ustring aOptions, Glib::ustring aBitrate,
	Glib::ustring aFrekvenci, Glib::ustring aChannels, Glib::ustring vystupFol){
	this->kontainer = kontainer;
	this->vKodek = vKodek;
	this->vOptions = vOptions;
	this->vPomer = vPomer;
	this->vX = vX;
	this->vY = vY;
	this->vBitrate = vBitrate;
	this->vFrame = vFrame;
	this->x264 = x264;
	this->aKodek = aKodek;
	this->aOptions = aOptions;
	this->aBitrate = aBitrate;
	this->aFrekvenci = aFrekvenci;
	this->aChannels = aChannels;
	this->vystupFol = vystupFol;
}
};
#endif
