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

#include "Save_profil.h"

Save_profil::Save_profil() {
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
}

Save_profil::~Save_profil() {
	// TODO Auto-generated destructor stub
}
void Save_profil::Basic(Glib::ustring con, Glib::ustring vid, Glib::ustring aud){
	data[2] = con; data[3] = vid; data[4] = aud;
}
void Save_profil::Video(Glib::ustring vCod, Glib::ustring vBit, Glib::ustring vFrame,
		Glib::ustring vRes,Glib::ustring vX,Glib::ustring vY, Glib::ustring x264){
	VideoPrekladac vvv;
	data[5] = vvv.getVideoKodek(vCod).getKodek();
	data[6] = vBit; data[7] = vFrame; data[8]= vRes;
	data[9] = vX; data[10] = vY; data[11] = x264;
}
void Save_profil::Audio(Glib::ustring aCod, Glib::ustring aCha, Glib::ustring aBit, Glib::ustring aRat){
	AudioPrekladac aaa;
	data[12]= aaa.getAudioKodek(aCod)->getKodek();
	data[13] = aCha; data[14] = aBit; data[15] = aRat;
}
void Save_profil::Save(Glib::ustring typ, Glib::ustring name){
	data[0] = typ;	data[1] = name;
	Check_config_dir inpor;
	int cis = rand ();
	cis = cis % 1000000;
	std::fstream nev;
	//Doplnky dop;
	Glib::ustring ces = inpor.getCDirectory()+"/"+typ+"_"+name+"_"+Glib::ustring::format(cis);
	nev.open(ces.c_str(), std::fstream::out);
	for(unsigned int i = 0; i<16; i++){
		nev<<slova[i]+"=\""+data[i]+"\""<<std::endl;
	}
	nev.close();
	nev.open(inpor.getCFile().c_str(), std::fstream::out | std::fstream::app);
	nev<<ces<<std::endl;
	nev.close();
}
