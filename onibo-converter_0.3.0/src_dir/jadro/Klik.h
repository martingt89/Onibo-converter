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

#ifndef KLIK_H_
#define KLIK_H_
#include <list>
#include "../grafika/GUI.h"
#include "../grafika/Indikator.h"
#include "../grafika/Vysledky.h"
#include "Jadro.h"
#include "Info.h"
#include "Davkovac.h"
#include "File_Onb.h"
#include "../grafika/Gloader.h"
#include <gtkmm/messagedialog.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/textview.h>
#include <gtkmm/stock.h>
class Klik {
private:
	bool running;
	GUI_onb gui;
	Jadro jadro;
	Davkovac davkovac;
	File_Onb file;
	Indikator *indik;
	Info *info;
	Gtk::MessageDialog* prepis;
	Gtk::MessageDialog* diaDone;
	Gtk::Button* star;
	Gtk::Button* ok_button;
	Vysledky* vysledok;
	Gtk::Window *done_window;
	Gtk::TextView* sprava_vys;
	void convert();
	void zobraz();
public:
	Klik();
	virtual ~Klik();
	bool isRun();
	void init(Gloader* gl);
	void setGUI(GUI_onb, Indikator*);
	void setInfo(std::list<Information>);
	void run();
	void exit();
	void skovaj();
};

#endif /* KLIK_H_ */
