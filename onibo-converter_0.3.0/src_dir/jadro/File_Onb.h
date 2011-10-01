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

#ifndef FILE_ONB_H_
#define FILE_ONB_H_
#include <glibmm/ustring.h>
#include <sys/stat.h>

class File_Onb{
private:
	struct stat st;
	int exist;
public:
	File_Onb();
	virtual ~File_Onb();
	void set(Glib::ustring ces);
	bool getFile();
	void setHmm(Glib::ustring ces, Glib::ustring ces2, Glib::ustring prip);
	bool getDirectory();
	bool getExist();
};
#endif /* FILE_ONB_H_ */
