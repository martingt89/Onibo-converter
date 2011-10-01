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

#include "File_inport.h"
//#include <iostream>

File_inport::File_inport() {
	Check_config_dir con;
	confDir = con.getCDirectory();
	confFile = con.getCFile();
}

File_inport::~File_inport() {
	// TODO Auto-generated destructor stub
}
int File_inport::inport(Glib::ustring file) {
	//convert adress to file name
	int poz = file.rfind("/");
	Glib::ustring subor = Glib::ustring(file.c_str()+poz);
	File_load fil(file);
	if(fil.getType().compare(CUSTOMVIDEO)==0){
		return 1;
	}

	std::fstream vys;
	vys.open((confDir+subor).c_str(), std::fstream::in);
	if(vys.good()){
//		std::cout<<"exist"<<std::endl;
		return -1;
	}
	Glib::ustring command = "cp -n \"" + file + "\" " + confDir;
	if(system(command.c_str())!=0){
		return -2;
	}
	vys.close();
	vys.open(confFile.c_str(), std::fstream::out | std::fstream::app);
	vys<<confDir+subor<<std::endl;
	vys.close();
	return 0;
}
