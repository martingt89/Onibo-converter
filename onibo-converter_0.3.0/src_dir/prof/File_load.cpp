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

#include "File_load.h"
//#include <iostream>

File_load::File_load(Glib::ustring cesta) {
	OK = false;
	slova[0] = "type";
	slova[1] = "name";
	slova[2] = "container";
	slova[3] = "video";
	slova[4] = "audio";
	slova[5] = "vcodec";
	slova[6] = "vbitrate";
	slova[7] = "framerate";
	slova[8] = "resolution";
	slova[9] = "resx";
	slova[10] = "resy";
	slova[11] = "x264";
	slova[12] = "acodec";
	slova[13] = "channels";
	slova[14] = "abitrate";
	slova[15] = "rate";
	subor.open(cesta.c_str(), std::ifstream::in);
	while (subor.good()) {
		OK = true;
		std::string str;
		getline(subor, str);
		char ch[1];
		std::string::iterator it;
		for(it = str.begin(); it!= str.end(); it++){
			if(*it!=' '&&*it!='\t')break;
		}
		std::string orez = std::string(it, str.end());
//		std::cout<<orez<<std::endl;
		orez.copy(ch,1,0);
		if (ch[0] != '#') {
			size_t first;
			size_t last;
			last = str.rfind('"');
			first = str.find('"');
			for (unsigned int i = 0; i < 16; i++) {
				size_t found;
				found=str.find(slova[i]);
				if(found != std::string::npos && first != std::string::npos && found<first){
					Glib::ustring moj = Glib::ustring(str.c_str()+first+1, str.c_str()+last);
					spracuj[i] = moj;
					break;
				}
			}
		}
	}
}

File_load::~File_load() {
	subor.close();
}
bool File_load::isOK(){
	return OK;
}
