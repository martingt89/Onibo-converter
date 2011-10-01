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

#include "Udaje.h"

Udaje::Udaje() {
	vOptions.push_back(CUSTOMVIDEO);vOptions.push_back(COPYVIDEO);vOptions.push_back(NOVIDEO);
	
	vFrame.push_back("copy");vFrame.push_back("10");vFrame.push_back("15");vFrame.push_back("20");
	vFrame.push_back("23.976");vFrame.push_back("24");vFrame.push_back("25");vFrame.push_back("29.97");
	vFrame.push_back("30");
	
	vBitrate.push_back("200");vBitrate.push_back("320");vBitrate.push_back("500");vBitrate.push_back("700");
	vBitrate.push_back("1100");vBitrate.push_back("1500");

	vResolution.push_back(CUSTOMRESOL);vResolution.push_back(VIDEORESOLUTION43);vResolution.push_back(VIDEORESOLUTION169);
	vResolution.push_back(ORIGINALRESOL);

	vX.push_back("320");vX.push_back("640");vX.push_back("768");vX.push_back("800");vX.push_back("1024");
	vX.push_back("1280");vX.push_back("1920");
	
	vY.push_back("240");vY.push_back("480");vY.push_back("576");vY.push_back("600");vY.push_back("768");
	vY.push_back("720");vY.push_back("1080");
	//audio
	aOptions.push_back(CUSTOMAUDIO);aOptions.push_back(COPYAUDIO);aOptions.push_back(NOAUDIO);
	
	aChannels.push_back("original");aChannels.push_back(AUDIOCHANELSMONO);aChannels.push_back(AUDIOCHANELSSTEREO);
	
	aVzorkovanie.push_back(ORIGINALAUDIOVZORK);aVzorkovanie.push_back("48000");
	aVzorkovanie.push_back("44100");aVzorkovanie.push_back("32000");aVzorkovanie.push_back("22050");
	aVzorkovanie.push_back("16000");aVzorkovanie.push_back("8000");
}

Udaje::~Udaje() {
	// TODO Auto-generated destructor stub
}

std::list<Glib::ustring> Udaje::getAOptions(){
	if(clr == true)
	return aOptions;
	return empty;
}
std::list<Glib::ustring> Udaje::getAChannels(){
	if(clr == true){
	return aChannels;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getAVzorkovanie(){
	if(clr == true){
	return aVzorkovanie;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::geVOptions(){
	if(clr == true){
	return vOptions;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getVBitrate(){
	if(clr == true){
	return vBitrate;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getVFrame(){
	if(clr == true){
	return vFrame;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getVResolution(){
	if(clr == true){
	return vResolution;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getVX(){
	if(clr == true){
	return vX;
	}
	return empty;
}
std::list<Glib::ustring> Udaje::getVY(){
	if(clr == true){
	return vY;
	}
	return empty;
}
//--------------------------------------------------------------------------
int Udaje::getAOptions(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=aOptions.begin(); it!= aOptions.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
int Udaje::getAChannels(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=aChannels.begin(); it!= aChannels.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
int Udaje::getAVzorkovanie(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=aVzorkovanie.begin(); it!= aVzorkovanie.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
int Udaje::getVOptions(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=vOptions.begin(); it!= vOptions.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
int Udaje::getVFrame(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=vFrame.begin(); it!= vFrame.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
int Udaje::getVResolution(Glib::ustring us){
	std::list<Glib::ustring>::iterator it;
	int i = 0;
	for(it=vResolution.begin(); it!= vResolution.end(); it++){
		if(it->compare(us)==0){
			return i;
		}
		i++;
	}
	return -1;
}
