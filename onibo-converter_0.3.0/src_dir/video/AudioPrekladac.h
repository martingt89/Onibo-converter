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

#ifndef AUDIOPREKLADAC_H_
#define AUDIOPREKLADAC_H_
#include "AudioKodeky.h"
#include "BasicKon.h"
#include "AudioVorbis.h"
#include "../makros.h"
#include <vector>
#include <cstdlib>

class AudioPrekladac {
	std::vector<AudioKodeky*> zoznam;
public:
	AudioPrekladac();
	virtual ~AudioPrekladac();
	AudioKodeky* getAudioKodek(Glib::ustring);
	std::list<Glib::ustring> preloz(Glib::ustring kodek, Glib::ustring opt,
			Glib::ustring bitrate, Glib::ustring vzorkovanie,
			Glib::ustring kanal);
	Glib::ustring getByKodek(Glib::ustring);
};

#endif /* AUDIOPREKLADAC_H_ */
