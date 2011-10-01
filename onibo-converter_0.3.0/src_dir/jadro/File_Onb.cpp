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
 
#include "File_Onb.h"
#include <iostream>

File_Onb::File_Onb(){

}
File_Onb::~File_Onb(){

}
void File_Onb::set(Glib::ustring ces){
	exist = stat(ces.c_str(),&st);
}
void File_Onb::setHmm(Glib::ustring ces, Glib::ustring ces2, Glib::ustring prip){
	Glib::ustring::size_type a = ces.rfind("/");
	Glib::ustring sub = "";
	if(a){
		sub = Glib::ustring(ces.c_str()+a+1);
	}else{
		sub = ces;
	}
	if(ces2.size() != 0){
		if(*(ces2.c_str()+ces2.size()-1) != '/'){
			ces2 += "/";
		}
	}
	Glib::ustring vys = ces2+sub+"."+prip;
	exist = stat(vys.c_str(),&st);

}
bool File_Onb::getFile(){
if (exist == 0 && S_ISREG (st.st_mode)) {
	return true;
}
return false;
}
bool File_Onb::getDirectory(){
if (exist == 0 && S_ISDIR (st.st_mode)) {
	return true;
}
return false;
}
bool File_Onb::getExist(){
if(exist != 0){
	return true;
}
return false;
}
