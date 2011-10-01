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

#include "AudioKodeky.h"

AudioKodeky::AudioKodeky() {
	// TODO Auto-generated destructor stub
}

AudioKodeky::~AudioKodeky() {
	// TODO Auto-generated destructor stub
}
void AudioKodeky::set(Glib::ustring meno, Glib::ustring kniz){
	this->meno = meno;
	kodek = kniz;
}
void AudioKodeky::setNastavenia(std::list<Glib::ustring> nas){
	nastavenia = nas;
}
void AudioKodeky::setAuto(){
	nastavenia.push_back("320");
	nastavenia.push_back("256");
	nastavenia.push_back("196");
	nastavenia.push_back("128");
	nastavenia.push_back("96");
	nastavenia.push_back("64");
}
std::list<Glib::ustring> AudioKodeky::getNastavenia(){
	return nastavenia;
}
Glib::ustring AudioKodeky::getMeno(){
	return meno;
}
Glib::ustring AudioKodeky::getKodek(){
	return kodek;
}
Glib::ustring AudioKodeky::getQuality(Glib::ustring u){
	return "none";
}
