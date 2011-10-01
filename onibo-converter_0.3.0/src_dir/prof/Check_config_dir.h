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

#ifndef CHACK_CONFIG_DIR_H_
#define CHACK_CONFIG_DIR_H_

#include <vector>
#include <glibmm/ustring.h>
#include <gtkmm/main.h>
#include "../jadro/File_Onb.h"

#include <fstream>
class Check_config_dir {
	Glib::ustring direct;
	Glib::ustring confDirectory;
	Glib::ustring confFile;
	std::vector<Glib::ustring> files;
	File_Onb file_test;
public:
	Check_config_dir();
	virtual ~Check_config_dir();
	int readProfils(bool);
	std::vector<Glib::ustring> Files(){return files;}
	Glib::ustring getCFile(){return confFile;}
	Glib::ustring getCDirectory(){return confDirectory;}
};

#endif /* CHACK_CONFIG_DIR_H_ */
