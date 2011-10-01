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

#ifndef GLOADER_H_
#define GLOADER_H_
#include <gtkmm/combobox.h>
#include <gtkmm/comboboxentry.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/builder.h>
#include <gtkmm/textview.h>
#include <gtkmm/aboutdialog.h>
#include <gtkmm/label.h>
#include <iostream>
class Gloader {
private:
	int err;
	Glib::RefPtr<Gtk::Builder> refBuilder;

public:
	Gloader();
	virtual ~Gloader();
	int getOK();

	Gtk::ComboBox* getProfilBox();
	Gtk::ComboBox* getTypBox();
	Gtk::Entry* getOutput();

	Gtk::ComboBox* getVCodecBox();
	Gtk::ComboBox* getVContBox();
	Gtk::ComboBox* getVOptBox();
	Gtk::ComboBox* getVRezolBox();
	Gtk::ComboBox* getVFraBox();
	Gtk::ComboBox* getVx264Box();
	Gtk::ComboBoxEntry *getVXEntry();
	Gtk::ComboBoxEntry *getVYEntry();
	Gtk::ComboBoxEntry* getVBitrate();

	/*         audio          */
	Gtk::ComboBox* getACodBox();
	Gtk::ComboBox* getAOptBox();
	Gtk::ComboBox* getAChanBox();
	Gtk::ComboBox* getARateBox();
	Gtk::ComboBoxEntry* getABitrate();

	Gtk::TreeView* getZobraz();
	Gtk::ProgressBar* getBar();

	Gtk::ImageMenuItem* getMenuAbout();
	Gtk::ImageMenuItem* getMenuOpen();

	Gtk::ImageMenuItem* getMenuSave();
	Gtk::ImageMenuItem* getMenuClose();
	Gtk::ImageMenuItem* getMenuStart();

	Gtk::ImageMenuItem* getMenuImport();
	Gtk::ImageMenuItem* getMenuExport();
	Gtk::ImageMenuItem* getMenuSavePro();
	Gtk::MenuItem* getMenuFilter();
	//
	template <class T>
	T get (Glib::ustring men) {
		T typ;
		refBuilder->get_widget(men, typ);
		return typ;
	}
};

#endif /* GLOADER_H_ */
