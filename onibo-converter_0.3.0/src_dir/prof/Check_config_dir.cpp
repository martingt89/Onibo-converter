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

#include "Check_config_dir.h"
#include <iostream>

Check_config_dir::Check_config_dir() {
	direct = "/onibo-converter";
	confDirectory = Glib::get_user_config_dir ()+"/onibo-converter";	// home/x/.config + /onibo-converter
	confFile = Glib::get_user_config_dir ()+"/onibo-converter/profiles";
}

Check_config_dir::~Check_config_dir() {
	// TODO Auto-generated destructor stub
}
int Check_config_dir::readProfils(bool st){
	std::vector<Glib::ustring> subo;
	subo.push_back("nokia5530");
//	subo.push_back("next default");
	
	file_test.set(confDirectory);
	int stat = 0;
	if(file_test.getDirectory() == false){
		if(system(("mkdir "+confDirectory).c_str()) != 0){
			std::cerr<<"ERROR, Check_config_dir, system mkdir"<<std::endl;
			stat = 1;
		}
	}

	Glib::ustring command = "cd "+ confDirectory;

	if(system(command.c_str())!= 0){
		std::cerr<<"ERROR, Check_config_dir, system cp"<<std::endl;
		stat = 2;
	}
	
	std::fstream profils;

	profils.open (confFile.c_str(), std::fstream::in);
	int exist = 0;
	while (profils.good()) {
		exist++;
		std::string str;
		getline(profils, str);
		files.push_back(str);
	}
	profils.close();
	if(exist < 2){
		profils.open (confFile.c_str(), std::fstream::out | std::fstream::app);
		for(unsigned int i = 0; i<subo.size(); i++){
			profils<<Glib::get_user_config_dir ()+"/onibo-converter/"+subo[i]<<std::endl;
		}
		profils.close();
		Glib::ustring cp;
		cp = "cp "+Glib::get_current_dir ()+"/profils";
		for(unsigned int i = 0; i<subo.size(); i++){
			int a = system ((cp+"/"+subo[i]+ " " + Glib::get_user_config_dir ()+"/onibo-converter/"+subo[i]).c_str());
			if(a != 0){
				stat = 3;
				std::cerr<<"ERROR, Check_config_dir, system cp: "<<a<<std::endl;
			}
		}
		if(st != true){
			this->readProfils(true);
		}
	}
	return stat;
}
