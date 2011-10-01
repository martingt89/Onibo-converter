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

#include "Zobrazovac.h"
#include <iostream>

std::list<Glib::ustring> spracuj(Glib::ustring u);
Zobrazovac::Zobrazovac(Gtk::TreeView* tree, FilWin *ff, int *opt) {
	option = opt;
	m_TreeView = tree;
	std::list<Gtk::TargetEntry> listTargets;
	listTargets.push_back( Gtk::TargetEntry("STRING") );
	listTargets.push_back( Gtk::TargetEntry("text/plain") );
	m_TreeView->drag_dest_set(listTargets);
	m_TreeView->set_rules_hint(true);
	m_TreeView->signal_drag_data_received().connect(sigc::mem_fun(*this,&Zobrazovac::drop));
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
	m_TreeView->set_model(m_refTreeModel);
	m_TreeView->append_column("Filters", m_Columns.m_col_filters);
	m_TreeView->append_column("Name", m_Columns.m_col_name);
	filwin = ff;
	filwin->addSignal(*this, &Zobrazovac::closeFil);
}
Zobrazovac::~Zobrazovac() {
	// TODO Auto-generated destructor stub
}
void Zobrazovac::addPrvok(Glib::ustring u){
	std::list<Information>::iterator iter;
	bool uzje = false;
	for(iter = fil.begin(); iter!= fil.end(); iter++){
		if(iter->getName().compare(u) == 0){
			uzje = true;
			break;
		}
	}
	if(uzje == false){
		row = *(m_refTreeModel->append());
		row[m_Columns.m_col_name] = u;
		row[m_Columns.m_col_filters] = "no";
		Information ff(u);
		fil.push_back(ff);
	}
}
void Zobrazovac::clr(){
	fil.clear();
	m_refTreeModel->clear();
}
void Zobrazovac::drop(
        const Glib::RefPtr<Gdk::DragContext>& context, int, int,
        const Gtk::SelectionData& selection_data, guint, guint time)
{
  const int length = selection_data.get_length();
  if((length >= 0) && (selection_data.get_format() == 8))
  {
	  std::list<Glib::ustring> dat = spracuj(selection_data.get_data_as_string());
	  std::list<Glib::ustring>::iterator datIt;
	  for(datIt=dat.begin(); datIt!=dat.end(); datIt++){
		  char cp[9];
		  strncpy(cp, datIt->c_str(), 8);
		  cp[8] = '\0';
		  if(strcmp(cp, "file:///")==0){
			  addPrvok(Glib::filename_from_uri(*datIt));
		  }
	  }
  }
  context->drag_finish(false, false, time);

}
std::list<Information> Zobrazovac::getListInfo(){
	return fil;
}
std::list<Glib::ustring> spracuj(Glib::ustring u){
	Glib::ustring::iterator tvoj;
	Glib::ustring::iterator moj;
	std::list<Glib::ustring> data;
	Glib::ustring dd = "";
	tvoj = u.begin();
	int i = 0;
	while(tvoj != u.end()){
		moj = tvoj;
		moj++;
		if((*moj) != '\n'){
			dd = dd + (*tvoj);
		}else{
			tvoj++;
			data.push_back(dd);
			i++;
			dd ="";
		}
		tvoj++;
		if(tvoj == u.end()){
			break;
		}
		moj=tvoj;
		moj++;
	}
	return data;
}
int Zobrazovac::getMnozstvo(){
	return fil.size();
}
void Zobrazovac::eraseActiv(){
	Glib::RefPtr<Gtk::TreeSelection> refTree = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTree->get_selected();
	Gtk::TreeModel::Row rowa = *iter;
	if(rowa){
		Glib::ustring u = rowa[m_Columns.m_col_name];
		std::list<Information>::iterator it = fil.begin();
		for(it = fil.begin(); it!= fil.end(); it++){
			if(it->getName().compare(u) == 0){
				fil.erase(it);
				m_refTreeModel->erase(iter);
				break;
			}
		}
	}
}
void Zobrazovac::nastavenia(){
	Glib::RefPtr<Gtk::TreeSelection> refTree = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter = refTree->get_selected();
	Gtk::TreeModel::Row rowa = *iter;
	
	Glib::ustring name = "";
	if(rowa){
		name = rowa[m_Columns.m_col_name];
		std::list<Information>::iterator it;

		it = fil.begin();
		for(it = fil.begin(); it!= fil.end(); it++){
			if(it->getName().compare(name) == 0){
				filwin->setFilter(&(*it));
				filwin->show(*option);
				break;
			}
		}
	}
}
void Zobrazovac::closeFil(){
	Glib::RefPtr<Gtk::TreeSelection> refTree = m_TreeView->get_selection();
	Gtk::TreeModel::iterator iter;
	iter = refTree->get_selected();
	Gtk::TreeModel::Row rowa = *iter;
	if(rowa){
		if(filwin->getChenged() == true){
			rowa[m_Columns.m_col_filters] = "yes";
		}else{
			rowa[m_Columns.m_col_filters] = "no";
		}
	}
}
