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

#ifndef AUDIOVORBIS_H_
#define AUDIOVORBIS_H_
#include <glibmm/ustring.h>
#include <list>
#include <cstdlib>
#include "AudioKodeky.h"
class AudioVorbis : public AudioKodeky{
public:
	AudioVorbis();
	virtual ~AudioVorbis();
	Glib::ustring getQuality(Glib::ustring);

};
#endif /* AUDIOVORBIS_H_ */
