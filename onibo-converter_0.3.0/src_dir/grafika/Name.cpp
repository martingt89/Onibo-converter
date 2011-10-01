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

#include "Name.h"
#include <iostream>
Name::Name(Gloader* glo) {
	set = false;
	label = glo->get<Gtk::Label*>("warning");
	winT = glo->get<Gtk::Window*>("window3");
	okT = glo->get<Gtk::Button*>("win3OK");
	closeT = glo->get<Gtk::Button*>("win3Close");
	typeT = glo->get<Gtk::Entry*>("win3typ");
	subTypT = glo->get<Gtk::Entry*>("win3subtyp");
	okT->signal_clicked().connect(sigc::mem_fun(*this, &Name::funOk));
	closeT->signal_clicked().connect(sigc::mem_fun(*this, &Name::hide));
}

Name::~Name() {
	// TODO Auto-generated destructor stub
}
void Name::funOk(){
	typT = typeT->get_text();
	menoT = subTypT->get_text();
	if(typT.size()!=0 && menoT.size()!= 0 && typT.compare(CUSTOMPROFIL)!= 0){
		set = true;
		winT->hide();
	}else{
		if(typT.compare(CUSTOMPROFIL) == 0)
			label->set_text("Typ cannot by \"" CUSTOMPROFIL "\"");
		set = false;
	}
}
bool Name::getOk(){
	return set;
}
void Name::show(){
	set = false;
	label->set_text("");
	typeT->set_text("");
	subTypT->set_text("");
	winT->show();
}
