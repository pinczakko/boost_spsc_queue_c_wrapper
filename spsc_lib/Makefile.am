noinst_LTLIBRARIES = libspscwrapped.la 

AM_CPPFLAGS = $(BOOST_CPPFLAGS) 

AM_CXXFLAGS = -std=c++11
AM_LDFLAGS = $(BOOST_LDFLAGS)

libspscwrapped_la_SOURCES = spsc_interface.hpp \
						spsc_interface.cc \
					    spsc_wrapper.h \
						spsc_wrapper.cc	

libspscwrapped_la_LIBADD = $(BOOST_SYSTEM_LIB) \
					  $(BOOST_THREAD_LIB) \
					  $(BOOST_DATE_TIME_LIB) \
					  $(BOOST_CHRONO_LIB)

