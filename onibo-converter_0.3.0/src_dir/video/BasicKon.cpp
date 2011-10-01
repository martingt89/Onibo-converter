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

#include "BasicKon.h"

BasicKon::BasicKon() {
	Kontainer *gp3 = new Kontainer("3gp", "images/img3gp.png");
	gp3->addVKodek(MPEG4);gp3->addVKodek(MPEG2);gp3->addVKodek(X264);
	gp3->addAKodek(MP3);gp3->addAKodek(AAC);
	zoznam[0] = gp3;

	Kontainer *avi = new Kontainer("avi", "images/imgavi.png");
	avi->addVKodek(MPEG4);avi->addVKodek(X264);avi->addVKodek(XVID);
	avi->addVKodek(MPEG2);avi->addVKodek(WMV);
	avi->addAKodek(MP3);avi->addAKodek(AC3);avi->addAKodek(WMA);
	avi->addAKodek(MP2);
	zoznam[1] = avi;

	Kontainer *flv = new Kontainer("flv", "images/imgflv.png");
	flv->addVKodek(X264);
	flv->addAKodek(AAC);flv->addAKodek(MP3);
	zoznam[2] = flv;

	Kontainer *mkv = new Kontainer("mkv", "images/imgmkv.png");
	mkv->addVKodek(THEORA);mkv->addVKodek(X264);mkv->addVKodek(MPEG4);
	mkv->addVKodek(MPEG2);mkv->addVKodek(XVID);
	mkv->addAKodek(VORBIS);mkv->addAKodek(MP3);mkv->addAKodek(AAC);
	mkv->addAKodek(AC3);mkv->addAKodek(MP2);
	zoznam[3] = mkv;

	Kontainer *mov = new Kontainer("mov", "images/imgmov.png");
	mov->addVKodek(X264);mov->addVKodek(MPEG4);mov->addVKodek(MPEG2);
	mov->addAKodek(MP3);mov->addAKodek(AAC);mov->addAKodek(AC3);mov->addAKodek(MP2);
	zoznam[4] = mov;

	Kontainer *mp3 = new Kontainer("mp3", "images/imgmp3.png");
	mp3->addAKodek(MP3);
	zoznam[5] = mp3;

	Kontainer *mp4 = new Kontainer("mp4", "images/imgmp4.png");
	mp4->addVKodek(MPEG4);mp4->addVKodek(X264);
	mp4->addAKodek(AAC);
	zoznam[6] = mp4;

	Kontainer *mpeg = new Kontainer("mpeg", "images/imgmpeg.png");
	mpeg->addVKodek(MPEG2);mpeg->addVKodek(MPEG1);
	mpeg->addAKodek(MP3);mpeg->addAKodek(MP2);
	zoznam[7] = mpeg;

	Kontainer *ogg = new Kontainer("ogg", "images/imgogg.png");
	ogg->addAKodek(VORBIS);ogg->addAKodek(FLAC);
	zoznam[8] = ogg;

	Kontainer *wma = new Kontainer("wma", "images/imgwma.png");
	wma->addAKodek(WMA);
	zoznam[9] = wma;

	Kontainer *wmv = new Kontainer("wmv", "images/imgwmv.png");
	wmv->addVKodek(WMV);
	wmv->addAKodek(WMA);wmv->addAKodek(MP3);
	zoznam[10] = wmv;

	for(unsigned int i=0; i<KONTAINERY; i++){
		poMenach.push_back(zoznam[i]->getMeno());
	}
}

BasicKon::~BasicKon() {
	for(unsigned int i=0; i<KONTAINERY; i++){
		delete zoznam[i];
	}
}
std::list<Glib::ustring> BasicKon::getKontainery(){
	return poMenach;
}
Kontainer* BasicKon::getKontainer(int i){
	return zoznam[i];
}
int BasicKon::getNumber(Glib::ustring name){
	for(int i=0; i<KONTAINERY; i++){
		if(name.compare(zoznam[i]->getMeno())==0){
			return i;
		}
	}
	return -1;
}
