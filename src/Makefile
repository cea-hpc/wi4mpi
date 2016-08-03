############################# Wi4MPI License ###########################
# `04/04/2016`                                                         #
# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
#                                                                      #
# IDDN.FR.001.210022.001.S.P.2014.000.10800                            #
# This file is part of the Wi4MPI library.                             #
#                                                                      #
# This software is governed by the CeCILL-C license under French law   #
# and abiding by the rules of distribution of free software. You can   #
# use, modify and/ or redistribute the software under the terms of     #
# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
# following URL http://www.cecill.info.                                #
#                                                                      #
# The fact that you are presently reading this means that you have     #
# had knowledge of the CeCILL-C license and that you accept its        #
# terms.                                                               #
#                                                                      #
# Authors:                                                             #
#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
#                                                                      #
########################################################################


CC=icc
FC=ifort

prefix=/usr/local
exec_prefix=$(prefix)
bindir=$(exec_prefix)/bin
libexecdir=$(exec_prefix)
sysconfdir=$(exec_prefix)/etc

MPICC=mpicc
CFLAGS = -g -O3 -fPIC -shared -pthread
#CFLAGS += -DDEBUG
SOURCES = new_utils.c new_utils_fn.c test_generation_wrapper.c wrapper.c c2f_f2c.c 
empty_lib_src = lib_empty.c 
INSTALL = install

OMPI_OMPI_OBJS=$(subst .c,_OMPI_OMPI.o,$(SOURCES) )
OMPI_INTEL_OBJS=$(subst .c,_OMPI_INTEL.o,$(SOURCES) )
INTEL_OMPI_OBJS=$(subst .c,_INTEL_OMPI.o,$(SOURCES) )
INTEL_INTEL_OBJS=$(subst .c,_INTEL_INTEL.o,$(SOURCES) )

WI4MPI_LIBEXECDIR=libexec/wi4mpi
OMPI_FAKE_LIBDIR=$(WI4MPI_LIBEXECDIR)/fakelibOMPI
INTEL_FAKE_LIBDIR=$(WI4MPI_LIBEXECDIR)/fakelibINTEL
CXX_FAKE_LIBDIR=$(WI4MPI_LIBEXECDIR)/fakelibCXX

OMPI_OMPI_LIBS=$(WI4MPI_LIBEXECDIR)/libwi4mpi_OMPI_OMPI.so
OMPI_INTEL_LIBS=$(WI4MPI_LIBEXECDIR)/libwi4mpi_OMPI_INTEL.so
INTEL_OMPI_LIBS=$(WI4MPI_LIBEXECDIR)/libwi4mpi_INTEL_OMPI.so
INTEL_INTEL_LIBS=$(WI4MPI_LIBEXECDIR)/libwi4mpi_INTEL_INTEL.so

INTEL_FAKE_LIBS=$(INTEL_FAKE_LIBDIR)/libmpifort.so.12 $(INTEL_FAKE_LIBDIR)/libmpi.so.12 
OMPI_FAKE_LIBS=$(OMPI_FAKE_LIBDIR)/libmpi.so.1 $(OMPI_FAKE_LIBDIR)/libmpi_f77.so.1  $(OMPI_FAKE_LIBDIR)/libmpi_f90.so.1  $(OMPI_FAKE_LIBDIR)/libmpi_mpifh.so.2
CXX_FAKE_LIBS=$(CXX_FAKE_LIBDIR)/libmpi_cxx.so.1 $(CXX_FAKE_LIBDIR)/libmpicxx.so.12

LIBS= $(OMPI_OMPI_LIBS) $(OMPI_OMPI_LIBS) $(OMPI_INTEL_LIBS) $(INTEL_INTEL_LIBS) 

.PHONY: OMPI_OMPI OMPI_INTEL INTEL_OMPI INTEL_INTEL all clean install 
all: OMPI_OMPI OMPI_INTEL INTEL_OMPI INTEL_INTEL
#OMPI_OMPI OK
#OMPI_INTEL 
#INTEL_OMPI 
#INTEL_INTEL 

