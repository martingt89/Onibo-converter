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

#include "Okno.h"
#include <iostream>

Okno::Okno() {
	systemB = false;
	pred = new Loader;
	doplnky = new Doplnky();
	udaje = new Udaje();
	audi = new AudioPrekladac;
	vid = new VideoPrekladac;
	pripony = new BasicKon();

	voptions = new Vysuvatko();
	profil = new Vysuvatko();
	typ = new Vysuvatko();
	kodek = new Vysuvatko();
	kontainer = new Vysuvatko();
	frame = new Vysuvatko();
	vPomer = new Vysuvatko();
	x264 = new Vysuvatko();
	xVelk = new VysuvatkoEntry();
	yVelk = new VysuvatkoEntry();
	bitrateV = new VysuvatkoEntry();
	//
	akodek = new Vysuvatko();
	aoptions = new Vysuvatko();
	achannels = new Vysuvatko();
	afrekvenci = new Vysuvatko();
	abitrate = new VysuvatkoEntry();
	load = new Gloader();

	if (load->getOK() == 0) {
		klk.init(load);
		window = load->get<Gtk::Window*>("window1");
				
		nameWin = new Name(load);
		filwin = new FilWin(load);
		
		start = load->get<Gtk::Button*>("button3");
		vystup = load->get<Gtk::Button*>("vystup_button");
		vstup = load->get<Gtk::Button*>("button1");
		tl_clr = load->get<Gtk::Button*>("button2");
		remov_button = load->get<Gtk::Button*>("button5");

		savePro_menu = load->getMenuSavePro();
		filter_menu = load->getMenuFilter();
		
		indikator = new Indikator(load->get<Gtk::ProgressBar *>("progressbar1"));
		about_menu = load->getMenuAbout();
		start_menu = load->getMenuStart();
		open_menu = load->getMenuOpen();
		save_menu = load->getMenuSave();
		exit_menu = load->getMenuClose();
		import_menu = load->getMenuImport();
		export_menu = load->getMenuExport();
		
		kodek->setCombo(load->getVCodecBox());
		kontainer->setCombo(load->getVContBox());
		voptions->setCombo(load->getVOptBox());
		profil->setCombo(load->getProfilBox());
		typ->setCombo(load->getTypBox());
		vPomer->setCombo(load->getVRezolBox());
		frame->setCombo(load->getVFraBox());
		x264->setCombo(load->getVx264Box());
		xVelk->setCombo(load->getVXEntry());
		yVelk->setCombo(load->getVYEntry());
		bitrateV->setCombo(load->getVBitrate());
		
		akodek->setCombo(load->getACodBox());
		aoptions->setCombo(load->getAOptBox());
		achannels->setCombo(load->getAChanBox());
		afrekvenci->setCombo(load->getARateBox());
		abitrate->setCombo(load->getABitrate());
		
		tabula = new Zobrazovac(load->getZobraz(), filwin, &opti_zob);
		
		outfolder = load->getOutput();
		ObrKont = load->get<Gtk::Image*>("obrazok_kon");
		about_dialog_m = load->get<Gtk::AboutDialog*>("aboutdialog1");

		about_dialog_m->signal_response().connect(sigc::mem_fun(*this,
				&Okno::about_close_m));
		vstup->signal_clicked().connect(sigc::mem_fun(*this,
				&Okno::vstupneSubory));
		vystup->signal_clicked().connect(sigc::mem_fun(*this,
				&Okno::vystupPriecinok));
		tl_clr->signal_clicked().connect(sigc::mem_fun(*tabula,
				&Zobrazovac::clr));
		start->signal_clicked().connect(sigc::mem_fun(*this, &Okno::klik));
		savePro_menu->signal_activate().connect(sigc::mem_fun(nameWin, &Name::show));
		nameWin->addSignal(*this, &Okno::save);
		window->signal_hide().connect(sigc::mem_fun(*this, &Okno::exit));

		about_menu->signal_activate().connect(sigc::mem_fun(*about_dialog_m,
				&Gtk::AboutDialog::show));
		start_menu->signal_activate().connect(sigc::mem_fun(*this, &Okno::klik));
		open_menu->signal_activate().connect(sigc::mem_fun(*this,
				&Okno::vstupneSubory));
		save_menu->signal_activate().connect(sigc::mem_fun(*this,
				&Okno::vystupPriecinok));
		exit_menu->signal_activate().connect(sigc::mem_fun(*this, &Okno::exit));
		import_menu->signal_activate().connect(sigc::mem_fun(*this, &Okno::import));
		export_menu->signal_activate().connect(sigc::mem_fun(*this, &Okno::exporting));
		filter_menu->signal_activate().connect(sigc::mem_fun(*tabula, &Zobrazovac::nastavenia));
		
		
		remov_button->signal_clicked().connect(sigc::mem_fun(*tabula, &Zobrazovac::eraseActiv));
		window->show();

		kontainer->setRiadky(pripony->getKontainery());
		profil->addSignal(*this, &Okno::changeProfil);
		typ->addSignal(*this, &Okno::changeTyp);
		kodek->addSignal(*this, &Okno::changeKodek);
		frame->addSignal(*this, &Okno::setCustomProfil);
		bitrateV->addSignal(*this, &Okno::setCustomProfil);
		xVelk->addSignal(*this, &Okno::changeX);
		yVelk->addSignal(*this, &Okno::changeY);
		voptions->addSignal(*this, &Okno::changeVOpt);
		kontainer->addSignal(*this, &Okno::changeKontainer);
		vPomer->addSignal(*this, &Okno::changePomer);
		//
		akodek->addSignal(*this, &Okno::changeAKodek);
		achannels->addSignal(*this, &Okno::setCustomProfil);
		afrekvenci->addSignal(*this, &Okno::setCustomProfil);
		abitrate->addSignal(*this, &Okno::setCustomProfil);
		aoptions->addSignal(*this, &Okno::changeAOpt);

		outfolder->set_text(Glib::get_home_dir()+"/");
		typ->setRiadky(pred->getTypy());
		changeProfil();
		Gtk::Main::run();
	}
}
Okno::~Okno() {
	delete pred;
	delete doplnky;
	delete udaje;
	delete audi;
	delete vid;
	delete pripony;
	delete voptions;
	delete profil;
	delete kodek;
	delete kontainer;
	delete frame;
	delete vPomer;
	delete x264;
	delete xVelk;
	delete yVelk;
	delete bitrateV;
	 //
	delete akodek;
	delete aoptions;
	delete achannels;
	delete afrekvenci;
	delete abitrate;
	//
	delete indikator;
	delete tabula;
	delete nameWin;
	delete filwin;
	//
	delete load;
}

