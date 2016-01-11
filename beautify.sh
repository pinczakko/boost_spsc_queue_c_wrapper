#!/bin/sh

find . -type f -name "*.cc" | xargs astyle --style=stroustrup 
find . -type f -name "*.hpp" | xargs astyle --style=stroustrup 
find . -type f -name "*.[ch]" | xargs indent -linux 

### cleanup remnant files
find . -type f -name "*~" | xargs rm -vf
find . -type f -name "*.orig" | xargs rm -vf 
