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

#include "AudioPrekladac.h"
#include <iostream>

AudioPrekladac::AudioPrekladac() {
	AudioKodeky *mp3 = new AudioKodeky();
	mp3->set(MP3, "libmp3lame");
	mp3->setAuto();
	zoznam.push_back(mp3);

	AudioKodeky *mp2 = new AudioKodeky();
	mp2->set(MP2, "mp2");
	mp2->setAuto();
	zoznam.push_back(mp2);

	AudioKodeky *vorbis = new AudioVorbis();
	vorbis->set(VORBIS, "libvorbis");
	vorbis->setAuto();
	zoznam.push_back(vorbis);

	AudioKodeky *ac3 = new AudioKodeky();
	ac3->set(AC3, "ac3");
	ac3->setAuto();
	zoznam.push_back(ac3);

	AudioKodeky *aac = new AudioKodeky();
	aac->set(AAC, "libfaac");
	aac->setAuto();
	zoznam.push_back(aac);

	AudioKodeky *wma = new AudioKodeky();
	wma->set(WMA, "wmav2");
	wma->setAuto();
	zoznam.push_back(wma);

	AudioKodeky *flac = new AudioKodeky();
	flac->set(FLAC, "flac");
	flac->setAuto();
	zoznam.push_back(flac);
}

AudioPrekladac::~AudioPrekladac() {
	for(unsigned int i = 0; i != zoznam.size(); i++){
		delete zoznam[i];
	}
	// TODO Auto-generated destructor stub
}
AudioKodeky* AudioPrekladac::getAudioKodek(Glib::ustring meno) {
	for (unsigned int i = 0; i < zoznam.size(); i++) {
		if (zoznam[i]->getMeno().compare(meno) == 0) {
			return zoznam[i];
		}
	}
	return NULL; //program drop
}
std::list<Glib::ustring> AudioPrekladac::preloz(Glib::ustring kodek, Glib::ustring opt,
		Glib::ustring bitrate, Glib::ustring vzorkovanie, Glib::ustring kanal) {
	std::list<Glib::ustring> audio;
	std::cout<<opt<<std::endl;
//	std::cout<<"Audio Prekladac 1"<<std::endl;
	int opts = atoi(opt.c_str());
	std::cout<<opts<<std::endl;
	if (opt.compare(NOAUDIO) == 0 || opt.compare("-1") == 0) { //no audio
		audio.push_back("-an");
	}
//	std::cout<<"Audio Prekladac 2"<<std::endl;
	if (opt.compare(COPYAUDIO) == 0) {//original
		audio.push_back("-acodec");
		audio.push_back("copy");
	}
//	std::cout<<"Audio Prekladac 3"<<std::endl;
	if (opt.compare(CUSTOMAUDIO) == 0) { //custom
		audio.push_back("-acodec");
		audio.push_back((this->getAudioKodek(kodek))->getKodek());
		Glib::ustring qua = getAudioKodek(kodek)->getQuality(bitrate);
		if(qua.compare("none")!=0){
			audio.push_back("-aq");
			audio.push_back(qua);
			std::cout<<"-aq "<<qua<<std::endl;
		}else{
			audio.push_back("-ab");
			audio.push_back(bitrate+'k');
		}
		
		if (vzorkovanie.compare(ORIGINALAUDIOVZORK) != 0) {
			audio.push_back("-ar");
			audio.push_back(vzorkovanie);
		}
		if (kanal.compare(AUDIOCHANELSMONO) == 0) {
			audio.push_back("-ac");
			audio.push_back("1");
		}
		if (kanal.compare(AUDIOCHANELSSTEREO) == 0) {
			audio.push_back("-ac");
			audio.push_back("2");
		}
	}
//	std::cout<<"Audio Prekladac 4"<<std::endl;
	return audio;
}
Glib::ustring AudioPrekladac::getByKodek(Glib::ustring kod){
	for(unsigned int i = 0; i<zoznam.size(); i++){
		if(kod.compare(zoznam[i]->getKodek())==0){
			return zoznam[i]->getMeno();
		}
	}
	return "-1";
}