void Okno::changeAKodek() {
	setCustomProfil();
	AudioKodeky *kod = audi->getAudioKodek(akodek->getActiv());
	abitrate->setRiadky(kod->getNastavenia());
}
void Okno::changeAOpt() {
	setCustomProfil();
	bool str = systemB;
	if (aoptions->getActivePor() != 0) { //trosku provizorne
		systemB = true;
		akodek->Clr();
		achannels->Clr();
		afrekvenci->Clr();
		abitrate->Clr();
		systemB = str;
	} else {
		if (achannels->getActivePor() == -1) {
			zasobnik = pripony->getKontainer(kontainer->getActivePor());
			if (akodek->setRiadky(zasobnik->getAKodeky()) != -1) {
				systemB = true;
				achannels->setRiadky(udaje->getAChannels());
				afrekvenci->setRiadky(udaje->getAVzorkovanie());
				abitrate->set_editable(true);
				systemB = str;
			}
		}
	}
}
void Okno::changeKodek() {
	setCustomProfil();
	VideoKodeky kod = vid->getVideoKodek(kodek->getActiv());
	x264->setRiadky(kod.getX264());
}
void Okno::changeVOpt() {
	setCustomProfil();
	opti_zob = voptions->getActivePor();
	bool str = systemB;
	if (voptions->getActivePor() != 0) { // provizorne
		kodek->Clr();
		frame->Clr();
		bitrateV->Clr();
		systemB = true;
		xVelk->Clr();
		yVelk->Clr();
		systemB = str;
		vPomer->Clr();
		x264->Clr();
	} else {
		if (bitrateV->get_editable() == false) {
			systemB = true;
			zasobnik = pripony->getKontainer(kontainer->getActivePor());
			if (kodek->setRiadky(zasobnik->getVKodeky()) != -1) { //ak existuje aspon jeden kodek nastavia sa hodnoty
				bitrateV->setRiadky(udaje->getVBitrate());
				frame->setRiadky(udaje->getVFrame());
				xVelk->setRiadky(udaje->getVX());
				yVelk->setRiadky(udaje->getVY());
				vPomer->setRiadky(udaje->getVResolution());
			}
			systemB = str;
		}
	}
}
void Okno::setCustomProfil() {
	if (!systemB) {
		systemB = true;
		typ->set_activ(pred->getCustomProfil());
		systemB = false;
		profil->set_activ(0);
	}
}
void Okno::changeX() {
	setCustomProfil();
	if (systemB == false) {
		systemB = true;
		yVelk->setText(doplnky->XtoY(xVelk->getActiv(), yVelk->getActiv(),
				vPomer->getActiv()));
		systemB = false;
	}
}
void Okno::changeY() {
	setCustomProfil();
	if (systemB == false) {
		systemB = true;
		xVelk->setText(doplnky->YtoX(xVelk->getActiv(), yVelk->getActiv(),
				vPomer->getActiv()));
		systemB = false;
	}
}
void Okno::changePomer() {
	setCustomProfil();
	bool str = systemB;
	if (vPomer->getActivePor() == 3) {
		systemB = true;
		yVelk->Clr();
		xVelk->Clr();
		systemB = str;
	} else {
		if (xVelk->get_editable() == false) {
			xVelk->setRiadky(udaje->getVX());
			yVelk->setRiadky(udaje->getVY());
		}
		systemB = true;
		yVelk->setText(doplnky->XtoY(xVelk->getActiv(), yVelk->getActiv(),
				vPomer->getActiv()));
		systemB = str;
	}
}
void Okno::changeTyp(){
	profil->setRiadky(pred->getMena(typ->getActiv()));
}
void Okno::changeProfil() {
	if(systemB != true){
	systemB = true;
	Profil pro = *(pred->getProfil(typ->getActiv(), profil->getActiv()));
	if (pro.getKontainer() != -1) {//nastavenie pre custom
		kontainer->set_activ(pro.getKontainer());
		this->changeKontainer();
		voptions->set_activ(0);
		kodek->set_activ(pro.getKodek());
		x264->set_activ(pro.getX264());
		bitrateV->setText(pro.getBitrateV());
		frame->set_activ(pro.getFramerate());
		vPomer->set_activ(pro.getPomer());
		xVelk->setText(pro.getX());
		yVelk->setText(pro.getY());
		voptions->set_activ(pro.getNastav());
		aoptions->set_activ(0);
		akodek->set_activ(pro.getKodekA());
		achannels->set_activ(pro.getChannel());
		afrekvenci->set_activ(pro.getFrekvencia());
		abitrate->setText(pro.getBitrateA());
		aoptions->set_activ(pro.getNastavA());
	}
	systemB = false;
	}
}
void Okno::changeKontainer() {
	setCustomProfil();
	ObrKont->set(pripony->getKontainer(kontainer->getActivePor())->getCesta());
	zasobnik = pripony->getKontainer(kontainer->getActivePor());
	int doc = voptions->getActivePor();
	int dd = kodek->setRiadky(zasobnik->getVKodeky());
	udaje->setEmpty(dd);
	if(doc != -1 && dd != -1){
		voptions->set_activ(doc);
		changeVOpt();
	}else{
		bitrateV->setRiadky(udaje->getVBitrate());
		frame->setRiadky(udaje->getVFrame());
		bool str = systemB;
		systemB = true;
		yVelk->setRiadky(udaje->getVY());
		xVelk->setRiadky(udaje->getVX());
		systemB = str;
		vPomer->setRiadky(udaje->getVResolution());
		voptions->setRiadky(udaje->geVOptions());
		if(dd == -1)
			x264->Clr();
	}
	udaje->setEmpty(0);
	doc = aoptions->getActivePor();
	if (doc < 1) {
		if (akodek->setRiadky(zasobnik->getAKodeky()) != -1) {//ak existuje aspon jeden kodek
			if (doc == -1) {
				achannels->setRiadky(udaje->getAChannels());
				afrekvenci->setRiadky(udaje->getAVzorkovanie());
				aoptions->setRiadky(udaje->getAOptions());
			}
		}
	}
}
void Okno::exit() {
	klk.exit();
	Gtk::Main::quit();
}
void Okno::klik() {
	if(!klk.isRun()){
		GUI_onb gui;
		gui.set(kontainer->getActiv(), kodek->getActiv(), voptions->getActiv(), 
			vPomer->getActiv(), xVelk->getActiv(), yVelk->getActiv(), bitrateV->getActiv(),
			frame->getActiv(), x264->getActiv(), akodek->getActiv(), aoptions->getActiv(), 
			abitrate->getActiv(), afrekvenci->getActiv(), achannels->getActiv(), outfolder->get_text());
		klk.setGUI(gui,indikator);
		klk.setInfo(tabula->getListInfo());
		klk.run();
	}else{
		klk.exit();
	}
}
	

