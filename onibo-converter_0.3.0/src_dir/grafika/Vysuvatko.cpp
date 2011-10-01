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

#include "Vysuvatko.h"

Vysuvatko::Vysuvatko() {
	m_Columns = new ModelColumns();
	por = 0;
}

Vysuvatko::~Vysuvatko() {
	// TODO Auto-generated destructor stub
}
void Vysuvatko::setCombo(Gtk::ComboBox* ko){
	kombo = ko;
	m_refTreeModel = Gtk::ListStore::create(*m_Columns);
	kombo->set_model(m_refTreeModel);
}
void Vysuvatko::addRiadok(Glib::ustring nazov){
	row = *(m_refTreeModel->append());
	row[m_Columns->m_col_name] = nazov;
	row[m_Columns->m_col_id] = por;
	por++;
}
int Vysuvatko::setRiadky(std::list<Glib::ustring> data){
	Clr();
	std::list<Glib::ustring>::iterator iter;
	int i = 0;
	for(iter = data.begin(); iter!= data.end(); iter++){
		addRiadok(*iter);
		i++;
	}

	if(i == 0){
		return -1;
	}
	Start(0);
	return 0;
}
void Vysuvatko::Start(int i){
	kombo->pack_start(m_Columns->m_col_name);
	if(!(i<0)){
		kombo->set_active(i);
	}
}
void Vysuvatko::Clr(){
	por = 0;
	kombo->unset_model();
	kombo->clear ();
	m_refTreeModel= Gtk::ListStore::create(*m_Columns);
	kombo->set_model(m_refTreeModel);
}
void Vysuvatko::set_activ(int i){
	kombo->set_active(i);
}
Glib::ustring Vysuvatko::getActiv(){
	Gtk::TreeModel::iterator iter = kombo->get_active();
	Glib::ustring name;
	if(iter){
		Gtk::TreeModel::Row rowa = *iter;
		if(rowa){
			name = rowa[m_Columns->m_col_name];
			//std::cout<<"id riadku: "<<rowa[m_Columns->m_col_id]<<std::endl;
		}
	}else{
		name = "-1";
	}
	return name;
}
int Vysuvatko::getActivePor(){
	Gtk::TreeModel::iterator iter = kombo->get_active();
	if(iter){
		Gtk::TreeModel::Row rowa = *iter;
		return rowa[m_Columns->m_col_id];
	}
	return -1;
}

VysuvatkoEntry::VysuvatkoEntry() {
	// TODO Auto-generated destructor stub
}

VysuvatkoEntry::~VysuvatkoEntry() {
	// TODO Auto-generated destructor stub
}
void VysuvatkoEntry::setCombo(Gtk::ComboBoxEntry* ko){
	kombo = ko;
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	kombo->set_model(m_refTreeModel);
}
void VysuvatkoEntry::addRiadok(Glib::ustring nazov){
	row = *(m_refTreeModel->append());
	row[m_Columns.m_col_name] = nazov;
}
int VysuvatkoEntry::setRiadky(std::list<Glib::ustring> data){
	Clr();
	this->set_editable(true);
	std::list<Glib::ustring>::iterator iter;
	int i = 0;
	for(iter = data.begin(); iter!= data.end(); iter++){
		addRiadok(*iter);
		i++;
	}
	if(i == 0){
		this->set_editable(false);
		return -1;
	}
	Start(0);
	return 0;
}
void VysuvatkoEntry::Start(int i){
	kombo->set_text_column(m_Columns.m_col_name);
	if(!(i<0)){
		kombo->set_active(i);
	}
}
void VysuvatkoEntry::Clr(){
	kombo->unset_model();
	Gtk::Entry *ent = kombo->get_entry ();
	ent->set_text("");
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	kombo->set_model(m_refTreeModel);
	this->set_editable(false);
}
Glib::ustring VysuvatkoEntry::getActiv(){
	Gtk::Entry* entry = kombo->get_entry();
	Glib::ustring name;
	if(entry){
		name = entry->get_text();
	}else{
		name = "!";
	}
	return name;
}
void VysuvatkoEntry::setText(Glib::ustring u){
	Gtk::Entry* entry = kombo->get_entry();
	entry->set_text(u);
}
void VysuvatkoEntry::set_editable(bool ano){
	Gtk::Entry* entry = kombo->get_entry();
	entry->set_editable(ano);
}
bool VysuvatkoEntry::get_editable(){
	Gtk::Entry* entry = kombo->get_entry();
	return entry->get_editable();
}
