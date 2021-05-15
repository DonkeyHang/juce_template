#!/bin/bash

# NEWPROJECT BUILD SCRIPT

NEWPROJECT_DIR="$(dirname $0)"; # save the directory of the script

ZIPPING=0;
TESTING=0;


###  UTILITY FUNCTIONS  ###

# function to check if a requested command is valid
command_exists () {
	loc="$(type "$1" > /dev/null)" || [[ -z "$loc" ]] ;
}

# no cmake, and you're on Windows :(
windows_no_cmake () {
	printf "\n \t \v CMake cannot be found, and I've detected you're on Windows. \n"
	printf "\t Installing software from the command line on Windows is the realm of gods and demons. \n"
	printf "Please manually install CMake and re-run this script. \n"
	exit 1
}

enable_zip () {
	ZIPPING=1;
  	printf "A .zip containing all the NewProject artefacts will be created after the build is complete. \n"
}

unknown_argument () {
	printf "\v Unknown argument '$1'. For usage, run this script with --help or -h. \n"
	exit 0;
}


###  CHECK FOR FLAGS & ARGUMENTS  ###

# check to see if the script was invoked with the --help or -h flags
if [[ ${#@} -ne 0 ]] && ( [[ ${@#"--help"} = "" ]] || [[ ${@#"-h"} = "" ]] ); then
 	printf "\n \t \v NEWPROJECT BUILD SCRIPT \n USAGE: \n \n"
  	printf "Simply execute this script with no flags or arguments to build a default release confguration of NewProject in VST, AU and Standalone formats. \n"
  	printf "Invoke this script with the --zip or -z flags to zip the build artifacts together into one .zip file upon completion of the build. \n"
  	exit 0;
fi


for flag in "$@" ; do
	case "$flag" in
		--zip*)  enable_zip ;;
		-z*)	 enable_zip ;;
		*)		 unknown_argument "$flag" ;;
	esac
done


###  CMAKE INSTALLATION  ###

# if CMake can't be found, install it
if ! command_exists cmake ; then
	case "$OSTYPE" in
		darwin*) printf "\n \t \v Installing CMake... \n \n" && brew install cmake ;;  # MacOS
		msys*)   windows_no_cmake ;;
		*)       printf "\n \t \v Installing Cmake... \n \n" && sudo apt-get -y install cmake ;;  # Linux
	esac
fi


# if CMake still can't be found, there must be some error
if ! command_exists cmake ; then
	printf "\n \t \v CMake could not be found, and could not be automatically installed. \n Please manually install CMake and then re-run this script. \n"
	exit 1
fi


###  THE BUILD SCRIPT  ###

cd "$NEWPROJECT_DIR" # assume that the directory of the script is also the location of the local Imogen git clone

# first, make sure the local copy of the repo is up to date
printf "\n \t \v Checking for new commits to NewProject remote... \n \n"
git pull --recurse-submodules=yes


set -e;  # from this point forward, any errors trigger an exit signal


# configure CMake
printf "\n \t \v Configuring CMake... \n \n"
cmake -DCMAKE_BUILD_TYPE=release -B Builds -DKickLab_unitTesting=FALSE -Dbv_alwaysForceCacheInits=TRUE .


# execute build
printf "\n \t \v Building NewProject... \n \n"
cmake --build Builds --target KickLab_All --config Release


# zip artifacts (if requested by user)
if [ "$ZIPPING" -eq "1" ] ; then
	set +e;  # an error in zipping shouldn't be fatal
	printf "\n \t \v Zipping artifacts... \n \n"
	cd Builds
	cmake -E tar cfv KickLab.zip --format=zip KickLab_artefacts/
fi


printf "\n \t \v NewProject built successfully!"
printf "\n \t \v Enjoy! \n"

exit 0;

###

