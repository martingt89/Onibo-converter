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

#include "File_convert.h"
#include <iostream>
File_convert::File_convert() {
	Check_config_dir file;
	
	int a = file.readProfils(false);
	if(a != 0){
		std::cerr<<"Something is wrong: File_convert: "<<a<<std::endl;
	}
	
	std::vector<Glib::ustring> subory = file.Files();
	for (unsigned int i = 0; i < subory.size(); i++) {
		run(subory[i]);
	}
}

File_convert::~File_convert() {
	// TODO Auto-generated destructor stub
}
void File_convert::run(Glib::ustring u) {
	Zberac* zb = new Zberac();
	File_load* file = new File_load(u);
	if (file->isOK() == true) {
		Udaje* udaj = new Udaje();
		bool nekoniec = true;
		bool video = true;
		bool audio = true;
		int cis;
		zb->typ = file->getType();
		zb->meno = file->getName();
		zb->resolX = file->getResX();
		zb->resolY = file->getResY();
		if(file->getVBitrate().size() != 0){
			zb->bitrateV = file->getVBitrate();
		}
		if(file->getAbitrate().size() != 0){
			zb->bitrateA = file->getAbitrate();
		}
//		std::cout<<u<<std::endl;
		/////////////////////////////////////////////
		if (nekoniec && (cis = udaj->getVResolution(file->getResolution()))	!= -1) {
			zb->pomer = cis;
//			std::cout<<"Res "<<cis<<std::endl;
		} else {
			video = false;
		}
		if (nekoniec && (cis = udaj->getVFrame(file->getFramerate())) != -1) {
			zb->framerate = cis;
//			std::cout<<"fra "<<cis<<std::endl;
		} else {
			video = false;
		}
		BasicKon *kon = new BasicKon();
		VideoPrekladac *vidPrek = new VideoPrekladac();
		bool mozno = true;
		if (nekoniec && (cis = kon->getNumber(file->getContainer())) != -1) {
			zb->kontainer = cis;
		} else {
			nekoniec = false;
		}
		if (nekoniec && (cis = vidPrek->getX264Num(file->getX264())) != -1) {
			zb->x264 = cis;
		} else {
			mozno = false;
		}
//		std::cout<<"x264 "<<cis<<std::endl;
		Glib::ustring nazov = vidPrek->getByKodek(file->getVCodec());
		if (nazov.compare(X264) == 0 && mozno == false) {
			video = false;
		}

		if (nekoniec && (cis = kon->getKontainer(zb->kontainer)->getVKodekNum(nazov)) != -1) {
			zb->kodekV = cis;
		} else {
			video = false;
//			std::cout<<"err"<<nazov<<std::endl;
		}
//		std::cout<<"kodV "<<nazov<<" "<<zb->kontainer<<std::endl;


		if (nekoniec && (cis = udaj->getVOptions(file->getVideo())) != -1) {
			if((cis == 1 || cis == 2) && video == false){
				nekoniec = true;
			}else{
				if(video){
					nekoniec = true;
				}else{
					nekoniec = false;
				}
			}
			zb->nastav = cis;
		} else {
//			std::cout<<kon->getKontainer(zb->kontainer)->getVKodeky().size()<<std::endl;
			if(kon->getKontainer(zb->kontainer)->getVKodeky().size()!=0){
				nekoniec = false;
			}
			else{
				nekoniec = true;
			}
		}
		////////////////////////////////////////////////////

		if (nekoniec && (cis = udaj->getAChannels(file->getChannels())) != -1) {
			zb->channelA = cis;
		} else {
			audio = false;
		}
		if (nekoniec && (cis = udaj->getAVzorkovanie(file->getRate())) != -1) {
			zb->frekvenciaA = cis;
		} else {
			audio = false;
		}

		/////////////////////////////////////////////////////

		AudioPrekladac *audPrek = new AudioPrekladac();
		Glib::ustring audionazov = audPrek->getByKodek(file->getAcodec());
		if (nekoniec && (cis = kon->getKontainer(zb->kontainer)->getAKodekNum(
				audionazov)) != -1) {
			zb->kodekA = cis;
		} else {
			audio = false;
		}
//		std::cout<<"Akod: "<<cis<<std::endl;
		if (nekoniec && (cis = udaj->getAOptions(file->getAudio())) != -1) {
			if((cis == 1 || cis == 2) && audio == false){
				nekoniec = true;
			}else
				if(audio){
					nekoniec = true;
				}else{
					nekoniec = false;
				}
			zb->nastavA = cis;
		} else {
			if(kon->getKontainer(zb->kontainer)->getAKodeky().size()!=0){
				nekoniec = false;
			}
			else{
				nekoniec = true;
			}
		}

		delete audPrek;
		delete vidPrek;
		delete kon;

		if (nekoniec) {
			zb->file = u;
//			std::cout<<"koniec"<<std::endl;
			zberac.push_back(zb);
		} else {
			delete zb;
		}
		delete udaj;
	}else{
		delete zb;
	}
	delete file;
}