OMPI_OMPI: $(OMPI_OMPI_LIBS)   $(CXX_FAKE_LIBS)
INTEL_OMPI: $(INTEL_OMPI_LIBS) $(INTEL_FAKE_LIBS) $(CXX_FAKE_LIBS)
OMPI_INTEL: $(OMPI_INTEL_LIBS) $(OMPI_FAKE_LIBS)  $(CXX_FAKE_LIBS)
INTEL_INTEL: $(INTEL_INTEL_LIBS) $(CXX_FAKE_LIBS)

test_generation_wrapper_OMPI_OMPI.o: DEFINES=-DOMPI_OMPI -Iapp/OMPI_OMPI
test_generation_wrapper_OMPI_INTEL.o: DEFINES=-DOMPI_INTEL -Iapp/OMPI_INTEL
test_generation_wrapper_INTEL_OMPI.o: DEFINES=-DINTEL_OMPI -Iapp/INTEL_OMPI
test_generation_wrapper_INTEL_INTEL.o: DEFINES=-DINTEL_INTEL -Iapp/INTEL_INTEL

wrapper_OMPI_OMPI.o: DEFINES=-std=c99 -D_GNU_SOURCE -DIFORT_CALL -Dompi_ompi -I./OMPI_OMPI/ -I./ -I./app/OMPI_OMPI
wrapper_OMPI_INTEL.o: DEFINES=-std=c99 -D_GNU_SOURCE -DIFORT_CALL -Dompi_mpich -I./OMPI_INTEL/ -I./ -I./app/OMPI_INTEL
wrapper_INTEL_OMPI.o: DEFINES=-std=c99 -D_GNU_SOURCE -DIFORT_CALL -Dmpich_ompi -I./INTEL_OMPI/ -I./ -I./app/INTEL_OMPI
wrapper_INTEL_INTEL.o: DEFINES=-std=c99 -D_GNU_SOURCE -DIFORT_CALL -Dmpich_mpich -I./INTEL_INTEL/ -I./ -I./app/INTEL_INTEL

new_utils_OMPI_OMPI.o:DEFINES=-Iapp/OMPI_OMPI
new_utils_OMPI_INTEL.o:DEFINES=-Iapp/OMPI_INTEL
new_utils_INTEL_OMPI.o:DEFINES=-Iapp/INTEL_OMPI
new_utils_INTEL_INTEL.o:DEFINES=-Iapp/INTEL_INTEL

new_utils_fn_OMPI_OMPI.o:DEFINES=-Iapp/OMPI_OMPI
new_utils_fn_OMPI_INTEL.o:DEFINES=-Iapp/OMPI_INTEL
new_utils_fn_INTEL_OMPI.o:DEFINES=-Iapp/INTEL_OMPI
new_utils_fn_INTEL_INTEL.o:DEFINES=-Iapp/INTEL_INTEL

new_utils_fn_fort_OMPI_OMPI.o:DEFINES=-I./ -I./app/OMPI_OMPI
new_utils_fn_fort_OMPI_INTEL.o:DEFINES=-I./ -I./app/OMPI_INTEL
new_utils_fn_fort_INTEL_OMPI.o:DEFINES=-I./ -I./app/INTEL_OMPI
new_utils_fn_fort_INTEL_INTEL.o:DEFINES=-I./ -I./app/INTEL_INTEL

c2f_f2c_OMPI_OMPI.o:DEFINES=-I./ -I./app/OMPI_OMPI -I./OMPI_OMPI/ -Dompi_ompi -DOMPI_OMPI 
c2f_f2c_OMPI_INTEL.o:DEFINES= -I./app/OMPI_INTEL -I./OMPI_INTEL/ -Dompi_mpich -DOMPI_INTEL
c2f_f2c_INTEL_OMPI.o:DEFINES=-I./ -I./app/INTEL_OMPI -I./INTEL_OMPI/ -Dmpich_ompi -DINTEL_OMPI 
c2f_f2c_INTEL_INTEL.o:DEFINES=-I./ -I./app/INTEL_INTEL -I./INTEL_INTEL/ -Dmpich_mpich -DINTEL_INTEL 

$(OMPI_OMPI_LIBS): $(OMPI_OMPI_OBJS)  | $(WI4MPI_LIBEXECDIR)
	$(CC) $(CFLAGS) -o $@ $^ 
$(OMPI_INTEL_LIBS): $(OMPI_INTEL_OBJS) |  $(WI4MPI_LIBEXECDIR)
	$(CC) $(CFLAGS) -o $@ $^ 
