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

#include "VideoPrekladac.h"
#include "BasicKon.h"
//#include <iostream>
VideoPrekladac::VideoPrekladac() {
	numCPU = sysconf( _SC_NPROCESSORS_ONLN );
	VideoKodeky mpeg4(MPEG4, "mpeg4");
	zoznam.push_back(mpeg4);
	VideoKodeky mpeg2(MPEG2, "mpeg2video");
	zoznam.push_back(mpeg2);
	VideoKodeky x264(X264, "libx264");
	x.push_back("normal");
	x.push_back("veryfast");
	x.push_back("fast");
	x.push_back("medium");
	x.push_back("slow");
	x.push_back("veryslow");
	x.push_back("hq");
	x.push_back("ipod320");
	x.push_back("ipod640");
	x264.setX264(x);
	zoznam.push_back(x264);
	VideoKodeky mpeg1(MPEG1, "mpeg1video");
	zoznam.push_back(mpeg1);
	VideoKodeky xvid(XVID, "libxvid");
	zoznam.push_back(xvid);
	VideoKodeky wmv(WMV, "wmv2");
	zoznam.push_back(wmv);
	VideoKodeky theora(THEORA, "libtheora");
	zoznam.push_back(theora);
}

VideoPrekladac::~VideoPrekladac() {
	// TODO Auto-generated destructor stub
}
VideoKodeky VideoPrekladac::getVideoKodek(Glib::ustring meno) {
	for (unsigned int i = 0; i < zoznam.size(); i++) {
		if (strcmp(zoznam[i].getMeno().c_str(), meno.c_str()) == 0) {
			return zoznam[i];
		}
	}
	return zoznam[0]; //snad sa nic nepokazi, keby som odovzdaval adresy bolo by to lahsie...
}
std::list<Glib::ustring> VideoPrekladac::preloz(Glib::ustring kontajner,
		Glib::ustring kodek, Glib::ustring videoMod, Glib::ustring pomer,
		Glib::ustring x, Glib::ustring y, Glib::ustring bit,
		Glib::ustring frame, Glib::ustring x264) {
	std::list<Glib::ustring> prikaz;
	if (videoMod.compare(NOVIDEO) == 0 || videoMod.compare("-1") == 0) {
		prikaz.push_back("-vn");
	} else {
		if (videoMod.compare(COPYVIDEO) == 0) {
			prikaz.push_back("-vcodec");
			prikaz.push_back("copy");
		} else {
			prikaz.push_back("-vcodec");
			prikaz.push_back((this->getVideoKodek(kodek)).getKodek());
			if(strcmp(x264.c_str(), "-1") != 0){
				//Doplnky dop;
				prikaz.push_back("-fpre");
				prikaz.push_back("ffmpeg/ffpresets/"+x264+".ffpreset");
				prikaz.push_back("-threads");
				prikaz.push_back(Glib::ustring::format(numCPU));
			}
			prikaz.push_back("-b");
			prikaz.push_back(bit + "k");
			if (pomer.compare(ORIGINALRESOL) != 0) {
				prikaz.push_back("-s");
				prikaz.push_back(x + "x" + y);
//				std::cout<<x<<" "<<y<<std::endl;
			}
			if (frame.compare(COPYFRAMERATE) != 0) {
				prikaz.push_back("-r");
				prikaz.push_back(frame);
			}
		}
	}
	return prikaz;
}
int VideoPrekladac::getX264Num(Glib::ustring u){
	int i= 0;
	std::list<Glib::ustring>::iterator it;
	for(it = x.begin(); it!=x.end(); it++){
		if(it->compare(u) == 0){
			return i;
		}
		i++;
	}
	return -1;
}
Glib::ustring VideoPrekladac::getByKodek(Glib::ustring kod){
	for(unsigned int i = 0; i<zoznam.size(); i++){
		if(kod.compare(zoznam[i].getKodek())==0){
			return zoznam[i].getMeno();
		}
	}
	return "-1";
}
