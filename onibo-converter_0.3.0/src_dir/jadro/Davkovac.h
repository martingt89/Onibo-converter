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

#ifndef DAVKOVAC_H_
#define DAVKOVAC_H_
#include <gtkmm/treeiter.h>
#include <glibmm/ustring.h>
#include "../video/Information.h"
class Davkovac {
	std::list<Glib::ustring> abort_m;
	std::list<Information> filtre;
	std::list<Information>::iterator it_fil;
	bool set;
	int i;
	int pocet;
public:
	Davkovac();
	virtual ~Davkovac();
	void setListInfo(std::list<Information>);
	Information* getNextInfo();
	void setEnd();
	int getKtory();
	int getPocet();
	void back();
	void refresh();
	std::list<Glib::ustring> getAbort();
};

#endif /* DAVKOVAC_H_ */
