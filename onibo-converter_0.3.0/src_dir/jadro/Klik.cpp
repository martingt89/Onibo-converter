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
 
#include "Klik.h"
#include <iostream>

Klik::Klik(){
	running = false;
	info = new Info;
	vysledok = new Vysledky;
	jadro.message.connect(sigc::mem_fun(*this, &Klik::zobraz));
	jadro.thread_done.connect(sigc::mem_fun(*this, &Klik::convert));
	indik = NULL;
	star = NULL;
}
Klik::~Klik(){
	delete info;
	delete vysledok;
}
bool Klik::isRun(){
return running;
}
void Klik::init(Gloader* gl){
	prepis = gl->get<Gtk::MessageDialog*>("messagedialog1");
	diaDone = gl->get<Gtk::MessageDialog*>("messagedialog2");
	star = gl->get<Gtk::Button*>("button3");
	done_window = gl->get<Gtk::Window*>("window2");
	ok_button = gl->get<Gtk::Button*>("button4");
	sprava_vys = gl->get<Gtk::TextView*>("textview1");

	diaDone->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	prepis->add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	prepis->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);

	ok_button->signal_clicked().connect(sigc::mem_fun(*this, &Klik::skovaj));
	done_window->signal_hide().connect(sigc::mem_fun(*this, &Klik::skovaj));
}
void Klik::setGUI(GUI_onb g, Indikator *ind){
	gui = g;
	indik = ind;
}
void Klik::setInfo(std::list<Information> inf){
	davkovac.setListInfo(inf);
}
void Klik::exit(){
	davkovac.setEnd();
	jadro.exit();
	if(star){
		star->set_label("Start");
	}
	if(indik){
		indik->setText("");
	}
	running = false;
}
void Klik::run(){
	davkovac.refresh();
	info->clr();
	running = true;
	star->set_label("Stop");
	vysledok->restart();
	convert();
}
void Klik::convert(){
	int status = info->getStatus();
	if (status == 3) { //save all abort file
		vysledok->set(info->getNazov(), status);
		vysledok->setStop(davkovac.getAbort());
	} else {
		vysledok->set(info->getNazov(), status);
	}
	Information* inf = davkovac.getNextInfo();
	if(inf != NULL){
		info->setNazov(inf->getName());
		info->setDalsi();
		file.setHmm(inf->getName(), gui.vystupFol, gui.kontainer);
		bool con = true;
		if(file.getFile() == true){
			int res = prepis->run();
			if (res == Gtk::RESPONSE_OK) {
				con = true;
			} else {
				vysledok->set(info->getNazov(), -1);
				con = false;
			}
			prepis->hide();
		}
		if(con){
			jadro.set(inf, gui, info, davkovac.getPocet());
			jadro.start();
		}else{
			convert();
		}
	}else{
		indik->setText("");
		star->set_label("Start");
//		std::cout<<vysledok->getSprava()<<std::endl;
		if (davkovac.getPocet() != 0) {
			done_window->show();
			Glib::RefPtr < Gtk::TextBuffer > bufer = Gtk::TextBuffer::create();
			bufer->set_text("");
			sprava_vys->set_buffer(bufer);
			bufer->set_text(vysledok->getSprava());
			sprava_vys->set_buffer(bufer);
		} else {
			diaDone->show();
			diaDone->run();
			diaDone->hide();
		}
		running = false;
	}
}
void Klik::zobraz(){
	indik->setCast(info->getFragment());
	indik->setText(info->getText());
}
void Klik::skovaj(){
	if (done_window->is_visible()) {
		done_window->hide();
	}
}
/*
void Okno::spracuj() {
	int status = info->getStatus();
	if (status == 2) {
		info->setStatus(-1);
		int res = dia->run();
		if (res == Gtk::RESPONSE_OK) {
			davka.back();
			info->setPrepis(true);
			info->setBack();
		} else {
			vysledok->set(info->getNazov(), -1);
		}
		dia->hide();
	} else {
		if (status == 3) { //save all abort file
			vysledok->set(info->getNazov(), status);
			vysledok->setStop(davka.getAbort());
		} else {
			vysledok->set(info->getNazov(), status);
		}
	}
	Information *akt_fil = davka.getNextInfo();
	if (akt_fil != NULL) {
		info->setDalsi();
		jadro->setFilter(akt_fil);
		jadro->start();
	} else {
		indikator->setText("");
		zamkni->setKonvert(false);
		start->set_label("Start");
		if (davka.getPocet() != 0) {
			done_window->show();
			Glib::RefPtr < Gtk::TextBuffer > bufer = Gtk::TextBuffer::create();
			bufer->set_text(vysledok->getSprava());
			sprava_vys->set_buffer(bufer);
		} else {
			diaDone->show();
			diaDone->run();
			diaDone->hide();
		}
	}
}
*/
