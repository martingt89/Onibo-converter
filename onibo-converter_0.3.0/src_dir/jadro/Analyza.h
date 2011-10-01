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

#ifndef ANALYZA_H_
#define ANALYZA_H_
#include <glibmm/ustring.h>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>
#include "../makros.h"
class Analyza {
	double duration;
	int res_x;
	int res_y;
public:
	Analyza(Glib::ustring in);
	virtual ~Analyza();
	void decode(Glib::ustring ria);
	double getDuration();
	int getX();
	int getY();
};

#endif /* ANALYZA_H_ */
