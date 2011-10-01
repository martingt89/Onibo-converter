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

#ifndef INFORMATION_H_
#define INFORMATION_H_
#include <glibmm/ustring.h>
#include "../makros.h"
class Information {
private:
	int yup;
	int ydown;
	int xleft;
	int xright;
	double start_time;
	double end_time;
	bool deinter;
	double duration;
	bool resolution;
	int x;
	int y;
	Glib::ustring name;
	
public:
	Information(Glib::ustring);
	virtual ~Information();
	void set(int yu, int yd, int xl, int xr, double st, double et, bool de, bool re);
	bool getEdit();
	int getYUp();
	int getYdown();
	int getXLeft();
	int getXright();
	double getStart();
	double getEnd();
	bool getDein();
	bool getReso();
	//
	double getDuration();
	int getX();
	int getY();
	void setDuration(double);
	void setResol(int, int);
	Glib::ustring getParametre(Glib::ustring);
	Glib::ustring getName();
};

#endif /* INFORMATION_H_ */