void Okno::import(){
	Gtk::FileChooserDialog dialog("Please choose a file",
				Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
	dialog.set_current_folder(Glib::get_home_dir());
	int result = dialog.run();
	dialog.hide();
	switch (result) {
		case (Gtk::RESPONSE_OK): {
			File_inport moj;
			int a = moj.inport(dialog.get_filename());
			if(a == 1){
				this->dialog("Invalid profil, TYPE = custom");
			}
			if(a == 0){
				pred->scanFiles();
				typ->setRiadky(pred->getTypy());
				this->dialog("New profil is import ^__^");
			}
			if(a == -1){
				this->dialog("File name alredy exist, rename it!");
			}
			if(a == -2){
				this->dialog("Application error, cannot import");
			}
			break;
		}	
		default: {break;}
	}
}
void Okno::exporting(){
	Glib::ustring src;
	src = (pred->getProfil(typ->getActiv(),profil->getActiv()))->getSub();
	if(src.compare("-1") == 0){
		this->dialog("Custom profile cannot by export, save it");
	}else{
		Gtk::FileChooserDialog dialog("Save file",
				Gtk::FILE_CHOOSER_ACTION_SAVE);
		dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
		dialog.add_button(Gtk::Stock::SAVE,Gtk::RESPONSE_OK);
		dialog.set_current_folder(Glib::get_home_dir());
		dialog.set_current_name(typ->getActiv()+"_"+profil->getActiv());
		dialog.set_do_overwrite_confirmation(true);
		dialog.show();
		int result = dialog.run();
		switch (result) {
		case (Gtk::RESPONSE_OK): {
			Glib::ustring comm = "cp \""+src+"\" \""+dialog.get_filename()+"\"";
			int a = system(comm.c_str());
			break;
		}
		default: {break;}
		}
	}
}
void Okno::about_close_m(int i) {
	about_dialog_m->hide();
}
int Okno::dialog (Glib::ustring text){
	Gtk::MessageDialog *mesDia = new Gtk::MessageDialog(text, false, Gtk::MESSAGE_INFO,
			Gtk::BUTTONS_CLOSE, false);
	mesDia->show();
	if (mesDia->run())
		mesDia->hide();
	delete mesDia;
	return 0;
}
void Okno::vstupneSubory() {
	Gtk::FileChooserDialog *dialog = new Gtk::FileChooserDialog("Please choose a file",
			Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog->add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
	dialog->set_current_folder(Glib::get_home_dir());
	dialog->set_select_multiple(true);
	int result = dialog->run();
	switch (result) {
		case (Gtk::RESPONSE_OK): {
			std::vector<Glib::ustring> filenam = dialog->get_filenames();
			std::string filename = dialog->get_filename();
			for (unsigned int i = 0; i < filenam.size(); i++) {
				tabula->addPrvok(filenam[i]);
			}
			break;
		}		
		case (Gtk::RESPONSE_CANCEL): {
			break;
		}
		default: {
			break;
		}
	}
	delete dialog;
}
void Okno::vystupPriecinok() {
	Gtk::FileChooserDialog dialog("Please choose a folder",
			Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button("Select", Gtk::RESPONSE_OK);

	dialog.set_current_folder(Glib::get_home_dir());
	dialog.show();
	int result = dialog.run();
	switch (result) {
		case (Gtk::RESPONSE_OK): {
			outfolder->set_text(dialog.get_filename());
			break;
		}
		default: {break;}
	}
}
void Okno::save(){
	if(nameWin->getOk()){
		Save_profil saw;
		saw.Basic(kontainer->getActiv(), voptions->getActiv(), aoptions->getActiv());
		saw.Video(kodek->getActiv(), bitrateV->getActiv(), frame->getActiv(), vPomer->getActiv(),
			xVelk->getActiv(), yVelk->getActiv(), x264->getActiv());
		saw.Audio(akodek->getActiv(), achannels->getActiv(), abitrate->getActiv(), afrekvenci->getActiv());
		saw.Save(nameWin->getTyp(), nameWin->getMeno());
		pred->scanFiles();
		typ->setRiadky(pred->getTypy());
		this->dialog("New profil is save");
	}
}
