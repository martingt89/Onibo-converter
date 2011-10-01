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

#include "grafika/Okno.h"
#include <glibmm/thread.h>
#include <glibmm/ustring.h>
#include <iostream>
int main (int argc, char **argv)
{
	Glib::thread_init();
	Gtk::Main kit(argc, argv);

	Glib::ustring ces = argv[0];
	Glib::ustring::size_type vzd = ces.rfind("/");
	ces = Glib::ustring(ces.c_str(), ces.c_str()+vzd);
	int a = chdir(ces.c_str());
	if(a != 0){
		std::cerr<<"ERROR chdir: "<<a<<std::endl;
	}
	Okno *Hl = new Okno();
	delete Hl;
  	return 0;
}
