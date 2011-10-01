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

#ifndef OKNO_H_
#define OKNO_H_

#include <glibmm/thread.h>
#include <gtkmm/main.h>
#include <gtkmm/filechooserdialog.h>
#include <giomm/file.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include "Vysuvatko.h"
#include "Zobrazovac.h"
#include "Gloader.h"
#include "Indikator.h"
#include "Name.h"
#include "FilWin.h"
#include "GUI.h"
#include "../jadro/Klik.h"
#include "../prof/File_inport.h"
#include "../prof/Save_profil.h"
#include "../jadro/Doplnky.h"
#include "../video/Kontainer.h"
#include "../video/BasicKon.h"
#include "../video/Loader.h"
#include "../video/VideoKodeky.h"
#include "../video/VideoPrekladac.h"
#include "../video/Profil.h"
#include "../video/AudioKodeky.h"
#include "../video/AudioPrekladac.h"
#include "../video/Udaje.h"
#include "../video/Information.h"

class Okno {
private:
	Gloader *load;
	Gtk::Window* window;
	Gtk::Window* window3;
	Gtk::Entry* outfolder;
	Gtk::Button* start;
	Gtk::Button* vystup;
	Gtk::Button* vstup;
	Gtk::Button* tl_clr;
	Gtk::Button* remov_button;
	Gtk::ProgressBar *bar;
	Gtk::AboutDialog* about_dialog_m;
	Gtk::Image* ObrKont;
	Gtk::ImageMenuItem* about_menu;
	Gtk::ImageMenuItem* start_menu;
	Gtk::ImageMenuItem* open_menu;
	Gtk::ImageMenuItem* save_menu;
	Gtk::ImageMenuItem* exit_menu;
	Gtk::ImageMenuItem* import_menu;
	Gtk::ImageMenuItem* export_menu;
	Gtk::ImageMenuItem* savePro_menu;
	Gtk::MenuItem* filter_menu;

	Glib::Thread* thread;
	Vysuvatko *kodek;
	Vysuvatko *kontainer;
	Vysuvatko *voptions;
	Vysuvatko *profil;
	Vysuvatko *typ;
	Vysuvatko *frame;
	Vysuvatko *vPomer;
	Vysuvatko *x264;
	VysuvatkoEntry *xVelk;
	VysuvatkoEntry *yVelk;
	VysuvatkoEntry *bitrateV;
	//
	Vysuvatko *akodek;
	Vysuvatko *aoptions;
	Vysuvatko *achannels;
	Vysuvatko *afrekvenci;
	VysuvatkoEntry* abitrate;
	//
	Zobrazovac * tabula;
	Name *nameWin;
	FilWin *filwin;

	Indikator *indikator;

	Kontainer* zasobnik;
	BasicKon* pripony;
	Loader* pred;
	Doplnky* doplnky;
	Udaje* udaje;
	AudioPrekladac* audi;
	VideoPrekladac* vid;

	bool systemB;
	int opti_zob;
	Klik klk;
public:
	Okno();
	virtual ~Okno();
	void exit();
	void changeKontainer();
	void changeKodek();
	void changeTyp();
	void changeProfil();
	void setCustomProfil();
	void changeVOpt();
	void changeX();
	void changeY();
	void changePomer();
	void vstupneSubory();
	void vystupPriecinok();
	void changeAKodek();
	void changeAOpt();
	void klik();
	void about_close_m(int);
	void import();
	void exporting();
	void save();
	int dialog(Glib::ustring text);
};

#endif /* OKNO_H_ */
