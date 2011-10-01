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

#include "FilWin.h"
#include <iostream>

FilWin::FilWin(Gloader *glo) {
	ok = false;

	start_time_ad = new Gtk::Adjustment(0, 0, 0); 
	end_time_ad = new Gtk::Adjustment(-1, -1, -1);
	yhorad = new Gtk::Adjustment(0, 0, 0);
	ydolad = new Gtk::Adjustment(0, 0, 0);
	xleftad = new Gtk::Adjustment(0, 0, 0);
	xrightad = new Gtk::Adjustment(0, 0, 0);
	winF = glo->get<Gtk::Window*>("window4");
	okF = glo->get<Gtk::Button*>("filter_OK");
	closeF = glo->get<Gtk::Button*>("filter_cancel");
	resol = glo->get<Gtk::Label*>("label29");
	durat = glo->get<Gtk::Label*>("label28");
	warning = glo->get<Gtk::Label*>("label34");
	//
	deinterlance = glo->get<Gtk::CheckButton*>("checkbutton1");
	yhor = glo->get<Gtk::SpinButton*>("spinbutton3");
	ydol = glo->get<Gtk::SpinButton*>("spinbutton4");
	start_time = glo->get<Gtk::SpinButton*>("spinbutton1");
	end_time = glo->get<Gtk::SpinButton*>("spinbutton2");
	xleft = glo->get<Gtk::SpinButton*>("spinbutton5");
	xright = glo->get<Gtk::SpinButton*>("spinbutton6");
	resolution = glo->get<Gtk::CheckButton*>("checkbutton2");
	//
	yhor->set_adjustment(*yhorad);
	ydol->set_adjustment(*ydolad);
	xleft->set_adjustment(*xleftad);
	xright->set_adjustment(*xrightad);
	start_time->set_adjustment(*start_time_ad);
	end_time->set_adjustment(*end_time_ad);
	
	end_time->signal_value_changed ().connect(sigc::mem_fun(*this, &FilWin::endChenged));
	okF->signal_clicked().connect(sigc::mem_fun(*this, &FilWin::apply));
	closeF->signal_clicked().connect(sigc::mem_fun(*this, &FilWin::hide));
	//

}

FilWin::~FilWin() {
	delete start_time_ad;
	delete end_time_ad;
	delete yhorad;
	delete ydolad;
	delete xleftad;
	delete xrightad;
}
void FilWin::endChenged(){
	if(end_time->get_value()<0){
		end_time->set_value(-1);
	}

}
void FilWin::apply(){
	if(fil->getDuration() != -1){
		bool end = true;
		if(end_time->get_value()>=0 && end_time->get_value()<start_time->get_value()){
			warning->set_text("End time is lower then start time");
			end = false;
		}
		if(yhor->get_value()+ydol->get_value() >= fil->getY() && fil->getY() != 0){
			warning->set_text("Crop video isn't corect => Y");
			end = false;
		}
		if(xleft->get_value()+xright->get_value() >= fil->getX() && fil->getX() != 0){
			warning->set_text("Crop video isn't corect => X");
			end = false;
		}
		if(end){
			ok = true;
			fil->set(yhor->get_value(),ydol->get_value(), xleft->get_value(), xright->get_value(), start_time->get_value(), 
				end_time->get_value(), deinterlance->get_active(), resolution->get_active());
			winF->hide();
		}
	}else{
		winF->hide();
	}
}
void FilWin::hide(){
	winF->hide();
}
void FilWin::setFilter(Information *ff){
	warning->set_text("");
	fil = ff;
	bool chyba = false;
	if(fil->getDuration() < 0){
		//zapnut analyzator
		Analyza an(ff->getName());
		double dur = an.getDuration();
		fil->setDuration(dur);
		if(dur > 0){
			fil->setResol(an.getX(), an.getY());
		}else{
			chyba = true;
		}
	}
	if(chyba != true){
		duration = fil->getDuration();
		xRes = fil->getX();
		yRes = fil->getY();
		yhorad->set_upper(yRes);
		ydolad->set_upper(yRes);
		xleftad->set_upper(xRes);
		xrightad->set_upper(xRes);
		resolution->set_active(ff->getReso());
		resol->set_text("Resolution: "+Glib::ustring::format(xRes)+"x"+Glib::ustring::format(yRes));
		durat->set_text("Duration: "+Glib::ustring::format(duration));
		deinterlance->set_active(ff->getDein());
		yhor->set_value(ff->getYUp());
		ydol->set_value(ff->getYdown());
		start_time->set_value(ff->getStart());
		end_time->set_value(ff->getEnd());
		start_time_ad->set_upper(duration);
		end_time_ad->set_upper(duration);
	}else{
		warning->set_text("Input file error");
	}
}
void FilWin::show(int opt){
	if(opt != CUSTOMVIDEONUM || xRes == 0 || yRes == 0){
		deinterlance->set_sensitive(false);
		yhor->set_sensitive(false);
		ydol->set_sensitive(false);
		xleft->set_sensitive(false);
		xright->set_sensitive(false);
		resolution->set_sensitive(false);
		resol->set_text("No video or copy video");
	}else{
		deinterlance->set_sensitive(true);
		yhor->set_sensitive(true);
		ydol->set_sensitive(true);
		xleft->set_sensitive(true);
		xright->set_sensitive(true);
		resolution->set_sensitive(true);
	}
	ok = false;
	winF->show();
}
bool FilWin::getChenged(){
	return fil->getEdit();
}
