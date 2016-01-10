bin_PROGRAMS = wrapper_test

AM_CPPFLAGS = -I$(top_srcdir)/spsc_lib \
			$(BOOST_CPPFLAGS) 

AM_CXXFLAGS = -std=c++11
AM_LDFLAGS = $(BOOST_LDFLAGS)

wrapper_test_SOURCES = wrapper_test.c 
### Below is just a trick to force using C++ linker
nodist_EXTRA_wrapper_test_SOURCES = dummy.cc 

wrapper_test_LDFLAGS = -pthread
wrapper_test_LDADD = $(top_builddir)/spsc_lib/libspscwrapped.la \
					  $(BOOST_SYSTEM_LIB) \
					  $(BOOST_THREAD_LIB) \
					  $(BOOST_DATE_TIME_LIB) \
					  $(BOOST_CHRONO_LIB)
