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

#ifndef ZOBRAZOVAC_H_
#define ZOBRAZOVAC_H_

#include <gtkmm/liststore.h>
#include <gtkmm/treeview.h>
#include "FilWin.h"
#include "../video/Information.h"
class Zobrazovac {
private:
	class ModelColumns: public Gtk::TreeModel::ColumnRecord {
	public:
		ModelColumns() {
			add(m_col_name);
			add(m_col_filters);
		}
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
		Gtk::TreeModelColumn<Glib::ustring> m_col_filters;
	};
//private:
	ModelColumns m_Columns;
	Gtk::TreeView *m_TreeView;
	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
	Gtk::TreeModel::Row row;
	std::list<Information> fil;
	FilWin* filwin;
	int *option;
public:
	Zobrazovac(Gtk::TreeView*, FilWin *, int *opt);
	virtual ~Zobrazovac();
	void addPrvok(Glib::ustring u);
	void clr();
	void drop(const Glib::RefPtr<Gdk::DragContext>& context, int x, int y,
			const Gtk::SelectionData& selection_data, guint info, guint time);
	std::list<Information> getListInfo();
	int getMnozstvo();
	void eraseActiv();
	void nastavenia();
	void closeFil();
	template<class T_return, class T_obj, class T_obj2>
		void addSignal(T_obj& _A_obj, T_return(T_obj2::* _A_func)()) {
			Glib::RefPtr < Gtk::TreeSelection > refTree
					= m_TreeView->get_selection();
			refTree->signal_changed().connect(sigc::mem_fun(_A_obj, _A_func));
		}
};

#endif /* ZOBRAZOVAC_H_ */
