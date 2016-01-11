#!/bin/sh

## NOTE:
## -----
## - Passing native linker flag via LDFLAGS worked as documented in libtool. 
##

case "$1" in 

	clean) if [ ! -d _debug ]; then
				echo "_debug directory does not exist. Terminating script.."
		   else 
		   		cd _debug
		   		make distclean
		   		rm -rf *
		   		cd ..
   		   fi
		;;


	*)	if [ ! -d _debug ]; then
				echo "_debug directory does not exist. Creating directory.."
				mkdir -v _debug
		else
				echo "_debug directory exists. Cleaning up.."
				cd _debug
				rm -rf *
				cd ..
		fi
		cd _debug
		../configure CFLAGS="-DDEBUG=1 -g -O0" CXXFLAGS="-DDEBUG=1 -g -O0" && make V=1
		cd ..
		;;
esac
