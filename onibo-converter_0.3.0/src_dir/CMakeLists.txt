link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(onibo-converter # name of the executable on Windows will be example.exe 
    main.cpp
    grafika/Gloader.cpp grafika/Gloader.h grafika/Indikator.cpp grafika/Indikator.h
    grafika/Name.cpp grafika/Name.h grafika/Okno.cpp grafika/Okno.h
    grafika/Vysledky.cpp grafika/Vysledky.h grafika/Vysuvatko.cpp grafika/Vysuvatko.h
    grafika/Zamok.cpp grafika/Zamok.h grafika/Zobrazovac.cpp grafika/Zobrazovac.h
    grafika/FilWin.cpp grafika/FilWin.h grafika/GUI.h
    jadro/Davkovac.cpp jadro/Davkovac.h
    jadro/Doplnky.cpp jadro/Doplnky.h
    jadro/Generator.cpp jadro/Generator.h
    jadro/Info.cpp jadro/Info.h
    jadro/Jadro.cpp jadro/Jadro.h
    jadro/Analyza.cpp jadro/Analyza.h
    jadro/File_Onb.cpp jadro/File_Onb.h
    jadro/Klik.cpp jadro/Klik.h
    
    prof/File_convert.cpp
	prof/File_convert.h
	prof/File_inport.cpp
	prof/File_inport.h
	prof/File_load.cpp
	prof/File_load.h
	prof/Check_config_dir.cpp
	prof/Check_config_dir.h
	prof/Save_profil.cpp
	prof/Save_profil.h
	prof/Zberac.cpp
	prof/Zberac.h
	video/AudioKodeky.cpp
	video/AudioKodeky.h
	video/AudioPrekladac.cpp
	video/AudioPrekladac.h
	video/AudioVorbis.cpp
	video/AudioVorbis.h
	video/BasicKon.cpp
	video/BasicKon.h
	video/Kontainer.cpp
	video/Kontainer.h
	video/Loader.cpp
	video/Loader.h
	video/Profil.cpp
	video/Profil.h
	video/Type.cpp
	video/Type.h
	video/Udaje.cpp
	video/Udaje.h
	video/VideoKodeky.cpp
	video/VideoKodeky.h
	video/VideoPrekladac.cpp
	video/VideoPrekladac.h
	video/Information.cpp
	video/Information.h
    )

target_link_libraries(onibo-converter ${GTKMM_LIBRARIES})
    
#executable
install(TARGETS onibo-converter DESTINATION /usr/share/onibo-converter/)
