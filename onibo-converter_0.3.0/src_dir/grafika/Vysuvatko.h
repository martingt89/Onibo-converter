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

#ifndef VYSUVATKO_H_
#define VYSUVATKO_H_
#include <gtkmm/comboboxentry.h>
#include <gtkmm/liststore.h>
#include "../jadro/Doplnky.h"
class ModelColumns: public Gtk::TreeModel::ColumnRecord {
public:
	ModelColumns() {
		add(m_col_name);
		add(m_col_id);
	}
	Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	Gtk::TreeModelColumn<int> m_col_id;
};

class Vysuvatko {
private:
	ModelColumns *m_Columns;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	Gtk::TreeModel::Row row;
	Glib::RefPtr<Gtk::TreeModel> niec;
	Gtk::ComboBox* kombo;
	sigc::connection conn;
	int por;
	void addRiadok(Glib::ustring);
	void Start(int);
public:
	Vysuvatko();
	virtual ~Vysuvatko();
	void setCombo(Gtk::ComboBox*);
	int setRiadky(std::list<Glib::ustring> data);
	void Clr();
	Glib::ustring getActiv();
	int getActivePor();
	void set_activ(int);
	template<class T_return, class T_obj, class T_obj2>
	void addSignal(T_obj& _A_obj, T_return(T_obj2::* _A_func)()) {
		conn = kombo->signal_changed().connect(sigc::mem_fun(_A_obj, _A_func));
	}
};

class VysuvatkoEntry {
private:
	ModelColumns m_Columns;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	Gtk::TreeModel::Row row;
	Gtk::ComboBoxEntry* kombo;
	void Start(int);
	void addRiadok(Glib::ustring);
public:
	VysuvatkoEntry();
	virtual ~VysuvatkoEntry();
	void setCombo(Gtk::ComboBoxEntry*);
	int setRiadky(std::list<Glib::ustring> data);
	void Clr();
	Glib::ustring getActiv();
	void setText(Glib::ustring);
	void set_editable(bool);
	template<class T_return, class T_obj, class T_obj2>
	void addSignal(T_obj& _A_obj, T_return(T_obj2::* _A_func)()) {
		kombo->signal_changed().connect(sigc::mem_fun(_A_obj, _A_func));
	}
	bool get_editable();
};
#endif /* VYSUVATKO_H_ */
