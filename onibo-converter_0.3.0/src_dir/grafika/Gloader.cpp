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

#include "Gloader.h"
#define GUI "GUI/GUI.glade"
Gloader::Gloader() {
	err = 0;
	Glib::ustring chyba = "";
	//Load the GtkBuilder file and instantiate its widgets:
	refBuilder = Gtk::Builder::create();
#ifdef GLIBMM_EXCEPTIONS_ENABLED
	try
	{
		refBuilder->add_from_file(GUI);
	}
	catch(const Glib::FileError& ex)
	{
		chyba = "FileError: " + ex.what();
		err = 1;
	}
	catch(const Gtk::BuilderError& ex)
	{
		chyba = "BuilderError: " + ex.what();
		err = 1;
	}
#else
	std::auto_ptr < Glib::Error > error;

	if (!refBuilder->add_from_file("GUI.glade", error)) {
		chyba = error->what();
		err = 1;
	}
#endif /* !GLIBMM_EXCEPTIONS_ENABLED */
}
Gloader::~Gloader() {
	// TODO Auto-generated destructor stub
}
int Gloader::getOK() {
	return err;
}

Gtk::ComboBox* Gloader::getTypBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("type_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getProfilBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("subtype_box", comb);
	return comb;
}
Gtk::Entry* Gloader::getOutput() {
	Gtk::Entry *ent;
	refBuilder->get_widget("vystup_entry", ent);
	return ent;
}
//video
Gtk::ComboBox* Gloader::getVCodecBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("v_codec_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getVContBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("b_cont_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getVFraBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("v_frame_box", comb);
	return comb;
}
Gtk::ComboBoxEntry *Gloader::getVXEntry() {
	Gtk::ComboBoxEntry *ent;
	refBuilder->get_widget("v_x_boxentry", ent);
	return ent;
}
Gtk::ComboBoxEntry *Gloader::getVYEntry() {
	Gtk::ComboBoxEntry *ent;
	refBuilder->get_widget("v_y_boxentry", ent);
	return ent;
}
Gtk::ComboBox* Gloader::getVOptBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("b_vid_options_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getVRezolBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("v_resolution_box", comb);
	return comb;
}
Gtk::ComboBoxEntry* Gloader::getVBitrate() {
	Gtk::ComboBoxEntry *ent;
	refBuilder->get_widget("v_bitrate_boxentry", ent);
	return ent;
}
Gtk::ComboBox* Gloader::getVx264Box() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("v_x264_box", comb);
	return comb;
}
//Audio
Gtk::ComboBox* Gloader::getACodBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("a_codec_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getAOptBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("b_aud_options_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getAChanBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("a_channel_box", comb);
	return comb;
}
Gtk::ComboBox* Gloader::getARateBox() {
	Gtk::ComboBox* comb;
	refBuilder->get_widget("a_rate_box", comb);
	return comb;
}
Gtk::ComboBoxEntry* Gloader::getABitrate() {
	Gtk::ComboBoxEntry *ent;
	refBuilder->get_widget("a_bitrate_boxentry", ent);
	return ent;
}
//doplnky
Gtk::TreeView* Gloader::getZobraz() {
	Gtk::TreeView* zob;
	refBuilder->get_widget("treeview1", zob);
	return zob;
}
Gtk::ProgressBar* Gloader::getBar() {
	Gtk::ProgressBar* bar;
	refBuilder->get_widget("progressbar1", bar);
	return bar;
}
Gtk::ImageMenuItem* Gloader::getMenuAbout(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("imagemenuitem1", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuOpen(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("imagemenuitem3", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuSave(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("imagemenuitem4", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuClose(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("imagemenuitem5", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuStart(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("imagemenuitem2", abo);
	return abo;
}

Gtk::ImageMenuItem* Gloader::getMenuImport(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("import_profil", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuExport(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("export_profil", abo);
	return abo;
}
Gtk::ImageMenuItem* Gloader::getMenuSavePro(){
	Gtk::ImageMenuItem* abo;
	refBuilder->get_widget("save_profil", abo);
	return abo;
}
Gtk::MenuItem* Gloader::getMenuFilter(){
	Gtk::MenuItem* abo;
	refBuilder->get_widget("filter_item", abo);
	return abo;
}
