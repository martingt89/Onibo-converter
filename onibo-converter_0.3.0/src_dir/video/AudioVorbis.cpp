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

#include "AudioVorbis.h"

AudioVorbis::AudioVorbis() {
	//AudioKodeky::AudioKodeky(meno, kodek);
	//AudioKodeky(meno, kodek);
}

AudioVorbis::~AudioVorbis() {
	// TODO Auto-generated destructor stub
}

Glib::ustring AudioVorbis::getQuality(Glib::ustring u){
	int zoz[11];
	zoz[0] = 64;
	zoz[1] = 80;
	zoz[2] = 96;
	zoz[3] = 112;
	zoz[4] = 128;
	zoz[5] = 160;
	zoz[6] = 192;
	zoz[7] = 224;
	zoz[8] = 256;
	zoz[9] = 320;
	zoz[10] = 500;
	int dostal = atoi(u.c_str());
	int najmenej = -1;
	najmenej = dostal - zoz[0];
	if(najmenej<0)
		najmenej*=-1;
	
	
	int medzera;

	Glib::ustring vys = "0";
	for(unsigned int i = 0; i!=11; i++){
		zoz[i]<dostal?medzera = dostal-zoz[i]:medzera = dostal+zoz[i];
		
		if(najmenej > medzera){
			najmenej = medzera;
			//Doplnky dop;
			vys = Glib::ustring::format(i+1);
		}
	}
	return vys;
}
