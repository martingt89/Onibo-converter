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

#ifndef UDAJE_H_
#define UDAJE_H_
#include <glibmm/ustring.h>
#include <list>
#include "../makros.h"
class Udaje {
private:
	std::list<Glib::ustring> vOptions;
	std::list<Glib::ustring> vFrame;
	std::list<Glib::ustring> vBitrate;
	std::list<Glib::ustring> vResolution;
	std::list<Glib::ustring> vX;
	std::list<Glib::ustring> vY;
	//
	std::list<Glib::ustring> aOptions;
	std::list<Glib::ustring> aChannels;
	std::list<Glib::ustring> aVzorkovanie;
	std::list<Glib::ustring> empty;

	bool clr;
public:
	Udaje();
	virtual ~Udaje();
	void setEmpty(int i){
		if(i!=-1){
			clr=true;
		}else{
			clr=false;
		}
	}
	std::list<Glib::ustring> getAOptions();
	std::list<Glib::ustring> getAChannels();
	std::list<Glib::ustring> getAVzorkovanie();
	std::list<Glib::ustring> geVOptions();
	std::list<Glib::ustring> getVBitrate();
	std::list<Glib::ustring> getVFrame();
	std::list<Glib::ustring> getVResolution();
	std::list<Glib::ustring> getVX();
	std::list<Glib::ustring> getVY();

	int getAOptions(Glib::ustring);
	int getAChannels(Glib::ustring);
	int getAVzorkovanie(Glib::ustring);
	int getVOptions(Glib::ustring);
	int getVFrame(Glib::ustring);
	int getVResolution(Glib::ustring);
};

#endif /* UDAJE_H_ */
