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

#include "Indikator.h"

Indikator::Indikator(Gtk::ProgressBar* bar) {
	progress = bar;
}

Indikator::~Indikator() {
	// TODO Auto-generated destructor stub
}
void Indikator::setText(Glib::ustring u){
	mutex.lock();
		progress->set_text(u);
	mutex.unlock();
}
void Indikator::setCast(double d){
	mutex.lock();
	if(d>1){
		d = 1;
	}
	progress->set_fraction(d);
	mutex.unlock();
}
