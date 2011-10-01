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

#ifndef SAVE_PROFIL_H_
#define SAVE_PROFIL_H_
#include "Zberac.h"
#include "Check_config_dir.h"
#include "../video/VideoPrekladac.h"
#include "../video/AudioPrekladac.h"
#include <fstream>
#include <glibmm/ustring.h>
#include <cstdlib>
class Save_profil {
private:
	Glib::ustring slova[16];
	Glib::ustring data[16];
public:
	Save_profil();
	virtual ~Save_profil();
	void Save(Glib::ustring, Glib::ustring);
	void Basic(Glib::ustring con, Glib::ustring vid, Glib::ustring aud);
	void Video(Glib::ustring vCod, Glib::ustring vBit, Glib::ustring vFrame,
			Glib::ustring vRes,Glib::ustring vX,Glib::ustring vY, Glib::ustring x264);
	void Audio(Glib::ustring aCod, Glib::ustring aCha, Glib::ustring aBit, Glib::ustring aRat);
};

#endif /* SAVE_PROFIL_H_ */
