cmake_minimum_required(VERSION 2.8)

project(onibo-converter)

set(CMAKE_CXX_FLAGS "-O2 -Wall")

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-2.4) # look into FindPkgConfig.cmake, 
                                                                # it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES 
# contain what you expect 

add_subdirectory(src_dir) 

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/my_cmake_script/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/my_cmake_script/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/my_cmake_script/cmake_uninstall.cmake")


#executable
INSTALL(PROGRAMS dat_dir/script/onibo-converter DESTINATION /usr/bin/)
INSTALL(PROGRAMS exe_dir/ffmpeg DESTINATION /usr/share/onibo-converter/ffmpeg/)
#menu item
INSTALL(FILES dat_dir/GUI/onibo-converter.png DESTINATION /usr/share/pixmaps/)
INSTALL(PROGRAMS dat_dir/menu/onibo-converter.desktop DESTINATION  /usr/share/applications/)
#folders
INSTALL(DIRECTORY dat_dir/ffmpeg DESTINATION /usr/share/onibo-converter/)
INSTALL(DIRECTORY dat_dir/GUI DESTINATION /usr/share/onibo-converter/)
INSTALL(DIRECTORY dat_dir/images DESTINATION /usr/share/onibo-converter/)
INSTALL(DIRECTORY dat_dir/profils DESTINATION /usr/share/onibo-converter/)
#copyright
INSTALL(FILES dat_dir/license/copyright DESTINATION /usr/share/doc/onibo-converter/)
