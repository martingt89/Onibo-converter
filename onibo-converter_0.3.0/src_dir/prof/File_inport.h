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

#ifndef FILE_INPORT_H_
#define FILE_INPORT_H_
#include <fstream>
#include <glibmm/ustring.h>
#include "Check_config_dir.h"
#include "File_load.h"
#include "../makros.h"
class File_inport {
private:
	Glib::ustring confDir;
	Glib::ustring confFile;
public:
	File_inport();
	virtual ~File_inport();
	int inport(Glib::ustring);
};

#endif /* FILE_INPORT_H_ */
