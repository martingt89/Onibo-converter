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

#include "Jadro.h"
#include <iostream>
Jadro::Jadro() {
	chipid = -1;
	info = NULL;
}
Jadro::~Jadro() {

}

void Jadro::set(Information* inf, GUI_onb g,  Info * info, int poc){
	information = inf;
	this->info = info;
	this->info->setPocet(poc);
	gui = g;
}

void Jadro::start() {
	thread = Glib::Thread::create(sigc::mem_fun(*this, &Jadro::run), false);
}

void Jadro::run() { //only one instance thread can by run
	std::cout<<"RUN convert"<<std::endl;
	Glib::Mutex::Lock lock(mutex);
	Generator gen(gui, information);
	Glib::ustring command = gen.run();
	info->setStatus(-1);
	//info->setNazov(information->getName());
	status = 0;
	ex_duration = -1;
	ex_duration = information->getEnd() - information->getStart();
	int pc[2]; /* Parent to child pipe */
	int cp[2]; /* Child to parent pipe */
	int pid;
	chipid = -1;
	char ch;
	int assd = -1;
	int stat = 0;
	if (info->getConvert() == true) {
		if (pipe(pc) >= 0 && pipe(cp) >= 0) {
			switch (pid = fork()) {
			case -1:
				std::cout<<"ABORT"<<std::endl;
				abort(); //internal error
			case 0: /* Child. */
				close(2); /* Close current stderr. */
				if(dup(cp[1]) < 0 ){ /* Make stderr go to write end of pipe. */
					stat = -1;
				} 
				close(0); /* Close current stdin. */
				if(dup(pc[0]) < 0 ){ /* Make stdin come from read end of pipe. */
					stat = -1;
				} 
				close(pc[1]);
				close(cp[0]);
				if(stat != -1){
					assd = system(command.c_str());
					std::cerr<<"onibo_status="<<assd<<std::endl;
				}
				abort(); //exit proces
			default:
				chipid = pid;
				close(pc[1]);
				close(cp[1]);
				Glib::ustring riadok = "";
				while (read(cp[0], &ch, sizeof(char)) == 1) {
					if (ch == '\r' || ch == '\n') {
						analyza(riadok);
						riadok = "";
					} else {
						riadok = riadok + ch;
					}
				}
				wait(NULL); //wait for close child proces
				chipid = -1;
			}
		} else {
			status = 4; //system error
		}
	} else {
		status = 3;
	}
	info->setFragment(0);
	info->setStatus(status);
	message();
	thread_done();
}
void Jadro::analyza(Glib::ustring u) {
	if (u.size() != 0) {
		std::cout<<u<<std::endl;
		double pozicia = 0;
		const char * cas = strstr(u.c_str(), "time=");
		if (cas != NULL) {
			pozicia = atoi(cas + 5);
			const char * cas2 = strstr(cas, ".");
			if (cas2 != NULL) {
				int des = atoi(cas2 + 1);
				pozicia = pozicia + des / 100.0;
			}
			if (dlzkaVidea != 0) {
				struct timeval time;
				struct timezone timez;
				int rc;
				rc = gettimeofday(&time, &timez);
				if (rc == 0) {
					double akt_cas = time.tv_sec + (time.tv_usec * 1.0 / 1000000);
					info->addTime(pozicia, akt_cas, dlzkaVidea);
				}
				info->setFragment((pozicia * 1.0) / dlzkaVidea);
				message();
			}
		} else {
			const char * vys = strstr(u.c_str(), "onibo_status=");
			if(vys != NULL){
			int stat = atoi(vys+13);
				if(stat != 0 && status == 0){
					status = 10;
				}
			}
			const char * pch = strstr(u.c_str(), "Duration:");
			if (pch != NULL) {
				int hod = 0;
				int min = 0;
				int sek = 0;
				hod = atoi((pch + 10));
				min = atoi(pch + 13);
				sek = atoi(pch + 16);
				if(ex_duration != -1){
					dlzkaVidea = ex_duration;
				}else{
					dlzkaVidea = sek + min * 60 + hod * 3600;
				}
			} else {
				const char * nejde = strstr(u.c_str(), "Permission denied");
				if (nejde != NULL) {
					status = 1;
				} else {
					const char * invalid = strstr(u.c_str(),
							"Invalid data found");
					if (invalid != NULL) {
						status = 5;
					}
					const char * invali = strstr(u.c_str(),
							"Operation not permitted");
					if (invali != NULL) {
						status = 6;
					}
					const char * fold = strstr(u.c_str(),
							"No such file or directory");
					if (fold != NULL) {
						status = 7;
					}
				}
			}
		}
	}
}

void Jadro::exit() {
	if (info) {
		info->setCovert(false);
	}
	Glib::ustring prikaz;
	int dieta = chipid;
	prikaz = "killtree() { \nlocal _pid=$1 \nlocal _sig=${2-TERM} "
		"\nfor _child in $(ps -o pid --no-headers --ppid ${_pid}); do "
		"\nkilltree ${_child} ${_sig} \ndone \nkill -9 ${_pid}"
		"\n} \nkilltree $@" + Glib::ustring::format(dieta);
	if (dieta > -1) {
		int ss = system(prikaz.c_str());
		status = 3;
		info->setStatus(status);
	}
	if (info) {
		info->setStatus(3);
	}
}
