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

#include "Generator.h"
#include <iostream>

Generator::Generator(GUI_onb g, Information *inf) {
	gui = g;
	inform = inf;
	vstup = inform->getName();
	Glib::ustring::iterator it;
	for (it = vstup.end(); it != vstup.begin(); it--) {
		if (*it == '/')
			break;
	}
	it++;
	Glib::ustring nazovss = Glib::ustring(it, vstup.end());

	it = gui.vystupFol.end();
	it--;
	if (*it == '/') {
		vystup = gui.vystupFol + nazovss + "." + gui.kontainer;
	} else {
		vystup = gui.vystupFol + "/" + nazovss + "."
				+ gui.kontainer;
	}
}

Generator::~Generator() {
	// TODO Auto-generated destructor stub
}
Glib::ustring Generator::run() {
//	bool prepis;
//	prepis = skrinka.getInfo()->getPrepis();
	std::vector<Glib::ustring> skript;
	skript.push_back(FFMPEG);
	skript.push_back("-i");
	Glib::ustring vstup_up = "\"" +vstup+ "\"";
	Glib::ustring vystup_up = "\"" +vystup+ "\"";

	skript.push_back(vstup_up);
//	if (prepis == true) {
		skript.push_back("-y");
//	}
	std::list<Glib::ustring>::iterator iter;
	Glib::ustring x = gui.vX;
	Glib::ustring y = gui.vY;
	//edit resolution
//	std::cout<<x<<" "<<y<<std::endl;
	if(inform->getX() + inform->getY() != 0){
		if(inform->getReso()==true){
			int xi = atoi(x.c_str());
			double hmm = xi*1.0/inform->getX();
			xi = (inform->getX()-inform->getXLeft()-inform->getXright())*hmm + inform->getXLeft()+inform->getXright();
			x = Glib::ustring::format(xi);
			
			int yi = atoi(y.c_str());
			hmm = yi*1.0/inform->getY();
			yi = (inform->getY()-inform->getYUp()-inform->getYdown())*hmm + inform->getYUp() + inform->getYdown();
			y = Glib::ustring::format(yi);
		}else{
			int xi = atoi(x.c_str());
			xi = xi + inform->getXLeft() + inform->getXright();
			x = Glib::ustring::format(xi);
		
			int yi = atoi(y.c_str());
			yi = yi + inform->getYUp() + inform->getYdown();
			y = Glib::ustring::format(yi);
		}
	}
	
//	std::cout<<x<<" "<<y<<std::endl;
	
	std::list<Glib::ustring> parameter;
	std::cout<<inform->getEdit()<<std::endl;
	std::cout<<gui.vPomer<<std::endl;
	std::cout<<inform->getReso()<<std::endl;
	
	if(inform->getEdit() == true && gui.vPomer.compare(ORIGINALRESOL)==0 && inform->getReso() == false){
		int asx = inform->getX() + inform->getXLeft()+inform->getXright();
		x = Glib::ustring::format(asx);
		int asy = inform->getY()+ inform->getYUp() + inform->getYdown();
		y = Glib::ustring::format(asy);
//		std::cout<<std::endl<<"tu"<<std::endl;
		parameter = vid.preloz(gui.kontainer,
		gui.vKodek, gui.vOptions, CUSTOMRESOL , x, y, 
		gui.vBitrate, gui.vFrame, gui.x264);	
	}else{	
		parameter = vid.preloz(gui.kontainer,
		gui.vKodek, gui.vOptions, gui.vPomer, x, y, 
		gui.vBitrate, gui.vFrame, gui.x264);
	}

	for (iter = parameter.begin(); iter != parameter.end(); iter++) {
		skript.push_back(*iter);
	}
	
	parameter = aud.preloz(gui.aKodek, gui.aOptions,
	gui.aBitrate, gui.aFrekvenci, gui.aChannels);
	
	for (iter = parameter.begin(); iter != parameter.end(); iter++) {
		skript.push_back(*iter);
	}
	
	skript.push_back(inform->getParametre(gui.vOptions.c_str()));
	skript.push_back("-map_meta_data "+vystup_up+":"+vstup_up);
	
	skript.push_back(vystup_up);

	Glib::ustring exec = "";
	for (unsigned int i = 0; i != skript.size(); i++) {
		exec = exec + " " + skript[i];
	}
	std::cout<<exec<<std::endl;
	return exec;
}
