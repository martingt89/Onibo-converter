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

#include "Zamok.h"

Zamok::Zamok() {
	prepis = false;
	konvertovanie = false;
}
Zamok::~Zamok() {
	// TODO Auto-generated destructor stub
}
void Zamok::setKonvert(bool konvert){
	 Glib::Mutex::Lock lock (mutex);
	 konvertovanie = konvert;
}
bool Zamok::getKonvert(){
	Glib::Mutex::Lock lock (mutex);
	return konvertovanie;
}
void Zamok::setVideo(std::list<Glib::ustring> v){
	Glib::Mutex::Lock lock (mutex);
	vid = v;
}
void Zamok::setAudio(std::list<Glib::ustring> a){
	Glib::Mutex::Lock lock (mutex);
	aud =a;
}
std::list<Glib::ustring> Zamok::getVideo(){
	Glib::Mutex::Lock lock (mutex);
	return vid;
}
std::list<Glib::ustring> Zamok::getAudio(){
	Glib::Mutex::Lock lock (mutex);
	return aud;
}
void Zamok::setPrepisat(bool b){
	Glib::Mutex::Lock lock (mutex);
	prepis = b;
}
bool Zamok::getPrepisat(){
	Glib::Mutex::Lock lock (mutex);
	return prepis;
}
