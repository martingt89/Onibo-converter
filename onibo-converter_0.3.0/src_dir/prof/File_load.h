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

#ifndef FILE_LOAD_H_
#define FILE_LOAD_H_
#include <fstream>
#include <glibmm/ustring.h>
#include <string>
#include <cstdlib>
#include <algorithm>
typedef Glib::ustring retazec;
class File_load {
private:
	std::ifstream subor;
	retazec spracuj[16];
	retazec slova[16];
	bool OK;
public:
	File_load(Glib::ustring);
	virtual ~File_load();
	Glib::ustring getType(){return spracuj[0];}
	Glib::ustring getName(){return spracuj[1];}
	Glib::ustring getContainer(){return spracuj[2];}
	Glib::ustring getVideo(){return spracuj[3];}
	Glib::ustring getAudio(){return spracuj[4];}
	Glib::ustring getVCodec(){return spracuj[5];}
	Glib::ustring getVBitrate(){return spracuj[6];}
	Glib::ustring getFramerate(){return spracuj[7];}
	Glib::ustring getResolution(){return spracuj[8];}
	Glib::ustring getResX(){return spracuj[9];}
	Glib::ustring getResY(){return spracuj[10];}
	Glib::ustring getX264(){return spracuj[11];}
	Glib::ustring getAcodec(){return spracuj[12];}
	Glib::ustring getChannels(){return spracuj[13];}
	Glib::ustring getAbitrate(){return spracuj[14];}
	Glib::ustring getRate(){return spracuj[15];}
	bool isOK();
};

#endif /* FILE_LOAD_H_ */
