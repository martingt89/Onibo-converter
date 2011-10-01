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

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <glibmm/ustring.h>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "../grafika/GUI.h"
#include "../makros.h"
#include "../video/Information.h"
#include "../video/AudioPrekladac.h"
#include "../video/VideoPrekladac.h"
class Generator {
	GUI_onb gui;
	Glib::ustring vstup;
	Glib::ustring vystup;
	Information *inform;
	AudioPrekladac aud;
	VideoPrekladac vid;
public:
	Generator(GUI_onb, Information*);
	virtual ~Generator();
	Glib::ustring run();
};

#endif /* GENERATOR_H_ */
