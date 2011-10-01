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

#include "Information.h"
#include <iostream>

Information::Information(Glib::ustring na) {
	name = na;
	yup = 0;
	ydown = 0;
	xright = 0;
	xleft = 0;
	start_time = 0;
	end_time = -1;
	deinter = false;
	duration = -1;
	x = 0;
	y = 0;
	resolution = true;
}


Information::~Information() {
	// TODO Auto-generated destructor stub
}
Glib::ustring Information::getName(){
	return name;
}
Glib::ustring Information::getParametre(Glib::ustring u){
	Glib::ustring par = "";
	if(start_time != 0){
		std::cout<<start_time<<std::endl;
		par += " -ss "+Glib::ustring::format(start_time);
	}
	if(end_time != -1){
		std::cout<<end_time - start_time<<std::endl;
		par += " -t "+Glib::ustring::format(end_time - start_time);
	}
	if(u.compare(CUSTOMVIDEO)==0 && yup+ydown+xright+xleft != 0){
		if(yup != 0){
			par += " -croptop "+Glib::ustring::format(yup);
		}
		if(ydown != 0){
			par += " -cropbottom "+Glib::ustring::format(ydown);
		}
		if(xright != 0){
			par += " -cropright "+Glib::ustring::format(xright);
		}
		if(xleft != 0){
			par += " -cropleft "+Glib::ustring::format(xleft);
		}
	}
	if(u.compare(CUSTOMVIDEO)==0 && deinter == true){
		par+= " -deinterlace";
	}
	return par;
}
void Information::set(int yu, int yd, int xl, int xr, double st, double et, bool de, bool re){
	yup = yu;
	ydown = yd;
	xright = xr;
	xleft = xl;
	start_time = st;
	end_time = et;
	deinter = de;
	resolution = re;
}
void Information::setDuration(double dd){
	duration = dd;
}
void Information::setResol(int a, int b){
	x = a;
	y = b;
}
double Information::getDuration(){
	return duration;
}
int Information::getX(){
	return x;
}
int Information::getY(){
	return y;
}
int Information::getYUp(){
	return yup;
}
int Information::getYdown(){
	return ydown;
}
int Information::getXLeft(){
	return xleft;
}
int Information::getXright(){
	return xright;
}
double Information::getStart(){
	return start_time;
}
double Information::getEnd(){
	return end_time;
}
bool Information::getDein(){
	return deinter;
}
bool Information::getReso(){
	return resolution;
}
bool Information::getEdit(){
	if((yup+ydown+xright+xleft)!=0){
		return true;
	}
	if(start_time != 0 || end_time != -1){
		return true;
	}
	if(deinter != false || resolution != true){
		return true;
	}
	return false;
}
