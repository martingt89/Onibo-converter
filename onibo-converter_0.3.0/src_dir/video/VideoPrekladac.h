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

#ifndef VIDEOPREKLADAC_H_
#define VIDEOPREKLADAC_H_
#include "VideoKodeky.h"
#include "../makros.h"
#include <vector>
#include <unistd.h>
#include <cstring>

class VideoPrekladac {
private:
	std::list<Glib::ustring> x;
	std::vector<VideoKodeky> zoznam;
	int numCPU;
public:
	VideoPrekladac();
	virtual ~VideoPrekladac();
	VideoKodeky getVideoKodek(Glib::ustring);
	std::list<Glib::ustring> preloz(Glib::ustring kontajner,
			Glib::ustring kodek, Glib::ustring videoMod, Glib::ustring pomer,
			Glib::ustring x, Glib::ustring y, Glib::ustring bit,
			Glib::ustring frame, Glib::ustring x264);
	int getX264Num(Glib::ustring);
	Glib::ustring getByKodek(Glib::ustring);
};

#endif /* VIDEOPREKLADAC_H_ */
