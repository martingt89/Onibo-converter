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

#include "Info.h"

Info::Info() {
	status = -2;
	akt = 0;
	convert = true;
	mn_merani = 0;
	last = 0;
	prepisat = false;
	do_konca = 0;
}

Info::~Info() {
	// TODO Auto-generated destructor stub
}
Glib::ustring Info::getNazov(){
	Glib::Mutex::Lock lock (mutex);
	return nazov;
}
Glib::ustring Info::getText(){
	Glib::Mutex::Lock lock (mutex);
	std::list<double>::iterator it;
	std::list<double>::iterator it2;
	Glib::ustring zostava = "N/A";
	double c_cas = 0;
	double c_roz = 0;
	if(video_cas.size() != 0){
		it2 = rozdiel_merania.begin();
		for(it = video_cas.begin(); it != video_cas.end(); it++){
			c_cas += *it;
			c_roz += *it2;
			it2++;
		}
		if(do_konca < 0)do_konca = 0;
		int sscs = do_konca/(c_cas/c_roz*1.0);
		zostava = Glib::ustring::format(sscs);
	}

	Glib::ustring text = Glib::ustring::format(akt) +"/" + Glib::ustring::format(pocet)+
			"   " + nazov +"   "+zostava+" sec";
	return text;
}
void Info::setNazov(Glib::ustring meno){
	Glib::Mutex::Lock lock (mutex);
	nazov = meno;
}
void Info::setFragment(double d){
	Glib::Mutex::Lock lock (mutex);
	fragment = d;
}
double Info::getFragment(){
	Glib::Mutex::Lock lock (mutex);
	return fragment;
}
void Info::setStatus(int i){
	Glib::Mutex::Lock lock (mutex);
	status = i;
}
int Info::getStatus(){
	Glib::Mutex::Lock lock (mutex);
	int stat = status;
	status = -2;
	return stat;
}
void Info::setPocet(int poc){
	Glib::Mutex::Lock lock (mutex);
	pocet = poc;
}
void Info::setDalsi(){
	Glib::Mutex::Lock lock (mutex);
	akt++;
}
void Info::clr(){
	Glib::Mutex::Lock lock (mutex);
	akt = 0;
	pocet = 0;
	status = -2;
	convert = true;
	mn_merani = 0;
	video_cas.clear();
	rozdiel_merania.clear();
	prepisat = false;
	last = 0;
	do_konca = 0;
}
void Info::setCovert(bool b){
	Glib::Mutex::Lock lock (mutex);
	convert = b;
}
bool Info::getConvert(){
	Glib::Mutex::Lock lock (mutex);
	return convert;
}
void Info::addTime(double akt_time, double def_time, double dlzka){
	Glib::Mutex::Lock lock (mutex);
	if(last != 0){
		std::list<double>::iterator iter;
		double roz = def_time - last_roz;
		double cas = akt_time - last;
		if(cas > 0){
			mn_merani++;
			if(mn_merani > 60){
				iter = video_cas.begin();
				video_cas.erase(iter);
				iter = rozdiel_merania.begin();
				rozdiel_merania.erase(iter);
			}
			video_cas.push_back(cas);
			rozdiel_merania.push_back(roz);
		}
	}
	last = akt_time;
	last_roz = def_time;
	do_konca = dlzka - akt_time;
}
