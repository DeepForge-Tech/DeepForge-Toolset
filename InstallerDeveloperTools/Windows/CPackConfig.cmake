# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows;C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENTS_ALL "major;devel")
set(CPACK_COMPONENTS_ALL_SET_BY_USER "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/msys64/mingw64/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "InstallerDeveloperTools built using CMake")
set(CPACK_GENERATOR "RPM")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows;InstallerDeveloperTools;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/InstallerDeveloperTools")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "InstallerDeveloperTools 0.1.1")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "InstallerDeveloperTools 0.1.1")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "C:/msys64/mingw64/bin/objcopy.exe")
set(CPACK_OBJDUMP_EXECUTABLE "C:/msys64/mingw64/bin/objdump.exe")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/msys64/mingw64/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Installer DeveloperTools")
set(CPACK_PACKAGE_FILE_NAME "InstallerDeveloperTools-0.1.1-win64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "InstallerDeveloperTools 0.1.1")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "InstallerDeveloperTools 0.1.1")
set(CPACK_PACKAGE_NAME "InstallerDeveloperTools")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "0.1.1")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_READELF_EXECUTABLE "C:/msys64/mingw64/bin/readelf.exe")
set(CPACK_RESOURCE_FILE_LICENSE "C:/msys64/mingw64/share/cmake/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "C:/msys64/mingw64/share/cmake/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/msys64/mingw64/share/cmake/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_COMPONENT_INSTALL "ON")
set(CPACK_RPM_DEBUGINFO_PACKAGE "ON")
set(CPACK_RPM_DEBUGINFO_SINGLE_PACKAGE "ON")
set(CPACK_RPM_FILE_NAME "RPM-DEFAULT")
set(CPACK_RPM_MAIN_COMPONENT "major")
set(CPACK_RPM_PACKAGE_RELEASE "10")
set(CPACK_RPM_PACKAGE_RELEASE_DIST "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/Blackflame576/Documents/Blackflame576/DigitalBit/DeveloperTools/InstallerDeveloperTools/Windows/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()

# Configuration for component "major"
set(CPACK_COMPONENT_MAJOR_DESCRIPTION "Something for demo")

# Configuration for component "devel"
set(CPACK_COMPONENT_DEVEL_DESCRIPTION "For Development")
