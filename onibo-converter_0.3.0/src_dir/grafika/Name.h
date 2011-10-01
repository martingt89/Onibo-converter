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

#ifndef NAME_H_
#define NAME_H_
#include <glibmm/ustring.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include "Gloader.h"
#include "../makros.h"
class Name {
private:
	bool set;
	Gtk::Window *winT;
	Glib::ustring typT;
	Glib::ustring menoT;
	Gtk::Button *okT;
	Gtk::Button *closeT;
	Gtk::Entry *typeT;
	Gtk::Entry *subTypT;
	Gtk::Label *label;
public:
	Name(Gloader* glo);
	virtual ~Name();
	template<class T_return, class T_obj, class T_obj2>
	void addSignal(T_obj& _A_obj, T_return(T_obj2::* _A_func)()) {
		winT->signal_hide().connect(sigc::mem_fun(_A_obj, _A_func));
	}
	Glib::ustring getTyp(){return typT;}
	Glib::ustring getMeno(){return menoT;}
	void funOk();
	bool getOk();
	void show();
	void hide(){winT->hide();}
};

#endif /* NAME_H_ */