$(INTEL_OMPI_LIBS): $(INTEL_OMPI_OBJS)  | $(WI4MPI_LIBEXECDIR)
	$(MPICC) $(CFLAGS) -o $@ $^ 
$(INTEL_INTEL_LIBS): $(INTEL_INTEL_OBJS) | $(WI4MPI_LIBEXECDIR)
	$(CC) $(CFLAGS) -o $@ $^ 

$(INTEL_FAKE_LIBS): lib_empty.o | $(INTEL_FAKE_LIBDIR)
	$(CC) -shared -fPIC -o $@ $<

$(OMPI_FAKE_LIBS): lib_empty.o | $(OMPI_FAKE_LIBDIR)
	$(CC) -shared -fPIC -o $@ $<

$(CXX_FAKE_LIBS): lib_empty.o | $(CXX_FAKE_LIBDIR)
	$(CC) -shared -fPIC -o $@ $<

$(INTEL_FAKE_LIBDIR) $(OMPI_FAKE_LIBDIR) \
$(CXX_FAKE_LIBDIR) $(WI4MPI_LIBEXECDIR) :
	$(INSTALL) -d $@

%_OMPI_OMPI.o:%.c
	$(CC) $(CFLAGS) $(DEFINES)  -o $@ -c $<

%_OMPI_INTEL.o:%.c
	$(CC) $(CFLAGS) $(DEFINES)  -o $@ -c $<

%_INTEL_OMPI.o:%.c
	$(CC) $(CFLAGS) $(DEFINES)  -o $@ -c $<

%_INTEL_INTEL.o:%.c
	$(CC) $(CFLAGS) $(DEFINES)  -o $@ -c $<

%.o:%.c
	$(CC) -o $@ -c $<

clean:
	$(RM) *.o *.so *.so.12 *.so.1

# $(INSTALL) -D $(bindir) 
install:
	$(INSTALL) -D bin/wi4mpi $(bindir)/wi4mpi
	$(INSTALL) -D etc/wi4mpi.cfg $(sysconfdir)/wi4mpi.cfg
	$(INSTALL) -D $(OMPI_OMPI_LIBS) $(libexecdir)/$(OMPI_OMPI_LIBS)
	$(INSTALL) -D $(OMPI_INTEL_LIBS) $(libexecdir)/$(OMPI_INTEL_LIBS)
	$(INSTALL) -D $(INTEL_OMPI_LIBS) $(libexecdir)/$(INTEL_OMPI_LIBS)
	$(INSTALL) -D $(INTEL_INTEL_LIBS) $(libexecdir)/$(INTEL_INTEL_LIBS)
	$(INSTALL) -D $(INTEL_FAKE_LIBDIR)/libmpifort.so.12 $(libexecdir)/$(INTEL_FAKE_LIBDIR)/libmpifort.so.12
	$(INSTALL) -D $(INTEL_FAKE_LIBDIR)/libmpi.so.12 $(libexecdir)/$(INTEL_FAKE_LIBDIR)/libmpi.so.12
	$(INSTALL) -D $(OMPI_FAKE_LIBDIR)/libmpi.so.1 $(libexecdir)/$(OMPI_FAKE_LIBDIR)/libmpi.so.1
	$(INSTALL) -D $(OMPI_FAKE_LIBDIR)/libmpi_f90.so.1 $(libexecdir)/$(OMPI_FAKE_LIBDIR)/libmpi_f90.so.1
	$(INSTALL) -D $(OMPI_FAKE_LIBDIR)/libmpi_f77.so.1 $(libexecdir)/$(OMPI_FAKE_LIBDIR)/libmpi_f77.so.1
	$(INSTALL) -D $(OMPI_FAKE_LIBDIR)/libmpi_mpifh.so.2 $(libexecdir)/$(OMPI_FAKE_LIBDIR)/libmpi_mpifh.so.2
	$(INSTALL) -D $(CXX_FAKE_LIBDIR)/libmpi_cxx.so.1 $(libexecdir)/$(CXX_FAKE_LIBDIR)/libmpi_cxx.so.1
	$(INSTALL) -D $(CXX_FAKE_LIBDIR)/libmpicxx.so.12 $(libexecdir)/$(CXX_FAKE_LIBDIR)/libmpicxx.so.12

