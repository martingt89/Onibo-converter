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

#ifndef FILWIN_H_
#define FILWIN_H_
#include "Gloader.h"
#include <glibmm/ustring.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/spinbutton.h>
#include "../video/Information.h"
#include "../jadro/Analyza.h"
#include "../makros.h"

class FilWin {
	bool ok;
	double duration;
	int xRes;
	int yRes;
	Information *fil;
	Gtk::Window *winF;
	Gtk::Button *okF;
	Gtk::Button *closeF;
	Gtk::Label *resol;
	Gtk::Label *durat;
	Gtk::Label *warning;
	Gtk::CheckButton *deinterlance;
	Gtk::CheckButton *resolution;
	Gtk::SpinButton *start_time;
	Gtk::SpinButton *end_time;
	Gtk::SpinButton *yhor;
	Gtk::SpinButton *ydol;
	Gtk::SpinButton *xleft;
	Gtk::SpinButton *xright;
	Gtk::Adjustment *yhorad; 
	Gtk::Adjustment *ydolad; 
	Gtk::Adjustment *xleftad; 
	Gtk::Adjustment *xrightad; 
	Gtk::Adjustment *start_time_ad; 
	Gtk::Adjustment *end_time_ad; 
public:
	FilWin(Gloader *glo);
	virtual ~FilWin();
	void apply();
	void hide();
	void show(int opt);
	void endChenged();
	void setFilter(Information *ff);
	bool getChenged();
	template<class T_return, class T_obj, class T_obj2>
	void addSignal(T_obj& _A_obj, T_return(T_obj2::* _A_func)()) {
		winF->signal_hide().connect(sigc::mem_fun(_A_obj, _A_func));
	}
};

#endif /* FILWIN_H_ */
