#!/bin/sh

## NOTE:
## -----
## - Passing native linker flag via LDFLAGS worked as documented in libtool though. 
##
##

case "$1" in 

	clean) if [ ! -d _release ]; then
				echo "_release directory does not exist. Terminating script.."
		   else
			cd _release
			make distclean
			rm -rf *
			cd ..
		   fi
		;;

	*) 	if [ ! -d _release ]; then
			echo "_release directory does not exist. Creating directory.."
			mkdir -v _release
		else
			echo "_release directory exists. Cleaning up.."
			cd _release
			rm -rf *
			cd ..
	   	fi
		cd _release
	   	../configure CFLAGS="-DNDEBUG=1 -O3" CXXFLAGS="-DNDEBUG=1 -O3" && make V=1 
	   	cd ..
	   ;;
esac
