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

#include "Analyza.h"
#include <iostream>

Analyza::Analyza(Glib::ustring in) {
	duration = -1;
	int cp[2]; /* Child to parent pipe */
	int pid;
	int assd;
	char ch;
	int ex;
	res_x = 0;
	res_y = 0;
	Glib::ustring ias321 = " -i";
	Glib::ustring command = FFMPEG + ias321 +" \""+in+"\"";
	if (!(pipe(cp) < 0)) {
		switch (pid = fork()) {
		case -1:
			abort(); //internal error
		case 0: /* Child. */
			close(2); /* Close current stderr. */
			ex = dup(cp[1]); /* Make stderr go to write end of pipe. */
			close(cp[0]);
			assd = system(command.c_str());
			close(cp[1]);
			abort(); //exit proces
		default:
			close(cp[1]);
			Glib::ustring riadok = "";
			while (read(cp[0], &ch, sizeof(char)) == 1) {
				if (ch == '\r' || ch == '\n') {
					decode(riadok);
					riadok = "";
				} else {
					riadok = riadok + ch;
				}
			}
			close(cp[0]);
			wait(NULL); //wait for close child proces
		}
	}
}

Analyza::~Analyza() {

}
void Analyza::decode(Glib::ustring ria){
	if (ria.size() != 0) {
		const char * pch = strstr(ria.c_str(), "Duration:");
		if (pch != NULL) {
			int hod = 0;
			int min = 0;
			int sek = 0;
			int mil = 0;
			hod = atoi(pch + 10);
			min = atoi(pch + 13);
			sek = atoi(pch + 16);
			mil = atoi(pch + 19);
			duration = sek + min * 60 + hod * 3600 + mil/100.0;
		}
		const char * vid = strstr(ria.c_str(), "Video: ");
		if(vid != NULL){
			Glib::ustring::size_type par = ria.find("PAR");
			if(par>0){
				Glib::ustring vysek = Glib::ustring(vid+6, ria.c_str()+par);
				Glib::ustring::size_type y = vysek.rfind("x");
				res_y = atoi(vysek.c_str()+y+1);
				vysek = Glib::ustring(vysek.c_str(), vysek.c_str()+y);
				Glib::ustring::size_type x = vysek.rfind(" ");
				res_x = atoi(vysek.c_str()+x+1);
			}
		}
	}
}
double Analyza::getDuration(){
	return duration;
}
int Analyza::getX(){
	return res_x;
}
int Analyza::getY(){
	return res_y;
}
